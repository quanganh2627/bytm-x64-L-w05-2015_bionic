_LIBC_ARCH_COMMON_SRC_FILES += \
    arch-x86/x86-atom/string/sse2-memchr-atom.S \
    arch-x86/x86-atom/string/sse2-memrchr-atom.S \
    arch-x86/x86-atom/string/sse2-strchr-atom.S \
    arch-x86/x86-atom/string/sse2-strrchr-atom.S \
    arch-x86/x86-atom/string/sse2-index-atom.S \
    arch-x86/x86-atom/string/sse2-strnlen-atom.S \
    arch-x86/x86-atom/string/sse2-wcschr-atom.S \
    arch-x86/x86-atom/string/sse2-wcsrchr-atom.S \
    arch-x86/x86-atom/string/sse2-wcslen-atom.S \
    arch-x86/x86-atom/string/sse2-wcscmp-atom.S \
    arch-x86/x86-slm/string/sse2-bcopy-slm.S \
    arch-x86/x86-slm/string/sse2-bzero-slm.S \
    arch-x86/x86-slm/string/sse2-memcpy-slm.S \
    arch-x86/x86-slm/string/sse2-memmove-slm.S \
    arch-x86/x86-slm/string/sse2-memset-slm.S \
    arch-x86/x86-slm/string/sse2-stpcpy-slm.S \
    arch-x86/x86-slm/string/sse2-stpncpy-slm.S \
    arch-x86/x86-slm/string/sse2-strcpy-slm.S \
    arch-x86/x86-slm/string/sse2-strlen-slm.S \
    arch-x86/x86-slm/string/sse2-strncpy-slm.S

ifeq ($(ARCH_X86_HAVE_SSSE3),true)
_LIBC_ARCH_COMMON_SRC_FILES += \
    arch-x86/x86-atom/string/ssse3-strcat-atom.S \
    arch-x86/x86-atom/string/ssse3-strcmp-atom.S \
    arch-x86/x86-atom/string/ssse3-strlcat-atom.S \
    arch-x86/x86-atom/string/ssse3-strlcpy-atom.S \
    arch-x86/x86-atom/string/ssse3-strncat-atom.S \
    arch-x86/x86-atom/string/ssse3-strncmp-atom.S \
    arch-x86/x86-atom/string/ssse3-memcmp16-atom.S \
    arch-x86/x86-atom/string/ssse3-wcscat-atom.S \
    arch-x86/x86-atom/string/ssse3-wcscpy-atom.S
else
_LIBC_ARCH_COMMON_SRC_FILES += \
    arch-x86/generic/string/strcat.S \
    arch-x86/generic/string/strcmp.S \
    arch-x86/generic/string/strncmp.S \
    string/memcmp16.c \
    string/strncat.c \
    string/strlcat.c \
    string/strlcpy.c \
    upstream-freebsd/lib/libc/string/wcscpy.c \
    upstream-freebsd/lib/libc/string/wcscat.c
endif

ifeq ($(ARCH_X86_HAVE_SSE4),true)
 _LIBC_ARCH_COMMON_SRC_FILES += \
    arch-x86/x86-slm/string/sse4-memcmp-slm.S \
    arch-x86/x86-slm/string/sse4-wmemcmp-slm.S
else
 _LIBC_ARCH_COMMON_SRC_FILES += \
    arch-x86/generic/string/memcmp.S \
    upstream-freebsd/lib/libc/string/wmemcmp.c
endif
