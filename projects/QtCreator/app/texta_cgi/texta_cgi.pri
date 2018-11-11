########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   File: texta_cgi.pri
#
# Author: $author$
#   Date: 11/7/2018
#
# QtCreator .pri file for texta executable texta_cgi
########################################################################

########################################################################
# texta_cgi

# texta_cgi TARGET
#
texta_cgi_TARGET = texta_cgi

# texta_cgi INCLUDEPATH
#
texta_cgi_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# texta_cgi DEFINES
#
texta_cgi_DEFINES += \
$${texta_DEFINES} \

########################################################################
# texta_cgi OBJECTIVE_HEADERS
#
#texta_cgi_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/base/Base.hh \

# texta_cgi OBJECTIVE_SOURCES
#
#texta_cgi_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/base/Base.mm \

########################################################################
# texta_cgi HEADERS
#
texta_cgi_HEADERS += \
$${TEXTA_SRC}/texta/app/cgi/texta/main.hpp \

# texta_cgi SOURCES
#
texta_cgi_SOURCES += \
$${TEXTA_SRC}/texta/app/cgi/texta/main.cpp \
$${texta_function_SOURCES} \

########################################################################
# texta_cgi FRAMEWORKS
#
texta_cgi_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# texta_cgi LIBS
#
texta_cgi_LIBS += \
$${texta_LIBS} \


