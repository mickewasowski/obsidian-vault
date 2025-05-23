---
aliases:
context:
- "[[JavaScript]]"
---

# Hoisting

---
Default JS behavior where function and variable declarations are moved to the top of their scope.

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


NOT hoisted:
- arrow functions