---
aliases:
context:
- "[[Linux]]"
- "[[Linux-distros]]"
---

# Ubuntu

Free and open-source Linux-based OS.

---
Ubuntu is a free and open-source Linux-based operating system developed by Canonical. It's known for its ease of use, security, and regular updates, making it popular for both beginners and experienced users. Ubuntu comes with a user-friendly interface and pre-installed software for everyday tasks like web browsing, email, and document editing. It is widely used on personal computers, servers, and even in cloud computing environments.


## Install from .deb file

Steps:
1. open terminal
2. navigate to the files folder
3. install it with `sudo dpkg -i filename.deb`
4. fix dependencies if needed `sudo apt -f install`


## Make Alacritty default terminal
Steps:
1. open terminal 
2. run `sudo update-alternatives --config x-terminal-emulator`
3. select Alacritty from the list
4. if it's not listed, add it:
   `sudo update-alternatives --install /usr/bin/x-terminal-emulator x-terminal-emulator /usr/bin/alacritty 50`