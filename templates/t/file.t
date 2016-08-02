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
%#   File: file.t
%#
%# Author: $author$
%#   Date: 7/25/2016
%########################################################################
%with(%
%input_file,%(%else-then(%input_file%,%(%input%)%)%)%,%
%Input_file,%(%else-then(%Input_file%,%(%input_file%)%)%)%,%
%INPUT_FILE,%(%else-then(%INPUT_FILE%,%(%toupper(%Input_file%)%)%)%)%,%
%input_file,%(%else-then(%_Input_file%,%(%tolower(%Input_file%)%)%)%)%,%
%input_path,%(%else-then(%input_path%,%(%filepath(%Input_file%)%)%)%)%,%
%Input_path,%(%else-then(%Input_path%,%(%input_path%)%)%)%,%
%INPUT_PATH,%(%else-then(%INPUT_PATH%,%(%toupper(%Input_path%)%)%)%)%,%
%input_path,%(%else-then(%_Input_path%,%(%tolower(%Input_path%)%)%)%)%,%
%input_base,%(%else-then(%input_base%,%(%filebase(%Input_file%)%)%)%)%,%
%Input_base,%(%else-then(%Input_base%,%(%input_base%)%)%)%,%
%INPUT_BASE,%(%else-then(%INPUT_BASE%,%(%toupper(%Input_base%)%)%)%)%,%
%input_base,%(%else-then(%_Input_base%,%(%tolower(%Input_base%)%)%)%)%,%
%input_extension,%(%else-then(%input_extension%,%(%fileextension(%Input_file%)%)%)%)%,%
%input_extension,%(%else-then(%input_extension%,%(%input_extension%)%)%)%,%
%INPUT_EXTENSION,%(%else-then(%INPUT_EXTENSION%,%(%toupper(%input_extension%)%)%)%)%,%
%input_extension,%(%else-then(%_input_extension%,%(%tolower(%input_extension%)%)%)%)%,%
%include_path,%(%else-then(%include_path%,%(%Input_path%)%)%)%,%
%Include_path,%(%else-then(%Include_path%,%(%include_path%)%)%)%,%
%INCLUDE_PATH,%(%else-then(%INCLUDE_PATH%,%(%toupper(%Include_path%)%)%)%)%,%
%include_path,%(%else-then(%_Include_path%,%(%tolower(%Include_path%)%)%)%)%,%
%lcomment,%(%else-then(%lcomment%,%(%%#)%)%)%,%
%LComment,%(%else-then(%LComment%,%(%lcomment%)%)%)%,%
%LCOMMENT,%(%else-then(%LCOMMENT%,%(%toupper(%LComment%)%)%)%)%,%
%lcomment,%(%else-then(%_LComment%,%(%tolower(%LComment%)%)%)%)%,%
%rcomment,%(%else-then(%rcomment%,%()%)%)%,%
%RComment,%(%else-then(%RComment%,%(%rcomment%)%)%)%,%
%RCOMMENT,%(%else-then(%RCOMMENT%,%(%toupper(%RComment%)%)%)%)%,%
%rcomment,%(%else-then(%_RComment%,%(%tolower(%RComment%)%)%)%)%,%
%bcomment,%(%else-then(%bcomment%,%(%%########################################################################)%)%)%,%
%BComment,%(%else-then(%BComment%,%(%bcomment%)%)%)%,%
%BCOMMENT,%(%else-then(%BCOMMENT%,%(%toupper(%BComment%)%)%)%)%,%
%bcomment,%(%else-then(%_BComment%,%(%tolower(%BComment%)%)%)%)%,%
%ecomment,%(%else-then(%ecomment%,%(%%########################################################################)%)%)%,%
%EComment,%(%else-then(%EComment%,%(%ecomment%)%)%)%,%
%ECOMMENT,%(%else-then(%ECOMMENT%,%(%toupper(%EComment%)%)%)%)%,%
%ecomment,%(%else-then(%_EComment%,%(%tolower(%EComment%)%)%)%)%,%
%mcomment,%(%else-then(%mcomment%,%(%%########################################################################)%)%)%,%
%MComment,%(%else-then(%MComment%,%(%mcomment%)%)%)%,%
%MCOMMENT,%(%else-then(%MCOMMENT%,%(%toupper(%MComment%)%)%)%)%,%
%mcomment,%(%else-then(%_MComment%,%(%tolower(%MComment%)%)%)%)%,%
%copyright,%(%else-then(%copyright%,%(copyright.t)%)%)%,%
%Copyright,%(%else-then(%Copyright%,%(%copyright%)%)%)%,%
%COPYRIGHT,%(%else-then(%COPYRIGHT%,%(%toupper(%Copyright%)%)%)%)%,%
%copyright,%(%else-then(%_Copyright%,%(%tolower(%Copyright%)%)%)%)%,%
%disclaimer,%(%else-then(%disclaimer%,%(disclaimer.t)%)%)%,%
%Disclaimer,%(%else-then(%Disclaimer%,%(%disclaimer%)%)%)%,%
%DISCLAIMER,%(%else-then(%DISCLAIMER%,%(%toupper(%Disclaimer%)%)%)%)%,%
%disclaimer,%(%else-then(%_Disclaimer%,%(%tolower(%Disclaimer%)%)%)%)%,%
%file,%(%else-then(%file%,%(File)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%author,%(%else-then(%author%,%($author$)%)%)%,%
%Author,%(%else-then(%Author%,%(%author%)%)%)%,%
%AUTHOR,%(%else-then(%AUTHOR%,%(%toupper(%Author%)%)%)%)%,%
%author,%(%else-then(%_Author%,%(%tolower(%Author%)%)%)%)%,%
%organization,%(%else-then(%organization%,%($organization%)%)%)%,%
%Organization,%(%else-then(%Organization%,%(%organization%)%)%)%,%
%ORGANIZATION,%(%else-then(%ORGANIZATION%,%(%toupper(%Organization%)%)%)%)%,%
%organization,%(%else-then(%_Organization%,%(%tolower(%Organization%)%)%)%)%,%
%%(%BComment%
%LComment% %include(%Include_path%/%Copyright%)%
%LComment%
%parseln(%include(%Include_path%/%Disclaimer%)%,%(%LComment% )%,%(
)%,,%(%dl%)%,dl)%
%LComment%
%LComment%   File: %File%
%LComment%
%LComment% Author: %Author%
%LComment%   Date: %date()%
%EComment%
)%)%