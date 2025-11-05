---
aliases:
context:
---

# React sample

---
### **Core React fundamentals (1–8)**

1. Explain the conceptual model of React: virtual DOM, reconciliation, and how React maps declarative components to imperative DOM updates.
2. Describe the difference between React elements, components (function/class), and instances — where each exists in memory and lifecycle.
3. Explain JSX: how it compiles to `React.createElement`, how children are represented, and tradeoffs of using JSX vs hyperscript or `h()`.
4. How does reconciliation work at a high level? Explain keys, element type comparison, and common causes of unexpected re-renders or remounts.
5. Describe the React render phase vs commit phase: what should and must not be done in each phase, and why side-effects belong in effects.
6. Explain controlled vs declarative rendering in React and how immutability of props/state aids predictable rendering.
7. Discuss how React batches state updates and how batching differs between events, native events, and async/Promise contexts.
8. Explain the difference between React’s development build and production build; what runtime checks are removed and why this matters.

---

### **Components & props (9–16)**

9. What are the tradeoffs between function components and class components today; what behaviors do hooks replace from classes and what remains different?
10. Explain prop drilling, patterns to avoid it, and how to design component APIs to minimize unnecessary coupling.
11. How do `defaultProps`, destructured defaults, and functional default parameter values differ for function components and what are migration considerations?
12. Describe component composition patterns: children-as-function, render props, higher-order components, and when to prefer each.
13. Explain how to design a stable public component API (props, events/callbacks), including versioning and deprecation strategies for a component library.
14. How does React treat children as opaque data? Discuss scenarios where children identity affects reconciliation and how to handle dynamic children lists.
15. Describe `propTypes` and runtime prop validation tradeoffs vs TypeScript static typing; when runtime validation is still necessary.
16. Explain how to implement component contracts and assertions for invariants (e.g., required sibling components, context providers) and how to surface useful errors.

---

### **State & lifecycle/hooks (17–28)**

17. Explain in detail how `useState` works under the hood (state queues, render closures) and common pitfalls with stale closures.
18. How does `useEffect` differ from `useLayoutEffect` in timing and impact on rendering; give concrete examples when each is appropriate.
19. Describe rules of hooks and why they’re necessary; how linters and static analysis can enforce them and pitfalls of conditional hooks.
20. Explain how to implement custom hooks safely: state encapsulation, returning stable references, memoizing callbacks and values, and composing hooks.
21. Discuss `useRef`: identity semantics, mutable `.current`, when to use refs vs state, and how refs avoid re-renders.
22. How do you manage local derived state vs computed values from props? Discuss `useMemo`, derived state anti-patterns, and synchronization strategies.
23. Explain `useReducer`: when it’s preferable to useReducer over useState, how to structure reducers for composition, and handling side-effects.
24. Describe how to implement effect cleanup patterns correctly (subscriptions, timers, `AbortController`) and common leak sources in effects.
25. Explain how to avoid tearing and race conditions when effects depend on async operations and component unmounting.
26. Discuss patterns for exposing imperative instance methods from function components (`useImperativeHandle`) and when to prefer them.
27. Explain how state initializer functions work for expensive initial state and how lazy initialization interacts with re-renders.
28. Describe strategies for managing form state, complex nested state, and normalization approaches with hooks.

---

### **Context & state management (29–36)**

29. Explain how React Context works internally (provider tree, subscription model) and why context updates can cause re-renders in descendants.
30. Compare lifting state up, context, and external stores (Redux, Zustand, MobX) for different app sizes and concurrency needs.
31. How do you design a performant Context provider to avoid unnecessary child renders? Discuss memoization, splitting contexts, and selector patterns.
32. Explain the tradeoffs of colocated state vs global state and how to decide where to put state given frequency of updates and sharing needs.
33. Describe patterns for derived selectors, memoized selectors, and normalization in client-side stores to minimize recalculation and re-renders.
34. Discuss optimistic updates, conflict resolution, and consistency models when state is modified locally and reconciled with the server.
35. Explain how server-driven state (SSR/hydration) interacts with client-side stores and strategies to hydrate and rehydrate store state safely.
36. Describe how to implement time-travel debugging or undo/redo semantics in a React app and the state design implications.

