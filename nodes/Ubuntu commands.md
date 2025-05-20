---
aliases: 
context:
  - "[[Ubuntu]]"
---

#wip

# Ubuntu commands

Useful commands
WSL

---

##### force restart of the wsl
1. open powershell as admin
2. run the below command
```
Get-Process | Where-Object { $_.Name -like "*wsl*" } | Stop-Process -Force
```
1. start wsl in terminal again
2. you should have a working Ubuntu now