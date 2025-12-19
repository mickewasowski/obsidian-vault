---
aliases:
context:
- "[[C lang path]]"
---

#wip

# C lang

---
### Overview

1. What is C?
- C is a general-purpose, imperative computer programmin language that supports structured programming.
Imperative means that it is organized around statements and variables (explain what to do).
- it is one of the most widely used programming languages of all time
- C is a modern language:
    - has most basic control structures and features of modern languages
    - designed for top-down planning
    - organized around the use of functions (modular design) structured programming
    - a very reliable and readable program
2. Usage
- C is used on everything from minicomputers, Unix/Linux systems to pc's and mainframes
- C is the preferred language for producing work processing programs, spreadsheets and compilers
- C has become popular for programmming embedded systems
    - used to program microprocessors found in automobiles, cameras, DVD players, etc.
3. Early on
- C has and continues to play a strong role in the development of Linux
- C programs are easy to modify and easy to adapt to new models or languages
- In the 1990s, many software houses began turning to the C++ language for large programming projects
- C is a subset of C++ with object-oriented programming tools added
    - any C program is a valid C++ program
    - by learning C, you also learn much of C++
- C remains a core skill needed by corporations and ranks in the top 10 of desired skills
- C provides constructs that map efficiently to typical machine instructions and thus is used by programs that were previously implemented in assembly language
    - provides low-level access to memory (has many low-level capabilities)
    - requires minimal run-time support
- was invented in 1972 by Dennis Ritchie of Bell Laboratories
    - Ritchie was working on the desing of the UNIX OS
- was created as a tool for working programmers
    - main goal is to be a useful language
    - easy readability and writability
4. History
- C initially became widely known as the development language of the UNIX OS
    - virtually all new major OS' are written in C and/or C++
- C evolved from a previous programming language named B
    - uses many of the important concepts of B while adding data typing and other powerful features
    - B was a "typeless" language - every data item occupied one "word" in memory, and the burden of typing variables fell on the shoulders of the programmer
- C is available for most computers
- C is also hardware independent
- by the late 1970s, C had evolved into what is now referred to as "traditional C"
- the rapid expansion of C working on many different hardware platforms led to many variations that were similar but often incompatible
    - a standard version of C was created (C89/C90, C99, C11)
- a program written only in Standard C and without any hardware-dependent assumptions will run correctly on any platform with a standard C compiler
    - non-standard C programs may run only on a certain platform or with a particular compiler
- C89 is supported by current C compilers
    - most C code being written today is based on it
- C99 is a revised standard for the C programming language that refines and expands the capabilities of C
    - has not been widely adopted and not all popular C compilers support it
5. Standards
- the current standard is commonly referred to as C11
    - some elements of the language as defined by C11 are optional
    - also possible that a C11 compiler may not implement all of the language features madated by the C11 standard


### Essential features - Efficiency, Portability, Power


The main features of C are the following:
- Efficient
- Portable
- Powerful and Flexible
- Programmer Oriented


1. Efficiency and Portability
- C is an efficient language
    - takes advantage of the capabilities of current computers
    - C programs are compact and fast (similar to assembly language programs)
    - programmers can fine-tune their programs for maximum speed or most efficient use of memory
- C is a portable language
    - C programs written on one system can be run on other systems with little or no modification
    - compilers are available for many computer architectures
- Linux/UNIX systems typically come with a C compiler as part of the package
    - compilers are available for personal computers


2. Power and Flexibility
- the Unix/Linux kernel is written in C
- many compilers and interpreters for other languages (FORTRAN, Perl, Python, Pascal, LISP, Logo, and BASIC) have been written in C
- C programs have been used for solving physics and engineering problems and even for animation special effects for movies
- C is flexible
    - used for developing just about everything you can imagine by way of a computer program
    - accounting applications to word processing and from games to OS
    - it is the basis for more advanced languages, such as C++
- It is also used for developing mobile phone apps in the form of Objective C (this is what iOS used, essentially it is C with objects)
- C is easy to learn because of its compactness
    - is an ideal first language to learn if you want to be a programmer
    - you will acquire sufficient knowledge for practical application development quickly and easily


3. Programmer Oriented
- C fulfills the needs of programmers
    - gives you access to hardware
    - enables you to manipulate individual bits in memory
- C contains a large selection of operators which allows you to express yourself succinctly (in a brief and clearly expressed manner)
- C is less strict than most languages in limiting what you can do
    - can be both an advantage and a danger
    - advantage is that many tasks (such as converting forms of data) are easier in C
    - danger is that you can make mistakes (pointers) that are impossible in some languages
    - C gives you more freedom, but it also puts more resposibility on you
