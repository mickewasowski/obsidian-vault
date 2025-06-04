---
aliases:
context:
- "[[CSS]]"
---

# will-change

Hints to browsers how an element is expected to change.

---
When this property is set browsers may set up optimizations before an element is actually changed.

>[!warning] will-change is intended to be used as a last resort to try to deal with existing performance issues.

### Values
- will-change: auto; (default behavior)
- will-change: scroll-position; (indicates the author expects to animate or change the scroll position of the element)
- will-change: contents; (indicates the author expects to animate or change something about the element's contents)
- will-change: transform; / Example of <custom-ident> */
- will-change: opacity; /* Example of <custom-ident> */
- will-change: left, top; /* Example of two <animatable-feature> */
