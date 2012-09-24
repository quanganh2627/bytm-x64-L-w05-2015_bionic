/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "dlmalloc.h"

/* Bionic error handling declarations */
#define PROCEED_ON_ERROR 0
static void __log_alloc_size(size_t size);
static void __bionic_heap_state_debug(void* m_ori, void* p_ori, int line);
static void __bionic_heap_error(const char* msg, const char* function, void* p);

#define PRINT_SIZE(size) __log_alloc_size((size))
#define DUMP_HEAP_BEFORE_ERROR_ACTION(m, p)  \
    __bionic_heap_state_debug((void*)(m), (void*)(p), __LINE__)
#define CORRUPTION_ERROR_ACTION(m) \
    __bionic_heap_error("HEAP MEMORY CORRUPTION", __FUNCTION__, NULL)
#define USAGE_ERROR_ACTION(m,p) \
    do {    \
    DUMP_HEAP_BEFORE_ERROR_ACTION(m,p);  \
    __bionic_heap_error("ARGUMENT IS INVALID HEAP ADDRESS", __FUNCTION__, p); \
    } while(0)

/*
 * Ugly inclusion of C file so that bionic specific #defines configure
 * dlmalloc.
 */
#include "../upstream-dlmalloc/malloc.c"

#include <private/logd.h>

/* Bionic error handling definitions */
/* Convert a pointer into hex string */
static char* __uint_to_char(unsigned int val, char* buff, int len, int base)
{
    const char *base_char = "0123456789ABCDEF";
    char* ptr = buff + len - 1;
    *ptr = '\0';

    if(base < 2 || base > 16)
        return ptr;

    if (val != 0)
    {
        while(ptr != buff && val != 0)
        {
            *--ptr = base_char[val % base];
            val /= base;
        }
    }
    else if (ptr != buff)
        *--ptr = '0';

    return ptr;
}

static void __log_alloc_size(size_t size)
{
    char buffer[128];
    const int len = 36;
    const int base = 10;
    char s[len];
    strlcpy(buffer, "malloc size: ", sizeof(buffer));
    strlcat(buffer, __uint_to_char(size, s, len, base), sizeof(buffer));
    __libc_android_log_write(ANDROID_LOG_FATAL, "libc", buffer);
}

#define STR_DUMPING_HEAP "*** *** *** *** *** *** *** HEAP INFO *** *** *** *** *** *** ***\n"
static void __bionic_heap_state_dump(mchunkptr p, char *tag)
{
    char buffer[1024];
    const int addr_len = 36;
    const int addr_base = 16;
    const int decimal_base = 10;
    char addr[addr_len];

    strlcpy(buffer, STR_DUMPING_HEAP, sizeof(buffer));
    strlcat(buffer, "chunk ptr 0x", sizeof(buffer));
    strlcat(buffer, __uint_to_char((unsigned int)p, addr, addr_len, addr_base), sizeof(buffer));
    strlcat(buffer, "(", sizeof(buffer));
    strlcat(buffer, tag, sizeof(buffer));
    strlcat(buffer, "), cinuse(", sizeof(buffer));
    strlcat(buffer, cinuse(p) ? "1" : "0", sizeof(buffer));
    strlcat(buffer, "), pinuse(", sizeof(buffer));
    strlcat(buffer, pinuse(p) ? "1" : "0", sizeof(buffer));
    strlcat(buffer, "), chunksize(", sizeof(buffer));
    strlcat(buffer, __uint_to_char(chunksize(p), addr, addr_len, decimal_base), sizeof(buffer));
    strlcat(buffer, ") \n>>>> Heap: 0x", sizeof(buffer));
    strlcat(buffer, __uint_to_char((unsigned int)p->prev_foot, addr, addr_len, addr_base), sizeof(buffer));
    strlcat(buffer, "(prev_foot) \n>>>> Heap: 0x", sizeof(buffer));
    strlcat(buffer, __uint_to_char((unsigned int)p->head, addr, addr_len, addr_base), sizeof(buffer));
    strlcat(buffer, "(head) \n>>>> Heap: 0x", sizeof(buffer));
    strlcat(buffer, __uint_to_char((unsigned int)p->fd, addr, addr_len, addr_base), sizeof(buffer));
    strlcat(buffer, "(fd) \n>>>> Heap: 0x", sizeof(buffer));
    strlcat(buffer, __uint_to_char((unsigned int)p->bk, addr, addr_len, addr_base), sizeof(buffer));
    strlcat(buffer, "(bk)", sizeof(buffer));

    //Dump heap treebin info if large chunk
    if ((chunksize(p) >> SMALLBIN_SHIFT) >= NSMALLBINS)
    {
        tbinptr q = (tbinptr)p;
        strlcat(buffer, "\n>>>> Heap: 0x", sizeof(buffer));
        strlcat(buffer, __uint_to_char((unsigned int)q->child[0], addr, addr_len, addr_base), sizeof(buffer));
        strlcat(buffer, "(child[0])", sizeof(buffer));
        strlcat(buffer, "\n>>>> Heap: 0x", sizeof(buffer));
        strlcat(buffer, __uint_to_char((unsigned int)q->child[1], addr, addr_len, addr_base), sizeof(buffer));
        strlcat(buffer, "(child[1])", sizeof(buffer));
        strlcat(buffer, "\n>>>> Heap: 0x", sizeof(buffer));
        strlcat(buffer, __uint_to_char((unsigned int)q->parent, addr, addr_len, addr_base), sizeof(buffer));
        strlcat(buffer, "(parent)", sizeof(buffer));
    }

    __libc_android_log_write(ANDROID_LOG_FATAL,"libc",buffer);
}

