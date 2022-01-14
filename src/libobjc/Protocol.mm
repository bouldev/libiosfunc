/*
 * Copyright (c) 1999-2001, 2005-2007 Apple Inc.  All Rights Reserved.
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
/*
	Protocol.h
	Copyright 1991-1996 NeXT Software, Inc.
*/

#include "objc-private.h"

#undef id
#undef Class

#include <stdlib.h>
#include <string.h>
#include <mach-o/dyld.h>
#include <mach-o/ldsyms.h>

#include "Protocol.h"
#include "NSObject.h"

// __IncompleteProtocol is used as the return type of objc_allocateProtocol().

// Old ABI uses NSObject as the superclass even though Protocol uses Object
// because the R/R implementation for class Protocol is added at runtime
// by CF, so __IncompleteProtocol would be left without an R/R implementation 
// otherwise, which would break ARC.

@interface __IncompleteProtocol : NSObject
@end

#if __OBJC2__
__attribute__((objc_nonlazy_class))
#endif
@implementation __IncompleteProtocol
@end
