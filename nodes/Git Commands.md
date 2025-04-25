---
aliases:
context:
- "[[Git]]"
---

#wip

# Git Commands

useful git bash commands

---

##### How to pull remote branch data

```bash
git pull master

git branch -r => lists all remote branches

git checkout -b feature_branch origin/feature_branch
```


##### List remote branches
```bash
git branch -r
```
typing Q will exit to the main view once you hit (END)

##### Fetch all remote branches
``` bash
git fetch --all
```

##### HEAD detached at origin/branch_name
This means you are not on a local branch. You're just temporarily looking at a specific snapshot of the code from the remote branch.
If you make any changes/commits now, they'll be orphaned (not tied to a branch). You can't push them easily unless you create a new branch.

If you want to work on that branch you need to:
``` bash
git checkout -b branch_name origin/branch_name
```
The above creates a local branch from the remote one and tracks it. Any commits you make are tied to it.


### How to setup two separate Git configurations locally
