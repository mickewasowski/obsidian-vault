---
aliases:
context:
- "[[Web Development]]"
---

# Proxy

A proxy is an intermediary between a client and a server.

---
### What is a Proxy?

A proxy is an intermediary between a client and a server.
Instead of your device talking directly to a website or service, it talks to the proxy first, and the proxy forwards the request.
- Without proxy: You → Website  
- With proxy: You → Proxy → Website

Common reasons to use a proxy:
- Hide your IP address from the destination server
- Filter or monitor traffic (common in schools/companies)
- Cache responses to improve speed
- Enforce access policies (block certain sites)
- Route traffic through a different location

Types you’ll hear about:
- Forward proxy: Acts on behalf of the client (you)
- Reverse proxy: Acts on behalf of servers (used by websites for load balancing, security, SSL termination)
- Transparent proxy: Intercepts traffic, often without explicit client setup