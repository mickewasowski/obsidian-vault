---
aliases:
context:
- "[[React]]"
- "[[JavaScript]]"
---

# Hierarchical state machine

This file contains an example implementation of a hierarchical state machine.

---

### What it is
A hierarchical state machine (HSM) is an extension of a regular finite state machine (FSM) that allows states to be **nested inside other states**.

- In a plain FSM, you have a flat set of states and transitions between them
- In an HSM, a *superstate* can contain *substates*. The substate inherits the behavior of its parent, and transitions can happen at different levels of the hierarchy.

This helps with:
- **Reducing complexity**: common behavior can be defined once in a higher-level state instead of repeating it in each substate.
- **Reusability**: states can share logic without duplication
- **Clarity**: the hierarchy shows structure (like grouping related states together)


### Example:
Imagine a phone call:
- Superstate: "Call Active"
   - Substate: "Talking"
   - Substate: "On Hold"
   Both substates share behaviors like "End Call" (handled by the parent), but have their own specific rules too.
