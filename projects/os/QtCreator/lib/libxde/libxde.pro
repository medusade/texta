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
#   File: libxde.pro
#
# Author: $author$
#   Date: 3/6/2023
#
# os specific QtCreator project .pro file for texta framework xde static library libxde
########################################################################
#
# Debug: xde/build/os/QtCreator/Debug/lib/libxde
# Release: xde/build/os/QtCreator/Release/lib/libxde
# Profile: xde/build/os/QtCreator/Profile/lib/libxde
#
include(../../../../../build/QtCreator/xde.pri)
include(../../../../QtCreator/xde.pri)
include(../../xde.pri)
include(../../../../QtCreator/lib/libxde/libxde.pri)

TARGET = $${libxde_TARGET}
TEMPLATE = $${libxde_TEMPLATE}
CONFIG += $${libxde_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libxde_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libxde_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libxde_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libxde_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libxde_HEADERS} \
$${libxde_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libxde_SOURCES} \

########################################################################
