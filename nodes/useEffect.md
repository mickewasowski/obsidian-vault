---
aliases:
context:
- "[[React]]"
---

#wip

# useEffect

React Hook for running side effects in functional components on mount, unmount, or state updates.

---

### Clean up callback
```jsx
useEffect(() => {

    // some logic here

    return () => {
        // some clean up logic here
    }

}, [state1, state2, globalState1]);
```
- the cleanup callback is called when the component is about to unmount or before the effect runs again due to a change in its dependencies.
This allows you to clean up resources, intervals, timeouts, reset states, or event listeners to prevent memory leaks.
Essentially React executes the cleanup function right before applying the next effect or when the component is removed from the DOM.
