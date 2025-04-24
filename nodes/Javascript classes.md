---
aliases:
context:
- "[[JavaScript]]"
---

#wip

# JavaScript classes

Describing what are classes and abstract classes.
Abstract classes are not natively supported in JS, they are supported in TS.

---

### Classes
In JS/TS classes are like blueprints for creating objects. They can have fields/properties and methods (functions).

``` js
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


``` typescript
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

``` ts
// subclass implements an abstract method
class Dog extends Animal {
  makeSound(): void {
    console.log("Woof!");
  }
}
```


``` ts
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

