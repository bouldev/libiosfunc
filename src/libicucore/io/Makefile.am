noinst_LTLIBRARIES = libicuio.la
libicuio_la_CPPFLAGS = \
	-I$(top_srcdir)/src/include \
	-I$(top_srcdir)/src/include/xnu_headers \
	-I. -I.. -I../common -I../i18n \
	-DU_DISABLE_RENAMING=1 \
	-DU_ATTRIBUTE_DEPRECATED= \
	-DU_IO_IMPLEMENTATION \
	-DU_HAVE_STRTOD_L=1 \
	-DU_HAVE_XLOCALE_H=1 \
	-DU_HAVE_STRING_VIEW=1 \
	-pedantic -std=c++11 \
	-Qunused-arguments \
	-dynamic
libicuio_la_SOURCES = \
	locbund.cpp \
	sprintf.cpp \
	sscanf.cpp \
	ucln_io.cpp \
	ufile.cpp \
	ufmt_cmn.cpp \
	uprintf.cpp \
	uprntf_p.cpp \
	uscanf.cpp \
	uscanf_p.cpp \
	ustdio.cpp \
	ustream.cpp
