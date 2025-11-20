---
aliases:
context:
- "[[Computer science]]"
---

# Heap

---
Upon compilation our code is translated into binary machine code, a sequence of instructions that need to be loaded in memory when our program is launched. This region is called the `Text` segment.

There are other regions such as `Initialized data` and `Uninitialized data`, and the `Stack`. The common thing between these regions is that their size is fixed.

The `Heap` however is a region which is capable of expansion as needed.

When we requestmemory via a system call, the OS doesn't respond with exactly the amout fo memory we need. Instead, it responds by giving us a memory chunk. The ability to request as many memory chunks as we want makes the amount of memory that can be allocated on the heap virtually unlimited.

Every bite of memory is accessible by an address. Addresses are represented by integers which have a fixed size known at compile time.
Instead of directly pushing data onto the stack, we opt to store it in the heap. Subsequently, in the stack, we only store the memory address in the heap where that data resides. These addresses are called `pointers` in low-level languages.

Unlike the Stack, in the Heap there is no guarantee of the order in which values will be removed.
Fragmentation on the Heap is essentially inevitable. Whenever we need to allocate space for a value in the heap, we should check if any of these holes are sufficiently large, because if so, we can bypass the overhead of invoking a system call (to request more memory).
There are 3 common strategies to pick a region to utitilize:
- choose the first hole that is large enough to accommodate out value
- select the smallest hole that is large enough for our value
- opt for the largest available hole where our value can fit
However, none of the above avoid fragmentation.

Values cannot grow or shrink without overwritting other values.
The solution to the problem with fragmentation without additional system call (requesting more memory) are Data structures. The Linked list structure is a great example because the previous node keeps a pointer to the next node. Every node stored in the heap contains an element and a pointer to the next node. When we need to add an element, we allocate memory on the heap for a new node and ensure that the last element of the linked list points to the new node, which becomes the new last node. With linked lists, we don't need large amounts of contiguous memory. In fact, they take advantage of the holes that appear over the heap. However, Linked lists have drawbacks, one of which is that nodes are scattered throughout the heap, leading to decreased probabilitites of cache hits.


### Why is Heap feared?

1. Performance penalties:
- allocations require searching available sub-regions within the Heap
- allocation may require a System call
2. Runtime errors:
- memory leaks
- null pointers
- dangling pointers
3. Fragmentation


### Benefits of using the Heap

- dynamic size
- large memory allocations
- fast accessing times if used correctly
