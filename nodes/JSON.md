---
aliases:
context:
- "[[Data Structures]]"
---

# JSON

JSON is central to JS work.

---
### Basics
- a text format for representing structured data
- looks a lot like JS object but stricter
- widely used for APIs, config files, databases, and storage

### Allowed data types in JSON
- objects
- arrays
- strings
- numbers
- booleans
- null

*Not allowed* `undefined`, functions, `NaN`, `Infinity`, comments, or trailing commas


### Parsing & Stringifying
```js
    const obj = { name: "Alice", age: 25 };

    // Object → JSON string
    const jsonStr = JSON.stringify(obj);
    // '{"name":"Alice","age":25}'

    // JSON string → Object
    const parsed = JSON.parse(jsonStr);
    // { name: "Alice", age: 25 }
```

Custom serialization:
```js
    JSON.stringify(obj, ["name"]); // only keep "name"
```

Revivers on parse (transform values while parsing)
```js
    const data = '{"date":"2025-09-15"}';
    const parsed = JSON.parse(data, (key, value) =>
      key === "date" ? new Date(value) : value
    );
    // parsed.date is a Date object
```

### Common pitfalls
1. Keys must be in double quotes
```js
    { "name": "Alice" } ✅
    { name: "Alice" } ❌
```

2. Only UTF-8 text - No raw binary (use base64 if needed)
3. Date objects are not supported - must be strings (ISO format)
