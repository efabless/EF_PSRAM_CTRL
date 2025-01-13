#define     EF_PSRAM_CTRL_BASE				    0x00000000

#define     EF_PSRAM_CTRL_RD_CMD_REG_ADDR        (EF_PSRAM_CTRL_BASE + 0x00800100)
#define     EF_PSRAM_CTRL_WR_CMD_REG_ADDR        (EF_PSRAM_CTRL_BASE + 0x00800200)
#define     EF_PSRAM_CTRL_EQPI_CMD_REG_ADDR      (EF_PSRAM_CTRL_BASE + 0x00800400)
#define     EF_PSRAM_CTRL_XQPI_CMD_REG_ADDR      (EF_PSRAM_CTRL_BASE + 0x00800800)
#define     EF_PSRAM_CTRL_WAIT_STATES_REG_ADDR   (EF_PSRAM_CTRL_BASE + 0x00801000)
#define     EF_PSRAM_CTRL_MODE_REG_ADDR          (EF_PSRAM_CTRL_BASE + 0x00802000)
#define     EF_PSRAM_CTRL_ENTER_QPI_REG_ADDR     (EF_PSRAM_CTRL_BASE + 0x00804000)
#define     EF_PSRAM_CTRL_EXIT_QPI_REG_ADDR      (EF_PSRAM_CTRL_BASE + 0x00808000)

volatile unsigned int * ef_psram_ctrl_rd_cmd         = (volatile unsigned int *) EF_PSRAM_CTRL_RD_CMD_REG_ADDR     ;
volatile unsigned int * ef_psram_ctrl_wr_cmd         = (volatile unsigned int *) EF_PSRAM_CTRL_WR_CMD_REG_ADDR     ;
volatile unsigned int * ef_psram_ctrl_eqpi_cmd       = (volatile unsigned int *) EF_PSRAM_CTRL_EQPI_CMD_REG_ADDR   ;
volatile unsigned int * ef_psram_ctrl_xqpi_cmd       = (volatile unsigned int *) EF_PSRAM_CTRL_XQPI_CMD_REG_ADDR   ;
volatile unsigned int * ef_psram_ctrl_wait_states    = (volatile unsigned int *) EF_PSRAM_CTRL_WAIT_STATES_REG_ADDR;
volatile unsigned int * ef_psram_ctrl_mode           = (volatile unsigned int *) EF_PSRAM_CTRL_MODE_REG_ADDR       ;
volatile unsigned int * ef_psram_ctrl_enter_qpi      = (volatile unsigned int *) EF_PSRAM_CTRL_ENTER_QPI_REG_ADDR  ;
volatile unsigned int * ef_psram_ctrl_exit_qpi       = (volatile unsigned int *) EF_PSRAM_CTRL_EXIT_QPI_REG_ADDR   ;
