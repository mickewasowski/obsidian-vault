---
aliases:
context:
- "[[Web Development]]"
---

#wip

# HTML

HyperText Markup Language used for structuring a webpage.

---

## Overview
HTML (HyperText Markup Language) is the standard markup language used to structure content on the web, defining elements like headings, paragraphs, links, images, and forms. It uses tags—enclosed in angle brackets—to semantically describe the role and hierarchy of each piece of content, enabling browsers to render pages correctly. Combined with CSS for styling and JavaScript for interactivity, HTML provides the foundational skeleton of every website.

### Beyond the basics of tags and document structure, every front-end developer should master:

Semantic HTML
Using elements like `<article>, <section>, <header>, <nav>, <main>, <figure> and <figcaption>` makes your markup meaningful—improving accessibility, SEO and maintainability.

Accessibility (a11y)
Proper use of native HTML controls, labels (`<label>`), landmarks, heading levels and ARIA roles ensures your sites work for screen readers and keyboard users alike.

Forms & Validation
Understanding built-in attributes (required, pattern, min/max) and the Constraint Validation API lets you build robust, user-friendly forms without excessive JavaScript.

Responsive Images & Media
Leveraging `<picture>`, srcset/sizes and the `<video>` element allows you to serve appropriately sized and formatted assets, boosting performance across devices.

Metadata & SEO Fundamentals
Proper `<meta>` tags (viewport, charset, description), `<title>`, structured data (JSON-LD) and link relationships (rel="canonical", rel="preload") form the backbone of search-engine friendliness and performance hints.

HTML5 APIs & Progressive Enhancement
Familiarity with features like the Canvas API, Web Storage (localStorage/sessionStorage), Geolocation, Drag & Drop and the History API enables richer experiences, with fallbacks for unsupported browsers.

Document Outline & Head Management
Keeping a clear, logical heading hierarchy and managing external resources (stylesheets, scripts) in the `<head>` optimizes both rendering performance and the user’s navigation through your content.

Performance Considerations
Knowing how HTML parsing, critical rendering paths and resource hints (`<link rel="preconnect">`, async/defer on scripts) affect load times helps you build faster, smoother pages.