---
aliases:
context:
---

# Javascript sample

---
### **Core JavaScript fundamentals & types (1–10)**

1. Explain the ECMAScript value types and the difference between primitive values and objects. Give examples where treating a primitive like an object matters.
2. Describe how JavaScript represents numbers internally (IEEE-754). What are consequences for arithmetic, equality, and financial calculations?
3. Explain NaN: how it compares, how to detect it reliably, and why Number.isNaN is preferred over global isNaN.
4. Describe the differences between undefined and null — when each is appropriate, and how JSON serialization handles them.
5. What are Symbols and why were they introduced? Show real-world use-cases (e.g., well-known symbols, private properties).
6. How does BigInt work? When should you use it, and what are the interoperability pitfalls with Number?
7. Explain how strings are represented and manipulated internally (UTF-16 code units). What problems arise with surrogate pairs and string length/substring operations?
8. Describe Typed Arrays and ArrayBuffer. When and why would you use them instead of regular arrays?
9. What are the tradeoffs between using plain objects ({}) vs Map/Set for collections? Discuss key types, enumeration order, and performance characteristics.
10. Explain the concept of "temporal dead zone" with let/const. Give examples of errors it prevents.

---

### **Type coercion, comparison & equality (11–16)**

11. Explain abstract equality (==) vs strict equality (===). Provide examples where == leads to surprising results and how to reason about its coercion rules.
12. Walk through JavaScript’s ToPrimitive, ToNumber, and ToString coercion algorithms. How do valueOf and toString influence coercion?
13. How does object-to-primitive conversion work for arrays, dates, and functions? Give examples where custom valueOf/toString changes behavior.
14. Describe how property access and indexing coerces keys (string vs symbol). How does Map differ in key handling?
15. Explain sorting arrays with Array.prototype.sort — how does it coerce elements by default, and why does comparator stability matter?
16. Discuss the pitfalls of floating-point comparisons and ways to compare numbers safely (epsilons, ulps, libraries).

---

### **Scope, closures, hoisting & execution context (17–24)**

17. Explain lexical scope vs dynamic scope. Why is JavaScript lexically scoped, and how does that impact closure behavior?
18. Describe hoisting for function declarations, function expressions, var, let, and const. Show subtle examples that trip developers.
19. Explain closures in depth: how they capture variables, lifetime implications, memory retention, and common pitfalls (e.g., loop variables).
20. What is an execution context and variable environment? Explain how environments chain and where global variables live.
21. How do block scopes and function scopes interact with closures? Provide patterns for avoiding accidental shared-state across closures.
22. Explain module scope with ES modules and how top-level await, live bindings, and hoisting of imports behave.
23. Describe how eval and indirect eval differ in scope behavior. When is eval run in global vs local scope?
24. Show how to implement private state for objects using closures and compare to using WeakMap or private class fields.

---

### **Functions, call site, this binding, arguments (25–32)**

25. Explain the four ways this is bound in JavaScript (global/default, implicit, explicit via call/apply/bind, and new). Give edge cases.
26. Compare function declarations, function expressions, arrow functions, and generator functions in terms of this, arguments, and hoisting.
27. How does Function.prototype.bind work under the hood? Explain partial application, constructor behavior of bound functions, and implications for instanceof.
28. Explain the arguments object vs rest parameters. Why are rest parameters preferred? How do they interact with strict mode and default parameters?
29. Describe how to safely curry and compose functions in JS; show pitfalls with context and variadic functions.
30. How do getters and setters influence function semantics when used as object properties? How does this behave with proxies and inheritance?
31. Explain tail-call optimization (TCO) and whether JavaScript engines implement it. Discuss alternatives for deep recursion (trampolines, iteration).
32. Discuss the tradeoffs of designing APIs as functions vs methods on objects (e.g., OOP vs functional styles).

---

### **Prototypes, inheritance, classes & object internals (33–40)**

