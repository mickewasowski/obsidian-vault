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
Every JS object has a secret link (its [[Prototype]]) to another object. This "prototype" object acts like a *blueprint*. When you try to access a property or method on an object, if it doesn't find it directly on the object, it looks for it on its prototype. If not there, it looks on that prototype, and so on, forming a **prototype chain**. This is how JavaScript does inheritance. 

> [!tip] ES6 `class` syntaxt is largely "syntactic sugar" over JavaScript's existing prototype-based inheritance.
> You could say that prototypes are the old syntax for modern day class syntax.
> While there are some minor differences and new features classes bring (like strict mode by default, easier `super` calls, or truly private class fields), the fundamental inheritance model remains prototypal.

> [!warning] To achieve a "private field" with prototypes you'd primarily use **closures**.
Example:
``` js
    function Person(name, initialAge) {
      // This 'privateAge' variable is local to each instance of Person,
      // created when 'new Person()' is called. It's not directly accessible from outside.
      let privateAge = initialAge; //truly private to each `Person` instance

      this.name = name; // Public property

      // Public method on the prototype that can access 'privateAge'
      this.getAge = function() {
        return privateAge; // This method "closes over" the privateAge variable
      };

      // Public method on the prototype that can modify 'privateAge'
      this.celebrateBirthday = function() {
        privateAge++; // Modifies the private variable
        console.log(`${this.name} is now ${privateAge} years old!`);
      };

        //getAge and celebrateBirthday are re-created for each `Person` instance
        //this would lead to higher memory consumption if you create many `Person` objects
    }

    const alice = new Person("Alice", 30);
    const bob = new Person("Bob", 25);

    console.log(alice.name); // Alice
    console.log(alice.getAge()); // 30

    alice.celebrateBirthday(); // Alice is now 31 years old!
    console.log(alice.getAge()); // 31

    // You cannot directly access alice.privateAge; it will be undefined.
    console.log(alice.privateAge); // undefined (or an error in strict mode if you tried to assign to it)

    bob.celebrateBirthday(); // Bob is now 26 years old!
    console.log(bob.getAge()); // 26
```
Why this works (the "closure" part):
- `privateAge` is declared using `let` (or `var`) inside the Person constructor function. This makes it a local variable.
- The `getAge` and `celebrateBirthday` methods, although assigned to `Person.prototype`, are *defined* within the same scope as `privateAge`.
- When an instance like `alice` is created, a new `privateAge` variable is created for *that* specific `privateAge`. This means they "remember" and can access that particular `privateAge` even after the `Person` constructor has finished executing.

