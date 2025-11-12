---
aliases:
context:
- "[[JavaScript]]"
---

# this keyword
`this` keyword in JavaScript refers to an object. It may have a different value depending on where it's being invoked.

---
#### Default binding
Traditional function, when invoked in the global scope refers to the global object (window in browsers, global in Node.js)

#### Implicit binding
This refers to the object the method is called on

#### Explicit binding
Set the this value with call(), bind(), apply()

#### Arrow functions
Arrow functions do not have their own context, they inherit it from the enclosing scope

#### Callbacks
Better use an arrow function (instead of function declaration), else it might loose its expected reference 


### In depth

In short, `this`:
- in an object method refers to the object
- alone it refers to the global object
- in a function refers to the global object
- in a function in _strict mode_ it is `undefined`
- in an event it refers to the element that received the event (e.g. button, video, audio, etc.)
- methods like `call()`, `bind()`, `apply()` can refer `this` to any object


1. `this` in object methods
- an object method may need access to the information stored in the object to do its job. The value of `this` is the object "before the dot", the one used to call the method.

```js
let user = {
    name: "John",
    age: 30,

    sayHi() {
        console.log(this.name);
    }
};

user.sayHi(); // this refers to user
```

2. `this` in a function (`function() {}` syntax)
- the `this` keyword when used in a function refers to the global object.
*In a browser the `this` object is window, in Node environment `this` is global.*
- in _strict mode_ `this` is `undefined`.

- `arrow functions` - they inherit `this` from the parent scope at the time they are *defined*. Because arrow functions do not have their own `this` binding it cannot be set by `bind()`, `call()` or `apply()`. When in object method it *does not* point to the current object.

3. `this` using it alone - refers to the global object

4. `this` in event handlers - refers to the HTML element that the event handler is attached to. This allows you to directly access and manipulate the element from within the event handler function.


[[Function Borrowing]] - call, bind, apply
