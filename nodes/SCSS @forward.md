---
aliases:
context:
- "[[SCSS]]"
---

# SCSS @forward

---
> `@forward 'some-path'` re-exports another module's public members.

It does *NOT* import them for use in the current file.

Instead it says:
> Anything from `some-path` should also be available to whoever imports me.


Example:
``` scss
// colors.scss
$primary: blue;

@mixin button {
	padding: 10px;
}
```

``` scss
// index.scss

@forward "colors";
```


``` scss
// main.scss

@use "index";

.button {
	color: index.$primary;
	@include index.buttons;
}
```


#### Why does this exist?

This approach is used as a public API wrapper.

It's commonly used to create:
- a single entry point
- a clean design system export
- a centralized module