---
aliases:
context:
- "[[Linux]]"
- "[[Terminal editor]]"
---

#wip

# Nano

Nano is a simple, user-friendlly command-line text editor available on Unix/Linux.

---
### Opening files
- open/create file `nano filename`


### Basic navigation
- use the arrows to move the cursor
- page up/down to move up/down a page
- `Ctrl + A` move to the start of the line
- `Ctrl + E` move to the end of the line
- `Ctrl + Y` scroll up
- `Ctrl + V` scroll down


### Editing text
- type normally to insert text
- delete/backspace to remove characters
- `Ctrl + K` cut an entire line
- `Ctrl + U` paste the last cut line
- `Ctrl + Space` start selecting text (move the cursor to hightlight)
- `Alt + 6` copy selected text
- `Ctrl + W` search for text (press Enter to find next match)
- `**Ctrl + **` find and replace text


### Saving and exiting
- `Ctrl + O` save then press Enter to confirm
- `Ctrl + X` exit, if not saved it will ask to save
- if prompted to save Y (yes) and N (no), confirm file name (or change it) and press Enter


### Misc
- `Ctrl + G` list all commands
- `Ctrl + C` show current cursor position
- `Ctrl + _` go to a specific line number
- `Ctrl + R` insert another file into the current one
