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
#   File: Makefile
#
# Author: $author$
#   Date: 11/12/2018
#
# generic Gcc Makefile for texta
########################################################################

OTHER_VERSION_PKG = ${PKG}
OTHER_DEPENDS_PKG = ${PKG}/..
OTHER_THIRDPARTY_NAME = thirdparty
OTHER_THIRDPARTY_VERSION_PKG = ${OTHER_VERSION_PKG}/${OTHER_THIRDPARTY_NAME}

TEXTA_PKG = ${PKG}
TEXTA_SRC = ${TEXTA_PKG}/src
TEXTA_BLD = ${TEXTA_PKG}/${BLD}/${BUILD_TYPE}
TEXTA_LIB = ${TEXTA_BLD}/lib
TEXTA_BIN = ${TEXTA_BLD}/bin

########################################################################
# rostra
ROSTRA_VERSION_MAJOR = 0
ROSTRA_VERSION_MINOR = 0
ROSTRA_VERSION_RELEASE = 0
ROSTRA_VERSION = ${ROSTRA_VERSION_MAJOR}.${ROSTRA_VERSION_MINOR}.${ROSTRA_VERSION_RELEASE}
ROSTRA_NAME = rostra
ROSTRA_GROUP = ${ROSTRA_NAME}
ROSTRA_VERSION_DIR = ${ROSTRA_GROUP}/${ROSTRA_NAME}-${ROSTRA_VERSION}
ROSTRA_DEPENDS_DIR = ${ROSTRA_NAME}

#ROSTRA_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${ROSTRA_VERSION_DIR}
#ROSTRA_PKG = ${OTHER_VERSION_PKG}/${ROSTRA_VERSION_DIR}
ROSTRA_PKG = ${OTHER_DEPENDS_PKG}/${ROSTRA_DEPENDS_DIR}
#ROSTRA_SRC = ${ROSTRA_PKG}/src/${BN_GROUP}/${BN_NAME}
ROSTRA_SRC = ${ROSTRA_PKG}/src
ROSTRA_BLD = ${ROSTRA_PKG}/${BLD}/${BUILD_TYPE}
ROSTRA_LIB = ${ROSTRA_BLD}/lib
ROSTRA_BIN = ${ROSTRA_BLD}/bin

# rostra USRDEFINES
#
rostra_USRDEFINES += \

# rostra USRINCLUDES
#
rostra_USRINCLUDES += \
-I${ROSTRA_SRC} \

# rostra USRCXXFLAGS
#
rostra_USRCXXFLAGS += \

# rostra USRLIBDIRS
#
rostra_USRLIBDIRS += \
-L${ROSTRA_LIB} \

# rostra LIBS
#
rostra_LIBS += \
-lrostra \

# rostra FRAMEWORKS
#
rostra_FRAMEWORKS += \

########################################################################
# nadir
NADIR_VERSION_MAJOR = 0
NADIR_VERSION_MINOR = 0
NADIR_VERSION_RELEASE = 0
NADIR_VERSION = ${NADIR_VERSION_MAJOR}.${NADIR_VERSION_MINOR}.${NADIR_VERSION_RELEASE}
NADIR_NAME = nadir
NADIR_GROUP = ${NADIR_NAME}
NADIR_VERSION_DIR = ${NADIR_GROUP}/${NADIR_NAME}-${NADIR_VERSION}
NADIR_DEPENDS_DIR = ${NADIR_NAME}

#NADIR_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${NADIR_VERSION_DIR}
#NADIR_PKG = ${OTHER_VERSION_PKG}/${NADIR_VERSION_DIR}
NADIR_PKG = ${OTHER_DEPENDS_PKG}/${NADIR_DEPENDS_DIR}
#NADIR_SRC = ${NADIR_PKG}/src/${BN_GROUP}/${BN_NAME}
NADIR_SRC = ${NADIR_PKG}/src
NADIR_BLD = ${NADIR_PKG}/${BLD}/${BUILD_TYPE}
NADIR_LIB = ${NADIR_BLD}/lib
NADIR_BIN = ${NADIR_BLD}/bin

# nadir USRDEFINES
#
nadir_USRDEFINES += \

# nadir USRINCLUDES
#
nadir_USRINCLUDES += \
-I${NADIR_SRC} \

# nadir USRCXXFLAGS
#
nadir_USRCXXFLAGS += \

# nadir USRLIBDIRS
#
nadir_USRLIBDIRS += \
-L${NADIR_LIB} \

# nadir LIBS
#
nadir_LIBS += \
-lnadir \

# nadir FRAMEWORKS
#
nadir_FRAMEWORKS += \

########################################################################
# xosnadir

# xosnadir USRDEFINES
#
xosnadir_USRDEFINES += \
${nadir_USRDEFINES} \
-DNO_USE_NADIR_BASE \
-DNO_USE_XOS_LOGGER_INTERFACE \

# xosnadir USRINCLUDES
#
xosnadir_USRINCLUDES += \
${nadir_USRINCLUDES} \

# xosnadir USRCXXFLAGS
#
xosnadir_USRCXXFLAGS += \
${nadir_USRCXXFLAGS} \

# xosnadir USRLIBDIRS
#
xosnadir_USRLIBDIRS += \
${nadir_USRLIBDIRS} \

# xosnadir LIBS
#
xosnadir_LIBS += \
-lxosnadir \

# xosnadir FRAMEWORKS
#
xosnadir_FRAMEWORKS += \
${nadir FRAMEWORKS} \

