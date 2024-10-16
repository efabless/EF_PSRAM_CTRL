from EF_UVM.bus_env.bus_item import bus_item
from uvm.macros import (
    uvm_object_utils_begin,
    uvm_object_utils_end,
    uvm_field_int,
    uvm_object_utils,
)

class psram_bus_item(bus_item):
    def __init__(self, name="psram_bus_item"):
        super().__init__(name)
        self.rand("addr", range(0, 0xFFFFFFF))

uvm_object_utils(psram_bus_item)
