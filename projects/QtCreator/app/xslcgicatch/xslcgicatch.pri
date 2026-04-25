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
#   File: xslcgicatch.pri
#
# Author: $author$
#   Date: 3/6/2023
#
# generic QtCreator project file for texta framework medusaxde executable xslcgicatch
########################################################################

########################################################################
# xslcgicatch

# xslcgicatch TARGET
#
xslcgicatch_TARGET = xslcgicatch

# xslcgicatch INCLUDEPATH
#
xslcgicatch_INCLUDEPATH += \
$${medusaxde_INCLUDEPATH} \

# xslcgicatch DEFINES
#
xslcgicatch_DEFINES += \
$${medusaxde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# xslcgicatch OBJECTIVE_HEADERS
#
#xslcgicatch_OBJECTIVE_HEADERS += \
#$${MEDUSAXDE_SRC}/xos/app/console/xslcgicatch/main.hh \

# xslcgicatch OBJECTIVE_SOURCES
#
#xslcgicatch_OBJECTIVE_SOURCES += \
#$${MEDUSAXDE_SRC}/xos/app/console/xslcgicatch/main.mm \

########################################################################
# xslcgicatch HEADERS
#
xslcgicatch_HEADERS += \
$${XDE_SRC}/capp/ccgi/cgicatch/ccgicatch.hxx \
$${XDE_SRC}/clib/ccgi/cgi.hxx \

# xslcgicatch SOURCES
#
xslcgicatch_SOURCES += \
$${XDE_SRC}/capp/ccgi/cgicatch/ccgicatch.cxx \
$${XDE_SRC}/clib/ccgi/cgi.cxx \

########################################################################
# xslcgicatch FRAMEWORKS
#
xslcgicatch_FRAMEWORKS += \
$${xde_FRAMEWORKS} \

# xslcgicatch LIBS
#
xslcgicatch_LIBS += \
$${xde_LIBS} \

########################################################################
# NO Qt
QT -= gui core
