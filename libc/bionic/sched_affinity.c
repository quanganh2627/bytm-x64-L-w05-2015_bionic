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
//#define WITH_DEBUG 1
#define _GNU_SOURCE 1

#include <sched.h>
#include <pthread.h>
#include <logd.h>

#ifdef WITH_DEBUG
#define debug(...) __libc_android_log_print(ANDROID_LOG_ERROR, "libc", ##__VA_ARGS__)
#else
#define debug(...)
#endif

#define log_error(...) __libc_android_log_print(ANDROID_LOG_ERROR, "libc", ##__VA_ARGS__)

extern int __sched_setaffinity(pid_t pid, size_t setsize, const cpu_set_t* set);

// per process variables
static pthread_key_t __affinity_key = 0;
static pthread_once_t __affinity_once = PTHREAD_ONCE_INIT;

#define GET_AFFINITY(set_)          ((set_)->__bits[0])
#define SET_AFFINITY(set_, val_)    \
    do { \
        (set_)->__bits[0] = (__CPU_BITTYPE)(val_); \
    } while (0)

void make_key()
{
    pthread_key_create(&__affinity_key, NULL);
}

int __sched_get_affinity(cpu_set_t *cpu_set)
{
    CPU_ZERO(cpu_set);
    if (__affinity_key) {
        SET_AFFINITY(cpu_set, pthread_getspecific(__affinity_key));
    }
    return (int)GET_AFFINITY(cpu_set);
}

int __sched_reset_affinity()
{
    if (__affinity_key && pthread_getspecific(__affinity_key) != NULL) {
        if (pthread_setspecific(__affinity_key, NULL) != 0) {
            log_error("__sched_reset_affinity: error pthread_setspecific\n");
            return -1;
        }
    }
    return 0;
}

int sched_start_affinity(pid_t tid)
{
    cpu_set_t newSet, oldSet;
    int cpu;

    // check tid
    if (tid <= 0) {
        log_error("sched_start_affinity: error tid\n");
        return -1;
    }

    // create key if needed
    if (pthread_once(&__affinity_once, make_key) != 0) {
        log_error("sched_start_affinity: error pthread_once\n");
        return -1;
    }

    // backup current affinity
    CPU_ZERO(&oldSet);
    if (sched_getaffinity(tid, sizeof(oldSet), &oldSet) == -1) {
        log_error("sched_start_affinity: error sched_getaffinity\n");
        return -1;
    }

    // get current cpu
    cpu = sched_getcpu();
    if (cpu == -1) {
        log_error("sched_start_affinity: error cpu\n");
        return -1;
    }

    // set affinity to current cpu
    CPU_ZERO(&newSet);
    CPU_SET(cpu, &newSet);
    if (__sched_setaffinity(tid, sizeof(newSet), &newSet) == -1) {
        log_error("sched_start_affinity: error sched_setaffinity\n");
        return -1;
    }

    // backup old affinity as key value, erase if previously set
    // since there is a unique thread calling this function,
    // restore affinity in case of failure
    if (pthread_setspecific(__affinity_key, (const void *)GET_AFFINITY(&oldSet)) != 0) {
        __sched_setaffinity(tid, sizeof(oldSet), &oldSet);
        log_error("sched_start_affinity: error pthread_setspecific\n");
        return -1;
    }

    debug("sched_start_affinity: tid=%d new_affinity=%x old_affinity=%x\n",
          tid, GET_AFFINITY(&newSet)&0xFF, GET_AFFINITY(&oldSet)&0xFF);

    // no error
    return 0;
}

int sched_end_affinity(pid_t tid)
{
    cpu_set_t cpuSet;

    // get backuped affinity
    if (!__sched_get_affinity(&cpuSet)) {
        log_error("sched_end_affinity: warning __sched_get_affinity\n");
        return -1;
    }

    // restore previous affinity
    if (__sched_setaffinity(tid, sizeof(cpuSet), &cpuSet) == -1) {
        log_error("sched_end_affinity: error sched_setaffinity\n");
        return -1;
    }

    // erase old affinity as key value
    if (pthread_setspecific(__affinity_key, NULL) != 0) {
        log_error("sched_end_affinity: error pthread_setspecific\n");
        return -1;
    }

    debug("sched_end_affinity: tid=%d affinity=%x\n",
          tid, GET_AFFINITY(&cpuSet)&0xFF);

    // no error
    return 0;
}

