---
aliases:
context:
---

# HTML sample

---
### **Core HTML semantics & fundamentals (1–10)**

1. Explain the purpose of semantic HTML and why using semantic elements matters for accessibility, SEO, and maintainability.
2. Describe the differences between `<section>`, `<article>`, `<main>`, `<aside>`, and `<div>` — when to use each and how they affect document outline and assistive tech.
3. Explain the role of the `<header>` and `<footer>` elements at document and section levels and common misuse patterns.
4. What is the HTML content model (flow content, phrasing content, metadata, sectioning) and how does it constrain valid element placement?
5. Discuss the distinction between inline-level and block-level elements; how do replaced elements (`img`, `video`) behave differently?
6. Describe void elements versus normal elements and important serialization rules when generating HTML programmatically.
7. Explain the purpose of the `<meta>` element and common meta tags (`charset`, `viewport`, `theme-color`, `robots`) and their practical impact.
8. How does the browser parse HTML into a DOM? Explain tokenization, parse errors, and error-correction heuristics the parser uses.
9. Describe the difference between HTML and XHTML/XML serializations and the implications for served MIME types and parsing behavior.
10. Explain `role` attributes and when to prefer semantic elements over role-based fixes for accessibility.

---

### **Document structure, head, and metadata (11–20)**

11. Explain the order and purpose of elements in the `<head>`: charset, title, meta viewport, links, styles, and scripts; which entries are critical for performance?
12. Discuss document character encoding: why declaring charset early matters and how encoding mismatches cause mojibake.
13. Explain the purpose of the HTTP `Content-Type` header vs `<meta charset>` and how they interact in real-world deployments.
14. Describe managing favicons and touch icons across devices and the difference between `link rel=icon`, `rel=apple-touch-icon`, and manifest icons.
15. How do `link rel=preload`, `prefetch`, and `dns-prefetch` differ? Explain use-cases and pitfalls for how they influence resource loading.
16. Explain the roles of `link rel=canonical`, `meta name=robots`, and structured data meta tags for SEO and crawler behavior.
17. Describe how to declare and use alternate language/canonical pages with `link rel=alternate hreflang=...`.
18. Explain how CSP nonces/hashes for inline scripts/styles are exposed via HTML and the tradeoffs between strict CSP and dynamic script insertion.
19. Discuss best practices for including third-party scripts in the head (blocking vs async/defer) and how to measure their impact.
20. Explain document-level metadata for social sharing (Open Graph, Twitter cards) and how they are discovered by crawlers.

---

### **Forms, inputs & accessibility of controls (21–30)**

21. Explain the semantics of `<form>`, `action`, `method`, and encoding types (`application/x-www-form-urlencoded`, `multipart/form-data`, `text/plain`).
22. Describe the input types in HTML5 (`email`, `tel`, `number`, `date`, `range`, `search`, `color`) and how they affect native UI, validation, and mobile keyboards.
23. How does constraint validation work in the browser (`required`, `pattern`, `min/max`, `step`, `setCustomValidity`) and how should you combine it with server validation?
24. Explain the role of `<label>` for form controls, the `for` attribute vs wrapping, and consequences for screen readers and hit targets.
25. Discuss ARIA roles and attributes for complex widgets (`aria-haspopup`, `aria-expanded`, `aria-controls`) and when to prefer native controls.
26. Describe accessible error reporting strategies for forms: `aria-live`, `role=alert`, focus management, and announcing validation messages.
27. Explain how to build custom form controls (combobox, datepicker) with accessible keyboard interactions and the necessary ARIA patterns.
28. Discuss progressive enhancement for forms: using native controls where possible, JS augmentations, and handling JS-disabled fallbacks.
29. Explain input performance considerations: debounced `onchange` vs `oninput` for large forms and race conditions with async validation.
30. Describe file input handling: `accept` attribute, multiple files, drag-and-drop considerations, and security constraints in browsers.

---

### **Media, images, and responsive assets (31–40)**

