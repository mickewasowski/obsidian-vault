---
aliases:
context:
- "[[Accessibility]]"
---

# Focus and Controlling focus

---
Focus order is important for tab navigation. It is important to order our HTML and specifically the focusable elements in the way they are seen in the browser.
The order of the elements needs to be sensible, otherwise you might get unwanted behavior such as jumping up and down the page instead of gradually moving down or up the page.

### tabindex attribute
```
tabindex='0' // => manually makes the element focusable (i.e. a div)
tabindex='-1' // => manually 'hides' the element (under the hood this is what the inert library does)
tabindex='5' // => greater than 0 sets the hirarchy of the focus order, the way it works is it starts from the lowest number higher than 0 and works it's way up
```

### roving tabindex
This a technique where you toggle between tabindex 0 and -1. This provides a more continuous experience for the user.
Example use is in a select menu which is followed by a button. If the person moves forward to the button but then decides to return to the menu the focused element would be the one he had previously selected.

Roving tabindex is a keyboard accessibility pattern used to manage focus within a group of interactive elements (like buttons, tabs, list items, etc.), allowing only one item to be focusable (tabindex="0") at a time, while the rest are not focusable (tabindex="-1"). This technique improves keyboard navigation by reducing the number of Tab key presses needed to move through UI components.

Why use roving tabindex?
Without it, each item in a group would be tabbable, meaning users would have to press Tab multiple times to move between them. With roving tabindex, the user:
Tabs once to enter the component group (like a menu or grid),
Then uses arrow keys (← → ↑ ↓) to move focus within the group.

How it works:
Only one element has tabindex="0" (focusable via Tab).
All other elements in the group have tabindex="-1" (not tabbable, but can receive focus programmatically).
Arrow keys move focus between items, updating tabindex accordingly.