33. Explain the prototype chain, [[Prototype]] vs prototype property, and how property lookup works at runtime.
34. Describe how JavaScript implements method overriding, super calls, and how Object.create differs from constructor prototypes.
35. Compare ES5 prototype-based patterns to ES6 class syntax. Is class “syntactic sugar”? Explain underlying semantics and caveats.
36. Explain hidden classes (shapes) and inline caches in JS engines and how object layout patterns affect performance.
37. How do Object.getOwnPropertyDescriptor, defineProperty, and property attributes (writable, configurable, enumerable) affect behavior? Provide use-cases.
38. Describe how property enumeration order is defined in ECMAScript and why relying on it can be problematic.
39. Explain how inheritance interacts with primitives boxed into objects (e.g., String.prototype). What are autoboxing pitfalls?
40. Show how to create an immutable object shallowly and deeply. Discuss Object.freeze limitations and alternatives.

---

### **Asynchronous programming, Promises, async/await, concurrency (41–52)**

41. Describe Promises: states, the executor, chaining, error propagation, and unhandled rejection semantics. Provide debugging techniques.
42. Explain async/await desugaring into Promises. How do try/catch and finally behave with async functions?
43. Compare Promise.all, Promise.allSettled, Promise.race, and Promise.any. Give practical examples and pitfalls (short-circuiting, rejection handling).
44. Explain cancellation patterns for async work in JS (AbortController, manual flags, cancellable Promises pattern) and tradeoffs.
45. Describe how to implement backpressure and concurrency control for many async tasks (semaphores, pools, rate limiters).
46. Explain microtask queue vs macrotask queue and how they affect Promise resolution ordering and DOM updates.
47. How do async iterators and for-await-of work? Provide a design where they are the appropriate abstraction.
48. Discuss strategies for error handling in async flows across module boundaries and in parallel operations.
49. Show how to implement a retry with exponential backoff for failing async operations and discuss idempotency concerns.
50. Explain how transact-like optimistic updates and eventual consistency are handled in frontend apps when network latency/failures occur.
51. Discuss event emitters vs observables vs promises — when to use each and how they compose.
52. Describe memory and leak risks with long-lived async operations (timers, event listeners, unresolved Promises) and mitigation patterns.

---

### **Event loop, tasks, timers, and browser rendering (53–58)**

53. Explain the JavaScript event loop in browsers vs Node.js. Include task queues, microtasks, rendering ticks, and I/O.
54. Why does setTimeout(fn, 0) still run after Promise.then callbacks? Explain with microtask/macrotask ordering.
55. Describe how requestAnimationFrame and requestIdleCallback work and when to use each for UI updates.
56. Explain how long-running JS blocks impact rendering and input responsiveness. How can you break work into chunks to keep UI responsive?
57. Discuss timers throttling in inactive tabs, background pages, and mobile. How do browsers change timer semantics for power-saving?
58. Explain how layout, paint, and composite steps are triggered from JavaScript DOM changes and how to avoid forced synchronous layouts (reflows).

---

### **Modules, packaging, bundling & deployment (59–64)**

59. Explain ES modules vs CommonJS: live bindings, circular dependencies, static analysis, and tree-shaking implications.
60. Describe named exports vs default exports and the tradeoffs for API design and refactoring safety.
61. How does code-splitting work at a bundler level? Explain dynamic import, chunking strategies, and preloading/prerendering.
62. Discuss tree-shaking pitfalls: side effects, re-exported modules, and how to design modules to be tree-shakeable.
63. Explain source maps: how they map transpiled/bundled code back to originals and common troubleshooting when breakpoints don’t match.
64. Describe strategies for producing modern+legacy bundles (differential serving) and automated toolchains to manage browserslist/targets.

---

### **Memory management, garbage collection & performance (65–70)**

65. Explain how modern JS engines implement garbage collection (mark-and-sweep, generational). How do object lifetimes affect GC behavior?
66. Describe common sources of memory leaks in frontend apps (forgotten timers, DOM references, closures) and techniques to detect them.
67. Explain how to profile memory usage in Chrome DevTools, interpret heap snapshots, and identify detached DOM trees.
68. Discuss performance considerations for arrays and objects (dense vs sparse arrays, using push vs indexing, avoiding polymorphism).
69. Explain how to optimize re-renders in a UI: memoization strategies, structural sharing, and immutable data patterns.
70. Describe how to optimize critical-path assets (fonts, images, JS), defer non-critical work, and measure impact with RAIL or web-vitals.

