`timescale 1ns/1ps

module top();
    reg 		CLK = 0;
    wire 		RESETn = 1;
    wire 		irq;

    wire [3:0]	din;
    wire [3:0]	dout;
    wire [3:0]	douten;

    wire 		sck;
    wire 		ce_n;
    wire sio0 = douten[0] ? dout[0] : 1'bz;
    wire sio1 = douten[1] ? dout[1] : 1'bz;
    wire sio2 = douten[2] ? dout[2] : 1'bz;
    wire sio3 = douten[3] ? dout[3] : 1'bz;
    pullup(sio3);  // Attach a weak pull-up to sio3 for hold pin 

    assign din = {sio3, sio2, sio1, sio0};

    `ifdef BUS_TYPE_AHB
        wire [31:0]	HADDR;
        wire 		HWRITE;
        wire 		HSEL = 0;
        wire 		HREADYOUT;
        wire [1:0]	HTRANS=0;
        wire [31:0]	HWDATA;
        wire [31:0]	HRDATA;
        wire 		HREADY;
        wire [2:0] HSIZE;
        // TODO: initialize the AHB wrapper here
        // for example
        EF_PSRAM_CTRL_V2_ahbl dut(.HCLK(CLK), .HRESETn(RESETn), .HADDR(HADDR), .HWRITE(HWRITE), .HSEL(HSEL), .HSIZE(HSIZE), .HTRANS(HTRANS), .HWDATA(HWDATA), .HRDATA(HRDATA), .HREADY(HREADY),.HREADYOUT(HREADYOUT), .sck(sck), .ce_n(ce_n), .din(din), .dout(dout), .douten(douten));
    `endif // BUS_TYPE_AHB
    M23LC1024 slave(
        .SCK(sck),
        .CS_N(ce_n),
        .SI_SIO0(sio0),
        .SO_SIO1(sio1),
        .SIO2(sio2),
        .HOLD_N_SIO3(sio3),
        .RESET(~RESETn)
    );
    wire [1:0] IOMode = slave.IOMode;
    // monitor inside signals
    `ifndef SKIP_WAVE_DUMP
        initial begin
            $dumpfile ({"waves.vcd"});
            $dumpvars(0, top);
        end
    `endif
    always #10 CLK = !CLK; // clk generator
endmodule