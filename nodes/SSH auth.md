---
aliases:
context:
---

# SSH auth

---

### Using multiple SSH keys for different _git_ providers

1. Generate a separate key per provider
```bash
   ssh-keygen -t ed25519 -f ~/.ssh/id_ed25519_bitbucket -C "your@email.com"
   ssh-keygen -t ed25519 -f ~/.ssh/id_ed25519_forgejo -C "your@email.com"
```

2. Add each public key to its provider

- ~/.ssh/id_ed25519_bitbucket.pub → Bitbucket → Personal Settings → SSH keys
- ~/.ssh/id_ed25519_forgejo.pub → Forgejo → Settings → SSH/GPG keys


3. Create/update ~/.ssh/config
   Host bitbucket.org
   HostName bitbucket.org
    User git
    IdentityFile ~/.ssh/id_ed25519_bitbucket

Host your-forgejo.com
 HostName your-forgejo.com
User git
 IdentityFile ~/.ssh/id_ed25519_forgejo

4. Test each connection
```bash
   ssh -T git@bitbucket.org
   ssh -T git@your-forgejo.com
```

---

Key thing to remember: adding a new Host block never touches existing ones, so you can keep adding providers (GitHub, GitLab, etc.) freely. I've also saved this to memory so I can
recall it in future sessions.
