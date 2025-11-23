---
aliases:
context:
- "[[Computer science]]"
---

# Computer Memory from Transistors

---
### Basic storing of memory with Transistors

![[Pasted image 20251123165046.png]]
In an OR gate the output is 0 if and only if both inputs are 0.
In the above example the circuit is remembering that the input was set to 1 at some point. Once set to 1 cannot be reset to 0.

The below example show a simple diagram for setting a value to be stored:
![[Pasted image 20251123172343.png]]
With this approach you can store either a 1 or a 0.


### Gated Latch

A Gated latch is able to store 1 bit of information.
 ![[Pasted image 20251123172817.png]]
In this example the Data will be ignored if the Write enable is set to 0, this way it persists the stored data. If Write enable is set to 1 then the stored data will be updated with the value of Data.
As long as the Transistors that make up this gate are connected to the current the value will be remembered.

To store 1 byte of information we can employ 8 latches and combine all of their write enable inputs into a single input that we can use to override all individual latches at once.

A collection of latches interconnected in this way is called a *Register*.
In this example an 8 bit register.
Registers are often liken (compared) to variables integrated directly into the hardware circuitry.
Ultimately they all consist of logic gates composed of transistors interconnected in a clever manner to retain values.
The quantity of latches within a register determines it length which can vary.
Larger registers imply an increase in both inputs and outputs.
Achieving a 1GB of storage capacity would require a big register with millions of wire for data inputs and outputs. If we want to remember bigger amounts of data we need another solution.

Instead of arranging latches in a linear array, we'll organize them in a 4x4 matrix totaling 16 latches. Our task now is to establish a method for identifying each one.
To accomplish this we'll use 4 wires for columns and 4 wires for rows. By activating a single wire in both the column and row we can pinpoint a unique latch in the matrix.

A Binary decoder when given an input activates only one of its outputs. By employing one decoder for rows and one decoder for columns we can input an address to select a specific latch in the matrix.
Now we need to identify a method to read and write in each latch. To do this we need to create a new input to let us toggle between reading/writing to the latch. Activating the read enable signal configures the Data line as an output.
When the read enable is 0 the Data line serves as an input. Then we can activate the Write enable and now we can override the value stored in the latch.
![[Pasted image 20251123175712.png]]

Now we can implement this modification to each latch in the matrix, connecting all Write enables to a single line, and respectively the Data in/out and Read enable.
This way we can set the data of all 16 latches at once without employing additional wires to each latch.
![[Pasted image 20251123180255.png]]

However making all the latches remember the same value is not the behavior we want. We need each latch to remember it's own value.
We know how to use the decoders to identify a specific latch. Now with the help of some AND gates we can ensure that only the correct Write enable and Read enable signals reach only the intended latch specified in the Address input.
As soon as the address input changes the AND gate obstructs any passage of input signals through this point.
![[Pasted image 20251123180928.png]]
![[Pasted image 20251123181056.png]]

![[Pasted image 20251123181304.png]]
At this point we are dealing with single bits. The minimum data a computer handles are bytes.
To store bytes instead of bits we can use 8 matrices. All these matrices will share the same address input allowing us to select corresponding latches across the matrices using the same address.
The read enable and write enable inputs should also be shared as we want to read or write an entire byte not just individual bits.
Each matrix will have its own data line providing access to any bit within the byte. 

When we write programs we don't need to concern ourselves with the underlying electronic matrix etched into the hardware. Instead we think of bytes as sequences of bits stored contiguously thus we abstract this further and conceptualize memory as a list of bytes.
In this abstraction addresses aren't intersections in an unseen matrix but rather indices in this list of bytes.
This is called Random Access Memory (RAM) since we can point to any random byte in the list by providing its address.
To simplify things we can define these sets of wire as a bus. The width of the address bus determines how many bytes we can handle.
For example with an 8 bit address bus using two decoders each capable of controlling 16 different outputs we can locate any of 256 bits within the matrix.
Generally if the address bus has N inputs two to the power of N bytes can be managed.
For instance a 32-bit wide address bus can address 4 billion bytes which explains why 32-bits computers can only handle up to 4 GB of RAM.

The type of RAM explained in this document is known as Static RAM.
This type of memory is very fast but all these logic gates require quite a few transistors so the production cost is higher.

Turns out that those small memory cells in the matrix can also be achieved using a single special transistor called a mosfet and a capacitor.
It is cheaper to produce but it is slower than static RAM.