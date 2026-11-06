---
aliases:
context:
---

# join and split

---
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
