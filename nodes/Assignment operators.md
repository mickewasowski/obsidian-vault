---
aliases:
context:
- "[[Expressions and Operators]]"
---

# Assignment operators

---
An assignment operator assigns a value to its left operand based on the value of its right operand.
The simple assignment operator is equal (`=`).


| Operator | Example   | Equivalent to | Description                                |
|----------|-----------|---------------|--------------------------------------------|
| `=`      | `x = y`   | –             | Assigns the value of `y` to `x`.           |
| `+=`     | `x += y`  | `x = x + y`   | Adds `y` to `x`.                           |
| `-=`     | `x -= y`  | `x = x - y`   | Subtracts `y` from `x`.                    |
| `*=`     | `x *= y`  | `x = x * y`   | Multiplies `x` by `y`.                     |
| `/=`     | `x /= y`  | `x = x / y`   | Divides `x` by `y`.                        |
| `%=`     | `x %= y`  | `x = x % y`   | Assigns remainder of `x / y` to `x`.       |
| `**=`    | `x **= y` | `x = x ** y`  | Raises `x` to the power of `y`.            |
| `<<=`    | `x <<= y` | `x = x << y`  | Left shift bits of `x` by `y`.             |
| `>>=`    | `x >>= y` | `x = x >> y`  | Right shift bits of `x` by `y`.            |
| `>>>=`   | `x >>>= y`| `x = x >>> y` | Unsigned right shift bits of `x` by `y`.   |
| `&=`     | `x &= y`  | `x = x & y`   | Bitwise AND of `x` and `y`.                |
| `|=`     | `x |= y`  | `x = x \| y`  | Bitwise OR of `x` and `y`.                 |
| `^=`     | `x ^= y`  | `x = x ^ y`   | Bitwise XOR of `x` and `y`.                |
| `&&=`    | `x &&= y` | `x = x && y`  | Logical AND assignment (short-circuits).   |
| `||=`    | `x ||= y` | `x = x || y`  | Logical OR assignment (short-circuits).    |
| `??=`    | `x ??= y` | `x = x ?? y`  | Nullish coalescing assignment.             |
|----------|-----------|---------------|--------------------------------------------|
