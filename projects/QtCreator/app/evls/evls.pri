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
#   File: evls.pri
#
# Author: $author$
#   Date: 3/6/2023
#
# generic QtCreator project file for texta framework evup executable evls
########################################################################

########################################################################
# evls

# evls TARGET
#
evls_TARGET = evls

# evls INCLUDEPATH
#
evls_INCLUDEPATH += \
$${evup_INCLUDEPATH} \

# evls DEFINES
#
evls_DEFINES += \
$${evup_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# evls OBJECTIVE_HEADERS
#
#evls_OBJECTIVE_HEADERS += \
#$${EVUP_SRC}/xos/app/console/evls/main.hh \

# evls OBJECTIVE_SOURCES
#
#evls_OBJECTIVE_SOURCES += \
#$${EVUP_SRC}/xos/app/console/evls/main.mm \

########################################################################
# evls HEADERS
#
evls_HEADERS += \
$${EVUP_SRC}/app/evls/evls.hpp \
$${EVUP_SRC}/os/evmain.hpp \

# evls SOURCES
#
evls_SOURCES += \
$${EVUP_SRC}/app/evls/evls.cpp \
$${EVUP_SRC}/os/evmain.cpp \

########################################################################
# evls FRAMEWORKS
#
evls_FRAMEWORKS += \
$${evup_FRAMEWORKS} \

# evls LIBS
#
evls_LIBS += \
$${evup_LIBS} \

########################################################################
# NO Qt
QT -= gui core
