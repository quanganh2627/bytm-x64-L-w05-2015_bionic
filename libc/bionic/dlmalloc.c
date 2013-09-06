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

#include "private/libc_logging.h"

// Send dlmalloc errors to the log.
static void __log_alloc_size(size_t size);
static void __bionic_heap_state_debug(void* m_ori, void* p_ori, int line);
static void __bionic_heap_corruption_error(const char* function);
static void __bionic_heap_usage_error(const char* function, void* address);
#define PROCEED_ON_ERROR 0
#define PRINT_SIZE(size) __log_alloc_size((size))
#define DUMP_HEAP_BEFORE_ERROR_ACTION(m, p) \
  __bionic_heap_state_debug((void*)(m), (void*)(p), __LINE__)
#define CORRUPTION_ERROR_ACTION(m) __bionic_heap_corruption_error(__FUNCTION__)
#define USAGE_ERROR_ACTION(m,p) \
  do { \
      DUMP_HEAP_BEFORE_ERROR_ACTION(m, p); \
      __bionic_heap_usage_error(__FUNCTION__, p); \
  } while(0)

// Ugly inclusion of C file so that bionic specific #defines configure dlmalloc.
#include "../upstream-dlmalloc/malloc.c"

static void __log_alloc_size(size_t size) {
  __libc_format_log(ANDROID_LOG_FATAL,"libc", "malloc size: %d", size);
}

#define STR_DUMPING_HEAP "*** *** *** *** *** *** *** HEAP INFO *** *** *** *** *** *** ***\n"
static void __bionic_heap_state_dump(mchunkptr p, char *tag) {
  __libc_format_log(ANDROID_LOG_FATAL, "libc",
                    "chunk ptr 0x%08x(%s), cinuse(%d), pinuse(%d), chunksize(%d)",
                    (unsigned int)p, tag, !!cinuse(p), !!pinuse(p), chunksize(p));
  __libc_format_log(ANDROID_LOG_FATAL, "libc",
                    "\t%x:  %08x  prev_foot\n"
                    "\t%x:  %08x  head\n"
                    "\t%x:  %08x  fd\n"
                    "\t%x:  %08x  bk",
                    (unsigned int)&(p->prev_foot),
                    (unsigned int)p->prev_foot,
                    (unsigned int)&(p->head),
                    (unsigned int)p->head,
                    (unsigned int)&(p->fd),
                    (unsigned int)p->fd,
                    (unsigned int)&(p->bk),
                    (unsigned int)p->bk);

  //Dump heap treebin info for large chunk
  if ((chunksize(p) >> SMALLBIN_SHIFT) >= NSMALLBINS) {
    tbinptr q = (tbinptr)p;
    __libc_format_log(ANDROID_LOG_FATAL, "libc",
                      "\t%x:  %08x  child[0]\n"
                      "\t%x:  %08x  child[1]\n"
                      "\t%x:  %08x  parent",
                      (unsigned int)&(q->child[0]),
                      (unsigned int)q->child[0],
                      (unsigned int)&(q->child[1]),
                      (unsigned int)q->child[1],
                      (unsigned int)&(q->parent),
                      (unsigned int)q->parent);
  }
}

