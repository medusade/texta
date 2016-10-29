%########################################################################
%# Copyright (c) 1988-2016 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: macosx-gcc-app-Makefile.t
%#
%# Author: $author$
%#   Date: 8/28/2016
%########################################################################
%with(%
%target,%(%else-then(%target%,%(Target)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%file,%(%else-then(%file%,%(Makefile)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%author,%(%else-then(%author%,%($author$)%)%)%,%
%Author,%(%else-then(%Author%,%(%author%)%)%)%,%
%AUTHOR,%(%else-then(%AUTHOR%,%(%toupper(%Author%)%)%)%)%,%
%author,%(%else-then(%_Author%,%(%tolower(%Author%)%)%)%)%,%
%organization,%(%else-then(%organization%,%($organization$)%)%)%,%
%Organization,%(%else-then(%Organization%,%(%organization%)%)%)%,%
%ORGANIZATION,%(%else-then(%ORGANIZATION%,%(%toupper(%Organization%)%)%)%)%,%
%organization,%(%else-then(%_Organization%,%(%tolower(%Organization%)%)%)%)%,%
%copyright,%(%else-then(%copyright%,%(Copyright (c) 1988-%year()% %Organization%)%)%)%,%
%Copyright,%(%else-then(%Copyright%,%(%copyright%)%)%)%,%
%COPYRIGHT,%(%else-then(%COPYRIGHT%,%(%toupper(%Copyright%)%)%)%)%,%
%copyright,%(%else-then(%_Copyright%,%(%tolower(%Copyright%)%)%)%)%,%
%disclaimer,%(%else-then(%disclaimer%,%(This software is provided by the author and contributors ``as is''
and any express or implied warranties, including, but not limited to,
the implied warranties of merchantability and fitness for a particular
purpose are disclaimed. In no event shall the author or contributors
be liable for any direct, indirect, incidental, special, exemplary,
or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or
business interruption) however caused and on any theory of liability,
whether in contract, strict liability, or tort (including negligence
or otherwise) arising in any way out of the use of this software,
even if advised of the possibility of such damage.)%)%)%,%
%Disclaimer,%(%else-then(%Disclaimer%,%(%disclaimer%)%)%)%,%
%DISCLAIMER,%(%else-then(%DISCLAIMER%,%(%toupper(%Disclaimer%)%)%)%)%,%
%disclaimer,%(%else-then(%_Disclaimer%,%(%tolower(%Disclaimer%)%)%)%)%,%
%%(########################################################################
%if(%Copyright%,%(# %Copyright%
#
)%)%%else-no(%Disclaimer%,%(%parse(%Disclaimer%,%(
)%,,,,%(# %ln%
)%,ln)%#
)%)%%if(%File%,%(#   File: %File%
#
)%)%%if(%Author%,%(# Author: %Author%
)%)%#   Date: %date()%
#
# MacOSX Gcc Makefile for application %Target%
########################################################################
PKG = ../../../../../..

#MAK = projects/Makefile/Gcc
PRJ = projects/macosx/Makefile/Gcc
SRC = src

#include $(PKG)/$(MAK)/Makedefines
include $(PKG)/$(PRJ)/Makedefines
include $(PKG)/$(MAK)/Makefile
#include $(PKG)/$(MAK)/app/%Target%/Makefile

#
# target
#
EXETARGET = %Target%

#
# user defines
#
USRDEFINES = \

#
# user includes
#
USRINCLUDES = \

#
# user libdirs
#
USRLIBDIRS = \

#
# user c++ flags
#
USRCXXFLAGS = \

#
# user c flags
#
USRCFLAGS = \

#
# user ld flags
#
USRLDFLAGS = \

#
# Executable C sources
#
EXE_C_SOURCES = \

#
# Executable C++ .cc sources
#
EXE_CC_SOURCES = \

#
# Executable C++ .cxx sources
#
EXE_CXX_SOURCES = \

#
# Executable C++ .cpp sources
#
EXE_CPP_SOURCES = \

#
# Executable Objective C .m sources
#
EXE_M_SOURCES = \

#
# Executable Objective C++ .mm sources
#
EXE_MM_SOURCES = \

#
# Executable libs
#
#LIBS = \
#-lsomelib
#
LIBS = \

#
# Executable depends
#
#EXEDEP = \
#$(PKG)/$(BLD)/libsomelib \
#
EXEDEP = \

#
# Executable depend dirs
#
#EXEDEP_DIRS = \
#../libsomelib
#
EXEDEP_DIRS = \

include $(PKG)/$(PRJ)/Makerules

#
# Executable depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#
)%)%