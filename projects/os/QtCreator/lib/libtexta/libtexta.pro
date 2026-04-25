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
#   File: libtexta.pro
#
# Author: $author$
#   Date: 3/5/2023
#
# os specific QtCreator project .pro file for texta framework texta static library libtexta
########################################################################
# Depends: nadir;rostra;talas;medusa;coral
#
# Debug: texta/build/os/QtCreator/Debug/lib/libtexta
# Release: texta/build/os/QtCreator/Release/lib/libtexta
# Profile: texta/build/os/QtCreator/Profile/lib/libtexta
#
include(../../../../../build/QtCreator/texta.pri)
include(../../../../QtCreator/texta.pri)
include(../../texta.pri)
include(../../../../QtCreator/lib/libtexta/libtexta.pri)

TARGET = $${libtexta_TARGET}
TEMPLATE = $${libtexta_TEMPLATE}
CONFIG += $${libtexta_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libtexta_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libtexta_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libtexta_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libtexta_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libtexta_HEADERS} \
$${libtexta_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libtexta_SOURCES} \

########################################################################
