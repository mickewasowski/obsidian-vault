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


