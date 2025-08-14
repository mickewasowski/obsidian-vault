---
aliases:
context:
- "[[Linux]]"
---

#wip

# Editing files

Editing files in the terminal.
Linux by default has the following text editors: `nano`, `vi/vim`, `emacs`, `gedit`.

---

### `nano` (simplest cli editor)
Best for: Beginners who need a simple, no-frills terminal editor.
Basics:
- open file `nano filename`
- write (save) `Ctrl + 0`
- Exit `Ctrl + X` (prompts to save)
- Search `Ctrl + W`
Pros: Easy, intuitive, no-screen shortcuts
Cons: Limited features, no modes


### `vi/vim` (powerful modal cli editor)
Best for: Advanced users who want efficiency in the terminal
Basics:
- open file `vim filename` (or `vi filename`)
- modes:
    - normal mode (default): navigate (`h, j, k, l`), delete (`dd`), undo (`u`)
    - insert mode: edit text (`i` to enter, `Esc` to exit)
    - command mode: save (`:w`), quit (`:q`), force quit (`:q!`), save & quit (`:wq`)
- search: `/pattern` (then `n` for next match and `N` for previous)
Pros: fast, lightweight, hightly customizable
Cons: steep learning curve (modes confuse beginners)


### emacs (extensible cli/gui editor)
Best for: programmers who want an all-in-one toolkit (editor, IDE, email, etc)
Basics:
- open file `emacs filename` (add `-nw` for terminal only)
- save `Ctrl + X Ctrl + S`
- exit `Ctrl + X Ctrl + C`
- search `Ctrl + S` (incremental search)
- key chrods: combos like `Ctrl + X` follwoed by another command
Pros: extremely powerful, scripting (Lisp), GUI support
Cons: bloated for simple tasks, complex shortcuts


### gedit (basic GUI editor)
Best for: beginners who prefer a graphical interface
Basics:
- open from terminal `gedit filename` (or launch via GUI)
- save `Ctrl + S`
- exit `Ctrl + Q` or close window
- search `Ctrl + F`
Pros: familiar GUI, syntax highlighting, plugins
Cons: not for remote/terminal work, less powerful than cli editors
