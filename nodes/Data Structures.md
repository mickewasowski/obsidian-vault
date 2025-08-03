---
aliases:
context:
- "[[JavaScript]]"
---

#wip

# Data Structures

A Data Structure is a format to organize, manage and store data in a way that allows efficient access and modification.

---

### Common data Structures

1. Arrays - ordered collections of elements, accessed by an index. JavaScript arrays are dynamic and can hold elements of different types. *They are fundamentally lists*.

2. Objects (Hash Maps/Dictionaries) - unordered collections of key-value pairs. Keys are string (or Symbols), and values can be any data type. They provide efficient lookup, insertion, and deletion by key.

3. Sets - collections of unique values. Useful for quickly checking membership or removing duplicates. Implemented using the build-in `Set` object.

4. Maps - collections of key-value pairs where keys can be of any data type (not just strings). Provides more flexibility than plain objects for key types. Implemented using the built-in `Map` object.

5. Stacks - last-in, first-out (LIFO) collections. Can be implemented using an array with `push()` and `pop()`

6. Queues - first-in, first-out (FIFO) collections. Can be implemented using an array with `push()` and `shift()` (or other optimizations for efficiency)

7. Linked lists - collections where elements are stored in nodes, and each node contains a value and a reference (or pointer) to the next node. Not natively built-in but can be implemented with objects.

8. Trees - hierarchical data structures where each node has a value and references to child nodes. Common types incllude Binary Trees and Binary Search Trees. Implemented using objects with nested references.

9. Graphs - collections of nodes (vertices) and connections (edges). Represent relationships between data. Implemented using adjacency lists (objects/Maps where keys are nodes and values are arrays/Sets of connected nodes) or adjacency matrices (2D arrays).



### Stack Data Structure Implementation
``` js
class Stack<T> {
    private data: T[];

    push(element: T) {
        this.data.push(element);
    }

    pop(): T {
        if (this.data.length > 0) {
            return this.data.pop();
        }
    }

    getStackLength(): number {
        return this.data.length;
    }

    peek(): T | undefined {
        if (this.data.length === 0) {
            return undefined;
        }

        return this.data[this.data.length - 1];
    }

    isEmpty(): boolean {
        return this.data.length === 0;
    }
}
```


### Queue Data Structure Implementation
``` js
class Queue<T> {
    private data: T[];

    constructor() {
        this.data = [];
    }

    enqueue(element: T) {
        this.data.push(element);
    }

    dequeue(): T | undefined {
        if (this.data.length === 0) {
            return undefined;
        }
        return this.data.shift();
    }

    size(): number {
        return this.data.length;
    }


    isEmpty(): boolean {
        return this.data.length === 0;
    }
}
```

### Singly Linked List Data Structure Implementation
``` js
class Node<T> {
    public value: T;
    public next: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList<T> {
    private head: Node<T> | null;
    private tail: Node<T> | null;
    private _size: number;

    constructor() {
        this.head = null;
        this.tail = null;
        this._size = 0;
    }

    addElement(element: T): void {
        const newNode = new Node(element);

        if (isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail!.next = newNode;
            this.tail = newNode;
        }

        this._size++;
    }

    removeElement(): T | undefined {
        if (isEmpty()) {
           return undefined;
        }

        const removedValue = this.head!.value;

        this.head = this.head!.next;
        
        if (!this.head) {
            this.tail = null;
        }

        this._size--; 
        return removedValue;
    }

    size(): number {
        return this._size;
    }

    isEmpty(): boolean {
      return this._size === 0;
    }

    toArray(): T[] {
        const result: T[] = [];
        let currentNode = this.head;

        while (currentNode) {
            result.push(currentNode.value);
            currentNode = currentNode.next;
        }
        
        return result;
    }
}
```
