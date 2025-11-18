---
aliases:
context:
- "[[JavaScript]]"
---

# Javascript Modules

Used to separate code into multiple files, so called "modules".
A module is just a file. One script is one module.

---
### Types of Modules
- AMD - one of the most ancient module systems, developed by `require.js`
- [[CommonJS]] - developed for Node.js server
- UMD - suggested as a universal module system, compatible with AMD and CommonJS
- [[ES Modules]]


Modules can load each other using `export` and `import` to interchange functionality.
- `export` - defines what functionality can be used in other modules
- `import` - allows to load functionality from other modules

In a browser if you want the module features to work we first need to tell the browser that the script is in fact a module:
```html
<!doctype html>
<script type="module">
  import {sayHi} from './say.js';

  document.body.innerHTML = sayHi('John');
</script>
```

> [!warning] Modules work only via HTTP(s), not locally
> If you try to open a page locally via `file://` protocol `import/export` will not work.
> You need to use a local web-server to test modules.


### Core module features

1. Always "use strict" - modules always work in strict mode.
2. Module-level scope - a module cannot access variables and functions from another module if they're not exported. Modules should `export` what they want to be accessible from outside and `import` what they need. With modules we use import/export instead of relying on global variables.
3. A module code is evaluated only the first time when imported - if a module is imported in multiple other modules, it's code is evaluated only on the first import.
4. In a module `this` is `undefined`


### Browser-specific features

1. Module scripts are always defered
- downloading external module scripts doesn't block HTML processing (they load in parallel with other resources)
- module scripts wait for the HTML document to fully load and then run
- relative order of scripts is maintained, scripts that go first in the document execute first

2. Async works on inline scripts
- for non-module scripts, the `async` attribute only works on external scripts. Async scripts run immediately when ready, independently of other scripts or the HTML document.
- for module scripts, it works on inline scripts as well. The below code doesn't wait for anything, it performs the import and runs when ready. That is good for functionality that doesn't depend on anything.
```html
<script async type="module">
  import {counter} from './analytics.js';

  counter.count();
</script>
```

3. External scripts
- external scripts with the same `src` are fetched and executed only one
- external scripts that are fetched from another origin require CORS headers. If a module script is fetched from another origin, the remote server must supply a header `Access-Control-Allow-Origin` allowing the fetch (ensure better security).

4. No "bare" modules allowed
Modules without any path are called "bare". Such modules are NOT allowed.
In the browser, `import` requires either a relative or an absolute path.

> [!tip] Certain environments, like Node.js or bundle tools allow bare modules, without any path, as they have their own ways for finding modules and hooks to fine-tune them. However, browsers do not support bare modules yet.

5. Compatibility, "nomodule" - old browsers do not understand `type="module"`. Scripts of unknown type are ignored. For them, we can provide a fallback using  the `nomodule` attribute.

6. Build tools
Browser modules are rarely used in their "raw" form. Usually bundle tools (such as Webpack, Rollup, Parcel) bundle them together.
Bundlers give more control over how modules are resolved, allowing bare modules and much more like CSS/HTML modules.

Bundlers work as follows:
- take a "main" module, the one intended to be put in the HTML `<script type="module">`
- analyze it's dependencies - imports and imports of imports
- build a single file with all modules (or multiple files, depending on the configuration), replacing native `import` calls with bundler functions (so it all works)
- in the process other transformations and optimizations may be applied such as:
    - unreachable code removed
    - unused exports removed ("tree-shaking")
    - development specific statements like `console` and `debugger` are removed
    - modern Javascript syntax may be transformed to older one with Babel
    - the resulting file is minified (spaces removed, variables replaced with shorter names, etc.)

> [!tip] If we use a bundler tool the `import/export` statements are removed and replaced with bundler functions.
> This way the resulting script does not require `type="module"` and we can put it into a regular script.


====================
Import/Export (static)
====================

### Types of imports

```js
import { something } from "./something.js" // named imports
import { something as test } from "./something.js" // rename a named import
import * as everything from "./something.js" // import everything from the file as everything object
import ThatThing from "./something.js" // default import
```


### Types of exports

```js
export const var1 = 'test';

export function func1() {
    //do something
}

export class MyClass {
    // something
}

export {var1, func1, MyClass}

export {var1 as myVar1}

export {MyClass as default}

export default function testFunc() {
    // test func
}
```

### Re-exporting

```js
export * from "./user.js" // re-export all named exports

export {sayHi} from "./user.js"

export {default as User} from "./user.js"

export {default} from "./user.js" // re-export the default export
```


=================
Dynamic imports
=================

`import(module)` expression loads the module and returns a promise that resolves into a module object that contains all its exports. It can be called from any place in the code.

```js
let modulePath = prompt("Which module to load?");

import(modulePath)
  .then(obj => <module object>)
  .catch(err => <loading error, e.g. if no such module>)
```

We can also use `await` if we're in an async function:
```js
// access named exports
let {hi, bye} = await import('./say.js');

hi();
bye();

// access default export
let obj = await import('./say.js');
let say = obj.default;

say();
```

> [!warning] Even thought `import()` uses parenthesis it is not a function call. You cannot assign it to a variable, nor use call/apply.
