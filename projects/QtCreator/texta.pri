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
# QtCreator .pri file for texta
########################################################################

OTHER_PKG = ../../../../../../..
OTHER_PRJ = ../../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/src/$${THIRDPARTY_NAME}

########################################################################
# rostra
ROSTRA_VERSION_MAJOR = 0
ROSTRA_VERSION_MINOR = 0
ROSTRA_VERSION_RELEASE = 0
ROSTRA_VERSION = $${ROSTRA_VERSION_MAJOR}.$${ROSTRA_VERSION_MINOR}.$${ROSTRA_VERSION_RELEASE}
ROSTRA_NAME = rostra
ROSTRA_GROUP = $${ROSTRA_NAME}
ROSTRA_SOURCE = src
ROSTRA_DIR = $${ROSTRA_GROUP}/$${ROSTRA_NAME}-$${ROSTRA_VERSION}
ROSTRA_PKG_DIR = $${ROSTRA_NAME}
ROSTRA_HOME_BUILD = $${HOME}/build/$${ROSTRA_NAME}
ROSTRA_HOME_BUILD_INCLUDE = $${ROSTRA_HOME_BUILD}/include
ROSTRA_HOME_BUILD_LIB = $${ROSTRA_HOME_BUILD}/lib
ROSTRA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ROSTRA_PKG_DIR}
ROSTRA_THIRDPARTY_SRC_GROUP = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_NAME = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ROSTRA_THIRDPARTY_SRC_GROUP}/$${ROSTRA_THIRDPARTY_SRC_NAME} 
ROSTRA_PKG = $${OTHER_PKG}/$${ROSTRA_PKG_DIR}
ROSTRA_PRJ = $${OTHER_PRJ}/$${ROSTRA_PKG_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_SRC_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PKG}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PRJ}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_PKG}/$${ROSTRA_SOURCE}
ROSTRA_SRC = $${ROSTRA_PRJ}/$${ROSTRA_SOURCE}

# rostra INCLUDEPATH
#
#rostra_INCLUDEPATH += \
#$${ROSTRA_HOME_BUILD_INCLUDE} \

rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

# rostra DEFINES
#
rostra_DEFINES += \

########################################################################
# nadir
NADIR_VERSION_MAJOR = 0
NADIR_VERSION_MINOR = 0
NADIR_VERSION_RELEASE = 0
NADIR_VERSION = $${NADIR_VERSION_MAJOR}.$${NADIR_VERSION_MINOR}.$${NADIR_VERSION_RELEASE}
NADIR_NAME = nadir
NADIR_GROUP = $${NADIR_NAME}
NADIR_SOURCE = src
NADIR_DIR = $${NADIR_GROUP}/$${NADIR_NAME}-$${NADIR_VERSION}
NADIR_PKG_DIR = $${NADIR_NAME}
NADIR_HOME_BUILD = $${HOME}/build/$${NADIR_NAME}
NADIR_HOME_BUILD_INCLUDE = $${NADIR_HOME_BUILD}/include
NADIR_HOME_BUILD_LIB = $${NADIR_HOME_BUILD}/lib
NADIR_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${NADIR_DIR}
NADIR_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${NADIR_DIR}
NADIR_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${NADIR_PKG_DIR}
NADIR_THIRDPARTY_SRC_GROUP = $${NADIR_NAME}
NADIR_THIRDPARTY_SRC_NAME = $${NADIR_NAME}
NADIR_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${NADIR_THIRDPARTY_SRC_GROUP}/$${NADIR_THIRDPARTY_SRC_NAME} 
NADIR_PKG = $${OTHER_PKG}/$${NADIR_PKG_DIR}
NADIR_PRJ = $${OTHER_PRJ}/$${NADIR_PKG_DIR}
#NADIR_SRC = $${NADIR_THIRDPARTY_SRC_DIR}
#NADIR_SRC = $${NADIR_THIRDPARTY_PKG}/$${NADIR_SOURCE}
#NADIR_SRC = $${NADIR_THIRDPARTY_PRJ}/$${NADIR_SOURCE}
#NADIR_SRC = $${NADIR_PKG}/$${NADIR_SOURCE}
NADIR_SRC = $${NADIR_PRJ}/$${NADIR_SOURCE}

