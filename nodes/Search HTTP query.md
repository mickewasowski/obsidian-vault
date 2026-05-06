---
aliases:
context:
- "[[HTTP request]]"
---

# Search HTTP query

GET vs POST request for search queries.

---
GET is semantically the "correct" query for search request, however there are situations where due to limitations we might use POST for such queries:

### Query parameters become too large
- GET sends filters in the URL
``` http
    GET /search?query=react&tags=frontend,typescript&sort=date&page=2
```
> This breaks down when search payloads become complex:
> - nested filters
> - arrays
> - large JSON objects
> - long free-text queries
> - elasticsearch-style DSLs

Example:
``` json
{
  "filters": {
    "price": { "min": 10, "max": 200 },
    "tags": ["gaming", "wireless"],
    "availability": true
  },
  "sort": [
    { "field": "rating", "direction": "desc" }
  ]
}
```
Encoding this into a URL becomes ugly and fragile

> URLs also have practical length limits:
> - browsers
> - proxies
> - load balancers
> - CDNs
> - servers

> Streams use POST with a JSON body:
``` http
    POST /search
    Content-Type: application/json
```

### Sensitive data should not live in the URL

GET query params appear in:
- browser history
- analytics
- logs
- proxy logs
- monitoring tools

> POST puts the data in the body, which is less exposed operationally (though still not "secure" by itself)

### Easier frontend-backend integration

Most frontends already work with DTOs
It is more natural for validation libraries
Sending JSON is simpler than serializing and deserializing URL params
