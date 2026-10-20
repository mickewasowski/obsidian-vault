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

```bash
    find . -name "*linux*"  => find files with names that include linux

    find . -name "linux*"  => find files with names that start with linux
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


Search for directories excluding the starting directory:
```bash
find . -mindepth 1 -type d
```


Search by multiple conditions:

```bash
find . -name "*.log" -o -name "*.json"
```

- `-o` - logical or operator


Search for file type with excluding a directory:
```bash
find . -name "*.txt" ! -path ./backup
```
> `-path ./backup` excludes the directory but NOT the files inside it
the above search for all txt files but excludes backup directory from the search

the below is the correct way to exclude the directory AND its contents
```bash
find . -type f -name "*.txt" -not -path "./backup/*"


// most efficient way:
find . -path "./backup" -prune -o -type f -name "*.txt" -print
```


Seach for a regular file with size greater than 1MB:
```bash
find . -type f -size +1M
```


Seach for files modified in the last 24 hours:
```bash
find . -mtime -1
```

Find every log file and execute `wc -l` to count the number of matching files:
```bash
find . -name "*.log" | wc -l
```

Find every log file and execute `wc -l` to count the number of lines in those files:
```bash
find . -type f -name "*.log" -exec wc -l {} \;
```
- `-exec` - executes a command for each matching file
- `{}` - represents the matching file's path
- `\;` - terminates the `-exec` command
> in the above the `wc -l` command is invoked once per file
> in the below the `+` passes multiple files in batches to `wc`:
```bash
find . -type f -name "*.log" -exec wc -l {} +
```


Find every empty txt file:
```bash
find . -empty -name "*.txt"
```


Find every empty txt file and delete it:
```bash
find . -empty -name "*.txt" -delete
```

### additional commands

- `-prune` (meaning trim, cutoff, remove) - the find command combined with `-prune` is used to exclude specific directories from the search and prevent the command from descending into them

Syntax:
```bash
find [path] [conditions to prune] -prune -o [actions to perform]
```

- prune stops find from recursing into the matched directory but does not exclude it from the output by default
- `-o` (OR) - used to specify what to do with the remaining files
- `-print` - often required at the end to print the files that were not pruned

Examples:
```bash
// exclude a single directory and print files
find . -name ".git" -prune -o -type f -print

// exclude multiple directories
find . \( -name ".git" -o -name "node_modules" \) -prune -o -type f -print

// exclude by path pattern
find . -path "./.svn/*" -prune -o -print
```


- `-exec` - allows you to execute a specified utility on every file or directory found by the `find` command

Syntax:
``` bash
find . -type f -name "*.txt" -exec cat {} \;

find . -type f -name "*.txt" -exec rm {} +
```
- `\;` (semicolon) - executes the command *once for each file found* (useful for commands that do not accept multiple arguments or require individual processing)
- `+` - executes the command *once for all files found* (useful for large number of files); **`{}` must be the last argument before** `+`
- `{}` - placeholder for the current file's path


### logical operators

- `-o` or `-or` - logical `or`
```bash
find /path \( -name "*.txt" -o -name "*.log" \)
```

- `-a` or `-and` - logical `and` (`and` is implicit and has higher precedence to `or`)
grouping is important (the parenthesis) because it makes two or more conditions act as a single group
```bash
find /path \( -name "*.txt" -o -name "*.log" \) -size +1M

// the above is equivalent to:
find /path \( -name "*.txt" -o -name "*.log" \) -a -size +1M


// without the parenthesis the first expression would be:
find /path -name "*.txt" -o -name "*.log" -size +1M
// and it would be interpreted as *(name is *.txt) OR (name is *.log AND size > 1M)*
```

- `!` or `-not` - logical `not`
```bash
find /path ! -name "*.tmp"
```
