---
aliases:
context:
- "[[Module bundlers]]"
---

# Tree shaking

---
### What is Tree shaking

Tree shaking is a **dead code elimination** technique. It removes unused exports from your final bundle to reduce size.

Key points:
- only works with **ES Modules** (`import` / `export`) - not CommonJS (`require` / `module.exports`)
- depends on **static analysis** of imports/exports
- often combined with **minification** in production builds


### How it works (simplified)

Suppose you have a utility file:
```js
// utils.ts
export function usedFunction() { return 1; }
export function unusedFunction() { return 2; }
```
And you import only the used function:
```js
import { usedFunction } from './utils';
console.log(usedFunction());
```
> A bundler with tree shaking will detect that `unusedFunction` is **never imported**, and will **exclude it from the final bundle**.


### Setting up Tree shaking

- Vite - uses **Rollup under the hood**, which has tree shaking by default
    - ensure your imports are *ES modules*
    - when you run `vite build`, tree shaking happens automatically
    - you can check output with:
```bash
vite build --report
```
This generates a **bundle analysis** to see unused code.


### TypeScript

- TypeScript itself does **not remove unused exports** in compiled JS
- You rely on **your bundler** (Webpack/Rollup/Vite) to do the shaking
- Make sure `tsconfig.json` has `"module": "ESNext"` so the output uses ES modules


### Common pitfalls

1. Using CommonJS: `require()` won't be tree-shakable
2. Side effects:
    - some modules may have code that runs on import, even if you don't use it. In Webpack, mark them in `package.json`:
```js
"sideEffects": false
```
Or list files that have side effects:
```js
"sideEffects": ["./styles.css"]
```

3. Dynamic imports (`import('module')`) are treated differently; they're **code-split**, not tree-shaken.

