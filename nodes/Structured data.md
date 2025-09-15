---
aliases:
context:
- "[[Data Structures]]"
---

# Structured data

Structured data is used by search-engines, like Google, to understand the content of the page, as well as to gather information about the web and the world in general.

---

### Depending on context
- **General programming sense**: how you organize and represent data (objects, arrays, maps, sets, JSON, etx.)
- **Web / SEO sense**: schema.org structured data (JSON-LD) used to help search engines understand your content
- **API / storage sense**: serialization, parsing, or transferring structured data across systems (JSON, structured clone algorithm, IndexedDB)


### Core data Structures
- objects - key-value pairs, flexible but unordered
- arrays - ordered lists, good for sequences
- maps - key-value pairs with any type of key, maintain insertion order
- sets - collections of unique values
- typed arrays - efficient fixed-length binary data, useful for performance or working with files/buffers


### JSON (JavaScript Object Notation)
- standard format for exchangin structured data
- `JSON.stringify()` -> convert JS object -> JSON string
- `JSON.parse()` -> convert JSON string -> JS object
- used in APIs, localStorage, config files


### Structured Clone Algorithm
- built into modern JS to deep-copy complex objects (with `structuredClone()`)
- works better than `JSON.stringify(obj)` since it supports Dates, Maps, Sets, and circular references


### Web APIs & Structured Data
- localStorage / sessionStorage - store structured data (must serialize with JSON)
- IndexedDB - can store more complex structured objects directly
- postMessage / Web Workers - use structured cloning to transfer data between threads


### Structured Data for SEO (JSON-LD)
- search engines like Google use JSON-LD scripts inside HTML to understand content

Example:
```html
    <script type="application/ld+json">
    {
      "@context": "https://schema.org",
      "@type": "Article",
      "headline": "What You Need to Know About Structured Data in JS",
      "author": { "@type": "Person", "name": "You" }
    }
    </script>
```
- this doesn't affect the page for users, but improves discoverability

