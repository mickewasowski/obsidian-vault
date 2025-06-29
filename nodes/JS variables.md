---
aliases:
context:
- "[[JavaScript]]"
---

# JS variables

A variable is a container for a value. Used to store and represent information in the JS codebase.

---
### Variable declarations

`var`, `let`, and `const` are special keywords used for variable declaration. Each of them provide different abilities to the variable.

> `var` declares:
- function-scoped or globally-scoped variable
- *optionally* initializing to a value
- *hoisting* => hoisted to the top of their scope, meaning they can be referenced before their declaration, but they will be `undefined` until the declaration is reached
- redeclaration - you can re-declare a variable using `var` within the same scope without any error
- reassignment - can be reassigned to a new value at any point in their scope

> `let` declares:
- block-scoped, only accessible within the block (enclosed by `{}`) in which it is defined
- similar to `var`, `let` is hoisted, but it cannot be accessed before its declaration due to the [[Temporal Dead Zone]]
- re-declaration - you *cannot* re-declare a variable using `let` in the same scope 
- reassignment - you can reassign its value, limited to the block in which they are defined

> `const` declares:
- block-scoped, similar to `let`
- also hoisted, but cannot be accessed before its declaration due to the [[Temporal Dead Zone]]
- re-declaration - *cannot* re-declare a variable using `const` in the same scope
- reassignment - *cannot* be reassigned. They must be initialized ath the time of declaration, and any attempt to reassign them will result in a `TypeError`
- mutability - if a variable is an `array` or an `object` its properties or elements can still be modified


> [!Warning] Variable shadowing
> Variable shadowing occurs when a variable declared in a certain scope (like function or block) has the same name as a variable declared in an outer scope. The inner variable "shadows" the outer variable, meaning that within the inner scope, the inner variable takes precedence and is the one that is accessed.



### Naming rules
1. A variable's name should clearly describe what it's meant for
2. Be descriptive but not too much, we must remain within the bounds of description
3. Abreviate long names (e.g. `dbname`)
4. Use a casing convention to break words (camel, pascal, snake, screaming snake)


### Scopes
In JS Scope refers to the visibility of a variable or how it can be used after it is declared. The scope of a variable depends on the keyword that was used to declare it.
Three types of scope:
1. Global scope - variables declared outside any function or curly braces (`{}`) have global scope and can be accessed from anywhere
2. Function scope - variables declared within a function can only be used within said function
3. Block scope - any part of JS code bounded by `{}`, variables declared within a block *cannot* be used outside of said block
4. Local scope - local variables are only recognized inside their functions, variables with the same name can be used in different functions. Local variables are created when a function starts, and are deleted when the function is completed.
