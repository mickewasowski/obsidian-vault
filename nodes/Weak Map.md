---
aliases:
context:
  - "[[JavaScript]]"
  - "[[Keyed Collections]]"
---


# Weak Map

WeakMap is a Map-like collection of key/value pairs whose keys must be objects, it removes them once they become inaccessible by other means.

---

Important differences from Maps:

- keys must be objects (not strings, numbers, or booleans)
- keys are "weakly held" => if no other references exist to that object, it can be garbage-collected
- not iterable => you can't loop over all keys/values
- useful for storing private or temporary data about objects

##### Creating a WeakMap

```js
const wm = new WeakMap();

const obj1 = {};
const obj2 = {};

wm.set(obj1, "data for obj1");
wm.set(obj2, "data for obj2");

console.log(wm.get(obj1)); // "data for obj1"
```

##### Key methods

- `set(key, value)` store a value with object `key`
- `get(key)` retrieve the value
- `has(key)` check if key exists
- `delete(key)` remove entry

```js
const wm = new WeakMap();
const el = document.createElement("div");

wm.set(el, { clicked: 0 });

console.log(wm.has(el)); // true
console.log(wm.get(el)); // { clicked: 0 }

wm.delete(el);
console.log(wm.has(el)); // false
```

##### Why WeakMap is _weak_

The weakness means if the object key has no other references, it will be automatically removed from the WeakMap by the garbage collector.

```JavaScript
let obj = { name: "temp" };
const wm = new WeakMap();

wm.set(obj, "some data");

console.log(wm.get(obj)); // "some data"

// Remove last reference
obj = null;

// Now obj and its data in WeakMap will be garbage-collected eventually
```

##### Real-world uses

1. Private data for objects
   You can simulate private fields for objects/classes without exposing them.
```JavaScript
const privateData = new WeakMap();

class User {
  constructor(name, password) {
    this.name = name;
    privateData.set(this, { password });
  }

  checkPassword(pw) {
    return privateData.get(this).password === pw;
  }
}

const u = new User("Alice", "secret");
console.log(u.checkPassword("secret")); // true
console.log(u.checkPassword("wrong"));  // false
```

2. DOM element metadata
```JavaScript
const elementData = new WeakMap();

function registerElement(el) {
  elementData.set(el, { clicked: 0 });

  el.addEventListener("click", () => {
    const data = elementData.get(el);
    data.clicked++;
    console.log(`${el.tagName} clicked ${data.clicked} times`);
  });
}

const button = document.createElement("button");
registerElement(button);
```
If the button is removed from the DOM and garbage-collected, its data in the WeakMap disappears automatically.


| Feature                         | Map           | WeakMap           |
| ------------------------------- | ------------- | ----------------- |
| Keys can be primitives          | Yes           | No (objects only) |
| Iterable (for…of, keys, values) | Yes           | No                |
| Size property                   | Yes (`.size`) | No                |
| Keys garbage-collected          | No            | Yes               |


### Rule of thumb
- Use `Map` when you need general-purpose key-value storage and iteration
- Use `WeakMap` when you need to attach hidden, temporary data to objects, especially DOM elements, without risking memory leaks.
