########################################################################
# Copyright (c) 1988-2023 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: evup.pri
#
# Author: $author$
#   Date: 3/6/2023
#
# generic QtCreator project .pri file for texta framework evup
########################################################################

OTHER_RPO = ../../../../../../..
OTHER_PKG = ../../../../../..
OTHER_PRJ = ../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/source/$${THIRDPARTY_NAME}


########################################################################
# evup
EVUP_NAME = evup
EVUP_SOURCE = source/$${EVUP_NAME}
EVUP_CREDS = creds

EVUP_PKG = ../../../../..
EVUP_BLD = ../..

EVUP_PRJ = $${EVUP_PKG}
EVUP_BIN = $${EVUP_BLD}/bin
EVUP_LIB = $${EVUP_BLD}/lib
EVUP_SRC = $${EVUP_PKG}/$${EVUP_SOURCE}
EVUP_CRD_SRC = $${EVUP_PKG}/$${EVUP_CREDS}/$${EVUP_SOURCE}

# evup BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
evup_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
evup_DEFINES += RELEASE_BUILD
}

# evup INCLUDEPATH
#
evup_INCLUDEPATH += \
$${EVUP_SRC}/os/evup \
$${EVUP_SRC}/os \
$${EVUP_SRC}/file \
$${EVUP_SRC}/base \
$${EVUP_SRC} \
$${EVUP_CRD_SRC} \
$${build_evup_INCLUDEPATH} \

# evup DEFINES
#
evup_DEFINES += \
$${build_evup_DEFINES} \

# evup LIBS
#
evup_LIBS += \
-L$${EVUP_LIB}/lib$${EVUP_NAME} \
-l$${EVUP_NAME} \
