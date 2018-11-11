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
# Os QtCreator .pri file for texta
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
TEXTA_OS = macosx
} else {
TEXTA_OS = linux
}

#CONFIG += c++11
#CONFIG += c++0x

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${TEXTA_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# nadir
NADIR_THIRDPARTY_PKG_MAKE_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_MAKE_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PKG_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PKG_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PRJ_BLD = $${OTHER_BLD}/$${NADIR_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_BLD}/lib
#NADIR_LIB = $${NADIR_PKG_BLD}/lib
NADIR_LIB = $${NADIR_PRJ_BLD}/lib
#NADIR_LIB = $${TEXTA_LIB}

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_NAME} \
-l$${NADIR_NAME} \

# xosnadir LIBS
#
xosnadir_LIBS += \
-L$${NADIR_LIB}/libxos$${NADIR_NAME} \
-lxos$${NADIR_NAME} \

########################################################################
# medusa
MEDUSA_THIRDPARTY_PKG_MAKE_BLD = $${MEDUSA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
MEDUSA_THIRDPARTY_PRJ_MAKE_BLD = $${MEDUSA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
MEDUSA_THIRDPARTY_PKG_BLD = $${MEDUSA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
MEDUSA_THIRDPARTY_PRJ_BLD = $${MEDUSA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
MEDUSA_PKG_BLD = $${OTHER_BLD}/$${MEDUSA_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
MEDUSA_PRJ_BLD = $${OTHER_BLD}/$${MEDUSA_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#MEDUSA_LIB = $${MEDUSA_THIRDPARTY_PKG_MAKE_BLD}/lib
#MEDUSA_LIB = $${MEDUSA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#MEDUSA_LIB = $${MEDUSA_THIRDPARTY_PKG_BLD}/lib
#MEDUSA_LIB = $${MEDUSA_THIRDPARTY_PRJ_BLD}/lib
#MEDUSA_LIB = $${MEDUSA_PKG_BLD}/lib
MEDUSA_LIB = $${MEDUSA_PRJ_BLD}/lib
#MEDUSA_LIB = $${TEXTA_LIB}

# medusa LIBS
#
medusa_LIBS += \
-L$${MEDUSA_LIB}/lib$${MEDUSA_NAME} \
-l$${MEDUSA_NAME} \

########################################################################
# coral
CORAL_THIRDPARTY_PKG_MAKE_BLD = $${CORAL_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
CORAL_THIRDPARTY_PRJ_MAKE_BLD = $${CORAL_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
CORAL_THIRDPARTY_PKG_BLD = $${CORAL_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
CORAL_THIRDPARTY_PRJ_BLD = $${CORAL_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
CORAL_PKG_BLD = $${OTHER_BLD}/$${CORAL_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
CORAL_PRJ_BLD = $${OTHER_BLD}/$${CORAL_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#CORAL_LIB = $${CORAL_THIRDPARTY_PKG_MAKE_BLD}/lib
#CORAL_LIB = $${CORAL_THIRDPARTY_PRJ_MAKE_BLD}/lib
#CORAL_LIB = $${CORAL_THIRDPARTY_PKG_BLD}/lib
#CORAL_LIB = $${CORAL_THIRDPARTY_PRJ_BLD}/lib
#CORAL_LIB = $${CORAL_PKG_BLD}/lib
CORAL_LIB = $${CORAL_PRJ_BLD}/lib
#CORAL_LIB = $${TEXTA_LIB}

# coral LIBS
#
coral_LIBS += \
-L$${CORAL_LIB}/lib$${CORAL_NAME} \
-l$${CORAL_NAME} \

########################################################################
# texta

# texta INCLUDEPATH
#
texta_INCLUDEPATH += \

# texta DEFINES
#
texta_DEFINES += \

# texta LIBS
#
texta_LIBS += \
$${coral_LIBS} \
$${medusa_LIBS} \
$${xosnadir_LIBS} \
$${build_texta_LIBS} \
-lpthread \
-ldl \

contains(TEXTA_OS,linux) {
texta_LIBS += \
-lrt
} else {
}

