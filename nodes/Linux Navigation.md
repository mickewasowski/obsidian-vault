---
aliases:
context:
- "[[Linux]]"
---

#wip

# Linux Navigation

Navigation between directories and files.

---

### `cd`
Lets you go into different folders.
top-most directory ("root") directory is referred to by a single leading slash "/".
An absolute path indicates the location of a directory in relation to this top-level directory.
*Every* absolute path **must** begin with "/".

The alternative is to use *relative paths*.
Relative paths refer to directories in relation to the current directory.
Any directory within the current directory can be referenced by name without a leading slash.

To go back to the parent of the current directory you can use '..' => `cd ..`

To return to the home directory you use `~` `cd ~`


### `ls`
Shows you what files and folders are inside.
You can add some optional flags to the command to modify the default behavior.
For instance:
> `-l` => list all of the contents in an extended form (file type and permissions, number of hard links to that file elsewhere on the system, owner, group owner, item size, date updated, name)
> file type and permissions => if it starts with 'd' then the item is a directory
> fily type and permissions => if it starts with "-" then it's a normal file

> `-a` => get a list of all files, including *hidden* files and directories

### `pwd`
Tells you where you are currently.

