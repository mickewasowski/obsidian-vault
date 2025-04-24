---
aliases:
context:
- "[[Network communication]]"
---

# HTTP request

---

HTTP requests are unidirectional and are performed from the client to the server.
Following is a description of how HTTP requests work:
1. client sends a request
2. handshake is done between the client and the server and a connection is established
3. server processes the client's request
4. once the response is ready it is sent to the client
5. the connection is closed

Every HTTP request is considered a new request because for each request a new connection is being opened between the client and the server. This is why HTTP is called stateless.