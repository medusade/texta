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
 *   File: ctconvertfunctions.cxx
 *
 * Author: $author$
 *   Date: 10/1/2017
 **********************************************************************
 */
#include "xde/ct/ctconvertfunctions.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cToUpperTFunction
 *
 * Author: $author$
 *   Date: 8/15/2008
 **********************************************************************
 */
class cToUpperTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cToUpperTFunction
     *
     *      Author: $author$
     *        Date: 8/15/2008
     **********************************************************************
     */
    cToUpperTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string,...","strings to upper"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1;
        const char *buffer1;
        cTFunctionArgument *arg1;

        if ((arg1 = arglist.GetFirstItem()))
        do
        {
            if ((buffer1 = arg1->GetBuffer(length1)))
            while(length1>0)
            {
                result.Put(toupper(*buffer1));
                buffer1++;
                --length1;
            }
        }
        while((arg1 = arg1->GetNextItem()));
        return e_ERROR_NONE;
    }
} g_cToUpperTFunction
("toupper","toupper(string,...)");

/**
 **********************************************************************
 *  Class: cToLowerTFunction
 *
 * Author: $author$
 *   Date: 8/15/2008
 **********************************************************************
 */
class cToLowerTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cToLowerTFunction
     *
     *      Author: $author$
     *        Date: 8/15/2008
     **********************************************************************
     */
    cToLowerTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string,...","strings to lower"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/15/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1;
        const char *buffer1;
        cTFunctionArgument *arg1;

        if ((arg1 = arglist.GetFirstItem()))
        do
        {
            if ((buffer1 = arg1->GetBuffer(length1)))
            while(length1>0)
            {
                result.Put(tolower(*buffer1));
                buffer1++;
                --length1;
            }
        }
        while((arg1 = arg1->GetNextItem()));
        return e_ERROR_NONE;
    }
} g_cToLowerTFunction
("tolower","tolower(string,...)");

/**
 **********************************************************************
 *  Class: cReplaceTFunction
 *
 * Author: $author$
 *   Date: 12/16/2012
 **********************************************************************
 */
class cReplaceTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cReplaceTFunction
     *
     *      Author: $author$
     *        Date: 12/16/2012
     **********************************************************************
     */
    cReplaceTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] = {
            {"from", "find from"},
            {"to", "replace with to"},
            {"string,...", "in string(s)"},
            {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/16/2012
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *from,*to,*arg;
        const char *fromChars,*toChars,*chars;
        TLENGTH fromLength,toLength,length;

        if ((from = arglist.GetFirstItem()))
        if ((fromChars = from->GetBuffer(fromLength)))
        if ((to = from->GetNextItem()))
        if ((toChars = to->GetBuffer(toLength)))
        if ((0 < fromLength) && (fromLength == toLength))
        if ((arg = to->GetNextItem()))
        {
            const char* found;
            int i;
            do
            {
                if ((chars = arg->GetBuffer(length)))
                if (0 < length)
                for (i = 0; i < length; i++)
                {
                    if ((found = strchr(fromChars, chars[i])))
                        result.Write(toChars+(found-fromChars), 1);
                    else result.Write(chars+i, 1);
                }
            }
            while((arg = arg->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cReplaceTFunction
("replace","replace(from,to,string,...)");

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