31. Explain the `<picture>`, `<source>`, `srcset`, and `sizes` attributes for responsive images — how the browser selects an image and what constraints govern selection.
32. Describe the difference between `<img>` and CSS `background-image` in semantics and when each is appropriate.
33. Discuss modern image formats (WebP, AVIF) and fallback strategies in `<picture>` and server negotiation.
34. Explain lazy-loading native attribute `loading="lazy"` versus JS-based lazy-loading and when each is appropriate.
35. Describe the `<video>` and `<audio>` elements: source fallbacks, codecs, `poster`, `preload`, `crossorigin`, and accessibility captions/subtitles (`<track>`).
36. Explain best practices for accessible media players: keyboard controls, focus behavior, captions, and descriptive text.
37. Discuss image decoding and paint behavior (`decode()`, `crossOrigin`, CORS) and how resource hints affect media load performance.
38. Explain `srcset` density descriptors (`1x`, `2x`) vs width descriptors (`w`) and sizing calculations with `devicePixelRatio` and CSS layout.
39. Describe art-direction techniques with `<picture>` for different aspect ratios and cropping per breakpoint.
40. Explain how to serve appropriately sized images from the server (on-the-fly resizing, responsive image generation) and caching considerations.

---

### **Accessibility (a11y) deep-dive (41–50)**

41. Explain the accessibility tree vs DOM tree: which elements are exposed to assistive tech and how role/aria attributes modify the tree.
42. Describe keyboard accessibility best practices: `tabindex` values, focus order, and handling custom widgets' keyboard interactions.
43. Explain semantic landmarks and their importance for screen reader navigation (`nav`, `main`, `search`, `banner`, `complementary`).
44. Discuss ARIA states and properties vs ARIA roles — when ARIA is necessary and when it’s harmful.
45. Explain how to test accessibility manually and with automated tools (`axe`, Lighthouse) and the limitations of each approach.
46. Describe screen reader behaviors (NVDA, VoiceOver, JAWS) for common patterns and pitfalls when testing only one screen reader.
47. Explain accessible name computation (how to derive accessible name from `label`, `aria-label`, `aria-labelledby`) and failure modes.
48. Discuss live regions (`aria-live`) and polite vs assertive updates — use-cases and problems with spamming updates.
49. Explain semantics and accessibility of headings hierarchy (`h1–h6`): document outline vs visual styling and why skipping levels is harmful.
50. Describe focus management patterns during routing and dialogs (restoring focus, returning focus to trigger) and how to handle focus traps.

---

### **Document structure for internationalization & localization (51–57)**

51. Explain the `lang` attribute, `dir` (`ltr`/`rtl`), and how proper language metadata affects screen readers and search engines.
52. Describe handling of bidirectional text, Unicode bidi overrides, and CSS directionality pitfalls for mixed-language content.
53. Explain how to set language per element and why granular language annotations are necessary for accessibility.
54. Discuss numeric, date, and currency formatting at the HTML layer vs relying on client JS Intl APIs and server-side formatting.
55. Describe how to manage translated static content like `alt` attributes, `title` attributes, and placeholders to avoid untranslated UI leakage.
56. Explain the role of `hreflang`, canonicalization, and server-side headers for multi-language SEO strategies.
57. Discuss strategies for Right-to-Left (RTL) CSS and asset handling, and how to flip images/icons and layout semantics.

---

### **Microdata, structured data & SEO (58–63)**

58. Explain the differences between microdata, JSON-LD, and RDFa for structured data and why JSON-LD is recommended by search engines.
59. Describe common `schema.org` types for articles, products, breadcrumbs, and FAQs, and how structured data impacts SERP features.
60. Explain how to mark up breadcrumbs, `BreadcrumbList` schema, and why both visible breadcrumbs and structured data are important.
61. Discuss using structured data to enable rich results (product, recipe) and pitfalls that cause manual actions or removed rich snippets.
62. Explain best practices for title and meta description: length, duplicates, dynamic rendering for SPAs, and server-side rendering implications.
63. Describe canonical tags, pagination `rel=prev/next` (legacy), and duplicate content handling strategies in multi-URL content systems.

---

### **Security & content integrity (64–70)**

64. Explain XSS vectors in HTML context: attribute injection, script injection, URL-based injection, and safe output encoding strategies.
65. Describe CSP (Content Security Policy): directives for scripts, styles, images, and how to deploy CSP in report-only mode to iterate.
66. Explain how to safely include third-party widgets and iframes, sandboxing iframe attributes, and postMessage security patterns.
67. Discuss handling untrusted user-generated HTML: sanitizer strategies, libraries (`DOMPurify`), and pitfalls of naive regex stripping.
68. Explain Subresource Integrity (SRI) for CDN-hosted scripts/styles and how hashes interact with cache-busting and build pipelines.
69. Describe pitfalls of data URLs and inline scripts/styles for CSP and performance implications.
70. Explain `referrer-policy` and `Feature-Policy` / `Permissions-Policy` headers and when to restrict browser features for security/privacy.

