---
aliases:
context:
- "[[JavaScript]]"
---

# Strict mode

---
### What is strict mode?

Stick mode was introduced to help developers write a more clean and secure code.
It was firstly introduced in ES5.
You enable it by writing:
```js
'use strict';
```
- at the top of a script file -> enables it for the entire file
- inside a function -> applies it to the function only

### Why use strict mode?
It helps you catch common mistakes and makes your code safer by:
1. preventing silent errors -> things that normally fail silently will throw errors
2. restricting unsafe features -> stops you from using error-prone of depricated features
3. making JavaScript engines optimize better -> sometimes strict code runs faster

### Key differences
1. No implicit globals:

without strict mode
```js
x = 10; // no var/let/const, still works (creates global variable!)
```

with strict mode:
```js
'use strict';
x = 10; // ❌ ReferenceError: x is not defined
```

2. Read-only properties can't be written to
```js
'use strict';
const obj = {};
Object.defineProperty(obj, "a", { value: 1, writable: false });
obj.a = 2; // ❌ TypeError
```

3. No duplicate parameter names
```js
function test(a, a) { return a; } // works in sloppy mode
'use strict';
function test(a, a) {} // ❌ SyntaxError
```

4. `this` in strict mode is not auto-coerced to `window`
```js
function f() {
  console.log(this);
}

f(); 
// Normal mode: logs `window` (in browsers)
// Strict mode: logs `undefined`
```

5. Reserved keywords protected
You can't use future reserved keywords as variable names:
- `implements`
- `interface`
- `let`
- `package`
- `private`
- `protected`
- `public`
- `static`
- `yield`

6. Octal literals are not allowed
```js
let num = 010; // 8 in sloppy mode
'use strict';
let num = 010; // ❌ SyntaxError
```

### Summary
Strict mode makes JavaScript less forgiving but safer.
It prevents accidental globals, disallows bad syntax, and forces cleaner coding practices.
