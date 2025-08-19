---
aliases:
context:
- "[[JavaScript]]"
- "[[Keyed Collections]]"
---

#wip

# Set

Lets you store unique values of any type. A value in a Set may only occur once, it is unique in the `Set` collection.

---
- Values can be of any type - primitive or objects
- Order of insertion is preserved when iterating
- Faster lookup compared to arrays

### Common methods

1. Adding/Deleting
    ```js
    const s = new Set();

    s.add(1); // Set {1}
    s.add(2).add(3); // chaining possible
    s.delete(2); // true (removed)
    s.has(3);    // true
    s.clear();   // removes all
    ```

2. Properties
    ```JavaScript
    s.size; // number of unique elements
    ```

3. Iteration
    ``` js
    const nums = new Set([10, 20, 30]);

    for (let n of nums) console.log(n); // 10, 20, 30
    nums.forEach((val) => console.log(val));
    ```

### Convertions

1. Array -> Set (remove duplicates)
    ```JavaScript
    const arr = [1, 2, 2, 3];
    const s = new Set(arr);
    console.log([...s]); // [1, 2, 3]
    ```

2. Set -> Array
    ```JavaScript
    const s = new Set([1, 2, 3]);
    const arr = Array.from(s); // or [...s]
    ```


### Practical use cases

1. Remove duplicates from an array
2. Check membership quickly:
    ```JavaScript
    const banned = new Set(["user1", "user2"]);
    console.log(banned.has("user1")); // true
    ```
3. Set operations (union, intersection, difference)
    ```JavaScript
    const a = new Set([1, 2, 3]);
    const b = new Set([3, 4, 5]);

    // Union
    const union = new Set([...a, ...b]); // {1,2,3,4,5}

    // Intersection
    const intersection = new Set([...a].filter(x => b.has(x))); // {3}

    // Difference
    const difference = new Set([...a].filter(x => !b.has(x))); // {1,2}
    ```

### When to use
- you need uniqueness
- you often check existence of items
- you want to remove duplicates easily
