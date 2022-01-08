#ifndef LIBIOSFUNC_BUILDTIME_COMMON_H
#define LIBIOSFUNC_BUILDTIME_COMMON_H

#include <config.h>
#include <sys/types.h>

#ifdef HAVE_TARGETCONDITIONALS_H
#include <TargetConditionals.h>
#endif

#ifndef HAVE_UINTPTR_T
typedef unsigned long uintptr_t;
#endif

#ifndef HAVE_PTRDIFF_T
typedef __darwin_ptrdiff_t ptrdiff_t;
#endif

#ifndef HAVE_U_INT64_T
typedef unsigned long long u_int64_t;
#endif

#ifndef HAVE_UINT64_T
typedef u_int64_t uint64_t;
#endif

#ifdef HAVE_SYSCONF
#include <unistd.h>
#endif

extern int os_log_shim_enabled(void *addr);
/* As we are directally using original sources instead of reimplementing missing functions,
 * redefinitions of some functions were not quite avoidable. So just give an option to
 * control the visibility of those redefined functions. */
#ifdef AVOID_SYMBOL_OVERWRITE
#define AVOID_CONFLICT __attribute__((visibility("hidden")))
#else
#define AVOID_CONFLICT
#endif

#endif
