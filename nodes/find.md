---
aliases:
context:
  - "[[Shell]]"
---

# find

Find command used to locate files and directories

---

```bash
    find [where to search] [conditions] [what to do]

    find . -name "file.txt"  => . (start searching from the current directory), look for something exactly named "file.txt"

    find . -name "*.txt" => wildcards work too, finds all files/directories whose name ends with ".txt"
```

Flags:
    - `-H` - follow symbolic links specified directly on the command line, but not symlinks encountered during traversal
    - `-L` - follow all symlinks
    - `-P` - never follow symlinks (default)
    - `-D <debug>` - enable debugging information
    - `-00-03` - set query optimization level

> `-H`, `-L` and `-P` usually come _before the search path_

```bash
    find -L . -name "*.txt"
```

Controlling directory traversal:
| Option                   | Purpose                                                          |
| ------------------------ | ---------------------------------------------------------------- |
| `-maxdepth N`            | Descend at most `N` directory levels                             |
| `-mindepth N`            | Don't examine entries shallower than `N`                         |
| `-depth`                 | Process directory contents before the directory itself           |
| `-xdev`                  | Don't cross into other mounted filesystems                       |
| `-mount`                 | Same as `-xdev`                                                  |
| `-noleaf`                | Disable GNU `find`'s directory-link optimization                 |
| `-ignore_readdir_race`   | Ignore certain errors caused by files disappearing during search |
| `-noignore_readdir_race` | Disable the above behavior                                       |

```bash
    find. -maxdepth 2 -type f
```

Most often used search params:
| Option / expression | What it does                              | Example                                |
| ------------------- | ----------------------------------------- | -------------------------------------- |
| `-name`             | Find by name                              | `find . -name "*.txt"`                 |
| `-iname`            | Find by name, case-insensitive            | `find . -iname "*.jpg"`                |
| `-type f`           | Only regular files                        | `find . -type f`                       |
| `-type d`           | Only directories                          | `find . -type d`                       |
| `-size`             | Find by size                              | `find . -size +100M`                   |
| `-mtime`            | Find by modification time in days         | `find . -mtime -7`                     |
| `-mmin`             | Find by modification time in minutes      | `find . -mmin -30`                     |
| `-maxdepth`         | Limit how deep `find` searches            | `find . -maxdepth 2`                   |
| `-mindepth`         | Skip the first N directory levels         | `find . -mindepth 2`                   |
| `-empty`            | Find empty files/directories              | `find . -type f -empty`                |
| `-perm`             | Find by permissions                       | `find . -perm 755`                     |
| `-user`             | Find files owned by a user                | `find . -user john`                    |
| `-newer`            | Find files newer than another file        | `find . -newer file.txt`               |
| `-path`             | Match against the whole path              | `find . -path "*/src/*.c"`             |
| `-delete`           | Delete matching results                   | `find . -name "*.tmp" -delete`         |
| `-exec`             | Run another command on results            | `find . -name "*.txt" -exec cat {} \;` |
| `-print`            | Print matching paths                      | `find . -name "*.txt" -print`          |
| `-print0`           | Print safely for piping to other commands | `find . -type f -print0`               |
| `-o`                | OR between conditions                     | `find . -name "*.c" -o -name "*.h"`    |
| `!`                 | NOT / exclude something                   | `find . ! -name "*.txt"`               |


Search by type:

| Type | Meaning          |
| ---- | ---------------- |
| `f`  | Regular file     |
| `d`  | Directory        |
| `l`  | Symbolic link    |
| `b`  | Block device     |
| `c`  | Character device |
| `p`  | Named pipe/FIFO  |
| `s`  | Socket           |

Search by size:

| Syntax     | Meaning         |
| ---------- | --------------- |
| `-size N`  | Exactly N units |
| `-size +N` | Greater than N  |
| `-size -N` | Less than N     |

Units:

| Unit | Meaning         |
| ---- | --------------- |
| `c`  | Bytes           |
| `w`  | 2-byte words    |
| `b`  | 512-byte blocks |
| `k`  | KiB             |
| `M`  | MiB             |
| `G`  | GiB             |

Seach by modificaton/access/change time

```bash
    find . -mtime -7
```

Modification time:

| Test        | Meaning                       |
| ----------- | ----------------------------- |
| `-mtime N`  | Modified N days ago           |
| `-mtime -N` | Modified less than N days ago |
| `-mtime +N` | Modified more than N days ago |
| `-mmin N`   | Same idea, but minutes        |

Access time:

```bash
    find . -atime -7
    find . -amin -30
```

Change time:

```bash
    find . -ctime -7
    find . -cmin -30
```

Searching by permissions:

```bash
    find . -perm 755


Several forms:
    -perm MODE
    -perm -MODE
    -perm /MODE
```

Searching by ownership:

| Test          | Purpose                        |
| ------------- | ------------------------------ |
| `-user NAME`  | Owned by user                  |
| `-uid N`      | Owned by numeric UID           |
| `-group NAME` | Owned by group                 |
| `-gid N`      | Owned by numeric GID           |
| `-nouser`     | UID has no corresponding user  |
| `-nogroup`    | GID has no corresponding group |



> There are many more options
