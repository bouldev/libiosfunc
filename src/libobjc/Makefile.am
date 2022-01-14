noinst_LTLIBRARIES = libobjc.la
SUBDIRS = asm
libobjc_la_LIBTOOLFLAGS = --tag=CXX
libobjc_la_CPPFLAGS = \
	-I. \
	-I$(top_srcdir)/src/include \
	-I$(top_srcdir)/src/include/xnu_headers \
	-D__APPLE_BLEACH_SDK__ \
	-DOBJC_OLD_DISPATCH_PROTOTYPES=1
libobjc_la_OBJCXXFLAGS = \
	$(CFLAGS) \
	-x objective-c++ \
	-fmessage-length=0 \
	-fdiagnostics-show-note-include-stack \
	-fmacro-backtrace-limit=0 \
	-fno-exceptions \
	-fno-rtti \
	-fno-sanitize=vptr \
	-fpascal-strings \
	-fvisibility=hidden \
	-fvisibility-inlines-hidden \
	-fno-objc-convert-messages-to-runtime-calls \
	-std=gnu++14 \
	-stdlib=libc++ \
	-Wno-trigraphs \
	-Wno-deprecated-declarations
libobjc_la_SOURCES = \
	objc-runtime-new.mm \
	objc-class.mm \
	objc-os.mm \
	objc-runtime.mm \
	objc-sel.mm \
	objc-loadmethod.mm \
	objc-opt.mm \
	objc-cache.mm \
	objc-initialize.mm \
	objc-exception.mm \
	objc-typeencoding.mm \
	objc-errors.mm \
	NSObject.mm \
	objc-weak.mm \
	objc-references.mm \
	objc-block-trampolines.mm \
	objc-file.mm \
	objc-sync.mm \
	objc-lockdebug.mm \
	objc-accessors.mm \
	maptable.mm \
	Protocol.mm
# libobjc_la_LDADD = -lobjc -lc++ -lc++abi
libobjc_la_LIBADD = asm/libobjc-asm.la

# objc-exception: CFLAGS += -fexceptions
