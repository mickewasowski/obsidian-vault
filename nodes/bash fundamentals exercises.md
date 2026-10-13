---
aliases:
context:
---

# bash fundamentals exercises

---
[x] 1. **Create a workspace**
   From your home directory, create this structure using terminal commands:

   ```text
   shell-practice/
   ├── logs/
   ├── backup/
   └── notes/
   ```

   Then navigate into `shell-practice`.

[x] 2. **Create and manipulate files**
   Inside `notes/`, create:

   ```text
   linux.txt
   bash.txt
   commands.txt
   ```

   Put some text into each file using `echo` and redirection. Then copy `linux.txt` into `backup/` and rename the copy to `linux-backup.txt`.

3. **Practice `find`**
   From `shell-practice/`, find:

   * every `.txt` file
   * only `.txt` files inside `notes/`
   * files whose names contain `linux`
   * directories only

4. **stdout vs stderr**
   Run one `ls` command where you give it:

   * one path that exists
   * one path that doesn't exist

   Redirect **stdout** into `success.txt` and **stderr** into `errors.txt`. Neither result should appear in your terminal.

5. **Append instead of overwrite**
   Create `history.txt` containing:

   ```text
   First entry
   ```

   Then, using separate commands, add:

   ```text
   Second entry
   Third entry
   ```

   without destroying the previous contents.

6. **Input redirection**
   Create a file containing several unsorted names:

   ```text
   George
   Alex
   Maria
   Bob
   David
   ```

   Use `sort` with **input redirection (`<`)** rather than giving `sort` the filename directly.

7. **Your first processing pipeline**
   Create `users.txt` containing duplicate names. Build a pipeline that:

   * reads the file
   * sorts the names
   * removes duplicate adjacent lines
   * saves the result to `unique-users.txt`

   Try to do it with one command.

8. **Count duplicate entries**
   Using the same `users.txt`, produce output such as:

   ```text
   4 alex
   3 john
   2 maria
   ```

   Use a pipeline involving `sort` and `uniq`. You'll need to figure out the appropriate `uniq` option.

9. **Practice output redirection**

   Inside `shell-practice/`, use `echo` and redirection to create three files:

   ```text
   report.txt
   notes.txt
   summary.txt
   ```

   Then:
   - Write some text into `report.txt`.
   - Append another line without overwriting the existing contents.
   - Redirect the output of `cat report.txt` into `summary.txt`.
   - Display `summary.txt` and verify that the contents match.

10. **Combine stdout and stderr**

    Run an `ls` command with one valid path and one nonexistent path.

    Redirect:
    - Standard output to `success.txt`.
    - Standard error to `errors.txt`.

    Then use `2>&1` to redirect both streams into `all-output.txt`.

    Inspect all three files using `cat` and explain which output each file contains.

11. **Command substitution**

    Use command substitution to create a directory whose name includes your current directory's name.

    For example, if `pwd` prints `/Users/you/shell-practice`, create a directory named:

    ```text
    shell-practice-backup
    ```

    Use `basename` inside `$(...)` to extract the final directory name, and `mkdir` to create the new directory.

12. **Process substitution**

    Create two files, `file1.txt` and `file2.txt`, with different contents.

    Use process substitution with `cat` to provide the contents of both files as inputs to a single command.

    Your goal is to understand how `<(...)` creates file-like inputs from commands without creating intermediate files.

    Hint: Process substitution is a Bash feature. For a meaningful comparison, you would need a comparison utility, which is outside the topics in the screenshot. Focus on understanding the syntax and the generated inputs.

13. **Create and manage Bash aliases**

    Create an alias called `croot` that runs `cd` to your `shell-practice/` directory.

    Then:
    - Display your current directory with `pwd`.
    - Define the alias.
    - Navigate somewhere else using `cd`.
    - Run `croot` and verify that you return to `shell-practice/`.
    - Inspect the alias using `alias`.
    - Remove it using `unalias`.

14. **Explore help commands and repeat commands**

    Practice discovering commands without looking up their usage online.

    - Use `help` to learn about the Bash built-in `cd`.
    - Use `help` to learn about `echo`.
    - Use `man` or `--help` to explore `ls` and `mkdir`, depending on your system.
    - Run `pwd`, then repeat the command using your shell's command history.
    - Use Tab completion to complete a directory name and a filename.

    Try to accomplish each task without manually typing the full command whenever completion is possible.

15. **Mini challenge: stop execution**

    Create a directory named `stop-challenge` and navigate into it.

    Execute these commands one at a time:

    ```bash
    touch first.txt
    touch second.txt
    ls
    ```

    Then:
    - Use your shell's keyboard interrupt (`Ctrl+C`) while a command is running.
    - Observe what happens when you interrupt it.
    - Use `help` to investigate the Bash `exit` built-in.
    - Exit the current shell session and open a new one.
    - Navigate back to the challenge directory and use `ls` to verify that your files still exist.

    Explain the difference between stopping a running command, exiting a shell, and deleting files.
