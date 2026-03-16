---
aliases:
context:
- "[[Linux]]"
- "[[Operating Systems]]"
- "[[File Systems]]"
---

# Hard Link

A Hard Link is another name for the same file data on disk.

---

### Overview

- every file is stored as an [[inode]] (a structure containing metadata + pointers to data)
- a hard link points **directly to that inode**
- multiple hard links = multiple filenames pointing to the **same underlying data**


### Key properties

- deleting the "original" file **does NOT** delete the data (as long as at least one hard link exists)
- all hard links are **equal** - there's no "original" vs "copy"
- cannot link:
    - across different filesystems
    -  typically connot link directories (to avoid loops)


### Example

```bash
ln file.txt hardlink.txt
```

>[!warning] If you change the file from which you created the hardlink by modifying its contents in place (append, truncate, overwrite), you're changing the inode's data. Since both names point to the same inode, the change is visible through both `file.txt` and `hardlink.txt` immediately.
> The main caveat: some programs don't edit in place. They do "safe save" (write a new temp file, then `rename()` it over the original). In that case:
>   - `file.txt` is replaced to point to a *new inode*
>   - `hardlink.txt` still points to the *old inode* (old contents)
>   - from then on the two files diverge
