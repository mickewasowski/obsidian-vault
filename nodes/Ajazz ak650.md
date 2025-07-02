---
aliases:
context:
- "[[Keyboard]]"
- "[[Linux]]"
---


# Ajazz ak650

Mechanical keyboard

---
> There was an issue where the f1-f12 buttons weren't working. The fn key was mapping them to some other keys.
> I fixed it by installing `keyd` and then I edited this file:
```
/etc/keyd/ajazz-ak650.conf

paste this in the file:

[ids]
*

[main]
brightnessdown   = f1
brightnessup     = f2
launcha             = f3
launchb             = f4
kbdillumdown   = f5
kbdillumup     = f6
prevsong           = f7
playpause           = f8
nextsong           = f9
mute           = f10
volumedown    = f11
volumeup            = f12
```

The above fixed most of the keys.

`sudo evtest` this helps with listing all the button events

> Interesting thing is that when I connect the keyboard to my PC with 2.4GHz dongle all works fine. There must be some issue with the cable connection.
