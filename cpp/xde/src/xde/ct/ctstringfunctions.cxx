/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: ctstringfunctions.cxx
 *
 * Author: $author$
 *   Date: 10/1/2017
 **********************************************************************
 */
#include "xde/ct/ctstringfunctions.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cPaddTFunction
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
class cPaddTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cPaddTFunction
     *
     *      Author: $author$
     *        Date: 12/28/2008
     **********************************************************************
     */
    cPaddTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string,...","strings to padd"},
           {"padding","padding to use"},
           {"length","padded length"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/28/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        const char *buffer;
        TLENGTH count,length,bufflen,padlen;
        cTFunctionArgument *arg,*strarg,*padarg,*lenarg;
        cDigitizer digits;

        if ((strarg = (arg = arglist.GetFirstItem())))
        if ((padarg = (arg = arg->GetNextItem())))
        if ((lenarg = (arg = arg->GetNextItem())))
        {
            length = 0;

            do
            {
                if ((buffer = strarg->GetBuffer(count)))
                if (0 < count)
                if (0 < (count = result.Write(buffer,count)))
                    length += count;

                if ((arg = arg->GetNextItem()))
                {
                    strarg = padarg;
                    padarg = lenarg;
                    lenarg = arg;
                }
            }
            while (arg);

            if ((buffer = lenarg->GetBuffer(bufflen)))
            if (0 < bufflen)
            if (0 < (padlen = digits.Signed(count, buffer, bufflen)))
            if (length < padlen)
            if ((buffer = padarg->GetBuffer(bufflen)))
            if (0 < bufflen)
            {
                if (bufflen > padlen)
                    bufflen = padlen;

                do
                {
                    if (0 >= (count = result.Write(buffer, bufflen)))
                        break;
                }
                while((length += count) < padlen);
            }
        }
        return e_ERROR_NONE;
    }
} g_cPaddTFunction
  ("padd","padd(string,...,padding,padlen)"),
  g_cPaddTFunction2
  ("strpad","strpad(string,...,padding,padlen)");

/**
 **********************************************************************
 **********************************************************************
 */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */


        

