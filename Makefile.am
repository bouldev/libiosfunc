dist_doc_DATA = README AUTHORS COPYING LICENSE

SUBDIRS = src

export IPHONEOS_DEPLOYMENT_TARGET SDKROOT

ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/src/include \
              -I$(top_srcdir)/src/xnu_headers

include_HEADERS = src/include/libiosfunc.h
EXTRA_HEADERS = src/include/extra-headers/rune.h \
                src/include/extra-headers/util.h \
                src/include/extra-headers/utmp.h \
                src/include/extra-headers/utmpx.h \
                src/include/extra-headers/wordexp.h

lib_LTLIBRARIES = libiosfunc.la

libiosfunc_la_CFLAGS = @CFLAGS@ -fPIC
libiosfunc_la_LDFLAGS = -no-undefined -dynamic -release 0.0.1

libiosfunc_la_SOURCES = \
	src/include/common.h \
	src/include/config.h.in \
	src/include/xnu_headers \
	src/libSystem

libiosfunc_la_LIBADD = \
	src/libSystem/libcompiler_rt/libcompiler_rt.la \
	src/libSystem/libkeymgr/libkeymgr.la \
	src/libSystem/libkxld/libkxld.la \
	src/libSystem/libsystem_asl/libsystem_asl.la \
	src/libSystem/libsystem_c/libsystem_c.la \
	src/libSystem/libsystem_darwin/libsystem_darwin.la \
	src/libSystem/libsystem_info/libsystem_info.la \
	src/libSystem/libsystem_kernel/libsystem_kernel.la \
	src/libSystem/libsystem_platform/libsystem_platform.la \
	src/libSystem/libsystem_pthread/libsystem_pthread.la \
	src/libSystem/libsystem_secinit/libsystem_secinit.la \
	src/libSystem/libsystem_trace/libsystem_trace.la \
	src/libSystem/libunc/libunc.la

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = @PACKAGE_NAME@.pc

install-extra-headers: $(EXTRA_HEADERS)
	@$(NORMAL_INSTALL)
	@list='$(EXTRA_HEADERS)'; test -n "$(includedir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(includedir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(includedir)" || exit 1; \
	fi; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  echo "$$d$$p"; \
	done | $(am__base_list) | \
	while read files; do \
	  echo " $(INSTALL_HEADER) $$files '$(DESTDIR)$(includedir)'"; \
	  $(INSTALL_HEADER) $$files "$(DESTDIR)$(includedir)" || exit $$?; \
	done

uninstall-extra-headers:
	@$(NORMAL_UNINSTALL)
	@list='$(EXTRA_HEADERS)'; test -n "$(includedir)" || list=; \
	files=`for p in $$list; do echo $$p; done | sed -e 's|^.*/||'`; \
	dir='$(DESTDIR)$(includedir)'; $(am__uninstall_files_from_dir)
