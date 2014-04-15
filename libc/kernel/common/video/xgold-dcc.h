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
#ifndef __DCC_IOCTL_H__
#define __DCC_IOCTL_H__
#include <linux/ioctl.h>
#define DCCDRV_VERSION_STR "1.1"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCCDRV_VERSION_INT (11)
#define DCC_DRIVER_NAME "dcc"
#define DCC_DEVICE_NAME "/dev/"DCC_DRIVER_NAME
#define DCC_TV_DISPLAY (1<<1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_LCDPAR_DISPLAY (1<<2)
#define DCC_LCDRGB_DISPLAY (1<<3)
#define DCC_ROTATE90 0x1
#define DCC_ROTATE180 0x2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_ROTATE270 0x3
#define DCC_MIRROR_SHIFT 2
#define DCC_SET_MIRROR(_a_ , _sw_)   (_a_ | ((!!_sw_) << DCC_MIRROR_SHIFT))
#define DCC_GET_MIRROR(_a_) ((_a_>>DCC_MIRROR_SHIFT)&0x1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
 DCC_FMT_YUV422PACKED = 1,
 DCC_FMT_YUV420PLANAR = 2,
 DCC_FMT_YVU420PLANAR = 3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DCC_FMT_YUV422PLANAR = 4,
 DCC_FMT_RGB565 = 5,
 DCC_FMT_RGB888 = 6,
 DCC_FMT_RGB4444 = 7,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DCC_FMT_RGB1555 = 8,
 DCC_FMT_ARGB8888 = 9,
 DCC_FMT_BGR565 = 10,
 DCC_FMT_BGR888 = 11,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DCC_FMT_ABGR8888 = 12,
 DCC_FMT_YUV444PACKED = 13,
 DCC_FMT_YUV444PLANAR = 14,
 DCC_FMT_YUV444SP = 15,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DCC_FMT_YUV422SP = 16,
 DCC_FMT_YUV420SP = 17,
};
#define DCC_UPDATE_MODE(_f_) (_f_ & DCC_UPDATE_MODE_MASK)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_UPDATE_MODE_BITS (3)
#define DCC_UPDATE_MODE_MASK ((1<<3)-1)
enum {
 DCC_UPDATE_ONESHOT_SYNC = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DCC_UPDATE_ONESHOT_ASYNC,
 DCC_UPDATE_CONTINOUS,
};
#define DCC_UPDATE_NOBACKGROUND (1<<DCC_UPDATE_MODE_MASK)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_FMT_VIDEO_SPRITE 0xFF
#define DCC_FLAG_NONE 0
#define DCC_FLAG_DRAW2DISP (1<<0)
#define DCC_FLAG_COLORKEY (1<<1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_BLEND_ALPHA_PLANE (1<<2)
#define DCC_BLEND_ALPHA_PIXEL (1<<3)
struct dcc_display_cfg_t {
 int width;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int height;
 int xdpi;
 int ydpi;
 int refresh_rate;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int mem_base;
 unsigned int mem_size;
 unsigned int format;
 unsigned int hwid;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int drvid;
 unsigned int overlay_nbr;
};
struct dcc_rq_t {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int fbwidth;
 unsigned int sphys;
 unsigned int sfmt;
 int sx;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int sy;
 int sw;
 int sh;
 unsigned int dphys;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int dx;
 int dy;
 unsigned int dfmt;
 int dw;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int dh;
 int angle;
 int alpha;
 unsigned int flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define DCC_RQ_SRC(_rq_, _p_, _x_, _y_, _w_, _h_, _f_)   _rq_.sphys = _p_;   _rq_.sx = _x_;   _rq_.sy = _y_;   _rq_.sw = _w_;   _rq_.sh = _h_;   _rq_.sfmt = _f_;
#define DCC_RQ_DST(_rq_, _fbw_, _p_, _x_, _y_, _w_, _h_, _f_)   _rq_.dphys = _p_;   _rq_.dx = _x_;   _rq_.dy = _y_;   _rq_.dw = _w_;   _rq_.dh = _h_;   _rq_.dfmt = _f_;   _rq_.fbwidth = _fbw_;
#define DCC_RQ_DECL(_rq_)   struct dcc_rq_t _rq_;   DCC_RQ_SRC(_rq_, 0, 0, 0, 0, 0, 0)   DCC_RQ_DST(_rq_, 0, 0, 0, 0, 0, 0, 0)   _rq_.angle = 0;   _rq_.alpha = 0xFF;   _rq_.flags = 0;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct dcc_rq_resize_t {
 unsigned int fbwidth;
 unsigned int sphys;
 unsigned int sfmt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int sx;
 int sy;
 int sw;
 int sh;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int wx;
 int wy;
 int ww;
 int wh;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int dphys;
 int dx;
 int dy;
 unsigned int dfmt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int dw;
 int dh;
 int angle;
 int alpha;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int colorkey;
 unsigned int flags;
};
#define DCC_RQRESIZE_SRC(_rq_, _p_, _x_, _y_, _w_, _h_, _f_)   _rq_.sphys = _p_;   _rq_.sx = _x_;   _rq_.sy = _y_;   _rq_.sw = _w_;   _rq_.sh = _h_;   _rq_.sfmt = _f_;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_RQRESIZE_WIN(_rq_, _x_, _y_, _w_, _h_)   _rq_.wx = _x_;   _rq_.wy = _y_;   _rq_.ww = _w_;   _rq_.wh = _h_;
#define DCC_RQRESIZE_DST(_rq_, _fbw_, _p_, _x_, _y_, _w_, _h_, _f_)   _rq_.dphys = _p_;   _rq_.dx = _x_;   _rq_.dy = _y_;   _rq_.dw = _w_;   _rq_.dh = _h_;   _rq_.dfmt = _f_;   _rq_.fbwidth = _fbw_;
#define DCC_RQRESIZE_DECL(_rq_)   struct dcc_rq_resize_t _rq_;   DCC_RQRESIZE_SRC(_rq_, 0, 0, 0, 0, 0, 0)   DCC_RQRESIZE_WIN(_rq_, 0, 0, 0, 0)   DCC_RQRESIZE_DST(_rq_, 0, 0, 0, 0, 0, 0, 0)   _rq_.angle = 0;   _rq_.alpha = 0xFF;   _rq_.flags = 0;
struct dcc_rect_t {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int phys;
 unsigned int fbwidth;
 unsigned int x;
 unsigned int y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int w;
 unsigned int h;
 unsigned int fmt;
 unsigned int color;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int flags;
};
#define DCC_INIT_RECT(_r_, _p_, _fbw_, _x_, _y_, _w_, _h_, _f_, _c_,_g_)   _r_.phys = _p_;   _r_.fbwidth = _fbw_;   _r_.x = _x_;   _r_.y = _y_;   _r_.w = _w_;   _r_.h = _h_;   _r_.fmt = _f_;   _r_.color = _c_;   _r_.flags = _g_;
#define DCC_SPRITE_NBR 4
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct dcc_sprite_t {
 unsigned int en;
 unsigned int phys;
 unsigned int id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int x;
 unsigned int y;
 unsigned int w;
 unsigned int h;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int alpha;
 unsigned int global;
 unsigned int fmt;
 unsigned int chromakey;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define DCC_SPRITE_DECLARE(_sp_)   struct dcc_sprite_t _sp_;
#define DCC_SPRITE_INIT(_sp_, _e_, _i_, _o_,   _x_, _y_, _w_, _h_, _a_, _g_, _f_, _c_)   _sp_.en = _e_;   _sp_.id = _i_;   _sp_.phys = _o_;   _sp_.x = _x_;   _sp_.y = _y_;   _sp_.w = _w_;   _sp_.h = _h_;   _sp_.alpha = _a_;   _sp_.global = _g_;   _sp_.fmt = _f_;   _sp_.chromakey = _c_;
#define DCC_SPRITE_OFF(_sp_) _sp_.en = 0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct dcc_overlay_t {
 unsigned int phys;
 unsigned int key;
 unsigned int use_upd_alpha;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int fmt;
};
#define DCC_INIT_OVERLAY(_o_, _p_, _k_, _a_, _fmt_)   _o_.phys = _p_;   _o_.key = _k_;   _o_.fmt = _fmt_;   _o_.use_upd_alpha = _a_;
struct dcc_point_t {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int phys;
 unsigned int fbwidth;
 unsigned int x;
 unsigned int y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int color;
};
#define DCC_POINT_INIT(_p_, _ph_, _fbw_, _x_, _y_, _c_)   _p_.phys = _ph_;   _p_.fbwidth = _fbw_;   _p_.x = _x_;   _p_.y = _y_;   _p_.color = _c_;
struct dcc_switch_t {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int enable;
 unsigned int value;
};
#define DCC_IOC_MAGIC 'x'
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_IOW_POWER_ON _IOWR('x', 0, unsigned int)
#define DCC_IOW_POWER_OFF _IOWR('x', 1, unsigned int)
#define DCC_IOW_FILLRECTANGLE _IOWR('x', 2, struct dcc_rect_t)
#define DCC_IOW_DRAWLINE _IOWR('x', 3, struct dcc_rect_t)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_IOW_BLIT _IOWR('x', 4, struct dcc_rq_t)
#define DCC_IOW_ROTATE _IOWR('x', 5, struct dcc_rq_t)
#define DCC_IOW_RESIZE _IOWR('x', 6, struct dcc_rq_resize_t)
#define DCC_IOW_DRAWLINEREL _IOWR('x', 13, struct dcc_rect_t)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_IOW_MIRROR _IOWR('x', 14, struct dcc_rq_t)
#define DCC_IOR_DISPLAY_INFO _IOWR('x', 15, struct dcc_display_cfg_t)
#define DCC_IOW_SCROLLMOVE _IOWR('x', 16, struct dcc_rq_t)
#define DCC_IOW_SPRITECONF _IOWR('x', 18, struct dcc_sprite_t)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_IOW_SETPIXEL _IOWR('x', 20, struct dcc_point_t)
#define DCC_IOW_CONVERT _IOWR('x', 21, struct dcc_rq_t)
#define DCC_IOW_UPDATE _IOWR('x', 22, struct dcc_rect_t)
#define DCC_IOW_OVERLAYCONF _IOWR('x', 23, struct dcc_overlay_t)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCC_IOW_UPDATE_OVERLAY _IOWR('x', 27, struct dcc_rect_t)
#define DCC_IOC_MAXNR (27)
#endif
