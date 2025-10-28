---
aliases:
context:
  - "[[Module bundlers]]"
---

# Vite

---

### What is Vite

Vite is a frontend build tool that replaces traditional bundlers like Webpack or Parcel.

Its goals:

- blazing-fast development (instant dev server startup)
- modern build pipeline (native ES modules, Rollup-based bundling)
- minimal configuration

### How it works

1. Dev Mode (ES Modules)
   During development Vite doesn't bundle code at all. It uses the browser's native ES module system and serves files **on-demand** via an ultra-fast dev server.

- When you import a file:

```js
import { MyComponent } from "./MyComponent.tsx";
```

Vite transforms it quickly and serves it as-needed.

- File changes trigger **instant updates** via **Hot Module Replacement** (hot reload)
  This means you can start coding almost instantly - no more waiting for Webpack to compile everything.

2. Build Mode (Rollup)
   When you run `vite build`, it switches to **Rollup** for bundling and optimization:

- tree shaking
- code splitting
- asset optimization
- minification
- output ready for production deployment

So:

- Dev = fast + dynamic
- Build = optimized + bundled

3. Key Vite concepts
   | Concept | Description | Example |
   | -------------------------------- | --------------------------------------------- | ------------------------|
   | **Entry point** | Usually `index.html` (not `index.js`!) | `<script type="module" src="/src/main.tsx"></script>` |
   | **Plugins** | Extend Vite behavior — same plugin format as Rollup | e.g. `@vitejs/plugin-react`, `vite-plugin-svgr` |
   | **Alias** | Shorten import paths | `resolve.alias: { '@': '/src' }` |
   | **Env files** | Support `.env`, `.env.development`, `.env.production` | Access via `import.meta.env.VITE_API_URL` |
   | **Static assets** | Put in `/public` folder (copied as-is to build) | `/public/logo.png` → `/logo.png` |
   | **Hot Module Replacement (HMR)** | Automatically updates changed modules without page reload | Built-in |

4. Environment variables
   Vite automatically loads `.env` files.
   Only variables prefixed with `VITE_` are exposed to the frontend.

```bash
# .env
VITE_API_URL=https://api.example.com
```

Then access it in code like:

```ts
console.log(import.meta.env.VITE_API_URL);
```

5. Common plugins you'll use

- `@vitejs/plugin-react` - enables JSX, Fast Refresh, and React-specific optimizations
- `vite-plugin-svgr` - import SVGs as React components
- `vite-plugin-pwa` - add PWA support
- `vite-plugin-eslint` - runs ESlint automatically during dev
- `vite-tsconfig-paths` - auto-resolve TS path aliases

### Gotchas

- Server-side rendering needs explicit setup (e.g. with Next.js or Vite SSR plugins)
- Some older libraries that use CommonJS may need `optimizeDeps.include`
- Not ideal if you rely on non-ESM third-party packages heavily

### Setup for UI library supporting multiple frameworks (code splitting)

In `package.json` the files you provide in `exports` define the **public entry points** for consumers of your package.

- It tells bundlers or Node which file to load for a given import path
- It does **not** control how Vite or Rollup split or bundle files
- The actual "chunking" or code splitting happens during your build step, based on **Rollup config** and **import graph**

```json
{
  "exports": {
    "./react": "./dist/react/index.js",
    "./react-native": "./dist/react-native/index.js"
  }
}
```

The above means consumers can do:

```js
import { Button } from "my-ui-lib/react";
import { Button } from "my-ui-lib/react-native";
```

But you still need to configure your bundler to build those files (e.g. separate Rollup/Vite entries)

If you want to create multiple bundles (like one for React and one for React Native), you need to declare **multiple entry files** in your `vite.config.ts`

```js
export default defineConfig({
  plugins: [react()],
  build: {
    lib: {
      entry: {
        react: "src/react/index.ts",
        "react-native": "src/react-native/index.ts",
      },
      formats: ["es", "cjs"],
    },
    rollupOptions: {
      output: {
        entryFileNames: `[name]/index.[format].js`, // here name is the key from the entry object
                // format is only necessary if you plan on building multiple formats
      },
    },
  },
});
```
That tells Vite/Rollup:
- build both `react` and `react-native` bundles
- output them under folders like:
```bash
dist/react/index.es.js
dist/react-native/index.es.js
```
Then your `"exports"` in `package.json` points to these bundles

