/******************************************************************************
*
* Copyright (C) 2018 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

#ifndef XILLIBPM_DEFS_H_
#define XILLIBPM_DEFS_H_

/*
 * Version number is a 32bit value, like:
 * (PM_VERSION_MAJOR << 16) | PM_VERSION_MINOR
 */
#define PM_VERSION_MAJOR    1U
#define PM_VERSION_MINOR    0U
#define PM_VERSION      ((PM_VERSION_MAJOR << 16) | PM_VERSION_MINOR)

/**
 *  PM Abort Reasons Enum
 */
enum XPmAbortReason {
	ABORT_REASON_WKUP_EVENT = 100,
	ABORT_REASON_PU_BUSY,
	ABORT_REASON_NO_PWRDN,
	ABORT_REASON_UNKNOWN,
};

/**
 *  @name Boot Status Enum
 */
enum XPmBootStatus {
	PM_INITIAL_BOOT, /**< boot is a fresh system startup */
	PM_RESUME, /**< boot is a resume */
	PM_BOOT_ERROR, /**< error, boot cause cannot be identified */
};

/**
 *  @name Device Capability Requirements Enum
 */
enum XPmCapability {
	PM_CAP_ACCESS = 0x1U, /**< Full access */
	PM_CAP_CONTEXT = 0x2U, /**< Configuration and contents retained */
	PM_CAP_WAKEUP = 0x4U, /**< Enabled as a wake-up source */
};

/**
 * XPm_DeviceStatus - struct containing device status information
 */
typedef struct XPm_DeviceStatus {
	u32 Status; /**< Device power state */
	u32 Requirement; /**< Requirements placed on the device by the caller */
	u32 Usage; /**< Usage info (which subsystem is using the device) */
} XPm_DeviceStatus;

/* Requirement limits */
#define XPM_MAX_CAPABILITY	(PM_CAP_ACCESS | PM_CAP_CONTEXT)
#define XPM_MAX_LATENCY		(0xFFFFU)
#define XPM_MAX_QOS			(100)
#define XPM_MIN_CAPABILITY	(0)
#define XPM_MIN_LATENCY		(0)
#define XPM_MIN_QOS			(0)
#define XPM_DEF_CAPABILITY	XPM_MAX_CAPABILITY
#define XPM_DEF_LATENCY		XPM_MAX_LATENCY
#define XPM_DEF_QOS			XPM_MAX_QOS

enum pm_query_id {
	XPM_QID_INVALID,
	XPM_QID_CLOCK_GET_NAME,
	XPM_QID_CLOCK_GET_TOPOLOGY,
	XPM_QID_CLOCK_GET_FIXEDFACTOR_PARAMS,
	XPM_QID_CLOCK_GET_MUXSOURCES,
	XPM_QID_CLOCK_GET_ATTRIBUTES,
	XPM_QID_PINCTRL_GET_NUM_PINS,
	XPM_QID_PINCTRL_GET_NUM_FUNCTIONS,
	XPM_QID_PINCTRL_GET_NUM_FUNCTION_GROUPS,
	XPM_QID_PINCTRL_GET_FUNCTION_NAME,
	XPM_QID_PINCTRL_GET_FUNCTION_GROUPS,
	XPM_QID_PINCTRL_GET_PIN_GROUPS,
	XPM_QID_CLOCK_GET_NUM_CLOCKS,
};

enum pm_pinctrl_config_param {
	PINCTRL_CONFIG_SLEW_RATE,
	PINCTRL_CONFIG_BIAS_STATUS,
	PINCTRL_CONFIG_PULL_CTRL,
	PINCTRL_CONFIG_SCHMITT_CMOS,
	PINCTRL_CONFIG_DRIVE_STRENGTH,
	PINCTRL_CONFIG_VOLTAGE_STATUS,
	PINCTRL_CONFIG_TRI_STATE,
	PINCTRL_CONFIG_MAX,
};

enum pm_pinctrl_slew_rate {
	PINCTRL_SLEW_RATE_SLOW,
	PINCTRL_SLEW_RATE_FAST,
};

enum pm_pinctrl_bias_status {
	PINCTRL_BIAS_DISABLE,
	PINCTRL_BIAS_ENABLE,
};

enum pm_pinctrl_pull_ctrl {
	PINCTRL_BIAS_PULL_DOWN,
	PINCTRL_BIAS_PULL_UP,
};

enum pm_pinctrl_schmitt_cmos {
	PINCTRL_INPUT_TYPE_CMOS,
	PINCTRL_INPUT_TYPE_SCHMITT,
};

enum pm_pinctrl_drive_strength {
	PINCTRL_DRIVE_STRENGTH_TRISTATE,
	PINCTRL_DRIVE_STRENGTH_4MA,
	PINCTRL_DRIVE_STRENGTH_8MA,
	PINCTRL_DRIVE_STRENGTH_12MA,
	PINCTRL_DRIVE_STRENGTH_MAX,
};

enum pm_pinctrl_tri_state {
	PINCTRL_TRI_STATE_DISABLE,
	PINCTRL_TRI_STATE_ENABLE,
};

