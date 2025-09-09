---
aliases:
context:
- "[[Code quality]]"
- "[[Code readability]]"
---

#wip

# Linters formatters

Improve code quality by finding errors, bugs, and style issues (linters) and automatically fixing formatting.

---
### Summary
Automatically fixing formatting like indentation and spacing (formatters).
Ensure consistency, readability, and early error detection.

### Examples
[[ESLint]]
[[Prettier]]

### Concept
Linters aren't exclusive to JavaScript.
A linter is a tool to help you improve your code.
It analyzes your code looking for problems.
The term linter comes from a tool originally called "lint" that analyzed C source code in 1978.
The goal of this tool is to analyze the source code and come up with compiler optimizations.
Linters are way more valuable for interpreted languages since there isn't a compiler to detect erros during development time.


### Benefits
- fewer errors in production - helps diagnose and fix technical issues (code smells) in the code 
- readable, maintainable, and more consistent code - can enforce rules (such as how many characters per line, quotes, etc)
- fewer discussions about code style and aesthetic choices during code reviews
- objective measurement of code quality
- more secure and performant code - some linters can analyze code regarding it's performance
- education about code quality reaches more developers - can help more inexperienced devs to learn about code quality


### Types of checks

- Syntax errors

- Code Standards Adherence - having a single consistent coding syle is beneficial for decreasing the cognitive load of reading, understanding, and maintaining code. A codebase that has a consistent code style will be easier to understand, and the developers that use it will be less likely to introduce bugs.
That's why some linters specialize in verifying codebases for adherence to code styles. Some tools are opinionated, i.e. they come with a pre-defined set of rules and conventions that can't be changed; others are highly customizable.

- Potential problems (a.k.a Code smells) - signs that something might be wrong with your code. Examples can be long functions, code that is too complex (objectively).

- Security checks - money, reputation, GDPR
