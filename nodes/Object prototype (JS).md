---
aliases:
context:
- "[[OOP]]"
- "[[JavaScript]]"
- "[[JS Object]]"
---

#wip

# Object prototype (JS) | Prototypes

The very core of OOP in JS.
*A prototype is simply an object from which another object inherits properties.*

---
### Object prototype
JS is an object-oriented language built around a prototype model.
In JS every object inherits properties from its prototype, if there are any.
*A prototype is simply an object from which another object inherits properties.*
>Prototypes form the very core of OOP in JS.


### Prototypes in JavaScript

#### 1. Core concept
- Every JS object has an internal *[[Prototype]]* property linking it to another object (it's **prototype**)
- When a property/method isn't found on an object, JS looks up the *prototype chain* until it finds it or hits `null`

#### 2. Constructor Functions & *prototype*
- Constructor Functions (used with *new*) have a `.prototype` property
- Instances inherit from this *prototype*

Example:
``` js
    function Car(model) {
      this.model = model;
    }

    // Add method to prototype (shared across instances)
    Car.prototype.drive = function() {
      console.log(`Driving ${this.model}`);
    };

    const tesla = new Car("Model 3");
    tesla.drive(); // "Driving Model 3" (inherited)
```

* Key notes
1. *Car.prototype* is the prototype of instances (`test.__proto__`)
2. Avoid arrow funcitons in prototypes (they don't bind `this`)


#### 3. The Prototype Chain
- Objects inherit from their prototype, which can inherit from another prototype, forming a *chain*
- The chain ends at `Object.prototype` (which has `toString()`, `hasOwnProperty`, etc.)

Example:
``` js
    const animal = { eats: true };
    const rabbit = Object.create(animal); // rabbit.__proto__ = animal
    console.log(rabbit.eats); // true (inherited)
```

#### 4. `__proto__` vs. `prototype`

| ---------------------- | ----------------------------- | -------------------------------- |
| Feature                |          `prototype`          |     `__proto__ ([[Prototype]])`  |
| ---------------------- | ----------------------------- | -------------------------------- |
| **Exists on**          | Constructor Functions         | All objects (instances)          |
| **Purpose**            | Defines inheritance for `new` | Points to the object's prototype |
| **Modern Alternative** | `class` syntax                | `Object.getPrototypeOf(obj)`     |


* Key Insight
``` js
    function Dog() {}
    const dog = new Dog();

    console.log(dog.__proto__ === Dog.prototype); // true
    console.log(Object.getPrototypeOf(dog) === Dog.prototype); // true (modern way)
```

#### 5. Inheritance patterns
A. Classical (Constructor Functions)
``` js
    function Animal(name) { this.name = name; }
    Animal.prototype.walk = function() { console.log("Walking"); };

    function Bird(name) {
      Animal.call(this, name); // Super constructor
    }
    Bird.prototype = Object.create(Animal.prototype); // Inheritance
    Bird.prototype.fly = function() { console.log("Flying"); };
```

B. Modern (`class` syntax)
``` js
    class Animal {
      constructor(name) { this.name = name; }
      walk() { console.log("Walking"); }
    }

    class Bird extends Animal {
      fly() { console.log("Flying"); }
    }
```

C. Pure Prototypal (`Object.create`)
``` js
    const person = { greet() { return "Hi!"; } };
    const john = Object.create(person);
    console.log(john.greet()); // "Hi!" (inherited)
```

#### 6. Key Methods & Checks

| ---------------------------- | ------------------------------------------------------------- | -------------------------------- |
| Method/Check                 |                      Purpose                                  |              Example             |
| ---------------------------- | ------------------------------------------------------------- | -------------------------------- |
| `Object.create(proto)`       | Creates object with given prototype                           | `const obj = Object.create(null)` |
| `Object.getPrototypeOf(obj)` | Returns prototype of `obj`                                    | `Object.getPrototypeOf([]) → Array.prototype`|
| `obj.hasOwnProperty("key")`  | Checks if property exists *directly* on `obj` (not inherited) | `obj.hasOwnProperty("name")` |
| `"key" in obj`               | Checks entire prototype chain                                 | `"toString" in {} → true` |


#### 7. Advanced Topics
A. Performance
- Modifying prototypes at runtime (`Object.setPrototypeOf()`) *kills optimization*. Prefer `Object.create()` or `class`

B. No-Prototype Objects
``` js
    const bareObj = Object.create(null); // No `toString`, `hasOwnProperty`, etc.
    console.log(bareObj.toString); // undefined
```

C. Shadowing
``` js
    const obj = { name: "Alice" };
    obj.name = "Bob"; // Overrides (shadows) inherited properties.
```




##### Research this:
Interviews (Why They Ask)
Tests your understanding of inheritance, memory efficiency (shared methods), and JavaScript’s unique design.

Common questions:
- How would you implement inheritance without class?
- What happens when you call new?
