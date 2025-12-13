---
aliases:
context:
  - "[[Computer science]]"
---

# Dynamic RAM

---

Understanding Dynamic RAM: Principles, Challenges, and Operations

#### Introduction: The Fundamentals and Importance of Dynamic RAM

Dynamic Random Access Memory (Dynamic RAM or DRAM) —a vital type of computer memory that, unlike Static RAM (SRAM), stores data using capacitors and transistors. DRAM is significant because it offers a **cost-effective** way to achieve **high memory density** by using fewer components per bit, making it the prevalent choice for main memory in computers.

- **Capacitors** are the fundamental component in DRAM, functioning as tiny energy storage devices that hold electrical charges representing binary data:
  - Charged capacitor = binary **1**
  - Discharged capacitor = binary **0**
- The **MOSFET (Metal-Oxide-Semiconductor Field-Effect Transistor)** acts as a switch to control charging and discharging of the capacitor.
- DRAM’s simplicity—using one transistor and one capacitor per bit—enables packing more memory cells into a given chip area, unlike SRAM that uses multiple transistors to trap data without capacitors.

- However, this efficiency comes with challenges, mainly because reading DRAM is a **destructive process** that discharges capacitors, requiring careful management to maintain data integrity.


#### Section 1: The Basic Components of Dynamic RAM

  At its core, a **DRAM memory cell** consists of:
- A **capacitor** capable of storing electrical charge temporarily (like a tiny battery but with short retention time).
- A **MOSFET transistor** that acts as a gate controlling the flow of charge to and from the capacitor.

- The MOSFET has three terminals: **gate, source, and drain**.
- Applying voltage to the gate allows current flow between source and drain, enabling the capacitor to be charged or discharged.
- This simple arrangement stores one bit of information: a charged capacitor represents a 1, a discharged capacitor represents a 0.

- This design contrasts with SRAM, which uses multiple transistors in a latch configuration to store bits as stable electrical signals without the need for capacitors.


#### Section 2: Advantages and Disadvantages of Dynamic RAM

  **Advantages:**
- DRAM’s single-transistor-and-capacitor cell leads to **higher density** and **lower manufacturing cost** compared to SRAM.
- This enables larger memory capacities in smaller physical spaces.

**Disadvantages:**

- Reading a DRAM cell is a **destructive operation** because it involves discharging the capacitor to detect its voltage, which means the data is lost during the read.
- The need to restore data after reading adds complexity.
- Additionally, DRAM cells gradually lose charge due to leakage currents—even when not accessed—which necessitates **periodic refreshing** to maintain data integrity.


#### Section 3: Organizing DRAM Cells in a Matrix and Addressing Mechanisms

  To manage billions of cells efficiently, DRAM cells are arranged in a **matrix** of rows and columns:
- Each **row** is connected via a **word line** (gate control line).
- Each **column** is connected via a **bit line** (source connections).

- Selecting a particular cell involves:
  - Activating one word line (row).
  - Activating one bit line (column).
- This selection is enabled by **binary decoders**, which use logic gates to translate binary addresses into specific row and column activations.

- However, reading an entire row simultaneously causes all capacitors in that row to discharge, complicating the reading process and risking data loss.


#### Section 4: Reading Data from Dynamic RAM without Destroying It

  DRAM mitigates destructive reads through a multi-step process:
- **Precharging bit lines** to half the operating voltage (e.g., 0.5 V if 1 V represents binary 1).
- When a word line is activated, all capacitors in that row connect to the bit lines:

  - Cells storing 1 slightly discharge into the bit line, increasing its voltage.
  - Cells storing 0 pull charge from the bit line, decreasing its voltage.

- A special circuit called a **sense amplifier** detects these subtle voltage differences on each bit line and amplifies them to full logic levels (0 or 1).
- The sense amplifier stores the detected value in a **latch**, preserving it even if the bit line voltage changes again.

- To select a specific bit from the entire row output, a **multiplexer (mux)** is used, controlled by part of the address, to route the correct bit value to the output.
- After the read, the data stored in the latches is written back to the capacitors to **restore their charge**, thus preserving the stored information.


#### Section 5: Writing Data to Dynamic RAM

  Writing builds on the reading procedure but reverses the data flow:
- Applying the desired voltage (0 or 1 volts) to the bit lines.
- Activating the word line to enable the MOSFETs in the row, charging or discharging capacitors accordingly.

- Unlike reading, writing requires precise targeting of a specific cell, not all cells in the row, which complicates the circuitry.
- A **demultiplexer (demux)** is used for writing, directing the input data to the correct latch, while the multiplexer handles reading.

- The process involves:

  - Precharging bit lines.
  - Reading the current row data into sense amplifiers.
  - Overwriting the targeted latch with the new value.
  - Writing back all latches’ data to their corresponding capacitors, ensuring only the desired cell changes while others retain their data.

- This elaborate process ensures **data integrity** despite DRAM’s destructive read behavior.


#### Section 6: Refreshing Dynamic RAM to Prevent Data Loss

  DRAM capacitors leak charge even when not accessed, leading to inevitable data loss over time.
- To combat this, **refresh cycles** periodically read and rewrite the data of every row before charges degrade too much.
- Refreshing is essentially a read operation followed immediately by a write-back, without outputting or inputting new data.

- Because only one latch per bit line exists, rows must be refreshed **one at a time**, sequentially.
- Refresh operations temporarily block normal read/write access, causing **latency** and slowing overall memory performance compared to SRAM.

- However, refresh intervals are typically long enough (a few milliseconds) to allow thousands of normal operations before a refresh must occur again.


#### Section 7: Timing and Addressing Complexities in DRAM

  DRAM control involves complex **timing mechanisms**:
- Different parts of the address are used at different times during read/write cycles (e.g., row address first, then column address).
- The CPU’s address signals are intercepted and managed by specialized circuitry to synchronize signals correctly.

- Additionally, DRAM usually handles data in **bytes (8 bits)** rather than single bits:
- Multiplexers and demultiplexers are designed to manage entire data buses simultaneously, enabling efficient byte-wise access.


#### Conclusion: Trade-offs and Implications of Dynamic RAM

  Dynamic RAM offers **greater storage density and lower costs** than Static RAM by storing data as electrical charges in capacitors.
- However, it requires intricate circuits and timing to overcome challenges like **destructive reads**, **charge leakage**, and **refresh cycles**, making it inherently **slower than SRAM**.

- The **cache memory** inside processors is typically SRAM, chosen for speed, while main memory uses DRAM for capacity and cost-effectiveness.
- This difference explains why bringing memory physically closer to the CPU (e.g., a hard drive) does not improve speed as dramatically as accessing faster memory types like SRAM.

- Understanding DRAM’s operation deepens appreciation for the complex interplay between hardware design and software performance in modern computers.


### Key Concepts Summary

- **Dynamic RAM (DRAM):** Memory storing bits as charges in capacitors controlled by MOSFETs.
- **Capacitor:** Stores electric charge representing binary data.
- **MOSFET:** Transistor acting as a switch to charge/discharge capacitors.
- **Word lines and bit lines:** Wires forming the memory matrix grid to select rows and columns.
- **Sense amplifier:** Detects minute voltage changes on bit lines to read data.
- **Multiplexer/Demultiplexer:** Circuits to select specific bits or route data for reading/writing.
- **Refreshing:** Periodic read-write cycles to prevent charge leakage and data loss.
- **Latency:** Delay caused by refresh cycles and complex read/write sequences.
- **Static RAM (SRAM):** Faster, more complex memory storing bits as stable electrical signals without capacitors.
