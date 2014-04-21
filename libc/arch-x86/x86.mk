_LIBC_ARCH_COMMON_SRC_FILES := \
    arch-x86/bionic/clone.S \
    arch-x86/bionic/_exit_with_stack_teardown.S \
    arch-x86/bionic/futex_x86.S \
    arch-x86/bionic/__get_sp.S \
    arch-x86/bionic/__get_tls.c \
    arch-x86/bionic/mprotect_int80.S \
    arch-x86/bionic/_setjmp.S \
    arch-x86/bionic/setjmp.S \
    arch-x86/bionic/__set_tls.c \
    arch-x86/bionic/sigsetjmp.S \
    arch-x86/bionic/syscall.S \
    arch-x86/bionic/vfork.S \
    arch-x86/generic/string/ffs.S \

arch_variant_mk := $(LOCAL_PATH)/arch-x86/$(TARGET_ARCH_VARIANT)/$(TARGET_ARCH_VARIANT).mk
ifeq ($(wildcard $(arch_variant_mk)),)
    arch_variant_mk := $(LOCAL_PATH)/arch-x86/generic/generic.mk
endif
include $(arch_variant_mk)
libc_common_additional_dependencies += $(arch_variant_mk)

arch_variant_mk :=

_LIBC_ARCH_STATIC_SRC_FILES := \
    bionic/dl_iterate_phdr_static.c \

_LIBC_ARCH_DYNAMIC_SRC_FILES :=
