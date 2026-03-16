---
aliases:
context:
- "[[Working with files]]"
- "[[File Systems]]"
---

# inode

inode = index node

---
### Overview

An inode (index node) is a filesystem data structure that represents a file "object" on disk.

What it contains (typically):
    - metadata: owner (UID), group (GID), permissions (mode), file type (regular file/directory/symlink/etc.), timestamps (atime/mtime/ctime), size
    - pointers to the file's data blocks on disk (where the contents live)
    - link count: how many directory entries (hard links) currently point to this inode

What it does NOT contain:
    - the file name
    - the path
