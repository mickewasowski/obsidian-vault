---
aliases:
context:
- "[[JavaScript]]"
---

# Type Assertion vs Type Casting

---
Type Assertion is TypeScript specific, it tells the compiler "Trust me, I know what type this is.". You're not changing the runtime value - just helping TS understand the type during compilation.
(compile time only)

Type Casting means converting one type to another at runtime - e.g. from float to int, or from string to a number.
TypeScript doesn't do runtime conversion - JavaScript does.

| Feature | Type Assertion (TS) | Type Casting (e.g. C#, Java) |
| --------| ----------| ---------|
| Used in | TS | Many languages (Java, C#, JS) |
| Runtime effect | none | changes the value |
| Purpose | tell compiler the type | convert data between types |
| Example | value as Type | Integer.parseInt() |