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
#   File: libevup.pri
#
# Author: $author$
#   Date: 3/6/2023
#
# generic QtCreator project file for texta framework evup static library libevup
########################################################################

########################################################################
# libevup
XOS_LIB_EVUP_VERSION_BUILD_DATE = 3/6/2023 #$$system(~/bin/utility/tdate)

# libevup TARGET
#
libevup_TARGET = evup
libevup_TEMPLATE = lib
libevup_CONFIG += staticlib

# libevup INCLUDEPATH
#
libevup_INCLUDEPATH += \
$${evup_INCLUDEPATH} \

# libevup DEFINES
#
libevup_DEFINES += \
$${evup_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_EVUP_VERSION_BUILD_DATE=$${XOS_LIB_EVUP_VERSION_BUILD_DATE} \

########################################################################
# libevup OBJECTIVE_HEADERS
#
#libevup_OBJECTIVE_HEADERS += \
#$${EVUP_SRC}/xos/lib/evup/version.hh \

# libevup OBJECTIVE_SOURCES
#
#libevup_OBJECTIVE_SOURCES += \
#$${EVUP_SRC}/xos/lib/evup/version.mm \

########################################################################
# libevup HEADERS
#
libevup_HEADERS += \
$${EVUP_SRC}/os/evdebug.h \
$${EVUP_SRC}/os/cevmutex.hpp \
$${EVUP_SRC}/os/cevsemaphore.hpp \
$${EVUP_SRC}/os/cevdatetime.hpp \
$${EVUP_SRC}/os/cevsystemtime.hpp \
$${EVUP_SRC}/os/cevsystemdate.hpp \
$${EVUP_SRC}/os/cevcharfile.hpp \
$${EVUP_SRC}/os/evfiletime.hpp \
$${EVUP_SRC}/os/cevfiletime.hpp \
$${EVUP_SRC}/os/cevfilepath.hpp \
$${EVUP_SRC}/os/cevfilepathwriter.hpp \
$${EVUP_SRC}/os/cevfilepathstring.hpp \
$${EVUP_SRC}/os/cevfilesystementry.hpp \
$${EVUP_SRC}/os/cevfilesystementryfound.hpp \
$${EVUP_SRC}/os/cevfiledirectoryentry.hpp \
$${EVUP_SRC}/os/cevfiledirectory.hpp \
$${EVUP_SRC}/os/cevuid.hpp \
$${EVUP_SRC}/os/cevgid.hpp \
$${EVUP_SRC}/os/cevpid.hpp \
$${EVUP_SRC}/os/cevpasswd.hpp \
$${EVUP_SRC}/os/cevmainarg.hpp \
$${EVUP_SRC}/os/cevmain.hpp \
$${EVUP_SRC}/os/cevsocket.hpp \

# libevup SOURCES
#
libevup_SOURCES += \
$${EVUP_SRC}/os/evdebug.c \
$${EVUP_SRC}/os/cevmutex.cpp \
$${EVUP_SRC}/os/cevsemaphore.cpp \
$${EVUP_SRC}/os/cevdatetime.cpp \
$${EVUP_SRC}/os/cevsystemtime.cpp \
$${EVUP_SRC}/os/cevsystemdate.cpp \
$${EVUP_SRC}/os/cevcharfile.cpp \
$${EVUP_SRC}/os/evfiletime.cpp \
$${EVUP_SRC}/os/cevfiletime.cpp \
$${EVUP_SRC}/os/cevfilepath.cpp \
$${EVUP_SRC}/os/cevfilepathwriter.cpp \
$${EVUP_SRC}/os/cevfilepathstring.cpp \
$${EVUP_SRC}/os/cevfilesystementry.cpp \
$${EVUP_SRC}/os/cevfilesystementryfound.cpp \
$${EVUP_SRC}/os/cevfiledirectoryentry.cpp \
$${EVUP_SRC}/os/cevfiledirectory.cpp \
$${EVUP_SRC}/os/cevuid.cpp \
$${EVUP_SRC}/os/cevgid.cpp \
$${EVUP_SRC}/os/cevpid.cpp \
$${EVUP_SRC}/os/cevpasswd.cpp \
$${EVUP_SRC}/os/cevmainarg.cpp \
$${EVUP_SRC}/os/cevmain.cpp \
$${EVUP_SRC}/os/cevsocket.cpp \

########################################################################
