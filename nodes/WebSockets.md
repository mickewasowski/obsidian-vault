---
aliases:
context:
- "[[Network communication]]"
- "[[JavaScript]]"
---

# WebSockets

---

Web Sockets are bidirectional as the client can send a msg to the server, and the server can also send a msg to the client.
Here a connection is established and it remains open, this way the communication is in real-time.

Web sockets provide a full-duplex bidirectional communication that follows the [[TCP protocol]].

1. the client sends a request
2. handshake is done and a persistent connection is established
3. now client and server can send/receive msg as and when needed
4. it removes the overhead of multiple handshakings as the connection is persisted