# nadir INCLUDEPATH
#
#nadir_INCLUDEPATH += \
#$${NADIR_HOME_BUILD_INCLUDE} \

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

# nadir DEFINES
#
nadir_DEFINES += \

########################################################################
# xosnadir

# xosnadir INCLUDEPATH
#
xosnadir_INCLUDEPATH += \
$${nadir_INCLUDEPATH} \

# xosnadir DEFINES
#
xosnadir_DEFINES += \
$${nadir_DEFINES} \
NO_USE_NADIR_BASE \
NO_USE_XOS_LOGGER_INTERFACE \

########################################################################
# medusa
MEDUSA_VERSION_MAJOR = 0
MEDUSA_VERSION_MINOR = 0
MEDUSA_VERSION_RELEASE = 0
MEDUSA_VERSION = $${MEDUSA_VERSION_MAJOR}.$${MEDUSA_VERSION_MINOR}.$${MEDUSA_VERSION_RELEASE}
MEDUSA_NAME = medusa
MEDUSA_GROUP = $${MEDUSA_NAME}
MEDUSA_SOURCE = src
MEDUSA_DIR = $${MEDUSA_GROUP}/$${MEDUSA_NAME}-$${MEDUSA_VERSION}
MEDUSA_PKG_DIR = $${MEDUSA_NAME}
MEDUSA_HOME_BUILD = $${HOME}/build/$${MEDUSA_NAME}
MEDUSA_HOME_BUILD_INCLUDE = $${MEDUSA_HOME_BUILD}/include
MEDUSA_HOME_BUILD_LIB = $${MEDUSA_HOME_BUILD}/lib
MEDUSA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${MEDUSA_DIR}
MEDUSA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${MEDUSA_DIR}
MEDUSA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${MEDUSA_PKG_DIR}
MEDUSA_THIRDPARTY_SRC_GROUP = $${MEDUSA_NAME}
MEDUSA_THIRDPARTY_SRC_NAME = $${MEDUSA_NAME}
MEDUSA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${MEDUSA_THIRDPARTY_SRC_GROUP}/$${MEDUSA_THIRDPARTY_SRC_NAME} 
MEDUSA_PKG = $${OTHER_PKG}/$${MEDUSA_PKG_DIR}
MEDUSA_PRJ = $${OTHER_PRJ}/$${MEDUSA_PKG_DIR}
#MEDUSA_SRC = $${MEDUSA_THIRDPARTY_SRC_DIR}
#MEDUSA_SRC = $${MEDUSA_THIRDPARTY_PKG}/$${MEDUSA_SOURCE}
#MEDUSA_SRC = $${MEDUSA_THIRDPARTY_PRJ}/$${MEDUSA_SOURCE}
#MEDUSA_SRC = $${MEDUSA_PKG}/$${MEDUSA_SOURCE}
MEDUSA_SRC = $${MEDUSA_PRJ}/$${MEDUSA_SOURCE}

# medusa INCLUDEPATH
#
#medusa_INCLUDEPATH += \
#$${MEDUSA_HOME_BUILD_INCLUDE} \

medusa_INCLUDEPATH += \
$${MEDUSA_SRC} \

# medusa DEFINES
#
medusa_DEFINES += \

