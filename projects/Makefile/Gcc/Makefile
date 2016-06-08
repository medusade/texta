########################################################################
# Copyright (c) 1988-2014 $organization$
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
#   Date: 11/22/2014
#
# Common Gcc Makefile for texta
########################################################################
TEXTA_PKG = ${PKG}
TEXTA_SRC = ${TEXTA_PKG}/src
TEXTA_BLD = ${TEXTA_PKG}/${BLD}/${BUILD_TYPE}
TEXTA_LIB = ${TEXTA_BLD}/lib
TEXTA_BIN = ${TEXTA_BLD}/bin

########################################################################
# nadir
NADIR_PKG = ${TEXTA_PKG}/../nadir
NADIR_SRC = ${NADIR_PKG}/src
NADIR_BLD = ${NADIR_PKG}/${BLD}/${BUILD_TYPE}
NADIR_LIB = ${NADIR_BLD}/lib
NADIR_BIN = ${NADIR_BLD}/bin

########################################################################
# coral
CORAL_PKG = ${TEXTA_PKG}/../coral
CORAL_SRC = ${CORAL_PKG}/src
CORAL_BLD = ${CORAL_PKG}/${BLD}/${BUILD_TYPE}
CORAL_LIB = ${CORAL_BLD}/lib
CORAL_BIN = ${CORAL_BLD}/bin

########################################################################
# medusa
MEDUSA_PKG = ${TEXTA_PKG}/../medusa
MEDUSA_SRC = ${MEDUSA_PKG}/src
MEDUSA_BLD = ${MEDUSA_PKG}/${BLD}/${BUILD_TYPE}
MEDUSA_LIB = ${MEDUSA_BLD}/lib
MEDUSA_BIN = ${MEDUSA_BLD}/bin

########################################################################
# texta
texta_USRDEFINES += \

texta_USRINCLUDES += \
-I${TEXTA_SRC} \
-I${MEDUSA_SRC} \
-I${CORAL_SRC} \
-I${NADIR_SRC} \

texta_USRCXXFLAGS += \
-std=c++0x

texta_USRLIBDIRS += \
-L${NADIR_LIB} \

texta_LIBS += \
-lxosnadir \
