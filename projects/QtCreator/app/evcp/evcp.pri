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
#   File: evcp.pri
#
# Author: $author$
#   Date: 3/6/2023
#
# generic QtCreator project file for texta framework evup executable evcp
########################################################################

########################################################################
# evcp

# evcp TARGET
#
evcp_TARGET = evcp

# evcp INCLUDEPATH
#
evcp_INCLUDEPATH += \
$${evup_INCLUDEPATH} \

# evcp DEFINES
#
evcp_DEFINES += \
$${evup_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# evcp OBJECTIVE_HEADERS
#
#evcp_OBJECTIVE_HEADERS += \
#$${EVUP_SRC}/xos/app/console/evcp/main.hh \

# evcp OBJECTIVE_SOURCES
#
#evcp_OBJECTIVE_SOURCES += \
#$${EVUP_SRC}/xos/app/console/evcp/main.mm \

########################################################################
# evcp HEADERS
#
evcp_HEADERS += \
$${EVUP_SRC}/app/evcp/evcp.hpp \
$${EVUP_SRC}/os/evmain.hpp \

# evcp SOURCES
#
evcp_SOURCES += \
$${EVUP_SRC}/app/evcp/evcp.cpp \
$${EVUP_SRC}/os/evmain.cpp \

########################################################################
# evcp FRAMEWORKS
#
evcp_FRAMEWORKS += \
$${evup_FRAMEWORKS} \

# evcp LIBS
#
evcp_LIBS += \
$${evup_LIBS} \

########################################################################
# NO Qt
QT -= gui core
