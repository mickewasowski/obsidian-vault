---
aliases:
context:
- "[[JavaScript]]"
---

#wip

# Temporal Dead Zone

---
This is the behavior we experience when we try to access a variable before it's been declared.
This happens for variables declared with let and const because upon hoisting they are not initialized, only the declarations are moved to the top of their scope.