---
aliases:
context:
- "[[Linux]]"
---

# curl

Transfer data from/to a server.
Stands for Client URL. It's used to make HTTP requests from the terminal.

---
``` bash
curl https://api.example.com/data
```
Makes a GET request and prints the response.

#### Common uses:
- -X => specify request method (e.g. POST)
- -d => send data (usually with POST)
- -H => add headers
- -o => save output to a file

Example:
``` bash
curl -X POST -H "Content-Type: application/json" \
     -d '{"name": "chatgpt"}' https://api.example.com/create
```