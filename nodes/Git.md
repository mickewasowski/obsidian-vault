---
aliases:
context:
- "[[VCS]]"
---

# Git

Git is a version control system.
It is the most globally used VCS due to its speed and flexibility.

---
Git was created in 2005 by Linus Torvalds.
It has a strong support for branching, merging and distributed development workflows.
Git is designed to handle projects of any size with speed and efficiency.
Provides non-linear development (parallel development).
Maintains a full history of all changes, enabling easy rollbacks and comparisons between versions.

In order to use Git you need to install it first. For the different OSs the steps may be different.

## Repository
A repository is a storage location for your project. It contains the documentation of your project, source code, and other files. Serves as a central hub for collaboration, version control, and code management. Allows multiple people to work on the same project without overwriting each other's work.

	git init
Creates a new empty repository, or converts an existing unversioned project into a Git repository.
Most other git commands are not available outside of an initialized repository, so typically this is the first command you run.

	git config
It is used to set configurations, both local or global, such as user email, etc. The configuration is stored in a .gitconfig text file. Configuration names are dot delimited strings composed of a section and a key, such as *user.email*

	git config --local [key] [value]
Manage local configuration for the current repository.

	git config --global [key] [value]
Manage global configuration, applies to all repositories on your system.

###### Working directory
> A Working directory is the local development environment where the files are stored and modified as part of a project. It reflects the current state of the project. Staging files is preparing them for commiting. Working directory allows you to add, delete or modify files. The WD is connected to a Git repository and it helps manage the differences between the commited history and the current state of the files.

> [!warning] Working directory and local Git repository are not the same thing! The working directory is the folder on your computer where your project's files are located.
> A local Git repository has the .git directory inside it, which contains all the Git-related data, such as commit history, branches, and configuration.


###### Staging area
> This is an intermediate step between your local changes and the the actual commit. 
These are the files you are ready to commit to the remote repository.

###### Commiting changes
> Crucial part of version control, allows you to save your progress and create a snapshot of your project's current state.

> [!warning] .gitignore
> It is placed at the root of your repository. It states which files are to be ignored. You can state a file name, a directory path, or a pattern to match against file names.

###### Viewing commit history
	git log 
		      --oneline
		      --graph
		      --patch
		      --stat
The above command allows you to view commit history in different formats. You can filter the data by author, date range, tag, and other criteria.


## Branching

Branching creates a separate development line that allows multiple changes to be worked on simultaneously without affecting the main code. It also allows you to collaborate with multiple people. With branches you can create isolated environments for different tasks.

 ###### Creating a branch can be done either from the console or from the Github user interface.
 
	git checkout -b BRANCH_NAME

The above is the command which creates a local branch with the provided name.

###### Renaming a branch
Renaming a branch means changing the name of a branch to something different while preserving its history and the commits it contains.
The branch itself remains the same in terms of code and the history it tracks, but the reference (the name by which you refer to it) is updated.
*The below applies if the remote branch name was renamed and now you want to apply the change locally.*

	git branch -m OLD_BRANCH_NAME NEW-BRANCH-NAME
	git fetch origin
	git branch -u origin/NEW-BRANCH-NAME NEW-BRANCH-NAME
	git remote set-head origin -a

Optionally the below removes the old branch name from the tracking references:

	git remote prune origin


> Rename a branch locally and push the change to the remote:
> *The below will keep the commit history of the branch*
> 
> 	git branch -m OLD_BRANCH_NAME NEW_BRANCH_NAME
> 	git push origin --delete OLD_BRANCH_NAME
> 	git push origin NEW_BRANCH_NAME

###### Deleting a branch
Deleting a Git branch essentially means deleting a line of development. It removes the pointer to a specific commit representing said line of development. When you remove the pointer the line of development is no longer accessible.
>A branch is typically deleted after a pull request is merged.
>If the branch you want to delete is the *default branch*, you must first specify a new default branch.
>If a branch you want to delete is *associated with a pull request* you must first close the pull request or merge it before deleting the branch.

&nbsp;
> Delete a local branch
	git branch -d BRANCH_NAME

> Delete a global branch:
	git branch -D BRANCH_NAME

> Delete a remote branch
	git push origin --delete BRANCH_NAME

> Fetch remote branches
	 	git fetch --all


###### Checkout Branch
To checkout to a branch means to switch your working directory to that branch, making it the active branch. This updates the files to match the state of that branch and allows you to work on it.

###### Merging basics
A merge is combining changes from one branch to another. When you want to integrate changes from one branch (the source) into another branch (the target), you need to perform a merge. This involves resolving conflicts, if any exist. The goal is to create a new commit representing the combined changes from both branches, resulting in a single, cohesive history for your project.

> Move / Rename forcefully
	git branch -M main => means rename the current branch to main. If a branch main already exists, overwrite it.
> The -M renames a branch even if the new branch already exists

## Github essentials

1. Create a free Github account and verify your email address
2. Create a repository with the same name as your Github username. Create a README.md file and write the information you'd like to showcase, such as skillset, etc. It will be your personalized landing page.

Github allows you to create and track issues, to manage and view code, and to collaborate with others. You can also contribute to open-source repositories.

