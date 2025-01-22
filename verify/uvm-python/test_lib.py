import cocotb
from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info
from uvm.base.uvm_config_db import UVMConfigDb
from uvm.base.uvm_object_globals import UVM_LOW
from uvm.base.uvm_globals import run_test
from psram_interface.psram_if import psram_if
from EF_UVM.bus_env.bus_interface.bus_if import (
    bus_apb_if,
    bus_irq_if,
    bus_ahb_if,
    bus_wb_if,
)
from cocotb_coverage.coverage import coverage_db
from cocotb.triggers import Event, First
from EF_UVM.bus_env.bus_regs import bus_regs
from uvm.base import UVMRoot
from EF_UVM.base_test import base_test

# seqences import
from psram_seq_lib.psram_ip_seq import psram_ip_seq

# override classes
from EF_UVM.ip_env.ip_agent.ip_driver import ip_driver
from psram_agent.psram_driver import psram_driver
from EF_UVM.ip_env.ip_agent.ip_monitor import ip_monitor
from psram_agent.psram_monitor import psram_monitor
from EF_UVM.ref_model.ref_model import ref_model
from psram_ref_model.psram_ref_model import psram_ref_model
from EF_UVM.ip_env.ip_coverage.ip_coverage import ip_coverage
from psram_coverage.psram_coverage import psram_coverage
from EF_UVM.ip_env.ip_logger.ip_logger import ip_logger
from psram_logger.psram_logger import psram_logger

# override but_item to change size 
from EF_UVM.bus_env.bus_item import bus_item
from psram_bus_item import psram_bus_item 


# 
from psram_seq_lib.psram_spi_seq import psram_spi_seq
from psram_seq_lib.psram_sqi_seq import psram_sqi_seq
from psram_seq_lib.psram_sdi_seq import psram_sdi_seq
from psram_seq_lib.psram_hsize_seq import psram_hsize_seq

@cocotb.test()
async def module_top(dut):
    # profiler = cProfile.Profile()
    # profiler.enable()
    BUS_TYPE = cocotb.plusargs["BUS_TYPE"]
    pif = psram_if(dut)
    if BUS_TYPE == "APB":
        w_if = bus_apb_if(dut)
    elif BUS_TYPE == "AHB":
        w_if = bus_ahb_if(dut)
    elif BUS_TYPE == "WISHBONE":
        w_if = bus_wb_if(dut)
    else:
        uvm_fatal("module_top", f"unknown bus type {BUS_TYPE}")
    # w_irq_if = bus_irq_if(dut)
    UVMConfigDb.set(None, "*", "ip_if", pif)
    UVMConfigDb.set(None, "*", "bus_if", w_if)
    # UVMConfigDb.set(None, "*", "bus_irq_if", w_irq_if)
    yaml_file = []
    UVMRoot().clp.get_arg_values("+YAML_FILE=", yaml_file)
    yaml_file = yaml_file[0]
    regs = bus_regs(yaml_file)
    UVMConfigDb.set(None, "*", "bus_regs", regs)
    UVMConfigDb.set(None, "*", "irq_exist", regs.get_irq_exist())
    UVMConfigDb.set(None, "*", "collect_coverage", True)
    UVMConfigDb.set(None, "*", "disable_logger", False)
    test_path = []
    UVMRoot().clp.get_arg_values("+TEST_PATH=", test_path)
    test_path = test_path[0]
    await run_test()
    coverage_db.export_to_yaml(filename=f"{test_path}/coverage.yaml")
    # profiler.disable()
    # profiler.dump_stats("profile_result.prof")


