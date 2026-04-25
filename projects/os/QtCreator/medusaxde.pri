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
#   File: medusaxde.pri
#
# Author: $author$
#   Date: 3/6/2023
#
# os specific QtCreator project file for texta framework medusaxde
########################################################################
# Depends: xde

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
MEDUSAXDE_OS = macosx
} else {
contains(UNAME,Linux) {
MEDUSAXDE_OS = linux
} else {
MEDUSAXDE_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,MEDUSAXDE_OS) {
MEDUSAXDE_BUILD = $${MEDUSAXDE_OS}
} else {
MEDUSAXDE_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,MEDUSAXDE_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(MEDUSAXDE_OS,macosx) {
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
contains(MEDUSAXDE_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(MEDUSAXDE_OS,windows) {
} else {
} # contains(MEDUSAXDE_OS,windows)
} # contains(MEDUSAXDE_OS,linux)
} # contains(MEDUSAXDE_OS,macosx)

########################################################################
# medusaxde

# medusaxde INCLUDEPATH
#
medusaxde_INCLUDEPATH += \

# medusaxde DEFINES
#
medusaxde_DEFINES += \

# medusaxde os LIBS
#
contains(MEDUSAXDE_OS,macosx|linux) {
medusaxde_os_LIBS += \
-lpthread \
-ldl
} else {
} # contains(MEDUSAXDE_OS,macosx|linux)

contains(MEDUSAXDE_OS,linux) {
medusaxde_os_LIBS += \
-lrt
} else {
} # contains(MEDUSAXDE_OS,linux)


# medusaxde base LIBS
#
medusaxde_base_LIBS += \


# medusaxde LIBS
#
medusaxde_LIBS += \
$${medusaxde_base_LIBS} \
$${build_medusaxde_LIBS} \
$${medusaxde_os_LIBS} \

########################################################################
