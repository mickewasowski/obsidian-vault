---
aliases:
context:
- "[[Control flow]]"
- "[[JavaScript]]"
---

# Exception Handling

All exceptions are simply objects. The majority of exceptions are implementations of the global Error class.

---
*Errors are thrown by the engine, and exceptions are thrown by the developer*

You can throw an error with the built-in Error class, or through a custom object.

### Generic exceptions
Error class provindes things such:
- file name
- line number
- stack trace
- message
- code

Example of throwing a simple error:
`throw new Error('Exception message');` 

> error.code vs error.message
`error.message` is the human readable error data
`error.code` identifies the *kind* of error that is being thrown


### Custom exceptions
You can throw *any* object, however, best practice is to extend the Error object with a new class.
```js
    function CustomException(message) {
      const error = new Error(message);
      return error;
    }

    CustomException.prototype = Object.create(Error.prototype);

    throw new CustomException('Exception message');
```

Throwing an error stops the current function execution (the statements after the throw won't be executed), and control flow will be passed to the first catch block in the call stack.
If no catch block exists among caller functions, the program will terminate.


### Try, Catch, Finally
- `try` - here we handle the code to run
- `catch` - handle errors
- `finally` - this executes after the previous two blocks regardless of the result


### Types of Errors
Beside the error constructors, JS also has other Error constructors:
- AggregateError - a collection of errors thrown simultaneously
- EvalError - an error occurred during the evaluation of a JavaScript expression
- InternalError - an internal JavaScript error, often indicating a bug in the engine
- RangeError - a value is outside the allowed range for a given operation
- ReferenceError - a variable or object is referenced before it's declared or doesn't exist
- SyntaxError - the code contains incorrect syntax, preventing it from being parsed
