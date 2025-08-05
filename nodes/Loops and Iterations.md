---
aliases:
context:
- "[[JavaScript]]"
---

#wip

# Loops and Iterations

Loops offer a quick and easy way to perform something repeatedly.

---
#### While
Executes a loop with a specified statement as long as the test condition evaluates to true.
The condition is evaluated *before* executing the statement.
``` js
while (condition) {
  statement
}
```
- condition - an expression evaluated *before* each pass through the loop. If this condition evaluates to `true`, statement is executed.

> Control flow statements:
> `break` stops the statement execution and goes to the first statement **after the loop**
> `continue` stops the statement execution and re-evaluates the condition


#### Do...While statement
Creates a loop that executes a specified statement until the test condition evaluates to `false`. The condition is evaluated *after* executing the statement, resulting in the specified statement executing at least once.
``` js
let i = 0;

do {
	i++;
} while (i < 5);
```

> Control flow statements:
> `break` stops the statement execution and goes to the first statement **after the loop**
> `continue` stops the statement execution and re-evaluates the condition

#### The for loop
Standard control-flow construct in many programming languages, including JS.
It is meant to repeatedly execute a piece of code a known number of times.

``` js
for (initialization; condition; update)
  statement;
```
- initialization - here any variables to be used in the loop are initialized to given values
- condition - the condition that is evaluated before every iteration. If it evaluates to `true`, the loop's body is executed, or else the execution terminates
- update - an expression that's evaluated after every iteration. Typically this updates a variable's value that's used in the loop's condition so that it eventually becomes `false` at a certain point and the loop comes to an end

> Control flow statements:
> `break` stops the statement execution and goes to the first statement **after the loop**
> `continue` stops the statement execution and re-evaluates the `condition` 


#### For...In statement
Iterates over all enumerable properties of an object that are keyed by strings (ignoring ones keyed by Symbols), including inherited enumerable properties.
To walk over all keys of an object we use `for..in` loop.
``` js
for (let key in object)
  statement
```
> Order of looping:
> The keys are ordered in a "special fashion": integer properties are sorted, others appear in creation order.
> If the key can be transformed to an integer and back, it's still the same, then it's considered an integer key 
> If the keys are non-integer, then they are listed in the creation order
Example:
``` js
	let codes = {
	  "49": "Germany",
	  "41": "Switzerland",
	  "44": "Great Britain",
	  // ..,
	  "1": "USA"
	};
	
	for (let code in codes) {
	  alert(code); // 1, 41, 44, 49
	}

// to fix the sorting issue with the codes above we should add a + sign to the beginning of each key
```

- variable - may be either a declaration with either `const, let, var`
- object - object whose non-symbol enumerable properties are iterated over
- statement - a statement to be executed on every iteration

> Control flow statement:
- `break` stops statement execution and goes to the first statement after the loop.
- `continue` stops statement execution and goes to the next iteration of the loop.


#### For...Of statement
Iterates over the values of an iterable object.
``` js
for (const element of object)
  statement
```

- variable - the value of the object at the iteration
- object - iterable object
- statement - to be executed on every iteration

> Control flow statement:
- `break` stops statement execution and goes to the first statement after the loop.
- `continue` stops statement execution and goes to the next iteration of the loop.

#### Break continue
- break statement, without a label reference, can only be used to jump out of a loop or a switch block.
- continue statement, with or without a label reference, can only be used to skip one loop iteration.