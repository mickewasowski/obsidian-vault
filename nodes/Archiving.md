---
aliases:
context:
- "[[Linux]]"
---


# Archiving

Archiving is the process where multiple files and directories are combined into one file.Primarily useful for backups and simplification of distribution.

---
### Tools
- `tar`
- `gzip`
- `bzip2`

`tar` is a versatile tool that can manage and organize files into one archive.
`gzip` and `bzip2` are used for file compression, reducing the file size and making data transmission easier.


### `tar` commands

- create archive
`tar -cvf archive.tar files_or_dirs/`

- create compressed archive (`gzip`)
`tar -czvf archive.tar.gz files_or_dirs/`

- extract archive
`tar -xvf archive.tar`

- extract compressed archive (`gzip`)
`tar -xzvf archive.tar.gz`

- list contents without extracting
`tar -tvf archive.tar`

> Flags breakdown
`c` create
`x` extract
`t` list
`v` verbose (optional, shows names)
`f` file name follows
`z` gzip compression


### `gzip` commands - works on single files only (not directories)

- compress a file (produces `file.txt.gz`, original file is removed by default)
`gzip file.txt`

- decompress a file
`gunzip file.txt.gz`

- keep original file when compressing
`gzip -k file.txt`

- keep original file when decompressing
`gunzip -k file.txt.gz`

- test compressed file (check integrity)
`gzip -t file.txt.gz`

- compress with maximum compression
`gzip -9 file.txt`

- decompress with `gzip` directly
`gzip -d file.txt.gz`


### `bzip2` commands - works on single files only (not directories)

- compress a file (produces `file.txt.bz2`, original file is removed by default)
`bzip2 file.txt`

- decompress a file
`bunzip2 file.txt.bz2`

- keep original file when compressing
`bzip2 -k file.txt`

- keep original file when decompressing
`bunzip2 -k file.txt.bz2`

- test compressed file (check integrity)
`bzip2 -t file.txt.bz2`

- compress with maximum compression
`bzip2 -9 file.txt`

- compress with `bzip2` directly
`bzip2 -d file.txt.bz2`


> For compressing a directory use `tar` with `bzip2`/`gzip`
`tar -cjvf archive.tar.bz2 dir/`
