---
aliases:
context:
- "[[JavaScript]]"
---

#wip

# State machine

State machine (or *finite state machine, FSM*) is a model of computation where something can be in **one state at a time**, and it can move to another state based on events or conditions.

---
### Structure
1. States = possible situations, distinct modes your system can be in
2. Transitions = rules for moving between states, the rules that say "from this state, go to that state when this event happens"
3. Initial state = where it starts
4. Events/inputs = what triggers a transition, things that cause a state change
5. Actions (optional) = what to *do* when entering/exiting a state

(Check out Traffic light project in my Github for a more "basic" implementation)

