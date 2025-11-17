---
aliases:
context:
  - "[[JavaScript]]"
---

# Iterators and Generators

---
### Summary

- Iterable - something you *can iterate over* (collection-like)
- Iterator - something that *produces values one by one*
- Generator - a *function that creates an iterator* using `yield`
- Async generator - generator where each yielded value may be asynchronously produced


1. Iteration Protocols
- iterable protocol - an object is iterable if it defines:
```js
obj[Symbol.iterator](): Iterator
```
Where `Iterator` is an object that follows the iterator protocol.

Built-in iterables:
- arrays
- strings
- maps
- sets
- dom nodelists
- generator objects (created by generator functions)

Usage:
Iterable objects can be consumed by:
- `for...of`
- spread syntax (`...`)
- array destructuring
- `Promise.all()`, `Array.from()`

1.1. Iterator protocol
An object is an iterator if it defines:
```js
iterator.next(): { value: any, done: boolean }
```

- `value` - next item in the sequence
- `done` - indicates termination of sequence

Example:
```js
const iterator = {
  current: 0,
  next() {
    if (this.current < 3) {
      return { value: this.current++, done: false };
    }
    return { value: undefined, done: true };
  },
};
```

Characteristics of Iterators:
- *Stateful* - the iterator must internally track progress
- *Pull-based* - consumers call `next()` to retrieve values
- *Lazy* - values are produced only when requested


2. Generators - a language-level abstraction that automatically implement the iterator protocol

2.1. Definition - a generator is created using `function*` syntax:
```js
function* example() {
  yield 1;
  yield 2;
}
```
Calling a generator function does *not* run it immediately - it returns a generator object (which is itself an iterator + iterable)

3. Key semantics of Generators

3.1. Execution Model
Generators act like pausable functions.
Execution moves in discrete steps:
- the function runs until it hits a `yield`
- execution pauses and returns `{ value, done }`
- `next()` resumes execution from where it left off
This makes generator functions cooperative coroutines.

3.2. Bidirectional data flow
`yield` is an expression, not a keyword-only statement
```js
function* sum() {
  const x = yield "x?";
  const y = yield "y?";
  return x + y;
}
```
`next(value)` sends data into the generator:
- the first `next()` value is always ignored
- subsequent `next(v)` assigns `v` to the last `yield` expression

3.3 Lazy sequences
Generators are ideal for producing sequences on demand:
```js
function* infinite() {
  let i = 0;
  while (true) yield i++;
}
```
Lazy evaluation ensures:
- small memory footprint
- potentially infinite datasets
- efficient streaming operations


4. Async Generators

4.1. Definition - async generators use `async function*` and produces promises:
```js
async function* updates() {
  while (true) {
    const data = await fetch("/api/info").then(r => r.json());
    yield data;
  }
}
```
Consumed with:
```js
for await (const item of updates()) {
  console.log(item);
}
```
Use cases:
- live data streams
- socket-like polling
- chunked API responses

### Practical use cases

```js
class Range {
  constructor(start, end) {
    this.start = start;
    this.end = end;
  }
  *[Symbol.iterator]() {
    for (let i = this.start; i < this.end; i++) {
      yield i;
    }
  }
}
```
