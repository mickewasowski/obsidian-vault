---
aliases:
context:
- "[[JavaScript]]"
---

# Memory management

In JavaScript memory is automatically allocated when objects are created, and memory is freed when the objects are no longer used (*garbage collection*).
An object is eligible for garbage collection when there are no references to it.

---
### Memory lifecycle

1. Allocate the memory you need
2. Use the allocated memory (read/write)
3. Release (free) the allocated memory when it is not needed anymore

> The second part is explicit in all languages. The first and last parts are explicit in low-level languages but are mostly implicit in high-level languages like JavaScript.

### Allocation in JavaScript

1. Value initialization - JS automatically allocates memory when values are initially declared (depending on the type of the value)
2. Allocation via function calls
    - some function calls result in object allocation
```js
const d = new Date(); // allocates a Date object
const e = document.createElement("div"); // allocates a DOM element
```
    - some methods allocate new values or objects
```js
const s = "string";
const s2 = s.substring(0, 3); // s2 is a new string
// Since strings are immutable values,
// JavaScript may decide to not allocate memory,
// but just store the [0, 3] range.

const a = ["yeah yeah", "no no"];
const a2 = ["generation", "no no"];
const a3 = a.concat(a2);
// new array with 4 elements being
// the concatenation of a and a2 elements.
```
3. Using values - means reading and writing in allocated memory. This can be done by reading/writing the value of a variable/object property, or passing an argument to a function.
4. Release when the memory is not needed anymore - **most memory management issues occur at this phase**
    - the difficult part is determining when the allocated memory is no longer needed
    - here Garbage collection comes into play with it's memory monitoring algorithm


### Garbage collection

[[Garbage collection (Javascript)]]

1. References - an object is said to reference another object if the former has access to the latter (either implicitly (prototype) or explicilty (object property values)).

2. Reference-counting garbage collection (this is no longer used in modern JS engines) - this algorithm determines if on object has *any* other objects referencing it. If there are zeroreferences it is concidered "garbage". This however creates an issue with memory leaks when circular reference occurs. This means that when two objects point at each other even after the function had completed it's execution, according to this algorithm the memory remains unclaimable.

3. Mark-and-Sweep algorithm - this algorithm reduces the definition of "an object is no longer needed" to "an object is unreachable".
This algorithm lies on a set of objects called *roots*. In JavaScript, the root is the global object. The garbage collector starts from these roots and finds objects that are referenced by these roots, then all objects referenced by the latter, etc. This way the garbage collector finds all *reachable* objects and collects all non-reachable objects.

> There is no manual control over the garbage collector, and therefore no manual way to release memory.

4. Data structures aiding memory management
JavaScript offers several data structures that indirectly observe garbage collection and can be used to manage memory usage.

- [[Weak Map]] and [[WeakSet]]
[[https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Memory_management#weakmaps_and_weaksets]]

