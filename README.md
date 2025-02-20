# EF_PSRAM_CTRL

A Controller for Quad I/O SPI PSRAM
  Pseudostatic RAM (PSRAM) is DRAM combined with a self-refresh circuit. 
  It appears externally as slower SRAM, albeit with a density/cost advantage 
  over true SRAM, and without the access complexity of DRAM.
  The controller was designed after:
- https://www.issi.com/WW/pdf/66-67WVS4M8ALL-BLL.pdf and
- https://www.microchip.com/en-us/parametric-search/514

utilizing SPI, QSPI and QPI modes.

The controller was verified against the Verilog model of Microchip M23LC1024 for SPI and QPI modes only.

##### Features:
- Small in size (800 cells)
- Supports PSRAM or serial SRAM memories up to 8MBytes.
- Programmable to configure: read/write commands, number of wait states, enter and exist quad i/o commands.

## The wrapped IP


 The IP comes with an AHBL Wrapper

#### Wrapped IP System Integration

```verilog
EF_PSRAM_CTRL_APB INST (
	`TB_AHBL_SLAVE_CONN,
	.sck(sck)
	.ce_n(ce_n)
	.din(din)
	.dout(dout)
	.douten(douten)
);
```
> **_NOTE:_** `TB_APB_SLAVE_CONN is a convenient macro provided by [BusWrap](https://github.com/efabless/BusWrap/tree/main).
### Wrappers with DFT support
Wrappers in the directory ``/hdl/rtl/bus_wrappers/DFT`` have an extra input port ``sc_testmode`` to disable the clock gate whenever the scan chain testmode is enabled.
### External IO interfaces
|IO name|Direction|Width|Description|
|---|---|---|---|
|sck|output|1|SPI master output clock|
|ce_n|output|1|SPI Master slave select.|
|din|input|4|SPI Master data in , slave out|
|dout|output|4|SPI Master data out , slave in|
|douten|output|4|SPI Master data out enable|
### Interrupt Request Line (irq)
This IP generates interrupts on specific events, which are described in the [Interrupt Flags](#interrupt-flags) section bellow. The IRQ port should be connected to the system interrupt controller.

## Implementation example  

The following table is the result for implementing the EF_PSRAM_CTRL IP with different wrappers using Sky130 HD library and [OpenLane2](https://github.com/efabless/openlane2) flow.
|Module | Number of cells | Max. freq |
|---|---|---|
|EF_PSRAM_CTRL|TBD| TBD |
|EF_PSRAM_CTRL_AHBL|TBD|TBD|
## The Programmer's Interface


### Registers

|Name|Offset|Reset Value|Access Mode|Description|
|---|---|---|---|---|
|rd_cmd|800100|0x00000003|w|RD Command Register|
|wr_cmd|800200|0x00000002|w|WR Command Register|
|eqpi_cmd|800400|0x00000035|w|Enter QPI Command Register|
|xqpi_cmd|800800|0x000000FE|w|Exit QPI Command Register|
|wait_states|801000|0x00000000|w|Wait States Register|
|mode|802000|0x00000000|w|I/O Mode Register, {qpi, qspi}|
|enter_qpi|804000|0x00000000|w|Initiate Enter QPI (EQPI) Mode process Register|
|exit_qpi|808000|0x00000000|w|Initiate Exit QPI (XQPI) Mode process Register|

### rd_cmd Register [Offset: 0x800100, mode: w]

RD Command Register
<img src="https://svg.wavedrom.com/{reg:[{name:'rd_cmd', bits:8},{bits: 24}], config: {lanes: 2, hflip: true}} "/>

### wr_cmd Register [Offset: 0x800200, mode: w]

WR Command Register
<img src="https://svg.wavedrom.com/{reg:[{name:'wr_cmd', bits:8},{bits: 24}], config: {lanes: 2, hflip: true}} "/>

### eqpi_cmd Register [Offset: 0x800400, mode: w]

Enter QPI Command Register
<img src="https://svg.wavedrom.com/{reg:[{name:'eqpi_cmd', bits:8},{bits: 24}], config: {lanes: 2, hflip: true}} "/>

### xqpi_cmd Register [Offset: 0x800800, mode: w]

Exit QPI Command Register
<img src="https://svg.wavedrom.com/{reg:[{name:'xqpi_cmd', bits:8},{bits: 24}], config: {lanes: 2, hflip: true}} "/>

### wait_states Register [Offset: 0x801000, mode: w]

Wait States Register
<img src="https://svg.wavedrom.com/{reg:[{name:'wait_states', bits:4},{bits: 28}], config: {lanes: 2, hflip: true}} "/>

### mode Register [Offset: 0x802000, mode: w]

I/O Mode Register, {qpi, qspi}
<img src="https://svg.wavedrom.com/{reg:[{name:'mode', bits:2},{bits: 30}], config: {lanes: 2, hflip: true}} "/>

### enter_qpi Register [Offset: 0x804000, mode: w]

Initiate Enter QPI (EQPI) Mode process Register
<img src="https://svg.wavedrom.com/{reg:[{name:'enter_qpi', bits:1},{bits: 31}], config: {lanes: 2, hflip: true}} "/>

### exit_qpi Register [Offset: 0x808000, mode: w]

Initiate Exit QPI (XQPI) Mode process Register
<img src="https://svg.wavedrom.com/{reg:[{name:'exit_qpi', bits:1},{bits: 31}], config: {lanes: 2, hflip: true}} "/>

## Firmware Drivers:
Firmware drivers for EF_PSRAM_CTRL can be found in the [Drivers](https://github.com/efabless/EFIS/tree/main/Drivers) directory in the [EFIS](https://github.com/efabless/EFIS) (Efabless Firmware Interface Standard) repo. EF_PSRAM_CTRL driver documentation  is available [here](https://github.com/efabless/EFIS/blob/main/Drivers/Docs/EF_PSRAM_CTRL/README.md).
You can also find an example C application using the EF_PSRAM_CTRL drivers [here](https://github.com/efabless/EFIS/tree/main/Drivers/Docs/EF_PSRAM_CTRL/example).
## Installation:
You can install the IP either by cloning this repository or by using [IPM](https://github.com/efabless/IPM).
### 1. Using [IPM](https://github.com/efabless/IPM):
- [Optional] If you do not have IPM installed, follow the installation guide [here](https://github.com/efabless/IPM/blob/main/README.md)
- After installing IPM, execute the following command ```ipm install EF_PSRAM_CTRL```.
> **Note:** This method is recommended as it automatically installs [EF_IP_UTIL](https://github.com/efabless/EF_IP_UTIL.git) as a dependency.
### 2. Cloning this repo: 
- Clone [EF_IP_UTIL](https://github.com/efabless/EF_IP_UTIL.git) repository, which includes the required modules from the common modules library, [ef_util_lib.v](https://github.com/efabless/EF_IP_UTIL/blob/main/hdl/ef_util_lib.v).
```git clone https://github.com/efabless/EF_IP_UTIL.git```
- Clone the IP repository
```git clone github.com/efabless/EF_PSRAM_CTRL```

### The Wrapped IP Interface 

>**_NOTE:_** This section is intended for advanced users who wish to gain more information about the interface of the wrapped IP, in case they want to create their own wrappers.

<img src="docs/_static/EF_PSRAM_CTRL.svg" width="600"/>

#### Ports 

|Port|Direction|Width|Description|
|---|---|---|---|
|sck|output|1|SPI master output clock|
|ce_n|output|1|SPI Master slave select.|
|din|input|4|SPI Master data in , slave out|
|dout|output|4|SPI Master data out , slave in|
|douten|output|4|SPI Master data out enable|
