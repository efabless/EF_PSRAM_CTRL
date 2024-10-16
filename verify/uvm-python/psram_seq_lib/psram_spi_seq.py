from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_fatal
from uvm.base.uvm_config_db import UVMConfigDb
from EF_UVM.bus_env.bus_seq_lib.bus_seq_base import bus_seq_base
from cocotb.triggers import Timer
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
import random
from EF_UVM.bus_env.bus_item import bus_item
from psram_seq_lib.psram_base_seq import psram_base_seq


class psram_spi_seq(psram_base_seq):
    # use this sequence write or read from register by the bus interface
    # this sequence should be connected to the bus sequencer in the testbench
    # you should create as many sequences as you need not only this one
    def __init__(self, name="psram_bus_seq"):
        super().__init__(name)

    async def body(self):
        await super().body()
        await self.write_multiple()
        for _ in range(30):
            await self.write_read_multiple()


uvm_object_utils(psram_spi_seq)
