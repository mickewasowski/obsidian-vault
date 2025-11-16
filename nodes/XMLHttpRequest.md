---
aliases:
context:
- "[[JavaScript]]"
- "[[Web Development]]"
---

# XMLHttpRequest

---
### Summary
XHR is a built-in browser API for making HTTP requests from JavaScript.
It's older than `fetch`, but still used in legacy code, some libraries, and for very specific features.


### How it works

`XMLHttpRequest` is an object that allow JavaScript to make network requests to servers *without reloading the page*.
It was foundational for early "AJAX" applications.
It can send/receive *any data*, not just XML.

1. Typical flow:
``` js
const xhr = new XMLHttpRequest();

xhr.open("GET", "/api/data");

xhr.onload = () => {
  console.log(xhr.responseText);
};

xhr.onerror = () => {
  console.error("Network error");
};

xhr.send();
```

2. Ready states
- 0 - UNSENT
- 1 - OPENED
- 2 - HEADERS_RECEIVED
- 3 - LOADING
- 4 - DONE
You can track them with `xhr.onreadystatechange`.

3. Supports progress events
This is one of the main reasons XHR is still somethimes preferred:
``` js
xhr.upload.onprogress = (e) => {
  console.log(e.loaded, e.total);
};
```

4. Supports aborting requests:
```js
xhr.abort();
```

### Compared to `fetch`

1. Disadvantages
- callback-based, not promise-based
- verbose API
- response handling is less elegant
- error handling is less predictable
- no streaming response access in most browsers
- harder to cancel (though possible with `abort()`)

2. Advantages
- better upload progress events
- wide legacy support
- some older systems/libraries still rely on it

> Modern code normally uses `fetch` but file-upload progress is still a scenario where XHR is often used.


### Response types and HTTP headers

Types:
- json
- text
- blob
- document
- arraybuffer


Headers:
```js
// setting
xhr.setRequestHeader("Content-Type", "application/json");

// getting
xhr.getResponseHeader("Content-Type");
xhr.getAllResponseHeaders();
```

### Example usage

```js
const xhr = new XMLHttpRequest();
xhr.open("POST", "/api/create");

xhr.setRequestHeader("Content-Type", "application/json");

xhr.onload = () => {
  if (xhr.status === 200) {
    console.log(JSON.parse(xhr.responseText));
  }
};

xhr.send(JSON.stringify({ name: "Rado" }));
```
