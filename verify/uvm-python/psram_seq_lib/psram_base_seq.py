from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_fatal
from uvm.base.uvm_config_db import UVMConfigDb
from EF_UVM.bus_env.bus_seq_lib.bus_seq_base import bus_seq_base
from cocotb.triggers import Timer
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
import random
from EF_UVM.bus_env.bus_item import bus_item


class psram_base_seq(bus_seq_base):
    # use this sequence write or read from register by the bus interface
    # this sequence should be connected to the bus sequencer in the testbench
    # you should create as many sequences as you need not only this one
    def __init__(self, name="psram_bus_seq"):
        super().__init__(name)
        self.valid_addr = set()

    async def body(self):
        await super().body()
        arr = []
        if not UVMConfigDb.get(self, "", "bus_regs", arr):
            uvm_fatal(self.tag, "No json file wrapper regs")
        else:
            self.regs = arr[0].reg_name_to_address

    async def write_to_mem(self, address=None, data=None, size=None):
        self.create_new_item()
        self.req.rand_mode(0)
        if address is None:
            address = random.randint(0, 0x1FFFF)
        self.req.addr = 0x00700000 + address
        self.req.data = random.randint(0, 0xFFFFFFFF) if data is None else data
        self.req.kind = bus_item.WRITE
        self.req.size = bus_item.WORD_ACCESS if size is None else size
        await uvm_do(self, self.req)
        self.valid_addr.add(address)
        if self.req.size == bus_item.WORD_ACCESS:
            self.valid_addr.add(address + 1)
            self.valid_addr.add(address + 2)
            self.valid_addr.add(address + 3)
        elif self.req.size == bus_item.HALF_WORD_ACCESS:
            self.valid_addr.add(address + 1)

    async def read_from_mem(self, address=None, size=None):
        self.create_new_item()
        self.req.rand_mode(0)
        if address is None:
            address = random.randint(0, 0x1FFFF)
        self.req.addr = 0x00700000 + address
        self.req.data = 0
        self.req.kind = bus_item.READ
        self.req.size = 2 if size is None else size
        await uvm_do(self, self.req)

    async def write_bulk(self, address, bulk_size, access_size):
        for _ in range(bulk_size):
            await self.write_to_mem(address=address, size=access_size)
            address += 4 if access_size == bus_item.WORD_ACCESS else 2 if access_size == bus_item.HALF_WORD_ACCESS else 1

    async def read_bulk(self, address, bulk_size, access_size):
        for _ in range(bulk_size):
            if not self.valid_read(address, access_size):
                return
            await self.read_from_mem(address=address, size=access_size)
            address += 4 if access_size == bus_item.WORD_ACCESS else 2 if access_size == bus_item.HALF_WORD_ACCESS else 1
            
    def valid_read(self, address, access_size):
        if address not in self.valid_addr:
            return False
        if access_size == bus_item.WORD_ACCESS:
            return address in self.valid_addr and address + 3 in self.valid_addr
        elif access_size == bus_item.HALF_WORD_ACCESS:
            return address in self.valid_addr and address + 1 in self.valid_addr
        else:
            return address in self.valid_addr

    async def set_mode(self, mode):
        if mode not in ["SPI", "SDI", "SQI"]:
            uvm_fatal(self.tag, f"Invalid mode {mode} should be SPI, SDI or SQI")
        if mode == "SQI":
            await self.set_waitstates(2)
            await self.psram_send_req(is_write=True, reg="eqpi_cmd", data=0x38)
            await self.psram_send_req(is_write=True, reg="enter_qpi", data=1)
            await self.psram_send_req(is_write=True, reg=0x0, data=0x0)
            for _ in range(10):
                await self.send_nop()
            await self.psram_send_req(is_write=True, reg="enter_qpi", data=0)
            await self.psram_send_req(is_write=True, reg="mode", data=2)     
        elif mode == "SDI":
            await self.set_waitstates(2)
            await self.psram_send_req(is_write=True, reg="eqpi_cmd", data=0x3B)
            await self.psram_send_req(is_write=True, reg="enter_qpi", data=1)
            await self.psram_send_req(is_write=True, reg=0x0, data=0x0)
            for _ in range(10):
                await self.send_nop()
            await self.psram_send_req(is_write=True, reg="enter_qpi", data=0)
            await self.psram_send_req(is_write=True, reg="mode", data=1)     
    
    async def psram_send_req(self, is_write, reg, data):
        self.create_new_item()
        self.req.rand_mode(0)
        self.req.addr = reg if type(reg) is int else self.regs[reg]
        self.req.data = data
        self.req.kind = bus_item.WRITE
        await uvm_do(self, self.req)

    async def set_waitstates(self, waitstates):
        await self.psram_send_req(is_write=True, reg="wait_states", data=waitstates)

    async def write_multiple(self):
        for i in range(random.randint(10, 30)):
            await self.access_rand(is_write=True)

    async def access_rand(self, is_write=True):
        if is_write:
            address = random.randint(0, 0x1FFFF // 4) * 4
        else:
            filtered_set = {x for x in self.valid_addr if x % 4 == 0}
            address = random.choice(list(self.valid_addr))
        bulk_size = random.randint(1, 10)
        access_size = random.choice([bus_item.WORD_ACCESS, bus_item.HALF_WORD_ACCESS, bus_item.BYTE_ACCESS])
        if is_write == False: # correct read size depend on the address
            if access_size == bus_item.BYTE_ACCESS:
                pass
            elif access_size == bus_item.HALF_WORD_ACCESS :
                if address % 2 != 0:
                    access_size = bus_item.BYTE_ACCESS
            elif access_size == bus_item.WORD_ACCESS:
                if address % 4 != 0:
                    access_size = bus_item.BYTE_ACCESS
        last_address = address + (bulk_size - 1) * (4 if access_size == bus_item.WORD_ACCESS else 2 if access_size == bus_item.HALF_WORD_ACCESS else 1)
        if last_address > 0x1FFFF:
            bulk_size = 1
        if is_write:
            await self.write_bulk(address=address, bulk_size=bulk_size, access_size=access_size)
        else:
            await self.read_bulk(address=address, bulk_size=bulk_size, access_size=access_size)

    async def write_read_multiple(self):
        for i in range(random.randint(10, 30)):
            if random.random() < 0.8:  # read 80% of the time
                await self.access_rand(is_write=False)
            else:
                await self.access_rand(is_write=True)


uvm_object_utils(psram_base_seq)
