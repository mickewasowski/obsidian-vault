---
aliases:
context:
- "[[Expressions and Operators]]"
---

# Logical operators

---
There are four logical operators in Javascript:
- AND `&&`
- OR `||`
- NOT `!`
- NULLISH COALESCING `??` - used to default to a value if the only when something is `null` or `undefined`

```js
let result = value ?? defaultValue;
```
Meaning if `value` is `null` or `undefined`, then `result = defaultValue`
Otherwise, `result = value`
