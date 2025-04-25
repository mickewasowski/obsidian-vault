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

### Modes

| Mode name | Description |
| --------------| -------------|
| Normal | Navigate, delete, copy, etc. (enter it by pressing Esc)|
| Visual | Select text (enter it by pressing v)|
| Insert | Type text like a regular editor (enter it by pressing i)|
| Command | Run commands with : |