########################################################################
# coral
CORAL_VERSION_MAJOR = 0
CORAL_VERSION_MINOR = 0
CORAL_VERSION_RELEASE = 0
CORAL_VERSION = $${CORAL_VERSION_MAJOR}.$${CORAL_VERSION_MINOR}.$${CORAL_VERSION_RELEASE}
CORAL_NAME = coral
CORAL_GROUP = $${CORAL_NAME}
CORAL_SOURCE = src
CORAL_DIR = $${CORAL_GROUP}/$${CORAL_NAME}-$${CORAL_VERSION}
CORAL_PKG_DIR = $${CORAL_NAME}
CORAL_HOME_BUILD = $${HOME}/build/$${CORAL_NAME}
CORAL_HOME_BUILD_INCLUDE = $${CORAL_HOME_BUILD}/include
CORAL_HOME_BUILD_LIB = $${CORAL_HOME_BUILD}/lib
CORAL_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${CORAL_DIR}
CORAL_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${CORAL_DIR}
CORAL_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${CORAL_PKG_DIR}
CORAL_THIRDPARTY_SRC_GROUP = $${CORAL_NAME}
CORAL_THIRDPARTY_SRC_NAME = $${CORAL_NAME}
CORAL_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${CORAL_THIRDPARTY_SRC_GROUP}/$${CORAL_THIRDPARTY_SRC_NAME} 
CORAL_PKG = $${OTHER_PKG}/$${CORAL_PKG_DIR}
CORAL_PRJ = $${OTHER_PRJ}/$${CORAL_PKG_DIR}
#CORAL_SRC = $${CORAL_THIRDPARTY_SRC_DIR}
#CORAL_SRC = $${CORAL_THIRDPARTY_PKG}/$${CORAL_SOURCE}
#CORAL_SRC = $${CORAL_THIRDPARTY_PRJ}/$${CORAL_SOURCE}
#CORAL_SRC = $${CORAL_PKG}/$${CORAL_SOURCE}
CORAL_SRC = $${CORAL_PRJ}/$${CORAL_SOURCE}

# coral INCLUDEPATH
#
#coral_INCLUDEPATH += \
#$${CORAL_HOME_BUILD_INCLUDE} \

coral_INCLUDEPATH += \
$${CORAL_SRC} \

# coral DEFINES
#
coral_DEFINES += \



########################################################################
# texta
FRAMEWORK_NAME = texta
FRAMEWORK_SOURCE = src

TEXTA_PKG = ../../../../..
TEXTA_BLD = ../..

TEXTA_PRJ = $${TEXTA_PKG}
TEXTA_BIN = $${TEXTA_BLD}/bin
TEXTA_LIB = $${TEXTA_BLD}/lib
TEXTA_SRC = $${TEXTA_PKG}/$${FRAMEWORK_SOURCE}

# texta BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
texta_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
texta_DEFINES += RELEASE_BUILD
}

# texta INCLUDEPATH
#
texta_INCLUDEPATH += \
$${TEXTA_SRC} \
$${coral_INCLUDEPATH} \
$${medusa_INCLUDEPATH} \
$${xosnadir_INCLUDEPATH} \
$${build_texta_INCLUDEPATH} \

# texta DEFINES
#
texta_DEFINES += \
$${xosnadir_DEFINES} \
$${medusa_DEFINES} \
$${coral_DEFINES} \
$${build_texta_DEFINES} \

# texta LIBS
#
texta_LIBS += \
-L$${TEXTA_LIB}/lib$${FRAMEWORK_NAME} \
-l$${FRAMEWORK_NAME} \

# texta function SOURCES
#
texta_function_SOURCES += \
$${TEXTA_SRC}/texta/t/file_functions.cpp \
$${TEXTA_SRC}/texta/t/string_functions.cpp \
$${TEXTA_SRC}/texta/t/time_functions.cpp \
$${TEXTA_SRC}/texta/t/logical_functions.cpp \
$${TEXTA_SRC}/texta/t/conditional_functions.cpp \
$${TEXTA_SRC}/texta/t/block_functions.cpp \
$${TEXTA_SRC}/texta/t/base_functions.cpp \
$${TEXTA_SRC}/texta/t/functions.cpp \
