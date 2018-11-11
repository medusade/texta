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
#   File: texta.pri
#
# Author: $author$
#   Date: 11/7/2018
#
# build QtCreator .pri file for texta
########################################################################

########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#

# build rostra INCLUDEPATH
#
build_rostra_INCLUDEPATH += \

# build rostra DEFINES
#
build_rostra_DEFINES += \

# build rostra LIBS
#
build_rostra_LIBS += \

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

# build nadir INCLUDEPATH
#
build_nadir_INCLUDEPATH += \

# build nadir DEFINES
#
build_nadir_DEFINES += \

# build nadir LIBS
#
build_nadir_LIBS += \

########################################################################
# medusa
#
# pkg-config --cflags --libs medusa
#

# build medusa INCLUDEPATH
#
build_medusa_INCLUDEPATH += \

# build medusa DEFINES
#
build_medusa_DEFINES += \

# build medusa LIBS
#
build_medusa_LIBS += \

########################################################################
# coral
#
# pkg-config --cflags --libs coral
#

# build coral INCLUDEPATH
#
build_coral_INCLUDEPATH += \

# build coral DEFINES
#
build_coral_DEFINES += \

# build coral LIBS
#
build_coral_LIBS += \

########################################################################
# texta

# build texta INCLUDEPATH
#
build_texta_INCLUDEPATH += \
$${build_coral_INCLUDEPATH} \
$${build_medusa_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \
$${build_rostra_INCLUDEPATH} \


# build texta DEFINES
#
build_texta_DEFINES += \
$${build_rostra_DEFINES} \
$${build_nadir_DEFINES} \
$${build_medusa_DEFINES} \
$${build_coral_DEFINES} \


# build texta LIBS
#
build_texta_LIBS += \
$${build_coral_LIBS} \
$${build_medusa_LIBS} \
$${build_nadir_LIBS} \
$${build_rostra_LIBS} \


