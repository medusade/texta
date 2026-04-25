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
#   File: textacgi.pri
#
# Author: $author$
#   Date: 3/5/2023
#
# generic QtCreator project file for texta framework texta executable textacgi
########################################################################

########################################################################
# textacgi

# textacgi TARGET
#
textacgi_TARGET = textacgi

# textacgi INCLUDEPATH
#
textacgi_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# textacgi DEFINES
#
textacgi_DEFINES += \
$${texta_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# textacgi OBJECTIVE_HEADERS
#
#textacgi_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/xos/app/console/textacgi/main.hh \

# textacgi OBJECTIVE_SOURCES
#
#textacgi_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/xos/app/console/textacgi/main.mm \

########################################################################
# textacgi HEADERS
#
textacgi_HEADERS += \
$${TEXTA_SRC}/texta/app/cgi/texta/main.hpp \

# textacgi SOURCES
#
textacgi_SOURCES += \
$${TEXTA_SRC}/texta/app/cgi/texta/main.cpp \
$${texta_function_SOURCES} \

########################################################################
# textacgi FRAMEWORKS
#
textacgi_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# textacgi LIBS
#
textacgi_LIBS += \
$${texta_LIBS} \

########################################################################
# NO Qt
QT -= gui core