- Every JS object has an internal *[[Prototype]]* property linking it to another object (it's **prototype**)
- When a property/method isn't found on an object, JS looks up the *prototype chain* until it finds it or hits `null`

#### 2. Constructor Functions & *prototype*
**Constructor Functions** are regular JavaScript functions, but with a special purpose: *to create and initialize new objects*.
By convention, you name them with an *uppercase first letter*. This helps you know it's meant to be used as a constructor.
You call a constructor function using the *new* keyword `const newObj = new Person('alice')`.
> When `new` is used, JavaScript automatically does a few things:
> 1. It creates a *new, empty object* behind the scenes
> 2. It sets `this` inside the constructor function to point to **that new empty object**
> 3. It executes the code inside the constructor function, which typically adds properties to `this` (the new object)
> 4. It automatically *returns that new object* (unless you explicitly return a different object)

Purpose:
- To defined the initial state (properties/data) that each new object will have
- To create multiple similar objects easily, instead of manually creating each one



**Prototype** - Every JavaScript function (including constructor functions) automatically gets a special object property called `prototype`.
This `prototype` property is itself an object.

Purpose:
- To store properties and methods that you want to be shared among all instances created by that constructor function.
- This is the core mechanism for inheritance in JavaScript (prototypal inheritance).

How it works (the prototype chain):
- When you create an object with `new ConstructorFunction()`, that new object gets a hidden link ([[Prototype]] or `__proto__`) to `ConstructorFunction.prototype`.
- When you try to access a property or method on an object (e.g. `alice.sayHello()`), JavaScript first checks if the property exists directly on `alice`.
- If not, it follows the hidden link to `Person.prototype` and looks there.
- If still not found, it continues up the "prototype chain" (the prototype's prototype, and so on) until it finds the property of reaches null.

Example:
``` js
    function Person(name, age) {
      this.name = name;
      this.age = age;
    }

    // Add a method to the prototype
    Person.prototype.sayHello = function() {
      console.log(`Hello, my name is ${this.name}.`);
    };

    // Add a property to the prototype
    Person.prototype.species = "human";

    const alice = new Person("Alice", 30);
    const bob = new Person("Bob", 25);

    alice.sayHello(); // Hello, my name is Alice. (Method inherited from prototype)
    bob.sayHello();   // Hello, my name is Bob.   (Method inherited from prototype)

    console.log(alice.species); // human (Property inherited from prototype)
    console.log(bob.species);   // human (Property inherited from prototype)

    // Check if 'sayHello' is an "own property" of alice:
    console.log(alice.hasOwnProperty('sayHello')); // false (It's on the prototype)
    // Check if 'name' is an "own property" of alice:
    console.log(alice.hasOwnProperty('name'));     // true (It was added by the constructor)
```
> Why use `prototype` for methods/shared properties?
- Memory efficiency: The `sayHello` function is create only once in memory. All `Person` objects share this single function, rather than each having its own copy. This saves memory, especially for many instances.
- Dynamic changes: If you modify `Person.prototype.sayHello` later, all existing and future instances will immediately see that change, because they all reference the same prototype object.

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
> `prototype` (on Constructor Functions)
> What it is: A property that only exist on funcitons (specifically, constructor funcitons)
> Purpose: It's the blueprint for objects that will be created by that constructor funciton using the `new` keyword. Whatever you put on `MyFunction.prototype` will be inherited by all instance created from `MyFunction`.
> Think of it as: The "template" or "shared parts" that new objects get when they are born.
Example:
``` js
    function Animal(name) {
      this.name = name;
    }

    // We add a method to Animal's prototype
    Animal.prototype.speak = function() {
      console.log(`${this.name} makes a sound.`);
    };

    // Animal.prototype is an object!
    console.log(typeof Animal.prototype); // "object"
    console.log(Animal.prototype);        // { speak: [Function], constructor: [Function: Animal] }


    const dog = new Animal("Buddy");
    dog.prototype // returns undefined since dog is an instance and prototype can only be called on the Animal (Constructor Function)
```


> `__proto__` (on Objects/Instances)
> What it is: A (historically non-standard, but now widely supported and officially in Annex B of the spec) property that exists on every object instance.
> Purpose: It's the actual link from an object instance to its prototype. It points to the object that the current object will delegate to if a property or method isn't found directly on itself.
> Think of it as: The "secret internal link" and object has to its blueprint.
> Modern alternative; You should prefer `Object.getPrototypeOf(obj)` to get an object's prototype and `Object.setPrototypeOf(obj, proto)` to set an object's prototype, as `__proto__` is generally discouraged for direct use due to performance implications and historical non-standardization.
Example:
``` js
    function Animal(name) {
      this.name = name;
    }

    Animal.prototype.speak = function() {
      console.log(`${this.name} makes a sound.`);
    };

    const dog = new Animal("Buddy"); // 'dog' is an instance

    // dog.__proto__ points to Animal.prototype
    console.log(dog.__proto__ === Animal.prototype); // true

    // This is the preferred way to get the prototype:
    console.log(Object.getPrototypeOf(dog) === Animal.prototype); // true

    // You can access inherited methods via __proto__ (but usually you just call them directly)
    dog.__proto__.speak.call(dog); // Buddy makes a sound. (This is just to illustrate the link)
    dog.speak(); // Buddy makes a sound. (Normal usage)
```


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
