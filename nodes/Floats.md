---
aliases:
context:
- "[[CSS Architecture]]"
---

# Floats

---

Float is essentially the ability of a text to "float" around an image.
**When you float a box it becomes a block box and can be shifted all the way left or right on the current line or the containing box.** 
A floated box is positioned within the normal flow, then taken out of the flow and shifted to left or right. Content may flow along the side of a float box. When a box is taken out of the flow other boxes will ignore it completely and not make space for it.
You should always set a width to a float element, except for an image with an implicit width. If no width is set the results can be unpredictable. Otherwise it will fill the entire line as if it were a regular block element and leave no room for anything else around it.
Unlike other boxes, float boxes' vertical margins are not collapsed with the margins of other elements above or below them.
Finally, float boxes can overlap other block boxes adjacent to it in the normal flow.
When you float two or more elements in the same direction they will stack upon each other until there is no more space, then they will be shifted downwards until they fit.

Full article: (https://www.smashingmagazine.com/2007/05/css-float-theory-things-you-should-know/)