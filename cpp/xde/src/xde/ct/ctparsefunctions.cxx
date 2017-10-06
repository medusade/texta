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
 *   File: ctparsefunctions.cxx
 *
 * Author: $author$
 *   Date: 10/1/2017
 **********************************************************************
 */
#include "xde/ct/ctparsefunctions.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cLeftTFunction
 *
 * Author: $author$
 *   Date: 8/15/2008
 **********************************************************************
 */
class cLeftTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cLeftTFunction
     *
     *      Author: $author$
     *        Date: 8/15/2008
     **********************************************************************
     */
    cLeftTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string","string"},
           {"pattern","pattern"},
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
        TLENGTH length1,length2;
        const char *buffer1, *buffer2;
        cTFunctionArgument *arg1, *arg2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((arg2 = arg1->GetNextItem()))
        if ((buffer1 = arg1->GetBuffer(length1)))
        if ((buffer2 = arg2->GetBuffer(length2)))
        if ((length2 > 0) && (length2 < length1))
        if ((buffer2 = strstr(buffer1, buffer2)))
            result.Write(buffer1, (TLENGTH)(buffer2-buffer1));

        return e_ERROR_NONE;
    }
} g_cLeftTFunction
  ("left","left(string,pattern)");

/**
 **********************************************************************
 *  Class: cRightTFunction
 *
 * Author: $author$
 *   Date: 8/15/2008
 **********************************************************************
 */
class cRightTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cRightTFunction
     *
     *      Author: $author$
     *        Date: 8/15/2008
     **********************************************************************
     */
    cRightTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string","string"},
           {"pattern","pattern"},
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
        TLENGTH length1,length2,length3;
        const char *buffer1, *buffer2;
        const char *found1, *found2;
        cTFunctionArgument *arg1, *arg2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((arg2 = arg1->GetNextItem()))
        if ((buffer1 = arg1->GetBuffer(length1)))
        if ((buffer2 = arg2->GetBuffer(length2)))
        if ((length2 > 0) && (length2 < length1))
        if ((found1 = strstr(buffer1, buffer2)))
        {
            while ((found2 = strstr(found1+length2, buffer2)))
                found1 = found2;

            if (length1 > (length3 = ((TLENGTH)(found1-buffer1))+length2))
                result.Write(found1+length2, length1-length3);
        }
        return e_ERROR_NONE;
    }
} g_cRightTFunction
  ("right","right(string,pattern)");

/**
 **********************************************************************
 *  Class: cLeftOfRightTFunction
 *
 * Author: $author$
 *   Date: 12/25/2008
 **********************************************************************
 */
class cLeftOfRightTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cLeftOfRightTFunction
     *
     *      Author: $author$
     *        Date: 12/25/2008
     **********************************************************************
     */
    cLeftOfRightTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string","string"},
           {"pattern","pattern"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/25/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1,length2,length3;
        const char *buffer1, *buffer2;
        const char *found1, *found2;
        cTFunctionArgument *arg1, *arg2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((arg2 = arg1->GetNextItem()))
        if ((buffer1 = arg1->GetBuffer(length1)))
        if ((buffer2 = arg2->GetBuffer(length2)))
        if ((length2 > 0) && (length2 < length1))
        if ((found1 = strstr(buffer1, buffer2)))
        {
            while ((found2 = strstr(found1+length2, buffer2)))
                found1 = found2;

            if (length1 > (length3 = ((TLENGTH)(found1-buffer1))))
                result.Write(buffer1, length3);
        }
        return e_ERROR_NONE;
    }
} g_cLeftOfRightTFunction
  ("left-of-right","left-of-right(string,pattern)");

/**
 **********************************************************************
 *  Class: cRightOfLeftTFunction
 *
 * Author: $author$
 *   Date: 12/25/2008
 **********************************************************************
 */
class cRightOfLeftTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cRightOfLeftTFunction
     *
     *      Author: $author$
     *        Date: 12/25/2008
     **********************************************************************
     */
    cRightOfLeftTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string","string"},
           {"pattern","pattern"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/25/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length1,length2,length3;
        const char *buffer1, *buffer2;
        cTFunctionArgument *arg1, *arg2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((arg2 = arg1->GetNextItem()))
        if ((buffer1 = arg1->GetBuffer(length1)))
        if ((buffer2 = arg2->GetBuffer(length2)))
        if ((length2 > 0) && (length2 < length1))
        if ((buffer2 = strstr(buffer1, buffer2)))
        if (length1 > (length3 = ((TLENGTH)(buffer2-buffer1))+length2))
            result.Write(buffer2+length2, length1-length3);

        return e_ERROR_NONE;
    }
} g_cRightOfLeftTFunction
  ("right-of-left","right-of-left(string,pattern)");

/**
 **********************************************************************
 *  Class: cLeftCharTFunction
 *
 * Author: $author$
 *   Date: 12/26/2008
 **********************************************************************
 */
class cLeftCharTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cLeftCharTFunction
     *
     *      Author: $author$
     *        Date: 12/26/2008
     **********************************************************************
     */
    cLeftCharTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/26/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *arg;
        const char *buffer;
        TLENGTH length;

        if ((arg = arglist.GetFirstItem()))
        if ((buffer = arg->GetBuffer(length)))
        if (length > 0)
            result.Write(buffer, 1);

        return e_ERROR_NONE;
    }
} g_cLeftCharTFunction
("left-char","left-char(string)");

/**
 **********************************************************************
 *  Class: cRightOfLeftCharTFunction
 *
 * Author: $author$
 *   Date: 12/26/2008
 **********************************************************************
 */
class cRightOfLeftCharTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cRightOfLeftCharTFunction
     *
     *      Author: $author$
     *        Date: 12/26/2008
     **********************************************************************
     */
    cRightOfLeftCharTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] = {{0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/26/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *arg;
        const char *buffer;
        TLENGTH length;

        if ((arg = arglist.GetFirstItem()))
        if ((buffer = arg->GetBuffer(length)))
        if (length > 1)
            result.Write(buffer+1);

        return e_ERROR_NONE;
    }
} g_cRightOfLeftCharTFunction
  ("right-of-left-char","right-of-left-char(string)"),
  g_cRightOfLeftCharTFunction2
  ("right-chars","right-chars(string)");

/**
 **********************************************************************
 *  Class: cParseTFunction
 *
 * Author: $author$
 *   Date: 12/25/2008
 **********************************************************************
 */
class cParseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cParseTFunction
     *
     *      Author: $author$
     *        Date: 12/25/2008
     **********************************************************************
     */
    cParseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string",""},
           {"delim",""},
           {"(before)",""},
           {"(between)",""},
           {"(after)",""},
           {"(expr)",""},
           {"var",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/25/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *before=0, *between=0, *after=0, *expr=0, *var=0;
        const char *string, *delim, *token, *name;
        cTFunctionArgument *arg1;
        TLENGTH delimLength, length;

        if ((arg1 = arglist.GetFirstItem()))
        if ((string = arg1->GetBuffer()))
        if ((arg1 = arg1->GetNextItem()))
        if ((delim = arg1->GetBuffer(delimLength)))
        {
            cTVariableInterface *variable = 0;

            if ((before = (arg1 = arg1->GetNextItem())))
            if ((between = (arg1 = arg1->GetNextItem())))
            if ((expr = (arg1 = arg1->GetNextItem())))
            if ((var = (arg1 = arg1->GetNextItem())))
            {
                if ((arg1 = arg1->GetNextItem()))
                {
                    after = expr;
                    expr = var;
                    var = arg1;
                }
                if ((name = var->GetBuffer()))
                    variable = t.GetVariable(name);
            }

            while ((token = strstr(string, delim)))
            {
                if (variable)
                    variable->PushValue
                    (string, (TLENGTH)(token-string));

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write
                    (string, (TLENGTH)(token-string));
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                if ((string = token+delimLength)[0])
                if (between)
                if (0 < (length = between->GetLength()))
                if (0 <= (length = between->Seek(0)))
                    t.Expand(result, *between);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (variable)
                    variable->PopValue();
            }

            if (string[0])
            {
                if (variable)
                    variable->PushValue(string);

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write(string);
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (variable)
                    variable->PopValue();
            }
        }
        return e_ERROR_NONE;
    }
} g_cParseTFunction
  ("parse","parse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])");

/**
 **********************************************************************
 *  Class: cRParseTFunction
 *
 * Author: $author$
 *   Date: 12/25/2008
 **********************************************************************
 */
class cRParseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cRParseTFunction
     *
     *      Author: $author$
     *        Date: 12/25/2008
     **********************************************************************
     */
    cRParseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string",""},
           {"delim",""},
           {"(before)",""},
           {"(between)",""},
           {"(after)",""},
           {"(expr)",""},
           {"var",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 12/25/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *before=0, *between=0, *after=0, *expr=0, *var=0;
        const char *string, *delim, *token, *name;
        cTFunctionArgument *arg1;
        TLENGTH delimLength, length;
        cString reversed;
        cString reversed2;

        if ((arg1 = arglist.GetFirstItem()))
        if ((string = arg1->GetBuffer()))
        if ((arg1 = arg1->GetNextItem()))
        if ((delim = arg1->GetBuffer(delimLength)))
        {
            cTVariableInterface *variable = 0;

            if ((before = (arg1 = arg1->GetNextItem())))
            if ((between = (arg1 = arg1->GetNextItem())))
            if ((expr = (arg1 = arg1->GetNextItem())))
            if ((var = (arg1 = arg1->GetNextItem())))
            {
                if ((arg1 = arg1->GetNextItem()))
                {
                    after = expr;
                    expr = var;
                    var = arg1;
                }
                if ((name = var->GetBuffer()))
                    variable = t.GetVariable(name);
            }

            while ((token = strstr(string, delim)))
            {
                const char* next = token+delimLength;
                reversed2.Assign(reversed.Chars(length));
                if ((next[0]))
                {
                    reversed.Assign(delim);
                    reversed.Append(string, token-string);
                }
                else reversed.Assign(string, token-string);
                reversed.Append(reversed2.Chars(length));
                string = next;
            }
            if ((string[0]))
            {
                reversed2.Assign(reversed.Chars(length));
                reversed.Assign(string);
                reversed.Append(reversed2.Chars(length));
            }
            string = reversed.Chars(length);
            while ((token = strstr(string, delim)))
            {
                if (variable)
                    variable->PushValue
                    (string, (TLENGTH)(token-string));

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write
                    (string, (TLENGTH)(token-string));
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                if ((string = token+delimLength)[0])
                if (between)
                if (0 < (length = between->GetLength()))
                if (0 <= (length = between->Seek(0)))
                    t.Expand(result, *between);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (variable)
                    variable->PopValue();
            }

            if (string[0])
            {
                if (variable)
                    variable->PushValue(string);

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write(string);
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (variable)
                    variable->PopValue();
            }
        }
        return e_ERROR_NONE;
    }
} g_cRParseTFunction
  ("reverse-parse","reverse-parse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])");

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
