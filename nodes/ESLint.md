---
aliases:
context:
- "[[Linters formatters]]"
---

# ESLint

ESLint is a JS linter checking code for problems, maintaining consistent style, and finding errors.

---
### What is ESLint?

It is a **static analysis tool** for JS/TS.
It parses your code *before* it runs and:
- finds errors - unused vars, undefined vars, unreachable code
- enforces **style and best practices** (indentation, quotes, semicolons, naming)
- helps enforce team conventions and consistency across a codebase
- integrates tightly with editors (like Neovim via LSP, or VSCode)
- can **auto-fix** many issues

> [!tip] ESLint focuses on *code correctness*, while Prettier focuses on *formatting*.


### How it works under the hood?

1. Parser: converts your code into an AST (abstract syntax tree)
    - for TS, you use `@typescript-eslint/parser`
2. Rules: each rule checks part of that tree (e.g. "no-unused-vars")
    - rules can be "off", "warn", or "error"
3. Plugins/Extends: Bundles of rules for specific frameworks or languages
    - example: `eslint:recommended`, `plugin:react/recommended`
4. Config file (`.eslintrc.*`): where you define your setup - parser, environment, rules, and plugins



### Format

- can be used both for a file or directory
```
npx eslint path-to-file-directory --fix
```