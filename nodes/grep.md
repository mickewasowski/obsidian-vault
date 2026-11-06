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

Command-line tool for searching plain-text in files and streams of data by a regular expression.

`grep` - globally search a regular expression and print

Used to search for text patterns within files.

```bash
grep "pattern" filename
```

Flags:
- `-i` - ignore case differences
- `-r` - search through all files in a directory or subdirectories
- `-v` - (invert match) find lines that do not match the pattern (*this one works only with files*)

```bash
grep -flag "pattern" filename

grep '^[A-Za-z]' filename  => line that starts with text
grep '^[0-9]' filename   => line that starts with numbers
```
