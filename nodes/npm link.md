---
aliases:
context:
---

#wip

# npm link

`npm link` uses symbolic links to connect to a local package folder (your library) into another project's `node_modules`.
This way your local project behaves *as if it were installed from npm*, but it's actually pointing to your local source directory.

---
### How it works

1. You run inside your library folder `npm link`
- this tells npm: "Make my-ui-lib globally available as a linkable package"

> Under the hood npm:
>  - creates a global symlink in your global `node_modules` (something like `~/.nvm/versions/node/vXXX/lib/node_modules/my-ui-lib`)
> - that symlink points to your local actual library folder (`~/Projects/my-ui-lib`)

So now your library is *registered* globally on your machine.

2. You run inside your test project:
- `npm link my-ui-lib`

> Now npm:
> - creates a symlink in your app's `node_modules/my-ui-lib`
> - that symlink points to the global symlink from *point 1* (which points back to your local folder)

So the final chain looks like:
``` 
my-test-app/node_modules/my-ui-lib ➜ ~/.nvm/.../node_modules/my-ui-lib ➜ ~/Projects/my-ui-lib
```


### Development flow

With `npm link`, you can edit files in your library and just rebuild it - the test app immediately reflects the updates since the link is live. 

You can also use something like `tsup --watch` or `vite build --watch` in your library so your changes propagate instantly.