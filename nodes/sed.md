---
aliases:
context:
- "[[Linux]]"
---

#wip

# sed

sed is for finding and replacing text in files or streams.

---
``` bash
sed 's/foo/bar/' file.txt
```
Replaces the *first* occurrence of foo with bar in each line of  file.txt

- s/foo/bar/g => replaces *all* occurrences on each line
- -i => edit file in-place

``` bash
sed -i 's/localhost/127.0.0.1/g' config.txt
```
Replaces *localhost* with *127.0.0.1* throughout the file.
