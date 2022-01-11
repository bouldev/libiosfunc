#ifndef LIBIOSFUNC_BUILDTIME_COMMON_H
#define LIBIOSFUNC_BUILDTIME_COMMON_H

#include <config.h>

#include <stdio.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <xpc/private.h>
#include <libc_private.h>

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

#define __APPLE_PR3417676_HACK__ 1
#define PRIVATE 1
#define OS_CRASH_ENABLE_EXPERIMENTAL_LIBTRACE 1
#define __LIBC__ 1
#define MACHTIME 1
#define XPRINTF_PERF 1
#define UNIFDEF_LEGACY_UTMP_APIS 1
#define DS_AVAILABLE 1

/* Move this to xpc/private.h
typedef struct os_log_pack_s {
    uint64_t        olp_continuous_time;
    struct timespec olp_wall_time;
    const void     *olp_mh;
    const void     *olp_pc;
    const char     *olp_format;
    uint8_t         olp_data[0];
} os_log_pack_s, *os_log_pack_t;
typedef struct _xpc_pipe_s* xpc_pipe_t;
*/

#define os_log_pack_size(fmt, ...) _os_log_pack_size(sizeof(fmt))
#define os_log_pack_fill(pack, size, errno, fmt, ...) _os_log_pack_fill(pack, size, errno, NULL, fmt)

extern int _xpc_pipe_s;
extern void xpc_pipe_invalidate(xpc_pipe_t pipe);
extern xpc_pipe_t xpc_pipe_create(const char *name, uint64_t flags);
extern int xpc_pipe_routine(xpc_pipe_t pipe, xpc_object_t request, xpc_object_t* reply);
extern void xpc_dictionary_get_audit_token(xpc_object_t xdict, audit_token_t *token);
extern size_t _os_log_pack_size(size_t os_log_format_buffer_size);
extern uint8_t *_os_log_pack_fill(os_log_pack_t pack, size_t size, int saved_errno, const void *dso, const char *fmt);
extern int os_log_shim_enabled(void *addr);
#define _FLOCKFILE(x) _flockfile(x)
#define FLOCKFILE(fp) _FLOCKFILE(fp)
#define FUNLOCKFILE(fp) _funlockfile(fp)
#define _flockfile flockfile
#define _funlockfile funlockfile
#define _getprogname getprogname
#define _write write
#define _read read
#define _sigprocmask sigprocmask
#define _close close
#define _waitpid waitpid
#define _open open
#define _fstat fstat
#define _pthread_mutex_lock pthread_mutex_lock
#define _pthread_mutex_unlock pthread_mutex_unlock
#define __isthreaded 1
#define __va_list __darwin_va_list
#define __weak_reference(sym,alias)
#define __warn_references(sym,msg)
#define __LIBC_PTHREAD_KEY(x)           (10 + (x))
#define __LIBC_PTHREAD_KEY_XLOCALE      __LIBC_PTHREAD_KEY(0)
#define LIBC_ABORT(f,...)       abort_report_np("%s:%s:%u: " f, __FILE__, __func__, __LINE__, ## __VA_ARGS__)
/* As we are directally using original sources instead of reimplementing missing functions,
 * redefinitions of some functions were not quite avoidable. So just give an option to
 * control the visibility of those redefined functions. */
#ifdef AVOID_SYMBOL_OVERWRITE
#define AVOID_CONFLICT __attribute__((visibility("hidden")))
#else
#define AVOID_CONFLICT
#endif

#endif
