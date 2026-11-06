---
aliases:
context:
---

# head and tail

---
Command-line utilities used to display the beggining or end of a file respectively.
`head` shows the first few lines
`tail` shows the last few lines


#### head

Displays the first 10 lines by default

*Options*:
- `-n` - displays the first n lines of a file
- `-c` - displays the first n bytes of a file

```bash
head -n 5 filename
```

View multiple files
```bash
head -n 3 file1 file2 file3
```
- `-q` - supresses the headings (file names) of files when viewing multiple files


#### tail

Displays the last part of a file

*Options*:
- `-n` - display n lines
- `-f` - follow the file as it grows (useful for monitoring log files in real-time)
- `-c` - display the last number of bytes
- `--pid=[pid]` - terminate after the process with pid dies
- `--retry` - keep trying to open a file even if its inaccessible

