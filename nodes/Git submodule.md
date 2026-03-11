---
aliases:
context:
 -"[[Git]]"
---


# Git submodule

A Git Submodule is a way to include one Git repository inside another, while keeping them as separate repos.

---

### Overview

A Git Submodule is a way to include one Git repository inside another, while keeping them as separate repos.
- your main project = superproject
- the shared repo = submodule

Instead of copying the code, Git stores:
- the URL of the submodule repo
- the exact commit hash that your project should use

That commit hash is the key.

Your main repo doesn't track the submodule's braches. *It tracks a specific commit SHA*


### How to add a submodule

```bash
git submodule add url_to_repo path_to_place_reference_to_the_repo_in_main_project
```

> [!warning] If someone updates the shared components repo:
> - your project does NOT automatically get that update
> - you must manually update the submodule reference


### Why to use submodules

Submodules are useful when:
- multiple projects share a codebase
- you want strict version control
- you want reproducible builds
- you don't want automatic updates breaking things


### Downsides

- Cloning requires:
```bash
git clone --recurse-submodules

// or

git submodule update --init --recursive
```
- developers forget to update submodules
- CI pipelines sometimes fail if submodules aren't initialized
- merge conflicts can happen on submodule SHAs


### Check hash

The below command returns the current hash strings for each submodule in your repo:
``` bash
git submodule status
```