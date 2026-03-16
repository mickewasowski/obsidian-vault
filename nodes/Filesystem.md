---
aliases:
context:
- "[[File Systems]]"
---

# Filesystem

A Filesystem is a set of on-disk data structures that describe what data exists on disk and where it lives.

---

### Overview

A useful mental model picture (Unix-like filesystems):
- directories - tables of `filename -> inode number` these are the directory entries
- inode table - a big table of inodes; each [[inode]] holds metadata + where the file's data blocks/extents lives on disk
- data area - the actual file contents (blocks/extents) on disk
- allocation metadata - bookkeeping for which inodes/blocks are free or used (bitmaps, free lists, etc.)
- often - a journal/log (e.g. ext4, APFS) to make updates crash-safe


>[!tip] We can think of filesystems as "indexes + records" in a database: names map to records (inodes), and inodes map to the actual bytes

