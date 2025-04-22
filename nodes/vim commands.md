---
aliases:
context:
---

#wip

# vim commands

ad

---

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

``` vim
in normal mode type
30igo
then hit Esc and it will type go 
```

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
> r<char> => replace character under cursor
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
> :sp file => horizontal split
> Ctrl-w + h/j/k/l => move between splits
> :tabnew file => open new tab
> gt / gT => next/previous tab
