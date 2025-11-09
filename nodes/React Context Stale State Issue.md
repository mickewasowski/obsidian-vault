---
aliases:
context:
  - "[[React]]"
  - "[[React context]]"
---

# React Context Stale State Issue

This issue was experience in the `hangman-game` project.

---
### Problem Description

A function defined inside a React Context provider was referencing outdated state values. The function performed some calculations using the state and then updated it. However, when invoked later (for example, from a consumer component), the state value inside the function was stale, even though the provider had already re-rendered with the new state.

This occurred because the function had _closed over_ the state from the render in which it was created. In JavaScript, functions capture variables from their lexical scope at the time of creation. React does not automatically refresh these closures on re-render. Therefore, when the provider re-rendered with updated state, the old function still referenced the state value from the previous render.

In this case:

- The context provider re-rendered with new state.
- A new function (with a new closure) was created, but consumers still held a reference to the old function.
- Calling that old function resulted in calculations being made with stale state.

### Root Cause

Each render of a React component creates a new lexical environment. Functions defined within that render capture variables from that specific environment. If such a function is passed outside (e.g., via context or props), it retains references to the variables as they existed at the time of its creation. Unless React is told to recreate the function, the closure remains stale.

### Fix

1. **Wrap the function in `useCallback` and provide the necessary dependencies.**
   This ensures that the function is recreated only when relevant dependencies (like the state it relies on) change, so it always has access to up-to-date state values.

   ```tsx
   const updateScore = useCallback(() => {
     console.log("Current score:", score);
     setScore(score + 1);
   }, [score]);
   ```

2. **Memoize the context value (optional but recommended).**
   If the function is part of the value passed to the provider, wrap it in `useMemo` to avoid unnecessary re-renders.

   ```tsx
   const value = useMemo(() => ({ score, updateScore }), [score, updateScore]);
   ```

3. **Add the function to dependency arrays where used.**
   In components that use the function inside `useEffect`, include it in the dependency array to ensure the effect runs with the latest version of the function.

   ```tsx
   useEffect(() => {
     updateScore();
   }, [updateScore]);
   ```

### Summary

- The stale state problem arises because functions in React close over variables from the render in which they were created.
- `useCallback` is required to recreate the function when its dependencies change.
- Without memoization, consumers may call outdated function references that still point to old state values.
