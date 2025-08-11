---
aliases:
context:
- "[[CSS]]"
---


# CSS Modules

CSS Modules are a way to write CSS where styles are scoped locally to each component, preventing class name conflicts.

---
CSS Modules work by generating unique class names and importing them into your JS, so styles only apply to the intended elements.

### Example usage:
``` jsx
//Button.jsx

import React from 'react';
import styles from './Button.module.css';

export default function Button({ children }) {
  return <button className={styles.button}>{children}</button>;
}
```

``` css
//Button.module.css

.button {
  background-color: #007bff;
  color: white;
  padding: 8px 16px;
  border: none;
  border-radius: 4px;
  cursor: pointer;
}
```

### Contents of module.css
1. class selectors `.button { color: red; }`
2. element selectors `h1 { font-size: 2rem; }`
3. pseudo-classes and pseudo-elements
``` css
.button:hover { background: blue; }
.input::placeholder { color: gray; }
```
4. media queries
``` css
@media (max-width: 600px) {
  .container { padding: 10px; }
}
```
5. css variables
``` css
:root {
  --main-color: #333;
}
```
6. keyframes for animations
``` css
@keyframes fadeIn {
  from { opacity: 0; }
  to { opacity: 1; }
}
.fade { animation: fadeIn 1s; }
```

> [!Tip] You can use any valid CSS syntax - the only requirement is the `module.css` extension for CSS Modules to work. The styles will be scoped to the component that imports them.

### How to use the defined styles from the module
1. import the CSS Module file `import styles from './Button.module.css'
2. apply the styles to your elements using `className`:
``` jsx
<button className={styles.button}>Click me</button>
```
> Explanation:
- the `styles` object contains all the class names defined in your CSS Module, renamed to be unique
- you access a class by its original name (`styles.button`) and assign it to the `className` prop in JSX
- this ensures your styles are scoped to the component and do not clash with other styles.

### N.B.
> [!warning] In CSS Modules only class names are exported as properties of the imported `styles` object.
> *Element selectors* (like `h1`, `p`, `div`) and *ID selectors* (like `#main`) are **not exported**. These cannot be accessed via `styles.h1` or `styles.main`. They apply globally if used in the CSS Module file, which is discouraged because it breaks style encapsulation.

> [!error] 
> Use class selectors for local, scoped styles via `styles.className`
> Element and ID selectors are not scoped or exported, and their use in CSS Modules is rare and not recommended. For true encapsulation, prefer class selectors.