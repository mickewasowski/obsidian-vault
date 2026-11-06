---
aliases:
context:
- [["C#"]]
- [["Message brokers]]"]]
---

# RabbitMQ

RabbitMQ is a message broker, provides the infrastructure.

---
## Main components:
- Exchange - receives messages from publishers and decides where to route them. (we can think of it as a post office sorting incoming mail)
- Queue - stores messages until a consumer processes and acknowledges them. (think of it as a mailbox)
- Producer / Publisher - the application or service that sends messages to RabbitMQ
- Consumer - the application or service that receives messages from a queue and processes them
- Binding - connects an exchange to a queue and defines the routing rules

## Exchange types
- Direct - exact routing key match
- Fanout - sends to every bound queue
- Topic - routes using routing key patterns
- Headers - routes based on message headers

## Common usecases
- Notifications - an order is placed, so send an email
- Background processing - generate a PDF without blocking an API request
- Microservice communication - one service notifies other services that something happened
- Data synchronization - keep information synchronized between different services
- Work distribution - distribute jobs among multiple worker instances
