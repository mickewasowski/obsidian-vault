---
aliases:
context:
---

# deep linking

---
### Overview

Deep linking is using a link (usually a URL) that opens a specific piece of content inside a website or app, instead of just opening the home screen.

A deep link carries navigation state (path + parameters) so the app can land you directly on the right screen, for example a specific product, a specific settings page, or a specific comment thread.


### Why it matters

- Shareable/bookmarkable links to exact screens
- Email/push/ads can open the right place in the app
- In SPAs, makes refresh and back/forward navigation map to real screens


### Types

1. Web deep links
   - Regular URLs that point to a specific route, e.g. `https://example.com/settings/billing`

2. App deep links (custom URL schemes)
   - URLs like `myapp://settings/billing` that the OS routes to an installed app
   - If the app is not installed, the link typically fails unless you build a fallback

3. Universal Links (iOS) / App Links (Android)
   - Normal `https://...` links that open the app when installed, otherwise open the website


### How it works (high level)

1. The link encodes where to go (path) and optional parameters (`?query=...`, `#hash`).
2. The browser/OS decides which handler should open it (website vs app).
3. The app/router parses the URL and maps it to a screen, then loads any needed data.


### Common pitfalls

- Cold start/auth: the app opens before you have user state; queue the navigation until ready
- Fallbacks: custom-scheme links do nothing when the app is not installed
- Security: never trust link parameters; validate and avoid putting secrets in URLs
- Route changes: without redirects, old deep links break ("link rot")


### Examples

- `https://shop.example.com/product/123?ref=email`
- `myapp://invite?code=ABC123`
- `https://example.com/invite/ABC123` (opens app via Universal Link/App Link when installed)

---
