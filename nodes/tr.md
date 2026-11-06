---
aliases:
context:
---

# tr

---
`tr` command in Unix-like OS is used to translate or delete characters.
It reads from stdin and writes to stdout.
*replace, delete or squeeze characters* from text.
Often used to convert uppercase or lowercase, delete characters, or replace one set of characters with another.
> `tr` cannot read from a file, that is why its often used with pipes and redirects.

Syntax:
```bash
tr [options] SET1 [SET2]
```

- `SET1` - characters you want to replace, delete, or squeeze
- `SET2` - replacement characters
- `OPTIONS` - flags that change the behavior

> running `tr` with no options replaces characters specified in `SET1` with the characters from `SET2` that have the same position
> **every occurence is replaced**
> the characters in SET1 are matched by position with those in SET2

Example:
```bash
echo "Welcome" | tr e o
# Wolcomo
```

> `tr` operates on individual characters

Convert lowercase to uppercase
```bash
# regular expression (regex)
echo "hello world" | tr 'a-z' 'A-Z'

# you can also use character classes:
echo "hello world" | tr '[:lower:]' '[:upper:]'
```

- `-d` - deleting characters
```bash
echo "hello world" | tr -d 'o'
echo "hello world" | tr -d 'eol'

# delete digits
echo "hello world" | tr -d '0-9'
```

- `-s` - squeezing repeated characters
```bash
echo "heeeelloooo woooorld" | tr -s 'elo'


# remove extra spaces
echo "hello    world" | tr -s ' '
```

- `-c` - complementing characters (means everything **except** the specified characters)
```bash
echo "abs1241agf324" | tr -cd '0-9'
```

```bash
# replace delimiters in csv file
John,25,London

echo 'John,25,London' | tr ',' '\t'

echo 'apple:banana:orange' | tr ':' '\n'
```

- `tr` doesn't work with filenames as input arguments, we use redirects or pipes
```bash
tr 'a-z' 'A-Z' < names.txt

cat names.txt | tr 'a-z' 'A-Z'
```