---

### **Design patterns, architecture & API design (71–76)**

71. Explain the tradeoffs between controlled vs uncontrolled components in UI libraries and how to design component APIs for flexibility.
72. Discuss Single Responsibility Principle and separation of concerns in frontend code — how to structure modules and components in medium-sized apps.
73. Describe how to design an idempotent client-side API layer that handles retries, deduplication, caching, and optimistic updates.
74. Explain how to implement a plugin or middleware system for a frontend library (compose, order, error isolation).
75. Compare pub/sub, observer, Redux-like state stores, and CQRS/event-sourcing approaches for state management in complex apps.
76. Describe how to design a reusable component library: theming, style isolation, API stability, accessibility, and documentation considerations.

---

### **Error handling, diagnostics & debugging (77–80)**

77. Explain best practices for error handling in async code: structured errors, wrapping, preserving stack traces, and Sentry integration.
78. Walk through debugging a race condition in frontend code. What tools and strategies do you use to reproduce and fix it?
79. Describe symbolication and sourcemap handling for production errors. How do you ensure useful stack traces from transpiled code?
80. Explain how to instrument performance and user behavior (metrics vs logs vs traces) in a privacy-conscious way.

---

### **Security, data handling & best practices (81–84)**

81. Explain XSS attack vectors in a modern SPA: DOM-based, reflected, stored; how templating, innerHTML, and user input lead to vulnerabilities and how to prevent them.
82. Describe CSRF in single-page apps and mitigation strategies when using cookies vs token-based auth.
83. Discuss Content Security Policy (CSP) design for an app that loads scripts, styles, and third-party widgets. What are common pitfalls when deploying CSP?
84. Explain how to securely store tokens (access/refresh) in the browser and tradeoffs of cookies, localStorage, IndexedDB, and in-memory solutions.

---

### **Type systems, gradual typing & TS interop (85–88)**

85. When migrating a large JS codebase to TypeScript, what incremental strategies would you use? Explain tsconfig, allowJs, and declaration files.
86. Describe structural vs nominal typing and how TypeScript’s structural typing model affects library design and refactoring.
87. Explain soundness limitations of TypeScript (e.g., any, type assertions, covariance/contravariance). How do you mitigate soundness issues in a codebase?
88. How do you design runtime validation for inputs (e.g., zod/io-ts) to complement static typing? When is runtime validation necessary despite types?

---

### **Iterators, generators, async iterators & streams (89–94)**

89. Explain the iterator protocol and how it powers for-of, spread, and destructuring. Show how to implement a custom iterator.
90. Describe generator functions: how yield works, how return and throw propagate, and practical use-cases for state machines and lazy sequences.
91. Explain async iterators and how they compare to callbacks, promises, and Observables. Provide examples with streaming data and backpressure.
92. Show how to implement a pipeline of synchronous and asynchronous transforms using iterators/generators. Discuss error propagation.
93. Discuss integration of Node/Fetch streams with async iterators in the browser (ReadableStream.getReader) and how to process streaming responses efficiently.
94. Explain memory and performance considerations when consuming large streams in the browser and techniques to avoid buffering entire payloads.

---

### **Reflect, Proxy, meta-programming & advanced APIs (95–100)**

95. Explain Reflect API and how it complements Proxy. Give examples where Reflect helps preserve default behavior inside traps.
96. Describe Proxy traps in detail (get, set, has, ownKeys, getOwnPropertyDescriptor, defineProperty, etc.) and performance/correctness caveats.
97. Show how to use Proxies to implement reactive systems (e.g., shallow vs deep reactivity), and discuss pitfalls such as property enumeration and identity.
98. Explain WeakMap/WeakSet semantics, why keys must be objects, and use-cases for attaching hidden per-object metadata.
99. Discuss advanced ES features such as private class fields (#), decorators (proposal state), and how they change encapsulation patterns.
100. Explain how to introspect and instrument runtime behavior for debugging or APM (wrapping functions, monkey-patching, and safely restoring original behavior).

