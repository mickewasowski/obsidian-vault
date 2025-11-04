---
aliases:
context:
- "[[Module bundlers]]"
---

# Rollup

---
### What is Rollup

JS module bundler that takes multiple ES modules and bundles them into a single or multiple output files.

1. How it works under the hood:
- reads your project's entry point
- traces all imports and dependencies
- applies transformations (via plugins)
- outputs and optimized bundle for distribution


2. Supported formats:
- es - modern js modules
- cjs - node.js or commonjs
- umd - for browser + node compatibility
- iife - immediately executed in browser script tag


> External dependencies - you mark packages you **don't want bundled** (e.g. React) as external, so the consumer provides them. Otherwise, they get bundled into your output - bloating your library.

3. Plugins
Rollup's power comes from the plugins.
They handle things like:
- transpile TS -> JS
- handle CSS/SCSS
- replace env variables
- resolve node modules


Common plugins:
- @rollup/plugin-node-resolve – locate modules
- @rollup/plugin-commonjs – convert CJS → ESM
- @rollup/plugin-json – import JSON
- rollup-plugin-postcss – handle styles
- rollup-plugin-dts – generate .d.ts files


4. Tree shaking
- automatically removes unused exports as long as your code uses ES modules.

5. Code splitting
- if you output multiple entry points or dynamic imports, Rollup can split bundes into chunks for efficiency:
```js
export default {
  input: ['src/index.ts', 'src/utils.ts'],
  output: {
    dir: 'dist',
    format: 'es',
    chunkFileNames: '[name]-[hash].js'
  }
}
```

### Typical config file
```js
// rollup.config.js
import typescript from '@rollup/plugin-typescript';
import dts from 'rollup-plugin-dts';

export default [
  {
    input: 'src/index.ts',
    output: {
      file: 'dist/index.js',
      format: 'es',
    },
    plugins: [typescript()],
    external: ['react', 'react-dom'],
  },
  {
    // For type declarations
    input: 'src/index.ts',
    output: {
      file: 'dist/index.d.ts',
      format: 'es',
    },
    plugins: [dts()],
  },
];

```


### Rollup vs Vite
| Feature           | Rollup                 | Vite                                            |
| ----------------- | ---------------------- | ----------------------------------------------- |
| Purpose           | Bundler for builds     | Dev server + build (uses Rollup under the hood) |
| Speed             | Slower in dev (no HMR) | Fast dev via ESBuild                            |
| Config complexity | Manual                 | Simplified via `vite.config.ts`                 |
| Best for          | Libraries, frameworks  | Apps, SSR, or libraries (with vite build)       |

