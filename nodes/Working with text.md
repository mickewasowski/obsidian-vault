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



