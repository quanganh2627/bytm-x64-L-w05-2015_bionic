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
#define VssProcPipelineMaxNumFilters 5
#define VSS_PROC_MAX_INPUT_PICTURES 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSS_PROC_MAX_OUTPUT_PICTURES 4
enum VssProcFilterType {
 VssProcFilterDenoise,
 VssProcFilterSharpening,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssProcFilterColorEnhancement,
 VssProcFilterFrameRateConversion
};
enum VssDenoiseType {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssProcDegrain,
 VssProcDeblock
};
enum VssFrcQuality {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssFrcMediumQuality,
 VssFrcHighQuality
};
enum VssFrcConversionRate {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssFrc2xConversionRate,
 VssFrc2_5xConversionRate,
 VssFrc4xConversionRate
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct VssProcPipelineParameterBuffer {
 unsigned int num_filters;
 enum VssProcFilterType filter_pipeline[VssProcPipelineMaxNumFilters];
 int _pad[2];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct VssProcSharpenParameterBuffer {
 int quality;
 unsigned int _pad[7];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct VssProcDenoiseParameterBuffer {
 enum VssDenoiseType type;
 int value_thr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int cnt_thr;
 int coef;
 int temp_thr1;
 int temp_thr2;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int _pad[2];
};
struct VssProcColorEnhancementParameterBuffer {
 int temp_detect;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int temp_correct;
 int clip_thr;
 int mid_thr;
 int luma_amm;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int chroma_amm;
 int _pad[2];
};
struct VssProcFrcParameterBuffer {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 enum VssFrcQuality quality;
 enum VssFrcConversionRate conversion_rate;
 int _pad[6];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSP_ROTATION_NONE 0
#define VSP_ROTATION_90 90
#define VSP_ROTATION_180 180
#define VSP_ROTATION_270 270
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct VssProcPicture {
 unsigned int surface_id;
 unsigned int irq;
 unsigned int base;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int height;
 unsigned int width;
 unsigned int rot_angle;
 unsigned int stride;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int format;
};
struct VssProcPictureParameterBuffer {
 unsigned int num_input_pictures;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int num_output_pictures;
 int _pad[6];
 struct VssProcPicture input_picture[VSS_PROC_MAX_INPUT_PICTURES];
 struct VssProcPicture output_picture[VSS_PROC_MAX_OUTPUT_PICTURES];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
union VssProcBuffer {
 struct VssProcPipelineParameterBuffer pipeline;
 struct VssProcSharpenParameterBuffer sharpen_base;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct VssProcDenoiseParameterBuffer denoiser_base;
 struct VssProcColorEnhancementParameterBuffer enhancer_base;
 struct VssProcFrcParameterBuffer frc;
 struct VssProcPictureParameterBuffer picture;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum VssProcCommandType {
 VssProcPipelineParameterCommand = 0xFFFE,
 VssProcSharpenParameterCommand = 0xFFFD,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssProcDenoiseParameterCommand = 0xFFFC,
 VssProcColorEnhancementParameterCommand = 0xFFFB,
 VssProcFrcParameterCommand = 0xFFFA,
 VssProcPictureCommand = 0xFFF9,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VspFencePictureParamCommand = 0xEBEC,
 VspSetContextCommand = 0xEBED
};
#define VSP_CMD_QUEUE_SIZE (64)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSP_ACK_QUEUE_SIZE (64)
struct vss_command_t {
 unsigned int context;
 unsigned int type;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int buffer;
 unsigned int size;
 unsigned int buffer_id;
 unsigned int irq;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int reserved6;
 unsigned int reserved7;
};
struct vss_response_t {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int context;
 unsigned int type;
 unsigned int buffer;
 unsigned int size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int vss_cc;
 unsigned int reserved5;
 unsigned int reserved6;
 unsigned int reserved7;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define VSP_COMMAND_INITIALIZER {0, 0, 0, 0, 0, 0, 0, 0}
#define VSP_RESPONSE_INITIALIZER {0, 0, 0, 0, 0, 0, 0, 0}
enum VssResponseType {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssCommandBufferReadyResponse,
 VssInputSurfaceReadyResponse,
 VssOutputSurfaceReadyResponse,
 VssOutputSurfaceFreeResponse,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssOutputSurfaceCrcResponse,
 VssEndOfSequenceResponse,
 VssErrorResponse,
 VssIdleResponse
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum VssStatus {
 VssOK,
 VssInvalidCommandType,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssInvalidCommandArgument,
 VssInvalidProcPictureCommand
};
enum vsp_format {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VSP_NV12,
 VSP_YV12,
 VSP_UYVY,
 VSP_YUY2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VSP_NV11,
 VSP_NV16,
 VSP_IYUV,
 VSP_TYPE_ERROR
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct vsp_data {
 unsigned int fw_state;
 unsigned int uninit_req;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define VSP_FIRMWARE_MAGIC_NUMBER 0x45BF1838
#define VSP_MAX_PROGRAMS 32
#define VSP_STRING_TABLE_SIZE 256
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum vsp_processor {
 vsp_sp0 = 0,
 vsp_sp1 = 1,
 vsp_vp0 = 2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 vsp_vp1 = 3,
 vsp_mea = 4
};
struct vsp_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int magic_number;
 unsigned int num_programs;
 unsigned int program_offset[VSP_MAX_PROGRAMS];
 unsigned int program_name_offset[VSP_MAX_PROGRAMS];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 char string_table[VSP_STRING_TABLE_SIZE];
 unsigned int boot_processor;
 unsigned int api_processor;
 unsigned int text_src;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int init_addr;
 unsigned int main_addr;
};
struct vsp_ctrl_reg {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int firmware_addr;
 unsigned int setting_addr;
 unsigned int reserved4;
 union {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int entry_kind;
 unsigned int uninit_req;
 };
 unsigned int context_init_req;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int context_init_ack;
 unsigned int context_uninit_req;
 unsigned int context_uninit_ack;
 unsigned int context_buf_addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int context_buf_sz;
 unsigned int cmd_rd;
 unsigned int cmd_wr;
 unsigned int ack_rd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int ack_wr;
};
struct vsp_settings_t {
 unsigned int firmware_addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int command_queue_size;
 unsigned int command_queue_addr;
 unsigned int response_queue_size;
 unsigned int response_queue_addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int state_buffer_size;
 unsigned int state_buffer_addr;
 unsigned int reserved7;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSP_SETTINGS_INITIALIZER {0, 0, 0, 0, 0, 0, 0, 0}
enum vsp_entry_kind {
 vsp_entry_init = 0,
 vsp_entry_continue = 1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 vsp_entry_resume = 2,
 vsp_exit = 3
};
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
