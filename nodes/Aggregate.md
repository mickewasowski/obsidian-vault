---
aliases:
context:
- "[[SQL]]"
---

# Aggregate

Aggregates are functions used to perform calculations and return a single value.

---
### Most common:
1. COUNT() - returns the number of rows
2. MAX() - returns the largest value in the column
3. MIN() - returns the smallest value in the column
4. SUM() - returns the total sum of a column
5. AVG() - returns the average value in a column


### COUNT

> counts every row in the table
``` SQL
SELECT COUNT(*) FROM table_name;
```


### MIN

> select the min value in a column
``` SQL
SELECT MIN(column1) FROM table_name;
```

### MAX

> select the max value in a column
``` SQL
SELECT column1, MAX(column2) FROM table_name;
```

### SUM

> sum of a column
``` SQL
SELECT SUM(column1) FROM table_name;
```

### AVG

> select the average value from a column
``` SQL
SELECT AVG(column) FROM table_name;
```

### GROUP BY - groups rows of data with the same values into buckets. It's often used with aggregate functions to group the results by one or more columns.

> groups data into two columns where the second one is the count
``` SQL
SELECT column1, COUNT(*) FROM table_name GROUP BY column1;
```
