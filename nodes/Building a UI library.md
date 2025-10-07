---
aliases:
context:
- "[[UI Libraries]]"
---

# Building a UI library

How To's and useful information you might need when building a UI library.

---
### Package.json structure and necessary fields

```json
{
  "name": "ui-design-system",
  "version": "0.1.0",
  "type": "module",
  "main": "dist/index.js",
  "module": "dist/index.mjs",
  "types": "dist/index.d.ts",
  "exports": {
    ".": {
      "import": "./dist/index.mjs",
      "require": "./dist/index.js"
    }
  },
  "scripts": {
    "dev": "tsup src/index.ts --watch",
    "build": "tsup src/index.ts --format cjs,esm --dts",
    "clean": "rm -rf dist"
  },
  "peerDependencies": {
    "react": "^19.1.1",
    "react-dom": "^19.1.1"
  },
  "devDependencies": {
    "@types/react": "^19.1.16",
    "@types/react-dom": "^19.1.9",
    "typescript": "~5.9.3",
    "tsup": "^8.0.0"
  }
}
```
The above is the general structure you need to follow when you want to build a library.

- `name` - this is the published name of the library. This is what users use to install it.
- `peerDependencies` - Packages expected to be provided by the consuming project. React dependencies need to be added here. Otherwise when someone install your library, `npm` will install *another copy of React* in node_modules.
That would lead to errors such as `Invalid hook call`.
- `scripts` - these are shortcuts for running commands, useful when developing
- `main` - entry point for `CommonJS` consumers (`require()`)
- `module` - entry point for ES module consumers (`import`)
- `types` - entry point for TypeScript types
- `exports` - defines modern, explicit entry points for bundlers and Node
- `devDependencies` - tools only needed for developing/building the library

> `tsup` - this is a bundler. Bundles to `/dist` in ESM and CJS formats, generates `.d.ts` automatically.

`name`, `type`, `version` - describe the package itself
`main`, `module`, `types`, `exports` - tell bundlers and Node how to import the library
`scripts` - automate your tasks while developing

