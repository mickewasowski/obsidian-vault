---
aliases:
context:
- "[[CSS Modules]]"
---


# SCSS Modules

They are just like [[CSS Modules]], but they also use SCSS (Sass) syntax for writing styles.

---
The main difference is in the syntax and features you can use:
- **SCSS Modules** use the `.module.scss` extension
- you get all the benefits of CSS Modules (local scoping, unique class names)
- you can use SCSS features: variables, nesting, mixins, functions, etc.

Example:
``` scss
$primary: #007bff;

.button {
  background-color: $primary;
  color: white;
  
  &:hover {
    background-color: darken($primary, 10%);
  }

	p {
		font-size: 2rem;
		color: blue;
	}
}
```