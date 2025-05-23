---
aliases:
context:
- "[[JavaScript]]"
---

# Garbage collection (JavaScript)

Garbage collection is an automatic process managed by the JS engine.

---
## Overview
Garbage collection is an automatic process managed by the [[JS engine]]:
- V8 in Chrome
- SpiderMonkey in Firefox
It's job is to free up memory by removing data that is no longer accessible or needed.

### Key concepts:
1. JavaScript's garbage collection is primarily based on reachability:
	1.1. reachable values are those that can be accessed or used in the program
	1.2. if a value is not reachable, it is considered *garbage* and is eligible for collection

### A value is considered reachable if:
1. is a global variable
2. is a local variable in a current function call
3. referenced from another reachable object (like a property or array element)


## Garbage collection process:

The JS engine runs the garbage collection process periodically. The main algorithm used is called  `Mark-and-Sweep`:

###### 1. Mark Phase
- The JS engine start from a set of roots (global objects, current function stack variables, etc.).
- It recursively follows all references from these roots and marks all reachable objects

###### 2. Sweep Phase
- It then scans through memory and collects all **unmarked** (unreachable) objects, freeing that memory.


## How JS engine decides to run the garbage collection process:
1. Automatically decides when to run the garbage collection process based on internal [[Heuristic]]s:
	- how much memory is currently being used
	- how many allocations have occurred
	- system memory pressure
	- time since the last garbage collection cycle	
2. Periodically doesn't mean on a fixed schedule like a timer. Instead it runs it when:
	- memory usage reaches a certain threshold
	- the call stack is empty (during idle time)
	- an object allocation fails due to lack of memory
	- based on profiling data and heuristics the engine gathers over time


### Developers tips:
- You don't need to **manually manage memory**, but:
	- avoid holding references to large objects when they're no longer needed
	- be cautious with with global variables, closures, and event listeners - they can keep things alive unintentionally