---
aliases:
context:
- "[[Windows]]"
- "[[New disk partition]]"
---

#wip

# Disk initialization

ad

---
When you can't initialize a new SSD/HDD from the Disk management UI you can perform the following from the Command prompt:
``` powershell
// step 1
diskpart

// step 2
list disk

// step 3 (here you need to choose the disk you want to format)
select disk X

// step 4 (this will clear any data on the disk)
clean

// step 5
create partition primary

// step 6
format fs=ntfs quick

// step 7
assign letter=Z

// step 8
exit

```