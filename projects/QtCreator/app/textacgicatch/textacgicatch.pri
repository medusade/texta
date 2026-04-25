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
#   File: textacgicatch.pri
#
# Author: $author$
#   Date: 3/5/2023
#
# generic QtCreator project file for texta framework texta executable textacgicatch
########################################################################

########################################################################
# textacgicatch

# textacgicatch TARGET
#
textacgicatch_TARGET = textacgicatch

# textacgicatch INCLUDEPATH
#
textacgicatch_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# textacgicatch DEFINES
#
textacgicatch_DEFINES += \
$${texta_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# textacgicatch OBJECTIVE_HEADERS
#
#textacgicatch_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/xos/app/console/textacgicatch/main.hh \

# textacgicatch OBJECTIVE_SOURCES
#
#textacgicatch_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/xos/app/console/textacgicatch/main.mm \

########################################################################
# textacgicatch HEADERS
#
textacgicatch_HEADERS += \
$${CORAL_SRC}/coral/app/cgi/catcher/main.hpp \

# textacgicatch SOURCES
#
textacgicatch_SOURCES += \
$${CORAL_SRC}/coral/app/cgi/catcher/main.cpp \

########################################################################
# textacgicatch FRAMEWORKS
#
textacgicatch_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# textacgicatch LIBS
#
textacgicatch_LIBS += \
$${texta_LIBS} \

########################################################################
# NO Qt
QT -= gui core
