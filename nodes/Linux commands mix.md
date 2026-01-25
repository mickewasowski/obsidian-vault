---
aliases:
context:
- "[[Linux]]"
---

# Linux commands mix

Here you can find the commands I have needed and didn't know.

---

| Command | What it does |
| ----------- | -------------- |
| `cp source_file_destination new_destination_directory` | this copies a file from one destination to another |
| `cp -r source_file_destination new_destination_directory` | this copies an entire directory |
| `rm -rf path_to_directory` | this deletes a directory or a file |



#### sudo apt update
- fetches the latest information about package versions from the internet
- it does NOT install or upgrade anything
- it just updates your system's awareness of what's available
We can think of it as like refreshing the App Store page to see what new updates are available - but not downloading or installing any updates yet.


#### sudo apt upgrade
- it compares your installed package versions with the newer versions that apt update found
- if a newer version exists, it upgrades the package
- it keeps the existing software versions compatible - it doesn't remove or install new packages unless necessary
- sometimes it asks you if you want to continue
The analogy is after you've refreshed the App Store page now you click "Update All" to actually install the new versions.


#### swap caps with ctrl
steps:
```
sudo vi /etc/default/keyboard

XKBOPTIONS="ctrl:swapcaps" or XKBOPTIONS="ctrl:nocaps"

sudo dpkg-reconfigure keyboard-configuration
```

#### chown
used to change ownership of files and directories
``` bash
// syntax
chown [OPTIONS] NEW_OWNER[:NEW_GROUP] FILE...
```

``` bash
// example
chown john:developers myfile.txt
```

Common use cases:
- change only the owner
- change only the group
- change recursive (for directories and contents)
Only the **root** can use this command.


#### check for process running on port

1. identify what process is running on the port
```bash
sudo lsof -i :3000

//or

sudo ss -lptn 'sport = :3000'
```

2. stop/kill the process
```bash
sudo kill -9 <PID>
```
