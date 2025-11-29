---
aliases:
context:
- "[[Redux Selector]]"
---

# createSelector

Comes from "reselect" Redux selector library.

---
### Use case

Custom Redux selectors are good because:
- centralize "how to derive data" - keeps logic in one place
- prevent stale state by design - selectors always compute from latest store state at render time
- simplify components - your component only gets the final result, no multi-step logic
- are memoized - `createSelector` only recomputes if its inputs change, reducing wasted work

> [!tip] If your handler function depends on derived logic that you compute inside your component -> move that logic into a selector
After that a `useCallback` becomes optional, not mandatory.


### Sample custom selectors

```js
import { createSelector } from "reselect";

// Input selectors (cheap, just extract values)
const selectState1 = (state) => state.state1;
const selectState2 = (state) => state.state2;

// If you need an argument (like currentId)
const selectCurrentId = (state, currentId) => currentId;

// Memoized combined selector
export const selectCombinedData = createSelector(
  [selectState1, selectState2, selectCurrentId],
  (state1, state2, currentId) => {
    const selectedA = state1.someTestProp[currentId];
    const relatedB = state2.items.filter(i => i.refId === currentId);

    return { selectedA, relatedB };
  }
);
```

How to use it:
```js
import { useSelector } from "react-redux";
import { selectCombinedData } from "../redux/selectors/mySelector";

function MyComponent({ someId }) {
  const { selectedA, relatedB } = useSelector((state) =>
    selectCombinedData(state, someId)
  );

  // Now everything is fresh & stable
  console.log(selectedA, relatedB);

  return (...);
}
```
