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
 *   File: ctblockfunctions.cxx
 *
 * Author: $author$
 *   Date: 10/1/2017
 **********************************************************************
 */
#include "xde/ct/ctblockfunctions.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cDoTFunction
 *
 * Author: $author$
 *   Date: 4/2/2008
 **********************************************************************
 */
class cDoTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cDoTFunction
     *
     *      Author: $author$
     *        Date: 4/2/2008
     **********************************************************************
     */
    cDoTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"(do),...","expansions to do"},
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
        cTFunctionArgument *expr;

        for (expr = arglist.GetFirstItem();
             expr; expr = expr->GetNextItem())
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        return e_ERROR_NONE;
    }
} g_doTFunction
  ("do","do((do),...)");

/**
 **********************************************************************
 *  Class: cApplyTFunction
 *
 * Author: $author$
 *   Date: 12/26/2008
 **********************************************************************
 */
class cApplyTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cApplyTFunction
     *
     *      Author: $author$
     *        Date: 12/26/2008
     **********************************************************************
     */
    cApplyTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"name","variable name"},
           {"value","variable value expansion"},
           {"(do)","do expansion"},
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
        TLENGTH length;
        const char* buffer;
        cTVariableInterface *variable;
        cTFunctionArgument *name;
        cTFunctionArgument *value;
        cTFunctionArgument *expr = 0;

        if ((expr = (name = arglist.GetFirstItem())))
        {
            do
            {
                if (!(expr = (value = name->GetNextItem())))
                    expr = name;

                else if (!(expr = value->GetNextItem()))
                        expr = value;

                else
                {
                    if ((buffer = value->GetBuffer(length)))
                    if ((variable = GetVariable(t, *name)))
                        variable->PushValue(buffer,length);

                    name = expr;
                    continue;
                }
                break;
            }
            while (name);

            if (expr)
            if (expr->GetLength()>0)
                t.Expand(result, *expr);

            if ((expr = (name = arglist.GetFirstItem())))
            do
            {
                if (!(expr = (value = name->GetNextItem())))
                    expr = name;

                else if (!(expr = value->GetNextItem()))
                        expr = value;

                else
                {
                    if ((buffer = value->GetBuffer(length)))
                    if ((variable = GetVariable(t, *name)))
                        variable->PopValue();

                    name = expr;
                    continue;
                }
                break;
            }
            while (name);
        }
        return e_ERROR_NONE;
    }
} g_cApplyTFunction
  ("apply","apply([name,value,...,](do))");

/**
 **********************************************************************
 *  Class: cWithTFunction
 *
 * Author: $author$
 *   Date: 4/2/2008
 **********************************************************************
 */
class cWithTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cWithTFunction
     *
     *      Author: $author$
     *        Date: 4/2/2008
     **********************************************************************
     */
    cWithTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"name","variable name"},
           {"(value)","variable value expansion"},
           {"(do)","do expansion"},
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
        TLENGTH length;
        const char* buffer;
        cTVariableInterface *variable;
        cTFunctionArgument *name;
        cTFunctionArgument *value;
        cTFunctionArgument *expr = 0;
        cCharBuffer value_result;

        if ((expr = (name = arglist.GetFirstItem())))
        {
            do
            {
                if (!(expr = (value = name->GetNextItem())))
                    expr = name;

                else if (!(expr = value->GetNextItem()))
                        expr = value;

                else
                {
                    if ((variable = GetVariable(t, *name)))
                    {
                        value_result.Clear();
                        t.Expand(value_result, *value);
                        if ((buffer = value_result.GetBuffer(length)))
                            variable->PushValue(buffer,length);
                    }
                    name = expr;
                    continue;
                }
                break;
            }
            while (name);

            if (expr)
            if (expr->GetLength()>0)
                t.Expand(result, *expr);

            if ((expr = (name = arglist.GetFirstItem())))
            do
            {
                if (!(expr = (value = name->GetNextItem())))
                    expr = name;

                else if (!(expr = value->GetNextItem()))
                        expr = value;

                else
                {
                    if ((buffer = value_result.GetBuffer(length)))
                    if ((variable = GetVariable(t, *name)))
                        variable->PopValue();

                    name = expr;
                    continue;
                }

                break;
            }
            while (name);
        }
        return e_ERROR_NONE;
    }
} g_cWithTFunction
  ("with","with([name,(value),...,](do))"),
  g_cWithTFunction2
  ("apply-x","apply-x([name,(value),...,](do))");

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
