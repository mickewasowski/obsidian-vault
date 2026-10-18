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

### less

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



### more

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

