---
aliases:
context:
- "[[Ubuntu]]"
---

#wip

# Ubuntu setup

Install these

---

# Installation of basic packages

```
    sudo apt install xclip
    sudo apt install fzf
    sudo apt install ripgrep
    sudo apt install fd-find
    sudo apt install gcc
```


# Aliases

``` bash
    alias gr="cd ~/Documents/github/"
    alias vnv="cd ~/.config/"
    alias v="nvim"
```

# Custom keymap settings
1. Disable everything from navigation and set only the below:
    - Move window one space to the left - Shift + Alt + ,
    - Move window one space to the right - Shift + Alt + .
    - Switch to workspace on the left - Alt + ,
    - Switch to workspace on the right - Alt + .
    - Switch windows - Alt + tab
2. Custom Shortcuts
    - flameshot (name) - flameshot gui (command) - Print (button)
    - terminal (name) - alacritty (command) - Super + T (button)
    - theme toggle:
``` bash
bash -c 'v=$(gsettings get org.gnome.desktop.interface color-scheme); if [ "$v" = "'\''prefer-dark'\''" ]; then gsettings set org.gnome.desktop.interface color-scheme default; else gsettings set org.gnome.desktop.interface color-scheme prefer-dark; fi'
```
3. Custom services (simply place the service files in `~/.config/systemd/user/` and then run `systemctl --user daemon-reload` to reload them):
    - alacritty theme sync
    - github repo update

> Reload services
``` bash
    systemctl --user daemon-reload
```

> Enable service at start
``` bash
    systemctl --user enable alacritty-theme-sync.service
```

> Start service now
``` bash
    systemctl --user start alacritty-theme-sync.service
```

# Alacritty theme sync with GNOME setup

1. run this command to make the script executable
``` bash
    chmod +x ~/.config/alacritty/sync-alacritty-theme.sh
```
