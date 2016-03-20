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
#   File: texta.pri
#
# Author: $author$
#   Date: 3/18/2016
########################################################################

texta_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

texta_DEFINES += \
$${texta_DEFINES} \

########################################################################
# xos
texta_HEADERS += \
$${XOS_SRC}/xos/base/binary/tree.hpp \
$${XOS_SRC}/xos/base/binary/branch.hpp \
$${XOS_SRC}/xos/base/tree.hpp \
$${XOS_SRC}/xos/base/branch.hpp \
$${XOS_SRC}/xos/base/leaf.hpp \
$${XOS_SRC}/xos/base/list.hpp \
$${XOS_SRC}/xos/base/item.hpp \

texta_SOURCES += \
$${XOS_SRC}/xos/base/binary/tree.cpp \
$${XOS_SRC}/xos/base/binary/branch.cpp \
$${XOS_SRC}/xos/base/leaf.cpp \
$${XOS_SRC}/xos/base/list.cpp \
$${XOS_SRC}/xos/base/item.cpp \

########################################################################
# texta
texta_HEADERS += \
$${TEXTA_SRC}/texta/app/console/texta/main.hpp \

texta_SOURCES += \
$${TEXTA_SRC}/texta/app/console/texta/main.cpp \

########################################################################
# xos
texta_HEADERS += \
$${XOS_SRC}/xos/base/getopt/main_opt.hpp \
$${XOS_SRC}/xos/base/getopt/main.hpp \
$${XOS_SRC}/xos/base/main.hpp \
$${XOS_SRC}/xos/base/main_main.hpp \

texta_SOURCES += \
$${XOS_SRC}/xos/base/getopt/main_opt.cpp \
$${XOS_SRC}/xos/base/main_main.cpp \

########################################################################
texta_LIBS += \
$${texta_LIBS} \

