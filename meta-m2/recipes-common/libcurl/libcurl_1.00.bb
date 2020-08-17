# Recipe created by recipetool
# This is the basis of a recipe and may need further editing in order to be fully functional.
# (Feel free to remove these comments when editing.)

# WARNING: the following LICENSE and LIC_FILES_CHKSUM values are best guesses - it is
# your responsibility to verify that the values are complete and correct.
#
# The following license files were not able to be identified and are
# represented as "Unknown" below, you will need to check them yourself:
#   COPYING
#   docs/LICENSE-MIXING.md
LICENSE = "Unknown"
LIC_FILES_CHKSUM = "file://COPYING;md5=2e9fb35867314fe31c6a4977ef7dd531 \
                    file://docs/LICENSE-MIXING.md;md5=ff0c1fab52a863b660cc43ddded0b11c"

SRC_URI = "https://curl.haxx.se/download/curl-7.71.1.tar.gz"
SRC_URI[md5sum] = "39bc8d8ae8d59587e863abab739ce7b4"
SRC_URI[sha256sum] = "59ef1f73070de67b87032c72ee6037cedae71dcb1d7ef2d7f59487704aec069d"

S = "${WORKDIR}/curl-7.71.1"

# NOTE: unable to map the following CMake package dependencies: QUICHE MbedTLS GSS BearSSL NGTCP2 LibSSH2 libssh NGHTTP2 NGHTTP3 CARES Brotli WolfSSL NSS
DEPENDS = "openssl zlib"

inherit cmake perlnative

# Specify any options you want to pass to cmake using EXTRA_OECMAKE:
EXTRA_OECMAKE = ""

