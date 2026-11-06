---
aliases:
context:
- "[[RabbitMQ]]"
---

# Wolverine

Wolverine is a messaging and application framework for .NET.

---
Its primary purpose is to help your services communicate with each other through message, without having to communicate directly.
It provides functionality for:
- sending messages between services
- publishing and handling events
- consuming messages from RabbitMQ
- managing message processing
- handling retries and failures
- integrating messaging with your application's dependency injection and application lifecycle

We can think of Wolverine as the layer between our application and the message broker.

## Why do we use Wolverine?
Without a messaging framework, you'd have to handle a lot of infrastructure-related work yourself:
- establish RabbitMQ connections
- declaring exchanges and queues
- configuring bindings
- serializing and deserializing messages
- handling acknowledgements
- implementing retry mechanisms

> Wolverine abstracts much of this complexity and lets you focus on the actual business logic
