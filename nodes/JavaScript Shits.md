---
aliases:
context:
- "[[JavaScript]]"
- "[[Coding Shits]]"
---

#wip

# JavaScript Shits

ad

---
### Difference between | and ??

I had the following case:
``` javascript
// I provide the following to my function
myFunction(var1 | var2); // the type of the vars here is expected to be string

function myFunction (input: string) {
	// here the type of the input i receive was number
}
```

A working version of the above is:
``` javascript
myFunction(var1 ?? var2)  or myFunction(var1)

function myFunction(input: string) {
	// the type of the input in both cases is string as i expect
}
```


Why did I experience this behavior:

| var1 &#124;  var2 | var1 ?? var2 |
| ------------ | ------------ |
| bitwise or | nullish coalescing |
| coerces both vars to numbers (if they're not already) | does *not* coerce the types of the vars or evaluate them numerically |
| performs a bitwise operation | just picks the first defined value |
| returns a number | returns the value of the variable how it received it |

### parseInt
When parsing a string which contains both numbers and text, `parseInt` will try to parse the provided string up until it reaches a text character.
If the string begins with a number => returns the parsed number up until the text
If the string begins with text character => returns `NaN`
``` js
	parseInt('42px');     // → 42 ✅
	parseInt('px42');     // → NaN ❌
	Number('42px');       // → NaN ❌
```

### for..in loop
> The keys are ordered in a "special fashion": integer properties are sorted, others appear in creation order.
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
```