---
aliases:
context:
---

# Piping and Redirection

Commands that allow you to combine commands and reroute their input and output

---

### Piping

Linking one command's output to another command's input

- lists the files in the directory and counts the lines (how many files there are)
```bash
    ls | wc -l
```

- transform text to uppercase
```bash
    echo "hello, world" | tr \[a-z\] \[A-Z\]
```


### Redirection

Redirection is a way of changing a command's default input or output

`>` vs `>>`
`>` - creates/overwrites a file
`>>` - creates or appends to a file


1. The Input operator - The Input operator gives input to a command or process (`<` - operator)
2. The Input operator (rw) - Does the same as the input operator only it opens the file in read/write mode. (`<>` - operator). If the file does not exist it will be created. (*this is rarely used*)
3. The Output operator - controls the command output stream. (`>`). If the file you are redirecting to does not exist, it will be created. If it does exist, it will be overwritten.


