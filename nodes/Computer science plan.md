---
aliases:
context:
---

#wip

# Computer science plan

---

# 6-Month CS + DSA Study Plan (with C)

Start: Day 1 = 10 Dec 2025  
Heavy period: Day 1–27 (until 5 Jan) → ~8h/day  
After that:  
- Weekdays: 1–2h/day  
- Weekends: 4–6h/day  

Goals:
- Learn C deeply
- Understand CPU, RAM, GPU, memory model
- Master DSA and algorithms (implemented in C)
- Learn OS, networks, databases, distributed systems, systems design
- Cover core CS math
- Build small systems/projects along the way

Resources referenced (you don't need all at once):
- C:
  - Beej’s Guide to C
  - "The C Programming Language" (K&R)
- Systems/Architecture:
  - "Computer Systems: A Programmer’s Perspective" (CSAPP)
- OS:
  - "Operating Systems: Three Easy Pieces" (OSTEP)
- Networks:
  - Beej’s Guide to Network Programming
- Algorithms:
  - MIT 6.006 (YouTube OCW)
  - CLRS or any structured DSA text
- DSA basics:
  - roadmap.sh Data Structures & Algorithms
  - W3Schools DSA

Use this note as a living document: check off days, add links, paste code snippets, etc.

---

## Daily Structure Templates

### During recovery (Days 1–27)
Total: ~8 hours/day

- Session 1 (2h): Theory (reading/watching)
- Break (30m)
- Session 2 (2h): C coding / exercises
- Lunch (1–1.5h)
- Session 3 (2h): DSA/Algorithms / systems topics
- Break (15–30m)
- Session 4 (1–1.5h): Project / recap / notes

### After 5 Jan (Days 28+)

Weekdays (Mon–Fri): 1–2h  
- 20–30m: theory / lecture  
- 40–60m: coding practice / implementation in C  
- 10–20m: quick summary note

Weekends (Sat–Sun): 4–6h  
- 1–2h: deeper reading / lectures  
- 2–3h: implementation + exercises  
- 30–60m: project work / recap

---

# MONTH 1 (Days 1–27) – C, CPU, Memory, Intro DSA

Focus:
- C fundamentals
- CPU / RAM / caches / memory layout
- Pointers, malloc/free
- Basic data structures: arrays, strings, linked lists, stacks, queues, hash tables, trees intro, graphs intro
- GPU/graphics basics at a conceptual level

---

## Day 1 – CPU basics & C setup

Session 1 (CPU Fundamentals):
- Watch:
  - Branch Education – "How CPUs Work" (YouTube)
- Read:
  - Ben Eater – "How a CPU Works" (eater.net/cpu)
- Take notes on:
  - ALU, control unit, registers, instruction pointer
  - Fetch → decode → execute cycle
- Draw a diagram of the CPU pipeline.

Session 2 (C Setup & Basics):
- Install:
  - GCC/Clang
  - Your preferred editor/Neovim flow
- Write simple programs:
  - `hello.c`
  - Sum of two numbers
  - Average of an array (hard-coded small array)
- Practice compiling: `gcc main.c -o main`

Session 3 (Memory Hierarchy):
- Watch:
  - Computerphile – "Memory and Caches"
- Read:
  - GeeksForGeeks – "Cache Memory in Computer Organization"
- Notes:
  - Registers vs L1/L2/L3 vs RAM vs disk
  - Spatial vs temporal locality

Session 4 (Recap):
- Create Obsidian note:
  - "CPU Basics"
  - "Memory Hierarchy"
- Add diagrams and your own words.

---

## Day 2 – RAM, virtual memory & control flow in C

Session 1 (RAM & Virtual Memory):
- Watch:
  - Branch Education – "How RAM Works"
- Read:
  - Berkeley CS162 – virtual memory intro
- Notes:
  - Physical vs virtual address
  - Pages, page tables, page faults

Session 2 (C: Control Flow):
- Implement:
  - if/else cases
  - switch statements
  - for/while loops
- Exercises:
  - Write a program that prints multiplication table.
  - Sum only even numbers in an array.

Session 3 (Stack Frames):
- Read about call stack / stack frames (any CS article).
- Write a program with multiple functions:
  - `main -> f1 -> f2`
- Print addresses of local variables in each to see stack behavior.

Session 4 (Practice):
- Implement a "stack frame visualizer" in comments + prints.
- Summarize what happens when a function is called.

---

## Day 3 – Compilation model, functions, pointers

Session 1 (Compilation Model):
- Read:
  - Overview of stages: preprocessor, compiler, assembler, linker.
- Try:
  - `gcc -S main.c` to see assembly output.
- Note:
  - What is an object file?
  - What is a symbol?

Session 2 (Functions & Headers in C):
- Create:
  - `math_utils.h`, `math_utils.c` with some functions (add, subtract).
- Use:
  - `#include "math_utils.h"` in `main.c`.

Session 3 (Pointer Fundamentals):
- Implement examples:
  - `int *p = &x;`
  - Change x via p.
- Practice pointer arithmetic with arrays:
  - Print values via indexing and via pointer.

Session 4 (Exercises):
- Reverse an array using pointers only (no indexing).
- Write Obsidian note: "Pointers – intuition + examples".

---

## Day 4 – Memory layout, arrays, strings, malloc intro

Session 1 (Program Memory Layout):
- Read:
  - Memory layout of a C program (text/data/bss/heap/stack).
- Draw:
  - One diagram with all segments labeled.

Session 2 (Arrays & Strings in C):
- Implement:
  - `my_strlen`
  - `my_strcpy`
  - `my_strcmp`
- Focus on:
  - Null-terminated strings

Session 3 (Dynamic Memory Basics):
- Learn:
  - `malloc`, `calloc`, `realloc`, `free`
- Write:
  - A program that allocates an array using malloc, fills it, prints it, and frees it.
- Intentionally cause:
  - A memory leak (forget to free) and note behavior.

Session 4 (Project):
- Implement:
  - `my_strdup` using malloc
  - `my_strcat` that returns a new string
- Take notes: "Heap vs Stack" with examples from your code.

---

## Day 5 – Heap internals, structs, linked list theory

Session 1 (Heap Allocation Deep Dive):
- Skim:
  - "What Every Programmer Should Know About Memory" – focus on conceptual sections about caches, memory allocation.
- Notes:
  - Fragmentation
  - Free lists (conceptual)

Session 2 (Structs in C):
- Define:
  - `struct Point { int x; int y; };`
- Work with:
  - Arrays of structs
  - Pointers to structs (`Point *p`)

Session 3 (Linked List Theory):
- Read:
  - Singly linked list basics from W3Schools DSA or similar.
- Notes:
  - Node structure
  - Head pointer
  - Traversal

Session 4 (Implementation – Singly Linked List in C):
- Implement:
  - `push_front`
  - `push_back`
  - `delete_value`
  - `print_list`

---

## Day 6 – Memory safety, file I/O, doubly linked list

Session 1 (Memory Safety):
- Read:
  - Common C memory bugs (dangling pointers, double free, buffer overflow).
- If possible:
  - Install valgrind and run a simple program to see memory report.

Session 2 (File I/O in C):
- Use:
  - `fopen`, `fclose`, `fgets`, `fprintf`, `fread`, `fwrite`
- Exercise:
  - Write and then read a simple text file with user data.

Session 3 (Doubly Linked List):
- Implement:
  - Node with `prev` and `next`
  - `push_front`, `push_back`, `remove`
  - Forward and backward traversal

Session 4 (Mini Project):
- Build: list-based phonebook
  - Each node = contact (name, phone).
  - Operations: add contact, list all, delete by name.

---

## Day 7 – CPU vs GPU, C recap, stack/heap practice

Session 1 (CPU vs GPU Architecture):
- Watch:
  - Branch Education – "How GPUs Work"
- Read:
  - High-level GPU intro (NVIDIA blog, Scratchapixel graphics pipeline overview).
- Notes:
  - CPU vs GPU: few powerful cores vs many simple cores
  - Why GPUs are good for parallel workloads.

Session 2 (C Recap):
- Reimplement small tasks without looking at previous code:
  - String functions
  - Linked list core methods

Session 3 (Stack vs Heap Drills):
- Write several small programs:
  - Allocate on stack vs heap
  - Return pointers correctly (never to stack locals).
- Try to guess memory segment for each variable and then confirm.

Session 4 (Weekly Recap):
- Create a "Week 1 Summary" note:
  - What you learned
  - What feels shaky
  - Questions for future you

---

## Day 8 – Dynamic array (vector) in C

Session 1 (Theory: Dynamic Array / Vector):
- Read:
  - Dynamic array concept (growable array).
- Understand:
  - Capacity
  - Size
  - Amortized analysis for push_back

Session 2–3 (Implementation in C):
- Implement:
  - `vector_create`, `vector_destroy`
  - `vector_push_back`
  - `vector_pop_back`
  - `vector_get` / `vector_set`
  - Automatic resize when full

Session 4 (Tests):
- Write a `main.c` that:
  - Pushes 1000 elements
  - Prints size, capacity changes
  - Verifies all values

---

## Day 9 – Stack & queue in C

Session 1 (Stack/Queue theory):
- Read:
  - Stack and queue from W3Schools DSA or GeeksForGeeks.

Session 2 (Stack implementation):
- Implement stack using dynamic array:
  - `stack_push`, `stack_pop`, `stack_peek`, `stack_is_empty`

Session 3 (Queue implementation):
- Implement queue using circular buffer:
  - `queue_enqueue`, `queue_dequeue`
  - Head/tail indices, wrap-around.

Session 4 (Use cases):
- Write small programs:
  - Reverse a string using stack.
  - Simulate a simple queue of tasks.

---

## Day 10 – Hash table (part 1, theory + design)

Session 1 (Hashing theory):
- Read:
  - Hash table articles (hash functions, collisions, load factor).
- Notes:
  - Separate chaining vs open addressing

Session 2–3 (Design hash table in C):
- Choose:
  - Key type = string
  - Value type = int or void* for extensibility
- Design:
  - `hash_table_entry`
  - `hash_table` struct with bucket array
  - `hash_function` for strings

Session 4 (Start implementation):
- Implement:
  - `hash_table_create`
  - `hash_function`
  - Basic `insert` without collisions handling yet.

---

## Day 11 – Hash table (part 2, chaining, resize)

Session 1–2 (Implementation):
- Add chaining:
  - Each bucket is a linked list
  - Implement `insert`, `get`, `remove`
- Manage:
  - Load factor, threshold for resizing

Session 3–4 (Resize + tests):
- Implement resize:
  - Allocate bigger bucket array, rehash entries
- Write tests that:
  - Insert many entries
  - Get random ones
  - Delete some
  - Validate everything works

---

## Day 12 – Trees (binary trees basics)

Session 1 (Theory: Binary Trees):
- Read:
  - Binary trees overview: nodes, left/right, height, depth.

Session 2 (Binary Tree Implementation):
- Define:
  - `struct Node { int value; Node *left; Node *right; };`
- Implement:
  - `insert` (not necessarily BST yet, just sample structure)
  - `print_preorder`

Session 3 (Traversals):
- Implement:
  - Preorder
  - Inorder
  - Postorder
- Practice:
  - Draw a tree and trace by hand.

Session 4 (Exercises):
- Write programs to:
  - Count nodes
  - Compute height
  - Count leaves

---

## Day 13 – Binary Search Tree (BST)

Session 1–2 (BST Implementation):
- Implement:
  - `bst_insert`
  - `bst_search`
  - `bst_find_min` / `bst_find_max`

Session 3 (BST delete):
- Implement:
  - Delete node with 0, 1, 2 children
- Practice:
  - Draw the tree before/after deletions

Session 4 (Use case):
- Build a simple "ordered set" using BST:
  - Insert
  - Check membership
  - Print sorted values.

---

## Day 14 – Balanced trees (AVL intro, optional deep dive later)

Session 1 (AVL Theory):
- Read:
  - AVL tree rotations, balance factor.

Session 2–3 (AVL Insert):
- Implement:
  - Height tracking
  - LL, RR, LR, RL rotations
- Only basic insertion is enough for now.

Session 4:
- Test:
  - Insert values that cause each type of rotation
- Note any confusion for later review.

---

## Day 15 – Sorting & searching algorithms (C implementations)

Session 1 (Searching):
- Implement:
  - Linear search
  - Binary search on sorted array

Session 2–3 (Sorting):
- Implement:
  - Bubble sort (for understanding)
  - Insertion sort
  - Selection sort

Session 4 (Initial performance feel):
- Sort arrays of:
  - 100, 1000, 10000 elements
- Measure approximate runtime with `clock()` and note differences.

---

## Day 16 – Merge sort and quicksort

Session 1–2 (Merge Sort):
- Understand:
  - Divide and conquer
- Implement:
  - Recursive merge sort with a helper `merge` function.

Session 3–4 (Quick Sort):
- Implement:
  - Quicksort with a pivot (e.g., middle element)
  - Partition function
- Compare results and performance roughly.

---

## Day 17 – Big-O and algorithm analysis

Session 1 (Theory):
- Read:
  - Big-O basics (Big-O, Big-Omega, Big-Theta).
- List:
  - Complexities of:
    - Dynamic array operations
    - Linked list operations
    - Hash table operations
    - Tree operations
    - Sorting algorithms

Session 2–3 (Analysis Practice):
- For each structure and algorithm implemented:
  - Write a short note with:
    - Time complexity of operations
    - Space complexity
- Try to reason *why*.

Session 4:
- Quick quiz to yourself:
  - "What is the complexity of X?" for 20–30 questions.

---

## Day 18 – Recursion basics & simple DP

Session 1 (Recursion):
- Write recursively:
  - Factorial
  - Fibonacci (inefficient version)
  - Sum of array

Session 2 (Stack visualization):
- Draw recursion trees.
- Show how many calls each function makes.

Session 3 (Intro DP):
- Convert Fibonacci recursion to:
  - Memoized recursion
  - Iterative DP

Session 4:
- Note:
  - Difference between brute recursion and DP.
  - Where you store subproblem results.

---

## Day 19 – Graphs I (representation, BFS)

Session 1 (Graph theory basics):
- Read:
  - Graphs, adjacency lists, adjacency matrices.

Session 2–3 (C Implementation):
- Represent graph as:
  - `vector` of adjacency lists OR
  - `struct Graph { int n; vector<int> *adj; }` (translated to C).
- Implement BFS:
  - Use queue
  - Print visited order

Session 4:
- Test BFS on:
  - Simple undirected graph
  - Directed graph

---

## Day 20 – Graphs II (DFS, topological sort)

Session 1 (DFS theory):
- Read:
  - DFS, recursion tree.

Session 2 (DFS implementation in C):
- Implement recursive DFS:
  - Use an array to track visited nodes.

Session 3 (Topological sort):
- Implement:
  - Topological sort using DFS on a DAG.

Session 4:
- Use:
  - Example DAG and verify order by hand.

---

## Day 21 – GPU architecture deep dive & graphics pipeline

Session 1 (GPU deeper theory):
- Read:
  - Intro to GPU programming and parallelism.
- Understand:
  - Threads, warps/wavefronts (conceptual)
  - Why memory access patterns matter.

Session 2–3 (Graphics Pipeline basics):
- Learn:
  - Vertex processing
  - Clipping
  - Rasterization
  - Fragment shading
  - Depth testing

Session 4:
- Create note:
  - "Graphics Pipeline"
  - Outline each stage in your own words.

---

## Day 22 – Software rasterizer (part 1)

Session 1 (Frame buffer in C):
- Design:
  - 2D array representing pixels (e.g., ASCII characters).

Session 2–3 (Basic drawing primitives):
- Implement:
  - `set_pixel(x, y, char)`
  - Clear screen
  - Dump buffer to console

Session 4:
- Implement:
  - Bresenham line algorithm to draw lines.

---

## Day 23 – Software rasterizer (part 2)

Session 1–2 (Triangles):
- Implement:
  - Filled triangle (scanline or barycentric method).

Session 3 (Simple scene):
- Draw:
  - 2–3 triangles forming a simple shape or letter.

Session 4:
- Note:
  - How rasterization relates to GPU pipeline.

---

## Day 24 – Malloc simulator (concept + design)

Session 1 (Malloc internals):
- Read:
  - High-level overview of malloc/free implementation ideas.

Session 2–3 (Design):
- Design:
  - A big static array as "heap"
  - Block header structure (size, free/used, next)
- Plan functions:
  - `my_malloc`, `my_free`

Session 4:
- Write header and minimal skeleton of code.

---

## Day 25 – Malloc simulator (implementation)

Session 1–3 (Implementation):
- Implement:
  - `my_malloc` to:
    - Find free block
    - Split block if necessary
  - `my_free` to:
    - Mark block as free

Session 4:
- Test:
  - Allocate and free multiple blocks
  - Print layout of your simulated heap.

---

## Day 26 – Malloc simulator (coalescing) + cleanup

Session 1–2 (Coalescing):
- Add:
  - Merge adjacent free blocks when freeing.

Session 3–4 (Refactor & document):
- Clean up code
- Write README-like note explaining how your allocator works.

---

## Day 27 – Big recap (Month 1)

Session 1–2:
- Review all notes from:
  - CPU, memory, C basics, DSA basics, graphs, GPU.

Session 3:
- Run through:
  - Small tests for all your core data structures.

Session 4:
- Write:
  - "Month 1 Retrospective" with:
    - What you know well
    - What feels weak
    - Plan for next months

---

# MONTHS 2–6 – Full CS + DSA Curriculum

From Day 28 onward:
- Weekdays: 1–2h/day
- Weekends: 4–6h/day

Instead of micro-scheduling every single calendar date (which would make this note insanely long and hard to use), the plan below is:

- Still day-level, but grouped into weeks.
- For each week:
  - Weekday days are labeled and specific.
  - Weekend days have separate, longer tasks.
- If you want, you can later expand each week into its own daily note.

Map:
- Month 2 ≈ Days 28–57
- Month 3 ≈ Days 58–87
- Month 4 ≈ Days 88–117
- Month 5 ≈ Days 118–147
- Month 6 ≈ Days 148–177

You can finish faster by doing extra on weekends or adding extra weekday time.

---

## MONTH 2 (Days 28–57) – DSA Deep Dive in C

Focus:
- Solidify and extend DSA in C
- Finish any gaps from Month 1
- Advanced trees, heaps, tries
- Advanced graph algorithms
- More sorting/searching variants
- Begin LeetCode-style problem solving (but implementing in C)

### Week 5 (Days 28–34) – Heaps & Priority Queues

Weekday template (Days 28–32, Mon–Fri, 1–2h each):
- Day 28:
  - Read: binary heap concept, min vs max heap.
  - Implement `heap_insert`, `heapify_up` (array-based).
- Day 29:
  - Implement `heap_extract_min` / `heap_extract_max`, `heapify_down`.
- Day 30:
  - Implement `build_heap` from unsorted array.
- Day 31:
  - Use heap to implement priority queue.
- Day 32:
  - Solve 1–2 problems using a heap (e.g. k-largest elements, merging k sorted lists conceptually).

Weekend (Days 33–34, Sat–Sun, 4–6h each):
- Deep exercise:
  - Implement both min and max heap variations in a reusable C library.
  - Benchmark heap sort vs quicksort on random arrays.
  - Write an Obsidian note summarizing heaps and priority queues.

---

### Week 6 (Days 35–41) – Tries, Sets, Maps

Weekdays (1–2h):
- Day 35:
  - Read: Trie (prefix tree) basics for strings.
  - Design `TrieNode` struct.
- Day 36:
  - Implement `trie_insert` for lowercase a–z words.
- Day 37:
  - Implement `trie_search`, `trie_starts_with`.
- Day 38:
  - Implement deletion from trie (optional if too complex; focus on insert/search).
- Day 39:
  - Implement a simple spell checker / autocomplete demo using trie.

Weekend (Days 40–41):
- Build:
  - A small command-line dictionary:
    - Load words into trie or hash map
    - Allow search, prefix search.
- Reflect:
  - Compare hash table vs trie trade-offs.

---

### Week 7 (Days 42–48) – Advanced Graphs (Shortest Paths, MST)

Weekdays:
- Day 42:
  - Read: weighted graphs, shortest path basics.
- Day 43:
  - Implement Dijkstra’s algorithm with a min-heap.
- Day 44:
  - Implement Bellman–Ford (even if slower, to understand).
- Day 45:
  - Read: Minimum Spanning Tree (MST), Kruskal and Prim.
- Day 46:
  - Implement Kruskal (using your own DSU / union-find).
- Day 47:
  - Implement Prim (using heap or simpler approach).

Weekend:
- Day 48–49:
  - Implement DSU (Disjoint Set Union) with path compression & union by rank.
  - Visualize:
    - Graph + MST in text form.
  - Solve 1–2 MST / shortest-path-style problems.

---

### Week 8 (Days 50–56) – Algorithm Patterns and Practice

Weekdays:
- Day 50:
  - Review all DSA structures in C:
    - dynamic array, list, stack, queue, hash, tree, heap, trie, graphs, DSU.
- Day 51:
  - Learn two-pointer technique and apply on arrays (e.g. pair sums).
- Day 52:
  - Learn sliding window technique, implement:
    - max sum subarray of size k.
- Day 53:
  - Learn backtracking basics, implement:
    - simple subset / permutation generator.
- Day 54:
  - Start solving LeetCode-style easy problems (reimplement in C).

Weekend (Days 55–56):
- Focus:
  - 4–6 easy problems that exercise:
    - arrays
    - strings
    - linked lists
    - hash tables
  - For each:
    - Write problem statement in your own words.
    - Design approach before coding.
    - Analyze complexity.

---

## MONTH 3 (Days 58–87) – Algorithms Proper + OS Intro

Focus:
- Algorithm paradigms: recursion, DP, greedy, divide & conquer.
- Systematically go through DSA roadmap (arrays → lists → stacks → queues → hash → trees → graphs → DP).
- Start OS fundamentals (processes, threads, memory).

### Week 9 – Recursion & Classic DP

Weekdays:
- Pick 1–2 DP problems per day (Fibonacci variants, knapsack, coin change, grid paths).
- For each day:
  - Write naive recursive solution.
  - Then memoized version.
  - Then bottom-up DP table.

Weekends:
- Work through:
  - 3–4 DP problems (knapsack, LIS, LCS, coin change).
- Keep:
  - A "DP patterns" note: overlapping subproblems, state representation, transitions.

---

### Week 10 – Greedy Algorithms and More Sorting

Weekdays:
- Study greedy properties:
  - activity selection
  - interval scheduling
  - Huffman coding (concept).
- Implement:
  - activity selection with sorting.
  - a simple Huffman tree (optional, nice stretch).

Weekend:
- Practice ~4 greedy problems:
  - e.g. meeting rooms, minimum number of platforms, etc.

---

### Week 11 – OS Fundamentals (Processes, Threads, Scheduling)

Weekdays:
- Read OSTEP chapters on:
  - processes
  - process API
  - scheduling.
- Exercises:
  - Draw process state diagrams.
  - Use `ps`, `top`, `htop` on your system to observe processes.

Weekend:
- Implement in C:
  - A program that:
    - forks child processes (if using Linux/WSL).
    - prints PIDs.
  - A simple round-robin simulator for processes with bursts (in pure C, just simulation).

---

### Week 12 – OS: Virtual Memory and Concurrency Basics

Weekdays:
- Read OSTEP sections on:
  - address spaces
  - paging
  - segmentation.
- Then:
  - basics of concurrency: threads, race conditions, locks.

Weekend:
- Implement:
  - Multi-threaded C program using pthreads (if available) with race condition.
  - Fix race using mutex locks.
- Note:
  - Where concurrency is tricky.

---

## MONTH 4 (Days 88–117) – Networks, Systems Programming, More OS

Focus:
- Network programming in C.
- Sockets, TCP/IP basics.
- OS internals continued: filesystems, storage.
- Combine C + OS + networking.

### Week 13 – Networking Basics

Weekdays:
- Read:
  - Intro to networking: TCP vs UDP, IP, ports, DNS.
- Watch:
  - short videos on HTTP, TCP handshake.

Weekend:
- Write:
  - Obsidian notes "Networking 101"
    - OSI model
    - where sockets live
  - Use `ping`, `traceroute`, `curl` in terminal and document what you see.

---

### Week 14 – Sockets in C (Beej)

Weekdays:
- Work through:
  - Beej’s Guide to Network Programming sections on:
    - socket()
    - bind()
    - listen()
    - accept()
    - connect()
- Each day:
  - Implement a tiny snippet from guide in your own file.

Weekend:
- Build:
  - Simple TCP echo server and client in C.
  - Test from two terminals (or two machines).

---

### Week 15 – OS: Filesystems and Storage

Weekdays:
- Read OSTEP chapters on:
  - filesystems
  - I/O
  - disk and storage stack.
- Explore:
  - `ls -l`, file permissions, `stat`, `strace` on a simple program.

Weekend:
- Implement:
  - A simple key/value store using append-only log file.
  - Basic compaction: rewrite log to remove deleted keys.

---

### Week 16 – Systems Programming & Tools

Weekdays:
- Learn:
  - `make` and Makefiles
  - basics of debugging with `gdb`
- Each day:
  - Write or improve your Makefiles for your C projects.
  - Practice stepping through code in gdb.

Weekend:
- Refactor:
  - Your DSA library into a clean repo:
    - `/include`
    - `/src`
    - `/tests`
  - Add Makefile.

---

## MONTH 5 (Days 118–147) – Databases, Distributed Systems, System Design

Focus:
- SQL + relational databases.
- NoSQL types.
- Distributed systems concepts.
- Systems design patterns.

### Week 17 – SQL and Relational DBs

Weekdays:
- Learn:
  - SELECT, INSERT, UPDATE, DELETE.
  - WHERE, JOIN, GROUP BY.
- Use:
  - SQLite or Postgres locally.

Weekend:
- Mini project:
  - Design a schema for a simple app:
    - e.g. todo app, blog, or simple game stats.
  - Implement queries that:
    - insert data
    - list data with conditions
    - aggregate stats.

---

### Week 18 – Indexes, Transactions, NoSQL

Weekdays:
- Learn:
  - Indexes (B+ trees high-level).
  - ACID properties.
  - Isolation levels.
- Intro to NoSQL:
  - key-value stores
  - document DBs.

Weekend:
- Compare:
  - When to use SQL vs NoSQL.
- Document:
  - Example architecture where you’d pick each.

---

### Week 19 – Distributed Systems Concepts

Weekdays:
- Learn:
  - replication
  - sharding
  - eventual consistency
  - CAP theorem.
- Watch:
  - short intros to distributed systems.

Weekend:
- Write:
  - A note summarizing:
    - different replication strategies (master-slave, multi-master).
    - pros/cons.
- Design:
  - A simple sharded key/value store on paper.

---

### Week 20 – System Design Basics

Weekdays:
- Study:
  - load balancers
  - caching layers (CDN, Redis)
  - queues (Kafka/RabbitMQ concepts)
  - stateless vs stateful services.

Weekend:
- Pick one system design problem (e.g. URL shortener):
  - Draw architecture
  - Identify:
    - components
    - data stores
    - scaling strategies
  - Write it out as if explaining in an interview.

---

## MONTH 6 (Days 148–177) – CS Math, GPU, Projects, Interview Prep

Focus:
- Discrete math, probability, graph theory fundamentals.
- GPU / graphics deeper if you want.
- Capstone projects.
- DSA/algorithm interview-style prep.

### Week 21 – Discrete Math Core

Weekdays:
- Learn:
  - sets, functions, relations.
  - logic, implications, equivalence.
- Practice:
  - truth tables
  - simple proof patterns (direct, contrapositive).

Weekend:
- Work through:
  - a set of logic exercises.
- Write:
  - Note: "Math for CS – Logic + Sets".

---

### Week 22 – Combinatorics & Probability

Weekdays:
- Learn:
  - permutations, combinations
  - basic probability rules.

Weekend:
- Solve:
  - 10–15 small combinatorics and probability problems.
- Connect:
  - to hashing, randomized algorithms, load distribution.

---

### Week 23 – Graph Theory and Applications

Weekdays:
- Learn:
  - terms: degree, path, cycle, tree, DAG, bipartite.
- Relate:
  - to your graph algorithms in C.

Weekend:
- Implement:
  - Bipartite check algorithm.
  - Strongly connected components (Kosaraju or Tarjan) if you feel ready.

---

### Week 24 – GPU / Graphics Deep Dive + Final Projects

Weekdays:
- Read:
  - more from Scratchapixel or similar on rasterization, shading.
- Relate:
  - to your software rasterizer.

Weekend:
- Choose 1–2 capstone projects:

Project ideas (in C, using everything you learned):
1. "libdsa" – your own C DSA library:
   - dynamic arrays, lists, stacks, queues, hash tables, trees, graphs, heaps, tries.
   - with tests and simple benchmarks.

2. "Mini DB":
   - append-only log store on disk
   - indexing in memory
   - simple query engine

3. "Networked Service":
   - TCP server handling multiple clients
   - simple protocol (e.g. chat, key/value)

4. "Renderer":
   - improved version of your ASCII rasterizer
   - camera movement
   - simple shading.

---

## Ongoing (through all months) – Practice & Reinforcement

- Keep a "Problem Log" note:
  - for each coding problem:
    - date
    - topic
    - solution idea
    - complexity
    - what trick you learned.
- Periodically (every 2–3 weeks):
  - revisit old problems and re-implement from scratch.
- Any time you feel a concept is fuzzy:
  - schedule a "review day" where:
    - you re-read notes
    - re-implement core code from memory.
