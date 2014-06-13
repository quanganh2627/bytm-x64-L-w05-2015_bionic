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
#ifndef _ATOM_ISP_H
#define _ATOM_ISP_H
#include <linux/types.h>
#define CI_MODE_PREVIEW 0x8000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CI_MODE_VIDEO 0x4000
#define CI_MODE_STILL_CAPTURE 0x2000
#define CI_MODE_CONTINUOUS 0x1000
#define CI_MODE_NONE 0x0000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OUTPUT_MODE_FILE 0x0100
#define OUTPUT_MODE_TEXT 0x0200
struct atomisp_nr_config {
 unsigned int bnr_gain;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int ynr_gain;
 unsigned int direction;
 unsigned int threshold_cb;
 unsigned int threshold_cr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_tnr_config {
 unsigned int gain;
 unsigned int threshold_y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int threshold_uv;
};
struct atomisp_histogram {
 unsigned int num_elements;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 void __user *data;
};
enum atomisp_ob_mode {
 atomisp_ob_mode_none,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 atomisp_ob_mode_fixed,
 atomisp_ob_mode_raster
};
struct atomisp_ob_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 enum atomisp_ob_mode mode;
 unsigned int level_gr;
 unsigned int level_r;
 unsigned int level_b;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int level_gb;
 unsigned short start_position;
 unsigned short end_position;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_ee_config {
 unsigned int gain;
 unsigned int threshold;
 unsigned int detail_gain;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_3a_output {
 int ae_y;
 int awb_cnt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int awb_gr;
 int awb_r;
 int awb_b;
 int awb_gb;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int af_hpf1;
 int af_hpf2;
};
enum atomisp_calibration_type {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 calibration_type1,
 calibration_type2,
 calibration_type3
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_calibration_group {
 unsigned int size;
 unsigned int type;
 unsigned short *calb_grp_values;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_gc_config {
 __u16 gain_k1;
 __u16 gain_k2;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_3a_config {
 unsigned int ae_y_coef_r;
 unsigned int ae_y_coef_g;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int ae_y_coef_b;
 unsigned int awb_lg_high_raw;
 unsigned int awb_lg_low;
 unsigned int awb_lg_high;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int af_fir1_coef[7];
 int af_fir2_coef[7];
};
struct atomisp_grid_info {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int isp_in_width;
 unsigned int isp_in_height;
 unsigned int s3a_width;
 unsigned int s3a_height;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int s3a_bqs_per_grid_cell;
 unsigned int dis_width;
 unsigned int dis_aligned_width;
 unsigned int dis_height;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int dis_aligned_height;
 unsigned int dis_bqs_per_grid_cell;
 unsigned int dis_hor_coef_num;
 unsigned int dis_ver_coef_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_dis_vector {
 int x;
 int y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_dis_coefficients {
 struct atomisp_grid_info grid_info;
 short __user *vertical_coefficients;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 short __user *horizontal_coefficients;
};
struct atomisp_dis_statistics {
 struct atomisp_grid_info grid_info;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int __user *vertical_projections;
 int __user *horizontal_projections;
};
struct atomisp_3a_statistics {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct atomisp_grid_info grid_info;
 struct atomisp_3a_output __user *data;
};
struct atomisp_cont_capture_conf {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int num_captures;
 unsigned int skip_frames;
 int offset;
 __u32 reserved[5];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_wb_config {
 unsigned int integer_bits;
 unsigned int gr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int r;
 unsigned int b;
 unsigned int gb;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_cc_config {
 unsigned int fraction_bits;
 int matrix[3 * 3];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_de_config {
 unsigned int pixelnoise;
 unsigned int c1_coring_threshold;
 unsigned int c2_coring_threshold;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_ce_config {
 unsigned int uv_level_min;
 unsigned int uv_level_max;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_dp_config {
 unsigned int threshold;
 unsigned int gain;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_xnr_config {
 unsigned int threshold;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_parm {
 struct atomisp_grid_info info;
 struct atomisp_wb_config wb_config;
 struct atomisp_cc_config cc_config;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct atomisp_ob_config ob_config;
 struct atomisp_de_config de_config;
 struct atomisp_ce_config ce_config;
 struct atomisp_dp_config dp_config;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct atomisp_nr_config nr_config;
 struct atomisp_ee_config ee_config;
 struct atomisp_tnr_config tnr_config;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_parameters {
 struct atomisp_wb_config *wb_config;
 struct atomisp_cc_config *cc_config;
 struct atomisp_ob_config *ob_config;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct atomisp_de_config *de_config;
 struct atomisp_ce_config *ce_config;
 struct atomisp_dp_config *dp_config;
 struct atomisp_nr_config *nr_config;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct atomisp_ee_config *ee_config;
 struct atomisp_tnr_config *tnr_config;
 struct atomisp_shading_table *shading_table;
 struct atomisp_morph_table *morph_table;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct atomisp_macc_config *macc_config;
 struct atomisp_gamma_table *gamma_table;
 struct atomisp_ctc_table *ctc_table;
 struct atomisp_xnr_config *xnr_config;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct atomisp_gc_config *gc_config;
 struct atomisp_3a_config *a3a_config;
};
#define ATOMISP_GAMMA_TABLE_SIZE 1024
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_gamma_table {
 unsigned short data[ATOMISP_GAMMA_TABLE_SIZE];
};
#define ATOMISP_MORPH_TABLE_NUM_PLANES 6
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_morph_table {
 unsigned int height;
 unsigned int width;
 unsigned short __user *coordinates_x[ATOMISP_MORPH_TABLE_NUM_PLANES];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short __user *coordinates_y[ATOMISP_MORPH_TABLE_NUM_PLANES];
};
#define ATOMISP_NUM_SC_COLORS 4
#define ATOMISP_SC_FLAG_QUERY (1 << 0)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_shading_table {
 __u8 flags;
 __u8 enable;
 __u32 sensor_width;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 sensor_height;
 __u32 width;
 __u32 height;
 __u32 fraction_bits;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 __user *data[ATOMISP_NUM_SC_COLORS];
};
struct atomisp_makernote_info {
 unsigned int focal_length;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int f_number_curr;
 unsigned int f_number_range;
};
#define ATOMISP_NUM_MACC_AXES 16
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_macc_table {
 short data[4 * ATOMISP_NUM_MACC_AXES];
};
struct atomisp_macc_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int color_effect;
 struct atomisp_macc_table table;
};
#define ATOMISP_CTC_TABLE_SIZE 1024
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_ctc_table {
 unsigned short data[ATOMISP_CTC_TABLE_SIZE];
};
struct atomisp_overlay {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct v4l2_framebuffer *frame;
 unsigned char bg_y;
 char bg_u;
 char bg_v;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char blend_input_perc_y;
 unsigned char blend_input_perc_u;
 unsigned char blend_input_perc_v;
 unsigned char blend_overlay_perc_y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char blend_overlay_perc_u;
 unsigned char blend_overlay_perc_v;
 unsigned int overlay_start_x;
 unsigned int overlay_start_y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_sensor_mode_data {
 unsigned int coarse_integration_time_min;
 unsigned int coarse_integration_time_max_margin;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int fine_integration_time_min;
 unsigned int fine_integration_time_max_margin;
 unsigned int fine_integration_time_def;
 unsigned int frame_length_lines;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int line_length_pck;
 unsigned int read_mode;
 unsigned int vt_pix_clk_freq_mhz;
 unsigned int crop_horizontal_start;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int crop_vertical_start;
 unsigned int crop_horizontal_end;
 unsigned int crop_vertical_end;
 unsigned int output_width;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int output_height;
 uint8_t binning_factor_x;
 uint8_t binning_factor_y;
 uint8_t reserved[2];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_exposure {
 unsigned int integration_time[8];
 unsigned int shutter_speed[8];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int gain[4];
 unsigned int aperture;
};
struct atomisp_bc_video_package {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int ioctl_cmd;
 int device_id;
 int inputparam;
 int outputparam;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum atomisp_focus_hp {
 ATOMISP_FOCUS_HP_IN_PROGRESS = (1U << 2),
 ATOMISP_FOCUS_HP_COMPLETE = (2U << 2),
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_FOCUS_HP_FAILED = (3U << 2)
};
#define ATOMISP_FOCUS_STATUS_MOVING (1U << 0)
#define ATOMISP_FOCUS_STATUS_ACCEPTS_NEW_MOVE (1U << 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_FOCUS_STATUS_HOME_POSITION (3U << 2)
enum atomisp_camera_port {
 ATOMISP_CAMERA_PORT_SECONDARY,
 ATOMISP_CAMERA_PORT_PRIMARY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_CAMERA_PORT_THIRD,
 ATOMISP_CAMERA_NR_PORTS
};
enum atomisp_flash_mode {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_FLASH_MODE_OFF,
 ATOMISP_FLASH_MODE_FLASH,
 ATOMISP_FLASH_MODE_TORCH,
 ATOMISP_FLASH_MODE_INDICATOR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum atomisp_flash_status {
 ATOMISP_FLASH_STATUS_OK,
 ATOMISP_FLASH_STATUS_HW_ERROR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_FLASH_STATUS_INTERRUPTED,
 ATOMISP_FLASH_STATUS_TIMEOUT,
};
enum atomisp_frame_status {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_FRAME_STATUS_OK,
 ATOMISP_FRAME_STATUS_CORRUPTED,
 ATOMISP_FRAME_STATUS_FLASH_EXPOSED,
 ATOMISP_FRAME_STATUS_FLASH_PARTIAL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_FRAME_STATUS_FLASH_FAILED,
};
enum atomisp_acc_type {
 ATOMISP_ACC_STANDALONE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_ACC_OUTPUT,
 ATOMISP_ACC_VIEWFINDER
};
enum atomisp_acc_arg_type {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_ACC_ARG_SCALAR_IN,
 ATOMISP_ACC_ARG_SCALAR_OUT,
 ATOMISP_ACC_ARG_SCALAR_IO,
 ATOMISP_ACC_ARG_PTR_IN,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_ACC_ARG_PTR_OUT,
 ATOMISP_ACC_ARG_PTR_IO,
 ATOMISP_ARG_PTR_NOFLUSH,
 ATOMISP_ARG_PTR_STABLE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_ACC_ARG_FRAME
};
enum atomisp_acc_memory {
 ATOMISP_ACC_MEMORY_PMEM = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_ACC_MEMORY_DMEM,
 ATOMISP_ACC_MEMORY_VMEM,
 ATOMISP_ACC_MEMORY_VAMEM1,
 ATOMISP_ACC_MEMORY_VAMEM2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ATOMISP_ACC_NR_MEMORY
};
struct atomisp_sp_arg {
 enum atomisp_acc_arg_type type;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 void *value;
 unsigned int size;
};
struct atomisp_acc_fw_arg {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int fw_handle;
 unsigned int index;
 void __user *value;
 size_t size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct atomisp_acc_s_mapped_arg {
 unsigned int fw_handle;
 __u32 memory;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 size_t length;
 unsigned long css_ptr;
};
struct atomisp_acc_fw_abort {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int fw_handle;
 unsigned int timeout;
};
struct atomisp_acc_fw_load {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int size;
 unsigned int fw_handle;
 void __user *data;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct atomisp_acc_fw_load_to_pipe {
 __u32 flags;
 unsigned int fw_handle;
 __u32 size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 void __user *data;
 __u32 type;
 __u32 reserved[3];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_ACC_FW_LOAD_FL_PREVIEW (1 << 0)
#define ATOMISP_ACC_FW_LOAD_FL_COPY (1 << 1)
#define ATOMISP_ACC_FW_LOAD_FL_VIDEO (1 << 2)
#define ATOMISP_ACC_FW_LOAD_FL_CAPTURE (1 << 3)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_ACC_FW_LOAD_FL_ACC (1 << 4)
#define ATOMISP_ACC_FW_LOAD_TYPE_NONE 0
#define ATOMISP_ACC_FW_LOAD_TYPE_OUTPUT 1
#define ATOMISP_ACC_FW_LOAD_TYPE_VIEWFINDER 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_ACC_FW_LOAD_TYPE_STANDALONE 3
struct atomisp_acc_map {
 __u32 flags;
 __u32 length;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 void __user *user_ptr;
 unsigned long css_ptr;
 __u32 reserved[4];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_MAP_FLAG_NOFLUSH 0x0001
struct v4l2_private_int_data {
 __u32 size;
 void __user *data;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 reserved[2];
};
#define ATOMISP_IOC_G_XNR   _IOR('v', BASE_VIDIOC_PRIVATE + 0, int)
#define ATOMISP_IOC_S_XNR   _IOW('v', BASE_VIDIOC_PRIVATE + 1, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_G_NR   _IOR('v', BASE_VIDIOC_PRIVATE + 2, struct atomisp_nr_config)
#define ATOMISP_IOC_S_NR   _IOW('v', BASE_VIDIOC_PRIVATE + 3, struct atomisp_nr_config)
#define ATOMISP_IOC_G_TNR   _IOR('v', BASE_VIDIOC_PRIVATE + 4, struct atomisp_tnr_config)
#define ATOMISP_IOC_S_TNR   _IOW('v', BASE_VIDIOC_PRIVATE + 5, struct atomisp_tnr_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_G_HISTOGRAM   _IOWR('v', BASE_VIDIOC_PRIVATE + 6, struct atomisp_histogram)
#define ATOMISP_IOC_S_HISTOGRAM   _IOW('v', BASE_VIDIOC_PRIVATE + 7, struct atomisp_histogram)
#define ATOMISP_IOC_G_BLACK_LEVEL_COMP   _IOR('v', BASE_VIDIOC_PRIVATE + 8, struct atomisp_ob_config)
#define ATOMISP_IOC_S_BLACK_LEVEL_COMP   _IOW('v', BASE_VIDIOC_PRIVATE + 9, struct atomisp_ob_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_G_EE   _IOR('v', BASE_VIDIOC_PRIVATE + 12, struct atomisp_ee_config)
#define ATOMISP_IOC_S_EE   _IOW('v', BASE_VIDIOC_PRIVATE + 13, struct atomisp_ee_config)
#define ATOMISP_IOC_G_DIS_STAT   _IOWR('v', BASE_VIDIOC_PRIVATE + 14, struct atomisp_dis_statistics)
#define ATOMISP_IOC_S_DIS_COEFS   _IOW('v', BASE_VIDIOC_PRIVATE + 15, struct atomisp_dis_coefficients)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_S_DIS_VECTOR   _IOW('v', BASE_VIDIOC_PRIVATE + 16, struct atomisp_dis_vector)
#define ATOMISP_IOC_G_3A_STAT   _IOW('v', BASE_VIDIOC_PRIVATE + 17, struct atomisp_3a_statistics)
#define ATOMISP_IOC_G_ISP_PARM   _IOR('v', BASE_VIDIOC_PRIVATE + 18, struct atomisp_parm)
#define ATOMISP_IOC_S_ISP_PARM   _IOW('v', BASE_VIDIOC_PRIVATE + 19, struct atomisp_parm)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_G_ISP_GAMMA   _IOR('v', BASE_VIDIOC_PRIVATE + 20, struct atomisp_gamma_table)
#define ATOMISP_IOC_S_ISP_GAMMA   _IOW('v', BASE_VIDIOC_PRIVATE + 21, struct atomisp_gamma_table)
#define ATOMISP_IOC_G_ISP_GDC_TAB   _IOR('v', BASE_VIDIOC_PRIVATE + 22, struct atomisp_morph_table)
#define ATOMISP_IOC_S_ISP_GDC_TAB   _IOW('v', BASE_VIDIOC_PRIVATE + 23, struct atomisp_morph_table)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_ISP_MAKERNOTE   _IOWR('v', BASE_VIDIOC_PRIVATE + 24, struct atomisp_makernote_info)
#define ATOMISP_IOC_G_ISP_MACC   _IOR('v', BASE_VIDIOC_PRIVATE + 25, struct atomisp_macc_config)
#define ATOMISP_IOC_S_ISP_MACC   _IOW('v', BASE_VIDIOC_PRIVATE + 26, struct atomisp_macc_config)
#define ATOMISP_IOC_G_ISP_BAD_PIXEL_DETECTION   _IOR('v', BASE_VIDIOC_PRIVATE + 27, struct atomisp_dp_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_S_ISP_BAD_PIXEL_DETECTION   _IOW('v', BASE_VIDIOC_PRIVATE + 28, struct atomisp_dp_config)
#define ATOMISP_IOC_G_ISP_FALSE_COLOR_CORRECTION   _IOR('v', BASE_VIDIOC_PRIVATE + 29, struct atomisp_de_config)
#define ATOMISP_IOC_S_ISP_FALSE_COLOR_CORRECTION   _IOW('v', BASE_VIDIOC_PRIVATE + 30, struct atomisp_de_config)
#define ATOMISP_IOC_G_ISP_CTC   _IOR('v', BASE_VIDIOC_PRIVATE + 31, struct atomisp_ctc_table)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_S_ISP_CTC   _IOW('v', BASE_VIDIOC_PRIVATE + 32, struct atomisp_ctc_table)
#define ATOMISP_IOC_G_ISP_WHITE_BALANCE   _IOR('v', BASE_VIDIOC_PRIVATE + 33, struct atomisp_wb_config)
#define ATOMISP_IOC_S_ISP_WHITE_BALANCE   _IOW('v', BASE_VIDIOC_PRIVATE + 34, struct atomisp_wb_config)
#define ATOMISP_IOC_S_ISP_FPN_TABLE   _IOW('v', BASE_VIDIOC_PRIVATE + 35, struct v4l2_framebuffer)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_G_ISP_OVERLAY   _IOWR('v', BASE_VIDIOC_PRIVATE + 36, struct atomisp_overlay)
#define ATOMISP_IOC_S_ISP_OVERLAY   _IOW('v', BASE_VIDIOC_PRIVATE + 37, struct atomisp_overlay)
#define ATOMISP_IOC_CAMERA_BRIDGE   _IOWR('v', BASE_VIDIOC_PRIVATE + 38, struct atomisp_bc_video_package)
#define ATOMISP_IOC_G_SENSOR_MODE_DATA   _IOR('v', BASE_VIDIOC_PRIVATE + 39, struct atomisp_sensor_mode_data)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_S_EXPOSURE   _IOW('v', BASE_VIDIOC_PRIVATE + 40, struct atomisp_exposure)
#define ATOMISP_IOC_G_SENSOR_CALIBRATION_GROUP   _IOWR('v', BASE_VIDIOC_PRIVATE + 41, struct atomisp_calibration_group)
#define ATOMISP_IOC_G_3A_CONFIG   _IOR('v', BASE_VIDIOC_PRIVATE + 42, struct atomisp_3a_config)
#define ATOMISP_IOC_S_3A_CONFIG   _IOW('v', BASE_VIDIOC_PRIVATE + 43, struct atomisp_3a_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_ACC_LOAD   _IOWR('v', BASE_VIDIOC_PRIVATE + 44, struct atomisp_acc_fw_load)
#define ATOMISP_IOC_ACC_UNLOAD   _IOWR('v', BASE_VIDIOC_PRIVATE + 45, unsigned int)
#define ATOMISP_IOC_ACC_S_ARG   _IOW('v', BASE_VIDIOC_PRIVATE + 46, struct atomisp_acc_fw_arg)
#define ATOMISP_IOC_ACC_START   _IOW('v', BASE_VIDIOC_PRIVATE + 47, unsigned int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_ACC_WAIT   _IOW('v', BASE_VIDIOC_PRIVATE + 48, unsigned int)
#define ATOMISP_IOC_ACC_ABORT   _IOW('v', BASE_VIDIOC_PRIVATE + 49, struct atomisp_acc_fw_abort)
#define ATOMISP_IOC_G_SENSOR_PRIV_INT_DATA   _IOWR('v', BASE_VIDIOC_PRIVATE + 50, struct v4l2_private_int_data)
#define ATOMISP_IOC_S_ISP_SHD_TAB   _IOWR('v', BASE_VIDIOC_PRIVATE + 51, struct atomisp_shading_table)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_G_ISP_GAMMA_CORRECTION   _IOR('v', BASE_VIDIOC_PRIVATE + 52, struct atomisp_gc_config)
#define ATOMISP_IOC_S_ISP_GAMMA_CORRECTION   _IOW('v', BASE_VIDIOC_PRIVATE + 53, struct atomisp_gc_config)
#define ATOMISP_IOC_ACC_DESTAB   _IOW('v', BASE_VIDIOC_PRIVATE + 54, struct atomisp_acc_fw_arg)
#define ATOMISP_IOC_G_MOTOR_PRIV_INT_DATA   _IOWR('v', BASE_VIDIOC_PRIVATE + 57, struct v4l2_private_int_data)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_ACC_MAP   _IOWR('v', BASE_VIDIOC_PRIVATE + 58, struct atomisp_acc_map)
#define ATOMISP_IOC_ACC_UNMAP   _IOW('v', BASE_VIDIOC_PRIVATE + 59, struct atomisp_acc_map)
#define ATOMISP_IOC_ACC_S_MAPPED_ARG   _IOW('v', BASE_VIDIOC_PRIVATE + 60, struct atomisp_acc_s_mapped_arg)
#define ATOMISP_IOC_S_PARAMETERS   _IOW('v', BASE_VIDIOC_PRIVATE + 61, struct atomisp_parameters)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATOMISP_IOC_S_CONT_CAPTURE_CONFIG   _IOWR('v', BASE_VIDIOC_PRIVATE + 62, struct atomisp_cont_capture_conf)
#define ATOMISP_IOC_ACC_LOAD_TO_PIPE   _IOWR('v', BASE_VIDIOC_PRIVATE + 63, struct atomisp_acc_fw_load_to_pipe)
#define V4L2_CID_ATOMISP_BAD_PIXEL_DETECTION   (V4L2_CID_PRIVATE_BASE + 0)
#define V4L2_CID_ATOMISP_POSTPROCESS_GDC_CAC   (V4L2_CID_PRIVATE_BASE + 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_CID_ATOMISP_VIDEO_STABLIZATION   (V4L2_CID_PRIVATE_BASE + 2)
#define V4L2_CID_ATOMISP_FIXED_PATTERN_NR   (V4L2_CID_PRIVATE_BASE + 3)
#define V4L2_CID_ATOMISP_FALSE_COLOR_CORRECTION   (V4L2_CID_PRIVATE_BASE + 4)
#define V4L2_CID_ATOMISP_LOW_LIGHT   (V4L2_CID_PRIVATE_BASE + 5)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_CID_CAMERA_LASTP1 (V4L2_CID_CAMERA_CLASS_BASE + 1024)
#define V4L2_CID_FOCAL_ABSOLUTE (V4L2_CID_CAMERA_LASTP1 + 0)
#define V4L2_CID_FNUMBER_ABSOLUTE (V4L2_CID_CAMERA_LASTP1 + 1)
#define V4L2_CID_FNUMBER_RANGE (V4L2_CID_CAMERA_LASTP1 + 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_CID_REQUEST_FLASH (V4L2_CID_CAMERA_LASTP1 + 3)
#define V4L2_CID_FLASH_STATUS (V4L2_CID_CAMERA_LASTP1 + 5)
#define V4L2_CID_FLASH_MODE (V4L2_CID_CAMERA_LASTP1 + 10)
#define V4L2_CID_VCM_SLEW (V4L2_CID_CAMERA_LASTP1 + 11)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_CID_VCM_TIMEING (V4L2_CID_CAMERA_LASTP1 + 12)
#define V4L2_CID_TEST_PATTERN (V4L2_CID_CAMERA_LASTP1 + 13)
#define V4L2_CID_FOCUS_STATUS (V4L2_CID_CAMERA_LASTP1 + 14)
#define V4L2_CID_BIN_FACTOR_HORZ (V4L2_CID_CAMERA_LASTP1 + 15)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_CID_BIN_FACTOR_VERT (V4L2_CID_CAMERA_LASTP1 + 16)
#define V4L2_CID_G_SKIP_FRAMES (V4L2_CID_CAMERA_LASTP1 + 17)
#define V4L2_CID_2A_STATUS (V4L2_CID_CAMERA_LASTP1 + 18)
#define V4L2_2A_STATUS_AE_READY (1 << 0)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_2A_STATUS_AWB_READY (1 << 1)
#define V4L2_BUF_FLAG_BUFFER_INVALID 0x0400
#define V4L2_BUF_FLAG_BUFFER_VALID 0x0800
#define V4L2_BUF_TYPE_VIDEO_CAPTURE_ION (V4L2_BUF_TYPE_PRIVATE + 1024)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
 V4L2_COLORFX_SKIN_WHITEN_LOW = 1001,
 V4L2_COLORFX_SKIN_WHITEN_HIGH = 1002,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
