---
aliases:
context:
- "[[C lang]]"
---

# C lang - String

---

> C has no native string type.

A string in C is a contiguos array of char terminated by a null byte (\0, value 0).

```c
char s[] = "Hello";

// in memory this looks like so:
// 'H' 'e' 'l' 'l' 'o' '\0'
```
>[warning] The null terminator is mandatory, without it the data is not a string.
> buffer size − 1 = max string length
