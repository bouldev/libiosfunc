#ifndef LIBIOSFUNC_H
#define LIBIOSFUNC_H

#define IOSFUNC_PUBLIC __attribute__ ((visibility ("default")))
#define IOSFUNC_HIDDEN __attribute__ ((visibility ("hidden")))

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

IOSFUNC_PUBLIC void __clear_cache(void *start, void *end);
IOSFUNC_PUBLIC void __enable_execute_stack(void *addr);

#ifdef LIBIOSFUNC_INTERNAL
//IOSFUNC_HIDDEN void free_new_argv(char** argv);
// PATH_MAX for Darwin
#endif // LIBIOSFUNC_INTERNAL

#if defined(__APPLE__)
#  include <TargetConditionals.h>
#  if TARGET_OS_EMBEDDED
#    ifndef LIBIOSFUNC_INTERNAL
#    endif // LIBIOSFUNC_INTERNAL
#  endif // TARGET_OS_EMBEDDED
#endif // __APPLE__
  
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LIBIOSFUNC_H
