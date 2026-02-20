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
Create a local branch from a remote branch.


### How to setup two separate Git configurations locally

#wip








### Using personal token
> [!Tip] When the token had expired and you want to renew it you need to first copy the token, update it in the `.git-credentials`, then try to push and when it prompts you for username and password, for the password enter the new token.

Example structure:
```bash
https://<username>:<personal-access-token>@<host>
```


### How to checkout local repo to a tag
When your remote repo had released a version it creates a tag with that version.
If you want to checkout locally to that version (tag) the below are the commands you'll need:
``` bash
    git fetch --tags // fetch all remote tags

    git tag --list // list available tags

    git checkout tags/v1.2.3 // checkout to a specific tag
```
At this point, you'll be in a **detached HEAD state** (meaning you're not on a branch).
If you want to work from that tag and make changes, create a new branch from it:
``` bash
    git checkout -b my-branch-from-v1.2.3 tags/v1.2.3
```

### How to create a tag for an old commit
``` bash
    git log --oneline // find the commit hash you want

    git tag v1.0.0 <commit-hash> // create a tag pointing to that commit

    git push origin v1.0.0 // push the tag to the remote so others see it
```
