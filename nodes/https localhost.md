---
aliases:
context:
- "[[Web Development]]"
- "[[Local development]]"
---

# Https localhost

how to make localhost app created with vite run on https

---
1. Install library for certificate generation
```
brew install mkcert nss
```
2. Create and install a local CA (one-time)
```
mkcert -install
```
3. Generate certs for localhost
```
mkcert localhost 127.0.0.1 ::1
```
> This creates files like:
> - localhost+2.pem (certificate)
> - localhost+2-key.pem (private key)

> [!tip] `::1` is the IPv6 loopback address
> you’re telling mkcert to make one cert that is valid for all three local names/addresses:
> - localhost (hostname)
> - 127.0.0.1 (IPv4 loopback)
> - ::1 (IPv6 loopback)

4. Configure your local server to use those files
``` js
import { defineConfig } from "vite";
import fs from "node:fs";
import path from "node:path";

export default defineConfig({
  server: {
    host: "localhost",
    port: 5173,
    https: {
      key: fs.readFileSync(path.resolve(__dirname, "certs/localhost+2-key.pem")),
      cert: fs.readFileSync(path.resolve(__dirname, "certs/localhost+2.pem")),
    },
  },
});
```