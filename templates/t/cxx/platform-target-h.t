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
%#   File: platform-taget-h.t
%#
%# Author: $author$
%#   Date: 8/10/2016
%########################################################################
%with(%
%define,%(%else-then(%define%,%(Define)%)%)%,%
%Define,%(%else-then(%Define%,%(%define%)%)%)%,%
%DEFINE,%(%else-then(%DEFINE%,%(%toupper(%Define%)%)%)%)%,%
%define,%(%else-then(%_Define%,%(%tolower(%Define%)%)%)%)%,%
%target,%(%else-then(%target%,%(%Define%)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%%(
//
// Define %TARGET% if any of the %Define% variants are defined
//
#if defined(%DEFINE%) || defined(_%DEFINE%) || defined(__%DEFINE%__) || defined(__%Define%__) || defined(__%define%__)
#if defined(PLATFORM_DEFINED_DEBUG)
#error defined %TARGET%
#endif // defined(PLATFORM_DEFINED_DEBUG)
#if !defined(%TARGET%)
#define %TARGET%
#endif //  !defined(%TARGET%)
#endif //  defined(%DEFINE%) || defined(_%DEFINE%) || defined(__%DEFINE%__) || defined(__%Define%__) || defined(__%define%__)

//
// Define %TARGET% if all of the %Target% variants are defined
//
#if defined(%TARGET%) && defined(%TARGET%)
#if defined(PLATFORM_DEFINED_DEBUG)
#error defined %TARGET%
#endif // defined(PLATFORM_DEFINED_DEBUG)
#if !defined(%TARGET%)
#define %TARGET%
#endif // !defined(%TARGET%)
#endif // defined(%TARGET%) && defined(%TARGET%)

/*
 * Define %TARGET% if any of the %Define% variants are defined
 */
#if defined(%DEFINE%) || defined(_%DEFINE%) || defined(__%DEFINE%__) || defined(__%Define%__) || defined(__%define%__)
#if defined(PLATFORM_DEFINED_DEBUG)
#error defined %TARGET%
#endif /* defined(PLATFORM_DEFINED_DEBUG) */
#if !defined(%TARGET%)
#define %TARGET%
#endif /*  !defined(%TARGET%) */
#endif /*  defined(%DEFINE%) || defined(_%DEFINE%) || defined(__%DEFINE%__) || defined(__%Define%__) || defined(__%define%__) */

/*
 * Define %TARGET% if any of the %Target% variants are defined
 */
#if defined(%TARGET%) || defined(%TARGET%)
#if defined(PLATFORM_DEFINED_DEBUG)
#error defined %TARGET%
#endif /* defined(PLATFORM_DEFINED_DEBUG) */
#if !defined(%TARGET%)
#define %TARGET%
#endif /* !defined(%TARGET%) */
#endif /* defined(%TARGET%) || defined(%TARGET%) */

/*
 * Define %TARGET% if all of the %Target% variants are defined
 */
#if defined(%TARGET%) && defined(%TARGET%)
#if defined(PLATFORM_DEFINED_DEBUG)
#error defined %TARGET%
#endif /* defined(PLATFORM_DEFINED_DEBUG) */
#if !defined(%TARGET%)
#define %TARGET%
#endif /* !defined(%TARGET%) */
#endif /* defined(%TARGET%) && defined(%TARGET%) */

)%)%