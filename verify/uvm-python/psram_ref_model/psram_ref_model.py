from uvm.base.uvm_component import UVMComponent
from uvm.macros import uvm_component_utils
from uvm.tlm1.uvm_analysis_port import UVMAnalysisImp
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW, UVM_MEDIUM
from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info
from uvm.base.uvm_config_db import UVMConfigDb
from uvm.tlm1.uvm_analysis_port import UVMAnalysisExport
import cocotb
from EF_UVM.ref_model.ref_model import ref_model
from EF_UVM.bus_env.bus_item import bus_item
from cocotb.triggers import Event


class psram_ref_model(ref_model):
    """
    The reference model is a crucial element within the top-level verification environment, designed to validate the functionality and performance of both the IP (Intellectual Property) and the bus system. Its primary role is to act as a representative or mimic of the actual hardware components, including the IP and the bus. Key features and functions of the reference model include:
    1) Input Simulation: The reference model is capable of receiving the same inputs that would be provided to the actual IP and bus via connection with the monitors of the bus and IP.
    2) Functional Emulation: It emulates the behavior and responses of the IP and bus under test. By replicating the operational characteristics of these components, the reference model serves as a benchmark for expected performance and behavior.
    3) Output Generation: Upon receiving inputs, the reference model processes them in a manner akin to the real hardware, subsequently generating expected outputs. These outputs are essential for comparison in the verification process.
    4) Interface with Scoreboard: The outputs from the reference model, representing the expected results, are forwarded to the scoreboard. The scoreboard then compares these expected results with the actual outputs from the IP and bus for verification.
    5)Register Abstraction Layer (RAL) Integration: The reference model includes a RAL model that mirrors the register values of the RTL, ensuring synchronization between expected and actual register states. This model facilitates register-level tests and error detection, offering accessible and up-to-date register values for other verification components. It enhances the automation and coverage of register testing, playing a vital role in ensuring the accuracy and comprehensiveness of the verification process.
    """

    def __init__(self, name="psram_ref_model", parent=None):
        super().__init__(name, parent)
        self.tag = name
        self.ris_reg = 0
        self.mis_reg = 0
        self.irq = 0
        self.mis_changed = Event()
        self.icr_changed = Event()
        self.external_mem = Memory(size=0x1FFFF) # the slave is 1 MB

    def build_phase(self, phase):
        super().build_phase(phase)
        # Here adding any initialize for user classes for the model

    async def run_phase(self, phase):
        await super().run_phase(phase)
        # Here add the log to run when simulation starts
    
    def write_bus(self, tr):
        # Called when new transaction is received from the bus monitor
        # TODO: update the following logic to determine what to do with the received transaction
        uvm_info(
            self.tag,
            " Ref model recieved from bus monitor: " + tr.convert2string(),
            UVM_HIGH,
        )
        if tr.kind == bus_item.RESET:
            self.bus_bus_export.write(tr)
            uvm_info("Ref model", "reset from ref model", UVM_LOW)
            # TODO: write logic needed when reset is received
            # self.bus_bus_export.write(tr)
            return
        if tr.kind == bus_item.WRITE:
            # TODO: write logic needed when write transaction is received
            # For example, to write the same value to the same resgiter uncomment the following lines
            if tr.addr & 0xFFF00000 == 0x00700000: # access to the external memory
                addr_wr = tr.addr & 0xFFFFF
                if tr.size == bus_item.WORD_ACCESS:
                    self.external_mem.write_word(addr_wr, tr.data)
                elif tr.size == bus_item.HALF_WORD_ACCESS:
                    if addr_wr % 4 == 0:
                        self.external_mem.write_halfword(addr_wr, tr.data & 0xFFFF) 
                    else:
                        self.external_mem.write_halfword(addr_wr, tr.data >> 16)
                elif tr.size == bus_item.BYTE_ACCESS:
                    if addr_wr % 4 == 0:
                        self.external_mem.write_byte(addr_wr, tr.data & 0xFF)
                    elif addr_wr % 4 == 1:
                        self.external_mem.write_byte(addr_wr, (tr.data >> 8) & 0xFF)
                    elif addr_wr % 4 == 2:
                        self.external_mem.write_byte(addr_wr, (tr.data >> 16) & 0xFF)
                    else:
                        self.external_mem.write_byte(addr_wr, (tr.data >> 24) & 0xFF)
                else:
                    self.regs.write_reg_value(tr.addr, tr.data)
                self.bus_bus_export.write(tr) # this is output to the scoreboard

            # check if the write register is icr , set the icr changed event
        elif tr.kind == bus_item.READ:
            # TODO: write logic needed when read transaction is received
            # For example, to read the same resgiter uncomment the following lines
            td = tr.do_clone()
            if tr.addr & 0xFFF00000 == 0x00700000: # access to the external memory
                addr = tr.addr & 0xFFFFF
                if tr.size == bus_item.WORD_ACCESS:
                    td.data = self.external_mem.read_word(addr)
                elif tr.size == bus_item.HALF_WORD_ACCESS:
                    td.data = self.external_mem.read_halfword(addr)
                elif tr.size == bus_item.BYTE_ACCESS:
                    td.data = self.external_mem.read_byte(addr)
            else:
                data = self.regs.read_reg_value(tr.addr, mask=0xFFFFFF)
                td.data = data
            self.bus_bus_export.write(td) # this is output to the scoreboard

    def write_ip(self, tr):
        # Called when new transaction is received from the ip monitor
        # TODO: write what to do when new transaction ip transaction is received
        uvm_info(
            self.tag,
            "Ref model recieved from ip monitor: " + tr.convert2string(),
            UVM_HIGH,
        )

        # Update interrupts when a new ip transaction is received
        self.set_ris_reg()
        # Here the ref model should predict the transaction and send it to scoreboard
        # self.ip_export.write(td) # this is output ro scoreboard


