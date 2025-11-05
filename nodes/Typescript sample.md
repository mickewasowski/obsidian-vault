---
aliases:
context:
---

# Typescript sample

---
### **Basics & TypeScript philosophy (1–10)**

1. Explain the key design goals of TypeScript and how it balances static typing with JavaScript’s dynamic nature.
2. Describe structural typing (duck typing) used by TypeScript and contrast it with nominal typing; give examples where structural typing produces surprising compatibility.
3. What is the difference between `type` and `interface` in TypeScript? When should you prefer one over the other and why?
4. Explain the meaning and impact of the `--strict` compiler flag; what individual flags does it enable and what tradeoffs do they introduce?
5. Discuss the TypeScript compilation pipeline: parsing, type-checking, emit. How does `tsc` differ from transpiler-only tools (Babel/esbuild/SWC)?
6. Explain declaration files (`.d.ts`): when they are needed, how they represent runtime JS shapes, and pitfalls when they drift from implementation.
7. Describe the difference between value space and type space in TypeScript and how `typeof` in types differs from JavaScript `typeof`.
8. Explain const assertions (`as const`) and literal widening; how do they affect inference for arrays, tuples, and object literals?
9. How does TypeScript handle primitive wrapper types (`String`, `Number`, `Boolean`) vs primitives (`string`, `number`, `boolean`) and what pitfalls arise?
10. Discuss covariance, contravariance, and bivariance in TypeScript’s type system. Where do bivariant parameters show up and what risks do they pose?

---

### **Basic types, unions, intersections & nullable types (11–20)**

11. Explain union types and how control-flow based type narrowing works with unions using `typeof`, `instanceof`, `in`, and custom type guards.
12. Describe intersection types and practical use-cases where intersections are preferable to extending interfaces.
13. How does the non-null assertion operator (`!`) work and why should it be used sparingly? Explain safer alternatives.
14. Compare `null` and `undefined` handling in TypeScript under `strictNullChecks` vs without; how does this influence API design?
15. Explain literal types (string/number/boolean literals) and how they enable discriminated unions and more precise APIs.
16. Describe numeric literal types and how template literal types can create typed string patterns (e.g., `"GET" | "POST"`, or `/users/${string}`).
17. How do tuple types differ from arrays in TypeScript and how do labeled tuple elements and rest elements in tuples improve API ergonomics?
18. Explain the purpose of the `unknown` type vs `any`. When should `unknown` be preferred and how do you safely use it?
19. Describe the `never` type and common scenarios where it appears (exhaustiveness checks, impossible code paths).
20. Discuss mapped unions (distributive conditional types) and how unions distribute over conditional types; show a case where this is useful or surprising.

---

### **Advanced type-level features (21–35)**

21. Explain conditional types: syntax, distributivity, and how `infer` works inside conditional types.
22. Describe key remapping in mapped types (`as` syntax) and use-cases for renaming keys or filtering properties.
23. How do recursive conditional types enable type-level computations (e.g., `Flatten`, `DeepReadonly`)? What recursion depth limitations exist?
24. Discuss template literal types and how they can model string transforms, route paths, or derive typed event names.
25. Explain utility types in `lib.es5.d.ts` (`Partial`, `Required`, `Readonly`, `Pick`, `Omit`, `Record`, `Exclude`, `Extract`, `NonNullable`) and situations where they are insufficient.
26. Describe how to create custom utility types (e.g., `DeepPartial`, `Mutable`, `Merge`) and pitfalls with preserving optional/readonly modifiers.
27. Explain variance in mapped types and how `+readonly` / `-readonly` / `+?` / `-?` modifiers control property modifiers.
28. Discuss using conditional types and inference to extract function parameter/return types (`Parameters`, `ReturnType`) and limits when working with overloads.
29. How do labeled tuples interact with rest elements and inference? Provide examples where labeled tuples improve developer ergonomics.
30. Explain how to model branded/opaque types in TypeScript to simulate nominal typing and the tradeoffs of those patterns.
31. Describe how to write types that constrain strings to particular patterns (e.g., UUIDs) and what can (and can’t) be enforced at compile time.
32. Explain the concept of type-level sets (`Exclude`/`Extract`) and how to use them to refine unions in library APIs.
33. Discuss index signatures vs mapped types for dynamic keys. When should you prefer one approach over the other?
34. How can you build type-safe heterogeneous dictionaries (keyed by literal types) and ensure correct lookup types at compile time?
35. Describe the role and risks of conditional type distribution across unions (e.g., when it’s helpful vs when it causes unexpected expansion).

