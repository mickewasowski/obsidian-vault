---
aliases:
context:
- "[[Web Development]]"
- "[[JavaScript]]"
- "[[Graphics]]"
---

# Canvas HTML

Used to draw graphics on the fly with JS.

---
### Usage
- drawing shapes
- rendering images
- creating animations
- making games
- visualizing data (like charts or graphs)

### Basic syntax
``` 
<canvas id="myCanvas" width="300" height="300"></canvas>
```
- `id` - identifier to access the canvas via JS
- `width` and `height` - size of the drawing surface (in pixels). defaults to 300x150 if not specified.

### Accessing the drawing context
``` js
const canvas = document.getElementById('myCanvas');
const ctx = canvas.getContext('2d'); // here you can also provide webgl, webgl12, webhpu, bitmaprenderer
```
- `ctx` is now the 2d rendering context that exposes drawing methods.

### Common drawing methods
``` js
// Draw a rectangle
ctx.fillStyle = 'blue';
ctx.fillRect(10, 10, 100, 50); // x, y, width, height

// Draw a circle
ctx.beginPath();
ctx.arc(75, 75, 50, 0, Math.PI * 2); // x, y, radius, startAngle, endAngle
ctx.fill();

// Draw text
ctx.font = '20px Arial';
ctx.fillStyle = 'black';
ctx.fillText('Hello Canvas', 10, 140);
```

> [!Tip] Notes:
> - the canvas is `bitmap-based`, so if you scale it with CSS, the content can blur
> - canvas is `imperative` (you tell it exactly what to do), unlike SVG, which is `declarative`
> - to keep content responsive, you often pair it with JS to redraw on window resize