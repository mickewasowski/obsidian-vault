---
aliases:
context:
- "[[JavaScript]]"
- "[[Keyed Collections]]"
---


# WeakSet

WeakSet objects are collection of objects. Each object may occur only once, all objects are unique in a `WeakSet`.

---

### What it is

1. It can _only_ contain objects and nothing else
2. The references to objects inside a `WeakSet` are **weak** -> meaning if there are no other references to an object, it can be _garbage collected automatically_
3. It is **not enumerable** -> you can't iterate over a `WeakSet` or get its size

> Syntax

```JavaScript
const ws = new WeakSet();

const obj1 = { name: "A" };
const obj2 = { name: "B" };

const ws2 = new WeakSet([obj1, obj2]);
```

> Methods
 `WeakSet` is simpler than `Set`. It only has **three methods**:

1. `add(value)`

   ```JavaScript
   const ws = new WeakSet();
   const obj = {};
   ws.add(obj);
   ```

2. `has(value)`

   ```JavaScript
   ws.has(obj); // true
   ```

3. `delete(value)`
   ```JavaScript
   ws.delete(obj); // true
   ws.has(obj);    // false
   ```

> Differences from Set

| Feature            | `Set`                                             | `WeakSet`                                         |
| ------------------ | ------------------------------------------------- | ------------------------------------------------- |
| Values             | Any type (primitives + objects)                   | Only objects                                      |
| Iteration          | Iterable (`for...of`, `.forEach`)                 | ❌ Not iterable                                   |
| Size               | `.size` property available                        | ❌ No size                                        |
| Garbage Collection | Strong refs (objects stay until manually removed) | Weak refs (objects auto-removed if no other refs) |


### When to use
- to track objects temporarily without preventing garbage collection
- useful in scenarios like:
    - tagging objects (e.g. marking them as processed)
    - private data storage in classes


> [!tip] Use `WeakSet` if you just need to track object presence without worrying about memory leaks.
> If you need iteration or primitives, stick with `Set`.
