---
aliases:
context:
- "[[JavaScript]]"
- "[[JS-libs]]"
---

#wip

# RxJS

RxJS (Reactive Extensions for JavaScript) is a library for reactive programming using Observables.

---
RxJS lets you work with asynchronous data streams (like events, HTTP requests, or user input) in a more powerful, flexible, and declarative way.
Instead of writing callbacks or async/await everywhere, you can use RxJS to create streams of data, then transform, combine, or filter them using operators like map, filter, mergeMap, etc.

> [!tip] In NestJS, RxJS is built-in under the hood because it uses Observables in its HTTP layer, microservices, and guards, making it easy to handle reactive patterns when needed.
