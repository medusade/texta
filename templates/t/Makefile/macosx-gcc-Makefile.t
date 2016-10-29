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
%#   File: macosx-gcc-Makefile.t
%#
%# Author: $author$
%#   Date: 8/28/2016
%########################################################################
%with(%
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
# MacOSX Gcc Makefile
########################################################################
PKG = ../../../..

PRJ = projects/macosx/Makefile/Gcc
SRC = src

include $(PKG)/$(PRJ)/Makedefines

#
# Source subdirs
#
#SRC_DIRS = \
#$(PKG)/$(PRJ)/somedir \
#
SRC_DIRS = \
$(PKG)/$(PRJ)/lib \
$(PKG)/$(PRJ)/app \

include $(PKG)/$(PRJ)/Makedirs
)%)%