---

### **Performance optimization (37–44)**

37. Explain how to profile React apps: what to measure, how to interpret flame charts, and differences between CPU cost and wasted renders.
38. Describe when and how to use `React.memo`, `useMemo`, and `useCallback`; common misuse that can hurt rather than help performance.
39. Discuss virtualization/windowing for large lists (`react-window`, `react-virtualized`): tradeoffs for accessibility, keyboard navigation, and layout.
40. Explain why preventing re-renders isn’t always the primary goal and how rendering cost compares to DOM updates and layout.
41. Describe techniques to reduce bundle size: code-splitting components, dynamic import boundaries, and how to avoid shipping heavy libs to the client.
42. Explain how to measure and optimize Time to Interactive (TTI) and First Contentful Paint (FCP) in a React app, including lazy-loading and SSR strategies.
43. Discuss `useDeferredValue` and `startTransition` (if applicable): how they affect scheduling, user-perceived latency, and rendering priorities.
44. Describe memoization strategies for expensive computations in render and how to maintain correctness when inputs are complex objects.

---

### **Rendering & reconciliation details (45–52)**

45. Explain key pitfalls that cause component remounts (changing key, element type) and how to use keys correctly across lists and portals.
46. Describe portals: use-cases, event bubbling across portal boundaries, and how portals affect layout and stacking context concerns.
47. Explain hydration: what can go wrong during client hydration of server-rendered markup and strategies to avoid hydration mismatches.
48. Discuss how React decides to reuse DOM nodes across renders and techniques to preserve element state (e.g., inputs) across reorders.
49. Explain how refs to DOM nodes and component instances persist across renders and how remounts impact them.
50. Describe how to implement progressive enhancement or partial hydration strategies and their tradeoffs for SEO and interactivity.
51. Explain Suspense boundaries and how they affect fallback rendering, nested boundaries, and avoiding waterfall loading.
52. Discuss render-as-you-fetch patterns and how to coordinate data fetching with the render lifecycle for minimal waterfall requests.

---

### **Forms, controlled vs uncontrolled, and inputs (53–56)**

53. Explain differences between controlled and uncontrolled form components, including performance, validation timing, and server sync tradeoffs.
54. Describe strategies for building accessible, keyboard-friendly custom inputs (composition events, IME, caret control) in React.
55. How do you handle complex form validation (async validation, cross-field dependencies) and UX patterns for error display and focus management?
56. Explain techniques for preserving user input across navigation or remounts and handling autosave and conflict resolution.

---

### **Routing, SSR, and hydration (57–61)**

57. Discuss client-side routing tradeoffs: history API vs hash routing, code-splitting per route, and accessibility concerns for SPA navigation.
58. Explain server-side rendering (SSR) approaches for React (traditional SSR, streaming SSR, partial hydration) and their tradeoffs.
59. Describe hydration pitfalls (mismatched markup, deterministic IDs, random timestamps) and techniques to produce deterministic server markup.
60. Explain prefetching and preloading strategies for route-based code-splitting and data to improve perceived navigational speed.
61. Discuss authentication and protected routes across SSR and CSR boundaries, including cookie/session vs token strategies and secure redirects.

---

### **Testing React components & apps (62–69)**

62. Explain different levels of testing (unit, integration, E2E) for React apps and what each level should assert.
63. Discuss the philosophy of React Testing Library vs Enzyme: querying by user-visible output vs implementation details and why it matters.
64. How do you test async UI updates, timers, and effects reliably? Discuss fake timers, `act()`, and waiting strategies.
65. Describe strategies for testing components that use context, portals, and Suspense, including mocking providers and fallback boundaries.
66. Explain testing of performance-sensitive code and how to write regression tests for render counts or expensive computations.
67. Discuss snapshot testing: benefits, pitfalls, and when snapshots become brittle and should be avoided.
68. Explain end-to-end testing considerations for React apps (Cypress/Playwright): state setup, network stubbing, and flakiness mitigation.
69. Describe how to set up CI test runners for frontend tests that need browsers or headless environments and parallelization strategies.

