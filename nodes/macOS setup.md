---
aliases:
context:
---

# macOS setup

---

#### Neovim

1. install Homebrew
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
2. add Homebrew to PATH
```bash
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"
```
3. confirm Homebrew version
```bash
brew --version
```
4. install Neovim
```bash
brew install neovim

nvim --version
```
4. common Neovim dependencies
```bash
brew install ripgrep
brew install fd
brew install node
brew install lazygit   # optional
brew install fzf       # optional
brew install tree      # optional
```


#### Alacritty

1. install Alacritty
```bash
brew install --cask alacritty
```
2. verify version
```bash
alacritty --version
```


#### Tiling assistant

1. Rectangle setup - installation guide
> Download Rectangle - Go to `https://rectangleapp.com`
> Launch it

> Grant required macOS permission
- When prompted, allow **Accessibility** access
- Or manually: **System Settings** → **Privacy & Security** → **Accessibility** → enable **Rectangle**
- This is required for window movement/resizing shortcuts to work

> Set it to start automatically
- In Rectangle preferences, enable **Launch on login**
- Optional but recommended so shortcuts always work

> Apply the Linux-like keybind scheme
- Open Rectangle preferences → **Shortcuts**
- Set your chosen modifier (for example `Control + Option + Command`) and map:
  - Left Half / Right Half
  - Top Left / Top Right / Bottom Left / Bottom Right
  - Maximize
  - Center or Restore
  - Larger / Smaller

2. Rectangle setup - keybinds
Use this modifier combo for all window actions:  
`Control + Option + Command` (so shortcuts don’t clash much with macOS defaults)

- `⌃⌥⌘ + ←` → Left half  
- `⌃⌥⌘ + →` → Right half  
- `⌃⌥⌘ + U` → Top-left corner  
- `⌃⌥⌘ + I` → Top-right corner  
- `⌃⌥⌘ + J` → Bottom-left corner  
- `⌃⌥⌘ + K` → Bottom-right corner  
- `⌃⌥⌘ + ↑` → Maximize  
- `⌃⌥⌘ + ↓` → Restore/Center (pick whichever you use more)

For the “adjust width/height” feel (grow/shrink while anchored):

- `⌃⌥⌘ + =` → Larger  
- `⌃⌥⌘ + -` → Smaller  
- `⌃⌥⌘ + [` → Almost maximize height / taller  
- `⌃⌥⌘ + ]` → Smaller height / shorter

In Rectangle settings, bind these to:
- `Left Half`, `Right Half`
- `Top Left`, `Top Right`, `Bottom Left`, `Bottom Right`
- `Maximize`, `Center` (or `Restore`)
- `Larger`, `Smaller`


#### Virtual desktops (Workspaces)

MacOS equivalent is *Spaces* (on Mission Control).

**1) Turn on and use Spaces (virtual desktops)**
- Open **System Settings** → **Desktop & Dock**.
- Scroll to **Mission Control**.
- Keep **Displays have separate Spaces** = ON (good default).
- Open **Mission Control** (`Control + Up`) and click `+` top-right to add desktops.
- Put related windows/apps in each Space (drag windows in Mission Control).

**2) Make app switching less “global”**
- In **Desktop & Dock** → **Mission Control**, set:
- **When switching to an application, switch to a Space with open windows for the application** = **OFF**
  (this prevents macOS from constantly jumping to other Spaces when app-switching)

**3) Install AltTab (best Linux-like window switcher)**
- Download from: `https://alt-tab-macos.netlify.app`
  (or Homebrew: `brew install --cask alt-tab`)
- Launch AltTab and allow permissions when prompted.

**4) Grant required permissions**
- **System Settings** → **Privacy & Security** → **Accessibility** → enable **AltTab**.
- Also enable **Screen Recording** for AltTab if requested (needed for live window previews).

**5) Configure AltTab to current Space only**
In AltTab Preferences:
- **Controls / Shortcut**: set main switcher shortcut to `Option + Tab` (recommended), keep macOS `Cmd + Tab` unchanged.
- **Policy / Scope** (wording may vary by version):
  - Show windows from: **Current Space** (not all spaces)
  - Exclude minimized/hidden windows if you want cleaner cycling
- Optional: set appearance to list style if you prefer a lighter, Linux-like switcher.

**6) Set your workspace navigation shortcuts**
- Space switching: `Control + Left/Right`
- Mission Control overview: `Control + Up`
- Window switch in current Space: your AltTab shortcut (e.g. `Option + Tab`)

That gives you the closest macOS equivalent to your GNOME workflow: **Spaces + Space-local window switching**.

If you want, I can give you a **final keybind map** (Linux-to-mac translation table) so muscle memory is easier for the first week.
