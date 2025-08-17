---
aliases:
context:
- "[[Linux]]"
- "[[Useful]]"
---

# Bash Git pull script

This is a file providing automation for git pull of each repo on you device on system login.

---
### Automatically perform `git pull` on system login

1. Save your script in a file `~/update_repos.sh`
Script contents:
``` bash
#!/bin/bash

REPOS_DIR="$HOME/projects"   # change this path if needed

for dir in "$REPOS_DIR"/*; do
    if [ -d "$dir/.git" ]; then
        echo "Updating repo: $(basename "$dir")"
        cd "$dir" || continue
        git pull --rebase
    fi
done

```

2. Make it executable: `chmod +x ~/update_repos.sh`
3. Create a systemd user service
Make the unit file:
``` bash
mkdir -p ~/.config/systemd/user
nano ~/.config/systemd/user/git-update.service
```

Service file contents:
``` bash
[Unit]
Description=Update all git repos after login
After=network-online.target

[Service]
Type=oneshot
ExecStart=%h/update_repos.sh
WorkingDirectory=%h
StandardOutput=journal

[Install]
WantedBy=default.target
```

4. Enable the service:
Run:
``` bash
systemctl --user daemon-reload
systemctl --user enable git-update.service
systemctl --user start git-update.service
```

Check logs with:
``` bash
journalctl --user -u git-update.service
```


> [!tip] In the above we did two things:
> 1. create a bash script to update the repos
> 2. create a systemd user service => a small configuration file that tells system *when and how* to run it

##### Explanation of the **bash script** line by line:
- `#!/bin/bash` tells the sytem to run this file using the *Bash shell*
- `REPOS_DIR="$HOME/projects"` sets the folder where all your Git repos live
- `for dir in "$REPOS_DIR"/*; do` loops through every subdirectory in that folder
- `if [ -d "$dir/.git" ]; then` checks if that subdirectory is actually a **Git repo**
- `echo "Updating repo: $(basename "$dir")"` prints the repo's name, so you can see progress
- `cd "$dir" || continue` changes into that repo's folder (or skips if it fails)
- `git pull --rebase` pulls the latest changes from the remote repo and rebases your local changes on top (safer than plain `git pull` to avoid messy merges)
- `done` ends the loop
The result is each repo in the provided directory is updated


##### Explanation of the **systemd** service:
- `[Unit]`:
- `Description=...` human-readable name for the service
- `After=network-online.target` ensures it only runs *after your network is up* (so `git pull` works)

- `[Service]`
- `Type=oneshot` means it runs the script once, then stops (doesn't keep running)
- `ExecStart=%h/update_repos.sh` => `%h` is your home dir -> this runs your Bash script
- `WorkingDirectory=%h` sets your home as the working directory before running
- `StandardOutput=journal` send all output (`echo`, errors, git messages) to the systemd **journal logs** (you can view them with `journalctl`) 


- `[Install]`
- `WantedBy=default.target` tells systemd: *run this service at login time (when your user session starts)*


##### All together:
- when you login, `systemd --user` starts your session
- it sees `git-update.service` is enabled
- it waits for the network, then runs `update_repos.sh`
- that script loops through your repos and runs `git pull` in each
- done - it exits until your next login