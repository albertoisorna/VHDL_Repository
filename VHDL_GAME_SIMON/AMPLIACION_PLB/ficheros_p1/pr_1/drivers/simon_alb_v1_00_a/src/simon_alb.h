/*****************************************************************************
* Filename:          C:\Xilinx\PRACTICAS_FPGA\P3_INTENTO2\ficheros_p1\pr_1/drivers/simon_alb_v1_00_a/src/simon_alb.h
* Version:           1.00.a
* Description:       simon_alb Driver Header File
* Date:              Tue Jan 02 22:10:23 2018 (by Create and Import Peripheral Wizard)
*****************************************************************************/

#ifndef SIMON_ALB_H
#define SIMON_ALB_H

/***************************** Include Files *******************************/

#include "xbasic_types.h"
#include "xstatus.h"
#include "xio.h"

/************************** Constant Definitions ***************************/


/**
 * User Logic Slave Space Offsets
 * -- SLV_REG0 : user logic slave module register 0
 * -- SLV_REG1 : user logic slave module register 1
 */
#define SIMON_ALB_USER_SLV_SPACE_OFFSET (0x00000000)
#define SIMON_ALB_SLV_REG0_OFFSET (SIMON_ALB_USER_SLV_SPACE_OFFSET + 0x00000000)
#define SIMON_ALB_SLV_REG1_OFFSET (SIMON_ALB_USER_SLV_SPACE_OFFSET + 0x00000004)

/**************************** Type Definitions *****************************/


/***************** Macros (Inline Functions) Definitions *******************/

/**
 *
 * Write a value to a SIMON_ALB register. A 32 bit write is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is written.
 *
 * @param   BaseAddress is the base address of the SIMON_ALB device.
 * @param   RegOffset is the register offset from the base to write to.
 * @param   Data is the data written to the register.
 *
 * @return  None.
 *
 * @note
 * C-style signature:
 * 	void SIMON_ALB_mWriteReg(Xuint32 BaseAddress, unsigned RegOffset, Xuint32 Data)
 *
 */
#define SIMON_ALB_mWriteReg(BaseAddress, RegOffset, Data) \
 	xil_io_out32((BaseAddress) + (RegOffset), (Xuint32)(Data))

/**
 *
 * Read a value from a SIMON_ALB register. A 32 bit read is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is read from the register. The most significant data
 * will be read as 0.
 *
 * @param   BaseAddress is the base address of the SIMON_ALB device.
 * @param   RegOffset is the register offset from the base to write to.
 *
 * @return  Data is the data from the register.
 *
 * @note
 * C-style signature:
 * 	Xuint32 SIMON_ALB_mReadReg(Xuint32 BaseAddress, unsigned RegOffset)
 *
 */
#define SIMON_ALB_mReadReg(BaseAddress, RegOffset) \
 	xil_io_in32((BaseAddress) + (RegOffset))


/**
 *
 * Write/Read 32 bit value to/from SIMON_ALB user logic slave registers.
 *
 * @param   BaseAddress is the base address of the SIMON_ALB device.
 * @param   RegOffset is the offset from the slave register to write to or read from.
 * @param   Value is the data written to the register.
 *
 * @return  Data is the data from the user logic slave register.
 *
 * @note
 * C-style signature:
 * 	void SIMON_ALB_mWriteSlaveRegn(Xuint32 BaseAddress, unsigned RegOffset, Xuint32 Value)
 * 	Xuint32 SIMON_ALB_mReadSlaveRegn(Xuint32 BaseAddress, unsigned RegOffset)
 *
 */
#define SIMON_ALB_mWriteSlaveReg0(BaseAddress, RegOffset, Value) \
 	xil_io_out32((BaseAddress) + (SIMON_ALB_SLV_REG0_OFFSET) + (RegOffset), (Xuint32)(Value))
#define SIMON_ALB_mWriteSlaveReg1(BaseAddress, RegOffset, Value) \
 	xil_io_out32((BaseAddress) + (SIMON_ALB_SLV_REG1_OFFSET) + (RegOffset), (Xuint32)(Value))

#define SIMON_ALB_mReadSlaveReg0(BaseAddress, RegOffset) \
 	xil_io_in32((BaseAddress) + (SIMON_ALB_SLV_REG0_OFFSET) + (RegOffset))
#define SIMON_ALB_mReadSlaveReg1(BaseAddress, RegOffset) \
 	xil_io_in32((BaseAddress) + (SIMON_ALB_SLV_REG1_OFFSET) + (RegOffset))

/************************** Function Prototypes ****************************/


/**
 *
 * Run a self-test on the driver/device. Note this may be a destructive test if
 * resets of the device are performed.
 *
 * If the hardware system is not built correctly, this function may never
 * return to the caller.
 *
 * @param   baseaddr_p is the base address of the SIMON_ALB instance to be worked on.
 *
 * @return
 *
 *    - XST_SUCCESS   if all self-test code passed
 *    - XST_FAILURE   if any self-test code failed
 *
 * @note    Caching must be turned off for this function to work.
 * @note    Self test may fail if data memory and device are not on the same bus.
 *
 */
XStatus SIMON_ALB_SelfTest(void * baseaddr_p);

#endif /** SIMON_ALB_H */
