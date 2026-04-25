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
#   File: xsl.pri
#
# Author: $author$
#   Date: 3/6/2023
#
# generic QtCreator project file for texta framework medusaxde executable xsl
########################################################################

########################################################################
# xsl

# xsl TARGET
#
xsl_TARGET = xsl

# xsl INCLUDEPATH
#
xsl_INCLUDEPATH += \
$${medusaxde_INCLUDEPATH} \

# xsl DEFINES
#
xsl_DEFINES += \
$${medusaxde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# xsl OBJECTIVE_HEADERS
#
#xsl_OBJECTIVE_HEADERS += \
#$${MEDUSAXDE_SRC}/xos/app/console/xsl/main.hh \

# xsl OBJECTIVE_SOURCES
#
#xsl_OBJECTIVE_SOURCES += \
#$${MEDUSAXDE_SRC}/xos/app/console/xsl/main.mm \

########################################################################
# xsl HEADERS
#
xsl_HEADERS += \
$${XDE_SRC}/capp/xsl/cxslmain.hxx \

# xsl SOURCES
#
xsl_SOURCES += \
$${XDE_SRC}/capp/xsl/cxslmain.cxx \
$${XDE_SRC}/clib/cos/argmain.cxx \

########################################################################
# xsl FRAMEWORKS
#
xsl_FRAMEWORKS += \
$${medusaxde_FRAMEWORKS} \
$${xde_FRAMEWORKS} \

# xsl LIBS
#
xsl_LIBS += \
$${medusaxde_LIBS} \
$${xde_LIBS} \

########################################################################
# NO Qt
QT -= gui core
