/*
	Copyright 2024 Efabless Corp.

	Author: Efabless Corp. (ip_admin@efabless.com)

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/

#ifndef EF_PSRAM_CTRLREGS_H
#define EF_PSRAM_CTRLREGS_H

 
/******************************************************************************
* Includes
******************************************************************************/
#include <stdint.h>

/******************************************************************************
* Macros and Constants
******************************************************************************/

#ifndef IO_TYPES
#define IO_TYPES
#define   __R     volatile const uint32_t
#define   __W     volatile       uint32_t
#define   __RW    volatile       uint32_t
#endif

#define EF_PSRAM_CTRL_RD_CMD_REG_RD_CMD_BIT	((uint32_t)0)
#define EF_PSRAM_CTRL_RD_CMD_REG_RD_CMD_MASK	((uint32_t)0xff)
#define EF_PSRAM_CTRL_RD_CMD_REG_MAX_VALUE	((uint32_t)0xFF)

#define EF_PSRAM_CTRL_WR_CMD_REG_WR_CMD_BIT	((uint32_t)0)
#define EF_PSRAM_CTRL_WR_CMD_REG_WR_CMD_MASK	((uint32_t)0xff)
#define EF_PSRAM_CTRL_WR_CMD_REG_MAX_VALUE	((uint32_t)0xFF)

#define EF_PSRAM_CTRL_EQPI_CMD_REG_EQPI_CMD_BIT	((uint32_t)0)
#define EF_PSRAM_CTRL_EQPI_CMD_REG_EQPI_CMD_MASK	((uint32_t)0xff)
#define EF_PSRAM_CTRL_EQPI_CMD_REG_MAX_VALUE	((uint32_t)0xFF)

#define EF_PSRAM_CTRL_XQPI_CMD_REG_XQPI_CMD_BIT	((uint32_t)0)
#define EF_PSRAM_CTRL_XQPI_CMD_REG_XQPI_CMD_MASK	((uint32_t)0xff)
#define EF_PSRAM_CTRL_XQPI_CMD_REG_MAX_VALUE	((uint32_t)0xFF)

#define EF_PSRAM_CTRL_WAIT_STATES_REG_WAIT_STATES_BIT	((uint32_t)0)
#define EF_PSRAM_CTRL_WAIT_STATES_REG_WAIT_STATES_MASK	((uint32_t)0xf)
#define EF_PSRAM_CTRL_WAIT_STATES_REG_MAX_VALUE	((uint32_t)0xF)

#define EF_PSRAM_CTRL_MODE_REG_MODE_BIT	((uint32_t)0)
#define EF_PSRAM_CTRL_MODE_REG_MODE_MASK	((uint32_t)0x3)
#define EF_PSRAM_CTRL_MODE_REG_MAX_VALUE	((uint32_t)0x3)

#define EF_PSRAM_CTRL_ENTER_QPI_REG_ENTER_QPI_BIT	((uint32_t)0)
#define EF_PSRAM_CTRL_ENTER_QPI_REG_ENTER_QPI_MASK	((uint32_t)0x1)
#define EF_PSRAM_CTRL_ENTER_QPI_REG_MAX_VALUE	((uint32_t)0x1)

#define EF_PSRAM_CTRL_EXIT_QPI_REG_EXIT_QPI_BIT	((uint32_t)0)
#define EF_PSRAM_CTRL_EXIT_QPI_REG_EXIT_QPI_MASK	((uint32_t)0x1)
#define EF_PSRAM_CTRL_EXIT_QPI_REG_MAX_VALUE	((uint32_t)0x1)

#define EF_PSRAM_CTRL_EXTERNAL_MEMORY_MAX_VALUE	((uint32_t)2097151-1)



/******************************************************************************
* Typedefs and Enums
******************************************************************************/
          
typedef struct _EF_PSRAM_CTRL_TYPE_ {
    __RW 	external_memory[2097151];
	__R 	reserved_0[25];
	__W 	rd_cmd;
	__R 	reserved_1[63];
	__W 	wr_cmd;
	__R 	reserved_2[127];
	__W 	eqpi_cmd;
	__R 	reserved_3[255];
	__W 	xqpi_cmd;
	__R 	reserved_4[511];
	__W 	wait_states;
	__R 	reserved_5[1023];
	__W 	mode;
	__R 	reserved_6[2047];
	__W 	enter_qpi;
	__R 	reserved_7[4095];
	__W 	exit_qpi;
} EF_PSRAM_CTRL_TYPE;

typedef struct _EF_PSRAM_CTRL_TYPE_ *EF_PSRAM_CTRL_TYPE_PTR;     // Pointer to the register structure

  
/******************************************************************************
* Function Prototypes
******************************************************************************/



/******************************************************************************
* External Variables
******************************************************************************/




#endif

/******************************************************************************
* End of File
******************************************************************************/
