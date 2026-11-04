---
aliases:
context:
- "[[Shell]]"
- "[[Linux]]"
---

# Working with text

View, search, transform, analyze and wildcards.

---

## View and Seach

### Grep

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


### less and more

Command line utilities used to view the contents of text files one file at a time.
They allow you to navigate through the files, search for specific patterns and perform some basic text manipulation tasks directly from the terminal.

#### less

`less` is generally more prefered than `more` because it offers more features and backwards scroll.
`less` does not read the entire file on start-up (unlike `vim` or `nano`) which results in a much faster load times.

Usage:
```bash
less [options] filename


ps aux | less  => forwards the command output of `ps` to less
// the above produces a very long output
```
`ps` - displays information about a selection of the active processes

*Options*:
- `-N` - shows line numbers
- `-X` - leaves the contents of the file in the terminal (by default when you exit less the contents are cleared from the screen)
- `+F` - tells less to watch the file for changes
> `Ctrl + C` stops following the file for updates and restores normal navigation
- `F` - pressing this at any time in the file starts watching the file for changes
- `-S` - instead of wrapping long lines it chops them at the end of the screen (you can use left/right arrows to scroll the screen)
- `-I` - ignores case when searching (by default search is case-sensitive)
- `-R` - colors the lines instead of showing the raw escape codes
- `n` and `N` - repeat the search respectively forwards and backwards

*Navigation*:
- `f` or `space bar` - next page
- number followed by `f` or `space bar` - moves down a number of lines
- `up arrow` or `down arrow` - to scroll line by line
- `b` - move back to the previous page
- number followed by `b` - moves up a specified number of lines
- `/` followed by a pattern - searches for that pattern in the file
- `?` followed by a pattern - searches backwards for that pattern
- `q` - exits less
- `g` - go to the first line of the file
- `G` - go to the last line of the file

> I noticed vim motions for up and down also work

```bash
less file1 file2 file3  => view multiple files
```
- `:n` - go to next file
- `:p` - go to previous file
- `:e filename` - open new file



#### more

Similarly to `less` allows you to view the contentx of text files one page at a time.

- forward navigation only
- cannot scroll backwards
- useful for reading logs, configuration files or command outputs
- you can search for a pattern by typing `/pattern`

*Navigation*:
- `enter` - scrolls down one line
- `down arrow` or `space bar` - scrolls down one page
- `q` - quits
- `=` - show current line number

*Options*:
- `-d` - prompt navigation help
- `-f` - disable line wrapping
- `-p` - clears the display before showing the next page
- `-c` - overlaps the new text over the old text providing a continuos reading
- `-s` - squeeze blank lines, compresses multiple blank lines into a single blank line
- `-u` - removes underlined characters
- `+/pattern` - used to search the text inside your document
- `+num` - displays the content starting from the specified line number


### head and tail

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


### [find](nodes/find.md)


### cut and paste

#### cut

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


#### paste

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


### join and split

#### join

`join` combines lines from two files based on a common field

You can think of `join` as a SQL `inner join`, for example:

In the below two files the first column is an ID
``` bash
# employees.csv
    1 John
    2 Alice
    3 Bob
```

```bash
# salaries.csv
    1 3000
    2 4000
    3 3500
```
When you run `join employees.csv salaries.csv` you get:
```bash
    1 John 3000
    2 Alice 4000
    3 Bob 3500
```
How that works is:
1. `join` reads both files
2. it compares the first field of each line by default
3. when the fields match, it combines the lines
4. the common field appears only once

> by default, both files must be sorted by their joining fields, and only matching lines are displayed

Options:
- `-1 N` - use field N from the first file
- `-2 N` - use field N from the second file
- `-t CHAR` - specify a field separator (this tells `join` that the fields are not separated by a whitespace e.g. space or a tab but by a comma)
- `-a 1` - also display unmatched lines from the first file
- `-a 2` - also display unmatched lines from the second file
- `-o` - choose which fields to output

```bash
# choose which fields to combine
join -o 1.2,1.3,2.1,2.3 employees.csv salaries.csv
# gets the second and third fields from the first file
# and the first and third fields from the second file
```

```bash
# this joins two comman-separated files using their first fields

join -t ',' employees.csv salaries.csv
```

Supported file types:
- `txt`
- `csv`
- `tsv`
- `log`

> `join` works with *plain-text files containing structured data*, where each line represents a record and fields are separated by a delimiter
> It doesn't care about the file extension. It cares about *how the data is formatted*


#### split

`split` breaks one large file into multiple smaller files

Suppose you have a file called `logs.txt` containing 1000 lines.
If you want to split it into files containing 200 lines each you'd run:
```bash
    split -l 200 logs.txt
```

How it works:
1. `split` reads the original file
2. it divides its contents into smaller chunks
3. it writes each chunk to a separate file
4. the original file remains unchanged


Options:
- `-l N` - split every N lines (by default the names will begin with `x` e.g. `xaa`, `xab`, `xac`, etc)
- `-b SIZE` - split by size in bytes
- `-n N` - split into N chunks
- `-d` - use numeric suffixes instead of letters
- `-a N` - set the suffix length

Examples:
```bash
# split into 10 MB chunks
split -b 10M largefile.txt

# split into exactly 4 files
split -n 4 logs.txt

# use a custom prefix (for the new file names) and numeric suffixes
split -l 100 -d logs.txt part_
# essentially the above would produce files like:
# part_00
# part_01
# part_02
```

How to combine split files again:
```bash
cat part_* > restored.txt
```

Comparing if two files are identical:
```bash
# if the two files ARE identical the command will produce NO output
cmp file1.txt file2.txt
```

Check file sizes:
```bash
# the below will list the file sizes of every file in the directory
wc -c *
```


### tr (translate)

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


### sed (Stream EDitor)

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











