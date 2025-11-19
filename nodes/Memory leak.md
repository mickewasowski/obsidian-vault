---
aliases:
context:
- "[[JavaScript]]"
---

#wip

# Memory leak

A memory leak exists when your program continously alocates memory (a fixed resource) without releasing it.

---
In JavaScript, memory leaks commonly occur within heap allocated memory, where short lived objects are attached to long lived ones and the Garbage Collector cannot safely de-allocate that memory as it is still referenced from the root set (the global object).


### Performance profiler in Chrome browser

> [!warning] When measing performance it is important to do so in an Incognito window. If we do this in a normal window the measurement data would include all browser extensions, making it harder to identify issues caused by our own code.

1. Open Incognito browser window
2. Navigate to Performance tab
3. Check the *Memory* checkbox
4. Click Record icon


### Memory tab

In the Memory tab after clicking on the Take Snapshot button we generate a report about the Heap.
When we filter by "Detached" we can see detached nodes that are still being referenced by the heap.
