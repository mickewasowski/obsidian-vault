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

## Typed Arrays
Typed arrays are array-like objects that provide a mechanism for reading and writing raw binary data in memory buffers.
Here's how they differ from regular arrays:
1. Fixed-size and homogeneous - they are fixed in size once created and store elements of a single, specified numeric type. This allows for efficient memory usage.
2. Backed by an array buffer - doesn't directly store data. Instead, it's a "view" into an `ArrayBuffer`. An ArrayBuffer is a low-level, fixed-length binary data buffer.
3. Different "Views" - 
