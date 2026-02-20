---
aliases:
context:
---

# Plan

---

### Overall

1. Add endpoints for each request to each service in the BFF
2. Intercept the responses and return data in a format more suitable for the FE (return only the necessary data)
3. If there is no Redux state to cause re-renders, how will the UI update?

### BFF

1. add the relevant routes and addresses in the ReverseProxy configuration
2. 


### Hammer

1. remove user account ids (cash and trading `reference_id`s) from the state -> the CRM data should be kept in the BFF and when we need to make a request that requires the reference_id we should intercept the request in the BFF, get the id from the Redis DB and add it to the request (what we achieve with this approach is hiding the user sensitive data from the client)
2. 






### According to the documentation - PLATFORM_SECURITY_AND_LAYER_OWNERSHIP_PAPER

> [!tip] The below is the outline of what needs to happen in the BFF and Hammer projects

> BFF must include
  - Session ownership: create/renew/revoke sessions; map sessionToken <-> userObject; store server-side (Redis/equivalent).
  - User context lifecycle: build/refresh userObject from authoritative systems.
  - Security controls: rate limiting, abuse protection, CSRF (for cookie sessions), strong server-side logout/revocation.
  - Trust handoff to GW: mTLS + preferably a short-lived signed internal user-context token.
  - Observability/audit hooks: correlation/request IDs and session lifecycle audit.

> Frontend (client apps) must include
  - Only session-token handling (secure storage; HTTP-only cookies for web when possible).
  - Login/logout/session renewal and re-auth/SCA UX flows.
  - Consistent client metadata (device/app version) for fraud/debug.
  - No local authorization as security control (UI checks are UX only, not enforcement).

> Frontend should remove / stop doing
  - Stop carrying large identity/permissions payloads in client tokens (no “fat JWT userObject” model).
  - Stop making authorization decisions locally as if they enforce security.
  - Stop calling platform services directly; always go through BFF.
  - Avoid insecure token storage patterns (e.g., sensitive tokens in localStorage).