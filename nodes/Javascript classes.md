---
aliases:
context:
  - "[[JavaScript]]"
---

# JavaScript classes

Describing what are classes and abstract classes.
Abstract classes are not natively supported in JS, they are supported in TS.

---

### Classes

In JS/TS classes are like blueprints for creating objects. They can have fields/properties and methods (functions).

```js
// basic example
class Person {
  name: string;
  age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }

  greet(): void {
    console.log(`Hi, I'm ${this.name} and I'm ${this.age} years old.`);
  }
}
```

### Abstract classes

An abstract class is a class that cannot be instantiated on its own. It is meant to be a base class for other classes (like a blueprint).
It can contain:

1. abstract methods (methods without implementation)
2. methods with implementation
3. properties and fields

#### Abstract methods

An abstract method is a method without implementation. Subclasses must override it and provide their own implementation.

```typescript
abstract class Animal {
  protected name: string; // field

  constructor(name: string) {
    this.name = name;
  }

  // Abstract method: must be implemented by subclass
  abstract makeSound(): void;

  // Concrete method
  move(): void {
    console.log(`${this.name} is moving.`);
  }
}
```

```ts
// subclass implements an abstract method
class Dog extends Animal {
  makeSound(): void {
    console.log("Woof!");
  }
}
```

```ts
abstract class Animal {
  abstract get sound(): string;
}
// while ts doesn't support directly abstract properties, we can simulate them with abstract getters
class Cat extends Animal {
  get sound(): string {
    return "Meow";
  }
```

> [!warning] While TS doesn't support directly abstract properties, we can simulate them with abstract getters

## 1. What Classes Are

- Syntactic sugar over constructor functions and prototypes
- Provide a clearer, more organized way to define objects with shared behavior
- Still prototype-based under the hood, not classical OOP

## 2. Class Declaration vs Class Expression

**Declaration:**

```js
class Person {}
```

**Expression:**

```js
const Person = class {};
```

Notes:

- Declarations are hoisted but in TDZ (same as let/const)
- Expressions behave like normal variable declarations

## 3. Constructor

- Special method that runs when the object is instantiated
- Used to initialize instance properties

```js
class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }
}
```

## 4. Instance Methods

- Methods available on class instances
- Placed on the prototype

```js
class Person {
  greet() {
    return `Hi, I'm ${this.name}`;
  }
}
```

## 5. Static Methods / Static Properties

- Belong to the class itself, not the instance
- Used for utilities or factory functions

```js
class MathUtils {
  static clamp(value, min, max) { ... }
}
```

## 6. Fields (Public Class Fields)

- Declared directly in the class body
- Avoids constructor boilerplate

```js
class Timer {
  count = 0;
}
```

## 7. Private Fields (`#`)

- Encapsulated fields that cannot be accessed externally
- True privacy enforced by the language

````js
class Counter {
  #value = 0
  increment() {
    this.#value++
  }
}


## 8. Getters and Setters

- Provide controlled access to internal state
- Useful for computed properties

```js
class Rectangle {
  constructor(w, h) { this.w = w; this.h = h }
  get area() { return this.w * this.h }
  set width(v) { this.w = v }
}
````

## 9. Inheritance (`extends`)

- Allows building hierarchies of related classes
- Subclass constructor must call `super()` before using `this`

```js
class Animal {
  speak() {}
}
class Dog extends Animal {
  speak() {
    return "woof";
  }
}
```

## 10. Method Overriding & `super`

- Override parent method
- `super.method()` calls the parent implementation

```js
class Dog extends Animal {
  speak() {
    return super.speak() + " (dog version)";
  }
}
```

## 11. The Prototype Behind the Scenes

- Classes are wrappers over prototype-based inheritance
- Methods live on `Class.prototype`
- Instances have an internal `[[Prototype]]` link to that object

Useful for understanding performance and memory usage.

## 12. When To Use Classes

- When modeling entities with shared behavior
- When needing inheritance or polymorphism
- When building reusable components (game entities, UI components, data models)

When _not_ to use them:

- Simple data structures
- Stateless utility functions
- When composition is a better fit (often cleaner)

## 13. Common Pitfalls

- Forgetting to bind methods when passing them as callbacks
- Using classes for data-only objects
- Overusing inheritance instead of composition
- Not understanding that classes are still prototype-based

## 14. Real Project Examples

- Models in frontend state (e.g. Todo, User, Product)
- Reusable logic for games (Player, Enemy, Inventory)
- Canvas/animation objects (Sprite, Vector2D)
- API wrapper classes (HttpClient, StorageService)
