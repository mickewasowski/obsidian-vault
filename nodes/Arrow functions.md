---
aliases:
context:
- "[[Functions]]"
---

# Arrow functions

---
An Arrow function expression has a shorter syntax compared to function expressions and does not have its own `this`, `arguments`, `super` or `new.target`.
Arrow functions are *always anonymous*.

Two factors influenced the introduction of arrow functions:
- shorter functions
- non-binding of `this`

```js
const arr = ['test', 'sample', 'expression'];

const lengths = arr.map((x) => x.length);
console.log(lengths); // [4, 5, 9]
```

Until arrow functions, every function defined its own [[this keyword]] value.
This proved to be less than ideal with an object-oriented style of programming.
```js
function Person() {
  // The Person() constructor defines `this` as itself.
  this.age = 0;

  setInterval(function growUp() {
    // In nonstrict mode, the growUp() function defines `this`
    // as the global object, which is different from the `this`
    // defined by the Person() constructor.
    this.age++;
  }, 1000);
}

const p = new Person();
```

In ECMAScript 3/5 the solution for this was to assign the this to a variable that could be closed over.
```js
function Person() {
  // Some choose `that` instead of `self`.
  // Choose one and be consistent.
  const self = this;
  self.age = 0;

  setInterval(function growUp() {
    // The callback refers to the `self` variable of which
    // the value is the expected object.
    self.age++;
  }, 1000);
}
```

An arrow function doesn't have it's own `this`, it uses the `this` from it's enclosing execution context.
```js
function Person() {
  this.age = 0;

  setInterval(() => {
    this.age++; // `this` properly refers to the person object
  }, 1000);
}

const p = new Person();
```
