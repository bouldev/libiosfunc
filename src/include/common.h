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

#ifdef HAVE_SYSCONF
#include <unistd.h>
#endif
