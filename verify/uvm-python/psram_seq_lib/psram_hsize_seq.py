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
import random


class psram_hsize_seq(psram_base_seq):
    # use this sequence write or read from register by the bus interface
    # this sequence should be connected to the bus sequencer in the testbench
    # you should create as many sequences as you need not only this one
    def __init__(self, name="psram_bus_seq"):
        super().__init__(name)

    async def body(self):
        await super().body()
        # test write byte and half word
        for i in range(50):
            # write bytes or half words
            address = random.randint(0, 0x1FFFF // 4) * 4
            size = random.choice([bus_item.BYTE_ACCESS, bus_item.HALF_WORD_ACCESS])
            address_steps = [0, 1, 2, 3] if size == bus_item.BYTE_ACCESS else [0, 2]
            random.shuffle(address_steps)
            for i in address_steps:
                await self.write_to_mem(address=address + i, size=size)
            # read word
            await self.read_from_mem(address=address, size=bus_item.WORD_ACCESS)
        # test read byte and half word
        for i in range(50):
            # write word
            address = random.randint(0, 0x1FFFF // 4) * 4
            await self.write_to_mem(address=address, size=bus_item.WORD_ACCESS)
            # read bytes or half words
            size = random.choice([bus_item.BYTE_ACCESS, bus_item.HALF_WORD_ACCESS])
            address_steps = [0, 1, 2, 3] if size == bus_item.BYTE_ACCESS else [0, 2]
            random.shuffle(address_steps)
            for i in address_steps:
                await self.read_from_mem(address=address + i, size=size)

uvm_object_utils(psram_hsize_seq)
