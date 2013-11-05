/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _MDM_CTRL_H
#define _MDM_CTRL_H
#include <linux/ioctl.h>
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 MDM_CTRL_STATE_UNKNOWN = 0x0000,
 MDM_CTRL_STATE_OFF = 0x0001,
 MDM_CTRL_STATE_COLD_BOOT = 0x0002,
 MDM_CTRL_STATE_WARM_BOOT = 0x0004,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 MDM_CTRL_STATE_COREDUMP = 0x0008,
 MDM_CTRL_STATE_IPC_READY = 0x0010,
 MDM_CTRL_STATE_FW_DOWNLOAD_READY = 0x0020,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MDM_CTRL_STATE_NONE MDM_CTRL_STATE_UNKNOWN
enum {
 MDM_CTRL_NO_HU = 0x00,
 MDM_CTRL_HU_RESET = 0x01,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 MDM_CTRL_HU_COREDUMP = 0x02,
};
enum {
 MDM_TIMER_FLASH_ENABLE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 MDM_TIMER_FLASH_DISABLE,
 MDM_TIMER_DEFAULT
};
struct mdm_ctrl_cmd {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int param;
 unsigned int timeout;
};
#define MDM_CTRL_MAGIC 0x87
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MDM_CTRL_POWER_OFF _IO(MDM_CTRL_MAGIC, 0)
#define MDM_CTRL_POWER_ON _IO(MDM_CTRL_MAGIC, 1)
#define MDM_CTRL_WARM_RESET _IO(MDM_CTRL_MAGIC, 2)
#define MDM_CTRL_COLD_RESET _IO(MDM_CTRL_MAGIC, 3)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MDM_CTRL_SET_STATE _IO(MDM_CTRL_MAGIC, 4)
#define MDM_CTRL_GET_STATE _IO(MDM_CTRL_MAGIC, 5)
#define MDM_CTRL_WAIT_FOR_STATE _IO(MDM_CTRL_MAGIC, 6)
#define MDM_CTRL_FLASHING_WARM_RESET _IO(MDM_CTRL_MAGIC, 7)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MDM_CTRL_GET_HANGUP_REASONS _IO(MDM_CTRL_MAGIC, 8)
#define MDM_CTRL_CLEAR_HANGUP_REASONS _IO(MDM_CTRL_MAGIC, 9)
#define MDM_CTRL_SET_POLLED_STATES _IO(MDM_CTRL_MAGIC, 10)
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
