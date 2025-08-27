---
aliases:
context:
- "[[Operating Systems]]"
- "[[File Systems]]"
---

#wip

# Symlink

Symbolic link (Symlink) is a special file that points to another file or folder, like a shortcut.
It doesn't copy the data - just references the original location.

---
#### Create a symlink
(the below use case was tested with dist folder from one project and the node_modules of another project)
``` bash
ln -sfn pathA(target) pathB(source)
```

- target => what you want to point to
- source =>the link name (where you want the symlink to appear)

- `ln` - this is a Unix/Linux command used to create links between files/directories
- `-s` - *symbolic link* - Without this, `ln` create a *hard link*. With `-s`, it makes a *symlink*  (a pointer/refrence to another file/directory, like a shortcut)
- `-f` - *force* - If a file or symlink already exists at `pathB`, this option removes it before creating the new symlink. Without `-f`, the command would fail if `pathB` already exists.
- `n` - *treat destination as a normal file if it's a symlink* - Without `-n`, if `pathB` already exists and is a symlink to a directory, `ln` would create the new symlink *inside that directory*. With `-n`, `ln` replaces the symlink itself instead of messing with what it points to. This is especially important for your use case (avoiding nesting symlinks in `node_modules`)