---
aliases:
context:
---

# CSS sample

---
### **Core CSS fundamentals & box model (1–8)**

1. Explain the CSS box model in detail, including content, padding, border, margin, and how `box-sizing: border-box` changes layout calculations and common pitfalls when mixing box-sizing models.
2. Describe how percentage-based widths/heights are computed in CSS (containing block rules) and give examples of surprising behaviors (e.g., percentage height with auto parent height).
3. Explain margin collapsing: which margins collapse, when they don’t, and practical strategies to avoid accidental layout changes caused by collapsing margins.
4. Discuss the CSS cascade and origin layers (author, user, user-agent, !important). How do cascade layers and specificity interact in complex stylesheets?
5. Describe how CSS units (`px`, `em`, `rem`, `vw`, `vh`, `vmin/vmax`, `%`) differ semantically and practically; when to use each and accessibility implications (e.g., `rem` for root-scalable sizing).
6. Explain the difference between layout, painting, compositing, and how properties like `transform`/`opacity` promote layers and affect GPU usage.
7. Describe how to use containment (`contain` property) to limit layout/paint/size calculations for performance and give real-world examples.
8. Explain intrinsic and extrinsic sizing (`min-content`, `max-content`, `fit-content`) and how they’re used to build flexible components.

---

### **Selectors, specificity & inheritance (9–16)**

9. Explain selector specificity calculation precisely and demonstrate edge cases where long selector chains still lose to inline styles or `!important`.
10. Compare attribute selectors, pseudo-classes, pseudo-elements, descendant/child/sibling combinators — give performance and maintainability tradeoffs for each.
11. How does inheritance work in CSS? Which properties inherit by default and how can inheritance be leveraged for theming or reset styles?
12. Explain `:not()`, `:is()`, `:where()` differences, particularly how specificity is computed for `:is()` and `:where()`, and examples where using them simplifies selectors.
13. Discuss the impact of using overly-specific selectors vs class-based selectors on maintainability and overriding styles in large apps.
14. How do CSS variables (custom properties) interact with cascade and inheritance? Explain scoping, fallback values, and runtime updates with examples.
15. Describe how to build reliable component-level scoping using class names, descendant selectors, and attribute selectors without relying on ID selectors.
16. Explain performance considerations for complex selectors and how browsers optimize selector matching.

---

### **Layout: Floats, positioning, Flexbox (17–24)**

17. Describe the historical role of floats for layout and the main reasons they were replaced by Flexbox/Grid for major layout tasks.
18. Explain `position: static/relative/absolute/fixed/sticky`, containing blocks for absolutely positioned elements, and how stacking context is created.
19. Discuss the stacking context rules in depth and how `z-index` interacts with transforms, opacity, position, and isolation.
20. Explain how Flexbox computes main and cross axes, `flex-basis`/`grow`/`shrink`, flex shorthand corner cases, and how to build predictable flexible components.
21. Provide strategies to vertically and horizontally center content with Flexbox and explain why certain approaches fail when content size changes.
22. How do `min-width`/`min-height` interact with flex items and `flex-basis`? Explain common bugs with shrinking/flex overflow and how to fix them.
23. Discuss accessibility and focus order implications when reordering DOM visually with Flexbox (`order` property) versus reordering DOM elements.
24. Explain Flexbox performance characteristics and rendering considerations for large lists or nested flex layouts.

---

### **Layout: CSS Grid (25–31)**

25. Explain Grid’s fundamental concepts (grid container, grid lines, tracks, areas) and when Grid is preferable over Flexbox.
26. Describe explicit vs implicit grid tracks and how the auto-placement algorithm works; give examples of controlling placement with `grid-auto-flow`.
27. Explain fractional units (`fr`), `minmax()`, `repeat()`, and `fit-content()`; when to use each and pitfalls in complex responsive grids.
28. Discuss alignment in Grid (`justify-items`, `align-items`, `justify-content`, `align-content`) and how they interact with item alignment properties.
29. Show strategies for creating responsive grid layouts (`auto-fill`, `auto-fit`, `minmax()` with media queries) and discuss pros/cons of each.
30. Explain `subgrid` (and current browser support) and use-cases where `subgrid` solves layout problems that workaround solutions complicate.
31. Describe techniques for grid-based overlap/sticky headers and how grid interacts with stacking contexts.

---

### **Responsive design & media queries (32–38)**

