---
aliases:
context:
---

# CommonJS

---
CommonJS is used in older Node.js codebases and some tooling configs.

Syntax:
```js
const x = require('x');
module.exports = y;
```

Key traits:
- synchronous loading
- exports are mutable objects (you can change them after export)
- not natively supported in browsers without bundling
- in Node, files are usually `.cjs` or `.js` with `"type": "commonjs"` in package.json

Where is it used:
- old Node packages
- some build tools (older Webpack configs)
- legacy code
