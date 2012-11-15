/*
 * Copyright (C) 2012 The Android Open Source Project
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
#include <unwind.h>
#include <sys/types.h>
#include <pthread.h>
// =============================================================================
// stack trace functions
// =============================================================================

/*workaround if _Unwind_Backtrace can not work well */
#ifdef __i386__
#define UNWIND_WORKAROUND
#endif

struct stack_crawl_state_t {
    size_t count;
    intptr_t* addrs;
};


/* depends how the system includes define this */
#ifdef HAVE_UNWIND_CONTEXT_STRUCT
typedef struct _Unwind_Context __unwind_context;
#else
typedef _Unwind_Context __unwind_context;
#endif

static _Unwind_Reason_Code trace_function(__unwind_context* context, void* arg) {
    stack_crawl_state_t* state = static_cast<stack_crawl_state_t*>(arg);
    if (state->count) {
        intptr_t ip = (intptr_t)_Unwind_GetIP(context);
        if (ip) {
            state->addrs[0] = ip;
            state->addrs++;
            state->count--;
            return _URC_NO_REASON;
        }
    }
    /*
     * If we run out of space to record the address or 0 has been seen, stop
     * unwinding the stack.
     */
    return _URC_END_OF_STACK;
}

__LIBC_HIDDEN__ int get_backtrace(intptr_t* addrs, size_t max_entries) {
    stack_crawl_state_t state;
    state.count = max_entries;
    state.addrs = addrs;

#ifdef UNWIND_WORKAROUND
    int i, s;
    pthread_attr_t thread_attr;
    unsigned sb, st;
    size_t stacksize;
    pthread_t thread = pthread_self();
    unsigned *_ebp, *base_ebp;
    unsigned *caller;

    pthread_attr_init(&thread_attr);
    s = pthread_getattr_np(thread, &thread_attr);
    if (s) goto out;
    s = pthread_attr_getstack(&thread_attr, (void **)(&sb), &stacksize);
    if (s) goto out;
    st = sb + stacksize;

    asm ("movl %%ebp, %0"
            : "=r" (_ebp)
    );

    if (_ebp >= (unsigned *)(st - 4) || _ebp < (unsigned *)sb)
            goto out;
    base_ebp = _ebp;
    caller = (unsigned *) *(_ebp + 1);

    for (i = 0; i < max_entries; i++) {
        addrs[i] = (intptr_t) caller;
        state.count--;
        _ebp = (unsigned *) *_ebp;
        if (_ebp >= (unsigned *)(st - 4) || _ebp < base_ebp) break;
        caller = (unsigned *) *(_ebp + 1);
    }

out:
    pthread_attr_destroy(&thread_attr);
#else
    _Unwind_Backtrace(trace_function, &state);
#endif // UNWIND_WORKAROUND

    return max_entries - state.count;
}
