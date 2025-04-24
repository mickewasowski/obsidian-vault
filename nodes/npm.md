---
aliases:
context:
---

#wip

# npm

ad

---
``` bash
npm install
```
The above command needs to be applied if the package.json and package-lock.json *are not*  in sync.

``` bash
npm ci
```
The above can be applied if the package.json and package-lock.json *are* in sync.


### Difference between npm i and npm ci:

| npm install | npm ci (clean install) |
| --------| ----------|
| install dependencies listed in package.json | installs *exactly what's in package-lock.json* |
| if there is a package-lock.json it tries to match it - but can update it if there is a mismatch | fails if package-lock.json is out of sync with package.json |
| adds new packages to both node_modules and package-lock.json, adds to/creates node_modules if it's missing | doesn't update package-lock.json or install anything new, deletes node_modules first |


### Use it when:
| npm install | npm ci |
| ---------- | ----------|
| you're actively developing and want to add/update packages | you want clean reproducible installs |
| you don't mind updates of the package-lock.json | you're installing dependencies in a fresh environment |

