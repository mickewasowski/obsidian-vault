---
aliases:
context:
- "[[Shell]]"
---

# Shell fundamentals

---
### Commands for navigating, creating files and directories, and listing contents

#### `pwd` (print working directory) - displays the absolute path of the current directory you are working in, tells you where exactly you are located within the file system from the *root* directory

#### `mkdir` - used to create new directory/ies, you can list multiple names or parent/child couples separated by space and each will be created individually. You can also chain multiple commands with `&&` for example if you want to set different permissions to different directories
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

#### `mv` - used to move or rename files and directories
- flags:
    - `-i` - ask before replacing files
    - `-u` - move only if the source is newer (moves only if the source file is newer than the destination file)
    - `-v` - verbose mode, show files being moved

```bash
mv source destination

Example:
mv file.txt /path/to/destination/
mv -i file.txt /path/to/destination/
    => asks you if there is a file with the same name if you want to overwrite it

mv old_name.txt new_name.txt

mv -u file.txt outer2/
    => here the -u flag compares if there is a file.txt in outer2 and if its timestamp is older, its not comparing the directory timestamp if the file is not present
```


#### `ls` - used to list files and directories within a specified directory.
You can control the output with flags:
    - `-l` - long listing format (displays file permissions, number of links, owner name, owner group, file size, time of last modification, file or directory name)
    - `-a` - show hidden files
    - `-h` - human-readable sizes (4mb, 4k, 1gb, etc.)
    - `-t` - sort by modification time (most recently modified first)
    - `-r` - reverse order while sorting (when combined with `-t` it can show the oldest first)
    - `-R` - list sub-directories recursively (useful for viewing the entire directory tree)
    - `-S` - sort by size (largest first)
    - `-1` - list one file per line
    - `-d` - list directories themselves, not their contents
    - `-F` - append indicator (one of */=@|) to entries (e.g. / for directories, * for executables)

You can even use multiple flags at the same time:
```bash
    ls -lh
    ls -la
    ls -Sh
```


#### `touch` - mainly used to create new empty files, or to update file timestamps without changing their contents
    Flags:
        - `-a` - update only when the file was last read
        - `-m` - update only when the file was last changed
        - `-t` - set the timestamp to a specific time
        - `-c` - do not create any files

```bash
    touch *.txt => wildcards allow you to update multiple files at the same time

    touch file1.txt file2.txt file3.txt => create multiple files at the same time

    touch -t 202007250000 *.txt  => set the timestamp for all files
```


#### `cp` - used to copy files and directories from one location to the other. Creates an exact copy in the destination leaving the original in tact.
Can be used to copy single file, multiple files, or entire directories.
    Flags:
        - `-r` - copy all files and directories inside a directory
        - `-i` - ask before replacing
        - `-u` - only copy if the source is newer
        - `-v` -verbose mode, show files being copied


#### `cd` - allows you to navigate in the shell environment, by specifying a target directory as an argument
``` bash
cd ..  => move one directory up
cd ~  => change to the home directory (your user's folder in the home directory)
cd -  => switch to the previous directory
cd /  => change to the root directory (the very beggining of your harddrive)
```

#### `rm` - used to remove files or directories **permanently**. Specific options are needed to remove directories and their contents recursively.
```bash
    rm file_name.txt  => removes a file
```
Flags:
    - `-r` - delete a folder and everything inside it
    - `-i` - ask before deleting
    - `-f` - force delete without asking
    - `-v` - verbose mode, show files being removed


#### `cat` - name is short for concatenate, it is used to display the contents of one or more files on the standard output (usually your terminal screen). It can also be used to concatenate files, meaning to combine them into a single output stream.

Flags:
    - `-n` - add numbers to each line of the output
    - `-b` - add numbers only to lines with text (ignoring blank lines)
    - `-s` - remove extra empty lines (a line containing spaces or tabs is *not blank*), squeezes multiple consecutive completely blank lines into one blank line
    - `-v` - show non-printing characters (except for tabs and end of line)
    - `-T` - shows tabs (in neovim pressing the tab button simply creates spaces) `printf 'hello\tworld\n' > text.txt` then cat that

```bash
// concatenate two files into one (it creates a new file)

cat file1.txt file2.txt > combined.txt
```


#### `echo` - used to show a line of text or a variable's vlue in the terminal.

Basic usage:
```bash
    echo "Hello world!"
    Hello world!
```

Flags:
    - `-n` - don't add a new line at the end
    - `-e` - allow special characters like `\n` for new lines (`echo -e "Hello\tworld!"`)
    - `-E` - don't allow special characters (default)

> `;` - is a command separator
```bash
    echo -n "Hello "; echo "world" => this will print the first command, remain on the same line, then print the second word and go on a new line

    echo -n "Hello " echo "world"  => this is one command with 3 arguments because the syntax is `command argument1 (-n) argument2 (Hello ) argument3 (echo) argument4 (world)`
        // result: Hello echoworld  (and the input line remains on the same line)
```


#### `rmdir` - used to remove empty directories.


#### `find` - used to locate files and directories within a file system hierarchy. Allos you to search based on different criteria such as name, size, modification time, permissions, and file type. Recursively traverses directories, making it suitable for locating files across an entire file system or within specific subdirectories.

[[find]]

[[sort]]


### Navigating the file system

- absolute path - *always* begins from the absolute start of your hard drive
- relative path - relative to your current location


### Tab completion

