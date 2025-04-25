---
aliases:
context:
---

#wip

# neovim

ad

---
## Initial setup (video 1):

### Setup

1.  Install neovim (for the respective OS)
2. Create init.lua file

> [!warning] Keep in mind the below is the configuration for Linux/macOS

We put the init.lua in the below directory:
`~/.config/nvim/init.lua`

`nvim ~/.config/nvim/init.lua` this is how we open the file
and then we write the file with `:w`

lua file contents:
``` vim
vim.cmd("set expandtab")
vim.cmd("set tabstop=2")
vim.cmd("set softtabstop=2")
vim.cmd("set shiftwidth=2")
```
and then we type `:source %` and this is how we can run vim code in a lua file and then source it


3. Install package manager (neovim package manager)

There are two main managers - packer and lazy.
Mainly lazy is used.

We need to add the following to the *init.lua* file if we want the Single file setup structure:
``` vim
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not (vim.uv or vim.loop).fs_stat(lazypath) then
  local lazyrepo = "https://github.com/folke/lazy.nvim.git"
  local out = vim.fn.system({
	  "git",
	  "clone",
	  "--filter=blob:none",
	  "--branch=stable",
	  lazyrepo,
	  lazypath
  })
  if vim.v.shell_error ~= 0 then
    vim.api.nvim_echo({
      { "Failed to clone lazy.nvim:\n", "ErrorMsg" },
      { out, "WarningMsg" },
      { "\nPress any key to exit..." },
    }, true, {})
    vim.fn.getchar()
    os.exit(1)
  end
end
vim.opt.rtp:prepend(lazypath)

local plugins = {}
local opts = {}

require("lazy").setup(plugins, opts)
```

Now when we are in neovim we have the `:Lazy` command available. 

4. Next is to add a colorscheme (catppuccin is recommended)
In order to install it we need to add the tupple for catppuccin in the plugins variable in the init.lua file as follows:

``` vim
local plugins = {
	{ "catppuccin/nvim", name = "catppuccin", priority = 1000 }
}
```

Then we need to quit nvim and reload the file as follows:

`nvim ~/.config/nvim/init.lua` and then we'll see how Lazy automatically detects and installs catppuccin.

Now with the above we have only installed catppuccin, now we need to require it in order to start using it. What we need to do now is add a require statement below the require for the Lazy setup:

``` vim
require("catppuccin").setup()
vim.cmd.colorscheme "catppuccin"
```

Now we again need to reopen the init.lua file.

5. Now we need to add fuzzy find (telescope)
*This is used to search words in files, and many more other functionalities*
`You can see all it's functionalities by typing :Telescope`
Simply add the Telescope tupple to the plugins (as for the catppuccin)
```
	{
	    'nvim-telescope/telescope.nvim', tag = '0.1.8',
	      dependencies = { 'nvim-lua/plenary.nvim' }
	}
```
Now again reopen nvim with the init.lua file
Now we need to initialize it by creating a local variable below the require for lazy and then set the keymap and then source the file:
```
local builtin = require("telescope.builtin")
vim.keymap.set('n', '<C-p>', builtin.find_files, {})
```
Now *ctrl + p* will open the fuzzy search.

6. Now we need to set live grep
*This is used to search files by name*
Add the keymap below the telescope keymap:
`vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})
And also add below the vim.cmd commands the following:
`vim.g.mapleader = " "`

Now to open live grep you type space + fg

7. Now we add a package for highlighting and indenting (treesitter)
Add the bellow to the plugins object:
``` vim
{"nvim-treesitter/nvim-treesitter", build = ":TSUpdate"}
```

You can run `:TSUpdate` to update all your packages. 

Add the below after the keymap for live_grep:
``` vim
local config = require("nvim-treesitter.configs")
config.setup({
  ensure_installed = {"lua", "javascript"},
  highlight = { enable = true },
  indent = { enable = true },
})
```



### Final init.lua file:
``` vim
vim.cmd("set expandtab")
vim.cmd("set tabstop=2")
vim.cmd("set softtabstop=2")
vim.cmd("set shiftwidth=2")
vim.g.mapleader = " "

local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not (vim.uv or vim.loop).fs_stat(lazypath) then
  local lazyrepo = "https://github.com/folke/lazy.nvim.git"
  local out = vim.fn.system({
	  "git",
	  "clone",
	  "--filter=blob:none",
	  "--branch=stable",
	  lazyrepo,
	  lazypath
  })
  if vim.v.shell_error ~= 0 then
    vim.api.nvim_echo({
      { "Failed to clone lazy.nvim:\n", "ErrorMsg" },
      { out, "WarningMsg" },
      { "\nPress any key to exit..." },
    }, true, {})
    vim.fn.getchar()
    os.exit(1)
  end
end
vim.opt.rtp:prepend(lazypath)

local plugins = {
	{ "catppuccin/nvim", name = "catppuccin", priority = 1000 },
	{
   'nvim-telescope/telescope.nvim', tag = '0.1.8',
    dependencies = { 'nvim-lua/plenary.nvim' }
	},
  { "nvim-treesitter/nvim-treesitter", build = ":TSUpdate" }
}
local opts = {}

require("lazy").setup(plugins, opts)
require("catppuccin").setup()
vim.cmd.colorscheme "catppuccin"
local builtin = require("telescope.builtin")
vim.keymap.set('n', '<C-p>', builtin.find_files, {})
vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})

local config = require("nvim-treesitter.configs")
config.setup({
  ensure_installed = {"lua", "javascript"},
  highlight = { enable = true },
  indent = { enable = true },
})
```



#### Setup TODO:
- [x] install neovim
- [x] create init.lua file
- [x] setup the tab spacing
- [x] provide the Lazy configuration
- [x] add catppuccin
- [x] add telescope for fuzzy find
- [x] add livegrep
- [x] add treesitter




## Follow-up setup (video 2):

1. Neotree (file explorer)
Add the below to the plugins object in init.lua:
```
{
    "nvim-neo-tree/neo-tree.nvim",
    branch = "v3.x",
    dependencies = {
      "nvim-lua/plenary.nvim",
      "nvim-tree/nvim-web-devicons",
      "MunifTanjim/nui.nvim",
    },
    lazy = false,
}
```

Also add keymap:
``` vim
vim.keymap.set('n', '<C-n>', ':Neotree filesystem reveal left<CR>', {})
```

Now we can open the filesystem with `Ctrl + n` and then press `a` to add a file.
We need to create a folder lua with a *plugins.lua* file
Then we paste these contents (the contents of the plugins variable)
``` vim
return {
	{ "catppuccin/nvim", name = "catppuccin", priority = 1000 },
	{
   'nvim-telescope/telescope.nvim', tag = '0.1.8',
    dependencies = { 'nvim-lua/plenary.nvim' }
	},
  { "nvim-treesitter/nvim-treesitter", build = ":TSUpdate" },
  {
    "nvim-neo-tree/neo-tree.nvim",
    branch = "v3.x",
    dependencies = {
      "nvim-lua/plenary.nvim",
      "nvim-tree/nvim-web-devicons",
      "MunifTanjim/nui.nvim",
    },
    lazy = false,
  }
}
```

Then we change the init.lua requirement for lazy like so:
`require("lazy").setup("plugins")`

Then we create a new `plugins` folder in the `lua` folder
There we cut and paste the catppuccin plugin configuration:

``` vim
	return {
    "catppuccin/nvim",
    lazy = false,
    name = "catppuccin",
    priority = 1000,
    config = function()
      vim.cmd.colorscheme "catppuccin"
    end
  }
```














