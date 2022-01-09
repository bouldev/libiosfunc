/*
 * Copyright (c) 2006-2018 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */
#include <common.h>

#include <sys/cdefs.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <sys/msgbuf.h>
#include <sys/resource.h>
#include <sys/process_policy.h>
#include <sys/event.h>
#include <mach/message.h>

#include "libproc_internal.h"

AVOID_CONFLICT int __proc_info(int callnum, int pid, int flavor, uint64_t arg, void * buffer, int buffersize);
AVOID_CONFLICT int __proc_info_extended_id(int32_t callnum, int32_t pid, uint32_t flavor, uint32_t flags, uint64_t ext_id, uint64_t arg, user_addr_t buffer, int32_t buffersize);
__private_extern__ int proc_setthreadname(void * buffer, int buffersize);
AVOID_CONFLICT int __process_policy(int scope, int action, int policy, int policy_subtype, proc_policy_attribute_t * attrp, pid_t target_pid, uint64_t target_threadid);
AVOID_CONFLICT int proc_rlimit_control(pid_t pid, int flavor, void *arg);

#ifndef WAKEMON_GET_PARAMS
#define WAKEMON_GET_PARAMS 0x4
#define WAKEMON_SET_DEFAULTS 0x8
#endif

int
proc_clear_vmpressure(pid_t pid)
{
	if (__process_policy(PROC_POLICY_SCOPE_PROCESS, PROC_POLICY_ACTION_RESTORE, PROC_POLICY_RESOURCE_STARVATION, PROC_POLICY_RS_VIRTUALMEM, NULL, pid, (uint64_t)0) != -1) {
		return 0;
	} else {
		return errno;
	}
}

/* set the current process as one who can resume suspended processes due to low virtual memory. Need to be root */
int
proc_set_owner_vmpressure(void)
{
	int retval;

	if ((retval = __proc_info(PROC_INFO_CALL_SETCONTROL, getpid(), PROC_SELFSET_VMRSRCOWNER, (uint64_t)0, NULL, 0)) == -1) {
		return errno;
	}

	return 0;
}

/* mark yourself to delay idle sleep on disk IO */
int
proc_set_delayidlesleep(void)
{
	int retval;

	if ((retval = __proc_info(PROC_INFO_CALL_SETCONTROL, getpid(), PROC_SELFSET_DELAYIDLESLEEP, (uint64_t)1, NULL, 0)) == -1) {
		return errno;
	}

	return 0;
}

/* Reset yourself to delay idle sleep on disk IO, if already set */
int
proc_clear_delayidlesleep(void)
{
	int retval;

	if ((retval = __proc_info(PROC_INFO_CALL_SETCONTROL, getpid(), PROC_SELFSET_DELAYIDLESLEEP, (uint64_t)0, NULL, 0)) == -1) {
		return errno;
	}

	return 0;
}

/* disable the launch time backgroudn policy and restore the process to default group */
int
proc_disable_apptype(pid_t pid, int apptype)
{
	switch (apptype) {
	case PROC_POLICY_OSX_APPTYPE_TAL:
	case PROC_POLICY_OSX_APPTYPE_DASHCLIENT:
		break;
	default:
		return EINVAL;
	}

	if (__process_policy(PROC_POLICY_SCOPE_PROCESS, PROC_POLICY_ACTION_DISABLE, PROC_POLICY_APPTYPE, apptype, NULL, pid, (uint64_t)0) != -1) {
		return 0;
	} else {
		return errno;
	}
}

/* re-enable the launch time background policy if it had been disabled. */
int
proc_enable_apptype(pid_t pid, int apptype)
{
	switch (apptype) {
	case PROC_POLICY_OSX_APPTYPE_TAL:
	case PROC_POLICY_OSX_APPTYPE_DASHCLIENT:
		break;
	default:
		return EINVAL;
	}

	if (__process_policy(PROC_POLICY_SCOPE_PROCESS, PROC_POLICY_ACTION_ENABLE, PROC_POLICY_APPTYPE, apptype, NULL, pid, (uint64_t)0) != -1) {
		return 0;
	} else {
		return errno;
	}
}

#if !TARGET_OS_SIMULATOR

int
proc_suppress(__unused pid_t pid, __unused uint64_t *generation)
{
	return 0;
}

#endif /* !TARGET_OS_SIMULATOR */
