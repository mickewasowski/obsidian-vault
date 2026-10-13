---
aliases:
context:
- "[[Shell fundamentals]]"
---

# Redirects & Pipelines

Allow you to control the flow of data between commands.

---

### Summary - one of the most important concepts in Linux shell. They allow you to control **where a command gets its input, where its output goes, and how multiple commands communicate with each other.**

1. Redirects - change where a command's input comes from or where its output goes.

2. Pipelines - connect the output of one command directly to the input of another, enabling you to chain commands together to perform complex operations is a sequence.


### Redirects

1. Output redirection
- `>` - redirects the standard output of a command into a file, **it overrides the destination file**
(`>` is shorthand for `1>`)
```bash
    echo "Hello" > hello.txt  => this will create the file if it doesnt exist and then save the text inside
```

- `>>` - adds output to the **end** of the file, instead of replacing it (starts on a new line)
(`>>` is shorthand for `1>>`)
```bash
    echo "my name's Peter" >> hello.txt
```

- `2>` - redirects the output for errors, *2* refers to file descriptor 2 (stderr)
```bash
    ls nonexistent.txt 2> errors.txt  => overwrites in the file

    command 2>> errors.txt  => appends the errors in the file
```

- `&>` - used when you want one file descriptor to go to the same destination as another file descriptor
```bash
    2>&1  => redirect file descriptor 2 to wherever file descriptor 1 is currently going

    command > output.txt 2>&1  => combining stdout and stderr

    // Example:
    ls ./logs > everything.txt 2>&1 
```

- redirect stdout and stderr independently
```bash
    command > output.txt 2> errors.txt
```

Example:
```bash
    find / -name "*.txt" > results.txt 2> errors.txt
        // successful search results go into results.txt
        // errors and other problems go into errors.txt
```

- `/dev/null` - special file, anything written to it is discarded
(the black hole for output)
```bash
    command > /dev/null

    command 2> /dev/null  => discards errors
```


2. Input redirection
- `<` - tells a command to take its standard input from a file rather than from the terminal

```bash
    sort < names.txt  => this will take the names, sort them alphabetically and print them

    sort < names.txt > sortedNames.txt  => reads from one file and writes into another
```


### Pipelines

Pipes in shell allow you to send the output of one command as the input to another command.

- `|` (pipe operator) - connects the standard output of the command on the left to the standard input of the command on the right

You can connect as many commands as you like, you're not limited to two

