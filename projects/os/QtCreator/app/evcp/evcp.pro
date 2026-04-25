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
#   File: evcp.pro
#
# Author: $author$
#   Date: 3/6/2023
#
# os specific QtCreator project .pro file for texta framework evup executable evcp
########################################################################
#
# Debug: evup/build/os/QtCreator/Debug/bin/evcp
# Release: evup/build/os/QtCreator/Release/bin/evcp
# Profile: evup/build/os/QtCreator/Profile/bin/evcp
#
include(../../../../../build/QtCreator/evup.pri)
include(../../../../QtCreator/evup.pri)
include(../../evup.pri)
include(../../../../QtCreator/app/evcp/evcp.pri)

TARGET = $${evcp_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${evcp_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${evcp_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${evcp_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${evcp_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${evcp_HEADERS} \
$${evcp_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${evcp_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${evcp_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${evcp_LIBS} \
$${FRAMEWORKS} \

########################################################################
