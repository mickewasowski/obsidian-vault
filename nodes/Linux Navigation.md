---
aliases:
context:
- "[[Linux]]"
---

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


## Directory hierarchy
Crucial for efficient navigation and file management.
Filesystem Hierarchy Standard (FHS) is a defined tree like structure that prevents files from being scattered all over the system.

`/` root directory, top level of the file system
The base of the entire filesystem hierarchy, all other directories branch from here.


`/boot`
Contains files needed to boot the system.
Includes kernel images, initramfs, and bootloader files.


`/home` user home directories
Contains personal directories for each user.


`/bin` essential binary executables
Contains essential command binaries needed in single-user mode.
Common commands: `ls`, `cp`, `mv`, `cat`, `bash`
Accessible to all users


`/sbin` system administration binaries
Contains essential system administration binaries.
Typically requires admin privileges.
Commands: `fdisk`, `ifconfig`, `reboot`, `iptables`


`/etc` configuration files
Contains system-wide configuration files.
Example:
- `/etc/passwd` user account information
- `/etc/group` group information
- `/etc/fstab` filesystem table
- `/etc/hosts` hostname to IP mappings


`/dev`
Contains device files that represent hardware components
Examples:
- `/dev/sda` first SATA/SCSI disk
- `/dev/tty` terminal devices
- `/dev/null` null device (discards all data)


`/proc`
Virtual filesystem providing process and kernel information.
Files don't exist on disk, generated on the fly by the kernel.
Examples:
- `/proc/cpuinfo` CPU information
- `/proc/meminfo` memory information
- `/proc/[pid]` directory for each running process


`/var` variable data (log, spool files)
Contains files that change frequently.
Subdirectories:
- `/var/log` system log files
- `/var/spool` spool directories (print queues, mail)
- `/var/cache` application cache data
- `/var/www` web server root (common location)


`/usr` user programs and data
Contains the majority of user utilities and applications.
Subdirectories:
- `/usr/bin` non-essential user binaries
- `/usr/sbin` non-essential system binaries
- `/usr/lib` libraries for binaries `/usr/bin` and `/usr/sbin`
- `/usr/local` locally installed software
- `/usr/share` architecture-independent data


`/lib` shared libraries
Contains libraries needed by binaries in `/bin` and `/sbin`.
Similar for `/usr/lib` but for essential system binaries.


`/tmp` temporary files
Temporary files created by the system and user.
Typically cleared on reboot.


`/opt` third-party applications (optional software)
Contains add-on application software packages. 


`/mnt`
Temporary mount points for filesystem.
Traditionally used for manually mounted devices.


`/media`
Mount points for removable media (USB drives, CDs, etc.)
Often automatically mounted.


`/srv` Service data
Contains data for services provided by the filesystem - web server data, FTP filesystem


`/run` Runtime data
Contains system information describing the system since boot.
Replaces `/var/run` in many modern distributions.
