---
aliases:
context:
---

# university inspired program

---
# Four-Year Software Engineering Self-Study Curriculum

## Goal

Build a strong computer science foundation inspired by MIT, Carnegie Mellon, and Stanford, then layer on practical production software engineering, backend development, DevOps, cloud infrastructure, distributed systems, reliability, security, and system design.

The program is designed to be followed alongside a full-time software engineering job.

## Study Model

The below are rough estimations:
- **Normal week:** 8–10 focused hours
- **Busy week minimum:** ~3 hours
- **Highly motivated week:** up to ~12 hours
- **Per year:** roughly 450 focused hours
- **Total:** roughly 1,800–2,000 focused hours over four years
- Take short breaks of several days when needed.
- Do not compensate for missed weeks with unsustainable study marathons.
- "Year 1", "Year 2", etc. are levels, not rigid calendar deadlines. If a year takes 10 or 14 months, continue when the material is genuinely complete.

### Suggested Weekly Rhythm

| Day | Work |
|---|---|
| Monday | 60–75 min theory / lecture |
| Tuesday | 60–90 min exercises / DSA |
| Wednesday | Off |
| Thursday | 60–90 min systems / practical work |
| Friday | Off or 45–60 min review |
| Saturday | 3–4 h serious project / lab session |
| Sunday | 1.5–2.5 h exercises, review, and planning |

## Core Learning Loop

For every major topic:

1. Learn the theory.
2. Complete exercises.
3. Implement the concept.
4. Break the implementation intentionally.
5. Debug it.
6. Explain why it works.
7. Apply it in a project.

Target approximately **40% theory / 60% practical work**.

---

# Year 1 — Foundations

## Months 1–2: C, Linux, and Developer Environment

### C

Study:
- Compilation and linking
- Primitive types
- Binary representation
- Pointers
- Arrays
- Strings
- Structs
- Stack vs. heap
- `malloc` / `free`
- Memory ownership
- Function pointers
- Files
- Memory corruption
- Makefiles
- Debugging

### Linux

