---
aliases:
context:
- "[[Computer science]]"
---

# Array List vs Linked List

---
Arrays can't grow and they are limited to storing only one kind of element at a time.

An array doesn't have information about it's size. Therefore it doesn't have length property or a way to validate if the index you're trying to access is in it's bounds.
When accessing memory out of the bounds of an array there are two posibilities:
- your program will be terminated by the OS with a Segmentation fault error if you're trying to access memory out of the memory limit
- if the array is located further away from the memory limit, the OS will NOT terminate our program since we're accessing memory within our process' memory boundaries.


### Linked List (struct)
We only need to maintain a reference to the first node in the stack. When we wish to add a new node we search for a space big enough for that node. Then we update the last node of the list to point to the new node, which becomes the new last one.

LinkedLists are not optimal for performance because of their nodes being scattered all over the Heap.
The cache's sole purpose is to store a copy of a small region of memory. The cache of the CPU stores contiguous regions of memory, this is why LinkedLists are not optimal for Cache Hit.
Fetching data from memory takes time relative to the CPU's speed. But if the data is present in the cache loading it to the Registers is a lot faster.
`Cache Hit` - data is found in the CPU cache
`Cache Miss` - data is NOT in the CPU cache


### Array List
With Array Lists we still use arrays but in a smarter way. Instead of just holding a reference to that array we create a Data type that holds that reference, and some additional information about the array. When created this data type allocates memory for an empty array, the capacity attribute indicates how many elements the array can hold, the length attribute indicates how many elements the array contains at any given time.
```c
struct ArrayList {
    items: *[i16],
    capacity: usize,
    lenght: usize
}

let my_list = ArrayList::new();
```
The idea behind this data type is that it will handle the array for us. It comes with some associated methods - `new, push(self, element: i16), get, remove`.
If the array is full and we want to add more elements than the current capacity of the array, we need to allocate a larger array to fit more elements. Typically we allocate new array twice as long as the full array. During this process we update both the capacity and the reference of the new array. This involves copying the values from the old array into the new array. Once the new array has the copied values the old array is no longer needed, so we free it's memory. Finally with the new space we can add the new element and update the array length.

It is best if you can allocate the memory you will need upon creation, or at least approximately. This way you'll have less frequent allocations, thus better performance.


### Arrays in JavaScript
In JavaScript arrays are actually Hash Maps.

```js
let my_arr = [];
my_arr['hello'] = 'world';
my_arr[1_000_000] = 'test'; // it's not actually allocating memory for 1_000_000 items, just this one
```
