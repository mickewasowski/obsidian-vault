---
aliases:
context:
- "[[Computer science]]"
---

# Transistors

---
Transistors are the building blocks of modern computers.

### Transistors in Computing

1. Transistor basics
- a transistor has three terminals - *collector*, *emitter*, and *base*
- it operates as a switch controlled by electrical signals: no current to the base means no conduction between collector and emitter (acting as an insulator), and current to the base allows conduction (acting as a conductor)
- this switching behavior enables transistors to represent binary states (0 and 1)
2. Logic Gates from Transistors
- a single transistor can implement a simple *gate* where the output equals the input
- by changing circuit arrangements, transistors can form logic gates like:
    - *NOT gate (inverter)* - output is the opposite of input
    - *AND gate* - outputs 1 only if both inputs are 1 (series connection of transistors)
    - *OR gate* - outputs 1 if at least one input is 1 (parallel connection of transistors)
- these gates are abstracted into symbols to simplify circuit design
- *XOR gate* (exclusive or) outputs 1 when inputs differ and is key in arithmetic operations
3. Combining Logic Gates
- outputs of logic gates can feed into inputs of others to build complex circuits
- XOR gate is an example of combining simpler gates for more sophisticated behavior


### Arithmetic with Logic Gates

1. Binary addition
- binary addition rules mirror decimal addition but overflow occurs when 1 + 1 = 10 (binary two)
- to handle this, circuits output both *sum* and *carry* bits
- a *half adder* circuit uses an XOR gate for sum and an AND gate for carry but cannot handle carry input from previous additions
- a *full adder* solves this by accepting three inputs: two bits plus a carry-in, producing sum and carry-out
- multi-bit addition requires chaining full adders, passing carry-outs to the next adder's carry-in
2. Multi-bit adders
- for n-bit binary numbers, n full adders are needed
- example: an 8-bit adder sums two 8-bit inputs and outputs an 8-bit result plus an overflow (carry-out) signal
- *overflow signal* indicates if the result exceeds the storage capacity and requires extra bits
3. Speed and Practicality
- transistors are preferred for logic gates over mechanical or other alternatives due to their *speed and compactness*, enabling near-instantaneours output changes


### Instruction Interpretations: Binary decoders and CPU logic

1. Binary decoders
- these circuits take binary inputs and activate exactly one output line corresponding to that input number, deactivationg all others
- number of outputs = 2^(number of inputs). For example:
    - 3 inputs -> 8 outputs
    - 4 inputs -> 16 outputs
- decoders are essential for selecting among multiple circuit operations
2. Instruc decoding in CPUs
- instructions are binary codes (machine code), often represented by assembly language for humans
- a simple architecture example: first two bits classify instruction type (e.g. arithmetic operations), next bits specify the exact operation (opcode)
- logic gates (like NOR gates) can identify instruction categories
- the opcode is fed into a decoder inside a CPU component (referred to as "Our Mysterious Component") that enables only the relevant arithmetic logic circuit's output to pass through
- this component is simplified model of an Arithmetic Logic Unit (ALU), which performs arithmetic and logical operations based on input values and opcode


### Important insights

- Abstraction is key: moving from individual transistors to logic gates, then to adders and decoders, illustrates how complexity is managed through abstraction
- Overflow handling is critical: ignoring overflow can cause sever errors (e.g. a historical rocket accident)
- Logic gates are the foundation of all computational operations inside CPUs
- Arithmetic Logic Unit (ALU) is the central CPU component responsible for arithmetic and logic operations, controlled by opcodes decoded from instructions




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


