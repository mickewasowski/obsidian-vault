---
aliases:
context:
  - "[[JavaScript]]"
  - "[[JS - Personal Utils]]"
---

# Scroll position

In this file is an example functionality on how to determine scroll direction on mobile and desktop.

---

### Mobile detection

```js
const startYRef = (useRef < number) | (null > null);

const handleTouchStart = (e) => {
  if (e.touches && e.touches.length > 0) {
    startYRef.current = e.touches[0].clientY;
  }
};

const handleTouchMove = (e) => {
  const el = bodyRef.current;
  if (!el) return;

  if (loadingTop || loadingBottom) return;
  if (startYRef.current === null) return;

  const THRESHOLD = 2;

  const atTop = el.scrollTop === 0;
  const atBottom =
    Math.abs(el.scrollHeight - el.clientHeight - el.scrollTop) < THRESHOLD;

  const currentY = e.touches[0].clientY;
  const deltaY = currentY - startYRef.current;

  // At top and swiping down (deltaY > 0)
  if (atTop && deltaY > 0) {
    console.log("Tried to overscroll at top (touch)");
    startYRef.current = null; // Prevent repeated triggers

    // perform custom logic
  }
  // At bottom and swiping up (deltaY < 0)
  else if (atBottom && deltaY < 0) {
    console.log("Tried to overscroll at bottom (touch)");
    startYRef.current = null; // Prevent repeated triggers

    // perform custom logic
  }
};

const handleTouchEnd = () => {
  startYRef.current = null;
};
```

> Explanation of what each line is for:

##### `startYRef`

