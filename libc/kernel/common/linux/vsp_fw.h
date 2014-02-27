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
#ifndef _VSP_FW_H_
#define _VSP_FW_H_
#pragma pack(4)
#define VssProcPipelineMaxNumFilters 5
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSS_PROC_MAX_INPUT_PICTURES 1
#define VSS_PROC_MAX_OUTPUT_PICTURES 4
#define VSP_APP_ID_NONE 0
#define VSP_APP_ID_FRC_VPP 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSP_APP_ID_VP8_ENC 2
#define VSP_APP_ID_WIDI_ENC 3
enum VssProcFilterType {
 VssProcFilterDenoise,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssProcFilterSharpening,
 VssProcFilterColorEnhancement,
 VssProcFilterFrameRateConversion
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum VssDenoiseType {
 VssProcDegrain,
 VssProcDeblock
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum VssFrcQuality {
 VssFrcMediumQuality,
 VssFrcHighQuality
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum VssFrcConversionRate {
 VssFrc2xConversionRate,
 VssFrc2_5xConversionRate,
 VssFrc4xConversionRate,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssFrc1_25xConversionRate
};
struct VssProcPipelineParameterBuffer {
 unsigned int num_filters;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 enum VssProcFilterType filter_pipeline[VssProcPipelineMaxNumFilters];
 unsigned int intermediate_buffer_base;
 unsigned int intermediate_buffer_size;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct VssProcSharpenParameterBuffer {
 int quality;
 unsigned int _pad[7];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct VssProcDenoiseParameterBuffer {
 enum VssDenoiseType type;
 int value_thr;
 int cnt_thr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int coef;
 int temp_thr1;
 int temp_thr2;
 int _pad[2];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct VssProcColorEnhancementParameterBuffer {
 int temp_detect;
 int temp_correct;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int clip_thr;
 int mid_thr;
 int luma_amm;
 int chroma_amm;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int _pad[2];
};
struct VssProcFrcParameterBuffer {
 enum VssFrcQuality quality;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 enum VssFrcConversionRate conversion_rate;
 int _pad[6];
};
#define VSP_ROTATION_NONE 0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSP_ROTATION_90 90
#define VSP_ROTATION_180 180
#define VSP_ROTATION_270 270
struct VssProcPicture {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int surface_id;
 unsigned int irq;
 unsigned int base;
 unsigned int height;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int width;
 unsigned int rot_angle;
 unsigned int stride;
 unsigned int format;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int tiled;
 int _pad[7];
};
struct VssProcPictureParameterBuffer {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int num_input_pictures;
 unsigned int num_output_pictures;
 int _pad[6];
 struct VssProcPicture input_picture[VSS_PROC_MAX_INPUT_PICTURES];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct VssProcPicture output_picture[VSS_PROC_MAX_OUTPUT_PICTURES];
};
union VssProcBuffer {
 struct VssProcPipelineParameterBuffer pipeline;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct VssProcSharpenParameterBuffer sharpen_base;
 struct VssProcDenoiseParameterBuffer denoiser_base;
 struct VssProcColorEnhancementParameterBuffer enhancer_base;
 struct VssProcFrcParameterBuffer frc;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct VssProcPictureParameterBuffer picture;
};
enum VssProcCommandType {
 VssProcPipelineParameterCommand = 0xFFFE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssProcSharpenParameterCommand = 0xFFFD,
 VssProcDenoiseParameterCommand = 0xFFFC,
 VssProcColorEnhancementParameterCommand = 0xFFFB,
 VssProcFrcParameterCommand = 0xFFFA,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssProcPictureCommand = 0xFFF9,
 VspFencePictureParamCommand = 0xEBEC,
 VspSetContextCommand = 0xEBED,
 Vss_Sys_STATE_BUF_COMMAND
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define VSP_CMD_QUEUE_SIZE (64)
#define VSP_ACK_QUEUE_SIZE (64)
struct vss_command_t {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int context;
 unsigned int type;
 unsigned int buffer;
 unsigned int size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int buffer_id;
 unsigned int irq;
 unsigned int reserved6;
 unsigned int reserved7;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct vss_response_t {
 unsigned int context;
 unsigned int type;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int buffer;
 unsigned int size;
 unsigned int vss_cc;
 unsigned int reserved5;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int reserved6;
 unsigned int reserved7;
};
#define VSP_COMMAND_INITIALIZER {0, 0, 0, 0, 0, 0, 0, 0}
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSP_RESPONSE_INITIALIZER {0, 0, 0, 0, 0, 0, 0, 0}
enum VssResponseType {
 VssIdleResponse = 0x80010000,
 VssErrorResponse = 0x80020000,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssEndOfSequenceResponse = 0x80030000,
 VssCommandBufferReadyResponse = 0x80040000,
 VssInputSurfaceReadyResponse = 0x80050000,
 VssOutputSurfaceReadyResponse = 0x80060000,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssVp8encSetSequenceParametersResponse = 150,
 VssVp8encEncodeFrameResponse
};
enum VssStatus {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssOK = 0x8001,
 VssInvalidCommandType = 0x8002,
 VssInvalidCommandArgument = 0x8003,
 VssInvalidProcPictureCommand = 0x8004,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssInvalidDdrAddress = 0x8005,
 VssInvalidSequenceParameters_VP8 = 0x1,
 VssInvalidPictureParameters_VP8 = 0x2,
 VssInitFailure_VP8 = 0x5
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum FrcResponseType {
 VssOutputSurfaceFreeResponse = 0x0000F001,
 VssOutputSurfaceCrcResponse = 0x0000F002
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum vsp_format {
 VSP_NV12,
 VSP_YV12,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VSP_UYVY,
 VSP_YUY2,
 VSP_NV11,
 VSP_NV16,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VSP_IYUV,
 VSP_TYPE_ERROR
};
struct vsp_data {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int fw_state;
 unsigned int uninit_req;
};
#define VSP_SECURE_BOOT_MAGIC_NR 0xb0070001
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum vsp_processor {
 vsp_sp0 = 0,
 vsp_sp1 = 1,
 vsp_vp0 = 2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 vsp_vp1 = 3,
 vsp_mea = 4
};
struct vsp_secure_boot_header {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int magic_number;
 unsigned int boot_text_offset;
 unsigned int boot_text_reg;
 unsigned int boot_icache_value;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int boot_icache_reg;
 unsigned int boot_pc_value;
 unsigned int boot_pc_reg;
 unsigned int ma_header_offset;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int ma_header_reg;
 unsigned int boot_start_value;
 unsigned int boot_start_reg;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSP_MULTI_APP_MAGIC_NR 0xb10b0004
#define VSP_MULTI_APP_MAX_APPS 16
#define VSP_MULTI_APP_MAX_CONTEXTS 32
#define VSP_API_GENERIC_CONTEXT_ID (0xffffffff)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct vsp_multi_app_blob_data {
 unsigned int magic_number;
 unsigned int offset_from_start;
 unsigned int imr_state_buffer_addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int imr_state_buffer_size;
 unsigned int apps_default_context_buffer_size;
 unsigned int application_blob_offsets[VSP_MULTI_APP_MAX_APPS];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct vsp_multi_app_context_settings {
 unsigned int app_id;
 unsigned int usage;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct vsp_multi_app_imr_header {
 unsigned int vsp_and_imr_state;
 unsigned int reserved_1;
 unsigned int reserved_2;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int reserved_3;
 unsigned int reserved_4;
 unsigned int reserved_5;
 unsigned int reserved_6;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int reserved_7;
 struct vsp_multi_app_context_settings context_settings[VSP_MULTI_APP_MAX_CONTEXTS];
};
enum vsp_imr_state{
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 vsp_imr_uninitialized = 0,
 vsp_imr_safe_to_resume = 1,
 vsp_imr_initialized = 2,
 vsp_imr_app_is_running = 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum vsp_ctrl_reg_addr {
 VSP_SETTING_ADDR_REG = 3,
 VSP_SECBOOT_DEBUG_REG = 4,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VSP_ENTRY_KIND_REG = 5,
 VSP_POWER_SAVING_MODE_REG = 6,
 VSP_MMU_TLB_SOFT_INVALIDATE_REG = 7,
 VSP_CMD_QUEUE_RD_REG = 12,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VSP_CMD_QUEUE_WR_REG = 13,
 VSP_ACK_QUEUE_RD_REG = 14,
 VSP_ACK_QUEUE_WR_REG = 15
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct vsp_ctrl_reg {
 unsigned int reserved_2;
 unsigned int setting_addr;
 unsigned int secboot_debug;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int entry_kind;
 unsigned int power_saving_mode;
 unsigned int mmu_tlb_soft_invalidate;
 unsigned int reserved_8;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int reserved_9;
 unsigned int reserved_10;
 unsigned int reserved_11;
 unsigned int cmd_rd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int cmd_wr;
 unsigned int ack_rd;
 unsigned int ack_wr;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct vsp_settings_t {
 unsigned int reserved0;
 unsigned int command_queue_size;
 unsigned int command_queue_addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int response_queue_size;
 unsigned int response_queue_addr;
 unsigned int reserved5;
 unsigned int reserved6;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int reserved7;
};
enum vsp_context_usage {
 vsp_context_unused = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 vsp_context_deinit = 1,
 vsp_context_starting = 16,
 vsp_context_in_use = 17
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSP_SETTINGS_INITIALIZER {0, 0, 0, 0, 0, 0, 0, 0}
enum vsp_entry_kind {
 vsp_entry_booted = 0,
 vsp_entry_init = 1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 vsp_entry_resume = 2,
 vsp_exit = 3
};
enum vsp_power_saving_mode {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 vsp_always_on = 0,
 vsp_suspend_on_empty_queue = 1,
 vsp_hw_idle_on_empty_queue = 2,
 vsp_suspend_and_hw_idle_on_empty_queue
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct VssProcPictureVP8 {
 uint32_t surface_id;
 uint32_t irq;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t base;
 uint32_t base_uv;
 uint32_t height;
 uint32_t width;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t stride;
 uint32_t format;
};
typedef enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 vss_vp8enc_seq_param_recon_buffer_mode_per_seq = 0,
 vss_vp8enc_seq_param_recon_buffer_mode_per_pic,
 vss_vp8enc_seq_param_recon_buffer_mode_cnt
} vss_vp8enc_seq_param_recon_buffer_mode_t;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct VssVp8encSequenceParameterBuffer {
 uint32_t frame_width;
 uint32_t frame_height;
 uint32_t frame_rate;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t error_resilient;
 uint32_t num_token_partitions;
 uint32_t kf_mode;
 uint32_t kf_min_dist;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t kf_max_dist;
 uint32_t rc_target_bitrate;
 uint32_t rc_min_quantizer;
 uint32_t rc_max_quantizer;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t rc_undershoot_pct;
 uint32_t rc_overshoot_pct;
 uint32_t rc_end_usage;
 uint32_t rc_buf_sz;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t rc_buf_initial_sz;
 uint32_t rc_buf_optimal_sz;
 uint32_t max_intra_rate;
 uint32_t cyclic_intra_refresh;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t concatenate_partitions;
 uint32_t recon_buffer_mode;
 uint32_t ts_number_layers;
 uint32_t ts_target_bitrate[3];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t ts_rate_decimator[3];
 uint32_t ts_periodicity;
 uint32_t ts_layer_id[32];
 struct VssProcPictureVP8 ref_frame_buffers[4];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct VssVp8encEncodedFrame {
 uint32_t frame_size;
 uint32_t status;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t partitions;
 uint32_t partition_size[9];
 uint32_t partition_start[9];
 uint32_t segments;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t quantizer[4];
 uint32_t frame_flags;
 uint32_t partition_id;
 uint32_t buffer_level;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t quality;
 uint32_t surfaceId_of_ref_frame[4];
 uint32_t reserved[15];
 uint32_t coded_data[1];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct VssVp8encPictureParameterBuffer {
 struct VssProcPictureVP8 input_frame;
 struct VssProcPictureVP8 recon_frame;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t version;
 uint32_t pic_flags;
 uint32_t prev_frame_dropped;
 uint32_t cpuused;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t sharpness;
 uint32_t num_token_partitions;
 uint32_t encoded_frame_size;
 uint32_t encoded_frame_base;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum VssVp8encCommandType {
 VssVp8encSetSequenceParametersCommand = 123,
 VssVp8encEncodeFrameCommand,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssVp8encEndOfSequenceCommand,
 VssVp8encInit,
 Vss_Sys_Ref_Frame_COMMAND
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum VssGenCommandType {
 VssGenInitializeContext = 0xab01,
 VssGenDestroyContext = 0xab02
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#pragma pack()
#endif
