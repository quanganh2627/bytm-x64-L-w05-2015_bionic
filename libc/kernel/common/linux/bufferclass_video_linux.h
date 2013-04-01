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
#ifndef __BC_VIDEO_LINUX_H__
#define __BC_VIDEO_LINUX_H__
#include <linux/ioctl.h>
#define BC_FOURCC(a,b,c,d)   ((unsigned long) ((a) | (b)<<8 | (c)<<16 | (d)<<24))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BC_PIX_FMT_NV12 BC_FOURCC('N', 'V', '1', '2')
#define BC_PIX_FMT_UYVY BC_FOURCC('U', 'Y', 'V', 'Y')
#define BC_PIX_FMT_YUYV BC_FOURCC('Y', 'U', 'Y', 'V')
#define BC_PIX_FMT_RGB565 BC_FOURCC('R', 'G', 'B', 'P')
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BC_PIX_FMT_YV12 BC_FOURCC('Y', 'V', '1', '2')
typedef struct BC_Video_ioctl_package_TAG {
 int ioctl_cmd;
 int device_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int inputparam;
 int outputparam;
} BC_Video_ioctl_package;
typedef struct bc_buf_ptr {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int index;
 int size;
 unsigned long pa;
 unsigned long handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
} bc_buf_ptr_t;
#define BC_Video_ioctl_fill_buffer 0
#define BC_Video_ioctl_get_buffer_count 1
#define BC_Video_ioctl_get_buffer_phyaddr 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BC_Video_ioctl_get_buffer_index 3
#define BC_Video_ioctl_request_buffers 4
#define BC_Video_ioctl_set_buffer_phyaddr 5
#define BC_Video_ioctl_release_buffer_device 6
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BC_Video_ioctl_alloc_buffer 7
#define BC_Video_ioctl_free_buffer 8
#define BC_Video_ioctl_get_buffer_handle 9
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
