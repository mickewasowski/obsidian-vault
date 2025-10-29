---
aliases:
context:
- "[[Code Organization/Architecture strategy]]"
---

# Monorepo

A monorepo (short for *monolithic repository*) is a single code repository that contains **multiple projects**.

---
### What is monorepo
It could contain libraries, applications, services, or packages - all managed together in one place.
Instead of having separate repositories (a *polyrepo*) for each project, a monorepo stores everything in a single repo with a structured folder layout.

Example structure:
```bash
/monorepo
  /packages
    /ui-components
    /utils
  /apps
    /web
    /admin
  package.json
  tsconfig.json
```
Here:
- `ui-components` and `utils` might be shared libraries
- `web` and `admin` are separate applications
- everything lives together in one repository


### Common Monorepo tools

1. Task orchestration
- Nx - great for large-scale JS/TS projects
- Turborepo - fast build system optimized for JS/TS
- Lerna - manages versioning and publishing for multiple packages
- Bazel - used in very large organizations (like Google)

2. Dependency management
- pnpm workspaces
- npm workspaces
- yarn workspaces

3. Building
- Vite
- Rollup
- esbuild
- custom builds

4. TypeScript support
- `tsconfig.base.json` + per package `tsconfig.json` with references


### Pros of Monorepo

1. Benefits:
- shared code - reuse packages easily (`@company/ui`, `@company/utils`)
- consistent tooling - same ESLint, Prettier, TypeScript, etc.
- easier refactors - one commit can fix multiple apps/packages
- atomic commits - everything versioned together, no sync issues
- faster local dev - no need to publish to npm and re-install internal libs


2. Drawbacks:
- complex builds - can get slow or tricky without caching tools
- CI/CD complexity - need to detect which app/packages changed
- access control - harder to limit access if all teams share the same repo
- versioning - deciding between a single version or independent ones


### How to setup and use

1. Configuration setup:
- package.json - defines workspaces
- npm-workspace.yaml - workspace root config
- tsconfig.base.json - shared TS config

Example directories setup:
``` bash
my-monorepo/
├── package.json               # defines workspaces
├── pnpm-workspace.yaml        # workspace root config
├── tsconfig.base.json         # shared TS config
├── apps/
│   ├── marketing-site/
│   └── game-lobby/
└── packages/
    ├── ui-library/
    ├── utils/
    ├── api-client/
    └── config/
```
- `apps/*` -> all runnable apps (React, NextJS, etc.)
- `packages/*` -> shared libraries, each with its own `package.json`


2. Root configuration:

*package.json*
``` json
{
  "private": true,
  "name": "my-monorepo",
  "workspaces": [
    "apps/*",
    "packages/*"
  ],
  "devDependencies": {
    "typescript": "^5.6.0"
  },
  "scripts": {
    "build": "turbo run build",       // if using Turborepo
    "lint": "eslint . --ext .ts,.tsx"
  }
}
```
> `private: true` flag prevents the *root* from being published, only individual packages can be published.


*npm-workspace.yaml*
``` yaml
packages:
  - "apps/*"
  - "packages/*"
```


3. Example package configuration

```json
{
  "name": "@company/ui-library",
  "version": "1.0.0",
  "main": "dist/index.js",
  "module": "dist/index.esm.js",
  "types": "dist/index.d.ts",
  "scripts": {
    "build": "vite build"
  },
  "peerDependencies": {
    "react": "^18.0.0"
  }
}
```

```json
{
  "name": "@company/utils",
  "version": "1.0.0",
  "main": "dist/index.js",
  "types": "dist/index.d.ts",
  "scripts": {
    "build": "tsup src/index.ts --dts"
  }
}
```
> Both are standalone and publishable


4. Local linking between packages
- npm (pnpm, yarn) workspaces automatically create symlinks workspace dependencies
- you could simply provide the dependencies in the app/package like so:
```json
{
  "dependencies": {
    "@company/ui-library": "workspace:*",
    "@company/utils": "workspace:*"
  }
}
```


5. Selective installation by users
- this is achieved by independent versioning approach
- they can install a package or app by `npm install @company/ui-library` and they wouldn't even know it's from a monorepo
- you publish individually like so:
```bash
cd packages/ui-library
npm publish --access public
```
> Or you could use tools like Changesets, Lerna, or Nx release to automate versioning and publishing


6. Sharing configuration
```json
// packages/ui-library/tsconfig.json
{
  "extends": "../../tsconfig.base.json",
  "compilerOptions": {
    "outDir": "dist",
    "rootDir": "src"
  },
  "include": ["src"]
}
```
- you can configure base ESLint, TS, etc. and extend it in your app/package own `package.json`


7. Managing builds efficiently
- you can use a build orchestrator:
   - *Turborepo* - `turbo run build --filter=@company/ui-library`
   - *Nx* - `nx run-many --target=build --projects=ui-library,utils`
- these tools:
   - detect dependency graphs between packages
   - build only changed packages
   - cache results locally or remotely


8. Versioning options
Two main models:
- fixed/locked - all packages share the same version
- independent - each package has its own version
> Changesets lets you automate and mix both approaches












