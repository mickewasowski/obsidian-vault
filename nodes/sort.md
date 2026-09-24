---
aliases:
context:
- "[[Shell fundamentals]]"
---

# sort

Used to sort input in linux

---

### sort data and count unique entries

```bash
    sort users.txt | uniq -c
```

In the above example we don't need to provide the sort command again after the pipe because the two commands are connected:
```bash
    users.txt
       ↓
     sort
       ↓
    sorted output
       ↓
       |
       ↓
    uniq -c
       ↓
    counted output
```
> also `uniq` is a standalone command in linux and with `-c` it simply counts consecutive duplicate lines


