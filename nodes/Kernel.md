---
aliases:
context:
- "[[Computer science]]"
---

# Kernel

---
A kernel is the core component of an operation system. It sits between user-level applications and the hardware, acting as the system's central authority and coordinator.

### What the Kernel does

1. Process and CPU management
- creates and terminates processes
- schedules which process or thread runs on the CPU
- performs context switching (saving/restoring CPU state)
- enforces isolation so one process cannot interfere with another
This is why multiple applications can "run at the same time" on one machine.

2. Memory management
- allocates and frees RAM
- implements virtual memory
- maps virtual addresses to physical memory
- enforces meory protection (processes cannot read/write each other's memory)
This is why a crashing app ussually does not crash the entire system.

3. Hardware abstraction
- provides a uniform interface to hardware
- uses device drivers to control disks, GPUs, network cards, keyboards, etc.
- translates high-level requests ("write to file") into low-level hardware operations
Applications never talk to hardware directly.

4. System calls (syscalls)
The kernel exposes a controlled API called system calls that user programs use to request privileged operations:
- file I/O (read/write)
- process creation (fork, exec)
- networking (send, recv)
- memory allocation (mmap)
User code runs in user mode; kernel code runs in kernel mode with full privileges.

5. File systems
- manages files systems (ext4, NTFS, FAT, etc.)
- handles permissions and access control
- caches disk data for performance
To an application, files look like simple byte streams; the kernel handles the complexity.

6. Security and isolation
The kernel enforces:
- user permissions
- process isolation
- access control to memory, devices, and files
This is the foundation of OS security.

#### Kernel space vs user space:
- user space: applications, browsers, editors, servers
- kernel space: OS core with unrestricted access to hardware
A strict boundary exists; crossing it requires a syscall.

#### Types of kernels (briefly)

- monolithic kernel (Linux): most services run in kernel space -> fast, complex
- microkernel (MINIX, seL4): minimal kernel, more in user space -> safer, slower IPC
- hybrid kernel (Windows, macOS): mix of both approaches


#### Simple mental model

We can think of the kernel as:
- a traffic controller for CPU time
- a memory accountant
- a security guard
- a translator between software and hardware
Without a kernel, applications would need to manage hardware themselves - which is unsafe and impractical.
