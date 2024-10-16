from EF_UVM.ip_env.ip_logger.ip_logger import ip_logger
import cocotb
from uvm.macros import uvm_component_utils, uvm_fatal


class psram_logger(ip_logger):
    def __init__(self, name="psram_logger", parent=None):
        super().__init__(name, parent)
        return
        uvm_fatal("psram_logger", "please write self.header in list format")
        # self.header = ['Time (ns)', "Direction", "value"]
        self.col_widths = [10] * len(self.header)

    def logger_formatter(self, transaction):
        sim_time = f"{cocotb.utils.get_sim_time(units='ns')} ns"
        # this called when new transaction is called from ip monitor
        # TODO: should return the list of strings by the information in the header with the same order
        return [
            sim_time,
        ]


uvm_component_utils(psram_logger)
