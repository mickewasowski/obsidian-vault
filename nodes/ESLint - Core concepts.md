---
aliases:
context:
- "[[ESLint]]"
---

# ESLint - Core concepts

---

### Parser vs Plugin

- Parser - converts your source code into an AST (abstract syntax tree) so ESLint can read it.
    - for js -> default `espree`
    - for ts -> `@typescript-eslint/parser`
- Plugin - a set of rules built on top of ESLint
    - example: `eslint-plugin-react`, `@typescript-eslint/eslint-plugin`
    - you can load multiple plugins depending on your stack

> Parser = undrestands your language
> Plugin = defines what's "good" or "bad" in that language/framework


### Extends vs Plugins vs Rules

- `extends` - brings in **predefined rule sets** (like presets)
    - example: `plugin:react/recommended` enables all recommended React rules
- `plugins`: declares which **plugins** you want to use (so ESLint knows where rules come from)
- `rules`: your **custom overrides** - enabling, disabling, or changing severity

> **extends** = base config
> **plugins** = what's available
> **rules** = your tweaks


### Environments

- Defines **global variables** that exist in your runtime so ESLint doesn't flag them as "undefined".
    - `browser`: adds `window`, `document`, etc.
    - `node`: adds `process`, `require`, etc.
    - `es2021`: adds new globals like `Promise`, `globalThis`

> If you use `window` in Node environment without `"browser": true`, ESLint will warn you.


### Overrides

- Allows different rules for **specific file patterns**
    - common for tests, config files, or legacy code

```js
overrides: [
  {
    files: ["*.test.tsx"],
    rules: {
      "@typescript-eslint/no-explicit-any": "off",
    },
  },
]
```

> It helps apply stricter rules to source code but relax them for tests or scripts.


### Performance

- ESLint can be **slow** on large projects - you can improve it with:
    - `eslint_d` - runs ESLint as a background daemon (instant feedback)
    - `--cache` - lints only changed files
    - smaller file targets (e.g. lint `src/**` only)

> Goal - make linting part of your everyday flow, not a bottleneck.


### Custom rules

- You can define your own rules if your project has unique conventions.
    - for example: ensure all files have a specific comment header or enforce consistent naming of theme variables.
- Usually done via a custom ESLint plugin (advanced use case)

> Shows mastery - you're not just following the tool; you can extend it for your team or library.
