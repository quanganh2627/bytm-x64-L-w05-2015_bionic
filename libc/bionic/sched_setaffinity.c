/*
 * Copyright (C) 2010 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
//#define WITH_DEBUG  1
#define _GNU_SOURCE 1
#include <sched.h>

#ifdef WITH_DEBUG
#include <logd.h>
#define debug(...) __libc_android_log_print(ANDROID_LOG_ERROR, "libc", ##__VA_ARGS__)
#else
#define debug(...)
#endif

extern pid_t     __glthreadtid;
extern cpu_set_t __glthreadcpuset;

extern int __sched_setaffinity(pid_t pid, size_t setsize, const cpu_set_t* set);
extern int __sched_reset_affinity();

#define GET_AFFINITY(set_) ((set_)->__bits[0])

int sched_setaffinity(pid_t pid, size_t setsize, const cpu_set_t* set)
{
    int ret;

    // set affinity
    ret = __sched_setaffinity(pid, setsize, set);

    // reset backuped affinity if current thread has a limited affinity
    if (!ret && !__sched_reset_affinity()) {
        debug("sched_setaffinity: tid=%d affinity=%d\n", pid, GET_AFFINITY(set));
    }

    return ret;
}
