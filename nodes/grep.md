---
aliases:
context:
- "[[Linux]]"
---

# grep

Stands for Global Regular Expression Print. It's used to find lines in files that match a pattern.

---
```
grep "error" logfile.txt
```
 The above command finds all lines containing "error" in logfile.txt

Common flags:
- -i => case-insensitive
- -r => recursive through directories
- -n => show line numbers
- -v => invert match (i.e., show lines *not* matching)