Study:
- Files and directories — Linux
- Filesystem hierarchy — Linux
- Environment variables — Linux
- Pipes and redirection — Linux / Shell & Bash
- Permissions — Linux
- `grep` — Linux
- `awk` — Linux
- Processes — Linux
- Signals — Linux
- Users and groups — Linux
- systemd basics — Linux
- Package management — Linux
- SSH — Linux
- Bash scripting — Linux / Shell & Bash
- `find` — Shell & Bash
- `sed` — Shell & Bash
- `gdb` — C → Debugging
- `strace` — C → Debugging
- `lsof` — DevOps → Terminal Knowledge → Process Monitoring resources
- `/proc` — Supplementary: [Linux kernel documentation](https://github.com/torvalds/linux/blob/master/Documentation/filesystems/proc.rst)

Roadmaps: [Linux](https://roadmap.sh/linux) · [Shell & Bash](https://roadmap.sh/shell-bash) · [C](https://roadmap.sh/c) · [DevOps](https://roadmap.sh/devops)


### Project

Build a small Unix-style CLI application in C.

---

## Months 2–5: Data Structures & Algorithms + Discrete Mathematics

Study these in parallel.

### Data Structures & Algorithms

- Complexity analysis
- Big-O, Ω, Θ
- Arrays
- Linked lists
- Stacks
- Queues
- Hash tables
- Trees
- Binary search trees
- Heaps
- Priority queues
- Graphs
- BFS
- DFS
- Sorting
- Binary search
- Recursion
- Divide and conquer
- Greedy algorithms
- Dynamic programming
- Shortest paths
- Union-find

### Discrete Mathematics

- Logic
- Sets
- Functions
- Relations
- Proof techniques
- Mathematical induction
- Combinatorics
- Graph theory
- Recurrence relations
- Probability foundations

### Practice

Aim for roughly **2–4 well-understood algorithm problems per week** rather than maximizing problem count.

Implement important data structures yourself.

---

## Months 5–7: Computer Systems and Architecture

Study:

- Binary and hexadecimal
- Two's complement
- Integer representation
- Floating-point representation
- Assembly fundamentals
- CPU architecture
- Registers
- Instruction execution
- Stack frames
- Calling conventions
- Memory hierarchy
- CPU cache
- RAM
- Virtual memory introduction
- System calls
- Compilation pipeline
- Linking

### Project

Build a small emulator, virtual machine, or another low-level systems project.

Use tools such as `objdump`, `gdb`, and `strace` to inspect your own programs.

---

## Months 7–8: Networking Fundamentals

Understand the stack:

```text
Application
    ↓
HTTP
    ↓
TCP / UDP
    ↓
IP
    ↓
Ethernet / Wi-Fi
```

Study:

- IP addresses
- Subnetting fundamentals
- Ports
- Sockets
- DNS
- TCP
- UDP
- TLS
- HTTP
- HTTP/2 and HTTP/3 conceptually
- Proxies
- Reverse proxies
- NAT
- Firewalls
- Latency
- Bandwidth

### Projects

1. Build a TCP client/server.
2. Build a minimal HTTP server.

---

## Months 8–9: Docker

Study:

- Images
- Layers
- Containers
- Dockerfiles
- Build context
- Registries
- Port mapping
- Environment variables
- Volumes
- Docker networks
- Docker Compose
- Multi-stage builds

Containerize applications built earlier in the year.

Do **not** rush into Kubernetes yet.

---

## Months 9–11: Databases

### PostgreSQL

Study:

- Relational model
- SQL
- Schemas
- Normalization
- Primary/foreign keys
- Indexes
- B-trees
- Joins
- Transactions
- ACID
- Isolation levels
- Locking
- Query planning
- Migrations
- Connection pooling

Avoid hiding everything behind an ORM while learning the fundamentals.

### Redis

Study:

- Key/value model
- Redis data structures
- TTL
- Caching
- Cache-aside
- Sessions
- Rate limiting
- Pub/sub
- Eviction policies

Understand both **when Redis is useful and when it is the wrong tool**.

---

## Months 11–12: Year 1 Integration Project

Build and deploy something approximately like:

```text
React / TypeScript frontend
            │
          HTTPS
            │
          Go API
       ┌────┴────┐
       │         │
 PostgreSQL    Redis
       │
 Background worker

Docker Compose:
- frontend
- backend
- worker
- PostgreSQL
- Redis

CI:
- lint
- tests
- build
```

Deploy the application to a real Linux server.

---

# Year 2 — Systems Engineering

## Months 1–3: Operating Systems

Study:

- Processes
- Threads
- Scheduling
- Synchronization
- Mutexes
- Semaphores
- Deadlocks
- Virtual memory
- Paging
- Filesystems
- I/O
- System calls
- Context switching
- IPC

### Practical Work

Complete OS labs or small kernel exercises.

Revisit Docker and study the Linux primitives underneath containers:

- Namespaces
- cgroups
- Process isolation
- Filesystem isolation

---

## Months 3–4: Concurrency

Use Go extensively.

Study:

- Goroutines
- Channels
- Mutexes
- Atomics
- Race conditions
- Deadlocks
- Worker pools
- Cancellation
- Backpressure
- Concurrent data structures

### Project

Build a highly concurrent service and test it under load.

---

## Months 4–6: Advanced Networking and Backend Engineering

Study:

- Connection pooling
- WebSockets
- Server-Sent Events
- RPC
- gRPC
- Load balancing
- Reverse proxies
- API gateways
- Retries
- Timeouts
- Exponential backoff
- Idempotency
- Rate limiting
- Circuit breakers

Introduce **Nginx**.

---

## Months 6–7: Messaging and Event-Driven Systems

### RabbitMQ

Study:

- Queues
- Exchanges
- Routing
- Acknowledgements
- Retries
- Dead-letter queues

### Kafka

Understand:

- Event logs
- Topics
- Partitions
- Consumer groups
- Offsets
- Ordering
- Retention

### Project

Build an event-driven multi-service system.

---

## Months 7–9: Testing and Professional Software Engineering

### Testing

- Unit tests
- Integration tests
- End-to-end tests
- Contract testing
- Property-based testing
- Fuzzing
- Load testing
- Mocking philosophy
- Test architecture

### Software Engineering

- API design
- API versioning
- Backward compatibility
- Refactoring
- Dependency management
- Code review
- Documentation
- Database migrations
- Feature flags
- Release management

---

## Months 9–10: CI/CD

Study:

- Continuous integration
- GitHub Actions or equivalent
- Build artifacts
- Docker registries
- Automated testing
- Automated deployment
- Secrets management
- Environments
- Rollbacks
- Blue/green deployment
- Canary deployment

---

## Months 10–12: Cloud Foundations

Choose **one cloud provider** and learn it properly. AWS is a reasonable default.

Understand:

- Compute
- Storage
- Networking
- IAM
- VPCs
- Load balancers
- Managed databases
- DNS
- Object storage
- Autoscaling

Focus on concepts rather than memorizing a cloud provider's entire product catalog.

### Year 2 Project

Deploy a multi-service application through a complete CI/CD pipeline into cloud infrastructure.

---

# Year 3 — Distributed and Production Systems

## Months 1–3: Distributed Systems

Study:

- Partial failure
- Replication
- Partitioning
- Consensus
- Leader election
- Logical/physical clocks
- Ordering
- Consistency
- Availability
- CAP theorem
- Eventual consistency
- Distributed transactions
- Idempotency
- Fault tolerance

Study important systems and ideas:

- Raft
- Dynamo-style systems
- MapReduce
- Distributed databases

Revisit PostgreSQL, Redis, Kafka, and RabbitMQ from a distributed-systems perspective.

---

## Months 3–5: Kubernetes

Now learn orchestration.

Study:

- Pods
- Deployments
- Services
- ConfigMaps
- Secrets
- Ingress
- Health probes
- Resource requests/limits
- Autoscaling
- Persistent volumes
- Scheduling
- Rolling deployments
- Helm fundamentals

### Project

Move the Year 2 application onto Kubernetes.

---

## Months 5–6: Infrastructure as Code

### Terraform

Study:

- Providers
- Resources
- State
- Modules
- Environments
- Remote state
- Infrastructure lifecycle

Aim for a workflow like:

```text
git clone
    ↓
terraform apply
    ↓
Infrastructure exists
    ↓
Deploy
    ↓
Application running
```

---

## Months 6–8: Observability and SRE

Understand the three pillars:

- Logs
- Metrics
- Traces

Study:

- Prometheus
- Grafana
- OpenTelemetry
- Structured logging
- Alerting
- SLIs
- SLOs
- Error budgets
- Incident response
- Postmortems

Intentionally break services and diagnose failures using your observability stack.

---

## Months 8–10: Security

Study:

- Authentication
- Authorization
- OAuth
- OpenID Connect
- Cryptography fundamentals
- TLS
- Password hashing
- Secrets management
- SQL injection
- XSS
- CSRF
- SSRF
- Dependency vulnerabilities
- Container security
- Network security
- Threat modelling

---

## Months 10–12: Database Internals and Performance Engineering

### Database Internals

- Storage engines
- Write-ahead logs
- B-trees
- LSM trees
- MVCC
- Replication
- Sharding
- Query optimization
- Distributed databases

### Performance Engineering

- Profiling
- Benchmarking
- CPU bottlenecks
- Memory bottlenecks
- Allocation
- Cache behavior
- Network latency
- Database bottlenecks
- Load testing

### Year 3 Project

Build and operate a genuinely distributed application.

It should include multiple services, asynchronous communication, persistent storage, caching, observability, deployment automation, and intentional failure testing.

---

# Year 4 — Advanced Software Engineering

Year 4 is more flexible and elective-driven.

## Software Architecture

Study:

- Modular monoliths
- Microservices
- Event-driven architecture
- CQRS
- Event sourcing
- Domain boundaries
- Domain-Driven Design fundamentals
- Evolutionary architecture
- Migration strategies

The objective is not to prefer complicated architectures. It is to understand the trade-offs well enough to know when a simple monolith is the superior engineering decision.

---

## Compilers and Programming Languages

Study:

- Lexing
- Parsing
- ASTs
- Interpreters
- Type systems
- Compilation
- Optimization
- Runtime systems

Build at least a small interpreter/compiler.

---

## Advanced Distributed Systems

Move from textbooks/tutorials toward academic papers and system designs.

Analyze real distributed systems and their trade-offs.

---

## Reliability Engineering

Study:

- Chaos/failure testing
- Disaster recovery
- Backups
- Recovery objectives
- Multi-region architecture
- Capacity planning
- Graceful degradation
- Production failure modes

---

## System Design

Regularly design systems such as:

- GitHub
- Discord
- Dropbox
- URL shortener
- Metrics platform
- Large notification system
- Search/autocomplete service
- Exchange/trading system

For each design, reason about:

- Requirements
- Scale
- Data model
- APIs
- Architecture
- Consistency
- Availability
- Failure modes
- Caching
- Messaging
- Storage
- Observability
- Security
- Cost
- Trade-offs

---

# Final Capstone — Approximately 4–5 Months

Build one serious system integrating the curriculum.

A miniature trading platform is a particularly good candidate.

Example architecture:

```text
                         Clients
                            │
                       API Gateway
                            │
             ┌──────────────┼──────────────┐
             ▼              ▼              ▼
       Auth Service     Order API      Market Data
                            │
                            ▼
                       Order Engine
                            │
                     Event Streaming
                     ┌──────┴──────┐
                     ▼             ▼
                Portfolio       Analytics
                     │             │
                     └──────┬──────┘
                            ▼
                       PostgreSQL
                          Redis
```

### Infrastructure

- Linux
- Docker
- Kubernetes
- Terraform
- AWS or another selected cloud

### Observability

- OpenTelemetry
- Prometheus
- Grafana
- Structured logs

### Engineering

- CI/CD
- Unit/integration/E2E tests
- Load testing
- Failure testing
- Security
- Database migrations
- Deployment strategies

### Concepts Applied

The capstone should force you to use:

- Algorithms and data structures
- C/system-level understanding
- Networking
- Operating systems concepts
- Concurrency
- Go/backend engineering
- SQL/PostgreSQL
- Redis
- Messaging/event streaming
- Distributed systems
- Docker
- Kubernetes
- Terraform
- Cloud infrastructure
- CI/CD
- Observability
- Security
- Performance engineering
- System design

---

# Four-Year Progression at a Glance

## Year 1 — Foundations

**Goal:** Understand what exists underneath application development.

C → Linux → DSA → discrete mathematics → computer architecture → networking → Docker → PostgreSQL → Redis → first full-stack/backend system.

## Year 2 — Systems Engineering

**Goal:** Become comfortable building real production-oriented backend systems.

Operating systems → concurrency → advanced networking → RabbitMQ/Kafka → testing → professional engineering practices → CI/CD → cloud.

## Year 3 — Distributed Production Systems

**Goal:** Understand and operate systems at scale.

Distributed systems → Kubernetes → Terraform → observability/SRE → security → database internals → performance.

## Year 4 — Engineering Mastery

**Goal:** Develop architectural judgment and integrate everything learned.

Architecture → compilers/programming languages → advanced distributed systems → reliability → system design → major capstone.

---

# What Success Looks Like

At the end of the program, the objective is not to have memorized a collection of tools.

You should be able to answer questions such as:

- What happens between entering a URL and receiving a response?
- What happens inside the operating system when a process performs I/O?
- Why does a database index make a query faster?
- Why might an index make writes slower?
- When should Redis be used?
- When should Redis not be used?
- What happens when a cache goes down?
- Why would a queue help this architecture?
- What delivery guarantees does the queue provide?
- What happens when one service becomes unavailable?
- How do we prevent retries from duplicating operations?
- Why use containers?
- What does Kubernetes actually solve?
- When is Kubernetes unnecessary?
- How would this system behave with 100× the traffic?
- Where is its bottleneck?
- How would we measure that?
- How would we deploy it safely?
- How would we recover from a bad deployment?
- How would we diagnose a production incident?
- Which consistency guarantees does the system actually require?
- Should this system be a monolith or multiple services?
- What are the operational and financial costs of the architecture?

The goal is to progress from knowing **how to use technologies** to understanding **why systems are designed the way they are and what trade-offs those decisions create**.