32. Explain mobile-first vs desktop-first CSS strategies and the reasoning for preferring one over the other in long-lived codebases.
33. Describe CSS media features beyond width/height (`prefers-reduced-motion`, `prefers-color-scheme`, `resolution`, `pointer`, `hover`) and how to design adaptively.
34. Discuss container queries: how they differ from media queries, when to use them, and current substitutable patterns in environments that don’t support them.
35. Explain responsive images in CSS (`object-fit`, `srcset`/`sizes` for `<img>`) and tradeoffs with CSS background images.
36. Describe strategies for building fluid typography (`clamp()`, `calc()`, fluid type with `vw`) and pitfalls with accessibility and zoom.
37. Explain progressive enhancement vs feature detection in CSS and how to build resilient styles that degrade gracefully.
38. Discuss layout breakpoints strategy (content-driven breakpoints) vs device-driven breakpoints and how to implement and document them.

---

### **CSS architecture & scalability (BEM, ITCSS, SMACSS) (39–45)**

39. Compare BEM, SMACSS, and ITCSS: principles, folder structure, naming conventions, and tradeoffs for teams of different sizes.
40. Explain how to structure CSS modules (by feature vs by type) and when to prefer component-scoped styles over global styles.
41. Discuss strategies for managing specificity across large codebases (stylelint rules, conventions, utility classes) and preventing specificity wars.
42. Describe utility-first approaches (Tailwind-like) vs traditional component CSS — tradeoffs for DX, runtime size, and theming.
43. How do you version and release a shared component library’s CSS while maintaining backward compatibility and minimizing breaking changes?
44. Explain semantic class naming and the role of design tokens in decoupling styles from visual language across platforms.
45. Describe techniques for migrating a legacy CSS codebase to a modular architecture with minimal regressions.

---

### **Sass fundamentals: variables, nesting, mixins, functions (46–55)**

46. Explain the benefits and risks of nesting in Sass; how deep should nesting go and how to avoid specificity bloat?
47. Describe Sass variables vs CSS custom properties: compile-time vs runtime, use-cases for each, and interoperability patterns.
48. Show how to write robust mixins and when to prefer mixins vs placeholder selectors (`%extend`) vs utility classes.
49. Explain Sass functions: building reusable logic, performance considerations, and differences between built-in functions and user-defined ones.
50. Discuss partials and the `@use`/`@forward` module system in Sass; explain why `@import` was deprecated and how to structure modules.
51. How does Sass handle arithmetic and units? Explain unit coercion, unitless numbers, and pitfalls when mixing units in calculations.
52. Describe how to implement responsive helpers in Sass (mixins for breakpoints) vs generating utility classes—tradeoffs and maintenance.
53. Explain how to use maps in Sass effectively (nested maps for token systems) and patterns for safe map retrieval.
54. Show how to create a theming system with Sass that still allows runtime overrides via CSS variables.
55. Discuss testing and linting Sass (`stylelint`, `sass-lint`), and techniques to keep a Sass codebase maintainable.

---

### **Advanced Sass features: maps, control directives, modularization (56–61)**

56. Explain `@each`, `@for`, `@while` directives and practical use-cases for generating classes or responsive utilities in a controlled way.
57. Describe advanced map operations (`map-merge`, `map-get`, `map-deep-get` patterns) and how to avoid fragile map access patterns.
58. Discuss how to implement mixin/function fallbacks and feature toggles in Sass when some features aren’t supported by the runtime.
59. Explain using `@content` with mixins to build higher-order style utilities and examples of where this pattern simplifies component styles.
60. Describe strategies for splitting Sass into packages/modules for reuse across projects, including dependency management and token sharing.
61. Explain source maps for Sass, debugging compiled CSS, and pitfalls when stack traces don’t match original Sass files.

---

### **Theming & design tokens (62–67)**

62. Explain design tokens: what they are, how to model them (colors, spacing, type), and storage formats (JSON, Sass maps, CSS custom properties).
63. Compare compile-time theming (Sass variables) vs runtime theming (CSS variables) and hybrid approaches for efficient theming.
64. Describe implementing dark mode: `prefers-color-scheme`, class-based toggles, and considerations for transitions and image assets.
65. Explain token scale strategies (modular scale, spacing scales) and how to implement consistent responsive token adjustments.
66. Discuss cross-platform token distribution (web, native) and workflows to keep tokens synchronized across design and engineering.
67. Describe methods to safely expose theme overrides to third-party integrators while preserving encapsulation.

