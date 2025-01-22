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


/*! \file EF_PSRAM_CTRL.c
    \brief C file for TMR32 APIs which contains the function implmentations 
    
*/

#ifndef EF_PSRAM_CTRL_C
#define EF_PSRAM_CTRL_C

/******************************************************************************
* Includes
******************************************************************************/
#include "EF_PSRAM_CTRL.h"

/******************************************************************************
* File-Specific Macros and Constants
******************************************************************************/



/******************************************************************************
* Static Variables
******************************************************************************/



/******************************************************************************
* Static Function Prototypes
******************************************************************************/



/******************************************************************************
* Function Definitions
******************************************************************************/

EF_DRIVER_STATUS PSRAM_setReadCMD(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value){
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (value > EF_PSRAM_CTRL_RD_CMD_REG_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{
        psram->rd_cmd = value;
    }
    return status;
}

EF_DRIVER_STATUS PSRAM_setWriteCMD(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value){
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (value > EF_PSRAM_CTRL_WR_CMD_REG_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{
        psram->wr_cmd = value;
    }

    return status;
}

EF_DRIVER_STATUS PSRAM_setEnterQPIcmd(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (value > EF_PSRAM_CTRL_ENTER_QPI_REG_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{

        psram->enter_qpi = value;
    }
    return status;

}

EF_DRIVER_STATUS PSRAM_setExitQPIcmd(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (value > EF_PSRAM_CTRL_EXIT_QPI_REG_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{
        psram->exit_qpi = value;
    }
    return status;
}

EF_DRIVER_STATUS PSRAM_setWaitStates(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;


    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (value > EF_PSRAM_CTRL_WAIT_STATES_REG_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{
        psram->wait_states = value;
    }
    return status;

}

EF_DRIVER_STATUS PSRAM_setMode(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (value > EF_PSRAM_CTRL_MODE_REG_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{
        psram->mode = value;
    }

    return status;
}

EF_DRIVER_STATUS PSRAM_initiateEnterQPI(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value){


    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (value > EF_PSRAM_CTRL_ENTER_QPI_REG_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{
        psram->enter_qpi = value;
    }

    return status;
}

EF_DRIVER_STATUS PSRAM_initiateExitQPI(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (value > EF_PSRAM_CTRL_EXIT_QPI_REG_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{
        psram->exit_qpi = value;
    }
    return status;
}

EF_DRIVER_STATUS PSRAM_writeWord(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t addr, uint32_t word){
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (addr > EF_PSRAM_CTRL_EXTERNAL_MEMORY_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{
        psram->external_memory[addr] = word;
    }
    return status;
}

EF_DRIVER_STATUS PSRAM_readWord(EF_PSRAM_CTRL_TYPE_PTR psram, uint32_t addr, uint32_t *word){
    EF_DRIVER_STATUS status = EF_DRIVER_OK;
    if (psram == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (word == NULL){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else if (addr > EF_PSRAM_CTRL_EXTERNAL_MEMORY_MAX_VALUE){
        status = EF_DRIVER_ERROR_PARAMETER;
    }
    else{
        *word = psram->external_memory[addr];
    }
    return status;
}

/******************************************************************************
* Static Function Definitions
******************************************************************************/


#endif // EF_PSRAM_CTRL_C

/******************************************************************************
* End of File
******************************************************************************/
