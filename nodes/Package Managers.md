---
aliases:
context:
- "[[Web Development]]"
- "[[JavaScript]]"
---

#wip

# Package Managers

Package managers are tools that help install, update, and remove software pieces (packages).
They manage versions and what other packages are needed.

---
Handles:
- Dependencies: packages your project needs
- Dev dependencies: tools for development (e.g. eslint, vite)
- Versioning & locking: making sure you and your teammates use the same package version

#### Core files
- `package.json`
- Describes your project & dependencies:
``` json
{
  "name": "my-app",
  "version": "1.0.0",
  "scripts": {
    "dev": "vite",
    "build": "vite build"
  },
  "dependencies": {
    "react": "^18.2.0"
  },
  "devDependencies": {
    "eslint": "^8.0.0"
  }
}
```

- `package-lock.json` / `yarn.lock` / `pnpm-lock.yaml` - Locks exact versions so installs are **reproducible**
- `node_modules/` - the actual installed code. Huge, don't commit it.

#### Installing packages
- npm
``` sh
npm install react       # install and save in dependencies
npm install -D eslint   # install dev dependency
```

- yarn
``` sh
yarn add react
yarn add --dev eslint
```

- pnpm (performant npm)
``` sh
pnpm add react
pnpm add -D eslint
```

Difference:
- `-D` or `--save-dev` => devDependency
- Default -> dependency

#### Running scripts
Scripts in `package.json` can be run with:
``` sh
npm run dev
yarn dev        # yarn omits "run" for non-built-ins
pnpm dev
```
Example:
``` json
"scripts": {
  "dev": "vite",
  "test": "jest"
}
```

#### Key differences

> npm
- comes with Node.js by default
- stable, widely used
- has gotten much faster since v7+

> yarn
- originally built by Facebook to fix npm's slowness (back in npm v4 days)
- features - `workspaces` (monorepos), deterministic installs
- two flavors: yarn classic (v1) vs yarn berry (v2+) which is very different (plug'n'play, no `node_modules/` by default)

> pnpm
- newest & fastest option
- uses symlinks & content-addressable storage -> saves disk space (no huge duplicated `node_modules`)
- great for monorepos and modern workflows
- syntax is almost identical to npm

#### Updating and removing
``` sh
npm update lodash
npm uninstall lodash

yarn upgrade lodash
yarn remove lodash

pnpm update lodash
pnpm remove lodash
```

#### Global installs
``` sh
npm install -g typescript
yarn global add typescript
pnpm add -g typescript
```

#### `npx`, `pnpx`, `yarn dlx`
- lets you run binaries from `node_modules/.bin` without global installs
- Example:
``` sh
npx create-react-app myapp
pnpx create-react-app myapp
yarn dlx create-react-app myapp
```


#### Monorepose (advanced but useful)
- managing multiple packages in one repo
- supported by:
  - npm (workspaces)
  - yarn (workspaces, especially strong in v1+)
  - pnpm (workspaces, very efficient)

#### Best practices
- always commit `package.json` + lockfile
- don't commit `node_modules/`
- use exact versions for critical dependencies if stability matters
- learn one manager deeply, but know the differences
