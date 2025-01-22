# API Reference

## Header files

- [EF_Driver_Common.h](#file-ef_driver_commonh)
- [EF_PSRAM_CTRL.h](#file-ef_psram_ctrlh)
- [EF_PSRAM_CTRL_regs.h](#file-ef_psram_ctrl_regsh)

## File EF_Driver_Common.h

_C header file for common driver definitions and types._



## Structures and Types

| Type | Name |
| ---: | :--- |
| typedef uint32\_t | [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status)  <br>_A type that is used to return the status of the driver functions._ |


## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EF\_DRIVER\_ERROR**](#define-ef_driver_error)  ((uint32\_t)1)<br>_Unspecified error._ |
| define  | [**EF\_DRIVER\_ERROR\_BUSY**](#define-ef_driver_error_busy)  ((uint32\_t)2)<br>_Driver is busy._ |
| define  | [**EF\_DRIVER\_ERROR\_PARAMETER**](#define-ef_driver_error_parameter)  ((uint32\_t)5)<br>_Parameter error._ |
| define  | [**EF\_DRIVER\_ERROR\_SPECIFIC**](#define-ef_driver_error_specific)  ((uint32\_t)6)<br>_Start of driver specific errors._ |
| define  | [**EF\_DRIVER\_ERROR\_TIMEOUT**](#define-ef_driver_error_timeout)  ((uint32\_t)3)<br>_Timeout occurred._ |
| define  | [**EF\_DRIVER\_ERROR\_UNSUPPORTED**](#define-ef_driver_error_unsupported)  ((uint32\_t)4)<br>_Operation not supported._ |
| define  | [**EF\_DRIVER\_OK**](#define-ef_driver_ok)  ((uint32\_t)0)<br>_Operation succeeded._ |

## Structures and Types Documentation

### typedef `EF_DRIVER_STATUS`

_A type that is used to return the status of the driver functions._
```c
typedef uint32_t EF_DRIVER_STATUS;
```



## Macros Documentation

### define `EF_DRIVER_ERROR`

_Unspecified error._
```c
#define EF_DRIVER_ERROR ((uint32_t)1)
```

### define `EF_DRIVER_ERROR_BUSY`

_Driver is busy._
```c
#define EF_DRIVER_ERROR_BUSY ((uint32_t)2)
```

### define `EF_DRIVER_ERROR_PARAMETER`

_Parameter error._
```c
#define EF_DRIVER_ERROR_PARAMETER ((uint32_t)5)
```

### define `EF_DRIVER_ERROR_SPECIFIC`

_Start of driver specific errors._
```c
#define EF_DRIVER_ERROR_SPECIFIC ((uint32_t)6)
```

### define `EF_DRIVER_ERROR_TIMEOUT`

_Timeout occurred._
```c
#define EF_DRIVER_ERROR_TIMEOUT ((uint32_t)3)
```

### define `EF_DRIVER_ERROR_UNSUPPORTED`

_Operation not supported._
```c
#define EF_DRIVER_ERROR_UNSUPPORTED ((uint32_t)4)
```

### define `EF_DRIVER_OK`

_Operation succeeded._
```c
#define EF_DRIVER_OK ((uint32_t)0)
```


## File EF_PSRAM_CTRL.h

_C header file for TMR32 APIs which contains the function prototypes._




## Functions

| Type | Name |
| ---: | :--- |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_initiateEnterQPI**](#function-psram_initiateenterqpi) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t value) <br>_Initiate Enter QPI (EQPI) Mode process Register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_initiateExitQPI**](#function-psram_initiateexitqpi) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t value) <br>_Initiate Exit QPI (XQPI) Mode process Register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_readWord**](#function-psram_readword) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t addr, uint32\_t \*word) <br>_Read a word from the PSRAM external memory._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_setEnterQPIcmd**](#function-psram_setenterqpicmd) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t value) <br>_Sets the enter QPI command for the PSRAM controller._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_setExitQPIcmd**](#function-psram_setexitqpicmd) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t value) <br>_Sets the exit QPI command for the PSRAM controller._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_setMode**](#function-psram_setmode) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t value) <br>_Sets the mode for the PSRAM controller._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_setReadCMD**](#function-psram_setreadcmd) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t value) <br>_Sets the read command for the PSRAM controller._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_setWaitStates**](#function-psram_setwaitstates) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t value) <br>_Sets the wait states for the PSRAM controller._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_setWriteCMD**](#function-psram_setwritecmd) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t value) <br>_Sets the write command for the PSRAM controller._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**PSRAM\_writeWord**](#function-psram_writeword) ([**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr) psram, uint32\_t addr, uint32\_t word) <br>_Write a word to the PSRAM external memory._ |

## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EF\_PSRAM\_CTRL\_BASE**](#define-ef_psram_ctrl_base)  0x00000000<br> |
| define  | [**EF\_PSRAM\_CTRL\_ENTER\_QPI\_REG\_ADDR**](#define-ef_psram_ctrl_enter_qpi_reg_addr)  ([**EF\_PSRAM\_CTRL\_BASE**](#define-ef_psram_ctrl_base) + 0x00804000)<br> |
| define  | [**EF\_PSRAM\_CTRL\_EQPI\_CMD\_REG\_ADDR**](#define-ef_psram_ctrl_eqpi_cmd_reg_addr)  ([**EF\_PSRAM\_CTRL\_BASE**](#define-ef_psram_ctrl_base) + 0x00800400)<br> |
| define  | [**EF\_PSRAM\_CTRL\_EXIT\_QPI\_REG\_ADDR**](#define-ef_psram_ctrl_exit_qpi_reg_addr)  ([**EF\_PSRAM\_CTRL\_BASE**](#define-ef_psram_ctrl_base) + 0x00808000)<br> |
| define  | [**EF\_PSRAM\_CTRL\_MODE\_REG\_ADDR**](#define-ef_psram_ctrl_mode_reg_addr)  ([**EF\_PSRAM\_CTRL\_BASE**](#define-ef_psram_ctrl_base) + 0x00802000)<br> |
| define  | [**EF\_PSRAM\_CTRL\_RD\_CMD\_REG\_ADDR**](#define-ef_psram_ctrl_rd_cmd_reg_addr)  ([**EF\_PSRAM\_CTRL\_BASE**](#define-ef_psram_ctrl_base) + 0x00800100)<br> |
| define  | [**EF\_PSRAM\_CTRL\_WAIT\_STATES\_REG\_ADDR**](#define-ef_psram_ctrl_wait_states_reg_addr)  ([**EF\_PSRAM\_CTRL\_BASE**](#define-ef_psram_ctrl_base) + 0x00801000)<br> |
| define  | [**EF\_PSRAM\_CTRL\_WR\_CMD\_REG\_ADDR**](#define-ef_psram_ctrl_wr_cmd_reg_addr)  ([**EF\_PSRAM\_CTRL\_BASE**](#define-ef_psram_ctrl_base) + 0x00800200)<br> |
| define  | [**EF\_PSRAM\_CTRL\_XQPI\_CMD\_REG\_ADDR**](#define-ef_psram_ctrl_xqpi_cmd_reg_addr)  ([**EF\_PSRAM\_CTRL\_BASE**](#define-ef_psram_ctrl_base) + 0x00800800)<br> |


## Functions Documentation

### function `PSRAM_initiateEnterQPI`

_Initiate Enter QPI (EQPI) Mode process Register._
```c
EF_DRIVER_STATUS PSRAM_initiateEnterQPI (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t value
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `PSRAM_initiateExitQPI`

_Initiate Exit QPI (XQPI) Mode process Register._
```c
EF_DRIVER_STATUS PSRAM_initiateExitQPI (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t value
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `PSRAM_readWord`

_Read a word from the PSRAM external memory._
```c
EF_DRIVER_STATUS PSRAM_readWord (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t addr,
    uint32_t *word
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers. 
* `addr` The address in the external memory to read the word from 
* `word` The word read from the external memory


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `PSRAM_setEnterQPIcmd`

_Sets the enter QPI command for the PSRAM controller._
```c
EF_DRIVER_STATUS PSRAM_setEnterQPIcmd (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t value
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `PSRAM_setExitQPIcmd`

_Sets the exit QPI command for the PSRAM controller._
```c
EF_DRIVER_STATUS PSRAM_setExitQPIcmd (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t value
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `PSRAM_setMode`

_Sets the mode for the PSRAM controller._
```c
EF_DRIVER_STATUS PSRAM_setMode (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t value
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `PSRAM_setReadCMD`

_Sets the read command for the PSRAM controller._
```c
EF_DRIVER_STATUS PSRAM_setReadCMD (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t value
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `PSRAM_setWaitStates`

_Sets the wait states for the PSRAM controller._
```c
EF_DRIVER_STATUS PSRAM_setWaitStates (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t value
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `PSRAM_setWriteCMD`

_Sets the write command for the PSRAM controller._
```c
EF_DRIVER_STATUS PSRAM_setWriteCMD (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t value
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `PSRAM_writeWord`

_Write a word to the PSRAM external memory._
```c
EF_DRIVER_STATUS PSRAM_writeWord (
    EF_PSRAM_CTRL_TYPE_PTR psram,
    uint32_t addr,
    uint32_t word
) 
```


**Parameters:**


* `psram` An EF\_PSRAM\_TYPE\_PTR , which points to the base memory address of PSRAM registers. EF\_PSRAM\_TYPE is a structure that contains the PSRAM registers. 
* `addr` The address in the external memory to write the word to 
* `word` The word to write to the external memory


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code

## Macros Documentation

### define `EF_PSRAM_CTRL_BASE`

```c
#define EF_PSRAM_CTRL_BASE 0x00000000
```

### define `EF_PSRAM_CTRL_ENTER_QPI_REG_ADDR`

```c
#define EF_PSRAM_CTRL_ENTER_QPI_REG_ADDR ( EF_PSRAM_CTRL_BASE + 0x00804000)
```

### define `EF_PSRAM_CTRL_EQPI_CMD_REG_ADDR`

```c
#define EF_PSRAM_CTRL_EQPI_CMD_REG_ADDR ( EF_PSRAM_CTRL_BASE + 0x00800400)
```

### define `EF_PSRAM_CTRL_EXIT_QPI_REG_ADDR`

```c
#define EF_PSRAM_CTRL_EXIT_QPI_REG_ADDR ( EF_PSRAM_CTRL_BASE + 0x00808000)
```

### define `EF_PSRAM_CTRL_MODE_REG_ADDR`

```c
#define EF_PSRAM_CTRL_MODE_REG_ADDR ( EF_PSRAM_CTRL_BASE + 0x00802000)
```

### define `EF_PSRAM_CTRL_RD_CMD_REG_ADDR`

```c
#define EF_PSRAM_CTRL_RD_CMD_REG_ADDR ( EF_PSRAM_CTRL_BASE + 0x00800100)
```

### define `EF_PSRAM_CTRL_WAIT_STATES_REG_ADDR`

```c
#define EF_PSRAM_CTRL_WAIT_STATES_REG_ADDR ( EF_PSRAM_CTRL_BASE + 0x00801000)
```

### define `EF_PSRAM_CTRL_WR_CMD_REG_ADDR`

```c
#define EF_PSRAM_CTRL_WR_CMD_REG_ADDR ( EF_PSRAM_CTRL_BASE + 0x00800200)
```

### define `EF_PSRAM_CTRL_XQPI_CMD_REG_ADDR`

```c
#define EF_PSRAM_CTRL_XQPI_CMD_REG_ADDR ( EF_PSRAM_CTRL_BASE + 0x00800800)
```


## File EF_PSRAM_CTRL_regs.h





## Structures and Types

| Type | Name |
| ---: | :--- |
| typedef struct [**\_EF\_PSRAM\_CTRL\_TYPE\_**](#struct-_ef_psram_ctrl_type_) | [**EF\_PSRAM\_CTRL\_TYPE**](#typedef-ef_psram_ctrl_type)  <br> |
| typedef struct [**\_EF\_PSRAM\_CTRL\_TYPE\_**](#struct-_ef_psram_ctrl_type_) \* | [**EF\_PSRAM\_CTRL\_TYPE\_PTR**](#typedef-ef_psram_ctrl_type_ptr)  <br> |
| struct | [**\_EF\_PSRAM\_CTRL\_TYPE\_**](#struct-_ef_psram_ctrl_type_) <br> |


## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EF\_PSRAM\_CTRL\_ENTER\_QPI\_REG\_ENTER\_QPI\_BIT**](#define-ef_psram_ctrl_enter_qpi_reg_enter_qpi_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_PSRAM\_CTRL\_ENTER\_QPI\_REG\_ENTER\_QPI\_MASK**](#define-ef_psram_ctrl_enter_qpi_reg_enter_qpi_mask)  ((uint32\_t)0x1)<br> |
| define  | [**EF\_PSRAM\_CTRL\_ENTER\_QPI\_REG\_MAX\_VALUE**](#define-ef_psram_ctrl_enter_qpi_reg_max_value)  ((uint32\_t)0x1)<br> |
| define  | [**EF\_PSRAM\_CTRL\_EQPI\_CMD\_REG\_EQPI\_CMD\_BIT**](#define-ef_psram_ctrl_eqpi_cmd_reg_eqpi_cmd_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_PSRAM\_CTRL\_EQPI\_CMD\_REG\_EQPI\_CMD\_MASK**](#define-ef_psram_ctrl_eqpi_cmd_reg_eqpi_cmd_mask)  ((uint32\_t)0xff)<br> |
| define  | [**EF\_PSRAM\_CTRL\_EQPI\_CMD\_REG\_MAX\_VALUE**](#define-ef_psram_ctrl_eqpi_cmd_reg_max_value)  ((uint32\_t)0xFF)<br> |
| define  | [**EF\_PSRAM\_CTRL\_EXIT\_QPI\_REG\_EXIT\_QPI\_BIT**](#define-ef_psram_ctrl_exit_qpi_reg_exit_qpi_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_PSRAM\_CTRL\_EXIT\_QPI\_REG\_EXIT\_QPI\_MASK**](#define-ef_psram_ctrl_exit_qpi_reg_exit_qpi_mask)  ((uint32\_t)0x1)<br> |
| define  | [**EF\_PSRAM\_CTRL\_EXIT\_QPI\_REG\_MAX\_VALUE**](#define-ef_psram_ctrl_exit_qpi_reg_max_value)  ((uint32\_t)0x1)<br> |
| define  | [**EF\_PSRAM\_CTRL\_EXTERNAL\_MEMORY\_MAX\_VALUE**](#define-ef_psram_ctrl_external_memory_max_value)  ((uint32\_t)2097151-1)<br> |
| define  | [**EF\_PSRAM\_CTRL\_MODE\_REG\_MAX\_VALUE**](#define-ef_psram_ctrl_mode_reg_max_value)  ((uint32\_t)0x3)<br> |
| define  | [**EF\_PSRAM\_CTRL\_MODE\_REG\_MODE\_BIT**](#define-ef_psram_ctrl_mode_reg_mode_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_PSRAM\_CTRL\_MODE\_REG\_MODE\_MASK**](#define-ef_psram_ctrl_mode_reg_mode_mask)  ((uint32\_t)0x3)<br> |
| define  | [**EF\_PSRAM\_CTRL\_RD\_CMD\_REG\_MAX\_VALUE**](#define-ef_psram_ctrl_rd_cmd_reg_max_value)  ((uint32\_t)0xFF)<br> |
| define  | [**EF\_PSRAM\_CTRL\_RD\_CMD\_REG\_RD\_CMD\_BIT**](#define-ef_psram_ctrl_rd_cmd_reg_rd_cmd_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_PSRAM\_CTRL\_RD\_CMD\_REG\_RD\_CMD\_MASK**](#define-ef_psram_ctrl_rd_cmd_reg_rd_cmd_mask)  ((uint32\_t)0xff)<br> |
| define  | [**EF\_PSRAM\_CTRL\_WAIT\_STATES\_REG\_MAX\_VALUE**](#define-ef_psram_ctrl_wait_states_reg_max_value)  ((uint32\_t)0xF)<br> |
| define  | [**EF\_PSRAM\_CTRL\_WAIT\_STATES\_REG\_WAIT\_STATES\_BIT**](#define-ef_psram_ctrl_wait_states_reg_wait_states_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_PSRAM\_CTRL\_WAIT\_STATES\_REG\_WAIT\_STATES\_MASK**](#define-ef_psram_ctrl_wait_states_reg_wait_states_mask)  ((uint32\_t)0xf)<br> |
| define  | [**EF\_PSRAM\_CTRL\_WR\_CMD\_REG\_MAX\_VALUE**](#define-ef_psram_ctrl_wr_cmd_reg_max_value)  ((uint32\_t)0xFF)<br> |
| define  | [**EF\_PSRAM\_CTRL\_WR\_CMD\_REG\_WR\_CMD\_BIT**](#define-ef_psram_ctrl_wr_cmd_reg_wr_cmd_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_PSRAM\_CTRL\_WR\_CMD\_REG\_WR\_CMD\_MASK**](#define-ef_psram_ctrl_wr_cmd_reg_wr_cmd_mask)  ((uint32\_t)0xff)<br> |
| define  | [**EF\_PSRAM\_CTRL\_XQPI\_CMD\_REG\_MAX\_VALUE**](#define-ef_psram_ctrl_xqpi_cmd_reg_max_value)  ((uint32\_t)0xFF)<br> |
| define  | [**EF\_PSRAM\_CTRL\_XQPI\_CMD\_REG\_XQPI\_CMD\_BIT**](#define-ef_psram_ctrl_xqpi_cmd_reg_xqpi_cmd_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_PSRAM\_CTRL\_XQPI\_CMD\_REG\_XQPI\_CMD\_MASK**](#define-ef_psram_ctrl_xqpi_cmd_reg_xqpi_cmd_mask)  ((uint32\_t)0xff)<br> |
| define  | [**IO\_TYPES**](#define-io_types)  <br> |
| define  | [**\_\_R**](#define-__r)  volatile const uint32\_t<br> |
| define  | [**\_\_RW**](#define-__rw)  volatile       uint32\_t<br> |
| define  | [**\_\_W**](#define-__w)  volatile       uint32\_t<br> |

## Structures and Types Documentation

### typedef `EF_PSRAM_CTRL_TYPE`

```c
typedef struct _EF_PSRAM_CTRL_TYPE_ EF_PSRAM_CTRL_TYPE;
```

### typedef `EF_PSRAM_CTRL_TYPE_PTR`

```c
typedef struct _EF_PSRAM_CTRL_TYPE_* EF_PSRAM_CTRL_TYPE_PTR;
```

### struct `_EF_PSRAM_CTRL_TYPE_`


Variables:

-  [**\_\_W**](#define-__w) enter_qpi  

-  [**\_\_W**](#define-__w) eqpi_cmd  

-  [**\_\_W**](#define-__w) exit_qpi  

-  [**\_\_RW**](#define-__rw) external_memory  

-  [**\_\_W**](#define-__w) mode  

-  [**\_\_W**](#define-__w) rd_cmd  

-  [**\_\_R**](#define-__r) reserved_0  

-  [**\_\_R**](#define-__r) reserved_1  

-  [**\_\_R**](#define-__r) reserved_2  

-  [**\_\_R**](#define-__r) reserved_3  

-  [**\_\_R**](#define-__r) reserved_4  

-  [**\_\_R**](#define-__r) reserved_5  

-  [**\_\_R**](#define-__r) reserved_6  

-  [**\_\_R**](#define-__r) reserved_7  

-  [**\_\_W**](#define-__w) wait_states  

-  [**\_\_W**](#define-__w) wr_cmd  

-  [**\_\_W**](#define-__w) xqpi_cmd  



## Macros Documentation

### define `EF_PSRAM_CTRL_ENTER_QPI_REG_ENTER_QPI_BIT`

```c
#define EF_PSRAM_CTRL_ENTER_QPI_REG_ENTER_QPI_BIT ((uint32_t)0)
```

### define `EF_PSRAM_CTRL_ENTER_QPI_REG_ENTER_QPI_MASK`

```c
#define EF_PSRAM_CTRL_ENTER_QPI_REG_ENTER_QPI_MASK ((uint32_t)0x1)
```

### define `EF_PSRAM_CTRL_ENTER_QPI_REG_MAX_VALUE`

```c
#define EF_PSRAM_CTRL_ENTER_QPI_REG_MAX_VALUE ((uint32_t)0x1)
```

### define `EF_PSRAM_CTRL_EQPI_CMD_REG_EQPI_CMD_BIT`

```c
#define EF_PSRAM_CTRL_EQPI_CMD_REG_EQPI_CMD_BIT ((uint32_t)0)
```

### define `EF_PSRAM_CTRL_EQPI_CMD_REG_EQPI_CMD_MASK`

```c
#define EF_PSRAM_CTRL_EQPI_CMD_REG_EQPI_CMD_MASK ((uint32_t)0xff)
```

### define `EF_PSRAM_CTRL_EQPI_CMD_REG_MAX_VALUE`

```c
#define EF_PSRAM_CTRL_EQPI_CMD_REG_MAX_VALUE ((uint32_t)0xFF)
```

### define `EF_PSRAM_CTRL_EXIT_QPI_REG_EXIT_QPI_BIT`

```c
#define EF_PSRAM_CTRL_EXIT_QPI_REG_EXIT_QPI_BIT ((uint32_t)0)
```

### define `EF_PSRAM_CTRL_EXIT_QPI_REG_EXIT_QPI_MASK`

```c
#define EF_PSRAM_CTRL_EXIT_QPI_REG_EXIT_QPI_MASK ((uint32_t)0x1)
```

### define `EF_PSRAM_CTRL_EXIT_QPI_REG_MAX_VALUE`

```c
#define EF_PSRAM_CTRL_EXIT_QPI_REG_MAX_VALUE ((uint32_t)0x1)
```

### define `EF_PSRAM_CTRL_EXTERNAL_MEMORY_MAX_VALUE`

```c
#define EF_PSRAM_CTRL_EXTERNAL_MEMORY_MAX_VALUE ((uint32_t)2097151-1)
```

### define `EF_PSRAM_CTRL_MODE_REG_MAX_VALUE`

```c
#define EF_PSRAM_CTRL_MODE_REG_MAX_VALUE ((uint32_t)0x3)
```

### define `EF_PSRAM_CTRL_MODE_REG_MODE_BIT`

```c
#define EF_PSRAM_CTRL_MODE_REG_MODE_BIT ((uint32_t)0)
```

### define `EF_PSRAM_CTRL_MODE_REG_MODE_MASK`

```c
#define EF_PSRAM_CTRL_MODE_REG_MODE_MASK ((uint32_t)0x3)
```

### define `EF_PSRAM_CTRL_RD_CMD_REG_MAX_VALUE`

```c
#define EF_PSRAM_CTRL_RD_CMD_REG_MAX_VALUE ((uint32_t)0xFF)
```

### define `EF_PSRAM_CTRL_RD_CMD_REG_RD_CMD_BIT`

```c
#define EF_PSRAM_CTRL_RD_CMD_REG_RD_CMD_BIT ((uint32_t)0)
```

### define `EF_PSRAM_CTRL_RD_CMD_REG_RD_CMD_MASK`

```c
#define EF_PSRAM_CTRL_RD_CMD_REG_RD_CMD_MASK ((uint32_t)0xff)
```

### define `EF_PSRAM_CTRL_WAIT_STATES_REG_MAX_VALUE`

```c
#define EF_PSRAM_CTRL_WAIT_STATES_REG_MAX_VALUE ((uint32_t)0xF)
```

### define `EF_PSRAM_CTRL_WAIT_STATES_REG_WAIT_STATES_BIT`

```c
#define EF_PSRAM_CTRL_WAIT_STATES_REG_WAIT_STATES_BIT ((uint32_t)0)
```

### define `EF_PSRAM_CTRL_WAIT_STATES_REG_WAIT_STATES_MASK`

```c
#define EF_PSRAM_CTRL_WAIT_STATES_REG_WAIT_STATES_MASK ((uint32_t)0xf)
```

### define `EF_PSRAM_CTRL_WR_CMD_REG_MAX_VALUE`

```c
#define EF_PSRAM_CTRL_WR_CMD_REG_MAX_VALUE ((uint32_t)0xFF)
```

### define `EF_PSRAM_CTRL_WR_CMD_REG_WR_CMD_BIT`

```c
#define EF_PSRAM_CTRL_WR_CMD_REG_WR_CMD_BIT ((uint32_t)0)
```

### define `EF_PSRAM_CTRL_WR_CMD_REG_WR_CMD_MASK`

```c
#define EF_PSRAM_CTRL_WR_CMD_REG_WR_CMD_MASK ((uint32_t)0xff)
```

### define `EF_PSRAM_CTRL_XQPI_CMD_REG_MAX_VALUE`

```c
#define EF_PSRAM_CTRL_XQPI_CMD_REG_MAX_VALUE ((uint32_t)0xFF)
```

### define `EF_PSRAM_CTRL_XQPI_CMD_REG_XQPI_CMD_BIT`

```c
#define EF_PSRAM_CTRL_XQPI_CMD_REG_XQPI_CMD_BIT ((uint32_t)0)
```

### define `EF_PSRAM_CTRL_XQPI_CMD_REG_XQPI_CMD_MASK`

```c
#define EF_PSRAM_CTRL_XQPI_CMD_REG_XQPI_CMD_MASK ((uint32_t)0xff)
```

### define `IO_TYPES`

```c
#define IO_TYPES 
```

### define `__R`

```c
#define __R volatile const uint32_t
```

### define `__RW`

```c
#define __RW volatile       uint32_t
```

### define `__W`

```c
#define __W volatile       uint32_t
```


