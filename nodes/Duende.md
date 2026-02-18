---
aliases:
context:
- "[[Web Development]]"
---

# Duende

IdentityServer and BFF

---
In .NET circles, “Duende” usually means Duende Software’s identity/security libraries.

In your vault, it looks like you’re specifically using Duende BFF (nodes/BFF.md:18), not just talking about Duende in general.
- What Duende is
  - A company that builds .NET auth/security products.
  - Most known products: Duende.IdentityServer (OAuth2/OIDC server) and Duende.BFF (Backend-for-Frontend security layer).
  - It is commercial-licensed for production use.

- What it does (BFF context)
  - Keeps tokens off the browser (stores session server-side via cookie).
  - Handles OIDC login/logout redirects to your Identity Provider.
  - Adds CSRF protections for browser calls.
  - Proxies frontend calls to downstream APIs and forwards user tokens safely.
  - Centralizes auth/CORS/session behavior so frontend code is simpler.

- How it’s typically configured
  1. In Program.cs:
     - Add cookie + OIDC auth.
     - Add BFF services.
     - Add reverse proxy (often YARP) for API forwarding.
  2. In middleware:
     - UseAuthentication(), UseBff(), UseAuthorization().
  3. In endpoint mapping:
     - Map BFF management endpoints (/bff/login, /bff/logout, etc.).
     - Map proxy/API endpoints and require auth + anti-forgery where needed.
  4. In appsettings.json:
     - OIDC authority/client/scopes/callbacks.
     - Allowed frontend origins (CORS).
     - Proxy destination cluster URLs.

Minimal shape:
``` c#
builder.Services
  .AddAuthentication(options => { /* defaults */ })
  .AddCookie("cookie")
  .AddOpenIdConnect("oidc", options => { /* authority, client, scopes */ });
  
builder.Services.AddBff();

builder.Services.AddReverseProxy().LoadFromConfig(builder.Configuration.GetSection("ReverseProxy"));

app.UseAuthentication();
app.UseBff();
app.UseAuthorization();
app.MapBffManagementEndpoints();
app.MapReverseProxy().RequireAuthorization();
```

And from the frontend:
- send credentials: "include" on fetch
- send CSRF header (often x-csrf: "1") for non-GET calls