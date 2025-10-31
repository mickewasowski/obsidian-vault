---
aliases:
context:
- "[[Module bundlers]]"
---

# SWC

SWC (Speedy Web Compiler)

---
### What is SWC

SWC is a modern Javascript/Typescript compiler and bundler built in Rust.
It is designed to be much faster than Babel and Terser.
It's mainly used for frontend development to transform, compile, and minify code.


### Key features

1. Fast Compilation
    - written in Rust (low-level language like C) - extremely fast
    - can handle large projects with much lower build times
2. Javascript and Typescript support
    - transpiles modern Javascript (ES6+) to older versions for browser compatibility
    - can handle Typescript out-of-the-box without needing `tsc` for compilation
3. Minification
    - includes a built-in minifier for Javascript and Typescript, similar to Terser
4. Plugin Ecosystem
    - supports plugins to customize code tranformations
5. Integration with Modern Tooling
    - often used with Next.js, Vite, and other modern frameworks as a faster alternative to Babel
    - can replace Babel for transforming React/JSX code
