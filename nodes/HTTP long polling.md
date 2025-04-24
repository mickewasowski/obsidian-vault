---
aliases: 
context:
- "[[Network communication]]"
---
# HTTP long polling

---

HTTP long polling is a variation of the [[HTTP polling]], however the main difference here is that there will always be a non-empty response.
With the HTTP long polling the connection stays open and the client waits for a long period of time for a response. The server sends a response only if it has a response ready or a timeout occurs.
Unnecessary calls are not made.

1. client sends a request
2. handshake is done and a connection is established
3. the connection stays open until the server has a response or a timeout occurs
4. when the server has a response, it sends it to the client, which will never be empty
5. the connection is closed
6. this process is repeated but every time either a response is guaranteed or a timeout occurs which makes the client send the request again.

HTTP long polling is better than [[HTTP polling]] because the response comes in real-time as the connection remains open for longer.