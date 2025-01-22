/*
	Copyright 2025 Efabless Corp.


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


/*! \file EF_PSRAM_CTRL.h
    \brief C header file for TMR32 APIs which contains the function prototypes 
    
*/
#ifndef EF_PSRAM_CTRL_H
#define EF_PSRAM_CTRL_H

/******************************************************************************
* Includes
******************************************************************************/
#include "EF_PSRAM_CTRL_regs.h"
#include "EF_Driver_Common.h"


/******************************************************************************
* Macros and Constants
******************************************************************************/

#define     EF_PSRAM_CTRL_BASE				    0x00000000

#define     EF_PSRAM_CTRL_RD_CMD_REG_ADDR        (EF_PSRAM_CTRL_BASE + 0x00800100)
#define     EF_PSRAM_CTRL_WR_CMD_REG_ADDR        (EF_PSRAM_CTRL_BASE + 0x00800200)
#define     EF_PSRAM_CTRL_EQPI_CMD_REG_ADDR      (EF_PSRAM_CTRL_BASE + 0x00800400)
#define     EF_PSRAM_CTRL_XQPI_CMD_REG_ADDR      (EF_PSRAM_CTRL_BASE + 0x00800800)
#define     EF_PSRAM_CTRL_WAIT_STATES_REG_ADDR   (EF_PSRAM_CTRL_BASE + 0x00801000)
#define     EF_PSRAM_CTRL_MODE_REG_ADDR          (EF_PSRAM_CTRL_BASE + 0x00802000)
#define     EF_PSRAM_CTRL_ENTER_QPI_REG_ADDR     (EF_PSRAM_CTRL_BASE + 0x00804000)
#define     EF_PSRAM_CTRL_EXIT_QPI_REG_ADDR      (EF_PSRAM_CTRL_BASE + 0x00808000)

//volatile unsigned uint32_t * ef_psram_ctrl_rd_cmd         = (volatile unsigned uint32_t *) EF_PSRAM_CTRL_RD_CMD_REG_ADDR     ;
//volatile unsigned uint32_t * ef_psram_ctrl_wr_cmd         = (volatile unsigned uint32_t *) EF_PSRAM_CTRL_WR_CMD_REG_ADDR     ;
//volatile unsigned uint32_t * ef_psram_ctrl_eqpi_cmd       = (volatile unsigned uint32_t *) EF_PSRAM_CTRL_EQPI_CMD_REG_ADDR   ;
//volatile unsigned uint32_t * ef_psram_ctrl_xqpi_cmd       = (volatile unsigned uint32_t *) EF_PSRAM_CTRL_XQPI_CMD_REG_ADDR   ;
//volatile unsigned uint32_t * ef_psram_ctrl_wait_states    = (volatile unsigned uint32_t *) EF_PSRAM_CTRL_WAIT_STATES_REG_ADDR;
//volatile unsigned uint32_t * ef_psram_ctrl_mode           = (volatile unsigned uint32_t *) EF_PSRAM_CTRL_MODE_REG_ADDR       ;
//volatile unsigned uint32_t * ef_psram_ctrl_enter_qpi      = (volatile unsigned uint32_t *) EF_PSRAM_CTRL_ENTER_QPI_REG_ADDR  ;
//volatile unsigned uint32_t * ef_psram_ctrl_exit_qpi       = (volatile unsigned uint32_t *) EF_PSRAM_CTRL_EXIT_QPI_REG_ADDR   ;



/******************************************************************************
* Typedefs and Enums
******************************************************************************/



/******************************************************************************
* Function Prototypes
******************************************************************************/

//! Sets the read command for the PSRAM controller
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_setReadCMD(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Sets the write command for the PSRAM controller
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_setWriteCMD(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);

//uint32_t PSRAM_getWrireCMD();


//! Sets the enter QPI command for the PSRAM controller
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_setEnterQPIcmd(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);

//uint32_t PSRAM_getEnterQPIcmd();

//! Sets the enter QPI command for the PSRAM controller
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_setEnterQPIcmd(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Sets the exit QPI command for the PSRAM controller
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_setExitQPIcmd(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Sets the wait states for the PSRAM controller
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_setWaitStates(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);



//! Sets the mode for the PSRAM controller
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_setMode(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);




//! Initiate Enter QPI (EQPI) Mode process Register
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_initiateEnterQPI(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Initiate Exit QPI (XQPI) Mode process Register
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_initiateExitQPI(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);



//! Write a word to the PSRAM external memory
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        \param [in] addr The address in the external memory to write the word to
        \param [in] word The word to write to the external memory
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_writeWord(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t addr, uint32_t word);


//! Read a word from the PSRAM external memory
    /*!
        \param [in] psram An \ref EF_PSRAM_TYPE_PTR , which points to the base memory address of PSRAM registers. \ref EF_PSRAM_TYPE is a structure that contains the PSRAM registers.
        \param [in] addr The address in the external memory to read the word from
        \param [out] word The word read from the external memory
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS PSRAM_readWord(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t addr, uint32_t *word);

/******************************************************************************
* External Variables
******************************************************************************/


#endif  //EF_PSRAM_CTRL_H


/******************************************************************************
* End of File
******************************************************************************/