- C implementations have a large library of useful C functions
    - deal with common needs of most programmers


4. Other features
- provides low level features that are generally provided by the Lower level languages
- programs can be manipulated using bits
    - ability to manage memory representation at bit level
    - provides wide variaty of bit manipulation operators
- pointers play a big role in C
    - direct access to memory
    - supports efficient use of pointers


5. Disadvantages
- flexibility and freedom also requires added resposibility
    - use of pointers is problematic and abused
    - you can make programming errors that are difficult to trace
- sometimes because of its wealth of operators and its conciseness, it makes the language difficult to read and follow
    - there is an opportunity to write obscure code



### C Program Creation: Editing, Compiling, Linking

There are four fundamental tasks in the creation of any C program:
- Editing
- Compiling
- Linking
- Executing

The processes of editing, compiling, linking, and executing are essentially the same for developing programs in any environment and with any compiled language.


Editing is the process of creating and modifying your C source code
    - source code is inside a file and contains the program instructions you write
    - choose a wise name for your base file name (all source files end in the .c extension)


Compiling - a compiler converts your source code into machine language and detects and reports errors in your code
- the input to the compiler is the file you produce during your editing (source file)
Compilation is a two-stage process:
    - the first stage is called the preprocessing phase, during which your code may be modified or added to
    - the second stage is the actual compilation that generates the object code
- the compiler examines each program statement and checks it to ensure that it conforms to the syntax and semantics of the language
    - can also recognize structural errors (dead code)
    - does not find logic errors
    - typical errors reported might be due to an expression that has unbalanced parentheses (syntactic error), or due to the use of a variable that is not "defined" (semantic error)
- after all errors are fixed, the compiler will then take each statement of the program and translate it into assembly language
- the compiler will then translate the assembly language statements into actual machine instructions
    - the output from the compiler is known as object code and it is stored in files called object files (same name as source file with a .obj or .o extension)
- the standard command to compile your C programs will be cc (or the GNU compiler, which is .gcc)
    - cc -c myprog.c or gcc -c myprog.c
    - if you omit the -c flag, your program will automatically be linked as well


Linking
- after the program has been translated into object code, it is ready to be linked
    - the purpose of the linking phase is to get the program into a final form for execution on the computer
    - linking usually occurs automatically when compiling depending on what system you are on, but, can sometimes be a separate command
- the linker combines the object modules generated by the compiler with additional libraries needed by the program to create the whole executable
    - also detects and reports errors
    - if part of your program is missing or a nonexistent library component is referenced
- program libraries support and extend the C language by providing routines to carry out operations that are not part of the language
    - input and output libraries, mathematical libraries, string manipulation libraries

- a failure during the linking phase means that once again you have to go back and edit your source code

- success will produce an executable file
    - in a Windows environment, the executable file will have an .exe extension
    - in UNIX/Linux, there will be no such extension (a.out by default)
    - many IDEs have a build option, which will compile and link your program in a single operation to produce the executable

- a program of any significant size will consist of several source code files
    - each source code file needs the compiler to generate the object file that need to be linked

- the program is much easier to manage by breaking it up into a number of smaller source files
    - it is cohesive and makes the development and maintenance of the program a lot easier
    - the set of source files that make up the program will usually be integrated under a project name, which is used to refer to the whole program


Executing

The execution stage is where you run you program
    - each of the statements of the program is sequentially executed in turn
    - if the program requests any data from the user the program temporarily suspends its execution so that the input can be entered
    - results that are displayed by the program (output) appear in a window called the console
This stage can also generate a wide variaty of error conditions
    - producing the wrong output
    - just sitting there and doing nothing
    - crashing your computer
If the program does not perform the intended functionality then it will be necessary to go back and reanalyze the program's logic
    - known as the debugging phase, correct all the known problems or bugs from the program
    - will need to make changes to the original source program
    - the entire process of compiling, linking, and executing the program must be repeated until the desired results are obtained


### Setup for Ubuntu

The below is the bare minimum for compiling and running C code:
gcc -> compiler
libc6-dev -> C standard library headers (stdio.h, stdlib.h)

```bash
sudo apt update
sudo apt install gcc libc6-dev
```

Compile:
```bash
gcc main.c -o main
```

Run:
```bash
./main
```

For Neovim:
Mason ->
- clang-format - code formatter
command:
```bash
clang-format -i main.c
```
- clangd -> LSP


OR go to `codelite.org` -> Docs -> Getting started -> Linux
```bash
sudo apt install build-essential            \
                 git cmake                  \
                 libssh-dev libsqlite3-dev  \
                 libpcre2-dev bison flex
```
