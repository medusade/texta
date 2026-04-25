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
#   File: textacgi.pro
#
# Author: $author$
#   Date: 3/5/2023
#
# os specific QtCreator project .pro file for texta framework texta executable textacgi
########################################################################
# Depends: nadir;rostra;talas;medusa;coral
#
# Debug: texta/build/os/QtCreator/Debug/bin/textacgi
# Release: texta/build/os/QtCreator/Release/bin/textacgi
# Profile: texta/build/os/QtCreator/Profile/bin/textacgi
#
include(../../../../../build/QtCreator/texta.pri)
include(../../../../QtCreator/texta.pri)
include(../../texta.pri)
include(../../../../QtCreator/app/textacgi/textacgi.pri)

TARGET = $${textacgi_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${textacgi_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${textacgi_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${textacgi_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${textacgi_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${textacgi_HEADERS} \
$${textacgi_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${textacgi_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${textacgi_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${textacgi_LIBS} \
$${FRAMEWORKS} \

########################################################################
