---
aliases:
context:
- "[[this keyword]]"
---

# Function Borrowing

call, bind, apply functions

---
*Function borrowing* allows us to use the methods of one object on a different object without having to make a copy of that method and maintain it in two separate places.
It is accomplished through the use of `.call()`, `.apply()` or `.bind()`. These methods allow us to explicitly set this on the method we are borrowing.

*Default binding* (Direct invocation) - points to the global object. It is applied for standalone functions and is the fallback option for all other types.
```js
function myFunction() {
    console.log(this)
}
myFunction(); // Window {}
```


*Explicit binding* is when you use the `call`, `apply`, `bind` methods to explicitly set the value of `this` in a function.
With these methods you can force a function to use a certain object as its `this`.

- `call` - pass in the required object as the first parameter during the function call. The actual function parameters are passed after the object.
- `apply` - similar to call, but the actual function parameters are passed in an array
```js
function myFunction(param1, param2) {
    console.log(this)     
  }
 
const obj = {
  someKey: 1, 
}

const param1 = 1, param2 = 2;
myFunction.call(obj, param1, param2)       // {someKey: 1}
myFunction.apply(obj, [param1, param2])    // {someKey: 1}
```

- `bind` - you create a new function with a fixed `this`. These types of functions are commonly known as **bound functions**
```js
function myFunction() {
    console.log(this)     
  }
 
const obj = {
  someKey: 1, 
}

const boundFunction = myFunction.bind(obj)
boundFunction();      // {someKey: 1}
```



*Implicit bingding* is when you invoke a function in an Object using the dot notation.

- Nested function - when a function is nested inside a method of an object, the context of the inner function depends only on its invocation type and not on the outer function's context.
```js
const obj = {
  someKey: 1, 
  outer: function() {
    function inner(){
       console.log(this);
    }     
    inner();
  },
}

obj.outer(); // Window {}
```
In the above example `outer` was called using implicit binding, `inner` was called using default binding.

- Method separated from the object - when we copy an object method to a new variable, we are creating a reference to the function
```js
function myFunction() {
  console.log(this);
}

const obj = {
  someKey: 1,
  myFunction: myFunction,
}

obj.myFunction(); // { someKey: 1, myFunction: f }
const newFunction = obj.myFunction;
newFunction();    // Window {}
```
In the above example newFunction directly refers to myFunction, hence `this` refers to the global object.



*New binding* (Constructor invocation) - it is applied when we create an object using Function Constructors.

- without return
```js
function myFunction(){
  // JS internally creates an object and refers it as this
  
  // User explicitly adds required properties and methods to the object
  this.someKey = 1;
  this.inner = function(){
    console.log(this);
  }
  
  // JS internally returns the object
}

const obj = new myFunction();
obj.inner()           // {someKey: 1, inner: ƒ} with myFunction prototype
```
Under the hood the following happens:
- the constructor function is invoked and an object is internally created, inheriting the prototype of the constructor function
- the properties and functions are added to this object
- the newly created object is returned and is assigned to the LHS (left hand side) variable at the function call


- with return - the returned object is assigned to the LHS variable at the function call and the prototype of the constructor function is NOT inherited
```js
function myFunction(){
  return {
    someKey: 1,
  }
}

const obj = new myFunction();
console.log(obj);    // {someKey: 1} without myFunction prototype
```


*Arrow functions*
Arrow functions use "lexical scoping" to figure out what the value of `this` should be.
Lexical scoping is a fancy way of saying it uses `this` from the **outer function** in  which it is _defined_.

a. if the outer function is a normal function, `this` depends upon the type of binding of the outer function
b. if the outer function is an arrow function, JS again checks for the next outer function and this process continues till the global object
```js
function outer(){ 
    let inner = () => { 
      console.log(this);
    };
    inner()
  } 

const objA = {
  someKey: 1,
  outer : outer, 
};
const objB = {
  someKey: 2,
}

// In this example, each time when inner function is called, 
// JS simply takes the this value from outer function
outer();            // Window {}
objA.outer();       // {someKey: 1, outer: ƒ} --> objA
outer.call(objB)    // {someKey: 2} --> objB
```

> None of the binding rules has any Direct Effect on arrow functions.

```js
const myFunction = () => {
  console.log(this);
}

const objA = {
  myFunction: myFunction,
  inner: () => {
    console.log(this);
  }
}

const objB = {}

myFunction();                   // Window {}
objA.myFunction()               // Window {}
objA.inner()                    // Window {}
myFunction.call(objB);          // Window {}
const objC = new myFunction()   // myFunction is not a constructor
```

