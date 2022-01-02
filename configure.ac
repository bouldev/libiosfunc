AC_INIT([libiosfunc],[0.0.1],[me@torrekie.dev],[],[https://github.com/bouldev/libiosfunc])
AC_CONFIG_SRCDIR(README)
AC_CONFIG_MACRO_DIR(m4)
AM_INIT_AUTOMAKE(subdir-objects)
LT_INIT

AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_RANLIB

AC_CONFIG_HEADERS([src/include/config.h])

AC_CONFIG_FILES([
	Makefile
	libiosfunc.pc
])

AC_TYPE_SIZE_T
AC_CHECK_TYPE([uintptr_t], [AC_DEFINE([HAVE_UINTPTR_T], [1], [Define to 1 if you have the `uintptr_t'])], [], [])

AC_CHECK_HEADERS([fcntl.h mach/mach.h stdint.h os/base_private.h os/lock_private.h xpc/xpc.h xpc/private.h])
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UID_T
if test "x$ac_cv_header_os_lock_private_h" != xyes ||
	test "x$ac_cv_header_xpc_xpc_h" != xyes ||
	test "x$ac_cv_header_xpc_private_h" != xyes ||
	test "x$ac_cv_header_os_base_private_h" != xyes; then
	CFLAGS="$CFLAGS -Isrc/include/xnu_headers"
fi

AC_CHECK_HEADER_STDBOOL
AC_CHECK_HEADER([libkern/OSCacheControl.h], [libkern_oscachecontrol_h="yes"], [libkern_oscachecontrol_h=])
AC_MSG_CHECKING([whether to use libkern/OSCacheControl.h for sys_icache_invalidate()])
if test "x$libkern_oscachecontrol_h" != xyes; then
	AC_MSG_RESULT([no (header not found)])
	AC_MSG_CHECKING([sys_icache_invalidate() exists])
	AC_CHECK_FUNCS([sys_icache_invalidate], [AC_MSG_RESULT([yes])], [
		AC_MSG_RESULT([no])
		AC_MSG_ERROR([sys_icache_invalidate() missing, please check your iOS SDK])])
else
	AC_MSG_RESULT([yes])
	AC_DEFINE([HAVE_LIBKERN_OSCACHECONTROL_H], [1], [Define to 1 if you have the <libkern/OSCacheControl.h> header file])
	AC_DEFINE([HAVE_SYS_ICACHE_INVALIDATE], [1], [Define to 1 if you have the `sys_icache_invalidate' function])
fi
AC_CHECK_HEADERS([TargetConditionals.h sys/mman.h unistd.h])
if test "x$ac_cv_header_TargetConditionals_h" != xyes; then
	AC_MSG_ERROR([<TargetConditionals.h> missing, please check your iOS SDK])
elif test "x$ac_cv_header_sys_mman_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <sys/mman.h>])
elif test "x$ac_cv_header_unistd_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <unistd.h>])
fi

AC_CHECK_FUNCS([__builtin___clear_cache sysconf])

AC_OUTPUT
