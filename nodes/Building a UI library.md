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


### How to test your library locally

- run `npm run build` in you library to create `/dist`

1. With `npm link`:
- in your library's directory run `npm link` [[npm link]]
- in the project where you want to use it run `npm link your-library-name`

Now after the above steps you will be able to import components from the library inside your project.
If you need to make change to the library simply rebuild the library and the changes will be applied immediately.


2. With `npm pack` - this is closer to the *real publish flow*
- inside your library run `npm pack` - this creates a `.tgz` file
- then install it in your project `npm install ../path-to/my-lib-1.0.0.tgz`


2. If you're actively developing
- in your project add the library to your dev dependencies
``` json
"dependencies": {
  "your-design-system": "file:../your-design-system"
}
```
- then run `npm install`
- this symlinks the local package - fast and consistent