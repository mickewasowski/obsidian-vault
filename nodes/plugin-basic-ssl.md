---
aliases:
context:
- "[[Vite]]"
---

# plugin-basic-ssl

Auto-generates a SSL basic certificate that is self-signed.

---
### Overview

This is a plugin from Vite's fleet that allows you to run your local dev server over HTTPS with almost *zero* setup.


### What it does

At it's core:
- automatically generates self-signed SSL certificate
- enables HTTPS for your Vite local dev server
- lets you test features that require secure contexts (like service workers, cookies, WebAuthn, etc.)

> [!warning] The certificate is **untrusted** and your browser will show a warning which you must manually bypass.


Example config in `vite.config.ts`:
``` js
import basicSsl from '@vitejs/plugin-basic-ssl'

export default {
  plugins: [basicSsl()]
}
```
