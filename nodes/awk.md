---
aliases:
context:
- "[[Linux]]"
---

#wip

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