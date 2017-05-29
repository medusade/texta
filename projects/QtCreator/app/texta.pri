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
# nadir
texta_HEADERS += \
$${NADIR_SRC}/xos/fs/path.hpp \
$${NADIR_SRC}/xos/io/file/reader.hpp \
$${NADIR_SRC}/xos/base/redblack/tree.hpp \
$${NADIR_SRC}/xos/base/redblack/branch.hpp \
$${NADIR_SRC}/xos/base/avl/tree.hpp \
$${NADIR_SRC}/xos/base/avl/branch.hpp \
$${NADIR_SRC}/xos/base/binary/tree.hpp \
$${NADIR_SRC}/xos/base/binary/branch.hpp \
$${NADIR_SRC}/xos/base/tree.hpp \
$${NADIR_SRC}/xos/base/branch.hpp \
$${NADIR_SRC}/xos/base/leaf.hpp \
$${NADIR_SRC}/xos/base/list.hpp \
$${NADIR_SRC}/xos/base/item.hpp \
$${NADIR_SRC}/xos/base/to_string.hpp \

texta_SOURCES += \
$${NADIR_SRC}/xos/fs/path.cpp \
$${NADIR_SRC}/xos/base/redblack/tree.cpp \
$${NADIR_SRC}/xos/base/redblack/branch.cpp \
$${NADIR_SRC}/xos/base/leaf.cpp \
$${NADIR_SRC}/xos/base/list.cpp \
$${NADIR_SRC}/xos/base/item.cpp \
$${NADIR_SRC}/xos/base/to_string.cpp \

_texta_SOURCES += \
$${NADIR_SRC}/xos/base/avl/tree.cpp \
$${NADIR_SRC}/xos/base/avl/branch.cpp \
$${NADIR_SRC}/xos/base/binary/tree.cpp \
$${NADIR_SRC}/xos/base/binary/branch.cpp \

########################################################################
# texta
texta_HEADERS += \
$${TEXTA_SRC}/texta/xos/base/main_main.hpp \
$${TEXTA_SRC}/texta/xos/base/main.hpp \
$${TEXTA_SRC}/texta/xos/base/logger.hpp \
$${TEXTA_SRC}/texta/xos/base/base.hpp \

texta_SOURCES += \

_texta_HEADERS += \
$${TEXTA_SRC}/texta/xos/base/main_main.cpp \
$${TEXTA_SRC}/texta/xos/base/main.cpp \
$${TEXTA_SRC}/texta/xos/base/logger.cpp \
$${TEXTA_SRC}/texta/xos/base/base.cpp \

########################################################################
# texta
texta_HEADERS += \
$${TEXTA_SRC}/texta/app/console/texta/main.hpp \
$${TEXTA_SRC}/texta/console/main.hpp \
$${TEXTA_SRC}/texta/console/main_main.hpp \
$${TEXTA_SRC}/texta/console/main_opt.hpp \
$${TEXTA_SRC}/texta/t/processor.hpp \
$${TEXTA_SRC}/texta/t/functions.hpp \
$${TEXTA_SRC}/texta/t/function_extend.hpp \
$${TEXTA_SRC}/texta/t/function_named.hpp \
$${TEXTA_SRC}/texta/t/function_tree.hpp \
$${TEXTA_SRC}/texta/t/function_branch.hpp \
$${TEXTA_SRC}/texta/t/function_list.hpp \
$${TEXTA_SRC}/texta/t/function_item.hpp \
$${TEXTA_SRC}/texta/t/function.hpp \
$${TEXTA_SRC}/texta/t/function_argument.hpp \
$${TEXTA_SRC}/texta/t/function_argument_list.hpp \
$${TEXTA_SRC}/texta/t/function_argument_item.hpp \
$${TEXTA_SRC}/texta/t/function_parameter.hpp \
$${TEXTA_SRC}/texta/t/variable.hpp \
$${TEXTA_SRC}/texta/t/variable_tree.hpp \
$${TEXTA_SRC}/texta/t/variable_branch.hpp \
$${TEXTA_SRC}/texta/t/variable_leaf.hpp \
$${TEXTA_SRC}/texta/t/variable_list.hpp \
$${TEXTA_SRC}/texta/t/variable_item.hpp \
$${TEXTA_SRC}/texta/t/value.hpp \
$${TEXTA_SRC}/texta/t/value_list.hpp \
$${TEXTA_SRC}/texta/t/value_item.hpp \
$${TEXTA_SRC}/texta/t/t.hpp \
$${TEXTA_SRC}/texta/io/logger.hpp \
$${TEXTA_SRC}/texta/io/writer.hpp \
$${TEXTA_SRC}/texta/io/reader.hpp \
$${TEXTA_SRC}/texta/base/base.hpp \
$${TEXTA_SRC}/texta/base/logger.hpp \
$${TEXTA_SRC}/texta/base/main.hpp \
$${TEXTA_SRC}/texta/base/main_main.hpp \

texta_SOURCES += \
$${TEXTA_SRC}/texta/app/console/texta/main.cpp \
$${TEXTA_SRC}/texta/console/main_main.cpp \
$${TEXTA_SRC}/texta/console/main_opt.cpp \
$${TEXTA_SRC}/texta/t/processor.cpp \
$${TEXTA_SRC}/texta/t/function_extend.cpp \
$${TEXTA_SRC}/texta/t/function_named.cpp \
$${TEXTA_SRC}/texta/t/function_tree.cpp \
$${TEXTA_SRC}/texta/t/function_branch.cpp \
$${TEXTA_SRC}/texta/t/function_list.cpp \
$${TEXTA_SRC}/texta/t/function_item.cpp \
$${TEXTA_SRC}/texta/t/function.cpp \
$${TEXTA_SRC}/texta/t/function_argument.cpp \
$${TEXTA_SRC}/texta/t/function_argument_list.cpp \
$${TEXTA_SRC}/texta/t/function_argument_item.cpp \
$${TEXTA_SRC}/texta/t/function_parameter.cpp \
$${TEXTA_SRC}/texta/t/variable.cpp \
$${TEXTA_SRC}/texta/t/variable_tree.cpp \
$${TEXTA_SRC}/texta/t/variable_branch.cpp \
$${TEXTA_SRC}/texta/t/variable_leaf.cpp \
$${TEXTA_SRC}/texta/t/variable_list.cpp \
$${TEXTA_SRC}/texta/t/variable_item.cpp \
$${TEXTA_SRC}/texta/t/value.cpp \
$${TEXTA_SRC}/texta/t/value_list.cpp \
$${TEXTA_SRC}/texta/t/value_item.cpp \
$${TEXTA_SRC}/texta/t/t.cpp \
$${TEXTA_SRC}/texta/io/logger.cpp \
$${TEXTA_SRC}/texta/io/writer.cpp \
$${TEXTA_SRC}/texta/io/reader.cpp \

########################################################################
texta_LIBS += \
$${texta_LIBS} \

