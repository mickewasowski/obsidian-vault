---
aliases:
context:
- "[[Network communication]]"
---

# HTTP polling

---

HTTP polling is a version of an [[HTTP request]] that is being sent from the client to the server at a regular interval.
The difference here is that the response might be empty.

As follows are the steps:
1. client sends a request to the server
2. handshake is done and a connection is opened between the client and the server
3. the server sends a response to the client, it may or may not have any update for the client and therefore the response might be empty
4. the connection is closed
5. the process is repeated at a regular interval

The major disadvantage is the many unnecessary calls as most of the time they will be empty.
