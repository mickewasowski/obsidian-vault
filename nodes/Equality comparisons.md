---
aliases:
context:
- "[[JavaScript]]"
---

#wip

# Equality comparisons

Comparison operators are used in logical statements to determine equality of difference between values or variables. Can be used in conditional statements.

---
### Double equals (==)
Does the type conversion of operands before the comparison.
This one checks only for the value and not the type.
Applies various coercions to both sides (if they are not the same type) before testing for equality.
> Key notes:
1. If a string is compared to a number, it coerces the string to a number. The string "0" is converted to 0 and then we get 0 == 0
2. The left or right side is coerced to a number when a primitive type is compared to a number or boolean
    - boolean to number - if one operand is boolean it is always coerced to a number (`false` becomes 0 and `true` becomes 1)
    - string to number - if a `string` is compared to a number, the string is coerced to a number
    - object to primitive - if an object is compared to a primitive, it is coerced to a primitive value (string, number or boolean) first
The coercion order isn't strictly left-to-right; it's based on the types involved. The goal is to convert the operands into a common, comparable type, typically a number.

### Tripple equals (===)
Compares both the value and data type.
Treats `-0` and `+0` are equals, but `NaN` as not equal to each other.
It will only return true if both the type and the value are equal.


### Object.is()
Determines whether two values are the same value. It is not equivalent to `==`. Doesn't coerce either value.
`Object.is()` is also not equivalent to `===`. The only difference between `Object.is()` and `===` is their treatment of signed zeros and `NaN` values.

Returns true if any of the below are true:

- both are `undefined`
- both are `null`
- both are either `true` or `false`
- both are strings of the same lenght and the same characters in the same order
- both reference the same object in memory
- both BigInts with the same numeric value
- both `symbols` that reference the same symbol value
- both numbers and :
    - both are -0
    - both are +0
    - both NaN
    - both non-zero, not NaN, and have the same value


Examples:
``` js
    console.log(Object.is('1', 1));
    // Expected output: false

    console.log(Object.is(NaN, NaN));
    // Expected output: true

    console.log(Object.is(-0, 0));
    // Expected output: false

    const obj = {};
    console.log(Object.is(obj, {}));
    // Expected output: false
```
