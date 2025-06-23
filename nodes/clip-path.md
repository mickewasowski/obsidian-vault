---
aliases:
context:
- "[[CSS]]"
---

#wip

# clip-path

Used to create interesting shapes with CSS.

---
### Usages:
1. Crop images into image masks
2. Add stylish hover effects
3. Design eye-catching layouts


### Basic shapes:

> Circles
``` css
clip-path: circle(radius at cx cy); // cx and cy define the center coordinates
```
> for radius you can use pixels or percentages
> for coordinates you can use pixels, percentages or words (e.g. top left) 
> for coordinates you can also use 'center' to center the crop


> Ellipse
``` css
clip-path: ellipse(rx ry at cx cy);
```
> you provide two radii - one for the x axis and one for the y axis


> Inset
``` css
clip-path: inset(top right bottom left round (border-radius));

// example
clip-path: inset(20px 30px 40px 10px round 10px);
```
> lets you crop a rectangular area from an element - like padding that hides the outer edges
> the values define how much to cut from each side
> the optional round keyword - use it to add corner radius of the inset area just like border radius
> you can also provide two radii for the top left, bottom right and top right, bottom left corners
> for equal insets on all sides use a single value


> Polygon
``` css
clip-path: polygon(x1 y1, x2 y2, x3 y3); // you can provide as many points as you want

// example
clip-path: polygon(75% 0, 100% 50%, 75% 100%, 0 100%, 25% 50%, 0 0);
```
> you can create any custom shape by defining points using X and Y coordinates (anything outside these points gets clipped)
> each x-y pair defines a point and the next is connected to the previous, with the last automatically connecting to the first
> you can use pixels, percentages, or any other valid units


> Path
``` css
clip-path: path("M 10,40 L 70,40 L 80,30 L 80,10 L 90,0 L 140,0 L 150,10 L 150,190 L 140,200 L 10,200 L 0,190 L 0,50 Z");

// example with a figure with rounded edges
clip-path: path("M 10,40 L 70,40 A 10,10 0,0,0 80,30 L 80,10 A 10,10 0,0,1 90,0 L 140,0 A 10,10 0,0,1 150,10 L 150,190 A 10,10 0,0,1 140,200 L 10,200 A 10,10 0,0,1 0,190 L 0,50 A 10,10 0,0,1 10,40 Z");
```
> M tells the browser where to start the path, Z closes the path by connecting the last point to the first
> L - draws straight line between points
> (A rx,ry x-axis-rotation, large-arc-flag, sweep-flag) - use it for elliptical arc - draws a smooth curve between two points
	sweep-flag - 0 or 1 -> 1 equal convex and 0 equal concave
	 x-axis-rotation and large-arc-flag - usually set to 0 