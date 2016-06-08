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
#   File: texta.pro
#
# Author: $author$
#   Date: 3/18/2016
########################################################################
include(../../../../QtCreator/texta.pri)
include(../../../../QtCreator/app/texta.pri)
include(../../../../QtCreator/app/texta_functions.pri)
include(../../texta.pri)

TARGET = texta

INCLUDEPATH += \
$${texta_INCLUDEPATH} \

DEFINES += \
$${texta_DEFINES} \

HEADERS += \
$${texta_HEADERS} \

SOURCES += \
$${texta_SOURCES} \

LIBS += \
$${texta_LIBS} \
