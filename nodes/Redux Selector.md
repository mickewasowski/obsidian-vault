---
aliases:
context:
  - "[[JavaScript]]"
  - "[[Redux]]"
---

# Redux Selector

Hook for consuming global state from Redux.

---

> [!Warning] It is important to use single selectors.
> This is not performant and can cause unnecessary re-renders:

```js
    const {
      width,
      height,
      layout,
      open,
      tab,
      locale,
    } = useSelector((state) => ({
      width: state.app.window.width,
      height: state.app.window.height,
      layout: state.app.window.layout,
      open: state.app.menu.open,
      tab: state.app.menu.tab,
      locale: state.app.settings.locale,
    }));
```
Every time *any* of the selected values change in the Redux store (based on `===` shallow equality), your component will re-render.
You're returning a *new object literal* on every call.
By default, `useSelector` does a strict equality check (`===`) on the return value, so the new object means it *always re-renders* when *any* of those fields change - and even when none change unless you pass a custom equality function.

If `games` or `collections` are large arrays/objects and they change frequently (new reference), you'll get a lot of re-renders - event if only `width` changed.
If your components is heavy (complex JSX, expensive calculations), this could add unnecessary render cost.



The better aproach is:
``` js
    const width = useSelector(state => state.app.window.width);
    const height = useSelector(state => state.app.window.height);
    const layout = useSelector(state => state.app.window.layout);
    const open = useSelector(state => state.app.menu.open);
    const tab = useSelector(state => state.app.menu.tab);
    const locale = useSelector(state => state.app.settings.locale);
```

### Why separate `useSelector` calls can improve performance:
1. selective re-renders: Each `useSelector` call subscribes only to the specific piece of state it reads
2. fine-grained updates: when a single piece of state changes, only the components or hooks depending on that piece re-renders.
3. avoid unnecessary updates: a grouped selector returns a new object on every state change (even if only one property changed), causing your component to re-render unnecessarily
4. smaller comparison: react-redux uses strict equality (`= = =`) to check if the selected value changed. Single values are simpler and faster to compare than objects.

### When grouped selectors can be okay:
1. if you memoize the returned object with `shallowEqual` or a custom equality check
2. or if the selected properties always change together

## Summary
> Separate selectors = more precise subscriptions = fewere unnecessary re-renders = generally better performance, especially when your state updatesoften but only part of it changes at a time.