---

### **Generics (36–45)**

36. Explain how generics work in TypeScript: declaration sites, use sites, default type parameters, and when to constrain generics with `extends`.
37. Discuss generic variance: when type parameters act covariantly, contravariantly, or invariantly, and how to design APIs to be safe.
38. How to create higher-kinded-like patterns in TypeScript (emulating HKTs) for library design? What are the limitations and common workarounds?
39. Explain how to infer generic types from function arguments and return positions; how to use overloads or helper functions to improve inference.
40. Describe strategies to keep generic types readable in editor tooltips (type aliases, named generics, splitting types).
41. How can you express heterogeneous tuples and variadic generics in TypeScript? Provide examples for function composition or pipe utilities.
42. Discuss using generics for typed builder or fluent APIs while preserving method chaining types safely.
43. Explain pitfalls of overusing generics (combinatorial explosion of inference) and how to mitigate complexity with pragmatic default types or wrapper helpers.
44. How to design a generic typed API client layer that infers response types from endpoint definitions safely.
45. Describe how to model polymorphic React components or component factories with generics and how to preserve prop inference for consumers.

---

### **Type inference, control-flow analysis & narrowing (46–55)**

46. Explain how TypeScript’s control-flow analysis performs type narrowing across branches, assignments, and loops.
47. Describe limitations of control-flow narrowing across function boundaries and asynchronous code; how to design APIs to preserve narrow types.
48. How does inference work for contextual typing (callbacks, initializers) versus best-common-type inference for arrays/tuples?
49. Explain how discriminated unions enable exhaustive switch checks and how to implement compile-time exhaustiveness assertions.
50. Discuss user-defined type guards (`x is T`) and their implementation tradeoffs compared to predicate-returning functions.
51. Describe how flow analysis handles variables mutated after narrowing and patterns to avoid losing narrowed types.
52. Explain how inference of generic return types can be forced for better developer experience (e.g., using `as const`, helper wrappers).
53. Discuss the differences between type inference in TSX/JSX contexts and normal TypeScript files, particularly for JSX intrinsic elements.
54. How does TypeScript infer types for chained Promise-like objects and async/await? Explain the `Awaited` utility type semantics.
55. Describe techniques to debug complex inferred types in editors and `tsc` (e.g., debugger types, using type-level tests, isolating components).

---

### **Type compatibility, declaration merging & module augmentation (56–63)**

56. Explain declaration merging for interfaces and namespaces. When is merging useful and what are common pitfalls?
57. Describe module augmentation and the correct way to add properties to existing module types (e.g., augmenting Express `Request`).
58. How does TypeScript resolve overloads and pick signatures for overloaded functions? What pitfalls should library authors avoid?
59. Discuss how module resolution works (classic vs Node, `baseUrl`, `paths`) and how `tsconfig` paths interact with bundlers.
60. Explain how ambient declarations (`declare global`, `declare module`) affect type checking and when they should be used carefully.
61. Describe how to write and publish package typings for a JS library: bundling `.d.ts`, `types` field in package.json, `index.d.ts` vs `typesVersions`.
62. Explain differences between exporting types vs values (`export type` vs `export`) and how to avoid accidental value imports at runtime.
63. Discuss how declaration merging can cause subtle compatibility problems across library versions and how to avoid breaking consumers.

---

### **Compiler options, tooling & build strategies (64–72)**

64. Explain important `tsconfig.json` options that influence type-checking and code-generation (`module`, `target`, `lib`, `moduleResolution`, `outDir`, `declaration`).
65. Describe incremental builds, composite projects, and Project References: when to use them and how they affect build performance and edit/compile cycles.
66. Compare transpiling with `tsc` vs Babel/esbuild/SWC: type-checking concerns, emit differences (`const enums`, `namespaces`), and incremental workflows.
67. How do `isolatedModules` and `transpileOnly` modes affect which TypeScript features you can use and what errors are deferred?
68. Explain source maps and declaration maps: how they help debugging and how to configure them correctly for `.ts` → `.js` and `.d.ts` mapping.
69. Describe how to set up type-checking in CI with monorepos, multiple tsconfigs, and different runtime targets (Node/browser).
70. Discuss strategies for integrating TypeScript with linters and formatters (`ESLint` + `@typescript-eslint`, Prettier) and key rules to enforce.
71. Explain how to write and run type tests (`dtslint`, `tsd`) for library authors to guarantee typing behavior across versions.
72. Describe how to migrate a build system to keep fast dev iteration (watch mode, project references) while ensuring full type-checking in CI.

