---
aliases:
context:
- "[[Web Development]]"
- "[[JavaScript]]"
- "[[HTML]]"
---

# DOM Manipulation

The Document Object Model (DOM) is how programs see HTML and XML documents.

---
It lets scripts change a page's structure, content and style dynamically.
With the DOM, you can easily work with HTML tags, IDs, classes, and attributes to make webpages interactive.

It's like a *tree-like representation* of your HTML document that JS can read and manipulate.
Every tag becomes a **node** (an element node), text inside tags becomes a **text node**, and attributes/properties are also represented.

> Think of the DOM as an **API to your HTML**.

#### Selecting elements
``` js
// Modern
document.querySelector("h1")       // first <h1>
document.querySelectorAll(".item") // all with class="item"

// Classic
document.getElementById("main")
document.getElementsByClassName("item")
document.getElementsByTagName("p")
```
> `querySelector` is the most flexible (supports CSS selectors).

#### Changing content
``` js
const title = document.querySelector("h1");

// text
title.textContent = "Hello";    // changes text (keeps HTML as text)
title.innerText = "Hello";      // similar but respects styling/visibility
title.innerHTML = "<span>Hi</span>"; // parses HTML

// attributes
const link = document.querySelector("a");
link.href = "https://example.com";
link.setAttribute("target", "_blank");
```

#### Changing styles and classes
``` js
const box = document.querySelector(".box");

// inline style
box.style.backgroundColor = "red";
box.style.fontSize = "20px";

// classes (better practice)
box.classList.add("active");
box.classList.remove("hidden");
box.classList.toggle("highlight"); // adds if missing, removes if present
```

#### Creating and inserting elements
``` js
const newDiv = document.createElement("div");
newDiv.textContent = "I was created!";
newDiv.className = "generated";

// append into DOM
document.body.appendChild(newDiv);
document.body.insertBefore(newDiv, document.body.firstChild);

// modern
document.body.append("Text or node");
document.body.prepend(newDiv);
```

#### Removing elements
``` js
const item = document.querySelector(".item");
item.remove(); // modern way
```


#### Event handling (super important!)
``` js
const btn = document.querySelector("button");

// modern recommended
btn.addEventListener("click", () => {
  alert("Button clicked!");
});

// remove
btn.removeEventListener("click", handlerFn);
```
- common events: `click`, `mouseover`, `keydown`, `input`, `submit`, `scroll`

#### Event bubbling & delegation
- Events **bubble up** the DOM tree by default (from child -> parent)
- **Delegation**: Instead of adding listeners to every child, add one to a parent and check the `event.target`
``` js
document.querySelector("ul").addEventListener("click", (e) => {
  if (e.target.tagName === "LI") {
    e.target.classList.toggle("done");
  }
});
```

#### Performance considerations
- Minimize DOM manipulation inside loops (costly)
- Use **fragments** (`documen.createDocumentFragment()`) when inserting many elements
- Batch style changes with `classList` instead of multiple `.style` calls