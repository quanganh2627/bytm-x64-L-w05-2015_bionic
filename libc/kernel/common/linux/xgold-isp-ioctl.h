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
#ifndef _XGOLD_ISP_IOCTL_H
#define _XGOLD_ISP_IOCTL_H
#define CIFISP_CTK_COEFF_MAX 0x400
#define CIFISP_CTK_OFFSET_MAX 0x800
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_AE_MEAN_MAX 25
#define CIFISP_HIST_BIN_N_MAX 128
#define CIFISP_AFM_MAX_WINDOWS 3
#define CIFISP_BDM_MAX_TH 0xFF
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_FILT_MODE_MAX 0x2
#define CIFISP_FILT_CH_MODE_MAX 0x3
#define CIFISP_FILT_DIAG_SHARP_MAX 0x1
#define CIFISP_FILT_DIAG_TH_MAX 0x3FF
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_BP_MAX_TBL_NUM 128
#define CIFISP_BP_NEW_DET_MAX_NUM 8
#define CIFISP_BP_PIX_TYP (0x80000000)
#define CIFISP_BP_V_ADDR (0x07FF0000)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_BP_V_ADDR_SHIFT (16)
#define CIFISP_BP_H_ADDR (0x00000FFF)
#define CIFISP_BP_HOT_THRESH_MAX 0x00000FFF
#define CIFISP_BP_DEAD_THRESH_MAX 0x00000FFF
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_BLS_START_H_MAX (0x00000FFF)
#define CIFISP_BLS_STOP_H_MAX (0x00000FFF)
#define CIFISP_BLS_START_V_MAX (0x00000FFF)
#define CIFISP_BLS_STOP_V_MAX (0x00000FFF)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_BLS_SAMPLES_MAX (0x00000012)
#define CIFISP_BLS_FIX_SUB_MAX (0x00000FFF)
#define CIFISP_BLS_FIX_SUB_MIN (0xFFFFF000)
#define CIFISP_BLS_FIX_MASK (0x00001FFF)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_AWB_GAINS_MAX_VAL (0x000003FF)
#define CIFISP_AWB_GRID_MAX_OFFSET (0x00001FFF)
#define CIFISP_AWB_GRID_MAX_DIM (0x0000003F)
#define CIFISP_AWB_WINDOW_MAX_SIZE (0x00001FFF)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_AWB_GRID_MAX_DIST (0x00001FFF)
#define CIFISP_AWB_CBCR_MAX_REF (0x000000FF)
#define CIFISP_AWB_THRES_MAX_YC (0x000000FF)
#define CIFISP_AWB_MAX_SAT (0x00000FFF)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_AWB_MAX_GRID 972
#define CIFISP_AWB_MAX_FRAMES 7
#define CIFISP_EXP_ROW_NUM (5)
#define CIFISP_EXP_COLUMN_NUM (5)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_EXP_NUM_LUMA_REGS (CIFISP_EXP_ROW_NUM *  CIFISP_EXP_COLUMN_NUM)
#define CIFISP_EXP_MAX_HOFFS (2424)
#define CIFISP_EXP_MAX_VOFFS (1806)
#define CIFISP_EXP_MAX_HSIZE (520)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_EXP_MIN_HSIZE (35)
#define CIFISP_EXP_MAX_VSIZE (390)
#define CIFISP_EXP_MIN_VSIZE (28)
#define CIFISP_EXP_HEIGHT_MASK (0x000001FE)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_EXP_MAX_HOFFSET (0x00000FFF)
#define CIFISP_EXP_MAX_VOFFSET (0x000007FF)
#define CIFISP_MAX_HIST_PREDIVIDER (0x0000007F)
#define CIFISP_HIST_WINDOW_RESERVED (0xFFFFF000)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_GAMMA_OUT_MAX_SAMPLES 257
#define CIFISP_GAMMA_OUT_MAX_ADDR 128
#define CIFISP_LSC_MIN_XSECT_SIZE 11
#define CIFISP_LSC_MAX_XSECT_SIZE 1024
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_LSC_MIN_YSECT_SIZE 9
#define CIFISP_LSC_MAX_YSECT_SIZE 1024
#define CIFISP_LSC_GRAD_TBL_SIZE 16
#define CIFISP_LSC_SIZE_TBL_SIZE 16
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_LSC_DATA_TBL_SIZE 561
#define CIFISP_BPC_MAX_HOT_TB_SHIFT (7)
#define CIFISP_BPC_MAX_DEAD_TB_SHIFT (7)
#define CIFISP_BPC_MAX_HOT_GRAD_TRIG (7)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_BPC_MAX_DEAD_GRAD_TRIG (7)
#define CIFISP_TONE_MAP_TABLE_SIZE 257
enum cifisp_histogram_mode {
 CIFISP_HISTOGRAM_MODE_DISABLE = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 CIFISP_HISTOGRAM_MODE_RGB_COMBINED = 1,
 CIFISP_HISTOGRAM_MODE_R_HISTOGRAM = 2,
 CIFISP_HISTOGRAM_MODE_G_HISTOGRAM = 3,
 CIFISP_HISTOGRAM_MODE_B_HISTOGRAM = 4,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 CIFISP_HISTOGRAM_MODE_Y_HISTOGRAM = 5
};
enum cifisp_exp_ctrl_autostop {
 CIFISP_EXP_CTRL_AUTOSTOP_0 = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 CIFISP_EXP_CTRL_AUTOSTOP_1 = 1
};
struct cifisp_window {
 unsigned short h_offs;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short v_offs;
 unsigned short h_size;
 unsigned short v_size;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum cifisp_awb_mode_type {
 CIFISP_AWB_MODE_MANUAL = 0,
 CIFISP_AWB_MODE_RGB = 1,
 CIFISP_AWB_MODE_YCBCR = 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum cifisp_bp_type {
 CIFISP_BP_TYPE_HOT,
 CIFISP_BP_TYPE_DEAD
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum cifisp_bp_corr_type {
 CIFISP_BP_CORR_TYPE_TABLE,
 CIFISP_BP_CORR_TYPE_DIRECT
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum cifisp_bp_corr_rep {
 CIFISP_BP_CORR_REP_NB,
 CIFISP_BP_CORR_REP_LIN
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum cifisp_bp_corr_mode {
 CIF_ISP_BP_CORR_HOT_EN,
 CIF_ISP_BP_CORR_DEAD_EN,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 CIF_ISP_BP_CORR_HOT_DEAD_EN
};
enum cifisp_stat_type {
 CIFISP_STAT_AWB,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 CIFISP_STAT_AUTOEXP,
 CIFISP_STAT_AFM_FIN
};
enum cifisp_bls_win_enable {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ISP_BLS_CTRL_WINDOW_ENABLE_0 = 0,
 ISP_BLS_CTRL_WINDOW_ENABLE_1 = 1,
 ISP_BLS_CTRL_WINDOW_ENABLE_2 = 2,
 ISP_BLS_CTRL_WINDOW_ENABLE_3 = 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_awb_meas {
 unsigned int cnt;
 unsigned char mean_y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char mean_cb;
 unsigned char mean_cr;
 unsigned short mean_r;
 unsigned short mean_b;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short mean_g;
};
struct cifisp_awb_stat {
 struct cifisp_awb_meas awb_mean[CIFISP_AWB_MAX_GRID];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short hist_bins[CIFISP_HIST_BIN_N_MAX];
};
struct cifisp_bls_meas_val {
 unsigned short meas_a;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short meas_b;
 unsigned short meas_c;
 unsigned short meas_d;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_ae_stat {
 unsigned char exp_mean[CIFISP_AE_MEAN_MAX];
 struct cifisp_bls_meas_val bls_val;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_af_meas_val {
 unsigned int sum;
 unsigned int lum;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_af_stat {
 struct cifisp_af_meas_val window[CIFISP_AFM_MAX_WINDOWS];
};
union cifisp_stat {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_awb_stat awb;
 struct cifisp_ae_stat ae;
 struct cifisp_af_stat af;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_stat_buffer {
 enum cifisp_stat_type meas_type;
 union cifisp_stat params;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_bp_table_elem {
 unsigned short bp_ver_addr;
 unsigned short bp_hor_addr;
 unsigned char bp_val;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_bp_table {
 struct cifisp_bp_table_elem bp_tbl[CIFISP_BP_MAX_TBL_NUM];
 unsigned int bp_tbl_elem_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_bp_detection_config {
 bool bp_hot_turbulence_adj_en;
 bool bp_dead_turbulence_adj_en;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 bool bp_dev_hot_sign_sens;
 bool bp_dev_dead_sign_sens;
 unsigned char bp_hot_turbulence_shift;
 unsigned char bp_dead_turbulence_shift;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char bp_dev_hot_grad_trig_lvl;
 unsigned char bp_dev_dead_grad_trig_lvl;
};
struct cifisp_bp_correction_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 enum cifisp_bp_corr_type corr_type;
 enum cifisp_bp_corr_rep corr_rep;
 enum cifisp_bp_corr_mode corr_mode;
 unsigned char new_acc_thresh;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short abs_hot_thres;
 unsigned short abs_dead_thres;
 unsigned short dev_hot_thres;
 unsigned short dev_dead_thres;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_bp_table bp_corr_tbl;
};
struct cifisp_bls_fixed_val {
 signed short fixed_a;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 signed short fixed_b;
 signed short fixed_c;
 signed short fixed_d;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_gamma_corr_curve {
 unsigned short gamma_y0;
 unsigned short gamma_y1;
 unsigned short gamma_y2;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short gamma_y3;
 unsigned short gamma_y4;
 unsigned short gamma_y5;
 unsigned short gamma_y6;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short gamma_y7;
 unsigned short gamma_y8;
 unsigned short gamma_y9;
 unsigned short gamma_y10;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short gamma_y11;
 unsigned short gamma_y12;
 unsigned short gamma_y13;
 unsigned short gamma_y14;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short gamma_y15;
 unsigned short gamma_y16;
};
struct cifisp_gamma_curve_x_axis_pnts {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int gamma_dx0;
 unsigned int gamma_dx1;
};
struct cifisp_bpc_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_bp_correction_config corr_config;
 struct cifisp_bp_detection_config det_config;
};
struct cifisp_bls_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 bool enable_auto;
 unsigned char en_windows;
 struct cifisp_window bls_window1;
 struct cifisp_window bls_window2;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char bls_samples;
 struct cifisp_bls_fixed_val fixed_val;
};
struct cifisp_sdg_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_gamma_corr_curve curve_r;
 struct cifisp_gamma_corr_curve curve_g;
 struct cifisp_gamma_corr_curve curve_b;
 struct cifisp_gamma_curve_x_axis_pnts xa_pnts;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_lsc_config {
 unsigned int r_data_tbl[CIFISP_LSC_DATA_TBL_SIZE];
 unsigned int g_data_tbl[CIFISP_LSC_DATA_TBL_SIZE];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int b_data_tbl[CIFISP_LSC_DATA_TBL_SIZE];
 unsigned int x_grad_tbl[CIFISP_LSC_GRAD_TBL_SIZE];
 unsigned int y_grad_tbl[CIFISP_LSC_GRAD_TBL_SIZE];
 unsigned int x_size_tbl[CIFISP_LSC_SIZE_TBL_SIZE];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int y_size_tbl[CIFISP_LSC_SIZE_TBL_SIZE];
 unsigned short config_width;
 unsigned short config_height;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_awb_meas_config {
 struct cifisp_window awb_wnd;
 enum cifisp_awb_mode_type awb_mode;
 unsigned char max_y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char min_y;
 unsigned char max_csum;
 unsigned char min_c;
 unsigned char frames;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char awb_ref_cr;
 unsigned char awb_ref_cb;
 unsigned short gb_sat;
 unsigned short gr_sat;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short b_sat;
 unsigned short r_sat;
 unsigned char grid_h_dim;
 unsigned char grid_v_dim;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short grid_h_dist;
 unsigned short grid_v_dist;
 bool enable_ymax_cmp;
 bool rgb_meas_pnt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_awb_gain_config {
 unsigned short gain_red;
 unsigned short gain_green_r;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short gain_blue;
 unsigned short gain_green_b;
};
struct cifisp_flt_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int flt_mask_sharp0;
 unsigned int flt_mask_sharp1;
 unsigned int flt_mask_diag;
 unsigned int flt_mask_blur_max;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int flt_mask_blur;
 unsigned int flt_mask_lin;
 unsigned int flt_mask_orth;
 unsigned int flt_mask_v_diag;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int flt_mask_h_diag;
 unsigned int flt_lum_weight;
 unsigned short flt_blur_th0;
 unsigned short flt_blur_th1;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short flt_sharp0_th;
 unsigned short flt_sharp1_th;
 unsigned char flt_chrom_h_mode;
 unsigned char flt_chrom_v_mode;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char flt_diag_sharp_mode;
 unsigned char flt_mode;
};
struct cifisp_bdm_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char demosaic_th;
};
struct cifisp_ctk_config {
 unsigned short coeff0;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short coeff1;
 unsigned short coeff2;
 unsigned short coeff3;
 unsigned short coeff4;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short coeff5;
 unsigned short coeff6;
 unsigned short coeff7;
 unsigned short coeff8;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned short ct_offset_r;
 unsigned short ct_offset_g;
 unsigned short ct_offset_b;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_goc_config {
 unsigned short gamma_r[CIFISP_GAMMA_OUT_MAX_SAMPLES];
 unsigned short gamma_g[CIFISP_GAMMA_OUT_MAX_SAMPLES];
 unsigned short gamma_b[CIFISP_GAMMA_OUT_MAX_SAMPLES];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_macc_coeff {
 unsigned int coeff0;
 unsigned int coeff1;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_macc_config {
 struct cifisp_macc_coeff seg0;
 struct cifisp_macc_coeff seg1;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_macc_coeff seg2;
 struct cifisp_macc_coeff seg3;
 struct cifisp_macc_coeff seg4;
 struct cifisp_macc_coeff seg5;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_macc_coeff seg6;
 struct cifisp_macc_coeff seg7;
 struct cifisp_macc_coeff seg8;
 struct cifisp_macc_coeff seg9;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_macc_coeff seg10;
 struct cifisp_macc_coeff seg11;
 struct cifisp_macc_coeff seg12;
 struct cifisp_macc_coeff seg13;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_macc_coeff seg14;
 struct cifisp_macc_coeff seg15;
};
struct cifisp_cproc_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char c_out_range;
 unsigned char y_in_range;
 unsigned char y_out_range;
 unsigned char contrast;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned char brightness;
 unsigned char sat;
 unsigned char hue;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_tmap_config {
 unsigned short tmap_y[CIFISP_TONE_MAP_TABLE_SIZE];
 unsigned short tmap_c[CIFISP_TONE_MAP_TABLE_SIZE];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct cifisp_hst_config {
 enum cifisp_histogram_mode mode;
 unsigned char histogram_predivider;
 struct cifisp_window meas_window;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_aec_config {
 enum cifisp_exp_ctrl_autostop autostop;
 struct cifisp_window meas_window;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_ycflt_config {
 unsigned int ctrl;
 unsigned int chr_ss_ctrl;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int chr_ss_fac;
 unsigned int chr_ss_offs;
 unsigned int chr_nr_ctrl;
 unsigned int lum_eenr_edge_gain;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int lum_eenr_corner_gain;
 unsigned int lum_eenr_fc_crop_pos;
 unsigned int lum_eenr_fc_crop_neg;
 unsigned int lum_eenr_fc_gain_pos;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int lum_eenr_fc_gain_neg;
};
struct cifisp_last_capture_config {
 struct cifisp_ycflt_config ycflt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_tmap_config tmap;
 struct cifisp_cproc_config cproc;
 struct cifisp_macc_config macc;
 struct cifisp_goc_config goc;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_ctk_config ctk;
 struct cifisp_bdm_config bdm;
 struct cifisp_flt_config flt;
 struct cifisp_awb_gain_config awb_gain;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct cifisp_awb_meas_config awb_meas;
 struct cifisp_lsc_config lsc;
 struct cifisp_sdg_config sdg;
 struct cifisp_bls_config bls;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct cifisp_afc_config {
 unsigned char num_afm_win;
 struct cifisp_window afm_win[CIFISP_AFM_MAX_WINDOWS];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int thres;
 unsigned int var_shift;
};
#define CIFISP_IOC_G_BPC   _IOR('v', BASE_VIDIOC_PRIVATE + 0, struct cifisp_bpc_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_IOC_S_BPC   _IOW('v', BASE_VIDIOC_PRIVATE + 1, struct cifisp_bpc_config)
#define CIFISP_IOC_G_BLS   _IOR('v', BASE_VIDIOC_PRIVATE + 2, struct cifisp_bls_config)
#define CIFISP_IOC_S_BLS   _IOW('v', BASE_VIDIOC_PRIVATE + 3, struct cifisp_bls_config)
#define CIFISP_IOC_G_SDG   _IOR('v', BASE_VIDIOC_PRIVATE + 4, struct cifisp_sdg_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_IOC_S_SDG   _IOW('v', BASE_VIDIOC_PRIVATE + 5, struct cifisp_sdg_config)
#define CIFISP_IOC_G_LSC   _IOR('v', BASE_VIDIOC_PRIVATE + 6, struct cifisp_lsc_config)
#define CIFISP_IOC_S_LSC   _IOW('v', BASE_VIDIOC_PRIVATE + 7, struct cifisp_lsc_config)
#define CIFISP_IOC_G_AWB_MEAS   _IOR('v', BASE_VIDIOC_PRIVATE + 8, struct cifisp_awb_meas_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_IOC_S_AWB_MEAS   _IOW('v', BASE_VIDIOC_PRIVATE + 9, struct cifisp_awb_meas_config)
#define CIFISP_IOC_G_FLT   _IOR('v', BASE_VIDIOC_PRIVATE + 10, struct cifisp_flt_config)
#define CIFISP_IOC_S_FLT   _IOW('v', BASE_VIDIOC_PRIVATE + 11, struct cifisp_flt_config)
#define CIFISP_IOC_G_BDM   _IOR('v', BASE_VIDIOC_PRIVATE + 12, struct cifisp_bdm_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_IOC_S_BDM   _IOW('v', BASE_VIDIOC_PRIVATE + 13, struct cifisp_bdm_config)
#define CIFISP_IOC_G_CTK   _IOR('v', BASE_VIDIOC_PRIVATE + 14, struct cifisp_ctk_config)
#define CIFISP_IOC_S_CTK   _IOW('v', BASE_VIDIOC_PRIVATE + 15, struct cifisp_ctk_config)
#define CIFISP_IOC_G_GOC   _IOR('v', BASE_VIDIOC_PRIVATE + 16, struct cifisp_goc_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_IOC_S_GOC   _IOW('v', BASE_VIDIOC_PRIVATE + 17, struct cifisp_goc_config)
#define CIFISP_IOC_G_HST   _IOR('v', BASE_VIDIOC_PRIVATE + 18, struct cifisp_hst_config)
#define CIFISP_IOC_S_HST   _IOW('v', BASE_VIDIOC_PRIVATE + 19, struct cifisp_hst_config)
#define CIFISP_IOC_G_AEC   _IOR('v', BASE_VIDIOC_PRIVATE + 20, struct cifisp_aec_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_IOC_S_AEC   _IOW('v', BASE_VIDIOC_PRIVATE + 21, struct cifisp_aec_config)
#define CIFISP_IOC_G_BPL   _IOR('v', BASE_VIDIOC_PRIVATE + 22, struct cifisp_aec_config)
#define CIFISP_IOC_G_AWB_GAIN   _IOR('v', BASE_VIDIOC_PRIVATE + 23, struct cifisp_awb_gain_config)
#define CIFISP_IOC_S_AWB_GAIN   _IOW('v', BASE_VIDIOC_PRIVATE + 24, struct cifisp_awb_gain_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_IOC_G_CPROC   _IOR('v', BASE_VIDIOC_PRIVATE + 25, struct cifisp_cproc_config)
#define CIFISP_IOC_S_CPROC   _IOW('v', BASE_VIDIOC_PRIVATE + 26, struct cifisp_cproc_config)
#define CIFISP_IOC_G_MACC   _IOR('v', BASE_VIDIOC_PRIVATE + 27, struct cifisp_macc_config)
#define CIFISP_IOC_S_MACC   _IOW('v', BASE_VIDIOC_PRIVATE + 28, struct cifisp_macc_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_IOC_G_TMAP   _IOR('v', BASE_VIDIOC_PRIVATE + 29, struct cifisp_tmap_config)
#define CIFISP_IOC_S_TMAP   _IOW('v', BASE_VIDIOC_PRIVATE + 30, struct cifisp_tmap_config)
#define CIFISP_IOC_G_YCFLT   _IOR('v', BASE_VIDIOC_PRIVATE + 31, struct cifisp_ycflt_config)
#define CIFISP_IOC_S_YCFLT   _IOW('v', BASE_VIDIOC_PRIVATE + 32, struct cifisp_ycflt_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CIFISP_IOC_G_AFC   _IOR('v', BASE_VIDIOC_PRIVATE + 33, struct cifisp_afc_config)
#define CIFISP_IOC_S_AFC   _IOW('v', BASE_VIDIOC_PRIVATE + 34, struct cifisp_afc_config)
#define CIFISP_IOC_G_LAST_CONFIG   _IOR('v', BASE_VIDIOC_PRIVATE + 35, struct cifisp_last_capture_config)
#define V4L2_CID_CIFISP_BPC (V4L2_CID_PRIVATE_BASE + 0)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_CID_CIFISP_BLS (V4L2_CID_PRIVATE_BASE + 1)
#define V4L2_CID_CIFISP_SDG (V4L2_CID_PRIVATE_BASE + 2)
#define V4L2_CID_CIFISP_LSC (V4L2_CID_PRIVATE_BASE + 3)
#define V4L2_CID_CIFISP_AWB_MEAS (V4L2_CID_PRIVATE_BASE + 4)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_CID_CIFISP_FLT (V4L2_CID_PRIVATE_BASE + 5)
#define V4L2_CID_CIFISP_BDM (V4L2_CID_PRIVATE_BASE + 6)
#define V4L2_CID_CIFISP_CTK (V4L2_CID_PRIVATE_BASE + 7)
#define V4L2_CID_CIFISP_GOC (V4L2_CID_PRIVATE_BASE + 8)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_CID_CIFISP_HST (V4L2_CID_PRIVATE_BASE + 9)
#define V4L2_CID_CIFISP_AEC (V4L2_CID_PRIVATE_BASE + 10)
#define V4L2_CID_CIFISP_AWB_GAIN (V4L2_CID_PRIVATE_BASE + 11)
#define V4L2_CID_CIFISP_CPROC (V4L2_CID_PRIVATE_BASE + 12)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define V4L2_CID_CIFISP_MACC (V4L2_CID_PRIVATE_BASE + 13)
#define V4L2_CID_CIFISP_TMAP (V4L2_CID_PRIVATE_BASE + 14)
#define V4L2_CID_CIFISP_YCFLT (V4L2_CID_PRIVATE_BASE + 15)
#define V4L2_CID_CIFISP_AFC (V4L2_CID_PRIVATE_BASE + 16)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CI_MODE_PREVIEW 0x8000
#define CI_MODE_VIDEO 0x4000
#define CI_MODE_STILL_CAPTURE 0x2000
#define CI_MODE_CONTINUOUS 0x1000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define CI_MODE_NONE 0x0000
#endif
