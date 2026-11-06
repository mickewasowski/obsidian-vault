---
aliases:
context:
---

# cut

---
- `cut` - a command-line utility that allows you to cut parts of a line of text from specified files or piped data. can cut parts of a line by delimiter, byte position, and character

syntax:
```bash
cut OPTION... [FILE]...
```

flags:
- `-c` - extract characters by position
- `-b` - extract bytes by position
- `-f` - extract fields (columns)
- `-d` - specify the delimiter separating fields


Examples with characters:
```bash
    cut -c 1-3 names.txt    # extract the first 3 characters of each line
    cut -c 1 names.txt      # First character
    cut -c 2-5 names.txt    # Characters 2 through 5
    cut -c 4- names.txt     # From character 4 to the end
    cut -c -5 names.txt     # First 5 characters
    cut -c 1,3,5 names.txt  # Characters 1, 3 and 5
```
> [!warning] Positions start at `1` *not* `0`.


Examples with fields:
```bash
# sample data in users.csv
# john,25,developer
# alice,30,designer
# bob,28,engineer

    cut -d ',' -f 1 users.csv  # gets the data from the first field (column)
    cut -d ',' -f 2,3 users.csv  # extracts the data from the second and third fields

# specify ranges
    cut -d ',' -f 1-2 users.csv   # Fields 1 through 2
    cut -d ',' -f 2- users.csv    # Field 2 onward
    cut -d ',' -f 1,3 users.csv   # Fields 1 and 3
```
> [!warning] If you don't speicify `-d` the default delimiter is *tab*


Using `cut` with pipes:
```bash
    cat /etc/passwd | cut -d ':' -f 1
```

- `--complement` - extract everything except the selected fields or positions
- `-s` - suppress lines that don't contain the delimiter
- `--output-delimiter` - change the output delimiter
- `-z` - use *NUL* instead of newline as the line separator

Examples:
```bash
cut -d ',' -f 2 --complement users.csv
cut -d ',' -f 1,3 --output-delimiter=' | ' users.csv
```

> [!warning]
> `cut` doesn't support regex
> `-d` accepts only a single character
> it doesn't handle multiple consecutive spaces as a single delimiter
> it isn't a proper CSV parser, quoted commas can cause incorrect field extractions
> `-b` works with byte positions, which may differ from character positions in utf-8 text
