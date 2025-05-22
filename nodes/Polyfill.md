---
aliases:
context:
- "[[Accessibility]]"
---

# Polyfill

A Polyfill's purpose is to provide modern functionality on older browsers that do not natively support it.
Polyfills help bridge the gap between modern web features and older browser capabilities, ensuring broader compatibility without sacrificing innovation.

---
Polyfills mimic newer web APIs or features in environments that do not support them natively.

Examples are ES6+ features such as:
- Promise
- fetch
- Array.prototype.includes
The above are not natively supported in older browsers such as Internet Explorer.

An example polyfill implementation is:
``` javascript
if (!Array.prototype.includes) {
  Array.prototype.includes = function(searchElement, fromIndex) {
    return this.indexOf(searchElement, fromIndex) !== -1;
  };
}
```

How are they used:
1. manually included via script tags or bundlers
2. automatically added by tools like Babel (with @babel/polyfill or core-js) depending on your target browser configuration