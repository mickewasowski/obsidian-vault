---
aliases:
context:
---

# wc

`wc` stands for *word count* and it's used to count lines, workds, characters, and bytes in files or input.

---
### Basic usage

Useful when working with text files, logs and shell scripts.

Syntax:
```bash
wc employees.txt

# result
# 5  20  145 employees.txt
```
- `5` - lines
- `20` - words
- `145` - bytes

### Options

Most useful flags:
- `-l` - count lines
- `-w` - count words
- `-c` - count bytes
- `-m` - count characters
- `-L` - length of the longest line

> You can also combine flags: `wc -Lw employees.txt`


### Combining wc with other commands

```bash
# count files in a directory (counts the number of entries returned by ls)
ls | wc -l

# count employees in a text file
cat employees.txt | wc -l

# count how many employees are Developers
awk '$3 == "Developer"' | wc -l

# count how many times a word appears
grep -o "Developer" employees.txt | wc -l
```
- `grep -o` - prints each individual match on a separate line


### Useful

- `wc` - reads from files or standard input
- `wc -l` - counts newline characters, not necessarily logical records *a final line without a new line may not be counted*
- `wc -c` - counts bytes, while `wc -m` counts characters, these can differ with UTF-8 text


### Exercises

Create file:
```bash
cat > employees.txt <<'EOF'
John 25 Developer 3500
Alice 30 Designer 3000
Bob 22 Developer 2800
Sarah 35 Manager 5000
Mike 28 Developer 4000
EOF
```

[x] 1. count the total number of lines in employees.txt
```bash
wc -l employees.txt
```

[x] 2. count the total number of words
```bash
wc -w employees.txt
```

[x] 3. find the length of the longest line
```bash
wc -L employees.txt
```

[x] 4. count how many employees are Developers using awk and wc
```bash
awk '$3 == "Developer"' employees.txt | wc -l

```

[x] 5. find the number of bytes in the file
```bash
wc -c employees.txt
```

[x] 6. count the number of lines without using wc's default output format
```bash
wc employees.txt
```

[x] 7. count how many employees are Managers
```bash
awk '$3 == "Manager"' employees.txt | wc -l
```

[x] 8. count how many employees are younger than 30
```bash
awk '$2 < 30' employees.txt | wc -l
```

[x] 9. count how many employees have the word `Designer` in their line
```bash
awk '/Designer/' employees.txt | wc -l
```

[] 10. count the number of unique job titles in the file
```bash
# wrong
# uniq | awk '{print $3}' employees.txt | wc -l
```

[] 11. count how many employees remain after excluding Managers

[] 12. find the job with the most employees

[] 13. count how many employees earn between 4500 and 6000 (inclusive)

[] 14. count how many employees have names starting with M

[] 15. count the number of employees after sorting the file by salary

[] 16. write a single command that: finds all employees younger than 30, extracts only their job titles, counts how many employees belong to each job title
```bash
# expected output
# Developer  3
# Designer   1
```

