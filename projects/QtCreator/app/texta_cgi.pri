########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   Date: 6/4/2016
########################################################################

texta_cgi_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

texta_cgi_DEFINES += \
$${texta_DEFINES} \

########################################################################
# texta_cgi
texta_cgi_HEADERS += \
$${TEXTA_SRC}/texta/app/cgi/texta/main.hpp \
$${TEXTA_SRC}/texta/inet/cgi/main.hpp \

texta_cgi_SOURCES += \
$${TEXTA_SRC}/texta/app/cgi/texta/main.cpp \

########################################################################
# coral
texta_cgi_HEADERS += \
$${CORAL_SRC}/coral/app/cgi/main.hpp \
$${CORAL_SRC}/coral/console/main.hpp \
$${CORAL_SRC}/coral/console/main_main.hpp \

texta_cgi_SOURCES += \
$${CORAL_SRC}/coral/console/main_main.cpp \

########################################################################
texta_cgi_LIBS += \
$${texta_LIBS} \
