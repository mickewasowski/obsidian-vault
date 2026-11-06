---
aliases:
context:
---

# sed

sed is for finding and replacing text in files or streams.

---
``` bash
sed 's/foo/bar/' file.txt
```
Replaces the *first* occurrence of foo with bar in each line of  file.txt

- s/foo/bar/g => replaces *all* occurrences on each line
- -i => edit file in-place

``` bash
sed -i 's/localhost/127.0.0.1/g' config.txt
```
Replaces *localhost* with *127.0.0.1* throughout the file.

`sed` is used to search, replace, delete, insert, and modify text in files or from standard input.

> `sed` processes text automatically, making it particularly useful in shell scripts and pipelines


Syntax:
```bash
sed [options] 'command' filename
```

##### search and replace (`s`)
The substitution syntax is: `s/pattern/replacement/flags`

- `s` - substitution command
- `pattern` - text to search for
- `replacement` - new text
- `flags` - optional modifiers

> By default, `sed` replaces only the first occurence on each line

```bash
# users.txt
# Alice is 25
# Bob is 30
# Charlie is 35
# Alice is 28

sed 's/Alice/John/' users.txt
# result
# John is 25
# Bob is 30
# Charlie is 35
# John is 28
```

##### `g` - replace **all** occurences
```bash
# apple banana apple

echo "apple banana apple" | sed 's/apple/mango/g'
# mango banana mango
```

##### `I` - ignore case
```bash
# APPLE banana apple

echo "apple banana apple" | sed 's/apple/mango/gI'
# mango banana mango
```

##### `p` - print specific lines
```bash
sed -n '2p' users.txt
```
- `-n` - suppresses automatic printing
- `2` - specifies line number 2
- `p` - explicitly prints the selected line


```bash
# print range
sed -n '2,3p' users.txt
```
> without `-n` matching lines would be printed twice because `sed` automatically prints each processed line


##### `d` - delete lines
```bash
# delete single line
sed '2d' users.txt

# delete range
sed '2,3d' users.txt

# delete lines containing particular pattern
sed '/Alice/d' users.txt
```


##### `i` and `a` - insert and append text
> `sed` supports inserting lines before or after a specified line
```bash
# insert before
sed '2i New user' users.txt

# append after
sed '2a New user' users.txt
```

##### `-i` - modify files directly
> by default, `sed` does not modify the original file
```bash
# this prints the modified content but leaves users.txt unchanged
sed 's/Alice/John/g' users.txt

# actually modify the file
sed -i 's/Alice/John/g' users.txt

# create a backup
sed -i.bak 's/Alice/John/g' users.txt
```

##### use `sed` with regular expressions
```bash
# replaces all digits with X
echo "Alice 25 Bob 30" | sed 's/[0-9]/X/g'

# replace multiple consecutive spaces
echo "Hello    World" | sed 's/  */ /g'
```
> the pattern `  *` means one literal space followed by zero or more spaces

```bash
# with GNU you can also use:
sed -E 's/ +/ /g'
```
> `-E` enables extended regular expressions, where `+` means one or more occurences

```bash
# remove leading white space
echo "    Hello World" | sed 's/^[[:space:]]*//'
```
- `^` matches the beggining of a line
- `[[:space:]]` matches whitespace characters
- `*` means zero or more occurences

```bash
# remove trailing whitespace
sed 's/[[:space:]]*$//' users.txt
```
- `$` matches the end of a line

- `sed` can read from stdin
```bash
cat users.txt | sed 's/Alice/John/g'

grep "Alice" users.txt | sed 's/Alice/John/'
```

##### combine `sed` commands
```bash
sed -e 's/Alice/John/g' -e 's/Bob/Mike/g' users.txt
```

##### separate `sed` commands with semicolons
```bash
sed 's/Alice/John/g; s/Bob/Mike/g' users.txt
```

##### Commands and Options:
- `s` substitute text
- `g` replace all matches per line
- `p` print selected lines
- `d` delete lines
- `i` insert text before a line
- `a` append text after a line
- `c` replace an entire line
- `-n` suppress automatic printing
- `-i` edit the file in place
- `-E` enable extended regular expressions
- `-e` specify an editing command


How `sed` works:
1. reads one line into an internal buffer called the *pattern space*
(*pattern space* is a temporary buffer or memory area where `sed` stores the line it's currently processing)
2. executes the specified commands
3. prints the resulting text, unless printing is suppressed or the line is deleted
4. repeats for the next line

> e.g. `sed` executes the command line by line and prints each result after each execution


`sed` vs `grep` vs `cut` vs `tr`
- `grep` find lines matching patterns
- `cut` extract columns or fields
- `tr` translate or delete individual characters
- `sed` edit text using patterns and commands

##### Exercises

```bash
# replace the Alice occurence on the fifth line
sed '5s/Alice/Anna' employees.txt


# append after the last line (here the $ means the last line)
sed '$a George,Tester,3100,Sofia' employees.txt


# delete the digits and the predecending comma (// means empty replacement)
sed -E 's/,[0-9]+//g' employees.txt


# print only selected lines (filter)
sed -n '/Developer/{s/Developer/Engineer/g; s/Sofia/SOF/g; p;}' employees.txt
```
- `{...}` groups commands together and applies them only to lines matching `/Developer/`. Inside the group, we first make both substitutions, then print the modified pattern space

Alternative:
```bash
sed '/Developer/!d; s/Developer/Engineer/g; s/Sofia/SOF/g' employees.txt
```
- `/Developer/!d;` - means delete lines that **do not** contain `Developer`