class psram_base_test(base_test):
    def __init__(self, name="psram_first_test", parent=None):
        BUS_TYPE = cocotb.plusargs["BUS_TYPE"]
        super().__init__(name, bus_type=BUS_TYPE, parent=parent)
        self.tag = name

    def build_phase(self, phase):
        super().build_phase(phase)
        # override
        self.set_type_override_by_type(ip_driver.get_type(), psram_driver.get_type())
        self.set_type_override_by_type(
            ip_monitor.get_type(), psram_monitor.get_type()
        )
        self.set_type_override_by_type(
            ref_model.get_type(), psram_ref_model.get_type()
        )
        self.set_type_override_by_type(
            ip_coverage.get_type(), psram_coverage.get_type()
        )
        self.set_type_override_by_type(ip_logger.get_type(), psram_logger.get_type())
        self.set_type_override_by_type(bus_item.get_type(), psram_bus_item.get_type())
    
    def end_of_elaboration_phase(self, phase):
        super().end_of_elaboration_phase(phase)
        self.ip_interface = []
        if not UVMConfigDb.get(self, "", "ip_if", self.ip_interface):
            uvm_fatal(self.tag, "No interface specified for self driver instance")
        else:
            self.ip_interface = self.ip_interface[0]

    def check_mode(self, expected):
        if self.ip_interface.mode != expected:
            uvm_fatal("check_mode", f"Expected mode {expected} but got {self.ip_interface.mode}")
        else:
            uvm_info("check_mode", f"Mode is {expected}", UVM_LOW)

    # async def post_reset_phase(self, phase):
    #     await super().post_reset_phase(phase)
    #     bus_seq =  psram_enable_clock()
    #     await bus_seq.start(self.bus_sqr)
    #     return super().post_reset_phase(phase)


uvm_component_utils(psram_base_test)


class psram_spi_test(psram_base_test):
    def __init__(self, name="psram__first_test", parent=None):
        super().__init__(name, parent=parent)
        self.tag = name

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        # TODO: conntect sequence with sequencer here
        # for example if you need to run the 2 sequence sequentially
        bus_seq = psram_spi_seq("psram_spi_seq")
        # ip_seq = psram_ip_seq("psram_ip_seq")
        await bus_seq.start(self.bus_sqr)
        # await ip_seq.start(self.ip_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")

    async def shutdown_phase(self, phase):
        await super().shutdown_phase(phase)
        self.check_mode(0)  # SPI


uvm_component_utils(psram_spi_test)


class psram_sqi_test(psram_base_test):
    def __init__(self, name="psram__first_test", parent=None):
        super().__init__(name, parent=parent)
        self.tag = name

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        # TODO: conntect sequence with sequencer here
        # for example if you need to run the 2 sequence sequentially
        bus_seq = psram_sqi_seq("psram_sqi_seq")
        # ip_seq = psram_ip_seq("psram_ip_seq")
        await bus_seq.start(self.bus_sqr)
        # await ip_seq.start(self.ip_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")

    async def shutdown_phase(self, phase):
        await super().shutdown_phase(phase)
        self.check_mode(2)  # SQI


uvm_component_utils(psram_sqi_test)


class psram_sdi_test(psram_base_test):
    def __init__(self, name="psram__first_test", parent=None):
        super().__init__(name, parent=parent)
        self.tag = name

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        # TODO: conntect sequence with sequencer here
        # for example if you need to run the 2 sequence sequentially
        bus_seq = psram_sdi_seq("psram_sdi_seq")
        # ip_seq = psram_ip_seq("psram_ip_seq")
        await bus_seq.start(self.bus_sqr)
        # await ip_seq.start(self.ip_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")

    async def shutdown_phase(self, phase):
        await super().shutdown_phase(phase)
        self.check_mode(1)  # SDI

uvm_component_utils(psram_sdi_test)

class psram_hsize_test(psram_base_test):
    def __init__(self, name="psram__first_test", parent=None):
        super().__init__(name, parent=parent)
        self.tag = name

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        # TODO: conntect sequence with sequencer here
        # for example if you need to run the 2 sequence sequentially
        bus_seq = psram_hsize_seq("psram_hsize_seq")
        # ip_seq = psram_ip_seq("psram_ip_seq")
        await bus_seq.start(self.bus_sqr)
        # await ip_seq.start(self.ip_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")

    async def shutdown_phase(self, phase):
        await super().shutdown_phase(phase)
        self.check_mode(0)  # SPI


uvm_component_utils(psram_hsize_test)

