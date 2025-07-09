---
aliases:
context:
- "[[JS Data types]]"
---

#wip

# JS Object

Key-value pair data type.

---
JS Object is a data structure that allows us to have key-value pairs, so we can have distinct keys and each key is mapped to a value that can be of any JS data type.
``` js 
    let user = {
        name: 'John',
        age: 30,
        "likes birds": true, // the last property in the list may end with a comma ("trailing" or "hanging" comma)
    };

    user["likes birds"]
```
Property values are accessible using the dot notation. `user.name`
To remove a property we can use `delete user.age`

> If you try to access a property that doesn't exist there won't be any errors, it will simply return `undefined`.
> So if you want to test if a property exists you can either check if it's undefined or you can use operator `in`.
``` js
    "key" in object
    "skin" in user // false, user.skin doesn't exist
```

> [!Tip] It's important to use `in` operator to check if a property exists because if we rely on `undefined` there is a chance that the property actually exists but stores undefined.

To walk over all keys of an object we use `for..in` loop.

> [!Tip] Integer properties are sorted, others appear in creation order. The "integer property" term here means a string that can be converted to-and-from an integer without a change.
> On the other hand if the keys are non-integer they are listed in the creation order.
``` js
    let codes = {
        "49": "Germany",
        "41": "Switzerland",
        "44": "Great Britain",
        ...
        "1": "USA",
    };

    for (let code in codes) {
        alert(code); // 1, 41, 44, 49
    }
    // this can be cheated by adding + to each key so it cannot be converted to an integer
```

> Interesting thing is that even if you provide the property name in parentheses, if you define a property with one name and then try to define another with the same key string, the second one will override the first one (same as it would if you provide the name without parentheses).


