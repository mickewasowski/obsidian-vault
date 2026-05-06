---
aliases:
context:
---

# cat

Unix command for file concatenation and printing.

---
Used to concatenate files and print their contents to the standard output. It is often used to view the contents of files, combine multiple files, and create new files.

`cat file1.txt file2.txt` - this command combines the two files and prints their contents

> Options:
- `-n` - number of output lines
- `-s` - squeeze multiple adjacent blank lines into a single one

- merge files into one
``` bash
cat file1.txt file2.txt > file3.txt
```

- append file into another
``` bash
cat file1.txt >> file3.txt
```

- create a file with the bellow command, then type some lines, press `Enter`, and finish with `Ctrl + D`
``` bash
cat > newFile.txt
```

- show line numbers
``` bash
cat -n file1.txt
```

- show special characters - reveals tabs (`^I`), line endings (`$`), etc.
``` bash
cat -A file.txt
```
