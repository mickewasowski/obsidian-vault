---
aliases:
context:
---

# ES Modules

---
ES Modules are used in Browsers, modern Node, modern frontend tooling.

Syntax:
```js
import x from 'x';
export const y = ...
export default z;
```

Key traits:
- static imports (analyzed at build time -> better tree-shaking)
- async loading by default in the browser
- immutable bindings (exported names are read-only)
- works naturally with Typescript + React

Where is it used:
- essentially your entire React/TS codebase
- modern Node (using `"type": "module"` or `.mjs`)
