---
aliases:
context:
- "[[Git Commands]]"
---

#wip

# Git cherry pick

ad

---

#### CSS illustration ideas:
https://alvaromontoro.com/blog/67936/100-days-of-css-illustrations

#### CSS challenges:
https://medium.com/design-bootcamp/i-designed-and-completed-a-30-day-css-challenge-4e45c32f7f8c

#### FE challenges:
https://coderbyte.com/challenges?utm_campaign=NewHomepage


#### Minification in JS
It removes unnecessary comments and white spaces, shortens variable and function names.


practice keyboard typing:
https://www.edclub.com/sportal/program-3/140.play
https://www.keybr.com/




> The below command will perform checkout to the previous checkout.

	git checkout -

<br/>


> This will pull the code from the specific commit and creates a new commit in your (target) branch:

	git cherry-pick COMMIT-ID

> [!warning]
> Cherry picking can cause duplicate commits.

> [!tip]
> Cherry picking can be great for bug hotfixing.
> Let's say you're working on a feature and notice a bug.
> You can create a specific commit to fix the issue which then can be cherry picked from your branch.



# Collaboration

#### Forking vs Cloning

> **Cloning** a repository means to locally (on your local machine) create a copy of a remote repository. This allows you to make changes and then commit and push them back to the remote repo if you have the necessary permissions.

> **Forking** a repository is specific to Github, Gitlab and Bitbucket. It is creating a copy of someone else's repository in your own account. This creates an independent repository of the original and can be modified without affecting the original.

> [!warning] There is no git command for *forking*. It is a feature available in the mentioned platforms above.


#### Issues

- Creating issues: Users can create new issues by submitting a form on the repository’s Issues page.
- Issue titles and descriptions: Each issue has a title and body (description), which provide context for the problem or request.
- Assignees: Issues can be assigned to specific users, who are then responsible for addressing the issue.
- Labels: Labels are used to categorize issues by topic, priority, or other criteria. This helps filter and organize issues within a repository.
- States: Issues have states that reflect their status, such as “Open”, “Closed”, or “Pending”.
- Comments: Users can comment on existing issues to discuss or provide additional context.
- Labels and milestones: Issues can be associated with labels (topics) and milestones (deadlines), which help filter and prioritize them.

#### Pull requests

A Pull request (AKA Merge request) is a request to merge a set of changes.
Collaborators can review and discuss proposed changes.
The owner of the repo can also lock the merging to always require a review and confirmation.

##### Pull request from a fork
