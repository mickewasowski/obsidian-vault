---
aliases:
context:
- "[[React]]"
---

# React context

---

React context is used for "lifting state up" or in other words making some part of a state global.
In order to implement such a state you need to define a context.

For the context you will need:
1. Default type - this is a type which describes what information this context will hold
2. Define the context itself using the above type and write it in a constant
3. Define a provider wrapper - this is a function which returns a wrapper exposing your state and/or functions to update said state

In order to use the configured context you need the following:
1. Import the provider in a component
2. Wrap it's contents with the provider
3. Inside the children of this component you will now be able to consume the state (keep in mind those children need to be *functional components* to use the `useContext` hook)

Example context:
```js
import { createContext, useContext, useState, ReactNode } from "react";

type ThemeContextType = {
  theme: "light" | "dark";
  toggleTheme: () => void;
};

const ThemeContext = createContext<ThemeContextType | undefined>(undefined);

export const ThemeProvider = ({ children }: { children: ReactNode }) => {
  const [theme, setTheme] = useState<"light" | "dark">("light");

  const toggleTheme = () => {
    setTheme(prev => (prev === "light" ? "dark" : "light"));
  };

  const value = { theme, toggleTheme };

  return <ThemeContext.Provider value={value}>{children}</ThemeContext.Provider>;
};

export const useTheme = () => {
  const context = useContext(ThemeContext);
  if (!context) {
    throw new Error("useTheme must be used within a ThemeProvider");
  }
  return context;
};
```
