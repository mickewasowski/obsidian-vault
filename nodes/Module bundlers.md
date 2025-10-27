---
aliases:
context:
- "[[Frontend Build Tools]]"
- "[[Frontend Development Infrastructure]]"
---

# Module bundlers

A module bundler is a tool that takes your JS, TS, CSS, images and other assets, and packages them into one or more files (bundles) that browsers can efficiently load.

---
### Benefits of using Module bundlers

Without module bundlers you'd have to manually include each JS/CSS file in the head of the HTML file.
This is slow, error-prone and can lead to issues such as missed files.

Bundlers solve these issues by:
- handling dependencies automatically
- optimizing the code for performance
- allowing modern JS features (ES modules, JSX, TS) to work in browsers that don't support them natively


### Key concepts

1. Entry - the starting point of your app:
```json
// config file
entry: './src/index.tsx'
``` 

2. Output - where the bundled files go:
```json
output: {
    filename: 'bundle.js',
    path: path.resolve(__dirname, 'dist')
}
```

3. Loaders - tell the bundler how to process non-JS files or modern JS features
Examples:
- `ts-loader` -> compiles TS to JS
- `babel-loader` -> compiles modern JS/JSX to browser-compatible JS
- `css-loader` -> imports CSS into JS
- `file-loader` -> handles images, fonts

4. Plugins - extend bundlers with advanced features
- `HtmlWebpackPlugin` -> generates `index.html` automatically
- `MiniCssExtractPlugin` -> extracts CSS into separate files
- `DefinePlugin` -> defines global constants

5. Tree Shaking - removes unsused code from your final bundle. Works with ES modules (`import/export`) but not CommonJS (`require`)

6. Hot Modules Replacement (HMR) - lets you see code changes instantly without full page reloads, improving development speed.


### Popular Module Bundlers
[[Webpack]]
[[Vite]]
[[Parcel]]
[[Rollup]]


### What you need to know:

1. Entry & Output: know where your app starts and where the bundle goes
2. Loaders/Plugins: you need TS and JSX support at minimum (for frontend)
3. Dev vs Prod: bundlers often have different configs for development (fast, with HMR) and production (optimized, minified)
4. Code Splitting: load only what's needed per page/component to reduce bundle size
5. Assets: Images, fonts, CSS can be imported directly into JS
6. Module formats: understand `ESM` vs `CommonJS` when importing third-party libraries
7. Source maps: enable them to debug original TS/JSX code instead of bundled code
