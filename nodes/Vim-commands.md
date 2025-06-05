---
aliases:
context:
- "[[Text Editor]]"
---

# Vim

---
### Keys

| Key combination | Action performed |
|------------------  |--------------------  |
| h | moves left |
| l | moves right |
| j | moves down |
| k | moves up |
| 0 | jump to the beginning of the line |
| $ | jump to the end of the line |
| p | paste |
| y | yank / copy |
| o | new line below |
| O | new line above |
| Ctrl + a | increments the first occurrence of a number on the line where the cursor is or under the cursor |
| Ctrl + x | decrements the first occurrence of a number on the line where the cursor is or under the cursor |
| gg | jumps to the beginning of the file |
| G | jumps to the end of the file |
| 5gg | jumps to the 5th line |
| Esc | enters normal mode |
| v | enters visual mode for selections |
| shift + v | selects the entire row |
| ctrl + v | it's like the cursor is at the same Y on each row you select |
| v + f + letter | selects up to the first occurrence of the letter on that row | 
| v + i + w | if you're in the middle of the word, or anywhere in the word it selects the entire word |
| v + i + ( | selects everything within the brackets ( either ) works |
| y + i w | copies the entire word where your cursor is |
| d + i + w | deletes the entire word where your cursor is |
| v + a + ( | selects everything within the brackets including the brackets | 
| i | enters insert mode for regular typing |
| :reg | lists the last things you have copied or deleted, it also provides a code on how to get it, something like a clipboard |
| "0 | this is an example code from the above command, then you click p and it will paste it |
| q + letter | when you press q and then any other letter you start recording a macro, then to use the macro simply type @ + the letter you chose |
| web | 
| shift web| 
| c | deletes and enters insert mode |
| shift + zz | save & exit |
| shift + zq | exit |
| ctrl + d | scroll down |
| ctrl + u | scroll up (hold the ctrl) |
| r + letter | replaces the letter below the cursor with the letter |
| > | in visual mode indent text right |
| < | in visual mode indent text left |
| ctrl + r | redo |
| gc | comments the selected text |
| gcc | comments the row where the cursor is | 

### Modes

| Mode name | Description |
| --------------| -------------|
| Normal | Navigate, delete, copy, etc. (enter it by pressing Esc)|
| Visual | Select text (enter it by pressing v)|
| Insert | Type text like a regular editor (enter it by pressing i)|
| Command | Run commands with : |




### Basic navigation
> h => left
> l => right
> k => up
> j => down
> gg => top of the file
> ge => move to the end of the previous 
> G => bottom of the file
> 0 => beginning of the line
> ^ => move to first nonwhite space character
> $ => end of the line
> w => start of the next word
> 3w => same as pressing w 3 times
> e => end of the word
> b => start of the previous word
> \* => find the next occurrence of the word under the cursor (the slash here is escaping the symbol because of obsidian)
> \# => find the previous occurrence of the word under the cursor (the slash here is escaping the symbol because of obsidian)
> x => delete the character under the cursor
> X => delete the character to the left of the cursor
> r => replace the character under your cursor

### Insert mode

> Esc => normal mode / exit insert mode
> i => insert before the cursor
> I => insert at the beginning of the line
> a => insert after the cursor
> A => insert at the end of the line
> o => open a new line below
> O => open a new line above

### Editing mode

> x => delete character under cursor
> X => delete character to the left of the cursor
> dd => delete/cut current line
> yy => copy/yank current line
> p => paste after the cursor
> P => paste before the cursor
> u => undo
> Ctrl + r => redo
> r\<char> => replace character under cursor (the \ is escaping the symbol in obsidian)
> cw => change word (delete word, then go into insert mode)
> C => change to end of line (c$)
> . => repeats the previous command

### Search and replace

> /word => search forward for "word"
> ?word => search backward for "word"
> n / N => previous / next **match**
> :%s/foo/bar/g => replace all foo with bar in the whole file

### File operations

> :w => save file (write)
> :q => quit
> :wq or ZZ => save and quit
> :q! => quit without saving
> :e filename => open a file
> :vs filename => open file in vertical split


### Split and tabs

> :vsp file => vertical split
> ctrl-w + v => vertical split
> :sp file => horizontal split
> Ctrl-w + h/j/k/l => move between splits
> :tabnew file => open new tab
> gt / gT => next/previous tab


### Misc
> ctrl+z => minimize vim
> fg => maximize vim
> jobs => lists all minimized vims