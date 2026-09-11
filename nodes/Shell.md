---
aliases:
context:
- "[[Command-Line Interpreter]]"
---

# Shell

---
### Overview

Shell, often refered to as [[Bash]] (Bourne Again Shell), is a command-line interpreter.
It acts as an interface between the user and the [[Operating Systems]], allowing the users to execute commands, run scripts, and manage files.
It interprets the commands entered by the user and instructs the OS to perform the corresponding actions.


### Popular shells

> A shell is a command-line interpreter that provides a user interface for interacting with an OS. Different shells offer varying features, syntax, and capabilities.

1. `dash` (Debian Almquist Shell) - Unix shell that is smaller, faster, and requires fewer resources compared to Bash. It's often used as the default `/bin/sh` on Debian-based systems and is designed to be POSIX-compliant, focusing on speed and efficientcy in script execution. This makes it suitable for boot scripts and other system-level tasks where resource usage is critical.

2. Bash - command-line interpreter and a shell scripting language. Allows users to interact with the OS by typing commands which it interprets and instructs the OS to perform specific actions.

3. `zsh` - Z shell, is a Unix shell that can be used as an interactive login shell and as a shell script command interpreter. It's designed to be highly customizable and offers features like improved tab completion, shared command history across multiple terminal windows, and powerful theming options. (considered alternative to Bash)

4. `fish` - user-friendly command-line shell for UNIX-like OSs. Focuses on providing a more interactive and discoverable experience compared to traditional shells like Bash or Zsh. Key features include autosuggestions, syntax highlighting, and a simplified scripting language.

5. `cmd` - aka Command Prompt, is the default command-line interpreter on Windows OS.

6. PowerShell - cross-platform task automation and configuration management framework, consisting of a command-line shell and associated scripting language. It's built on the .NET Common Language Runtime (CLR) and accepts and returns .NET objects, which allows for more complex and structured data manipulation compared to traditional text-based shells.


### Setting up bash

Configuring your bash to your preference and workflow makes your work more optimized and efficient.
Examples of what you could configure:
- appearance
- define aliases for frequently used commands
- environment variables to control program behavior
- create custom functions to automate tasks


### Files & Directories

Files and directories are the building blocks of a file system.
- files - store data, such as text, images, or executable code
- directories (a.k.a. folders) - organize files and other directories in a hierarchical structure


#### Commands for navigating, creating files and directories, and listing contents

1. `pwd` (print working directory) - displays the absolute path of the current directory you are working in, tells you where exactly you are located within the file system from the *root* directory

2. `mkdir` - used to create new directory/ies, you can list multiple names or parent/child couples separated by space and each will be created individually. You can also chain multiple commands with `&&` for example if you want to set different permissions to different directories
- flags:
    - `-p` - creates parent directories as needed (if the parent directory already exists, it only creates the child directory)
    - `-v` - show a message for each created directory
    - `-m` - set file mode (permissions)

```bash
mkdir -p parent/child
mkdir -v new_directory
mkdir -m 755 new_directory


mkdir -p parent/child1 parent/child2 outer outer2 outer/child1 outer2/child1

mkdir -v parent/child1 parent/child2 outer outer2 outer/child1 outer2/child1

mkdir -m 755 parent/child3 && mkdir -m 444 parent/child4 && mkdir -m 222 parent/child5
```

In the above example `755` is an octal representation of file permissions, where `7` is for the *owner*, and the two `5`s are respectively for *group* and *others*.
Each digit is the sum of:
```bash
    4 = read    (r)
    2 = write   (w)
    1 = execute (x)

So:
    7 = 4 + 2 + 1 = rwx
    5 = 4 + 0 + 1 = r-x
    5 = 4 + 0 + 1 = r-x
```














