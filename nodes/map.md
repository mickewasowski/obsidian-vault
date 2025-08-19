---
aliases:
context:
- "[[JavaScript]]"
- "[[Keyed Collections]]"
---


# Map

Keyed collection, saves insertion order, can use anything as both key and value.

---
Map is a collection of keyed data items, just like an `Object`, but the main difference is that Map allows keys of any type.
Holds key-value pairs and remembers the insertion order of the keys.
Any value (both objects and primitive values) may be used as either a key or a value.
`Map` has built-in methods for easy iteration and size checking.

##### Creating a Map:

```js
// Create an empty Map
const myMap = new Map();

// Create a Map with initial values
const users = new Map([
  ["id", 123],
  ["name", "Alice"],
  ["active", true],
]);

console.log(users);
```

##### Basic methods:

Settings values:
```JavaScript
myMap.set("name", "Bob");
myMap.set("age", 25);
myMap.set(true, "yes");
myMap.set({ key: "obj" }, "object as key");

console.log(myMap);
```

Getting values:
```js
console.log(myMap.get("name")); // Bob
console.log(myMap.get(true));   // yes
```

Checking keys:
```JavaScript
console.log(myMap.has("age"));  // true
console.log(myMap.has("salary")); // false
```

Deleting keys:
```js
myMap.delete("age");
console.log(myMap.has("age")); // false
```

Size of a Map:
```js
console.log(myMap.size); // number of entries
```

##### Iterating over Maps

```js
for (let [key, value] of users) {
  console.log(key, value);
}
```

Other iteration methods:
```js
users.forEach((value, key) => {
  console.log(key, value);
});

// Get only keys
for (let key of users.keys()) {
  console.log(key);
}

// Get only values
for (let value of users.values()) {
  console.log(value);
}
```

| Feature | Map | Object |
| --------------- | --------------- | --------------- |
| Any type as key | Yes | No (mostly strings/symbols) |
| Keeps order | Yes | No guarantee |
| Easy size check | Yes (`.size`) | No (need `Object.keys(obj).length`) |
| Performance | Better for frequent additions/deletions | Not as optimized |


##### Converting betwen Objects & Maps
```js
// Object → Map
const obj = { a: 1, b: 2 };
const mapFromObj = new Map(Object.entries(obj));

// Map → Object
const mapToObj = Object.fromEntries(mapFromObj);
```


### When to use Map:
1. When you need keys that aren't just string (like objects, numbers, booleans)
2. When you will be frequently additing/removing entries
3. When you care about the insertion order


### Real examples:
1. When you want to count how many times a word is present:
```js
const text = "the cat sat on the mat and the cat slept";

const wordCount = new Map();

for (let word of text.split(" ")) {
  wordCount.set(word, (wordCount.get(word) || 0) + 1);
}

console.log(wordCount);
// Map(7) { 'the' => 3, 'cat' => 2, 'sat' => 1, 'on' => 1, 'mat' => 1, 'and' => 1, 'slept' => 1 }
```

2. Tracking logged-in user sessions:
``` js
const sessions = new Map();

const session1 = { user: "Alice" };
const session2 = { user: "Bob" };

sessions.set(session1, { lastLogin: Date.now() });
sessions.set(session2, { lastLogin: Date.now() });

console.log(sessions.get(session1)); // { lastLogin: ... }
```


3. Tracking DOM elements:
```js
const elementInfo = new Map();

const button = document.createElement("button");
const input = document.createElement("input");

elementInfo.set(button, { type: "button", clicked: false });
elementInfo.set(input, { type: "input", value: "" });

// Later...
elementInfo.get(button).clicked = true;
console.log(elementInfo.get(button));
```

