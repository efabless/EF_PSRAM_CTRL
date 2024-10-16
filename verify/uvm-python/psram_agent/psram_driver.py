from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info, uvm_warning
from uvm.base.uvm_config_db import UVMConfigDb
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW, UVM_MEDIUM
from cocotb.triggers import Timer, ClockCycles, FallingEdge, Event, RisingEdge, First
import cocotb
import random
from EF_UVM.ip_env.ip_agent.ip_driver import ip_driver


class psram_driver(ip_driver):
    def __init__(self, name="psram_driver", parent=None):
        super().__init__(name, parent)
        self.tag = name

    async def run_phase(self, phase):
        uvm_info(self.tag, "run_phase started", UVM_LOW)
        return
        while True:
            tr = []
            await self.seq_item_port.get_next_item(tr)
            tr = tr[0]
            # TODO: Add your code here for driving the IP
            uvm_fatal(
                self.tag, "please remove this line and write your code for driving here"
            )
            # use self.vif.<signal name> for driving interface signals
            self.seq_item_port.item_done()


uvm_component_utils(psram_driver)
