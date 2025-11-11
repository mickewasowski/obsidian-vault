---
aliases:
context:
- "[[Computer science]]"
---

# Fixed size types

---
_Memory is limited._
The purpose of variable types is to tell the system precisely how much memory you're program will use.

Computers work with groups of 8 bits called bytes.
The minimum number of bits you can use to represent something is 8.

In scripting languages the _Interpreter_ decides where and how much space in memory your variables require.
In most cases you end up using a lot more memory than necesarry.

In Javascript `String` and `Integer` actually take up several bytes in memory.
You don't have control over the memory allocation for your variables and on top of that the _Interpreter_ uses additional memory for each of them.
This produces an overhead over simple arithmetic operations or data manipulation.
Tags (the additional data the _Interpreter_ sets) must be initialized, read, compared, and written at runtime. All of these operations add overhead to a simple addition operation.
All of these tasks add time (CPU time), which means that most of the time the _Interpreter_ is executing those tasks instead of actually executing your code.

This is why **Statically typed** languages (C, Rust) are faster in executing than **Dynamically typed** languages (JS, Python).
