---
aliases:
context:
- "[[SQL]]"
---

# SQL Select

Retrieve information from table/tables.

---
### Basics
SQL statements (queries) are instructions that the database understands.

> selecting from a table:
``` sql
SELECT * FROM table_name;
```
* -> wild, means select everything from every column of the table

> select specific columns
``` sql
SELECT column1, column2, column3 FROM table_name;
```

> select unique values
``` sql
SELECT DISTINCT column1 FROM table_name;
```

### WHERE - used to filter information

> filter based on id
``` sql
SELECT * FROM table_name WHERE id = 123;
```

> [!Tip] Comparison operators
> = equal to
> != not equal to
> \> greater than
> < less than
> \>= greater or equal to
> <= less or equal to

### LIKE - used in where clause to match a pattern

> filter a column where the text in that column begins with 'T'
> % is a wildcard character - you can use it to select values that begin, end or contain a pattern
``` sql
SELECT * FROM table_name WHERE column1 LIKE 'T%';
SELECT * FROM table_name WHERE column1 LIKE '%the%'; // contains 'the'
```


### BETWEEN - used in where clause to filter the results in a certain range

> numbers - between is inclusive
``` sql
SELECT * FROM table_name WHERE column1 BETWEEN 2020 AND 2025; // inclusive
```

> strings - between stops at the second letter but doesn't include values that begin with it. So if a string is just 'D' it will be included, but if it's 'Dragon ball' it won't be returned.
``` sql
SELECT * FROM table_name WHERE column1 BETWEEN 'A' AND 'D'; // filters where the text begins with A to D (not inclusive for the second letter)
```

### ORDER BY - sorts data in ascending or descending order. (default is ascending)

> sort in ascending order the below
``` sql
SELECT * FROM table_name ORDER BY column1;
```

> sort in descending order
``` sql
SELECT * FROM table_name ORDER BY column1 DESC;
```
