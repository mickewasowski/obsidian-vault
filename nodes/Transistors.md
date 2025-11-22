---
aliases:
context:
- "[[Computer science]]"
---

# Transistors

---
### Transistors in Computing

A Transistor with three primary terminals (Collector, Emitter, Base), acts as a gatekeeper (switch) for electrical current, which flows when a small current is applied to the Base. This electrical behavior is crucial for operations in digital circuits.
By applying a small current to the base, the transistor transitions from an insulating state to a conducting state, allowing electricity to flow between the collector and emitter. This switch-like function of transistors is crucial for electronic computation without relying on mechanical movements, purely through electrical signals.

### Simple Circuits

Transistor circuits can act as gates, such as using them to operate an LED where the base terminal is an input and the emitter terminal is an output. This creates what's known as a simple gate where, for example, if the input is zero, the output is zero (LED off), and if the input is one, the output is one (LED on).


### Inverter or NOT gate

An inverted setup where the logic is flipped is called an inverter or a NOT gate. Here, if the input is zero, the LED is on, showing the output is one, and if the input is one, the LED turns off, showing the output is zero.


### Complex Circuits and Logic gates

By arranging transistors in series, multiple inputs can enforce complex logic like AND gates, where electricity flows (output is one) only when all input conditions are met.
When transistors are arranged in parallel, this forms OR gates, where electricity flows i at least one input condition is met. The nature of logic gates such as AND, OR, and NOT are essential abstractions that simplify even the most complex computational processes.


### Combination of Logic gates

Using these basic gates as building blocks, you can establish more intricate operations, such as XOR gates, using combinations of, for instance, AND, OR, and NOT gates. XOR gates output true only when the inputs differ.


### Logic Gates and their Functions

There are 3 base gates:
	- AND
	- OR
	- NOT
These gates form the base for computational logic and can be abstracted into "white boxes" to simplify understanding. An AND gate is realized by transistors in series requiring both inputs to be one, while OR gate uses parallel connections where any of the conducting transistor allows flow. 

All gates are as follow (in the below examples A and B represent inputs, Y represents output):
- AND `∧` - output is 1 only if all inputs are 1
`A ----|&|---- Y     B ----|&|`

- OR `∨` - outpus is 1 if at least one input is 1
`A ----|≥1|---- Y     B ----|≥1|`

- NOT `¬` - takes one input and inverts it
`A ----|>o---- Y`
(“>o” represents the inversion bubble.)

- NAND `⊼` - AND followed by NOT, output is 0 only if all inputs are 1. All digital circuits can be built only from NAND gates
`A ----|&o|---- Y     B ----|&o|`

- NOR `⊽` - OR followed by NOT, output is 1 only if all inputs are 0
`A ----|≥1o|--- Y     B ----|≥1o|`

-  XOR `⊕` - exclusive OR, output is 1 if the inputs are different
` A ----=1|----- Y       B ----=1|`

-  XNOR `⊙` - exclusive NOR, output is 1 when the inputs are the same
` A ----=1o|---- Y       B ----=1o|`


### Binary addition with Adders

Binary addition is facilitated using these logic gates. XOR and AND gates feature prominently to construct adders, devices essential for arithmetic operations.
A half adder can add two single binary digits (bits) and produce a sum and carry value but fails to manage carry from previous calculations.
This limitation necessitates the creation of a full adder, accommodating both summation and carry, and enabling a multi-digit binary addition through series of full adders.
Full adders expand on this by handling three inputs: two binary digits and an additional carry-in value from prior calculations.
The incredible speed and compactness of transistors make them ideal for efficiently executing these tasks.   


### Overflow in Binary Addition

Dealing with numerical overflow is a key function of these adders. Overflow indicates when a sum exceeds the allocated bit storage, reminiscent of storage oversights that can be catastrophic if unchecked, like in computing errors that caused historical mishaps in technology and aerospace.


### Binary Decoders and Instruction handling

Introducing components like binary decoders enables the controlled activation of specific operations based on binary input signatures, which help CPUs interpret and process instructions logically.


### Arithmetic Logic Unit (ALU)

These principles coalesce into the design of Arithmetic Logic Units (ALUs) within CPUs. The ALU manages various operations determined by opcode (operation code), routing calculations and controlling logical functions efficiently.