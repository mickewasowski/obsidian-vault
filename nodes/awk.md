---
aliases:
context:
- ""
- ""
---

# awk

awk is like a mini scripting language for analyzing and transforming text, especially in columns.

---
``` shell
awk '{print $1, $3}' data.txt
```
The above command prints the first and third column of each line in data.txt

``` shell
df -h | awk '{print $1, $5}'
```
Shows disk name and usage percentage.


### What is awk

`awk` is command-line tool used to **search, filter, extract, and manipulate text**, especially when working with structured data such as CSV files, logs, and command output.


> You can think of `awk` as a combination of `grep`, `cut` and parts of `sed`, with additional programming capabilities.
> The biggest difference is that `awk` understands fields (columns) and records (lines).

Syntax:
```bash
awk 'pattern { action }' filename
```

- `pattern` - determines which lines to process
- `action` - determines what to do with matching lines
- `filename` - the input file
> Both `pattern` and `action` are optional in certain forms.


### Understanding fields and records

By default, `awk` treats:
- each line as a *record*
- each whitespace-separated value as a *field*


```bash
# John 25 Developer 3500
#  $1  $2  $3       $4
```
- `$0` represents the entire record `John 25 Developer 3500`

```bash
# print only the names
awk '{print $1}' employees.txt

# print names and salaries
awk '{print $1, $4}' employees.txt
```
> `print` automatically separates the arguments with a space


### Filtering records

You can use conditions to select which lines should be processed.

```bash
# employees older than 28
awk '$2 > 28 {print $1, $2}' employees.txt

# employees earning at least 3500
awk '$4 >= 3500' employees.txt
```
> When you omit the action, `awk` automatically prints the entire matching line


### Filtering using text patterns

Similar to `grep`, `awk` supports regular expressions.

```bash
# prints all lines containing Developer
awk '/Developer/' employees.txt

# search within a specific field
# matches only records where the third field is exactly Developer
awk '$3 == "Developer"' employees.txt

# print employees whose names begin with A
awk '$1 ~ /^A/' employees.txt
```


### Using multiple conditions

`awk` supports logical operators

- `&&` AND
- `\|\|` OR
- `!` NOT
- `==` equal
- `!=` not equal
- `>` greater than
- `<` less than
- `>=` greater than or equal
- `<=` less than or equal

```bash
# print developers earning more then 3000
awk '$3 == "Developer" && $4 > 3000' employees.txt
```


### Built-in variables

`awk` provides several useful variables:
- `NR` - current record number (across all input files)
- `FNR` - current record number within the current file
- `NF` - number of fields in the current record
- `FS` - input field separator
- `OFS` - output field separator
- `RS` - input record separator
- `ORS` - output record separator


```bash
# prints the line number and the field contents
awk '{print NR, $1}' employees.txt

# print the last field of each line
awk '{print $NF}' employees.txt
```
> `NF` contains the number of the fields, so `$NF` references the last field


### Working with CSV files

By default, `awk` separates fields using whitespace.
For comma-separated data, use `-F` to secify a delimiter

```bash
# reads the comma delimiter and prints first and third columns (fields)
awk -F ',' '{print $1, $3}' employees.csv

# change the output separator
awk -F ',' 'BEGIN {OFS=" | " {print $1, $3}}' employees.csv
```
> Note that `-F ','` works for simple CSV files, but it doesn't correctly parse every CSV format, such as quoted fields containing commas


### BEGIN and END blocks

Unlike `grep` and `cut`, `awk` can execute code before and after processing the input.

`BEGIN` - executed once before reading input
`END` - executed once after all input is processed


```bash
awk '
BEGIN {print "Employee Salaries"}
{print $1, $4}
END {print "Finished"}
' employees.txt

# result
# Employee Salaries
# John 3500
# Alice 3000
# Bob 2800
# Sarah 5000
# Mike 4000
# Finished
```

### Performing calculations

One of `awk`'s most useful capabilities is performing calculations across records.

```bash
# calculate the total salary
awk '{total += $4} END {print total}' employees.txt

# calculate average salary
awk '{sum += $4} END {print sum / NR}' employees.txt
# here NR is the number of processed records
```


### Modifying output

`awk` can transform data as well

```bash
# changes the fourth field in memory, it does not modify the original file
awk '{$4 = $4 * 1.10; print}' employees.txt

# formatted output
awk '{printf "%-10s %8.2f\n", $1, $4}' employees.txt
```


### Using awk with pipes

`awk` works with standard input

```bash
# prints the process that uses more than 5% cpu
ps aux | awk '$3 > 5 {print $1, $2, $3}'

# print filesystem names and their disk usage percentages
df -h | awk 'NR > 1 {print $1, $5}'
```


### When to use `awk`

- `grep` - finding lines matching a pattern
- `cut` - extracting fields by delimiter or character position
- `sed` - editing and transforming text streams
- `awk` - field-based filtering, calculations, and structured text processing


### Exercises

Sample data:
```bash
cat > employees.txt <<'EOF'
John 25 Developer 3500
Alice 30 Designer 3000
Bob 22 Developer 2800
Sarah 35 Manager 5000
Mike 28 Developer 4000
EOF
```

1. print only the names and job titles of all employees
2. print all employees younger than 30
3. print only the names of employees who are Developers
4. print each employee's name followed by their salary, separated by a colon (:)
5. print the total number of employees using NR
6. calculate the total salary paid to Developers only
7. print the name of the employee with the highest salary
8. print employees earning more than 3000, including a line number before each result
