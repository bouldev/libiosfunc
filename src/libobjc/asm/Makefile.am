noinst_LTLIBRARIES = libobjc-asm.la
libobjc_asm_la_LIBTOOLFLAGS = --tag=CC
libobjc_asm_la_CCASFLAGS = \
	$(CFLAGS) \
	-I$(top_srcdir)/src/include \
	-I$(top_srcdir)/src/include/xnu_headers \
	-I.. -I. \
	-x assembler-with-cpp \
	-fmessage-length=0 \
	-fdiagnostics-show-note-include-stack \
	-fmacro-backtrace-limit=0 \
	-Wno-trigraphs \
	-fpascal-strings
libobjc_asm_la_SOURCES = \
	objc-msg-arm64.s \
	objc-sel-table.s
