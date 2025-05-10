---
aliases:
context:
- "[[Git Commands]]"
---

#wip

# Git Stash Commands

A stash follows LIFO (last-in-first-out). The most recent element in the stash is stash@{0}.

---
> Lists all stashed changes
``` bash
git stash list
```

> Shows a summary of the changes in a specific stash:
``` bash
git stash show stash@{0}
```

> See a full diff of the changes in a specific stash:
``` bash
git stash show -p stash@{0}
```

> This applies the most recent stash but keeps it in the stash list in case you want to reuse it:
``` bash
git stash apply
```

> This applies a specific stash:
``` bash
git stash apply stash@{1}
```

> Applies the stash and removes it from the stash list:
``` bash
git stash pop
```

> Applies a specific stash and removes it from the stash list:
``` bash
git stash pop stash@{1}
```

> Removes a specific stash from the list without applying it:
``` bash
git stash drop stash@{0}
```

> Remove all stashes at once without applying them:
``` bash
git stash clear
```