---
aliases:
context:
- "[[Linux]]"
---

# Shell basics

Shell acts like a middleman between the user and the kernel (core of the OS).

---
A shell is a command-line interface (CLI) that allows users to interact with the OS by typing commands.


### Types of shells
1. Bash (Bourne Again SHell) - default on many Linux distros
2. Zsh (Z Shell) - enhanced version of Bash
3. Fish (Friendly Interactive Shell) - user-friendly with auto-suggestions
4. Sh (Bourne Shell) - the original Unix shell

How to check your current shell: `echo $SHELL`


| Command | Description |
| -------------- | --------------- |
| `ls` | list files and directories |
| `cd` | change directory |
| `pwd` | print working directory (where you are now) |
| `mkdir` | create directory |
| `rm` | remove files/directories |
| `cp` | copy files/directories |
| `mv` | move/rename files |
| `cat` | display file content |
| `grep` | search for text in file |
| `chmod` | change file permissions |
| `man` | display manual for command |


### File permissions
Types:
- read (`r`)
- write (`w`)
- execute (`x`)

For:
- User (Owner)
- Group
- Others


View permissions: `ls -l`

Change permissions: `chmod 755 file.txt  # rwx for owner, r-x for group & others`


### Environment variables
Environment variables can affect the running process in a shell. They exist in every shell's session.
Some of them are user's home directory, command search path, terminal type and program preferences.
They provide a simple way to share configuration settings between multiple applications and processes in Linux.

Common ones:
- `$PATH` - lists directories where executable files are located (absolute paths to each executable)
- `$HOME` - user's home directory
- `$USER` - current username

View all variables: `printenv`

Set a temporary variable: `export MY_VAR="Hello"`


### Input/Output Redirection
Linux being a multi-user and multi-tasking OS, every process typically has 3 streams opened:
- Standard Input (stdin) - where the process reads its input from (default is the keyboard)
- Standard Output (stdout) - where to write its output (default is the terminal)
- Standard Error (stderr) - where to write error messages (default is the terminal)

- `>` - redirect output to a file (overwrite)
- `>>` - append output to a file
- `<` - use file as input
- `|` - pass output to another command

Example:
``` shell
    ls > files.txt       # Save directory listing to a file
    grep "error" log.txt # Search for "error" in log.txt
```


### Shell scripting basics
A shell script is a file containing a series of commands.

Example:
``` shell
    #!/bin/bash
    echo "Hello, World!"
```
Make it executable and run:
``` shell
    chmod +x hello.sh
    ./hello.sh
```


### Keyboard shortcuts
- Ctrl + C - stop current command
- Ctrl + Z - pause a process (fg to resume)
- Ctrl + D - exit shell (EOF signal)
- Ctrl + R - search command history
- Tab - auto-complete filenames/commands


### Getting help
- `man <command>` - display manual pages
- `<command> --help` - quick help
- `apropos <keyword>` - search for commands
- `tldr <command>` - practical examples


### Super User ("root user")
This user has complete control over the system and can access any stored data on it.
He has the ability to overwrite/modify system configurations, change other user's passwords, install software, and perform more administrative tasks in the shell environment.
Can be accessed throught the `sudo` or `su` commands.

