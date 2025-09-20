---
aliases:
context:
- "[[Expressions and Operators]]"
---

# BigInt operators

---
Most operators that can be used with `Number` can be used with `BigInt` as well, except for `unsigned right shift`.
Unsigned right shift is not defined for BigInt values because a BigInt does not have a fixed width, so technically it doesn't have a "highest bit".

> BigInts and Numbers are not mutually replaceable - you cannot mix them in calculations.
This is because BigInts are neither a subset or a superset of numbers.
BigInts have a higher precision than numbers when representing larger integers, but cannot represent decimals, so implicit conversion on either side might loose precision.
Use explicit conversion to signal whether you want the operation to be a number or a BigInt one.
