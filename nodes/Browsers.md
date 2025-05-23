---
aliases:
context:
- "[[Web Development]]"
- "[[Web]]"
---

# Browsers

Software for browsing the web.

---
### How JS Engines and Rendering Engines work together
1. The *rendering engine* loads HTML/CSS -> builds the page structure
2. When JS runs (e.g. document.getElementById()), the *JS engine* interacts with the DOM (managed by the rendering engine)
3. If JS modifies the DOM (e.g. adds an element), the *rendering engine* updates the layout and repaints the screen

###### Why does it matter?
=> Performance issues:
1. Slow JS - optimize code (reduce loops, use Web Workers) 
2. Slow rendering - simplify CSS/HTML (reduce complex selectors)

=> Browser compatibility:
1. JS engines handle ES6+ features differently
2. Rendering engines may display CSS/HTML slightly differently