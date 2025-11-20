---
aliases:
context:
- "[[Computer science]]"
---

# ArrayList vs LinkedList

---
Arrays can't grow and they are limited to storing only one kind of element at a time.

An array doesn't have information about it's size. Therefore it doesn't have length property or a way to validate if the index you're trying to access is in it's bounds.
When accessing memory out of the bounds of an array there are two posibilities:
- your program will be terminated by the OS with a Segmentation fault error if you're trying to access memory out of the memory limit
- if the array is located further away from the memory limit, the OS will NOT terminate our program since we're accessing memory within our process' memory boundaries.

### LinkedList

LinkedLists are not optimal for performance because of their nodes being scattered all over the Heap.
The cache of the CPU stores contiguous regions of memory, this is why LinkedLists are not optimal for Cache Hit.
