---
aliases:
context:
- "[[JavaScript]]"
- "[[CSS]]"
- "[[SASS]]"
- "[[React]]"
- "[[TypeScript]]"
---

# Sample questions

---
### JavaScript

> Core JavaScript (must) Why: Every frontend problem ultimately comes down to JS.

What to test:
- Understanding of scoping, closures, this, prototypal inheritance.
- ES6+ features: let/const, arrow functions, modules, async/await, promises, destructuring.
- Event loop, microtasks vs macrotasks.
- Immutability and pure functions. Sample questions/exercises:
- Explain event loop; why does setTimeout(fn,0) run after a Promise resolution?
- Write a function to deep-clone an object (discuss limitations).
- Implement debounce and throttle and explain use-cases.
- Small coding problem (30 min): transform/aggregate array of objects with reduce.


### React

> Framework competency (React as example) Why: Mid-level should build and reason about real apps in a framework.

What to test:
- Component design, props vs state, lifting state, composition.
- Lifecycle (or hooks), effects, dependency arrays, cleanup.
- State management options (Context, Redux, Zustand, query libs) and tradeoffs.
- Performance: memoization, keys, virtualization.
- Routing, code-splitting, server-side rendering vs CSR basics. Sample questions/exercises:
- Explain useEffect dependency array pitfalls and how to fix them.
- Given a slow list component, how would you profile and speed it up?
- Small live-coding: build a searchable list with debounced input; ensure no unnecessary re-renders.
- Ask about testing components (unit vs integration) and mocking fetch.


### HTML & CSS

> HTML & CSS (must) Why: Layout, semantics, and responsive UI are fundamental.

What to test:
- Semantic HTML and accessibility basics (aria roles, landmark elements).
- Flexbox, CSS Grid, responsive breakpoints, mobile-first approach.
- CSS methodologies and scoping (BEM, CSS Modules, styled-components).
- Cross-browser quirks and debugging layout issues. Sample tasks:
- Given a design, implement a responsive two-column layout that collapses to one column.
- Explain tabindex and accessible forms; fix an accessibility bug in markup.
- Diagnose why an element is overflowing its container (use devtools reasoning).


### Testing

> Testing (important) Why: Mid-level should write reliable, testable code.

What to test:
- Unit testing (Jest), component testing (React Testing Library), basic E2E (Cypress/Playwright).
- When to mock and when to integration-test. Sample questions:
- Write tests for a component that fetches and displays data; how do you simulate errors?
- Explain the tradeoffs of mocking network requests in unit tests.


### Performance & Web fundamentals

> Performance & Web Fundamentals (important) Why: Real apps must be fast and resilient.

What to test:
- Web vitals (LCP, CLS, FID), lazy loading, image optimization, caching strategies.
- Critical rendering path, bundling, tree shaking.
- Measuring & profiling: Lighthouse, devtools, flame charts. Sample questions/tasks:
- Given a slow page, outline steps to investigate and fix long LCP.
- Explain how to optimize bundle size and when to split code.


### Tooling, Build & Deploy

> Tooling, Build & Deploy (nice-to-have) Why: Mid-level should navigate the dev toolchain.

What to test:
- Bundlers (webpack, Vite), transpilation (Babel/TS), linters, formatters.
- CI basics: tests on PR, linting, build pipelines, environment variables.
- Familiarity with TypeScript (typing components, generics) or willingness to adopt it. Sample questions:
- How would you set up a build to produce modern and legacy bundles?
- Describe a typical CI flow for a frontend repo.


### A11y, Security & i18n

> Accessibility, Security & Internationalization (i18n) Why: Important for broad user coverage and safe apps.

What to test:
- Keyboard navigation, screenreader considerations, color contrast.
- XSS vectors on frontend and how to prevent injection with templates and sanitization.
- Basic i18n strategies and pluralization pitfalls. Sample exercises:
- Fix accessibility issues in a small page (missing labels, keyboard traps).
- Explain how to safely render user input in the DOM.


### Debugging, Observability & Error handling

> Debugging, Observability & Error Handling Why: Ability to triage issues quickly in production and dev.

What to test:
- Use of devtools, breakpoints, the network panel.
- Logging, Sentry or other error reporting basics, graceful degradation. Sample questions:
- Walk through how you'd debug a race condition causing stale UI.
- How would you add observability to a feature rollout to monitor regressions?


### Architecture & Component design


> Architecture & Component Design (system thinking) Why: Mid-level should design maintainable components and small systems.

What to test:
- Separation of concerns, single responsibility, presentational vs container components.
- API design of components, prop contracts, default props, controlled vs uncontrolled components.
- State co-location vs global state. Sample questions:
- Design a reusable DatePicker component API; what props/events would you include?
- When would you extract shared logic into a custom hook or utility module?



### Things to consider

Evaluation rubric — what to look for in answers
- Correctness: factual accuracy on core topics (JS internals, async).
- Depth: can they explain "why", not just "how"?
- Practicality: do they consider tradeoffs and constraints (time, scope, accessibility)?
- Ownership: evidence of having shipped features and taken responsibility.
- Communication: clear explanations, structured thought, asks clarifying questions.
- Growth potential: curiosity, willingness to learn new tools.

Red flags
- Can't reason about async/event loop or closures.
- No understanding of component lifecycle or causes of re-renders.
- Poor grasp of HTML semantics/accessibility.
- Over-reliance on copying solutions vs explaining choices.
- Defensive about feedback or inability to estimate/scope tasks.

Concrete interview exercises (examples)
- Live-coding (30–40 min): Build a small app — searchable todo list with add/remove, optimistic UI for delete, and tests. Evaluate code structure, state handling, and edge cases.
- Debugging exercise (15–20 min): Give them a broken app with console logs and a failing network request; ask to find root cause and propose fixes.
- Take-home (2–4 hours): Implement a small UI with given API, responsive layout, caching, and basic tests. Provide acceptance criteria and allow pair review.

Wrapping tips
- Ask clarifying questions early — candidates who clarify requirements show product sense.
- Use a mix of hands-on tasks and whiteboard/system questions to evaluate both coding skill and architecture.
- Make the interview a conversation — mid-level candidates shine when explaining tradeoffs and past decisions.


### questions

[[Javascript sample]]
[[CSS sample]]
[[React sample]]
[[Typescript sample]]
[[HTML sample]]

