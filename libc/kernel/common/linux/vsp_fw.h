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
 VssFrc4xConversionRate,
 VssFrc1_25xConversionRate
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct VssProcPipelineParameterBuffer {
 unsigned int num_filters;
 enum VssProcFilterType filter_pipeline[VssProcPipelineMaxNumFilters];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int _pad[2];
};
struct VssProcSharpenParameterBuffer {
 int quality;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int _pad[7];
};
struct VssProcDenoiseParameterBuffer {
 enum VssDenoiseType type;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int value_thr;
 int cnt_thr;
 int coef;
 int temp_thr1;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int temp_thr2;
 int _pad[2];
};
struct VssProcColorEnhancementParameterBuffer {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int temp_detect;
 int temp_correct;
 int clip_thr;
 int mid_thr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int luma_amm;
 int chroma_amm;
 int _pad[2];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct VssProcFrcParameterBuffer {
 enum VssFrcQuality quality;
 enum VssFrcConversionRate conversion_rate;
 int _pad[6];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define VSP_ROTATION_NONE 0
#define VSP_ROTATION_90 90
#define VSP_ROTATION_180 180
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VSP_ROTATION_270 270
struct VssProcPicture {
 unsigned int surface_id;
 unsigned int irq;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int base;
 unsigned int height;
 unsigned int width;
 unsigned int rot_angle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int stride;
 unsigned int format;
 unsigned int tiled;
 int _pad[7];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct VssProcPictureParameterBuffer {
 unsigned int num_input_pictures;
 unsigned int num_output_pictures;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int _pad[6];
 struct VssProcPicture input_picture[VSS_PROC_MAX_INPUT_PICTURES];
 struct VssProcPicture output_picture[VSS_PROC_MAX_OUTPUT_PICTURES];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
union VssProcBuffer {
 struct VssProcPipelineParameterBuffer pipeline;
 struct VssProcSharpenParameterBuffer sharpen_base;
 struct VssProcDenoiseParameterBuffer denoiser_base;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct VssProcColorEnhancementParameterBuffer enhancer_base;
 struct VssProcFrcParameterBuffer frc;
 struct VssProcPictureParameterBuffer picture;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum VssProcCommandType {
 VssProcPipelineParameterCommand = 0xFFFE,
 VssProcSharpenParameterCommand = 0xFFFD,
 VssProcDenoiseParameterCommand = 0xFFFC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VssProcColorEnhancementParameterCommand = 0xFFFB,
 VssProcFrcParameterCommand = 0xFFFA,
 VssProcPictureCommand = 0xFFF9,
 VspFencePictureParamCommand = 0xEBEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VspSetContextCommand = 0xEBED
};
enum vsp_format {
 VSP_NV12,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VSP_YV12,
 VSP_UYVY,
 VSP_YUY2,
 VSP_NV11,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VSP_NV16,
 VSP_IYUV,
 VSP_TYPE_ERROR
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
