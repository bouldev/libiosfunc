dist_doc_DATA = README AUTHORS COPYING LICENSE

#SUBDIRS = src

export IPHONEOS_DEPLOYMENT_TARGET SDKROOT

EXTRA_DIST = 	generate-changelog.sh \
		autogen.sh \
		TODO

ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/include \
	      -I$(top_srcdir)/src/include \
              -I$(top_srcdir)/src/libSystem/libsystem_asl

include_HEADERS = src/include/libiosfunc.h
EXTRA_HEADERS = src/include/extra-headers/rune.h \
		src/include/extra-headers/util.h \
		src/include/extra-headers/utmp.h \
		src/include/extra-headers/utmpx.h \
		src/include/extra-headers/wordexp.h

lib_LTLIBRARIES = libiosfunc.la
libiosfunc_la_CFLAGS = @CFLAGS@
libiosfunc_la_LDFLAGS = -no-undefined -release 0.0.1
libiosfunc_la_SOURCES = src/include/common.h \
			src/include/config.h.in \
			src/include/xnu_headers \
			src/libSystem \
			src/libSystem/libcompiler_rt/clear_cache.c \
			src/libSystem/libcompiler_rt/enable_execute_stack.c \
			src/libSystem/libsystem_asl/asl.c \
			src/libSystem/libsystem_asl/asl_fd.c \
			src/libSystem/libsystem_asl/asl_msg.c \
			src/libSystem/libsystem_asl/asl_mt_shim.c \
			src/libSystem/libsystem_asl/asl_util.c \
			src/libSystem/libsystem_asl/syslog.c \
			src/libSystem/libsystem_c/ascii.c \
			src/libSystem/libsystem_c/atexit.c \
			src/libSystem/libsystem_c/big5.c \
			src/libSystem/libsystem_c/collate.c \
			src/libSystem/libsystem_c/euc.c \
			src/libSystem/libsystem_c/findfp.c \
			src/libSystem/libsystem_c/fix_grouping.c \
			src/libSystem/libsystem_c/frune.c \
			src/libSystem/libsystem_c/fvwrite.c \
			src/libSystem/libsystem_c/gb18030.c \
			src/libSystem/libsystem_c/gb2312.c \
			src/libSystem/libsystem_c/gbk.c \
			src/libSystem/libsystem_c/getenv.c \
			src/libSystem/libsystem_c/ldpart.c \
			src/libSystem/libsystem_c/lmessages.c \
			src/libSystem/libsystem_c/lmonetary.c \
			src/libSystem/libsystem_c/lnumeric.c \
			src/libSystem/libsystem_c/localeconv.c \
			src/libSystem/libsystem_c/login.c \
			src/libSystem/libsystem_c/logout.c \
			src/libSystem/libsystem_c/mbrune.c \
			src/libSystem/libsystem_c/mbsnrtowcs.c \
			src/libSystem/libsystem_c/mskanji.c \
			src/libSystem/libsystem_c/none.c \
			src/libSystem/libsystem_c/printf-pos.c \
			src/libSystem/libsystem_c/runedepreciated.c \
			src/libSystem/libsystem_c/setenv.c \
			src/libSystem/libsystem_c/setinvalidrune.c \
			src/libSystem/libsystem_c/setlocale.c \
			src/libSystem/libsystem_c/setrunelocale.c \
			src/libSystem/libsystem_c/table.c \
			src/libSystem/libsystem_c/timelocal.c \
			src/libSystem/libsystem_c/utf2.c \
			src/libSystem/libsystem_c/utf8.c \
			src/libSystem/libsystem_c/utmpx-darwin.c \
			src/libSystem/libsystem_c/utmpx.c \
			src/libSystem/libsystem_c/vfprintf.c \
			src/libSystem/libsystem_c/wcsnrtombs.c \
			src/libSystem/libsystem_c/wordexp.c \
			src/libSystem/libsystem_c/xlocale.c \
			src/libSystem/libsystem_c/xprintf.c \
			src/libSystem/libsystem_c/xprintf_domain.c \
			src/libSystem/libsystem_c/xprintf_errno.c \
			src/libSystem/libsystem_c/xprintf_float.c \
			src/libSystem/libsystem_c/xprintf_hexdump.c \
			src/libSystem/libsystem_c/xprintf_int.c \
			src/libSystem/libsystem_c/xprintf_quote.c \
			src/libSystem/libsystem_c/xprintf_str.c \
			src/libSystem/libsystem_c/xprintf_time.c \
			src/libSystem/libsystem_c/xprintf_vis.c \
			src/libSystem/libsystem_darwin/variant.c \
			src/libSystem/libsystem_info/stub.c \
			src/libSystem/libsystem_kernel/libproc.c \
			src/libSystem/libsystem_kernel/os_xbs_chrooted.c \
			src/libSystem/libsystem_kernel/quota_obsolete.c \
			src/libSystem/libsystem_kernel/stat.c \
			src/libSystem/libsystem_kernel/system-version-compat-support.c \
			src/libSystem/libsystem_platform/OSAtomic.c \
			src/libSystem/libsystem_platform/_ctx_done.c \
			src/libSystem/libsystem_platform/init.c \
			src/libSystem/libsystem_pthread/_pthread_mutex_enable_legacy_mode.c \
			src/libSystem/libsystem_trace/_os_trace_basesystem_storage_available.c
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