---

### **Accessibility, internationalization & UX (70–74)**

70. Explain accessibility best practices for React: semantic markup, focus management, ARIA usage, and common anti-patterns caused by custom components.
71. Describe how to build accessible modal dialogs, tooltips, and dropdowns in React, including focus trapping and keyboard interactions.
72. Discuss internationalization strategies: message extraction, pluralization, ICU formatting, and runtime vs compile-time locale data.
73. Explain strategies to support RTL layouts and bi-directional text in component libraries and style systems.
74. Describe how to measure and validate accessibility in CI (`axe`, `pa11y`) and processes for prioritizing and fixing a11y issues.

---

### **TypeScript with React (75–79)**

75. Explain typing strategies for React function components, props, default props, and children in TypeScript without leaking types to consumers.
76. Discuss typing hooks and custom hooks in TypeScript: best practices for return types, generics, and inference.
77. How do you type `forwardRef` and `useImperativeHandle` patterns safely in TypeScript for exposing imperative APIs?
78. Describe strategies for gradually migrating a JavaScript React codebase to TypeScript and handling third-party untyped modules.
79. Explain pitfalls of typing state and reducers in TypeScript (discriminated unions, action types) and patterns to keep types maintainable.

---

### **Patterns & architecture (80–85)**

80. Describe container/presentational component separation and modern alternatives (cohesive component modules, hooks) for organizing UI code.
81. Explain component composition vs inheritance in React and provide examples where composition cleanly models concerns like theming or behavior.
82. Discuss micro-frontend patterns for React: integration options (iframes, module federation), styling isolation, and shared dependency strategies.
83. Explain how to design a scalable component library: Storybook usage, visual regression testing, tokens, and semantic API design.
84. Describe how to structure a medium-sized React app by domain, feature, or layer and tradeoffs for maintainability and testability.
85. Discuss strategies for progressive migration of legacy UI into a React app (gradual rewriting, adapter layers, shadow DOM).

---

### **Styling, CSS-in-JS & component styles (86–90)**

86. Compare styling approaches for React: CSS modules, BEM, styled-components/emotion, inline styles, and utility frameworks (Tailwind). Discuss tradeoffs for runtime and SSR.
87. Explain critical CSS and styling for SSR: how to collect and inline styles, avoid FOUC, and manage hydration of CSS-in-JS libraries.
88. Describe theming strategies in React: design tokens, CSS variables, provider-based theme contexts, and runtime theme switching performance.
89. Discuss scoping, style encapsulation, and selector specificity issues when building shared component libraries consumed by external apps.
90. Explain performance implications of dynamic styles (render-time style generation), caching strategies, and avoiding frequent re-insertion of style tags.

---

### **Build, tooling & deployment (91–93)**

91. Explain strategies to split bundles effectively in React apps: route-based splitting, vendor splitting, and low-level dynamic import boundaries.
92. Describe source maps, error stack mapping, and how to integrate Sentry or other error reporting to produce meaningful stack traces from production builds.
93. Discuss CI/CD strategies for React apps: preview environments, atomic deploys, cache strategies, and rollback tactics for client-side apps.

---

### **Concurrent features, Suspense & server components (94–97)**

94. Explain React Concurrent features conceptually: why cooperative scheduling matters, and how it changes UI responsiveness and rendering model.
95. Describe Suspense for data fetching: how it coordinates fallback UI, streaming, and how to structure boundaries to avoid waterfall loading.
96. Discuss React Server Components: separation of client/server rendering, data fetching on server, binary size reductions, and limitations/interop with client state.
97. Explain migration strategies for introducing Concurrent Mode features incrementally and compatibility considerations with third-party libraries.

---

### **Data fetching, caching & remote data (98–100)**

98. Compare data fetching approaches: imperative fetch in effects, render-as-you-fetch patterns, and query libraries (React Query/SWR). Discuss caching, staleness and revalidation semantics.
99. Explain how to design an idempotent data layer: caching strategies, cache invalidation, optimistic updates, and deduplication of requests.
100. Describe integration patterns between global state stores and remote data caches, server state synchronization, and strategies for offline-first UX.
