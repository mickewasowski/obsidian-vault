---
aliases:
context:
- "[[JavaScript]]"
---

# Hoisting
Default JS behavior where function and variable declarations are moved to the top of their scope.

---
Works for:
- function declarations (fully hoisted)
``` js
    function test() {
       console.log()
    }
```
- variables
- classes

Not fully hoisted:
- anon function expressions:
``` js
    var test = function () {
      console.log()
    }
```
- named function expressions:
``` js
    var test = function test() {
       console.log()
    }
```
*only the variable declaration* is hoisted, not the assignment of the functions above

**NOT** hoisted:
- arrow functions



### Hoisting (Table of Contents analogy)

You can think of the JavaScript engine as someone who reads a book (your script) in two passes

#### First pass (Compilation)
The engine skims through your entire code and just makes a list of all the variables and functions it sees, like creating a table of contents or a glossary (meaning: dictionary, lexicon, vocabulary) at the beginning. It notes down the variable and function names. For variables declared with `var`, it even gives them an initial value of `undefined`.

#### Second pass (Execution)
The engine actually reads your code line-by-line to run it.
When it gets to a line that uses a variable or function, it already know it exists from the first pass.


#### Key difference (`var` vs. `let`/`const`)
- `var` - hoisted and initialized with `undefined`. So if you use it before its actual line, it just returns `undefined`
```js
    console.log(message); // Outputs: undefined
    var message = "Hello, world!";
```

- `let` and `const` - they are also hoisted (the engine knows they exist), but they are not initialized. They sit in a [[Temporal Dead Zone]] until the line where they are defined is executed. Trying to access them in the TDZ results in a `ReferenceError`.
```js
    console.log(message); // Throws ReferenceError: Cannot access 'message' before initialization
    let message = "Hello, world!";
```

#### Function declaration vs. Expressions
What you're hoisting is either the entire function or just the variable that holds it.

- **Function Declaration** - *the entire function (name and body) is hoisted*. It's fully ready to be used anywhere in its scope.
```js
    sayHello(); // Works! Outputs: "Hello there!"

    function sayHello() {
      console.log("Hello there!");
    }
```

- **Function Expression** (including Arrow functions) - you're assigning a function to a variable. The variable declaration (`const`, `let`, `var`) is hoisted, but the *assignment* (the function body itself) is not.
```js
    // With an Arrow Function and 'const'
    sayHi(); // ❌ ReferenceError: Cannot access 'sayHi' before initialization

    const sayHi = () => {
      console.log("Hi!");
    };
```
The engine knows a variable `sayHi` exists (it's hoisted), but it's in the TDZ until the assignment line. If you used `var`, you'd get a `TypeError` because `sayHi` would be `undefined`.

