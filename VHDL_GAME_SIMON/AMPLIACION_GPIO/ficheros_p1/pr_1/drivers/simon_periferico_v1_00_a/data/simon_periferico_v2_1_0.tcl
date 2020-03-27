##############################################################################
## Filename:          C:\Xilinx\PRACTICAS_FPGA\P3_INTENTO2\ficheros_p1\pr_1/drivers/simon_periferico_v1_00_a/data/simon_periferico_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Wed Dec 27 09:35:57 2017 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "simon_periferico" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
