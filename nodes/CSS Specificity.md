---
aliases:
context:
- "[[CSS Architecture]]"
---

# CSS Specificity

---

Apart from [[Floats]] CSS Specificity is one of the most difficult concepts to grasp.

If two rules are applied to the same element, the one with higher specificity wins.

When two selectors have **equal** specificity value, the later one is the one that counts.

When selectors have **unequal** specificity, the one with a more specific rule wins.

The last rule defined overrides any previous, conflicting rules.

The embedded (style tag directly in the HTML file) style sheet has a greater specificity than other rules.

#### Specificity hierarchy:

1. inline styles
2. IDs
3. classes, attributes and pseudo-classes
4. elements and pseudo-elements - element type selector and instance of :before and :after

##### How to measure specificity: 

1. start at 0 (universal selector * is also 0)
2. add 1000 for each style attribute (inline styles)
3. add 100 for each ID
4. add 10 for each attribute, class or pseudo-class
5. add 1 for each element name or pseudo-element

Example:
```
body #content .data img:hover
1    100       10    1   10
```
The above example evaluates to 122

Another way would be:
1. count the number of ID selectors (= a)
2. count the number of classes, attributes and pseudo-classes (= b)
3. count the number of element name selectors and pseudo-elements (= c)

Concatenating the numbers a-b-c gives you the specificity.