static void __bionic_heap_state_debug(void* m_ori, void* p_ori, int line)
{
    mstate m = (mstate)m_ori;
    mchunkptr p = (mchunkptr)p_ori;
    char buffer[512];
    const int addr_len = 36;
    const int addr_base = 16;
    const int decimal_base = 10;
    char addr[addr_len];
    strlcpy(buffer, "FATAL ERROR occurring at line: ", sizeof(buffer));
    strlcat(buffer, __uint_to_char(line, addr, addr_len, decimal_base), sizeof(buffer));
    strlcat(buffer, "\nleast_addr: 0x", sizeof(buffer));
    strlcat(buffer, __uint_to_char((unsigned int)m->least_addr, addr, addr_len, addr_base), sizeof(buffer));
    strlcat(buffer, ", mchunkptr: 0x", sizeof(buffer));
    strlcat(buffer, __uint_to_char((unsigned int)p, addr, addr_len, addr_base), sizeof(buffer));

    strlcat(buffer, "\nSegment Infomation(base, size): ", sizeof(buffer));
    msegmentptr sp = &m->seg;
    for (;;) {
        strlcat(buffer, "(0x", sizeof(buffer));
        strlcat(buffer, __uint_to_char((unsigned int)sp->base, addr, addr_len, addr_base), sizeof(buffer));
        strlcat(buffer, ",", sizeof(buffer));
        strlcat(buffer, __uint_to_char(sp->size, addr, addr_len, decimal_base), sizeof(buffer));
        strlcat(buffer, ")", sizeof(buffer));
        if ((sp = sp->next) == 0)
          break;
    }

    __libc_android_log_write(ANDROID_LOG_FATAL,"libc",buffer);

    if (p != NULL && segment_holding(m, (char*)p) != 0
        && segment_holding(m, ((char *)p + sizeof(mchunk) - 1)) != 0)
    {
        __bionic_heap_state_dump(p,"p");

        if (p->fd != NULL && segment_holding(m, (char*)p->fd) != 0
            && segment_holding(m, ((char *)p->fd + sizeof(mchunk) - 1)) != 0)
            __bionic_heap_state_dump(p->fd, "p->fd");
        else
        {
            __libc_android_log_write(ANDROID_LOG_FATAL,"libc",
            STR_DUMPING_HEAP
            "chunk ptr p->fd is invalid with any segment");
        }

        if (p->bk != NULL && segment_holding(m, (char*)(p->bk)) != 0
            && segment_holding(m, ((char *)p->bk + sizeof(mchunk) - 1)) != 0)
            __bionic_heap_state_dump(p->bk, "p->bk");
        else
        {
            __libc_android_log_write(ANDROID_LOG_FATAL,"libc",
            STR_DUMPING_HEAP
            "chunk ptr p->bk is invalid with any segment");
        }

        //prev chunk adjacent
        if (!pinuse(p))
        {
            size_t prevsize = p->prev_foot;
            mchunkptr prev = chunk_minus_offset(p, prevsize);
            if (prev != NULL && segment_holding(m, (char*)prev) != 0
                && segment_holding(m, ((char *)prev + sizeof(mchunk) - 1)) != 0)
                __bionic_heap_state_dump(prev, "prev");
            else
            {
                __libc_android_log_write(ANDROID_LOG_FATAL,"libc",
                STR_DUMPING_HEAP
                "chunk ptr \"prev\" is invalid with any segment");
            }
        }
        else
            __libc_android_log_write(ANDROID_LOG_FATAL,"libc",
            STR_DUMPING_HEAP
            "chunk ptr \"prev\" is inuse");

        //next chunk adjacent
        size_t psize = chunksize(p);
        mchunkptr next = chunk_plus_offset(p, psize);
        if ((char*)p < (char*)next && segment_holding(m, (char*)next) != 0
            && segment_holding(m, ((char *)next + sizeof(mchunk) - 1)) != 0)
            __bionic_heap_state_dump(next, "next");
        else
        {
            __libc_android_log_write(ANDROID_LOG_FATAL,"libc",
            STR_DUMPING_HEAP
            "chunk ptr \"next\" is invalid with any segment");
        }

        //Dump heap treebin info if large chunk
        if((psize >> SMALLBIN_SHIFT) >= NSMALLBINS)
        {
            tbinptr q = (tbinptr)p;
            if (q->child[0] != NULL && segment_holding(m, (char*)(q->child[0])) != 0
                && segment_holding(m, ((char *)q->child[0] + sizeof(tchunk) - 1)) != 0)
                __bionic_heap_state_dump((mchunkptr)q->child[0], "p->child[0]");
            else
            {
                __libc_android_log_write(ANDROID_LOG_FATAL,"libc",
                STR_DUMPING_HEAP
                "chunk ptr p->child[0] is invalid with any segment");
            }

            if (q->child[1] != NULL && segment_holding(m, (char*)(q->child[1])) != 0
                && segment_holding(m, ((char *)q->child[1] + sizeof(tchunk) - 1)) != 0)
                __bionic_heap_state_dump((mchunkptr)q->child[1], "p->child[1]");
            else
            {
                __libc_android_log_write(ANDROID_LOG_FATAL,"libc",
                STR_DUMPING_HEAP
                "chunk ptr p->child[1] is invalid with any segment");
            }

            if (q->parent != NULL && segment_holding(m, (char*)(q->parent)) != 0
                && segment_holding(m, ((char *)q->parent + sizeof(tchunk) - 1)) != 0)
                __bionic_heap_state_dump((mchunkptr)q->parent, "p->parent");
            else
            {
                __libc_android_log_write(ANDROID_LOG_FATAL,"libc",
                STR_DUMPING_HEAP
                "chunk ptr p->parent is invalid with any segment");
            }
        }
    }
    else
    {
        __libc_android_log_write(ANDROID_LOG_FATAL,"libc",
        STR_DUMPING_HEAP
        "chunk ptr \"p\" is invalid with any segment\n");
    }
}

static void __bionic_heap_error(const char* msg, const char* function, void* p)
{
    /* We format the buffer explicitely, i.e. without using snprintf()
     * which may use malloc() internally. Not something we can trust
     * if we just detected a corrupted heap.
     */
    char buffer[256];
    strlcpy(buffer, "@@@ ABORTING: LIBC: ", sizeof(buffer));
    strlcat(buffer, msg, sizeof(buffer));
    if (function != NULL) {
        strlcat(buffer, " IN ", sizeof(buffer));
        strlcat(buffer, function, sizeof(buffer));
    }

    if (p != NULL) {
        const int hex_len = 36;
        const int hex_base = 16;
        char hexbuffer[hex_len];
        strlcat(buffer, " addr=0x", sizeof(buffer));
        strlcat(buffer, __uint_to_char((unsigned int)p, hexbuffer, hex_len, hex_base), sizeof(buffer));
    }

    __libc_android_log_write(ANDROID_LOG_FATAL, "libc", buffer);

    /* So that we can get a memory dump around p */
    *((int **) 0xdeadbaad) = (int *) p;
}
