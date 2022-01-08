AC_INIT([libiosfunc],[0.0.1],[me@torrekie.dev],[],[https://github.com/bouldev/libiosfunc])
AC_CONFIG_SRCDIR(README)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE(subdir-objects)
dnl AM_GNU_GETTEXT(external)
dnl AM_GNU_GETTEXT_VERSION(0.21)
LT_INIT

AC_PROG_CC([clang cc])
AC_PROG_CPP
AC_PROG_CXX([clang++ c++])
AC_PROG_RANLIB

AC_CONFIG_HEADERS([src/include/config.h])

AC_CONFIG_FILES([
	Makefile
	libiosfunc.pc
])

AC_TYPE_SIZE_T
AC_CHECK_TYPE([uintptr_t], [AC_DEFINE([HAVE_UINTPTR_T], [1], [Define to 1 if you have the `uintptr_t'])], [], [])
AC_CHECK_TYPE([ptrdiff_t], [AC_DEFINE([HAVE_PTRDIFF_T], [1], [Define to 1 if you have the `ptrdiff_t'])], [], [])
AC_CHECK_TYPE([u_int64_t], [AC_DEFINE([HAVE_U_INT64_T], [1], [Define to 1 if you have the `u_int64_t'])], [], [])
AC_CHECK_TYPE([uint64_t], [AC_DEFINE([HAVE_UINT64_T], [1], [Define to 1 if you have the `uint64_t`])], [], [])
AC_CHECK_HEADERS([fcntl.h launch.h mach/mach.h stdint.h utmp.h os/base_private.h os/lock_private.h xpc/activity.h xpc/base.h xpc/connection.h xpc/debug.h xpc/endpoint.h xpc/xpc.h xpc/private.h])
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UID_T
AC_ARG_ENABLE([avoid_redef], [AS_HELP_STRING([--enable-conflicts], [Allow functions that already exists in iOS to be redefined in libiosfunc [default=no]])], [], [
	AC_DEFINE([AVOID_SYMBOL_OVERWRITE], [1], [Define to 1 if you want to allow redefinitions])])
AC_ARG_VAR([XCRUN], [Xcode CLT xcrun command])
AC_ARG_VAR([SDKROOT], [Specify a sysroot if you want, default to XCRUN result or just "/"])
dnl AC_ARG_WITH([ios-target], [AS_HELP_STRING([--with-ios-target], [Target iOS version, defalut to 12.0])], [AC_SUBST([IPHONEOS_DEPLOYMENT_TARGET], [$withval])], [AC_SUBST([IPHONEOS_DEPLOYMENT_TARGET], [12.0])])
AC_ARG_VAR([IPHONEOS_DEPLOYMENT_TARGET], [Target iOS version, defalut to 12.0])
AC_SUBST([IPHONEOS_DEPLOYMENT_TARGET], [12.0])
if test "x$ac_cv_env_IPHONEOS_DEPLOYMENT_TARGET_set" = xset; then
	AX_COMPARE_VERSION([$ac_cv_env_IPHONEOS_DEPLOYMENT_TARGET_value], [ge], [12.0], [
		AC_SUBST([IPHONEOS_DEPLOYMENT_TARGET], [$ac_cv_env_IPHONEOS_DEPLOYMENT_TARGET_value])], [
		AC_MSG_ERROR([libiosexec have not yet tested on iOS 11 or lower, cannot proceed])])
else
	AC_SUBST([IPHONEOS_DEPLOYMENT_TARGET], [12.0])
fi
AC_SUBST([SDKROOT], [/])
if test "x$ac_cv_env_XCRUN_set" = x; then
	AC_PATH_PROG([XCRUN],[xcrun],[no])
else
	AC_SUBST([ac_cv_path_XCRUN], [$XCRUN])
fi
AC_MSG_CHECKING([if $XCRUN able to find iPhoneOS.sdk])
if test "x$ac_cv_path_XCRUN" != xno && test "x$ac_cv_env_SDKROOT_set" = x; then
	AS_IF([$XCRUN --sdk iphoneos --show-sdk-path &> /dev/null], [
		SDKROOT=`$XCRUN --sdk iphoneos --show-sdk-path`
		AC_MSG_RESULT([$SDKROOT])
	], [
		AC_MSG_RESULT([no])
		AC_MSG_WARN([$XCRUN is broken])
	])
elif test "x$ac_cv_env_SDKROOT_set" != x; then
	SDKROOT="$ac_cv_env_SDKROOT_value"
	AC_MSG_RESULT([user defined: $SDKROOT])
fi
CFLAGS="$CFLAGS -isysroot $SDKROOT"

AX_CHECK_COMPILE_FLAG(["-mios-version-min=$IPHONEOS_DEPLOYMENT_TARGET"], [CFLAGS="$CFLAGS -mios-version-min=$IPHONEOS_DEPLOYMENT_TARGET"], [
	AC_MSG_ERROR([Clang with -mios-version-min=$IPHONEOS_DEPLOYMENT_TARGET support is required])
], [-Wno-incompatible-sysroot -Werror])
dnl
dnl if test "x$ac_cv_header_os_lock_private_h" != xyes ||
dnl	test "x$ac_cv_header_xpc_xpc_h" != xyes ||
dnl	test "x$ac_cv_header_xpc_private_h" != xyes ||
dnl	test "x$ac_cv_header_os_base_private_h" != xyes ||
dnl	test "x$ac_cv_header_os_lock_private_h" != xyes ||
dnl	test "x$ac_cv_header_utmp_h" != xyes ; then
dnl	CFLAGS="$CFLAGS -Isrc/include/xnu_headers"
dnl fi
CFLAGS="$CFLAGS -Isrc/include/xnu_headers"
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
AC_CHECK_HEADERS([arpa/inet.h netinet/in.h TargetConditionals.h syslog.h termios.h sys/mman.h unistd.h utmpx.h paths.h sys/param.h sys/socket.h sys/time.h])
if test "x$ac_cv_header_TargetConditionals_h" != xyes; then
	AC_MSG_ERROR([<TargetConditionals.h> missing, please check your iOS SDK])
elif test "x$ac_cv_header_sys_mman_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <sys/mman.h>])
elif test "x$ac_cv_header_unistd_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <unistd.h>])
elif test "x$ac_cv_header_utmpx_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <utmpx.h>])
elif test "x$ac_cv_header_paths_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <paths.h>])
elif test "x$ac_cv_header_sys_param_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <sys/param.h>])
elif test "x$ac_cv_header_sys_socket_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <sys/socket.h>])
elif test "x$ac_cv_header_sys_time_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <sys/time.h>])
elif test "x$ac_cv_header_arpa_inet_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <arpa/inet.h>])
elif test "x$ac_cv_header_netinet_in_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <netinet/in.h>])
elif test "x$ac_cv_header_syslog_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <syslog.h>])
elif test "x$ac_cv_header_termios_h" != xyes; then
	AC_MSG_ERROR([libiosfunc cannot compile without <termios.h>])
fi

AC_CHECK_FUNCS([__builtin___clear_cache sysconf])

AC_OUTPUT
