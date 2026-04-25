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
#   File: evls.pro
#
# Author: $author$
#   Date: 3/6/2023
#
# os specific QtCreator project .pro file for texta framework evup executable evls
########################################################################
#
# Debug: evup/build/os/QtCreator/Debug/bin/evls
# Release: evup/build/os/QtCreator/Release/bin/evls
# Profile: evup/build/os/QtCreator/Profile/bin/evls
#
include(../../../../../build/QtCreator/evup.pri)
include(../../../../QtCreator/evup.pri)
include(../../evup.pri)
include(../../../../QtCreator/app/evls/evls.pri)

TARGET = $${evls_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${evls_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${evls_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${evls_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${evls_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${evls_HEADERS} \
$${evls_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${evls_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${evls_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${evls_LIBS} \
$${FRAMEWORKS} \

########################################################################