static void __bionic_heap_state_debug(void* m_ori, void* p_ori, int line) {
  mstate m = (mstate)m_ori;
  mchunkptr p = (mchunkptr)p_ori;
  __libc_format_log(ANDROID_LOG_FATAL, "libc", "FATAL ERROR occurring at line: %d\n"
                    "least_addr: 0x%08x, mchunkptr: 0x%08x. Segment Infomation:",
                    line, (unsigned int)m->least_addr, (unsigned int)p);

  msegmentptr sp = &m->seg;
  __libc_format_log(ANDROID_LOG_FATAL, "libc", "\t    base    :  size");
  for (int i = 0; sp != NULL; i++) {
    __libc_format_log(ANDROID_LOG_FATAL, "libc",
                      "\t%03d %08x:  %d",
                      i, (unsigned int)sp->base, sp->size);
    sp = sp->next;
  }

  __libc_format_log(ANDROID_LOG_FATAL, "libc", STR_DUMPING_HEAP);
  if (p != NULL && segment_holding(m, (char*)p) != 0
      && segment_holding(m, ((char *)p + sizeof(mchunk) - 1)) != 0) {
    __bionic_heap_state_dump(p,"p");

    __libc_format_log(ANDROID_LOG_FATAL, "libc", STR_DUMPING_HEAP);
    if (p->fd != NULL && segment_holding(m, (char*)p->fd) != 0
        && segment_holding(m, ((char *)p->fd + sizeof(mchunk) - 1)) != 0) {
      __bionic_heap_state_dump(p->fd, "p->fd");
    }
    else {
      __libc_format_log(ANDROID_LOG_FATAL, "libc",
                        "chunk ptr p->fd is invalid with any segment");
    }

    __libc_format_log(ANDROID_LOG_FATAL, "libc", STR_DUMPING_HEAP);
    if (p->bk != NULL && segment_holding(m, (char*)(p->bk)) != 0
        && segment_holding(m, ((char *)p->bk + sizeof(mchunk) - 1)) != 0)
      __bionic_heap_state_dump(p->bk, "p->bk");
    else  {
      __libc_format_log(ANDROID_LOG_FATAL, "libc",
                        "chunk ptr p->bk is invalid with any segment");
    }

    //prev chunk adjacent
    __libc_format_log(ANDROID_LOG_FATAL, "libc", STR_DUMPING_HEAP);
    if (!pinuse(p)) {
      size_t prevsize = p->prev_foot;
      mchunkptr prev = chunk_minus_offset(p, prevsize);
      if (prev != NULL && segment_holding(m, (char*)prev) != 0
          && segment_holding(m, ((char *)prev + sizeof(mchunk) - 1)) != 0) {
        __bionic_heap_state_dump(prev, "prev");
      } else {
        __libc_format_log(ANDROID_LOG_FATAL, "libc",
                          "chunk ptr \"prev\" is invalid with any segment");
      }
    }
    else {
      __libc_format_log(ANDROID_LOG_FATAL, "libc",
                        "chunk ptr \"prev\" is inuse");
    }

    //next chunk adjacent
    __libc_format_log(ANDROID_LOG_FATAL, "libc", STR_DUMPING_HEAP);
    size_t psize = chunksize(p);
    mchunkptr next = chunk_plus_offset(p, psize);
    if ((char*)p < (char*)next && segment_holding(m, (char*)next) != 0
        && segment_holding(m, ((char *)next + sizeof(mchunk) - 1)) != 0)
      __bionic_heap_state_dump(next, "next");
    else {
      __libc_format_log(ANDROID_LOG_FATAL, "libc",
                        "chunk ptr \"next\" is invalid with any segment");
    }

    //Dump heap treebin info if large chunk
    if((psize >> SMALLBIN_SHIFT) >= NSMALLBINS) {
      tbinptr q = (tbinptr)p;
      __libc_format_log(ANDROID_LOG_FATAL, "libc", STR_DUMPING_HEAP);
      if (q->child[0] != NULL && segment_holding(m, (char*)(q->child[0])) != 0
          && segment_holding(m, ((char *)q->child[0] + sizeof(tchunk) - 1)) != 0)
        __bionic_heap_state_dump((mchunkptr)q->child[0], "p->child[0]");
      else {
        __libc_format_log(ANDROID_LOG_FATAL, "libc",
                          "chunk ptr p->child[0] is invalid with any segment");
      }

      __libc_format_log(ANDROID_LOG_FATAL, "libc", STR_DUMPING_HEAP);
      if (q->child[1] != NULL && segment_holding(m, (char*)(q->child[1])) != 0
          && segment_holding(m, ((char *)q->child[1] + sizeof(tchunk) - 1)) != 0)
        __bionic_heap_state_dump((mchunkptr)q->child[1], "p->child[1]");
      else {
        __libc_format_log(ANDROID_LOG_FATAL, "libc",
                          "chunk ptr p->child[1] is invalid with any segment");
      }

      __libc_format_log(ANDROID_LOG_FATAL, "libc", STR_DUMPING_HEAP);
      if (q->parent != NULL && segment_holding(m, (char*)(q->parent)) != 0
          && segment_holding(m, ((char *)q->parent + sizeof(tchunk) - 1)) != 0)
        __bionic_heap_state_dump((mchunkptr)q->parent, "p->parent");
      else {
        __libc_format_log(ANDROID_LOG_FATAL, "libc",
                          "chunk ptr p->parent is invalid with any segment");
      }
    }
  }
  else {
    __libc_format_log(ANDROID_LOG_FATAL, "libc", "chunk ptr \"p\" is invalid with any segment\n");
  }
}

static void __bionic_heap_corruption_error(const char* function) {
  __libc_fatal("@@@ ABORTING: heap corruption detected by %s", function);
}

static void __bionic_heap_usage_error(const char* function, void* address) {
  __libc_format_log(ANDROID_LOG_FATAL, "libc",
                    "@@@ ABORTING: invalid address or address of corrupt block %p passed to %s",
                    address, function);
  // So that we can get a memory dump around the specific address.
  *((int**) 0xdeadbaad) = (int*) address;
}
