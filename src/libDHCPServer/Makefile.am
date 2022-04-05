noinst_LTLIBRARIES = libDHCPServer.la
libDHCPServer_la_CPPFLAGS = \
	-I. \
	-I$(top_srcdir)/src/include \
	-I$(top_srcdir)/src/include/xnu_headers \
	-D__APPLE_USE_RFC_3542
libDHCPServer_la_SOURCES = DHCPServer.c NICache.c netinfo.c
