---
aliases:
context:
- "[[Terminal Multiplexer]]"
---


# Screen command

Screen is a terminal multiplexer. It lets you run multiple terminal sessions inside a single terminal window or remote SSH connection.

---
### Functionalities

1. Session persistence - if you start a program in `screen` and you disconnect/detach (you close your terminal or lose SSH connection), the program keeps running in the background.
Later you can reconnect/reattach to the same session.
2. Multiple windows - you can create multiple virtual terminal windows inside a single `screen` session and switch between them.
3. Shared sessions - multiple people can attach to the same screen session, this is useful for pair programming, remote assistance, and teaching.


### Basic usage

1. Start a session:
    `screen`
2. Start a named session:
    `screen -S mySession`
3. Detach from a session (leave it running):
    `Ctrl + A` and then `D`
4. List all sessions:
    `screen -ls`
5. Reattach to a session:
    `screen -r mySession`


### Other useful commands

> [!tip] Remember `Ctrl + A` is the prefix for all `screen` commands

> Session management:
1. Exit screen:
    `exit` or `Ctrl + D`
2. Kill session:
    `screen -X -S mySession quit`

> Windows (virtual terminals inside screen session)
1. New window:
    `Ctrl + A` + `C`
2. Next window:
    `Ctrl + A` + `N`
3. Previous window:
    `Ctrl + A` + `P`
4. List windows:
    `Ctrl + A` + `"` (shows a list, use arrows to pick one)
5. Rename a window:
    `Ctrl + A` + `A`

> Scrolling & copy-paste
1. Enter copy/scrollback mode
    `Ctrl + A` + `[` (use arrows or PgUp/PgDown to scroll, space to start select, arrows to move, space again to copy)
2. Paste selection:
    `Ctrl + A` + `]`

> Session sharing/multiuser mode
1. Allow others to attach to your session:
    `screen -x sessionName` (both users can see the same session and can type)


> [!tip] If you plan on using it a lot, you can customize it with `~/.screenrc`
