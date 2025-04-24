---
aliases:
context:
- "[[JavaScript]]"
---

# this keyword

---
### Default binding
Traditional function, when invoked in the global scope refers to the global object (window in browsers, global in Node.js)


### Implicit binding
This refers to the object the method is called on


### Explicit binding
Set the this value with call(), bind(), apply()


### Arrow functions
Arrow functions do not have their own context, they inherit it from the enclosing scope

### Callbacks
Better use an arrow function (instead of function declaration), else it might loose its expected reference 