Github offers also private and public repositories.
>  *Private*  repositories are visible only to the owner and to designated collaborators. They are ideal for businesses, and/or for projects that are not yet ready for user consumption.

> *Public* repositories are ideal for showcasing your work/experience, open-source projects, collaboration, etc.


## Git remotes

In Git a remote is a reference to a repository that is located on another server or system.
Remotes allow you to share your code with others in order to collaborate, have a backup of your code, have the most up-to-date code for everyone to access.
You can push code to the remote to update it, you can pull changes from the remote to your local repo, or you can fetch changes without modifying your local copy.
This way you have a centralized version of your project, making it easier to track changes, monitor pull requests, and have a backup of your code.


###### Cloning repositories
Creates a local copy of a remote repository on your computer.
This allows you to work on the project locally, make changes and later push those changes to the remote repository.

	git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY

###### Managing remotes
Adding a remote allows you to push/pull and track changes

	git remote add [name] [url]

Listing remotes, the below command lists all configured remote repositories with their names and URLs

	git remote -v

Renaming existing remotes, the below command renames the remote only locally, it does not affect the remote itself

	git remote rename [old-name] [new-name]

Remove a remote repository:

	git remote remove [name]

Upstream branch
This is the remote branch that your local branch is tracking. It sets the default branch to push and pull changes.

	git push --set-upstream test-repo master


###### Fetch without merge

Running git fetch will retrieve the data from the remote repository but *will not automatically merge changes*. This way your local repository is up-to-date with the remote and your working directory remains unchanged. Later you can choose to merge or rebase to apply these changes.

	git fetch 

Running git pull on the other hand *retrieves and merges* all changes from the remote repo.

	git pull

> [!warning] The below command checks your connection with Git. If there is an issue with your SSH key the below will fail.
> 	ssh -T git@github.com


## Merge Strategies

Available options:
1. Fast-Forward (FF)
2. Non-Fast Forward
3. Rebase
4. Squash
5. Cherry picking


###### Fast-Forward vs. Non-Fast Forward
These two strategies describe how Git handles the history and pointers when merging branches.


> Fast forward:
- works only if no one else is working/committing to the main branch
- all the commits from the feature branch will be added to the main branch
- no new commits must be made to the main branch before you can merge your feature branch (the main branch (target) must be a strict subset of the feature branch, meaning the target must be entirely contained in the feature branch)
- best if you're the only one working on the project

In other words, if someone has made a commit to the main branch it would be as if you have an entirely different project in your feature branch. Hence the need to pull/rebase and resolve merge conflicts before you can merge your branch (which becomes a non-fast forward).

> [!warning] If someone has made a commit to the main branch you could no longer do a FF and you'll have to perform Non-FF, where you either need to pull the main branch into your or rebase from it.


> Non-Fast Forward:
- all commits are preserved in the feature branch
- Git creates an extra commit (merge commit) to combine both histories - links both branches
- multiple people can work/commit to the main branch at the same time
- you need to pull the main branch and resolve the conflicts before merging


###### Rebasing
Git *rebase* is like rewriting your code so that it appears as if you wrote it after the changes on the *main* branch were made.

	git rebase BRANCH_NAME
> The above command moves your commits on top of the latest commits on the *BRANCH_NAME*. Git then reapplies your changes one by one as if there were made after the *BRANCH_NAME*'s updates. If there are any conflicts Git will make you fix them manually.

When to use rebase:
1. to keep a linear commit history (no unnecessary merge commits)
2. when you want your feature branch to appear as if it was build on top of the latest main branch
3. before merging your feature branch (so there are no unnecessary merge commits)

<br>
> Before rebasing (*Feature branch is behind main*):
	main:    A --- B --- C  (new commits on main)
	feature: A --- B --- X --- Y (your changes)

>After rebasing (*git rebase main*):
	main:    A --- B --- C --- X' --- Y' (rewritten commits)
	feature:                             (now on top of main)

> Without rebasing, with merge commit: (*git merge main*)
	main:    A --- B --- C ---------
                          \          \
	feature:              X --- Y --- M (merge commit)


###### Squash
Git squash simply combines multiple commits into one commit. Used to create a more concise commit history.

> Check how many commits you have in your branch

	git log --oneline

> How to perform squashing of commits in your branch:
> 1.  git log --oneline => to see how many commits you have in your branch
> 2. git rebase -i HEAD~6 => here the 6 is the number of commits you have/want to squash
> 3. an editor of choice will pop up with your git commits
> 4. *pick* or *p* will only use those commits
> 5. *squash* or *s* will use them AND combine them all together
> 6. the first commit is the one that you will combine them without loosing your changes

<br>
<br>

> In the below logs we can see that the first 4 commits are on the feature branch. The last commit *6b51b1f* is in the master branch's commit history.
> When squashing commits you can squash only the commits that are in **your** branch's commit history.
```VIM
634d43d (HEAD -> local-renamed, origin/local-renamed-copy, origin/local-renamed, local-renamed-copy) doc3 added
a74e293 doc2 added
c4bb323 doc1 added
cb1af95 test files created from the bash terminal
6b51b1f (origin/master, master) test commit
```

<br>
<br>

> The below is safer than git push --force because it checks if there were any changes on the remote branch that you don't have locally, and it will not override them.

	git push --force-with-lease
