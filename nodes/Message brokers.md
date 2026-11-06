---
aliases:
context:
---

# Message brokers

---
## What is a Message broker?

A message broker is a piece of software that allows different applications to communicate with each other by sending and receiving messages.

It's a *middleman between services* - instead of the services communicating directly with each other (which creates dependencies), they communicate through the broker.


## How does it work?

There are three important concepts:
1. *Producer* - the service that sends a message
2. *Message broker* - receives and routes messages
3. *Consumer* - the service that receives and processes a message

Flow:
1. a producer creates a message
2. it sends the message to the broker
3. the broker routes the message to the appropriate queue
4. a consumer listens to that queue
5. the consumer receives and processes the message

Examples of message brokers:
- [[RabbitMQ]]
- Appache Kafka
- Azure Service Bus
