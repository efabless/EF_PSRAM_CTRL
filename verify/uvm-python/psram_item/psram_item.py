from uvm.seq.uvm_sequence_item import UVMSequenceItem
from uvm.macros import (
    uvm_object_utils_begin,
    uvm_object_utils_end,
    uvm_field_int,
    uvm_object_utils,
    uvm_error,
    uvm_info,
)
from uvm.base.uvm_object_globals import UVM_ALL_ON, UVM_NOPACK, UVM_HIGH, UVM_MEDIUM
from uvm.base.sv import sv
from EF_UVM.ip_env.ip_item import ip_item


class psram_item(ip_item):
    def __init__(self, name="psram_item"):
        super().__init__(name)
        # TODO: Add the variables that defined the item and thier randomization status

    def convert2string(self):
        # TODO: return the string representation of the item
        return ""

    def do_compare(self, tr):
        # method used by scoreboard to compare the items
        # TODO: Add logic to compare the item with another passed item
        # in the simple case this function should return (self.varaible1 == tr.variable2 and self.varaible2 == tr.variable2 and .. )
        return False


uvm_object_utils(psram_item)
