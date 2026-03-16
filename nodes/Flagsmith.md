---
aliases:
context:
- "[[Web Development]]"
---

# Flagsmith

Flagsmith is a feature flag + remote configuration service. In simple terms, it gives you a control panel to turn parts of your app on/off without redeploying code.

---
### Overview

At its core, Flagsmith allows you to wrap features in "flags" (basically switches).
Then from the dashboard you can decide:
- who sees the feature
- when it turns on
- how it behaves


### Key capabilities

1. Feature flags
- turn on/off features remotely
- control them per user, segment, or % rollout
- no need to deploy new code just to change behavior

2. Gradual rollouts (safe releases)
- release to 1%, 10%, 100% of users
- catch bugs earlier before it affects everyone

3. A/B testing & experiments

4. Remote config (not just on/off)
- change values, colors, text, etc. without redeploying

5. Instant rollback ("kill switch")
- if something breaks -> flip a switch -> feature gone
- no hotfix, no redeploy

6. Works everywhere - mobile and desktop, backend
- open-source + self host or cloud
