---
aliases:
context:
- "[[Data Structures]]"
---

# Indexed collections

Indexed collections are collections that have numeric indices i.e. the collections of data that are ordered by an index value.

---
## Arrays
Array in JavaScript is an ordered set of values that has a numeric index.
They allow you to access elements by the numeric index.
Ordered lists of values. They are highly versatile data structure.

> Key features:
1. Heterogeneous - they can store data of any type (strings, numbers, boolean, objects, etc.) within the same array
2. Dynamic size - they can grow or shrink in size as needed, with elements added or removed
3. Sparse - they can have "holes" where indexes are not assigned a value

> When to use them - they are the go-to data structure for almost all general purpose tasks:
1. Storing lists of data fetched from an API 
2. Managing UI components (list of items in a to-do list, etc.)
3. Implementing queues, stacks, and other basic data structure

> Key methods:
1. `map()`, `filter()`, `reduce()` - for functional programming and data transforming
2. `forEach()`, `for..of` - for iteration
3. `push()`, `pop()`, `shift()`, `unshift()` - adding/removing elements
4. `slice()`, `splice()` - for extracting and modifying parts of an array
5. `indexOf()`, `find()` - for searching

> Performance - while they are highly optimized, their flexibility comes with overhead. For extremely high-performance numerical computations (WebGL) better use typed arrays. For the vast majority of frontend tasks, their performance is more than sufficient.


## Typed Arrays
Typed arrays are array-like objects that provide a mechanism for reading and writing raw binary data in memory buffers.
Here's how they differ from regular arrays:
1. Fixed-size and homogeneous - they are fixed in size once created and store elements of a single, specified numeric type. This allows for efficient memory usage.
2. Backed by an array buffer - doesn't directly store data. Instead, it's a "view" into an `ArrayBuffer`. An ArrayBuffer is a low-level, fixed-length binary data buffer.
3. Different "Views" - `Uint8Array`, `Float32Array` - interprets the bytes in the buffer as a specific data type

> When to use them - when working with performance-critical tasks and APIs that deal with binary data such as:
1. WebSockets (sending/receiving binary data)
2. File APIs (reading files as binary data)
3. WebGL and Canvas (manipulating pixel data)
4. Fetching and processing large binary file (e.g. images, audio)


> Key differences from regular arrays:
1. Fixed size - they cannot be resized like normal arrays
2. Homogeneous - all elements must be of the same type
3. Performance - they are significantly faster for numerical computations and memory manipulation because they don't have the overhead of regular arrays
