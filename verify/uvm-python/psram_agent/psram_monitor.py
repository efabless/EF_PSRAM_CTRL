from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info, uvm_error, uvm_warning
from uvm.comps.uvm_monitor import UVMMonitor
from uvm.tlm1.uvm_analysis_port import UVMAnalysisPort
from uvm.base.uvm_config_db import UVMConfigDb
from cocotb.triggers import (
    Timer,
    ClockCycles,
    FallingEdge,
    Event,
    RisingEdge,
    Combine,
    First,
)
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW, UVM_MEDIUM
import cocotb
import math
from EF_UVM.ip_env.ip_agent.ip_monitor import ip_monitor


class psram_monitor(ip_monitor):
    def __init__(self, name="psram_monitor", parent=None):
        super().__init__(name, parent)

    async def run_phase(self, phase):
        # TODO: Add logic to monitor the IP
        # use self.vif.<signal name> for monitoring interface signals
        # self.monitor_port.write(tr) # this is the port to send the transaction after sampling it
        # NOTES: how to create transaction
        pass


uvm_component_utils(psram_monitor)
