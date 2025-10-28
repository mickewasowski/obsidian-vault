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

In `package.json` the files you provide in `exports` define the bundled files, meaning this is the way you manually create chunks of files.
```json
{
  "exports": {
    "react": "./src/path_to_index_file.ts",
    "react-native": "./src/path.ts"
  }
}
```

Then in the Vite config you can name these chunks in a way you'd like:

```js
export default defineConfig({
  build: {
    rollupOptions: {
      output: {
        entryFileName: (chunkInfo) => {
          if (process.env.MY_CUSTOM_ENV) {
            return `my-custom-bundle.[format].js`;
          }

          return `[format]/[name].js`;
        },
      },
    },
  },
});
```
