#!/bin/sh

set -e -x

# We don't use gettext currently
# ${AUTOPOINT:-autopoint} -f
${LIBTOOLIZE:-libtoolize} -c -f || glibtoolize -c -f
${ACLOCAL:-aclocal} -I m4
${AUTOCONF:-autoconf}
${AUTOHEADER:-autoheader}
${AUTOMAKE:-automake} -acf --foreign

exit 0