---

### **Runtime interop, JS libraries & third-party typings (73–80)**

73. Explain how to consume an untyped third-party JS library safely: writing minimal declaration files, using JSDoc, or runtime validation.
74. Describe the `@types` ecosystem: when to rely on DefinitelyTyped, when to ship your own types, and how to maintain them.
75. Discuss pitfalls of types drifting from runtime behavior (e.g., optional props, overloaded behaviors) and strategies to detect/mitigate them.
76. How do module formats (ESM vs CommonJS) affect import types and default import semantics in TypeScript? Explain interop flags like `esModuleInterop` and `allowSyntheticDefaultImports`.
77. Explain how to type dynamic `require`/`import` or JSON imports and how to configure `resolveJsonModule` and `esModuleInterop` for predictable types.
78. Describe how to type wrapper modules for native Node APIs or C bindings (`node-gyp`) and the role of node types in type safety.
79. Discuss versioning of types vs runtime package versions and how to handle breaking changes in types for a stable consumer experience.
80. Explain how to test and validate that type-level constraints reflect runtime invariants using lightweight runtime checks or type-tests.

---

### **TypeScript with frameworks & JSX (81–86)**

81. Describe best practices for typing React components with TypeScript (function components, props inference, default props, children).
82. Explain typing approaches for other front-end frameworks (Vue 3 Composition API, Svelte, Angular): where TS shines and common integration gotchas.
83. How does TSX’s JSX namespace and intrinsic element typing work, and how to extend `JSX.IntrinsicElements` for custom elements?
84. Discuss typing higher-order components, `forwardRef`, and polymorphic component patterns that preserve props inference in React.
85. Explain how to type React context, hooks, and complex state objects to avoid implicit `any` and improve DX.
86. Describe strategies to incrementally adopt TypeScript in framework-heavy codebases with lots of runtime patterns (e.g., template-driven code).

---

### **Type-level testing, ergonomics & developer experience (87–92)**

87. What are type-level tests (assertions that types equal expected types) and how to implement them (`tsd`/`dtslint`, conditional type tests)?
88. Discuss how to design types for good editor UX (intellisense, concise hover text, minimal noise) while preserving strict correctness.
89. Explain techniques to keep complex types maintainable: splitting into small aliases, naming conventions, and documentation comments.
90. How do you balance type strictness with ergonomics for API consumers (more helpful inference vs fewer required annotations)?
91. Describe patterns to provide helpful compiler errors and custom error messages via branded types or tagged property patterns.
92. Explain how to detect and debug type errors that only show up for consumers (library consumers but not in local dev) and mitigations like test matrices.

---

### **Migration, maintenance & long-term strategies (93–100)**

93. Describe a practical incremental migration plan for a large JS codebase to TypeScript, including strategies for `allowJs`, `checkJs`, and declaration generation.
94. Discuss how to maintain type-safety across a monorepo with many packages: shared types packages, versioning, and project references.
95. Explain strategies for handling breaking type changes in public APIs (`semver`, `typesVersions`, deprecation typing patterns).
96. How do you design a runtime data-validation and schema approach to complement TypeScript (`zod`, `io-ts`, `runtypes`) and where to place validation boundaries?
97. Describe approaches to prevent technical debt in types (abuse of `any`, type assertions) including lint rules, code review checklists, and automated `.d.ts` tests.
98. Discuss the tradeoffs of emitting declarations for internal modules vs only public packages and how `declarationMap`s affect debugging.
99. Explain how to keep TypeScript configuration and lib targets aligned with runtime environments (browsers, Node versions) and polyfill strategies.
100. Describe how to evaluate whether to adopt future TypeScript language features (e.g., template variadic kinds, type-level operators) and manage compatibility across team toolchains.
