---
aliases:
context:
---

# paste

---
`paste` merges lines from files horizontally. It outputs lines from each file's corresponding lines, separated by tabs by default.

Syntax:
```bash
paste [OPTION]... [FILE]...
```

> If no input files are provided or `-` is used as an argument `paste` uses the standard input

```bash
paste file1 file2
# if no options are provided the two files will be merged horizontally separated by tab like so:

Iron Man	Black Widow
Thor	Captain Marvel
Captain America	Dark Phoenix
Hulk	Nebula
Spider Man
```

You can redirect the output to another file:
(**if the file doesn't exist it will be created**)
```bash
paste file1 file2 > file3
```

- `-d` and `--delimiters` can be used to specify a list of characters to be used instead of TAB

Each delimiter is consecutively used, when the list is exhausted `paste` starts from the beggining
```bash
paste -d '%|' file1 file2 file1

# the above produces:
Iron Man%Black Widow|Iron Man
Thor%Captain Marvel|Thor
Captain America%Dark Phoenix|Captain America
Hulk%Nebula|Hulk
Spider Man%|Spider Man
```


- `-s` or `--serial` joins all lines from each input file into a single line (with default delimiter `tab`); each file produces it's own line
```bash
paste -s file1 file2

# file1
# Iron Man	Thor	Captain America	Hulk	Spider Man
# file2
# Black Widow	Captain Marvel	Dark Phoenix	Nebula
```

- `-z` or `--zero-terminated` uses *null character* instead of the default `tab` delimiter


Exercises:

``` bash
# sort alphabetically and print on a single line with , separator

sort unsorted.txt | paste -sd ',' -
# here the - reads from the standard input
# the pipe `|` connects the two, the output of the sort becomes the input (standard input) of the paste
```
