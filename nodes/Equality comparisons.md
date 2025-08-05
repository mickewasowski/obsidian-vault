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


##  Equality Algorithms

#### `isLooselyEqual` - underlies the `==` (loose equality) operator in JS
Checks whether its two operands  are equal, returning a `Boolean` result. It attempts to convert and compare operands that are of different types.
1. checks for the same type - if yes, use strict equality (`===`)
2. is types differ, applies *type coercion* rules:
   - `null == undefined` => true
   - if one is number and one is a string => convert string to number
   - if one is boolean => convert to number
   - if one is object and other is primitive => convert object to primitive
3. repeats comparison after coercion

> `IsLooselyEqual` enables type coercion to determine equality - unlike `IsStrictlyEqual` (`===`), which requires both type and value to match.

####  `IsStrictlyEqual` - checks whether its two operands are equal, returning a `Boolean` result.
 This is the internal algorithm behind the `===` operator in JavaScript (strict equality).
 It returns `true` only if:
1. types are the same, and
2. values are the same (by specific type of rules)

> Type-specific behavior:
- Primitives:
   - same type, same value => true
   - `NaN === NaN` => false (special case)
   - `+0 === -0` => true
- Objects:
   - only `true` if they reference the **exact same object**

> `IsStrictlyEqual` checks for **strict equality**: no type coercion, and values must be identical in type and content/reference. It is more predictable and recommended over `==` in most cases.

#### SameValueZero
This algorithm is used in places like `Array.prototype.includes()` and `Map`/`Set`, and `TypedArray.prototype.includes()` comparisons.
It is like `===` (strict equality), but with one difference:
- `NaN` is considered equal to `NaN`
- `+0` and `-0` are considered equal (same as `===`)

> `SameValueZero` is like strict equality (`===`), but treats `NaN` as equal to `NaN` - which `===` does not. It's commonly used in equality checks where `NaN` should be treated as equal.
Used in:
- `Array.prototype.includes()`
- `Map`/`Set`
- `TypedArray.prototype.includes()`


#### SameValue
this internal algorithm is `stricter than ===`, and is used in specific JS operations (e.g. `Object.is()`).
It is **identical to `===`, except**:
- `NaN === NaN` => **false**, but `SameValue(NaN, NaN)` => true
- `+0 === -0` => true, but `SameValue(+0, -0)` => `false`

Used in:
- `Object.is()`
- specification-level equality in some internal mechanics (e.g. module registry, record identity)