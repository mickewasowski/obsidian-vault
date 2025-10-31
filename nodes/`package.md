---
aliases:
context:
- "[[JavaScript]]"
---

# `package.json`

---
It defines metadata, dependencies, scripts, and configuration for your project, and it's used by tools like `npm`, `yarn`, or `pnpm` to manage packages and scripts.


### Core purpose
- describe your project (name, version, author, license)
- list dependencies (`dependencies`, `devDependencies`, `peerDependencies`)
- define build/test/start scripts (and others)
- configure tools (Babel, ESLint, Jest, etc.)
- specify module resolution and entry points


### Common structure
```json
{
  "name": "my-app",
  "version": "1.0.0",
  "description": "A sample React app",
  "main": "index.js",
  "scripts": {
    "start": "react-scripts start",
    "build": "react-scripts build"
  },
  "dependencies": {
    "react": "^18.3.1",
    "react-dom": "^18.3.1"
  },
  "devDependencies": {
    "typescript": "^5.4.0"
  },
  "keywords": ["react", "frontend", "typescript"],
  "author": "John Doe",
  "license": "MIT"
}
```

1. name - the name of your package when published to npm
2. version - version of your project following [semver][https://semver.org/]
3. description - short explanation of what your project does
4. keywords - helps discover your package in npm searches
5. homepage - link to the project homepage or documentation
6. bugs - where to report issues
7. license - declares license type (MIT, ISC, Apache-2.0)
8. author/contributors:
```json
"author": {
  "name": "John Doe",
  "email": "john@example.com",
  "url": "https://example.com"
}
```

### Execution & Entry Points

9. main - entry point when your package is imported using `require()`
10. module - ES module version (for bundlers like Rollup/Webpack)
11. types/typings - points to Typescript declaration file
12. exports - defines explicit entry points per environment
```json
"exports": {
  ".": {
    "import": "./dist/index.esm.js",
    "require": "./dist/index.cjs.js"
  }
}
```
13. files - lists which files are included when publishing

### Script & Dependencies

14. scripts - define npm commands
15. dependencies - runtime dependencies (used in production)
16. devDependencies - used during development only (Typescript, ESLint, Jest)
17. peerDependencies - declares that your package **expects** the consumer to install these
18. peerDependenciesMeta - marks peer dependencies as optional
```json
"peerDependenciesMeta": {
  "react-dom": {
    "optional": true
  }
}
```
19. optionalDependencies - dependencies that can fail to install without breaking
20. bundleDependencies/bundledDependencies - forces inclusion of dependencies when packaging


### Tool Configurations (Custom fields)

Many tools allow inline config inside `package.json`
- "eslintConfig"
- "babel"
- "jest"
- "prettier"
- "browserslist"
- "engines"