########################################################################
# medusa
MEDUSA_VERSION_MAJOR = 0
MEDUSA_VERSION_MINOR = 0
MEDUSA_VERSION_RELEASE = 0
MEDUSA_VERSION = ${MEDUSA_VERSION_MAJOR}.${MEDUSA_VERSION_MINOR}.${MEDUSA_VERSION_RELEASE}
MEDUSA_NAME = medusa
MEDUSA_GROUP = ${MEDUSA_NAME}
MEDUSA_VERSION_DIR = ${MEDUSA_GROUP}/${MEDUSA_NAME}-${MEDUSA_VERSION}
MEDUSA_DEPENDS_DIR = ${MEDUSA_NAME}

#MEDUSA_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${MEDUSA_VERSION_DIR}
#MEDUSA_PKG = ${OTHER_VERSION_PKG}/${MEDUSA_VERSION_DIR}
MEDUSA_PKG = ${OTHER_DEPENDS_PKG}/${MEDUSA_DEPENDS_DIR}
#MEDUSA_SRC = ${MEDUSA_PKG}/src/${BN_GROUP}/${BN_NAME}
MEDUSA_SRC = ${MEDUSA_PKG}/src
MEDUSA_BLD = ${MEDUSA_PKG}/${BLD}/${BUILD_TYPE}
MEDUSA_LIB = ${MEDUSA_BLD}/lib
MEDUSA_BIN = ${MEDUSA_BLD}/bin

# medusa USRDEFINES
#
medusa_USRDEFINES += \

# medusa USRINCLUDES
#
medusa_USRINCLUDES += \
-I${MEDUSA_SRC} \

# medusa USRCXXFLAGS
#
medusa_USRCXXFLAGS += \

# medusa USRLIBDIRS
#
medusa_USRLIBDIRS += \
-L${MEDUSA_LIB} \

# medusa LIBS
#
medusa_LIBS += \
-lmedusa \

# medusa FRAMEWORKS
#
medusa_FRAMEWORKS += \

########################################################################
# coral
CORAL_VERSION_MAJOR = 0
CORAL_VERSION_MINOR = 0
CORAL_VERSION_RELEASE = 0
CORAL_VERSION = ${CORAL_VERSION_MAJOR}.${CORAL_VERSION_MINOR}.${CORAL_VERSION_RELEASE}
CORAL_NAME = coral
CORAL_GROUP = ${CORAL_NAME}
CORAL_VERSION_DIR = ${CORAL_GROUP}/${CORAL_NAME}-${CORAL_VERSION}
CORAL_DEPENDS_DIR = ${CORAL_NAME}

#CORAL_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${CORAL_VERSION_DIR}
#CORAL_PKG = ${OTHER_VERSION_PKG}/${CORAL_VERSION_DIR}
CORAL_PKG = ${OTHER_DEPENDS_PKG}/${CORAL_DEPENDS_DIR}
#CORAL_SRC = ${CORAL_PKG}/src/${BN_GROUP}/${BN_NAME}
CORAL_SRC = ${CORAL_PKG}/src
CORAL_BLD = ${CORAL_PKG}/${BLD}/${BUILD_TYPE}
CORAL_LIB = ${CORAL_BLD}/lib
CORAL_BIN = ${CORAL_BLD}/bin

# coral USRDEFINES
#
coral_USRDEFINES += \

# coral USRINCLUDES
#
coral_USRINCLUDES += \
-I${CORAL_SRC} \

# coral USRCXXFLAGS
#
coral_USRCXXFLAGS += \

# coral USRLIBDIRS
#
coral_USRLIBDIRS += \
-L${CORAL_LIB} \

# coral LIBS
#
coral_LIBS += \
-lcoral \

# coral FRAMEWORKS
#
coral_FRAMEWORKS += \


########################################################################
# texta

# texta USRDEFINES
#
texta_USRDEFINES += \
${rostra_USRDEFINES} \
${xosnadir_USRDEFINES} \
${medusa_USRDEFINES} \
${coral_USRDEFINES} \
${build_texta_USRDEFINES} \

# texta USRINCLUDES
#
texta_USRINCLUDES += \
-I${TEXTA_SRC} \
${coral_USRINCLUDES} \
${medusa_USRINCLUDES} \
${xosnadir_USRINCLUDES} \
${rostra_USRINCLUDES} \
${build_texta_USRINCLUDES} \

# texta USRCXXFLAGS
#
texta_USRCXXFLAGS += \
${rostra_USRCXXFLAGS} \
${xosnadir_USRCXXFLAGS} \
${medusa_USRCXXFLAGS} \
${coral_USRCXXFLAGS} \
${build_texta_USRCXXFLAGS} \

# texta USRLIBDIRS
#
texta_USRLIBDIRS += \
-L${TEXTA_LIB} \
${coral_USRLIBDIRS} \
${medusa_USRLIBDIRS} \
${xosnadir_USRLIBDIRS} \
${rostra_USRLIBDIRS} \
${build_texta_USRLIBDIRS} \

# texta LIBS
#
texta_LIBS += \
-ltexta \
${coral_LIBS} \
${medusa_LIBS} \
${xosnadir_LIBS} \
${rostra_LIBS} \
${build_texta_LIBS} \

#
# Function .cpp sources
#
texta_function_CPP_SOURCES += \
${TEXTA_SRC}/texta/t/file_functions.cpp \
${TEXTA_SRC}/texta/t/string_functions.cpp \
${TEXTA_SRC}/texta/t/time_functions.cpp \
${TEXTA_SRC}/texta/t/logical_functions.cpp \
${TEXTA_SRC}/texta/t/conditional_functions.cpp \
${TEXTA_SRC}/texta/t/block_functions.cpp \
${TEXTA_SRC}/texta/t/base_functions.cpp \
${TEXTA_SRC}/texta/t/functions.cpp \

########################################################################

