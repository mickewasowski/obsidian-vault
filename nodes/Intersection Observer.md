---
aliases:
context:
- "[[Design patterns]]"
- "[[JavaScript]]"
- "[[Behavioral design patterns]]"
---

# Intersection Observer

---
Intersection Observer API is mainly used to detect when an element enters the viewport and then have something happen as it does.
Essentially, Intersection observer allows to watch for when an element (the target) enters the or exits another element (the root). The root can be either the viewport or another element (e.g. a div container).
The target needs to be the descendant of a scrollable element or the device's viewport.
The intersection ratio is the degree of intersection between the target element and its root. The ratio can be a value between 0.0 and 1.0, where this is a percentage value.

Example uses:
1. lazy load images
2. triggering animations
3. "infinite scrolling" websites so that the user doesn't have to flip pages


Example code setup:
```
	# **JS:**

const options = {

    root: document.querySelector('.span-wrapper'),

    rootMargin: '0px',

    threshold: 0.5,

};

  

const handleSpanShown = (entries, observer) => {

    entries.forEach(entry => {

        if (entry.isIntersecting) {

            entry.target.classList.add('visible');

        } else {

            entry.target.classList.remove('visible');

        }

    });

};

  

const observer = new IntersectionObserver(handleSpanShown, options);

const targets = document.querySelectorAll('.initial');

targets.forEach(target => {

    return observer.observe(target);

});



	# **HTML:**

<!DOCTYPE html>

<html lang="en">

<head>

    <meta charset="UTF-8">

    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <link rel="stylesheet" href="./styles.css">

    <script src="./index.js" defer></script>

    <title>Document</title>

</head>

<body>

    <div class="span-wrapper">

        <span class="initial"><p>1</p></span>

        <span class="initial"><p>2</p></span>

        <span class="initial"><p>3</p></span>

        <span class="initial"><p>4</p></span>

    </div>

</body>

</html>


	# **CSS:**

.span-wrapper {

    width: 400px;

    height: 400px;

    margin: auto;

    overflow-x: clip;

    overflow-y: auto;

    background-color: grey;

}

  

.initial:first-child {

    margin-top: 400px;

}

  

.span-wrapper > .initial {

    width: 100%;

    height: 100px;

    color: white;

    background-color: red;

    border-radius: 10px;

    display: block;

}

  

.span-wrapper > .visible {

    background-color: green;

}
```