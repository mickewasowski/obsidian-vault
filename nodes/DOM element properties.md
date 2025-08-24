---
aliases:
context:
- "[[HTML]]"
---

#wip

# DOM element properties

Some of the properties an element has.

---
### Size-related

`offsetHeight`
- the visible height of the element in pixels including - content height, padding, border, horizontal scrollbar height (if present), excludes margins

`clientHeight`
- the inner height of  the element in pixels including - content height, padding (*excludes* borders, scrollbars, and margins)

`scrollHeight`
- the total height of the content, including the parts not visible due to overflow/scrolling
- always >= `clientHeight`
- useful for knowing how much scrolling is possible


### Position-related
`offsetTop`
- the distance (in pixels) between the **top of the element** and the **top of its offset parent** (the nearest positioned ancestor)
- useful for positioning or checking where an element is in its container


### Scrolling-related
`scrollTop`
- the number of pixels that the element's content has been scrolled vertically
- `0` means it's scrolled to the top
- increases as you scroll *down*