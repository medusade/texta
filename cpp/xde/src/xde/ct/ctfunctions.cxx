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
 *   File: ctfunctions.cxx
 *
 * Author: $author$
 *   Date: 10/1/2017
 **********************************************************************
 */
#include "xde/ct/ctfunctions.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cFunctionParametersTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cFunctionParametersTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFunctionParametersTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cFunctionParametersTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"function","function name"},
           {"(before)","do before each"},
           {"(between)","do between each"},
           {"(do)","do for each"},
           {"name","parameter name variable"},
           {"desc","parameter description variable"},
           {0,0}};
        m_parameter = parameter;
        m_parameters = sizeof(parameter)/sizeof(cTFunctionParameter)-1;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/3/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        const char *name = 0;
        const char *desc = 0;
        const char *name_var = 0;
        const char *desc_var = 0;
        cTVariableInterface *name_variable = 0;
        cTVariableInterface *desc_variable = 0;
        cTFunctionArgument *fname = 0;
        cTFunctionArgument *before = 0;
        cTFunctionArgument *between = 0;
        cTFunctionArgument *expr = 0;
        cTFunctionArgument *arg;
        cTFunctionInterface* function;
        const cTFunctionParameter* parameter;
        int parameters;

        if ((fname = (arg = arglist.GetFirstItem())))
        if ((before = (arg = arg->GetNextItem())))
        if ((between = (arg = arg->GetNextItem())))
        if ((expr = (arg = arg->GetNextItem())))
        if ((arg = arg->GetNextItem()))
        {
            if ((name_var = arg->GetBuffer()))
                name_variable = t.GetVariable(name_var);

            if ((arg = arg->GetNextItem()))
            {
                if ((desc_var = arg->GetBuffer()))
                    desc_variable = t.GetVariable(desc_var);
            }
        }

        if (fname)
        if ((name = fname->GetBuffer()))
        if ((function = t.FindFunction(name)))
        if ((desc = function->GetDescription(parameter, parameters)))
        if (parameter && parameters)
        do
        {
            name = parameter->GetName();
            desc = parameter->GetDescription();

            if (name_variable && name)
                name_variable->PushValue(name);

            if (desc_variable && desc)
                desc_variable->PushValue(desc);

            if (before)
            {
                t.Expand(result,*before);
                before->Seek(0);
            }

            if (expr)
            {
                t.Expand(result,*expr);
                expr->Seek(0);
            }
            else
            {
                if (name)
                    result.Write(name);

                if (desc)
                    result.WriteL(":", desc, NULL_POINTER);
            }

            if ((function = t.GetNextFunction()))
            if (between)
            {
                t.Expand(result,*between);
                between->Seek(0);
            }
            else if (!expr)
                    result.Write(";");

            if (desc_variable && desc)
                desc_variable->PopValue();

            if (name_variable && name)
                name_variable->PopValue();

            parameter++;
        }
        while(--parameters);

        return e_ERROR_NONE;
    }
} g_cFunctionParametersTFunction
  ("function-parameters",
   "function-parameters(function, (before), (between), (do), name, desc)");

