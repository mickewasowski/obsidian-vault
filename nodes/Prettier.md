---
aliases:
context:
- "[[Linters formatters]]"
---

# Prettier

Prettier is an *opinionated code formatter*.
It focuses purely on **style consistency**.

---
### What it does?

It automatically formats your code (indentation, semicolons, quotes, wrapping, etc) so the whole team writes code that *looks* the same, no matter who types it.

> ESLint = code quality
> Prettier = code style


### How it works

1. Parses your code - builds an AST
2. Prints it back out in a consistent, predefined style
3. Ignores original whitespace and formatting - that's why it's "opinionated"

Run it with:
``` bash
npx prettier --write .
```
Formats everything automatically


### Common setup

1. Install

```bash
npm install -D prettier
```

2. Create config file `.prettierrc`:
```json
{
  "singleQuote": true,
  "semi": true,
  "tabWidth": 2,
  "trailingComma": "es5",
  "printWidth": 80
}
```


### Prettier + ESLint

They overlap (both touch style), so to avoid conflicts:
```bash
npm install -D eslint-config-prettier eslint-plugin-prettier
```

Then in `.eslintrc`:
```json
extends: [
  "plugin:prettier/recommended"
]
```

The above:
- turns off ESLint rules that Prettier already handles
- runs Prettier as an ESLint rule (`prettier/prettier`)

-> You get both linting and fomatting in a single command:
```bash
npx eslint . --fix
```
