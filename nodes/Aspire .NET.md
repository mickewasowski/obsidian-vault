---
aliases:
context:
- "[[nodes/C#|C#]]"
---

# Aspire .NET

Stack for building and running *cloud-native distributed apps*.

---
### What it is
- .NET Aspire is a Microsoft stack for building and running cloud-native distributed apps (multiple services, APIs, workers, caches, databases).
- It gives you a structured way to wire services together, configure them, and observe them locally.

### How it works
- You create an AppHost project (the orchestrator for local dev).
- In AppHost, you declare app resources/services in code (for example: API service, Redis, Postgres, worker).
- Aspire starts them together, handles service discovery/endpoints, and injects configuration/env vars.
- It provides a dashboard with logs, traces, metrics, health, and resource status in one place.
- Service projects use Aspire packages (like service defaults) for telemetry and resilience patterns.

### Typical flow
1. Define all components in AppHost.
2. Run AppHost locally.
3. Aspire launches dependencies (often via containers) + your .NET services.
4. Use dashboard to inspect failures/latency/logs.
5. Deploy with your preferred platform (Aspire improves dev experience; deployment target can vary).

### Why people use it
- Easier local setup for microservices.
- Better default observability (OpenTelemetry-based patterns).
- Less glue code for connecting services.