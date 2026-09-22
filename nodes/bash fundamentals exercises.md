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

9. **Search through command output**
   Use `ps` to display running processes and pipe its output into `grep` to find processes containing a particular word, such as:

   ```text
   bash
   ```

   Then redirect the matches into `bash-processes.txt`.

10. **Command substitution**
    Create a file whose filename contains today's date.

    The result should be something like:

    ```text
    backup-2026-09-22.txt
    ```

    You should use `date` and command substitution:

    ```bash
    $(...)
    ```

    rather than manually typing the date.

11. **Command substitution with variables**
    Without manually counting anything, make this:

    ```bash
    echo "There are _____ items in this directory"
    ```

    print the number of entries in your current directory.

    Hint: you'll need a command substitution containing a pipeline.

12. **Process substitution**
    Create:

    ```text
    file1.txt
    file2.txt
    ```

    with slightly different contents.

    Compare their **sorted contents** without creating temporary sorted files.

    In other words, don't do:

    ```bash
    sort file1.txt > sorted1.txt
    sort file2.txt > sorted2.txt
    diff sorted1.txt sorted2.txt
    ```

    Instead, solve it in one command using:

    ```bash
    <(...)
    ```

13. **Combine stdout and stderr**
    Run a command that produces both successful output and an error. Redirect **both stdout and stderr into the same file** called:

    ```text
    all-output.txt
    ```

    Try solving it using `2>&1`, not `&>`.

14. **Build a log-processing pipeline**
    Create `app.log`:

    ```text
    INFO Server started
    ERROR Database connection failed
    INFO User logged in
    WARNING Disk usage high
    ERROR Database connection failed
    ERROR Authentication failed
    INFO Request completed
    ERROR Database connection failed
    ```

    Write **one command** that:

    * reads `app.log`
    * keeps only lines containing `ERROR`
    * sorts them
    * counts identical errors
    * sorts the result by count
    * writes the final result to `error-summary.txt`

    Your final file should make it obvious which error occurred most frequently.

15. **Mini challenge: put everything together**
    Assume you're inside a directory containing many files and subdirectories. Write **one command/pipeline** that:

    * finds all `.txt` files recursively
    * suppresses any errors from `find`
    * counts how many `.txt` files were found
    * stores that number in a shell variable called `count`
    * then prints:

      ```text
      Found 17 text files
      ```

      where `17` is dynamically calculated.

    This combines `find`, stderr redirection, a pipeline, command substitution, a variable, and `echo`.

I would especially focus on **7–15**. Those force you to think in terms of data flowing through commands:

```text
file → command → stdout → pipe → stdin → command → redirect → file
```

For practice, send me your solutions **one at a time**. I can check each command, point out mistakes, and explain them without immediately giving you the correct solution.

