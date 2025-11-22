---
aliases:
context:
- "[[Computer science]]"
---

# Stack

Follows the LIFO (last in first out) principle.

---
### Why the Stack is fast

All it's memory is preallocated at the beginning of our program's execution so there's no need to request memory from the OS on the fly.


The Stack's space is limited, so if we push too many elements and run out of space we say the "Stack has overflowed".


### Execution stack (a.k.a. Program stack, a.k.a. Hardware stack)

When we want to allocate space for our program we first ask the Operating system to provide us with memory.

The Operating system acts like a mediary because if we try to use memory that is used by another program the OS will kill our program (terminate the program's execution for safety reasons). This is when we'd encounter the error `Segmentation fault (core dumped)`.

The OS doesn't provide memory for all our program, it provides a chunk where we can freely read and write.
If we don't organize our memory correctly, even if there is enough free memory but we can't store data due to the lack of contiguous space. This problem is called External fragmentation. In this case the only way to store our data is to request a new chunk of memory. Asking for more memory can be costly in performance and it takes time.

When the OS allocates memory for our program it doesn't track if we utilize it or not. It's sole awareness is that region of memory belongs to our program. If another program requires memory it will have to put it's data somewhere else.

* _Memory is finite!_ What do we do if all the memory is already is use by other programs?
Modern OS leverage Storage as if it were additional memory in the absense of free memory. In Linux systems such Storage memory has it's own partition called `swap`. This is what we call Virtual memory.

* CPU cache - it is a small dedicated memory located in the processor where a copy of a memory region is stored. This way when the CPU requires data for manipulation or an operation it can promptly retrieve it from the cache instead of searching for it in the main memory. When the necessary memory is present in the cache we call it a `Cache Hit`, however if the required data is not present in the cache we call it a `Cache Miss`. In such cases the CPU is compeled to wait for the data to be fetched from the memory encuring additional time. This process is completely invisible from the developers, and it's the hardware and not the OS to decide what memory region is stored in the cache.
If we care about performance what we can do is keep our data as compact as possible.

> Locality - this is known term for low-level language developers. This concept of keeping the data compact so it would fit in the cache of the CPU is called Locality.

When our program starts the `main()` function serves as our entry point in the Stack. Each variable we encounter it's value is stacked in this designated region. This is where the term the stack becomes aparent.
The memory address marking the beginning of the Stack is refered to as `Stack Origin`, while the `Stack Pointer` refers to the top most item on the Stack.
The `Stack Pointer` is also stored in memory, however there is a special space in the CPU called the `Stack Register`.
To write on the Stack what needs to happen is get the Stack Pointer, add 1 and that is the address of the memory where we can write data.

`Stack Frame` - this is a subregion for each function's data memory. When executing functions we need to know where to reset the Stack to when the function finishes executing.

`return link` - when a function is expected to return a value, we allocate a distinct place called the return link.
