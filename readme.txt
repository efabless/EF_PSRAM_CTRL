/*
	Copyright 2024 Efabless Corp.

	Author: Efabless Corp. (ip_admin@efabless.com)

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/

IP_name: EF_PSRAM_CTRL
Author: Efabless
Directory Structure:

    - fw 
        - **EF_PSRAM_CTRL_regs.h**: Header file containing the register definitions for the EF_PSRAM_CTRL interface.

    - hdl 
        - rtl 
            - **EF_PSRAM_CTRL.v**: Verilog source code for the EF_PSRAM_CTRL design, including the core logic of the UART module.
            - **bus_wrappers**
                - **EF_PSRAM_CTRL_AHBL.v**: Verilog wrapper to interface the EF_PSRAM_CTRL with the AMBA High-performance Bus (AHB-Lite) protocol.
            
    - **EF_PSRAM_CTRL.pdf**: Comprehensive documentation for the EF_PSRAM_CTRL, including its features, configuration, and usage.