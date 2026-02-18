---
aliases:
context:
- "[[Proxy]]"
---

# YARP

Yet Another Reverse Proxy - Microsoft open-source reverse proxy toolkit for ASP .NET Core.

---
Think of it as a way to put a smart traffic router in front of your services.

### What YARP does:
- Receives incoming requests at one endpoint
- Routes them to one of your backend services
- Can load-balance across multiple instances
- Supports transforms (rewrite paths, add/remove headers, etc.)
- Handles retries, health checks, TLS termination scenarios, auth integration, and observability

Typical use cases:
- API gateway in microservices
- Single public endpoint for many internal services
- Gradual migration/strangler pattern from legacy apps
- Centralized routing/security policy point

### How YARP is configured (high level):

1. Add YARP package in your ASP.NET Core app (`Yarp.ReverseProxy`)
2. Register it in DI (AddReverseProxy)
3. Define Routes and Clusters
   - Route = matching rule (path/host/method) + target cluster
   - Cluster = one or more destination backend URLs
1. Map proxy middleware (MapReverseProxy)

Minimal example:
``` c#
appsettings.json
{
  ReverseProxy: {
    Routes: {
      route1: {
        ClusterId: backendCluster,
        Match: {
          Path: /api/{**catch-all}
        }
      }
    },
    Clusters: {
      backendCluster: {
        Destinations: {
          d1: {
            Address: https://localhost:5001/
          }
        }
      }
    }
  }
}

Program.cs
var builder = WebApplication.CreateBuilder(args);
builder.Services
    .AddReverseProxy()
    .LoadFromConfig(builder.Configuration.GetSection("ReverseProxy"));
var app = builder.Build();
app.MapReverseProxy();
app.Run();
```


### Can I have multiple destinations and respective paths for each?

You can configure:
- Multiple routes (different path patterns)
- Each route points to a specific cluster
- Each cluster can have one or many destinations

So you can do both:
1) different paths to different backends, and  
2) multiple instances per backend for load balancing.

Example shape:
``` c#
{
  ReverseProxy: {
    Routes: {
      usersRoute: {
        ClusterId: usersCluster,
        Match: { Path: /users/{**catch-all} }
      },
      ordersRoute: {
        ClusterId: ordersCluster,
        Match: { Path: /orders/{**catch-all} }
      }
    },
    Clusters: {
      usersCluster: {
        Destinations: {
          u1: { Address: https://users-api-1/ },
          u2: { Address: https://users-api-2/ }
        }
      },
      ordersCluster: {
        Destinations: {
          o1: { Address: https://orders-api/ }
        }
      }
    }
  }
}
```

What this does:
- `/users/*` → usersCluster (load-balanced across u1 and u2)
- `/orders/*` → ordersCluster


### How to intercept request/response in YARP?

1. Middleware in the proxy pipeline (best for allow/deny, auth checks, logging, short-circuiting)
2. YARP transforms (best for changing path/query/headers/status/response headers)
3. Custom forwarding logic (advanced; for deep control, especially body-level handling)

For most cases, use middleware + transforms.
``` c#
var builder = WebApplication.CreateBuilder(args);
builder.Services
    .AddReverseProxy()
    .LoadFromConfig(builder.Configuration.GetSection("ReverseProxy"))
    .AddTransforms(context =>
    {
        // Before sending to destination
        context.AddRequestTransform(async t =>
        {
            var userId = t.HttpContext.User?.Identity?.Name ?? "anonymous";
            t.ProxyRequest.Headers.Add("X-User", userId);
            // inspect t.HttpContext.Request / t.ProxyRequest here
        });
        // After destination responds (headers/status phase)
        context.AddResponseTransform(async t =>
        {
            t.HttpContext.Response.Headers["X-Proxied-By"] = "YARP";
            // inspect t.ProxyResponse here
        });
    });

var app = builder.Build();

app.MapReverseProxy(proxyPipeline =>
{
    proxyPipeline.Use(async (ctx, next) =>
    {
        // Pre-forward interception
        if (!ctx.Request.Headers.ContainsKey("X-Tenant-Id"))
        {
            ctx.Response.StatusCode = 400;
            await ctx.Response.WriteAsync("Missing tenant header");
            return; // short-circuit
        }
        await next();
        // Post-forward interception point (limited once response started)
    });
});
app.Run();
```

Important caveat:
- Response/body rewriting is harder because YARP is stream-oriented for performance.
- Header/path/query/status interception is straightforward.
- If you need heavy request/response body mutation, do it carefully (buffering/custom logic), or move that concern into the backend service when possible.