Single tab will autocomplete a command or text if it is the only thing with that name.
If there are multiple options double tab will list all available options.


### Repeat commands

- `history` - command that lists all previously executed commands
- `!n` - where n is the command's number, executes that specific command
- `!!` - executes the last command
- `!string` - execute the most recent command that starts with "string"

```bash
    history

    !1980

    !!

    !git
```


### Help commands
- `man [command]` - lists the user manual of that command

```bash
    man ls  => lists the user manual for the ls command with all the arguments it could take
```


### Bash alias - it is a shortcut or a custom name you assign to a command or a sequence of commands instead of typing a long command every time

```bash
    alias ll='ls -la'
    alias gs='git status'
```

- `alias` - this command lists all aliases
- `unalias name` - removes an alias, deletes it from the .bashrc file


### Stop execution

- `kill` - command is used to terminate  processes in a unix-like OS. Powerful tool for managing system resources and ensuring thtatprocesses do not consume more resources than necessary

Common Uses:
    - terminate unresponsive processes
    - manage system resources by stopping unnecessary processes
    - send specific signals to processes for custom handling

Options:
- `-9` - forcefully terminate a process
- `-l` - list all signal names
- `-s [signal]` - specify a signal to send
- `-p` - print the process ID

```bash
    kill [option]

    kill -9 1234  => send the SIGKILL signal to a process, which forcefully terminates it

    kill -s SIGTERM 1234
```

| Signal    | Number | Example           | Meaning                                                                                                     |
| --------- | -----: | ----------------- | ----------------------------------------------------------------------------------------------------------- |
| `SIGTERM` | **15** | `kill -TERM 1234` | Politely asks the process to terminate. **Default signal for `kill`.**                                      |
| `SIGKILL` |  **9** | `kill -KILL 1234` | Immediately kills the process. Cannot be caught, ignored, or handled.                                       |
| `SIGHUP`  |  **1** | `kill -HUP 1234`  | Originally means terminal disconnected. Commonly used to tell daemons/services to **reload configuration**. |
| `SIGINT`  |  **2** | `kill -INT 1234`  | Interrupts the process. Usually equivalent to pressing **Ctrl+C**.                                          |
| `SIGQUIT` |  **3** | `kill -QUIT 1234` | Tells the process to quit, typically producing a **core dump**.                                             |
| `SIGSTOP` | **19** | `kill -STOP 1234` | Pauses/suspends the process. Cannot be caught or ignored.                                                   |
| `SIGCONT` | **18** | `kill -CONT 1234` | Resumes a process that was stopped.                                                                         |
| `SIGUSR1` | **10** | `kill -USR1 1234` | User-defined signal. Meaning depends entirely on the application.                                           |
| `SIGUSR2` | **12** | `kill -USR2 1234` | Another user-defined signal. Meaning depends on the application.                                            |


> **Core dump** is a file containing a snapshot of a program's memory and state at the moment it crashed or terminated unexpectedly. Developers use it to debug the program and determine what went wrong.


### [[Redirects & Pipelines]]

### Command substitution

Allows you to use the output of one command as an argument to another command.

```bash
    $(...)

    echo "Today is $(date)"
```
In the above example bash:
    - executes `date`
    - captures its stdout
    - replaces `$(date)` with that text
    - executes the resulting `echo` command

> The difference between pipes and command substitution is that with pipes you use the produced output of the prior command as the input of the next command. Whereas in command substitution you run a command to produce the argument for another command.


### Process substitution

Process substitution is a feature that lets you run a command and make its output (or input) appear to another command as if it were a file.

Syntax:
- `<(command)`  => redirects the output of the command as input (means i want to read output from this command through a file-like object)
- `>(command)`  => this provides a file-like destination whose contents are sent **into** the command (means i want to write data to a file-like object, and have that data become this command's input)

> Comparison:
```bash
    # Pipeline
    command1 | command2  => output of the left command is the input to the right command throught stdin

    # Command substitution
    command2 "$(command1)"  => the output of command1 is received by command2 as text or argument

    # Process substitution
    command2 <(command1)  => command2 receives something that behaves like a filename
```

> Process substitution is useful for example when you want to compare something that are not two files.
> Here for example you compare the results of two commands that are then presented like a file so that *diff* command can work:
```bash
    diff <(ls dir1) <(ls dir2)
```
> Bash runs both *ls* commands and provides *diff* with file-like paths representing their output.

```bash
    ls dir1 ──> temporary file-like stream ──┐
                                            ├──> diff
    ls dir2 ──> temporary file-like stream ──┘

        ||

    diff /dev/fd/63 /dev/fd/62
```


> `tr` - means translate characters, it reads text from *stdin* and replaces characters according to rules you give it
```bash
    echo "hello" > >(tr 'a-z' 'A-Z')

    // here we redirect echo's output to the next command

    echo "hello"    >    >(tr 'a-z' 'A-Z')
                    ↑    ↑
               redirect  process substitution
```
=> The above command means - "Take the stdout of `echo "hello"` and redirect it to a file-like destination connected to the stdin of `tr 'a-z' 'A-Z'`"
(for the above example you'd normally use a pipe, but for the sake of example we use process substitution)



Good mental model:
```bash
    $(command)   → "Give me the OUTPUT as TEXT."

    <(command)   → "Give me the OUTPUT as a FILE-LIKE thing."

    cmd1 | cmd2  → "Connect cmd1's OUTPUT to cmd2's INPUT."
```

[[bash fundamentals exercises]]
