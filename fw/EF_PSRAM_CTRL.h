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


/******************************************************************************
* Typedefs and Enums
******************************************************************************/



/******************************************************************************
* Function Prototypes
******************************************************************************/

//! Sets the read command for the EF_PSRAM controller
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_setReadCMD(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Sets the write command for the EF_PSRAM controller
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_setWriteCMD(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Sets the enter QPI command for the EF_PSRAM controller
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_setEnterQPIcmd(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);

//! Sets the enter QPI command for the EF_PSRAM controller
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_setEnterQPIcmd(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Sets the exit QPI command for the EF_PSRAM controller
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_setExitQPIcmd(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Sets the wait states for the EF_PSRAM controller
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_setWaitStates(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);



//! Sets the mode for the EF_PSRAM controller
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_setMode(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Initiate Enter QPI (EQPI) Mode process Register
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_initiateEnterQPI(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Initiate Exit QPI (XQPI) Mode process Register
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_initiateExitQPI(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value);


//! Write a word to the EF_PSRAM external memory
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        \param [in] addr The address in the external memory to write the word to
        \param [in] word The word to write to the external memory
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_writeWord(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t addr, uint32_t word);


//! Read a word from the EF_PSRAM external memory
    /*!
        \param [in] psram An \ref  EF_PSRAM_CTRL_TYPE_PTR , which points to the base memory address of EF_PSRAM registers. \ref  EF_PSRAM_CTRL_TYPE is a structure that contains the EF_PSRAM registers.
        \param [in] addr The address in the external memory to read the word from
        \param [out] word The word read from the external memory
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS  EF_PSRAM_CTRL_readWord(  EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t addr, uint32_t *word);

/******************************************************************************
* External Variables
******************************************************************************/


#endif  //  EF_PSRAM_CTRL_H


/******************************************************************************
* End of File
******************************************************************************/
