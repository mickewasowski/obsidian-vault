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