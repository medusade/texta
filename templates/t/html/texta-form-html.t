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
%#   File: texta-form-html.t
%#
%# Author: $author$
%#   Date: 5/21/2016
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%file,%(%else-then(%file%,%($file$)%)%)%,%
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
%date,%(%else-then(%date%,%(%date()%)%)%)%,%
%Date,%(%else-then(%Date%,%(%date%)%)%)%,%
%DATE,%(%else-then(%DATE%,%(%toupper(%Date%)%)%)%)%,%
%date,%(%else-then(%_Date%,%(%tolower(%Date%)%)%)%)%,%
%year,%(%else-then(%year%,%(%year()%)%)%)%,%
%Year,%(%else-then(%Year%,%(%year%)%)%)%,%
%YEAR,%(%else-then(%YEAR%,%(%toupper(%Year%)%)%)%)%,%
%year,%(%else-then(%_Year%,%(%tolower(%Year%)%)%)%)%,%
%copyright,%(%else-then(%copyright%,%(Copyright (c) %Year% %Organization%)%)%)%,%
%Copyright,%(%else-then(%Copyright%,%(%copyright%)%)%)%,%
%COPYRIGHT,%(%else-then(%COPYRIGHT%,%(%toupper(%Copyright%)%)%)%)%,%
%copyright,%(%else-then(%_Copyright%,%(%tolower(%Copyright%)%)%)%)%,%
%accept-charset,%(%else-then(%accept-charset%,%()%)%)%,%
%Accept-charset,%(%else-then(%Accept-charset%,%(%accept-charset%)%)%)%,%
%ACCEPT-CHARSET,%(%else-then(%ACCEPT-CHARSET%,%(%toupper(%Accept-charset%)%)%)%)%,%
%accept-charset,%(%else-then(%_Accept-charset%,%(%tolower(%Accept-charset%)%)%)%)%,%
%action,%(%else-then(%action%,%(texta-form-html.t)%)%)%,%
%Action,%(%else-then(%Action%,%(%action%)%)%)%,%
%ACTION,%(%else-then(%ACTION%,%(%toupper(%Action%)%)%)%)%,%
%action,%(%else-then(%_Action%,%(%tolower(%Action%)%)%)%)%,%
%enctype,%(%else-then(%enctype%,%()%)%)%,%
%Enctype,%(%else-then(%Enctype%,%(%enctype%)%)%)%,%
%ENCTYPE,%(%else-then(%ENCTYPE%,%(%toupper(%Enctype%)%)%)%)%,%
%enctype,%(%else-then(%_Enctype%,%(%tolower(%Enctype%)%)%)%)%,%
%method,%(%else-then(%method%,%(POST)%)%)%,%
%Method,%(%else-then(%Method%,%(%method%)%)%)%,%
%METHOD,%(%else-then(%METHOD%,%(%toupper(%Method%)%)%)%)%,%
%method,%(%else-then(%_Method%,%(%tolower(%Method%)%)%)%)%,%
%name,%(%else-then(%name%,%(Form)%)%)%,%
%Name,%(%else-then(%Name%,%(%name%)%)%)%,%
%NAME,%(%else-then(%NAME%,%(%toupper(%Name%)%)%)%)%,%
%name,%(%else-then(%_Name%,%(%tolower(%Name%)%)%)%)%,%
%target,%(%else-then(%target%,%()%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%onsubmit,%(%else-then(%onsubmit%,%(return setFormSubmit(getFormValue('%Name%Action','%Name%'),getFormValue('%Name%Method','%Name%'),'%Name%'))%)%)%,%
%onSubmit,%(%else-then(%onSubmit%,%(%onsubmit%)%)%)%,%
%onSubmit,%(%do(%onSubmit%)%)%,%
%ONSUBMIT,%(%else-then(%ONSUBMIT%,%(%toupper(%onSubmit%)%)%)%)%,%
%onsubmit,%(%else-then(%_onSubmit%,%(%tolower(%onSubmit%)%)%)%)%,%
%attributes,%(%else-then(%attributes%,%(Name;Action;Method;Enctype;Accept-charset;Target)%)%)%,%
%Attributes,%(%else-then(%Attributes%,%(%attributes%)%)%)%,%
%ATTRIBUTES,%(%else-then(%ATTRIBUTES%,%(%toupper(%Attributes%)%)%)%)%,%
%attributes,%(%else-then(%_Attributes%,%(%tolower(%Attributes%)%)%)%)%,%
%accept,%(%else-then(%accept%,%()%)%)%,%
%Accept,%(%else-then(%Accept%,%(%accept%)%)%)%,%
%ACCEPT,%(%else-then(%ACCEPT%,%(%toupper(%Accept%)%)%)%)%,%
%accept,%(%else-then(%_Accept%,%(%tolower(%Accept%)%)%)%)%,%
%autocomplete,%(%else-then(%autocomplete%,%()%)%)%,%
%Autocomplete,%(%else-then(%Autocomplete%,%(%autocomplete%)%)%)%,%
%AUTOCOMPLETE,%(%else-then(%AUTOCOMPLETE%,%(%toupper(%Autocomplete%)%)%)%)%,%
%autocomplete,%(%else-then(%_Autocomplete%,%(%tolower(%Autocomplete%)%)%)%)%,%
%novalidate,%(%else-then(%novalidate%,%()%)%)%,%
%Novalidate,%(%else-then(%Novalidate%,%(%novalidate%)%)%)%,%
%NOVALIDATE,%(%else-then(%NOVALIDATE%,%(%toupper(%Novalidate%)%)%)%)%,%
%novalidate,%(%else-then(%_Novalidate%,%(%tolower(%Novalidate%)%)%)%)%,%
%v5attributes,%(%else-then(%v5attributes%,%(Accept;Autocomplete;Novalidate)%)%)%,%
%V5Attributes,%(%else-then(%V5Attributes%,%(%v5attributes%)%)%)%,%
%V5ATTRIBUTES,%(%else-then(%V5ATTRIBUTES%,%(%toupper(%V5Attributes%)%)%)%)%,%
%v5attributes,%(%else-then(%_V5Attributes%,%(%tolower(%V5Attributes%)%)%)%)%,%
%title,%(%else-then(%title%,%(Create HTML Form)%)%)%,%
%Title,%(%else-then(%Title%,%(%title%)%)%)%,%
%TITLE,%(%else-then(%TITLE%,%(%toupper(%Title%)%)%)%)%,%
%title,%(%else-then(%_Title%,%(%tolower(%Title%)%)%)%)%,%
%fields,%(%else-then(%fields%,%(File;Author;Organization;Title;%Attributes%;onSubmit;Fields)%)%)%,%
%Fields,%(%else-then(%Fields%,%(%fields%)%)%)%,%
%FIELDS,%(%else-then(%FIELDS%,%(%toupper(%Fields%)%)%)%)%,%
%fields,%(%else-then(%_Fields%,%(%tolower(%Fields%)%)%)%)%,%
%submit,%(%else-then(%FormSubmit%,%(Submit)%)%)%,%
%Submit,%(%else-then(%Submit%,%(%submit%)%)%)%,%
%SUBMIT,%(%else-then(%SUBMIT%,%(%toupper(%Submit%)%)%)%)%,%
%submit,%(%else-then(%_Submit%,%(%tolower(%Submit%)%)%)%)%,%
%padd,%(%length(========================================================================)%)%,%
%%(%
%<!--========================================================================-->
<!--%padd( %Copyright%, ,%padd%)%-->
<!--                                                                        -->
<!-- This software is provided by the author and contributors ``as is''     -->
<!-- and any express or implied warranties, including, but not limited to,  -->
<!-- the implied warranties of merchantability and fitness for a particular -->
<!-- purpose are disclaimed. In no event shall the author or contributors   -->
<!-- be liable for any direct, indirect, incidental, special, exemplary,    -->
<!-- or consequential damages (including, but not limited to, procurement   -->
<!-- of substitute goods or services; loss of use, data, or profits; or     -->
<!-- business interruption) however caused and on any theory of liability,  -->
<!-- whether in contract, strict liability, or tort (including negligence   -->
<!-- or otherwise) arising in any way out of the use of this software,      -->
<!-- even if advised of the possibility of such damage.                     -->
<!--                                                                        -->
<!--%padd(   File: %File%, ,%padd%)%-->
<!--                                                                        -->
<!--%padd( Author: %Author%, ,%padd%)%-->
<!--%padd(   Date: %date%, ,%padd%)%-->
<!--========================================================================-->
<html>
    <!--========================================================================-->
    <!-- head                                                                   -->
    <!--========================================================================-->
    <head>
        <title>%Title%</title>
        <!--========================================================================-->
        <!-- style                                                                  -->
        <!--========================================================================-->
        <style
         type="text/css">
        </style>
        <!--========================================================================-->
        <!-- script                                                                 -->
        <!--========================================================================-->
        <script language="javaScript" src="../../js/html-form.js"></script>
        <script
         language="JavaScript"
         type="text/JavaScript">
        </script>
    </head>
    <!--========================================================================-->
    <!-- body                                                                   -->
    <!--========================================================================-->
    <body>%if(%Title%,%(%(
        )%<h3>%Title%</h3>%(
        )%<hr>)%)%
        <!--========================================================================-->
        <!-- form                                                                   -->
        <!--========================================================================-->
        <form%parse(%Attributes%;onSubmit,;,,,,%(%if(%do(%%%Attribute%%%)%,%(%(
         )%%Attribute%="%do(%%%Attribute%%%)%")%)%)%,Attribute)%>
        %parse(%Fields%,;,,%(
        )%,,%(%
%%with(%
%FieldName,%(%else-then(%left(%Field%,=)%,%(%Field%)%)%)%,%
%FieldValue,%(%else-then(%right(%Field%,=)%,%(%do(%%%Field%%%)%)%)%)%,%
%FieldPrefix,%(%if(%equal(Method,%FieldName%)%%equal(Action,%FieldName%)%,%(%Name%)%)%)%,%
%%(%
%%(    )%%FieldName%: <input name="%FieldPrefix%%FieldName%" value="%FieldValue%"/><br/>%
%)%)%%
%)%,Field)%%
      %%if(%Submit%,%(%(
            )%<hr/>%(
            )%<input type="submit" name="%Submit%" value="%do(%%%Submit%%%)%"/><br/>)%)%
        </form>
    </body>
</html>
%
%)%)%