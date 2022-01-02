#include <config.h>

#ifdef HAVE_TARGETCONDITIONALS_H
#include <TargetConditionals.h>
#endif

#ifndef HAVE_UINTPTR_T
typedef unsigned long uintptr_t;
#else
#include <sys/types.h>
#endif

#ifdef HAVE_SYSCONF
#include <unistd.h>
#endif
