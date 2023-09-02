# EF_PSRAM_CTRL_V2
Pseudostatic RAM (PSRAM) is DRAM combined with a self-refresh circuit. 
    It appears externally as slower SRAM, albeit with a density/cost advantage 
    over true SRAM, and without the access complexity of DRAM.

The controller was designed after:
- https://www.issi.com/WW/pdf/66-67WVS4M8ALL-BLL.pdf and
- https://www.microchip.com/en-us/parametric-search/514

utilizing SPI, QSPI and QPI modes.

The controller was verified against the Verilog model of Microchip M23LC1024 for SPI and QPI modes only.

## Features
- Small in size (800 cells)
- Supports PSRAM or serial SRAM memories up to 8MBytes.
- Programmable to configure: read/write commands, number of wait states, enter and exist quad i/o commands.

## Memory Map
|Region|Description|
|------|-----------|
|```0x07FF_FFFF - 0x0000_0000```| Data Access |
|```0x0FFF_FFFF - 0x0800_0000```| COnfiguration Registers|
## Configuration Registers
| Address | Description |
|---------|-------------|
|```0x0080_0100```|RD Command Register|
|```0x0080_0200```|WR Command Register|
|```0x0080_0400```|Enter QPI Command Register|
|```0x0080_0800```|Exit QPI Command Register|
|```0x0080_1000```|Wait States Register|
|```0x0080_2000```|I/O Mode Register, {qpi, qspi}|
|```0x0080_4000```|Initiate Enter QPI (EQPI) Mode process Register|
|```0x0080_8000```|Initiate Exit QPI (XQPI) Mode process Register|

## Operation
Out of reset, the controller is in the standard SPI mode which is supported by all SPI memories. 

Performing a memory read or a memory write from/to the data region will trigger the corresponding SPI command and is fully transparent. To the CPU it is a normal memory/read operation.

### Switch to QPI mode
1) Set RD/WR/Enter QPI/Exit QPI commands by writing to the corresponding configuration registers based on the memory supported command (consult the datasheet).
2) Set the number of wait states used by the read command by writing to the Wait States Register.
3) Write "1" to the Initiate EQPI Mode process register.
4) Perform a memory read/write to a data address
5) Write "0" to the Initiate EQPI Mode process register.
6) Wait for the memory to switch to quad i/o mode. Consult the datasheet to obtain the wait value.
7) Write "2" to the i/o mode register

