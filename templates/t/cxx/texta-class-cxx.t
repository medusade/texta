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
%#   File: texta-class-cxx.t
%#
%# Author: $author$
%#   Date: 5/21/2016
%########################################################################
%with(%
%class,%(%else-then(%class%,%(Class)%)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%implements,%(%else-then(%implements%,%(Implements)%)%)%,%
%Implements,%(%else-then(%Implements%,%(%implements%)%)%)%,%
%IMPLEMENTS,%(%else-then(%IMPLEMENTS%,%(%toupper(%Implements%)%)%)%)%,%
%implements,%(%else-then(%_Implements%,%(%tolower(%Implements%)%)%)%)%,%
%extends,%(%else-then(%extends%,%(Extends)%)%)%,%
%Extends,%(%else-then(%Extends%,%(%extends%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_Extends%,%(%tolower(%Extends%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(Framework)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%kit,%(%else-then(%kit%,%(Kit)%)%)%,%
%Kit,%(%else-then(%Kit%,%(%kit%)%)%)%,%
%KIT,%(%else-then(%KIT%,%(%toupper(%Kit%)%)%)%)%,%
%kit,%(%else-then(%_Kit%,%(%tolower(%Kit%)%)%)%)%,%
%file,%(%else-then(%file%,%(%Class%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%extension,%(%else-then(%extension%,%(Extension)%)%)%,%
%Extension,%(%else-then(%Extension%,%(%extension%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%include,%(%else-then(%include%,%(%Framework%/%Kit%/%Kit%.hpp)%)%)%,%
%Include,%(%else-then(%Include%,%(%include%)%)%)%,%
%INCLUDE,%(%else-then(%INCLUDE%,%(%toupper(%Include%)%)%)%)%,%
%include,%(%else-then(%_Include%,%(%tolower(%Include%)%)%)%)%,%
%hpp,%(%equal(hpp,%Extension%)%%equal(hxx,%Extension%)%%equal(h,%Extension%)%)%,%
%header,%(%else-then(%header%,%(%Framework%/%Kit%/%Class%.hpp)%)%)%,%
%Header,%(%else-then(%Header%,%(%header%)%)%)%,%
%HEADER,%(%else-then(%HEADER%,%(%toupper(%Header%)%)%)%)%,%
%header,%(%else-then(%_Header%,%(%tolower(%Header%)%)%)%)%,%
%copyright,%(%else-then(%copyright%,%(Copyright)%)%)%,%
%Copyright,%(%else-then(%Copyright%,%(%copyright%)%)%)%,%
%COPYRIGHT,%(%else-then(%COPYRIGHT%,%(%toupper(%Copyright%)%)%)%)%,%
%copyright,%(%else-then(%_Copyright%,%(%tolower(%Copyright%)%)%)%)%,%
%year,%(%else-then(%year%,%(Year)%)%)%,%
%Year,%(%else-then(%Year%,%(%year%)%)%)%,%
%YEAR,%(%else-then(%YEAR%,%(%toupper(%Year%)%)%)%)%,%
%year,%(%else-then(%_Year%,%(%tolower(%Year%)%)%)%)%,%
%author,%(%else-then(%author%,%(Author)%)%)%,%
%Author,%(%else-then(%Author%,%(%author%)%)%)%,%
%AUTHOR,%(%else-then(%AUTHOR%,%(%toupper(%Author%)%)%)%)%,%
%author,%(%else-then(%_Author%,%(%tolower(%Author%)%)%)%)%,%
%date,%(%else-then(%date%,%(Date)%)%)%,%
%Date,%(%else-then(%Date%,%(%date%)%)%)%,%
%DATE,%(%else-then(%DATE%,%(%toupper(%Date%)%)%)%)%,%
%date,%(%else-then(%_Date%,%(%tolower(%Date%)%)%)%)%,%
%%(%
%///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-%year()% $organization$
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: %do(%File%)%.%do(%Extension%)%
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
%if(%hpp%,%(#ifndef _%do(%FRAMEWORK%)%_%do(%KIT%)%_%do(%FILE%)%_%do(%EXTENSION%)%
#define _%do(%FRAMEWORK%)%_%do(%KIT%)%_%do(%FILE%)%_%do(%EXTENSION%)%

#include "%do(%Include%)%")%,%(#include "%do(%Header%)%")%)%

namespace %Framework% {
namespace %Kit% {

} // namespace %Kit%
} // namespace %Framework%

%if(%hpp%,%(#endif // _%do(%FRAMEWORK%)%_%do(%KIT%)%_%do(%FILE%)%_%do(%EXTENSION%)%
)%)%%
%)%)%