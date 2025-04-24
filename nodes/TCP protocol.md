---
aliases:
context:
- "[[Network communication]]"
- "[[Network protocols]]"
---

#wip

# TCP protocol

ad

---

Transmission Control Protocol (TCP) is a connection-oriented protocol for communication that helps in the exchange of messages between different devices over a network. In the [[OSI model]] it operates at the transport layer (layer 4). It lies between the Application and Network layers which are used for reliable delivery services.

- TCP uses a three-way handshake for establishing a connection (SYN, SYN_ACK, ACK) and a four-way handshake for closing a connection (FIN, ACK, FIN, ACK)
- it ensures error-free and in-order delivery of the data packets
- it uses acknowledgements (ACKs) to confirm receipt
- it prevents data overflow by adjusting the data transmission rate according to the receiver's buffer size
- it prevents network congestion by using algorithms such as Slow Start, Congestion Avoidance, Fast Retransmit, and Fast Recovery
- TCP header uses checksum to detect corrupted data and requests retransmission if needed