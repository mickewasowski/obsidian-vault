---
aliases:
context:
- "[[Code Organization/Architecture strategy]]"
---

# Monorepo

A monorepo (short for *monolithic repository*) is a single code repository that contains **multiple projects**.

---
### What is monorepo
It could contain libraries, applications, services, or packages - all managed together in one place.
Instead of having separate repositories (a *polyrepo*) for each project, a monorepo stores everything in a single repo with a structured folder layout.

Example structure:
```bash
/monorepo
  /packages
    /ui-components
    /utils
  /apps
    /web
    /admin
  package.json
  tsconfig.json
```
Here:
- `ui-components` and `utils` might be shared libraries
- `web` and `admin` are separate applications
- everything lives together in one repository


### Common Monorepo tools

- Nx - great for large-scale JS/TS projects
- Turborepo - fast build system optimized for JS/TS
- Lerna - manages versioning and publishing for multiple packages
- Bazel - used in very large organizations (like Google)


### Pros of Monorepo


