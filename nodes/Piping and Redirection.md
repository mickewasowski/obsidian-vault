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