---

### **Progressive enhancement, feature detection & fallbacks (71–76)**

71. Explain the progressive enhancement philosophy vs graceful degradation and how to structure markup for baseline functionality.
72. Describe feature detection with Modernizr-like patterns and how to conditionally enhance the DOM based on support.
73. Discuss `<noscript>` usage: server-rendered fallbacks, SEO implications, and progressive enhancement for users with JS disabled.
74. Explain how to use `<template>` and `<slot>` elements to implement progressive enhancements that degrade cleanly.
75. Describe how to implement accessible polyfills that integrate with native semantics when available.
76. Explain service workers as enhancement: when they should not change essential HTML semantics and how to avoid offline surprises.

---

### **Web components, shadow DOM & custom elements (77–82)**

77. Explain the Custom Elements API, lifecycle callbacks (`connectedCallback`, `disconnectedCallback`), and upgrade timing.
78. Describe Shadow DOM encapsulation: styling scoping, light DOM vs shadow DOM, and impact on accessibility and CSS selectors.
79. Discuss slots and fallback content: how composition works between host and consumer and pitfalls for style encapsulation.
80. Explain how to expose accessible APIs from web components (`delegatesFocus`, `tabindex`, ARIA passthrough) so they behave like native controls.
81. Describe strategies for theming web components (CSS custom properties, `part` and `theme` attributes) and tradeoffs of each.
82. Explain server-rendering web components and hydration challenges: progressive enhancement with declarative markup vs client upgrade.

---

### **Offline, caching, and progressive web apps (83–87)**

83. Explain the HTML-level entry points for PWAs: `manifest.json` link, `meta theme-color`, and installability criteria.
84. Describe adding a web app manifest: icons, scope, `start_url`, display modes, and best practices for multi-locale apps.
85. Explain how service worker-driven navigation fallback affects HTML routing and how to avoid serving stale HTML for dynamic apps.
86. Discuss offline-first HTML strategies for content-heavy sites and how to cache HTML responsibly to avoid content drift.
87. Explain background sync and periodic sync considerations that affect HTML UX (e.g., showing pending state in markup).

---

### **Canvas, SVG & advanced graphics integration (88–92)**

88. Compare inline SVG vs `<img src="...svg">` vs background SVG: styling, interactivity, accessibility, and performance tradeoffs.
89. Explain how to make inline SVG accessible: `<title>`/`<desc>`, `role`, focusability, and `aria-hidden` patterns for decorative SVGs.
90. Describe using `<canvas>`: fallback content, width/height attributes vs CSS resizing, and high-DPI scaling considerations.
91. Discuss progressive enhancement for graphics: serving vector vs raster, performance for complex SVGs, and inlining critical small SVGs.
92. Explain how to stream or progressively render large graphics (SVG sprites, symbol usage, sprite inlining) and caching strategies.

---

### **Validation, testing & tooling (93–96)**

93. Explain the role of HTML validation (W3C validators) and what kinds of issues validators catch vs what they miss.
94. Describe automated QA for HTML: visual regression testing, accessibility CI checks, link checkers, and HTML linting rules.
95. Discuss templating and server-side generation pitfalls that lead to invalid HTML: unescaped attributes, mismatched tags, and self-closing rules.
96. Explain strategies for testing dynamic HTML in E2E tests (deterministic IDs, data-test attributes, semantic queries) and reducing flakiness.

---

### **Advanced integration & real-world considerations (97–100)**

97. Describe embedding third-party content responsibly (widgets, ads): sandboxing, performance isolation, and measurement of impact.
98. Explain SEO challenges for client-side rendered HTML and best practices: server-side rendering, pre-rendering, and dynamic rendering tradeoffs.
99. Discuss accessibility and SEO implications of heavy DOM churn (SPAs) and how to maintain semantic structure across client navigations.
100. Describe long-term maintainability best practices for HTML in large apps: componentized templates, design tokens for markup, documentation, and contract testing between design and engineering.

