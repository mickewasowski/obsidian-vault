---
aliases:
context:
- "[[Working with text]]"
---

# cut exercises

---

Initial skeleton:
```bash
    cat > employees.txt <<'EOF'
    john:developer:3500:London
    alice:designer:3200:Paris
    bob:engineer:4000:Berlin
    mike:manager:5000:Sofia
    sarah:developer:4200:Amsterdam
    EOF
```

Exercises:

1\. Extract usernames

Display only the names of all employees.


2\. Extract multiple fields

Display each employee's name and salary, keeping the original delimiter.


3\. Extract character positions

Display only the first 4 characters of each line.


4\. Exclude a field

Display all fields except the job title.


5\. Combine commands with a pipe

Use cut and sort to display the employee cities in alphabetical order, without usernames, salaries, or job titles.

