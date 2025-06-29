---
aliases:
context:
- "[[Design patterns]]"
- "[[JavaScript]]"
- "[[Behavioral design patterns]]"
---

# Resize Observer

---
ResizeObserver is like document.onresize for elements.

### Why was it implemented

Before ResizeObserver was implemented you had to attach document.onresize and then figure out which elements have been affected. Then you would perform a specific routine based on how you want to react. If you needed new dimensions of an element after a resize, you had to call `getBoundingClientRect()` or `getComputedStyle()`.
However this didn't catch the cases where elements have changed their size without the main window resizing. For example, appending new children, setting display none, etc.

This is why ResizeObserver is useful. It reacts to changes in size of any of the observed elements, independent of what caused the change. It provides access to the new size of the observed elements too.


### Syntax

``` js
const ro = new ResizeObserver((entries) => {
    for (let entry of entries) {
        const cr = entry.contentRect;

        console.log('Element: ', entry.target);
        console.log('Element size: ', cr.width, cr.height);
        console.log('Element padding: ', cr.top, cr.left);
    }
});

// observe one or multiple elements - for multiple simply call the function X times
ro.observe(someElement);
```

### What is being reported
Generally the ResizeObserverEntry reports the content box of an element through a property called `contentRect` which returns a DOMRectReadOnly object.
The content box is the border box minus the padding.


