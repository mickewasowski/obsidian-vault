---
aliases:
context:
- "[[Module bundlers]]"
- "[[Minifiers]]"
---

# esbuild

esbuild is an extremely fast JS bundler and minifier written in Go.

---
### What is esbuild

- bundler and minifier
- extremely fast because it's written in Go instead of Javascript
- Vite uses it internally


### What is it used for

- bundle multiple JS/TS files into one (or a few) optimized output files
- transpile modern Javascript and Typescript
- minify code for production
- transform JSX into browser-compatible JS (for React)


### Core features

1. Bundling
- takes all of your JS, CSS, and assets, and builds them into optimized files; it follows imports and includes everything needed

```bash
esbuild src/index.tsx --bundle --outfile=dist/bundle.js
```

2. Transpiling
- out of the box:
    - converts Typescript -> Javascript
    - converts JSX -> `React.createElement()` or the automatic JSX runtime
```bash
esbuild src/index.tsx --bundle --outfile=dist/app.js --jsx=automatic
```

3. Minification
- use the `--minify` flag to shrink your code:
```bash
esbuild src/index.tsx --bundle --minify --outfile=dist/app.js
```
It minifies:
    - Javascript
    - Whitespace
    - Identifiers
    - JSX output

4. Super-Fast Builds
- esbuild's key feature: **speed**
It's 10-100x faster than Webpack or Babel because:
- it's compiled (Go binary)
- parallelizes work across CPU cores
- has almost no startup cost
Perfect for dev environments or CI/CD pipelines where speed matters.


5. Tree shaking - automatically removes unused exports
```js
import { usedFn } from './utils'; // only includes usedFn, if the rest aren’t used
```

6. Code splitting
With `--splitting` and `--format=esm`, esbuild can split your bundle:
```bash
esbuild src/index.tsx --bundle --splitting --format=esm --outdir=dist
```
This allows lazy loading and smaller initial bundles


7. Dev Server
You can run a lightweight local server with:
```bash
esbuild src/index.tsx --bundle --serve=8000 --outdir=dist
```
(Not as feature-rich as Vite's, but fast and easy)


8. Plugins
You can extend esbuild to:
- load assets (images, fonts)
- replace environment variables
- integrate with React frameworks
- add PostCSS, Sass, or CSS Modules

Example `esbuild.config.js`
```js
import { build } from 'esbuild';

build({
  entryPoints: ['src/index.tsx'],
  bundle: true,
  outdir: 'dist',
  plugins: [
    {
      name: 'replace-env',
      setup(build) {
        build.onResolve({ filter: /^env$/ }, () => ({
          path: JSON.stringify(process.env.NODE_ENV),
          namespace: 'env-ns',
        }));
      },
    },
  ],
});
```

Example React + Typescript build config:
```js
// esbuild.config.js
import { build } from 'esbuild';

build({
  entryPoints: ['src/index.tsx'],
  bundle: true,
  outfile: 'dist/bundle.js',
  platform: 'browser',
  sourcemap: true,
  minify: true,
  jsx: 'automatic',
  loader: { '.png': 'file', '.svg': 'file' },
}).catch(() => process.exit(1));
```

### Key Concepts to Know

- Entry point = main file that imports everything else
- Loader = tells esbuild how to handle file types (e.g. `.png`, `.ts`, `.css`)
- Platform = target (`browser`, `node`)
- Format = output type (`esm`, `cjs`, `iife`)
- External = exclude dependencies from bundling


### Bonus tips

- use `watch: true` for automatic rebuilds on file changes
- combine with PostCss or Tailwind CLI for styles
- use `define` to replace env vars:
```js
define: { 'process.env.NODE_ENV': '"production"' }
```
- works well with pnpm, yarn, and npm scripts
