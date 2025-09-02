---
aliases:
context:
- "[[Linux]]"
---


# File permissions

File permissions in Linux, how they are listed and modifying them.

---
## File permissions

Linux file permissions control read (r), write (w), and execute (x) access of owner, group, and others using octal or symbolic notation.
Format: `-rwxr--r--` shows file type and permissions

Use `chmod` to change permissions
Use `chown` to chage ownership
Use `chgrp` to change group ownership

The permissions are divided by _triplets_ for each - owner, group and others (in this order)
-rw-r--r-- 12 linuxize users 12.0K Apr 28 10:10 file_name
O G Others
|[-][-][-]- [------] [---]
| | | | | | |
| | | | | | +-----------> 7. Group
| | | | | +-------------------> 6. Owner
| | | | +--------------------------> 5. Alternate Access Method
| | | +----------------------------> 4. **Others Permissions**
| | +-------------------------------> 3. **Group Permissions**
| +----------------------------------> 2. **Owner Permissions**
+------------------------------------> 1. File Type

The file type can be either `-` (regular file), `d` (directory), or a symbolic link `l`, or other special types of files.

## Effect of Permissions on files

| Permission | Character | Meaning on File                                                                                                                                                                                                         |
| ---------- | --------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Read       | `-`       | the file is not readable. you cannot view the file contents.                                                                                                                                                            |
|            | `r`       | the file is readable                                                                                                                                                                                                    |
| Write      | `-`       | the file cannot be changed or modified                                                                                                                                                                                  |
|            | `w`       | the file can be changed or modified                                                                                                                                                                                     |
| Execute    | `-`       | the file cannot be executed                                                                                                                                                                                             |
|            | `x`       | the file can be executed                                                                                                                                                                                                |
|            | `s`       | if in the user triplet sets the `setuid` bit. if in the group sets the `setgid`. when the `setuid` or `setgid` flags are set on an executable file, the file is executed with the file's owner and/or group privileges. |
|            | `S`       | same as `s`, but the `x` flag is not set. this flag is rarely used on files.                                                                                                                                            |
|            | `t`       | if set on others triplet sets the `sticky` bit. it also means that `x` flag is set. this flag is useless on files.                                                                                                      |
|            | `T`       | same as `t` but the `x` is not set. again useless on files.                                                                                                                                                             |

## Effect of permissions on directories (folders)

| Permission | Character | Meaning on Directory                                                                                                                                             |
| ---------- | --------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Read       | `-`       | directory cannot be listed. you cannot see the names of the files inside (but you might still access them if you know the exact name and have `x`).              |
|            | `r`       | directory can be listed. you can see the names of the files inside (but you still need `x` to actually access them).                                             |
| Write      | `-`       | you cannot create, delete, or rename files inside this directory.                                                                                                |
|            | `w`       | you can create, delete, and rename files inside this directory (but you still need `x` to perform those actions).                                                |
| Execute    | `-`       | you cannot access files or subdirectories inside this directory, even if you know their names.                                                                   |
|            | `x`       | you can access files and subdirectories inside this directory (enter with `cd`, open files by name), but you cannot list them unless `r` is also set.            |
|            | `s`       | setuid bit (ignored on directories in Linux).                                                                                                                    |
|            | `S`       | same as above — ignored on directories.                                                                                                                          |
|            | `g+s`     | setgid bit. new files/subdirectories created inside inherit the group of the directory, rather than the user’s default group.                                    |
|            | `t`       | sticky bit. users can only delete or rename their own files inside this directory, even if they have write permission on the directory. commonly used on `/tmp`. |
|            | `T`       | sticky bit set but `x` missing (rare, mostly meaningless on directories).                                                                                        |
