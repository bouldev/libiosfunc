// https://github.com/llvm/llvm-project/blob/main/compiler-rt/lib/builtins/clear_cache.c
#include <common.h>

#if TARGET_OS_EMBEDDED && !defined(HAVE___BUILTIN___CLEAR_CACHE)
#ifdef HAVE_LIBKERN_OSCACHECONTROL_H
#include <libkern/OSCacheControl.h>
#elif HAVE_SYS_ICACHE_INVALIDATE && !defined(HAVE_LIBKERN_OSCACHECONTROL_H)
extern void sys_icache_invalidate(void *start, size_t len);
#else
#error "Where is your sys_icache_invalidate()?"
#endif

void __clear_cache(void *start, void *end) {
  // On Darwin, sys_icache_invalidate() provides __builtin___clear_cache functionality
  // __has_builtin(__builtin___clear_cache) check passes, but Apple did not provide "___clear_cache" symbol for embedded devices which normally exists in libcompiler_rt.dylib
  sys_icache_invalidate(start, end - start);
}
#endif
