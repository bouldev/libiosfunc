dist_doc_DATA = README

EXTRA_DIST = 	generate-changelog.sh \
		TODO

ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/include \
              -I$(top_srcdir)/src/include \
              -I$(top_srcdir)/src/libSystem/libsystem_asl

include_HEADERS=src/include/libiosfunc.h

lib_LTLIBRARIES = libiosfunc.la
libiosfunc_la_CFLAGS = @CFLAGS@ -Wno-deprecated-declarations
libiosfunc_la_LDFLAGS = -no-undefined -release 0.0.1
libiosfunc_la_SOURCES = src/libSystem/libcompiler_rt/clear_cache.c \
			src/libSystem/libcompiler_rt/enable_execute_stack.c \
			src/libSystem/libsystem_asl/asl_mt_shim.c

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = @PACKAGE_NAME@.pc
