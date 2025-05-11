---
aliases:
context:
-"[[neovim]]"
---

#wip

# Mason

ad

---
When I was getting this error:
```
Registry installation failed with the following error: GitHubRegistrySource(repo=mason-org/mason-registry) failed to install: ENOENT: no such file or directory: /home/rosen-yorgov/.local/share/nvim/mason/registries/github/mason-org/mason-registry/registry.json.zip
```

I tried many things but the only thing that seemed to help was deleting the lazy-lock.json file.