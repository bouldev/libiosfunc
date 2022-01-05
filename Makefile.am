dist_doc_DATA = README AUTHORS COPYING LICENSE

#SUBDIRS = src

EXTRA_DIST = 	generate-changelog.sh \
		autogen.sh \
		TODO

ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/include \
              -I$(top_srcdir)/src/include \
              -I$(top_srcdir)/src/libSystem/libsystem_asl

include_HEADERS=src/include/libiosfunc.h

lib_LTLIBRARIES = libiosfunc.la
libiosfunc_la_CFLAGS = @CFLAGS@ -Wno-deprecated-declarations
libiosfunc_la_LDFLAGS = -no-undefined -release 0.0.1 -Wl,-U,__BIG5_init \
			-Wl,-U,__DefaultRuneXLocale \
			-Wl,-U,__EUC_init \
			-Wl,-U,__GB18030_init \
			-Wl,-U,__GB2312_init \
			-Wl,-U,__GBK_init \
			-Wl,-U,__MSKanji_init \
			-Wl,-U,__UTF2_init \
			-Wl,-U,__UTF8_init \
			-Wl,-U,___environ_lock \
			-Wl,-U,___environ_unlock \
			-Wl,-U,___findenv_locked \
			-Wl,-U,___global_locale \
			-Wl,-U,___locale_key \
			-Wl,-U,___mbsnrtowcs_std \
			-Wl,-U,___open_path_locale \
			-Wl,-U,___printf_render_chr \
			-Wl,-U,___printf_render_float \
			-Wl,-U,___printf_render_int \
			-Wl,-U,___printf_render_ptr \
			-Wl,-U,___vfprintf \
			-Wl,-U,___wcsnrtombs_std \
			-Wl,-U,___xprintf_domain_init \
			-Wl,-U,___xprintf_domain_once \
			-Wl,-U,__ascii_init \
			-Wl,-U,__none_init \
			-Wl,-read_only_relocs,suppress
libiosfunc_la_SOURCES = src/include/common.h \
			src/include/config.h.in \
			src/include/xnu_headers \
			src/libSystem \
			src/libSystem/libcompiler_rt/clear_cache.c \
			src/libSystem/libcompiler_rt/enable_execute_stack.c \
			src/libSystem/libsystem_asl/asl_mt_shim.c \
			src/libSystem/libsystem_c/localeconv.c \
			src/libSystem/libsystem_c/atexit.c \
			src/libSystem/libsystem_c/runedepreciated.c \
			src/libSystem/libsystem_c/utmpx-darwin.c \
			src/libSystem/libsystem_c/utmpx.c \
			src/libSystem/libsystem_c/setenv.c \
			src/libSystem/libsystem_c/xprintf.c \
			src/libSystem/libsystem_c/wordexp.c \
			src/libSystem/libsystem_c/frune.c \
			src/libSystem/libsystem_c/login.c \
			src/libSystem/libsystem_c/logout.c \
			src/libSystem/libsystem_c/mbrune.c \
			src/libSystem/libsystem_c/setinvalidrune.c \
			src/libSystem/libsystem_c/setrunelocale.c \
			src/libSystem/libsystem_c/findfp.c

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = @PACKAGE_NAME@.pc
