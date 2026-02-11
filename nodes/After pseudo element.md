---
aliases:
context:
- "[[CSS]]"
---

# After pseudo element

---
### Auto width and position properties

This combined with *mask* and left and right position properties achieves a border animation simulating spreading of the border from the center to the edges of the container.

1. Setup
- Parent element: `position: relative`
- Child (or `::after` pseudo-element): `position: absolute`
- No explicit `width` defined (`width: auto`)

2. Core Rule - for absolutely positioned elements, horizontal layout follows this constraint:
```
left + width + right = containing block width
```

**If `width` is `auto` and both `left` and `right` are defined, the browser solves for `width`.**

Result:
```
width = containing_block_width - left - right - margins
```

> [!tip] The element stretches or shrinks to satisfy both constraints.

3. Behavior Matrix

> `left` only
```css
    position: absolute;
    left: 10px;
```
* Positioned relative to left edge.
* Width is shrink-to-fit (depends on content).

> `right` only
```css
    position: absolute;
    right: 10px;
```
* Positioned relative to right edge.
* Width is shrink-to-fit.


> `left` + `right` with `width: auto`
```css
    position: absolute;
    left: 10px;
    right: 10px;
```
* Element stretches horizontally.
* Width is computed.
* Changing `left` or `right` changes width.

> `left` + explicit `width`
```css
    position: absolute;
    left: 10px;
    width: 100px;
```
* Width is fixed.
* `left` controls horizontal position.
* `right` (if also set) creates an over-constrained system and the browser resolves it according to spec rules.

4. Key Concept - `left` and `right` are not purely positional offsets.
They are layout constraints.
When both are defined and width is `auto`, width becomes a derived value.

For an absolutely positioned `::after`:
* If you want it to stretch across the parent → define both `left` and `right`.
* If you want fixed size → define `width`.
* If you want content-based size → define only one horizontal offset.

