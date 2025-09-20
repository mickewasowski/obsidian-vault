---
aliases:
context:
- "[[Expressions and Operators]]"
---

# Bitwise operators

---
Bitwise operators treat arguments as 32-bits (zeros and ones) and work on the level of their binary representation.
Bitwise operators perform their operations on such binary representation, but they return standard Javascript numerical values.
In JS numbers are stored as 64-bit floating point values, therefore they are first converted to 32-bit signed integers, operations are performed, then they are converted back to 64-bit numbers.


Operators:
- AND `&`
- OR `|`
- XOR `^`
- NOT `~`
- LEFT SHIFT `<<`
- RIGHT SHIFT `>>`
- ZERO-FILL RIGHT SHIFT `>>>`

Examples:

- *AND* compares each bit `1 & 1 = 1`, otherwise `0`
```js
console.log(5 & 3); 
// 5 = 0101, 3 = 0011
// result = 0001 = 1
```

- *OR* compares each bit if either is `1`, result is one
```js
console.log(5 | 3); 
// 5 = 0101, 3 = 0011
// result = 0111 = 7
```

- *XOR* exclusive OR, `1` if bits are different
```js
console.log(5 ^ 3); 
// 0101 ^ 0011 = 0110 = 6
```

- *NOT* inverts bits (flips `0` -> `1` and `1` -> `0`), works on 32-bit signed integers, so the result might be weird
```js
console.log(~5);
// 5 = 00000000000000000000000000000101
// ~5 = 11111111111111111111111111111010 = -6
```

- *LEFT SHIFT* shifts bits left filling with `0`, equivalent to multiplying by `2^n`
```js
console.log(5 << 1);
// 0101 << 1 = 1010 = 10
```

- *SIGNED RIGHT SHIFT* shifts the bits right, keeping the sign bit (leftmost bit)
```js
console.log(5 >> 1);   // 0101 >> 1 = 0010 = 2
console.log(-5 >> 1);  // keeps sign → -3
```

- *UNSIGNED RIGHT SHIFT* shifts bits right filling with `0`, always produces a non-negative result
```js
console.log(5 >>> 1);  // 2
console.log(-5 >>> 1); // large positive number (2147483645)
```

> Why use bitwise operations?
- *performance tricks* - multiply/divide by powers of 2 with shifts
- *flags and masks* - store multiple true/false value in a single number
- *low-level operations* - working with binary data, graphics, encryption, networking


> How to interpret *binary number* into decimal?
```js
Binary:   1   1   0   0   1   0   1
Power:   2^6 2^5 2^4 2^3 2^2 2^1 2^0
Value:   64  32   0   0   4   0   1
```

// converts a binary to decimal
```js
const number = 1100011010101;
const arr = number.toString().split('').map(x => Number(x)).reverse();

let res = 0;
for (let i = 0; i < arr.length; i++) {
    res += (2 ** i) * arr[i];
}
console.log(res);
```
