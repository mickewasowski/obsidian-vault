---
aliases:
context:
- "[[JavaScript]]"
- "[[Web Development]]"
---

# Fetch API

The Fetch API is the new way for JS in browsers to make HTTP requests.
Fetch uses Promises, making code that waits for data cleaner.
It handles different data types and request methods (e.g. GET, POST, etc.)

---
- Replaces `XMLHttpRequest`
- Returns a **Promise** that resolves to a `Response` object

#### Syntax
``` js
fetch(url, options)
  .then(res => { /* handle response */ })
  .catch(err => { /* handle error */ });
```

#### Basic GET Request
``` js
fetch("https://jsonplaceholder.typicode.com/posts/1")
  .then(response => response.json())  // parse body as JSON
  .then(data => console.log(data))
  .catch(error => console.error("Error:", error));
```
- `response.json()` also returns a **Promise**, so you need another  `.then()`
- common alternatives: `.text()`, `.blob()`, `.arrayBuffer()`


#### Async/Await style (cleaner)
``` js
async function getPost() {
  try {
    const res = await fetch("https://jsonplaceholder.typicode.com/posts/1");
    if (!res.ok) throw new Error("Network response not ok");
    const data = await res.json();
    console.log(data);
  } catch (err) {
    console.error("Fetch failed:", err);
  }
}
```
- Always check `res.ok` (status 200-299), because fetch **only rejects on network errors**, not on HTTP errors like `404`


#### POST requests (sending data)
``` js
async function createPost() {
  const res = await fetch("https://jsonplaceholder.typicode.com/posts", {
    method: "POST",
    headers: {
      "Content-Type": "application/json"  // tell server you’re sending JSON
    },
    body: JSON.stringify({
      title: "New Post",
      body: "This is the body",
      userId: 1
    })
  });

  const data = await res.json();
  console.log(data);
}
```


#### Common options
``` js
fetch(url, {
  method: "POST",
  headers: {
    "Content-Type": "application/json",
    "Authorization": "Bearer token123"
  },
  body: JSON.stringify({ key: "value" }),
  credentials: "include" // for cookies (cross-origin needs CORS config)
});
```

#### Error handling
``` js
if (!response.ok) {
  throw new Error(`HTTP error! Status: ${response.status}`);
}
```


#### Aborting requests
``` js
const controller = new AbortController();

fetch("/api/data", { signal: controller.signal })
  .catch(err => console.error("Aborted:", err));

// cancel
controller.abort();
```

#### Streaming & advanced usage
- `response.body` is a **ReadableStream** (for progressive data, large files)
- Useful for file downloads or chat-like streaming API


#### Best practices
- always `try/catch` or check `.ok`
- use `async/await` for readability
- set `Content-Type` header when sending JSON
- abort requests on component unmount (React), or when user cancels
- handle timeouts (fetch has none by default - you must implement manually with `AbortController`)
