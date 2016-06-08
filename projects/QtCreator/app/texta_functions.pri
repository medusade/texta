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
#   File: texta_functions.pri
#
# Author: $author$
#   Date: 6/4/2016
########################################################################

########################################################################
# texta
texta_SOURCES += \
$${TEXTA_SRC}/texta/t/file_functions.cpp \
$${TEXTA_SRC}/texta/t/string_functions.cpp \
$${TEXTA_SRC}/texta/t/time_functions.cpp \
$${TEXTA_SRC}/texta/t/logical_functions.cpp \
$${TEXTA_SRC}/texta/t/conditional_functions.cpp \
$${TEXTA_SRC}/texta/t/block_functions.cpp \
$${TEXTA_SRC}/texta/t/base_functions.cpp \
$${TEXTA_SRC}/texta/t/functions.cpp \
