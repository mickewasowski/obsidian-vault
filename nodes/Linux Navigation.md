---
aliases:
context:
- "[[Linux]]"
---

#wip

# Linux Navigation

Navigation between directories and files.

---

## Navigation

### `cd`
Lets you go into different folders.
top-most directory ("root") directory is referred to by a single leading slash "/".
An absolute path indicates the location of a directory in relation to this top-level directory.
*Every* absolute path **must** begin with "/".

The alternative is to use *relative paths*.
Relative paths refer to directories in relation to the current directory.
Any directory within the current directory can be referenced by name without a leading slash.

To go back to the parent of the current directory you can use '..' => `cd ..`

To return to the home directory you use `~` `cd ~`


### `ls`
Shows you what files and folders are inside.
You can add some optional flags to the command to modify the default behavior.
For instance:
> `-l` => list all of the contents in an extended form (file type and permissions, number of hard links to that file elsewhere on the system, owner, group owner, item size, date updated, name)
> file type and permissions => if it starts with 'd' then the item is a directory
> fily type and permissions => if it starts with "-" then it's a normal file

> `-a` => get a list of all files, including *hidden* files and directories

### `pwd`
Tells you where you are currently.

## Moving files and directories

### `mv`
`mv [options] source target` - Basic command syntax

- moving a single file `mv file.txt /path/to/destination/`
- moving multiple files to the same destination `mv file1.txt file2.txt file3.txt /path/to/destination/`
- moving a directory `mv my_directory /path/to/new/location/`

> Important options
- `-i` (interactive) - prompts before overwriting `mv -i file.txt /path/to/destination/`
- `-n` (no clobber) - prevents overwriting existing files `mv -n file.txt /path/to/destination/`
- `-v` (verbose) - shows what's being done `mv -v file.txt /path/to/destination/`
- `-u` (update) - moves only when source is newer than destination `mv -u file.txt /path/to/destination/`
- `-f` (force) - if the target file is write protected, you'll be asked to confirm before overwriting, with `-f` you can avoid this and overwrite straighaway `mv -f file1.txt target`

> Renaming files
- `mv oldname.txt newname.txt` - mv command can also be used to rename a file
- `mv source_file target_directory/target_file` - you can also move it somewhere else with a different name
- `mv source_directory path_to_non_existing_directory` - you can also move an entire directory and rename it at the same time, the only difference is that the target must not exist

> Wildcards
- `mv *.txt /path/to/destination/` - you can use wildcards to move multiple files

## Creating and deleting files

### touch command
`touch` command is the simplest way to create an empty file - `touch example.txt`
This command will also update the timestamp of the file if it already exists.


### echo
`echo` creates a file by redirecting output to it
`echo "Hello world!" > hello.txt` - this command creates a file with 'Hello world!'


### cat
`cat` creates file interactively
`cat > newfile.txt` - after executing this command you can type your contents and then save it with `Ctrl + D`

### rm
`rm` is the primary tool for removing files, it is more versatile and can be used to delete directories with the `-r` flag
`rm filename.txt`

> `-r` recursively deletes files and directories
`rm -r folderName`

> `-i` prompts you before each removal, useful when removing multiple files
`rm -i file.txt`

> `-v` (verbose) shows you what is being deleted
`rm -v file.txt`

> `-f` forces removal without prompting

> `*.txt` (wildcards)
`rm *.txt` - removes all text files


### rmdir
`rmdir` is used to remove directories, used specifically to remove *empty* directories (it cannot delete a directory that contains files)
`rmdir emptyFolder`

> if the directory contains files you need to use `rm` with `-r` flag (recursive)
`rm -r nonEmptyFolder`

> if you want to be prompted for confirmation use `-i`
`rm -ri nonEmptyFolder`


## Creating directories

### mkdir

> create directory
`mkdir` used to create a directory
`mkdir my_directory`

> create nested directory
`mkdir -p parentFolder/childFolder`