is used to store the starting Y-coordinate of a touch event (whre the user's finger first touches the screen)

##### `handleTouchStart`

defines a function to handle the `touchestart` event, which fires when the user touches the screen

- `if (e.touches && e.touches.length > 0)`
  checks if `e.touches` exists and has at least one touch point (ensures the event contains valid touch data)
- `e.touches` is a `TouchList` containing all current touch points (e.g., multiple fingers on a touchscreen)
- `startYRef.current = e.touches[0].clientY` sets `startYRef.current` to the Y-coordinate of the first touch point (`e.touches[0]`).
- `clientY` is the vertical position of the touch relative to the viewport (in pixels). This stores the starting Y-position of the touch for later comparison in the `touchmove` event

##### `handleTouchMove`

handles the `touchmove` event, which firest as the user moves their finger across the screen.
This function detects if the user is trying to "overscroll" at the top or bottom of a scrollable element to trigger loading more content.

- `if (startYRef.corrune === null) return;` checks if `startYRef.current` is `null` (i.e. no valid `touchstart` event has been recorded).

- `const THRESHOLD = 2;` defines a constant `THRESHOLD` set to `2` (pixels). This is used to determine if the user is "at the bottom" of the scrollable element, allowing for a small margin of error in scroll position calculations.

- `const atTop = el.scrollTop === 0;` checks if the scrollable element is at the top.
  `el.scrollTop` is the number of pixels the element's content is scrolled vertically from the top.
  If `0`, the user is at the top of the content.

- `const atBottom = Math.abs(el.scrollHeight - el.clientHeight - el.scrollTop) < THRESHOLD` checks if the scrollable element is at (or very near) the bottom.
  `el.scrollHeight` total height of the element's content, including overflow.
  `el.clientHeight` visible height of the lement (excluding scrollbars).
  `el.scrollTop` current scroll position.
  `el.scrollHeight - el.clientHeight` gives the maximum scrollable distance. Subtracting `el.scrollTop` gives the remaining distance to the bottom.
  `Math.abs(...) < THRESHOLD`checks if the remaining distance vis less than 2 pixels, accounting for minor floating-point inaccuracies in scroll calculations.

- `const currentY = e.touches[0].clientY` gets the current Y-coordinate of the first touch point during the `touchmove` event.
  `e.touches[0].clientY` is the vertical position of the user's finger relative to the viewport.

- `const deltaY = currentY - startYRef.current` calculates the difference between the current Y-coordinate (`currentY`) and the starting Y-coordinate (`startYRef.current`)
  positive `deltaY` - user is moving their finger downward
  negative `deltaY` - user is moving their finger upward

- `if (atTop && deltaY > 0)`
  checks if the user is at the top of the scrollable element (`atTop` is true) and swiping downward (`deltaY > 0`)
  this indicates a "pull-to-refresh" gesture at the top

- `startYRef.current = null`
  resets it to `null` to prevent repeated triggers of the same action during this touch gesture

- `else if (atBottom && deltaY < 0)`
  checks if the user is at the bottom of the scrollable element (`atBottom` is true) and swiping upward (`deltaY < 0`)
  this indicates an "infinite scroll" or "load more" gesture at the bottom

##### `const handleTouchEnd`

Handle the `touchend` event, which fires when the user lifts their finger off the screen, resetting the touch tracking.
Here we again reset the `startYRef.current = null` to clear the stored starting Y-coordinate, ensuring that the next `touchmove` event won't proceed unless a new `touchstart` event sets a valid `startYRef.current`

### Deskop detection

```js
const handleOverscrollDesktop = (e) => {
  const el = bodyRef.current;
  if (!el) return;

  if (loadingTop || loadingBottom) return;

  const THRESHOLD = 2; // or 1, depending on your content

  const atTop = el.scrollTop === 0;
  const atBottom =
    Math.abs(el.scrollHeight - el.clientHeight - el.scrollTop) < THRESHOLD;

  if (atTop && e.deltaY < 0) {
    // User is at the top and tries to scroll up
    console.log("Tried to overscroll at top");

        // perform custom logic here
  } else if (atBottom && e.deltaY > 0) {
    // User is at the bottom and tries to scroll down
    console.log("Tried to overscroll at bottom");

        // perform custom logic here
  }
};
```

> Explanation of the above code line by line:

### `const handleOverscrollDesktop`
Defines a function to handle scroll event (likely `wheel` events) on a desktop device,
detecting when the user tries to scroll past the top or bottom of a scrollable element.

- `const el = bodyRef.current` retrieve the current value of the DOM node (or `null` if not yet assigned)

- `const THRESHOLD = 2;` this threshold is used to determine if the user is "at the bottom" of the scrollable element,
allowing for a small margin of error in scroll position calculations (due to potential floating-point inaccuracies in browser scroll measurements)

- `const atTop = el.scrollTop === 0` checks if the scrollable element is at the top.
`el.scrollTop` is the number of pixels the element's content is scrolled vertically from the top.
If 0, the user is at the top of the content.

- `const atBottom = Math.abs(el.scrollHeight - el.clientHeight - el.scrollTop) < THRESHOLD`
checks if the scrollable element is at (or very near) the bottom.
`el.scrollHeight` total height of the element's content (including overflow - content not currently visible)
`el.clientHeight` visible height of the element (excluding scrollbars)
`el.scrollTop` current scroll position (pixels scrolled from the top)
`el.scrollHeight - el.clientHeight` calculates the maximum scrollable distance (the total scrollable height)
subtracting `el.scrollTop` gives the remaining distance to the bottom
`Math.abs(...) < THRESHOLD` checks if the remaining distance is less than 2 pixels,
accounting for minor inaccuracies in scroll calculations

- `if (atTop && e.deltaY < 0)`
Checks two conditions:
-- `atTop` the user is at the top of the scrollable element (`el.scrollTop === 0`)
-- `e.deltaY < 0` the user is scrolling upward (negative `deltaY` indicates an upward scroll direction in a `WheelEvent`)
This combination indicates the user is trying to "overscroll" past the top ("pull-to-refresh" action attempt)

- `else if (atBottom && deltaY > 0)`
Checks two conditions:
-- `atBottom` the user is at (or near) the bottom of the scrollable element
-- `e.deltaY > 0` the user is scrolling downward (positive `deltaY` indicates a downward scroll direction)
This combination indicates the user is trying to "overscroll" past the bottom (load more action attempt)

