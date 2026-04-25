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
#   File: texta.pri
#
# Author: $author$
#   Date: 3/5/2023
#
# os specific QtCreator project file for texta framework texta
########################################################################
# Depends: nadir;rostra;talas;medusa;coral

UNAME = $$system(uname)

contains(UNAME,Darwin) {
DARWIN_VERSION = $$system(sw_vers -productVersion)
} else {
contains(UNAME,Linux) {
LINUX_VERSION = $$system(uname -r)
} else {
contains(UNAME,Windows) {
WINDOWS_VERSION = $$system(ver)
} else {
} # contains(UNAME,Windows)
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(UNAME,Darwin) {
DARWIN_VERSION_NUMBER = $$system(echo $${DARWIN_VERSION} | cut -d'.' -f1)
contains(DARWIN_VERSION_NUMBER,15) {
DARWIN_VERSION_NAME = Sequoia
} else {
contains(DARWIN_VERSION_NUMBER,14) {
DARWIN_VERSION_NAME = Sonoma
} else {
contains(DARWIN_VERSION_NUMBER,13) {
DARWIN_VERSION_NAME = Ventura
} else {
contains(DARWIN_VERSION_NUMBER,12) {
DARWIN_VERSION_NAME = Monterey
} else {
contains(DARWIN_VERSION_NUMBER,11) {
DARWIN_VERSION_NAME = Bigsur
} else {
contains(DARWIN_VERSION_NUMBER,10) {
DARWIN_VERSION_NAME = Sierra
} else {
DARWIN_VERSION_NAME = Mavricks
} # contains(DARWIN_VERSION,10)
} # contains(DARWIN_VERSION,11)
} # contains(DARWIN_VERSION,12)
} # contains(DARWIN_VERSION,13)
} # contains(DARWIN_VERSION,14)
} # contains(DARWIN_VERSION,15)
} # contains(UNAME,Darwin)

contains(UNAME,Darwin) {
TEXTA_OS = macosx
} else {
contains(UNAME,Linux) {
TEXTA_OS = linux
} else {
TEXTA_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,TEXTA_OS) {
TEXTA_BUILD = $${TEXTA_OS}
} else {
TEXTA_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,TEXTA_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(TEXTA_OS,macosx) {
contains(DARWIN_VERSION_NUMBER,15) {
#QMAKE_CXXFLAGS += -Werror -Wno-error=register
QMAKE_CXXFLAGS += -Wno-register
} else {
} # contains(DARWIN_VERSION_NUMBER,15)
contains(DARWIN_VERSION_NUMBER,14) {
QMAKE_CXXFLAGS += -Wno-dynamic-exception-spec
} else {
} # contains(DARWIN_VERSION_NUMBER,14)
contains(DARWIN_VERSION_NUMBER,11|12|13|14|15) {
QMAKE_CFLAGS += -Wno-implicit-function-declaration
} else {
} # contains(DARWIN_VERSION_NUMBER,11|12|13|14|15)
} else {
contains(TEXTA_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(TEXTA_OS,windows) {
} else {
} # contains(TEXTA_OS,windows)
} # contains(TEXTA_OS,linux)
} # contains(TEXTA_OS,macosx)


########################################################################
# nadir
NADIR_THIRDPARTY_PKG_MAKE_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${NADIR_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PKG_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${NADIR_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_PKG_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_PRJ_BLD = $${OTHER_BLD}/$${NADIR_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_BLD}/lib
NADIR_LIB = $${NADIR_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_PRJ_BLD}/lib
#NADIR_LIB = $${TEXTA_LIB}
NADIR_LIB_NAME = xos$${NADIR_NAME}

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_LIB_NAME} \
-l$${NADIR_LIB_NAME} \


########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${ROSTRA_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${TEXTA_LIB}
ROSTRA_LIB_NAME = xos$${ROSTRA_NAME}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_LIB_NAME} \
-l$${ROSTRA_LIB_NAME} \


########################################################################
# talas
TALAS_THIRDPARTY_PKG_MAKE_BLD = $${TALAS_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
TALAS_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${TALAS_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
TALAS_THIRDPARTY_PKG_BLD = $${TALAS_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
TALAS_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${TALAS_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
TALAS_PKG_BLD = $${OTHER_BLD}/$${TALAS_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
TALAS_PRJ_BLD = $${OTHER_BLD}/$${TALAS_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
#TALAS_LIB = $${TALAS_THIRDPARTY_PKG_MAKE_BLD}/lib
#TALAS_LIB = $${TALAS_THIRDPARTY_PRJ_MAKE_BLD}/lib
#TALAS_LIB = $${TALAS_THIRDPARTY_PKG_BLD}/lib
#TALAS_LIB = $${TALAS_THIRDPARTY_PRJ_BLD}/lib
TALAS_LIB = $${TALAS_PKG_BLD}/lib
#TALAS_LIB = $${TALAS_PRJ_BLD}/lib
#TALAS_LIB = $${TEXTA_LIB}
TALAS_LIB_NAME = $${TALAS_NAME}

# talas LIBS
#
talas_LIBS += \
-L$${TALAS_LIB}/lib$${TALAS_LIB_NAME} \
-l$${TALAS_LIB_NAME} \


########################################################################
# medusa
MEDUSA_THIRDPARTY_PKG_MAKE_BLD = $${MEDUSA_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
MEDUSA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${MEDUSA_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
MEDUSA_THIRDPARTY_PKG_BLD = $${MEDUSA_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
MEDUSA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${MEDUSA_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
MEDUSA_PKG_BLD = $${OTHER_BLD}/$${MEDUSA_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
MEDUSA_PRJ_BLD = $${OTHER_BLD}/$${MEDUSA_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
#MEDUSA_LIB = $${MEDUSA_THIRDPARTY_PKG_MAKE_BLD}/lib
#MEDUSA_LIB = $${MEDUSA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#MEDUSA_LIB = $${MEDUSA_THIRDPARTY_PKG_BLD}/lib
#MEDUSA_LIB = $${MEDUSA_THIRDPARTY_PRJ_BLD}/lib
MEDUSA_LIB = $${MEDUSA_PKG_BLD}/lib
#MEDUSA_LIB = $${MEDUSA_PRJ_BLD}/lib
#MEDUSA_LIB = $${TEXTA_LIB}
MEDUSA_LIB_NAME = $${MEDUSA_NAME}

# medusa LIBS
#
medusa_LIBS += \
-L$${MEDUSA_LIB}/lib$${MEDUSA_LIB_NAME} \
-l$${MEDUSA_LIB_NAME} \


########################################################################
# coral
CORAL_THIRDPARTY_PKG_MAKE_BLD = $${CORAL_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
CORAL_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${CORAL_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/$${BUILD_CONFIG}
CORAL_THIRDPARTY_PKG_BLD = $${CORAL_THIRDPARTY_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
CORAL_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${CORAL_THIRDPARTY_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
CORAL_PKG_BLD = $${OTHER_BLD}/$${CORAL_PKG}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
CORAL_PRJ_BLD = $${OTHER_BLD}/$${CORAL_PRJ}/build/$${TEXTA_BUILD}/QtCreator/$${BUILD_CONFIG}
#CORAL_LIB = $${CORAL_THIRDPARTY_PKG_MAKE_BLD}/lib
#CORAL_LIB = $${CORAL_THIRDPARTY_PRJ_MAKE_BLD}/lib
#CORAL_LIB = $${CORAL_THIRDPARTY_PKG_BLD}/lib
#CORAL_LIB = $${CORAL_THIRDPARTY_PRJ_BLD}/lib
CORAL_LIB = $${CORAL_PKG_BLD}/lib
#CORAL_LIB = $${CORAL_PRJ_BLD}/lib
#CORAL_LIB = $${TEXTA_LIB}
CORAL_LIB_NAME = $${CORAL_NAME}

# coral LIBS
#
coral_LIBS += \
-L$${CORAL_LIB}/lib$${CORAL_LIB_NAME} \
-l$${CORAL_LIB_NAME} \

########################################################################
# texta

# texta INCLUDEPATH
#
texta_INCLUDEPATH += \

# texta DEFINES
#
texta_DEFINES += \

# texta os LIBS
#
contains(TEXTA_OS,macosx|linux) {
texta_os_LIBS += \
-lpthread \
-ldl
} else {
} # contains(TEXTA_OS,macosx|linux)

contains(TEXTA_OS,linux) {
texta_os_LIBS += \
-lrt
} else {
} # contains(TEXTA_OS,linux)


# texta base LIBS
#
texta_base_LIBS += \
$${coral_LIBS} \
$${medusa_LIBS} \
$${talas_LIBS} \
$${rostra_LIBS} \
$${nadir_LIBS} \


# texta LIBS
#
texta_LIBS += \
$${texta_base_LIBS} \
$${build_texta_LIBS} \
$${texta_os_LIBS} \

########################################################################
