#define _XOPEN_SOURCE 600L
#define _DARWIN_C_SOURCE
#include <ucontext.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/param.h>
#define CONFORMANCE_SPECIFIC_HACK 1
#include <ptrauth.h>
#include <os/tsd.h>
#include "compat.h"
#include <platform/string.h>
#include <mach/arm/thread_status.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

void
_ctx_done(ucontext_t *uctx)
{
        if (uctx->uc_link == NULL) {
                _exit(0);
        } else {
                uctx->uc_mcsize = 0; /* To make sure that this is not called again without reinitializing */
                setcontext((ucontext_t *) uctx->uc_link);
                __builtin_trap();       /* should never get here */
        }
}
#pragma clang diagnostic pop