/**
 **********************************************************************
 *  Class: cFunctionsTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cFunctionsTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cFunctionsTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cFunctionsTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"(before)","do before each function"},
           {"(between)","do between each function"},
           {"(do)","do for each function"},
           {"name","variable name for function name"},
           {"desc","variable name for function description"},
           {0,0}};

        m_parameter = parameter;
        m_parameters = sizeof(parameter)/sizeof(cTFunctionParameter)-1;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/3/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        const char *name = 0;
        const char *desc = 0;
        const char *name_var = 0;
        const char *desc_var = 0;
        cTVariableInterface *name_variable = 0;
        cTVariableInterface *desc_variable = 0;
        cTFunctionArgument *before = 0;
        cTFunctionArgument *between = 0;
        cTFunctionArgument *expr = 0;
        cTFunctionArgument *arg;
        cTFunctionInterface* function;
        const cTFunctionParameter* parameter;
        int parameters;

        if ((before = (arg = arglist.GetFirstItem())))
        if ((between = (arg = arg->GetNextItem())))
        if ((expr = (arg = arg->GetNextItem())))
        if ((arg = arg->GetNextItem()))
        {
            if ((name_var = arg->GetBuffer()))
                name_variable = t.GetVariable(name_var);

            if ((arg = arg->GetNextItem()))
            {
                if ((desc_var = arg->GetBuffer()))
                    desc_variable = t.GetVariable(desc_var);
            }
        }

        if ((function = t.GetFirstFunction()))
        do
        {
            name = function->GetName();
            desc = function->GetDescription(parameter, parameters);

            if (name_variable && name)
                name_variable->PushValue(name);

            if (desc_variable && desc)
                desc_variable->PushValue(desc);

            if (before)
            {
                t.Expand(result,*before);
                before->Seek(0);
            }

            if (expr)
            {
                t.Expand(result,*expr);
                expr->Seek(0);
            }
            else
            {
                if (name)
                    result.Write(name);

                if (desc)
                    result.WriteL(":", desc, NULL_POINTER);
            }

            if ((function = t.GetNextFunction()))
            if (between)
            {
                t.Expand(result,*between);
                between->Seek(0);
            }
            else if (!expr)
                    result.Write(";");

            if (desc_variable && desc)
                desc_variable->PopValue();

            if (name_variable && name)
                name_variable->PopValue();
        }
        while(function);

        return e_ERROR_NONE;
    }
} g_cFunctionsTFunction
("functions","functions((before), (between), (do), name, desc)");

/**
 **********************************************************************
 *  Class: cParametersTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cParametersTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cParametersTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cParametersTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"named",""},
           {"(before)",""},
           {"(between)",""},
           {"(after)",""},
           {"(expr)",""},
           {"name",""},
           {"value",""},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        cTVariableInterface *nameVariable=0, *valueVariable=0;
        cTFunctionArgument *before=0, *between=0, *after=0;
        cTFunctionArgument *expr=0, *nameVar=0, *valueVar=0;
        cTFunctionArgument *arg1;
        const char *named, *name, *value;
        int namedLength, nameLength, valueLength;
        const char* chars;
        TLENGTH length;

        DBT("() in...\n");

        //result.Write("parameters...");

        namedLength = 0;

        if (!(arg1 = arglist.GetFirstItem()))
            named = 0;
        else
        if ((named = arg1->GetBuffer(length)))
        if (1 > length)
            named = 0;
        else namedLength = length;

        name = named;
        nameLength = namedLength;

        if ((value = t.GetFirstParameter
            (valueLength, name, nameLength)))
        {
            //result.Write("parameter");
            if (arg1)
            if ((before = (arg1 = arg1->GetNextItem())))
            if ((between = (arg1 = arg1->GetNextItem())))
            if ((after = (arg1 = arg1->GetNextItem())))
            if ((expr = (arg1 = arg1->GetNextItem())))
            if ((nameVar = (arg1 = arg1->GetNextItem())))
            {
                if ((chars = nameVar->GetBuffer()))
                    nameVariable = t.GetVariable(chars);

                if ((valueVar = (arg1 = arg1->GetNextItem())))
                {
                    if ((chars = valueVar->GetBuffer()))
                        valueVariable = t.GetVariable(chars);
                }
            }

            do
            {
                if (nameVariable)
                    nameVariable->PushValue
                    (name, nameLength);

                if (valueVariable)
                    valueVariable->PushValue
                    (value, valueLength);

                if (before)
                if (0 < (length = before->GetLength()))
                if (0 <= (length = before->Seek(0)))
                    t.Expand(result, *before);

                if (!expr)
                    result.Write
                    (value, valueLength);
                else
                if (0 < (length = expr->GetLength()))
                if (0 <= (length = expr->Seek(0)))
                    t.Expand(result, *expr);

                name = named;
                nameLength = namedLength;

                if ((value = t.GetNextParameter
                   (valueLength, name, nameLength)))
                if (between)
                if (0 < (length = between->GetLength()))
                if (0 <= (length = between->Seek(0)))
                    t.Expand(result, *between);

                if (after)
                if (0 < (length = after->GetLength()))
                if (0 <= (length = after->Seek(0)))
                    t.Expand(result, *after);

                if (valueVariable)
                    valueVariable->PopValue();

                if (nameVariable)
                    nameVariable->PopValue();
            }
            while ((value));
        }

        DBT("() ...out\n");
        return e_ERROR_NONE;
    }
} g_cParametersTFunction
  ("parameters",
   "parameters(named,(before),(between),(after),(expr),name,value)");

/**
 **********************************************************************
 *  Class: cGetenvTFunction
 *
 * Author: $author$
 *   Date: 12/16/2012
 **********************************************************************
 */
class cGetenvTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cGetenvTFunction
     *
     *      Author: $author$
     *        Date: 12/16/2012
     **********************************************************************
     */
    cGetenvTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[] = {
            {"string,...", "environment variable name(s)"},
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
        cTFunctionArgument *arg;
        const char* chars;
        TLENGTH length;

        if ((arg = arglist.GetFirstItem()))
        {
            do
            {
                if ((chars = arg->GetBuffer(length)))
                if (0 < length)
                if ((chars = getenv(chars)))
                if ((chars[0]))
                    result.Write(chars);
            }
            while((arg = arg->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cGetenvTFunction("getenv", "getenv(string,...)");

/**
 **********************************************************************
 *  Class: cImportTFunction
 *
 * Author: $author$
 *   Date: 4/2/2008
 **********************************************************************
 */
class cImportTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cImportTFunction
     *
     *      Author: $author$
     *        Date: 4/2/2008
     **********************************************************************
     */
    cImportTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"location,...","filename or uri to include literally"},
           {0,0}};

        m_parameter = parameter;
        m_parameters = sizeof(parameter)/sizeof(cTFunctionParameter)-1;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/2/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        eError error;
        TLENGTH pathlen;
        const char *path;
        cTFunctionArgument *expr;
        cCharFile file;

        for (expr = arglist.GetFirstItem();
             expr; expr = expr->GetNextItem())
        {
            if ((path = expr->GetBuffer(pathlen)))
            if (0 < pathlen)
            if (!(error = file.Open(path)))
            {
                result.WriteReader(file);
                file.Close();
            }
        }
        return e_ERROR_NONE;
    }
} g_cImportTFunction
  ("import","import(location,...)");

/**
 **********************************************************************
 *  Class: cIncludeTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cIncludeTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIncludeTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cIncludeTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"location,...","filename or uri to include expansion"},
           {0,0}};

        m_parameter = parameter;
        m_parameters = sizeof(parameter)/sizeof(cTFunctionParameter)-1;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/3/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        eError error;
        TLENGTH pathlen;
        const char*path;
        cTFunctionArgument* expr;
        cCharFile file;

        for (expr = arglist.GetFirstItem();
             expr; expr = expr->GetNextItem())
        {
            if ((path = expr->GetBuffer(pathlen)))
            if (0 < pathlen)
            if (!(error = file.Open(path))) {
                t.Expand(result,file);
                file.Close();
            } else {
                DBE("() ...failed on file.Open(path = \"%s\")\n",path);
            }
        }
        return e_ERROR_NONE;
    }
} g_cIncludeTFunction
  ("include","include(location,...)");

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