uvm_component_utils(psram_ref_model)

class Memory:
    def __init__(self, size=0x00700000):
        """Initialize the memory array with the given size."""
        self.size = size
        self.memory = bytearray(size)

    def _check_address(self, address, length):
        """Check if the address is within bounds."""
        if address < 0 or address + length > self.size:
            raise ValueError(f"Address {hex(address)} out of bounds.")

    def read_byte(self, address):
        """Read a single byte from memory."""
        self._check_address(address, 1)
        uvm_info("Ref model", f"read_byte {hex(address)}", UVM_LOW)
        return self.memory[address]

    def write_byte(self, address, value):
        """Write a single byte to memory."""
        self._check_address(address, 1)
        uvm_info("Ref model", f"write_byte {hex(value)} to {hex(address)}", UVM_LOW)
        self.memory[address] = value & 0xFF

    def read_halfword(self, address):
        """Read 2 bytes (half-word) from memory as two byte reads."""
        self._check_address(address, 2)
        byte0 = self.read_byte(address)
        byte1 = self.read_byte(address + 1)
        return byte0 | (byte1 << 8)

    def write_halfword(self, address, value):
        """Write 2 bytes (half-word) to memory as two byte writes."""
        self._check_address(address, 2)
        self.write_byte(address, value & 0xFF)           # Lower byte
        self.write_byte(address + 1, (value >> 8) & 0xFF) # Upper byte

    def read_word(self, address):
        """Read 4 bytes (word) from memory as four byte reads."""
        self._check_address(address, 4)
        byte0 = self.read_byte(address)
        byte1 = self.read_byte(address + 1)
        byte2 = self.read_byte(address + 2)
        byte3 = self.read_byte(address + 3)
        return byte0 | (byte1 << 8) | (byte2 << 16) | (byte3 << 24)

    def write_word(self, address, value):
        """Write 4 bytes (word) to memory as four byte writes."""
        self._check_address(address, 4)
        self.write_byte(address, value & 0xFF)           # Lowest byte
        self.write_byte(address + 1, (value >> 8) & 0xFF)  # Second byte
        self.write_byte(address + 2, (value >> 16) & 0xFF) # Third byte
        self.write_byte(address + 3, (value >> 24) & 0xFF) # Highest byte