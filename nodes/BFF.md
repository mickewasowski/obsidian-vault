---
aliases:
context:
- "[[Web Development]]"
---

# BFF

Backend for frontend - a dedicate backend layer to a specific frontend. Instead of the frontend calling many internal APIs directly, the frontend calls the BFF, and the BFF talks to downstream services.

---
#### Why this pattern exists:
- keeps auth/token complexity off the browser
- centralizes security rules (CORS, CSRF, session, logout, token forwarding)
- lets frontend evolve with a tailored API surface (not forced to match internal microservice contacts)


#### What is Duende

- Duende is a .NET identity/security company
- their BFF package provides production-grade building blocks for "frontend + secure gateway" apps:
	- login/logout endpoint behavior
	- session management integration
	- anti-forgery protection fors for browser calls
	- rules for forwarding user tokens to APIs 

> Why we use Duende?
- provides secure API gateway for frontend with OIDC login
- gives standardized, battle-tested defaults so you can implement business endpoints faster and safer

> In the BFF project Duende:
- enables bff middleware and reverse proxy mapping

#### OIDC - OpenID Connect

Standardized login with Google/Microsoft/enterprise IdP

Flow:
1. user clicks login
2. your app redirects user to Identity Provider (IdP)
3. user logs in there
4. IdP sends user back with auth result
5. your app creates a local authenticated session (cookie)
6. app can call APIs on behalf of user using access token

> [warning] Questions:
> 1. So following the above we should login the fe app using the login logic of the bff?


#### What is CSRF?

CSRF - Cross-site Request Forgery 

Attack idea:
- You’re logged into app A in one tab.
- You visit malicious site B.
- Site B causes your browser to send a request to app A.
- Because browser includes cookies automatically, app A might think it’s you.


## What needs to be done:

#### fetch() requests from client

> when sending requests from client -> bff always include this header (`credentials: "include"`)
``` js
fetch("https://your-bff/api/something", {
  method: "GET",
  credentials: "include"
})
```

> also include the anti-foraging header (`x-csrf: "1"`) for non-GET calls
``` js
fetch("https://your-bff/some/proxied/endpoint", {
  method: "POST",
  credentials: "include",
  headers: {
    "Content-Type": "application/json",
    "x-csrf": "1"
  },
  body: JSON.stringify(payload)
})
```


#### add frontend origin to Cors:AllowedOrigins

> this is done by adding the frontend domains to the AllowedOrigins array in the `Bff.Server appsettings.json`


> [info]  in `appsettings.json -> Clusters -> Destinations -> destination1 -> Address` we specify the GW url  