enum pm_ioctl_id {
	IOCTL_GET_RPU_OPER_MODE,
	IOCTL_SET_RPU_OPER_MODE,
	IOCTL_RPU_BOOT_ADDR_CONFIG,
	IOCTL_TCM_COMB_CONFIG,
	IOCTL_SET_TAPDELAY_BYPASS,
	IOCTL_SET_SGMII_MODE,
	IOCTL_SD_DLL_RESET,
	IOCTL_SET_SD_TAPDELAY,
	/* Ioctl for clock driver */
	IOCTL_SET_PLL_FRAC_MODE,
	IOCTL_GET_PLL_FRAC_MODE,
	IOCTL_SET_PLL_FRAC_DATA,
	IOCTL_GET_PLL_FRAC_DATA,
	IOCTL_WRITE_GGS,
	IOCTL_READ_GGS,
	IOCTL_WRITE_PGGS,
	IOCTL_READ_PGGS,
	/* IOCTL for ULPI reset */
	IOCTL_ULPI_RESET,
	/* Set healthy bit value */
	IOCTL_SET_BOOT_HEALTH_STATUS,
	IOCTL_AFI,
};

/* PLL parameters */
enum XPm_PllConfigParams {
	PLL_PARAM_ID_CLKOUTDIV,
	PLL_PARAM_ID_FBDIV,
	PLL_PARAM_ID_FRAC_DATA,
	PLL_PARAM_ID_PRE_SRC,
	PLL_PARAM_ID_POST_SRC,
	PLL_PARAM_ID_LOCK_DLY,
	PLL_PARAM_ID_LOCK_CNT,
	PLL_PARAM_ID_LFHF,
	PLL_PARAM_ID_CP,
	PLL_PARAM_ID_RES,
	PLL_PARAM_MAX,
};

/* System shutdown macros */
#define XPM_SHUTDOWN_TYPE_SHUTDOWN      0U
#define XPM_SHUTDOWN_TYPE_RESET         1U

/* RPU operation mode */
#define XPM_RPU_MODE_LOCKSTEP	0U
#define XPM_RPU_MODE_SPLIT	1U

/* RPU Boot memory */
#define XPM_RPU_BOOTMEM_LOVEC	(0U)
#define XPM_RPU_BOOTMEM_HIVEC	(1U)

/* PM API ids */
#define PM_GET_API_VERSION              1U
#define PM_SET_CONFIGURATION            2U
#define PM_GET_DEVICE_STATUS            3U
#define PM_GET_OP_CHARACTERISTIC        4U
#define PM_REGISTER_NOTIFIER            5U

#define PM_REQUEST_SUSPEND              6U
#define PM_SELF_SUSPEND                 7U
#define PM_FORCE_POWERDOWN              8U
#define PM_ABORT_SUSPEND                9U
#define PM_REQUEST_WAKEUP               10U
#define PM_SET_WAKEUP_SOURCE            11U
#define PM_SYSTEM_SHUTDOWN              12U

#define PM_REQUEST_DEVICE                13U
#define PM_RELEASE_DEVICE                14U
#define PM_SET_REQUIREMENT              15U
#define PM_SET_MAX_LATENCY              16U

#define PM_RESET_ASSERT                 17U
#define PM_RESET_GET_STATUS             18U
#define PM_MMIO_WRITE                   19U
#define PM_MMIO_READ                    20U

#define PM_INIT_FINALIZE                21U

#define PM_FPGA_LOAD                    22U
#define PM_FPGA_GET_STATUS              23U

#define PM_GET_CHIPID                   24U

#define PM_SECURE_RSA_AES               25U
#define PM_SECURE_SHA                   26U
#define PM_SECURE_RSA                   27U

#define PM_PINCTRL_REQUEST              28U
#define PM_PINCTRL_RELEASE              29U
#define PM_PINCTRL_GET_FUNCTION         30U
#define PM_PINCTRL_SET_FUNCTION         31U
#define PM_PINCTRL_CONFIG_PARAM_GET     32U
#define PM_PINCTRL_CONFIG_PARAM_SET     33U

#define PM_IOCTL                        34U

#define PM_QUERY_DATA                   35U

#define PM_CLOCK_ENABLE                 36U
#define PM_CLOCK_DISABLE                37U
#define PM_CLOCK_GETSTATE               38U
#define PM_CLOCK_SETDIVIDER             39U
#define PM_CLOCK_GETDIVIDER             40U
#define PM_CLOCK_SETRATE                41U
#define PM_CLOCK_GETRATE                42U
#define PM_CLOCK_SETPARENT              43U
#define PM_CLOCK_GETPARENT              44U
#define PM_SECURE_IMAGE                 45U
#define PM_FPGA_READ                    46U

#define PM_CREATE_SUBSYSTEM             47U
#define PM_DESTROY_SUBSYSTEM             48U

#define PM_DESCRIBE_NODES				49U
#define	PM_ADD_NODE						50U
#define	PM_ADD_NODE_PARENT				51U
#define	PM_ADD_NODE_NAME				52U

#define PM_PLL_SET_PARAMETER			53U
#define PM_PLL_GET_PARAMETER			54U
#define PM_PLL_SET_MODE					55U
#define PM_PLL_GET_MODE					56U

#define PM_API_MIN      PM_GET_API_VERSION
#define PM_API_MAX      PM_PLL_GET_MODE


#endif /* XILLIBPM_DEFS_H_ */