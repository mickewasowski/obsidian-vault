---
aliases:
context:
    - "[[Linux]]"
---

#wip

# Text processing

Manipulate, search, filter and format text files.

---

[[cat]]


### `echo` - used to print text

It is a very simple command that prints what you tell it to.

`echo Hello` -> prints back Hello

> Common uses

- display text
``` bash
echo "Some text"
```

- showing variable values
``` bash
name="Alice"
echo $name
```

- writing to files

This creates (or overwrites) `file.txt` with the text
``` bash
echo "Hello world!" > file.txt
```

This **appends** to the file instead of overwriting
``` bash
echo "Testing" >> file.txt
```

> Options

`-n` - no new lines, prevents new lines at the end
`-e` - enables escape sequences, lets you use special characters
