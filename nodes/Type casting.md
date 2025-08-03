---
aliases:
context:
- "[[JavaScript]]"
---

#wip

# Type casting

Type conversion (or typecasting) means the transfer of data from one data type to another.
Implicit conversion happens when the compiler (for compiled languages) or runtime (for script languages like JavaScript) automatically converts data types.

---

### String conversion
Can be performed with `String(value)`.

### Numeric conversion

Numeric conversion in mathematical functions and expressions happens automatically.
Example:
`alert( "6" / "2" ); //3, strings are converted to numbers`

Number(value) - explicit conversion:

| ---------- | ------------- |
| Value      | Becomes       |
| ---------- | ------------- |
| undefined  | NaN           |
| null       | 0             |
| true       | 1             |
| false      |  0            |
| string     | error - NaN   |

Examples:
``` js
    alert( Number("   123   ") ); // 123
    alert( Number("123z") );      // NaN (error reading a number at "z")
    alert( Number(true) );        // 1
    alert( Number(false) );       // 0
```


### Boolean conversion
The simplest one.
`Boolean(value)`

Conversion Rule:
- values that are intuitively "empty", like "0", an empty string, null, undefined, and NaN, become `false`.
- Other values become `true`.


## Type Conversion (Type casting) vs. Coercion (Implicit type conversion)

Type coercion is the automatic or implicit conversion of values from one data type to another (such as string to numbers).
> Implicit type conversion (coercion): JavaScript automatically converts data types when it expects a certain type, such as during operations ("5" + 2 results in "52") or comparisons ("5" == 5 results in `true`)
Happens when the compiler or runtime automatically converts data types. JS is loosely typed language and most of the time operators automatically convert a value to the right one.

Type conversion (type casting) is similar to type coercion because they convert values from one data type to another with one key difference - type coercion is implicit.
> Explicit type conversion (casting): You deliberately convert data types using built-in functions or methods, like `Number("5")` (results in `5`), `String(123)` (results in "123"), or `Boolean(0)` (results in `false`)
It means transfering data from one data type to another by *explicitly specifying the type to convert the given data to*. 
Examples:
> `parseInt`
> `parseFloat`
> `toString`
