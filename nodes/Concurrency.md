---
aliases:
context:
- "[[Computer science]]"
---

# Concurrency

---

> [!tip] Concurrency is about dealing with lots of things at once, but parallelism is about doing lots of things at once.

### How computers handle operations

In the CPU there are special registers such as:
- Instruction register
- Address register - hold the memory location of the next instruction that the CPU will execute
When the CPU is ready for the next instruction it fetches it's value and copies it to the Instruction register. The CPU then decodes it to know what to do next - an addition, a subtraction, a copy operation, etc. After the instruction is executed, the address register value increases pointing to the next instruction.

Cycles of CPU operations:
1. Fetch
2. Decode
3. Execute

There are also Jump instructions, they change the address register value making the CPU jump to a specific instruction instead of the next one in line. This is key in dealing with conditions and loops in programs.

The OS makes the CPU switch between different programs by changing the address register value.

When a program starts running it is labeled as process. OS employs a specific data type to store the details of each running process.
These processes are lined up in a queue which is overseen by a special part of the OS known as a scheduler.
When the CPU becomes available another component called the dispatcher steps in. It selects the topmost element in the queue, reads the process information and configures the address register so that the CPU can access that process in memory.

In practice programs depend on the OS to perform essential tasks. When we use functions to open a file, read and write to it, or things like requesting memory, we are interacting with the OS.
These interactions occur through interuptions at the hardware level. Interuptions act as a signal to the CPU. When an interaction occurs the CPU pauses its current task, saves its state by taking a snapshot saving it in memory and immediately jumps to a predefined location in memory where the interupt service routine associated with that specific interuption resides.
This routine is somewhere in the memory region allocated to the OS itself.
Programs use interuptions extensively especially for I/O operations as only the OS kernel can handle interactions with hardware. This is how the OS regains control of the CPU.

Since I/O operations often take time the process that initiated the interuption is temporarily placed back in the queue while waiting for the hardware response.
But before the process' captured state is stored within the process information. Then the dispatcher selects another process from the queue and sets the CPU to execute it.
Now this process can utilize the CPU until at some point it needs some sort of I/O operation requiring giving control back to the OS.
This cycle repeats continuously until it's the turn of our process again. When the process is taken from the queue its state is read and restored in the CPU jumping to the correct location in the user program to resume exactly where it left off.

And this is the process that allows the OS to alternate CPU usage among multiple processes.


### Cooperative scheduling (Non-Preemptive Scheduling)

There is a huge problem with the above approach. Once the CPU is allocated to a process it retains control until the process voluntarily releases either by terminating or by entering a waiting state by invoking the OS.
Consider an infinite loop scenario - if there are no interuptions inside the loop the CPU will endlessly execute those instructions.
If a process intentionally or unintentionally avoids making interuptions the OS will never regain control. In modern times this poses a serius security risk as malicious programs can exploit this vulnerability to monopolize CPU resources preventing other programs from accessing them.
This scheduling method reliant on process cooperation is known as Cooperative scheduling or Non-Preemptive scheduling.
Unfortunately there is no software fix for this issue and hardware intervention is necessary to prevent any user program from completely taking over the CPU.
A hardware timer is deployed - its function is straight forward, a time limit is set and it begins counting down. Once the time expires the timer triggers an interuption.
The timer is typically implemented within the CPU itself. So before allocating the CPU to any process the OS dispatcher uses a priviledged instruction to set and start the timer.


### Multicore systems

Rapidly switching between processes can create the illusion of simultaneous execution. As the number of running processes increases the time it takes for each process to regain CPU access also increases leading to noticable lag.
There are two solutions to this issue:
- software
- hardware

The software solution is a more complex dispatcher that can help manage processes more efficiently.

For the hardware solution one option is to increase the CPU speed allowing processes to regain CPU access faster. This approach has its limits due to physical contraints.
The breakthrough came with the addition of multiple processing unints to the same chip creating multi-core systems. With multiple cores the scheduler can allocate different processors to different programs enabling true parallelism and simultaneous execution.
Despite this there still can be more processes than cores requiring Concurrency to efficiently distribute processing resources among numerous processes in multi-core systems.
