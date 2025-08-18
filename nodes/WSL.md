---
aliases:
context:
- "[[Windows]]"
- "[[Microsoft]]"
- "[[Linux]]"
---

# WSL

Windows Subsystem for Linux is a compatibility layer developed by Microsoft that lets you run a Linux environment *natively* on Windows - without the need for a traditional virtual machine or dual-boot setup. 

---

### What it does:
WSL enables devs to use Linux command-line tools and apps alongside their Windows ones. It's great for web development, scripting, DevOps, and anything where Linux is the standard.

There are two versions:

| Feature | WSL 1 | WSL 2 |
| -------- | -------- | --------- |
| Architecture | translation layer | full Linux kernel via lightweight VM |
| Performance | faster file access | faster for system call, better compatibility |
| Compatibility | not all apps work | almost full Linux compatibility |
| Size | smaller | slightly heavier due to VM-based setup |


> [!tip] WSL 2 is recommended!

> [!warning] On Windows 10 you might experience issues when trying to install WSL from the command prompt/powershell. A workaround to fix this issue is to install it from the Windows Store directly.

### Use cases:
- running bash and linux commands
- managing Node.js, Python, Ruby envs
- Docker (runs better with WSL 2)
- using tools like [[grep]], [[awk]], [[sed]], [[curl]]
- developing on frameworks that expect a Linux filesystem


### Common Commands:
``` shell 
wsl                     # Launch default distro
wsl --install           # Install WSL (on Windows 11 or 10 21H2+)
wsl --list --verbose    # List installed distros
wsl --set-version <distro> 2   # Set specific distro to WSL 2
wsl --shutdown          # Shutdown all running WSL instances
```


### Integration with Windows:
- access Linux files from Windows:  \\wsl$\<distro_name>\
- access Windows files from Linux: /mnt/c/ , /mnt/d/ , etc.
- use Visual Studio Code with WSL via the Remote - WSL extension


### Check if WSL is active
1. From Powershell or CMD `wsl --list --running` or shorthand `wsl -l -v`, another one `tasklist | findstr "wsl"`
2. From inside WSL `uname -a`
3. Via Windows services `Get-Process | Where-Object { $_.ProcessName -mathc "vmmem" }`
