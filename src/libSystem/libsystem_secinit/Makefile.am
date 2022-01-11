noinst_LTLIBRARIES = libsystem_secinit.la
libsystem_secinit_la_CPPFLAGS = -I$(top_srcdir)/src/include -I$(top_srcdir)/src/include/xnu_headers
libsystem_secinit_la_CFLAGS = -fstack-protector -fno-unroll-loops -fno-inline-functions -DTRACE
libsystem_secinit_la_SOURCES = \
	libsecinit.c \
	libsecinit.h \
	misc.h
