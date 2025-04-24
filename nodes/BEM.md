---
aliases:
context:
- "[[CSS Architecture]]"
- "[[CSS Naming Conventions]]"
---

# BEM

---

BEM is a concrete application of the OOCSS principles, created by Yandex.

It stands for **Block**, **Element** and **Modifier**. The convention is meant to be descriptive.

Here is an example code:

```html
<div class="media media--inverted">
  <a href="#" class="media__image-wrapper">
    <img class="media__image" src="" alt="" />
  </a>
  <div class="media__content"></div>
</div>
```

From the code above we see that *media* is the main class name of the parent container. Any child element is named by adding two underscores and then its name as the class name (media__image-wrapper). Modifiers are indicated with double dashes (media--inverted). This would show an additional styling on top of the original provided by the *media* class name.

For example you'd like to have a button with rounded corners as the main styling.
Then if you want to add red color to the button when it is clicked once you can do so by providing a modifier (myButton--red), and for double click green (myButton--green).