---

### **Performance & optimization (68–74)**

68. Explain critical CSS: how to extract critical-path CSS, inline it, and defer non-critical styles. Discuss automation and edge cases.
69. Discuss CSS file size reduction strategies: purging unused CSS, critical splitting, avoiding large frameworks, and build-time tools.
70. Explain the cost of large selector lists and complex selectors on rendering performance and how to measure impact.
71. Describe font loading strategies (`font-display`, preloading, subset, variable fonts) and tradeoffs for FOUT/FOIT and CLS.
72. Discuss CSS-related network optimizations (`preconnect`, `dns-prefetch`, `preload`) and when to use each for fonts and critical assets.
73. Explain repaint/reflow triggers in the browser and coding practices to minimize layout thrashing (batch DOM reads/writes).
74. Describe measuring and diagnosing CSS performance issues using Lighthouse, Performance panel, and paint profiling.

---

### **Animations, transitions & motion design (75–82)**

75. Explain the differences between transition, animation (keyframes), and Web Animations API; when to use each and how to control playback.
76. Discuss performance considerations for animations (`transform`/`opacity` on composite layer vs layout/paint properties) and how to ensure 60fps.
77. Describe how to choreograph complex motion (staggered animations, sequenced timelines) while preserving accessibility and reduced-motion preferences.
78. Explain animation fill modes, easing functions, `cubic-bezier` curves, and how timing affects perceived performance and usability.
79. Discuss interruptible animations and how to safely synchronize JS-driven state changes with CSS animations.
80. Show how to use `will-change` properly and explain its memory/painting implications when overused.
81. Describe techniques for animating height/content size without layout thrashing (CSS transitions with `max-height`, Web Animations, FLIP technique).
82. Explain creating performant parallax or scroll-driven animations (`IntersectionObserver`, `requestAnimationFrame`, scroll-linked-animations when available).

---

### **Accessibility, forms, focus & interactions (83–88)**

83. Explain visual focus indicators: best practices for styling `:focus`, `:focus-visible`, and preserving accessibility while matching design.
84. Discuss accessible form styling: label association, error state visuals, `aria-live` for validation, and maintaining usable focus order.
85. Describe how color contrast is calculated, tools for checking contrast, and strategies for providing accessible color alternatives.
86. Explain click targets, touch size best practices, and responsive interaction affordances for mobile-first interfaces.
87. Discuss how CSS can support users with reduced motion, low-vision, or different input modalities (`prefers-reduced-motion`, `prefers-contrast`, `pointer`).
88. Describe pitfalls when hiding content visually (`display: none` vs `visibility: hidden` vs offscreen positioning) and implications for screen readers and SEO.

---

### **Typography & web fonts (89–93)**

89. Explain font loading lifecycle, `font-display` strategies, and how to choose fallback stacks to minimize layout shifts.
90. Discuss variable fonts: benefits, performance, responsive typography techniques using axes, and fallback strategies.
91. Describe best practices for line-height, measure (line length), letter-spacing, and rhythm to achieve readable, accessible typography.
92. Explain subpixel rendering and font rendering differences across platforms; how to mitigate layout differences using font metrics and fallback fonts.
93. Discuss techniques for optimizing iconography: icon fonts vs inline SVG vs SVG sprite vs icon components (accessibility, scaling, color).

---

### **Graphics: images, SVG, responsiveness (94–97)**

94. Explain responsive image strategies: `srcset`, `sizes`, `<picture>` element; how to choose breakpoints and image densities for performance.
95. Discuss SVG pros/cons for UI (inline SVG vs external SVG), styling with CSS, accessibility (`title`/`desc`, `role`), and interaction.
96. Describe image formats (JPEG/PNG/WebP/AVIF) characteristics and when to use each for quality vs performance tradeoffs.
97. Explain techniques for progressive image loading, lazy-loading best practices, placeholders (LQIP, blur-up), and handling art direction.

---

### **Browser internals, rendering, painting & debugging (98–100)**

98. Explain the browser rendering pipeline: style calculation, layout, paint, composite — and how CSS changes flow through this pipeline.
99. Describe how to use DevTools to debug layout issues: box model inspector, computed styles, paint flashing, layer borders, and performance recordings.
100. Discuss cross-browser compatibility debugging strategies for CSS, feature detection vs vendor prefixes, and using PostCSS/autoprefixer and caniuse data.
