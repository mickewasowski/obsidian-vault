---
aliases:
context:
  - "[[Frontend]]"
  - "[[Web Development]]"
---

# Image caching

Image caching reduces server load and bandwidth by storing assets locally. For a frontend dev, the goal is to balance **speed** (keeping things cached) with **freshness** (ensuring users see updates).

---

## 1. The Header Powerhouse

The browser's behavior is dictated by HTTP headers sent from the server.

> [!abstract] Key Headers
>
> - **`Cache-Control`**: The "Boss" header.
> - `max-age=31536000`: Cache for 1 year (standard for static assets).
> - `immutable`: Tells the browser the file will _never_ change.
> - **`ETag`**: A digital fingerprint. The browser asks "Does ETag X still match?"
> - **`304 Not Modified`**: The server's response when the cache is still valid (saves download time, but still costs a "round trip" request).

---

## 2. Cache Invalidation (The Hard Part)

Because browsers won't check the server for a "fresh" file if `max-age` hasn't expired, you must change the URL to force an update.

### Strategies

1. **Fingerprinting (Recommended):**

- Filename: `hero-v1.jpg` `hero-v2.jpg`
- Tools like Webpack/Vite do this automatically: `logo.89d2b1.png`.

2. **Query Strings:**

- `style.css?v=1.2`
- _Warning:_ Some CDNs ignore query strings, making this less reliable than renaming.

---

## 3. Frontend Implementation

### The `loading` and `decoding` Attributes

Modern HTML gives us direct control over how images enter the cache/memory.

```html
<img src="photo.webp" loading="lazy" decoding="async" alt="Description" />
```

### Service Workers (PWA)

For offline support or fine-grained control, use the **Cache API**.

> [!tip] Caching Strategies
>
> - **Cache First:** Use for icons/UI. Check cache, fallback to network.
> - **Stale-While-Revalidate:** Show the cached image immediately, but fetch a new one in the background for the _next_ visit.

---

## 4. Performance Checklist

- [ ] **Modern Formats:** Use WebP/AVIF (smaller files = faster cache writes).
- [ ] **Responsive Images:** Use `srcset` so mobile users don't cache 4K desktop images.
- [ ] **CDN:** Ensure images are served via a CDN (Cloudflare, Akamai) to cache at the "edge."
- [ ] **DevTools Check:** Open Network Tab Look for `(disk cache)` or `(memory cache)` in the Size column.

---

## 🛠️ Summary Table

| Method             | Speed   | Complexity | Best For               |
| ------------------ | ------- | ---------- | ---------------------- |
| **Browser Cache**  | Fast    | Low        | Everything             |
| **Memory Cache**   | Instant | Low        | Assets on current page |
| **Service Worker** | Fast    | High       | Offline / PWAs         |

---

Would you like me to generate a **JavaScript boilerplate** for a Service Worker that implements the "Stale-While-Revalidate" strategy for your images?
