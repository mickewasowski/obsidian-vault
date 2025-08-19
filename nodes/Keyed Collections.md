---
aliases:
context:
  - "[[JavaScript]]"
---


# Keyed Collections

Keyed collections are data collections that are ordered by key and not by index.

---

Keyed collections are associative in nature.
They are iterable in the order of insertion.

Keyed collectios examples:

1. Map
2. Set
3. Weak Map
4. Weak Set

### Map
[Map](nodes/Map.md)
A `Map` is a key-value store where keys can be of *any type*.
It preserves insertion order, allows iteration, and has `.size()`, `.set()`, `.get()`, `.delete()`, and `.has()`.
Best for dictionaries, caching, and when you need keys beyond just strings.


### Weak Map
[Weak Map](nodes/Weak%20Map.md)
A `WeakMap` is like a `Map` but only accepts *objects as keys*, not primitives.
Its keys are weakly held, so if an object key is no longer referenced elsewhere, it gets garbage-collected automatically.
It is not iterable and is mainly used for storing private/hidden data tied to object lifetimes.


### Set
[Set](nodes/Set.md)
A `Set` is a collection of unique values (no duplicates), storing primitives or objects.
It remembers insertion order and allows iteration, size checking, and set operations (uninion, intersection, difference).
Best for removing duplicates, fast lookups, and working with unique collections.


### WeakSet
[WeakSet](nodes/WeakSet.md)
A `WeakSet` is like a `Set` but only stores objects, not primitives.
Its references are weak, so objects are garbage-collected when no other references exist.
It cannot be iterated over or checked for size, making it useful for temporary tracking of objects.
