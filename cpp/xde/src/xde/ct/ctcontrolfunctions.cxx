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
 *   File: ctcontrolfunctions.cxx
 *
 * Author: $author$
 *   Date: 10/1/2017
 **********************************************************************
 */
#include "xde/ct/ctcontrolfunctions.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cExitTFunction
 *
 * Author: $author$
 *   Date: 5/31/2017
 **********************************************************************
 */
class cExitTFunction: public cTFunction {
public:
   typedef cTFunction cExtends;
   /**
    **********************************************************************
    * Constructor: cExitTFunction
    *
    *      Author: $author$
    *        Date: 5/31/2017
    **********************************************************************
    */
   cExitTFunction(const char* name, const char* description)
   : cExtends(name, description) {
       static cTFunctionParameter parameter[]
       = {{"...",""}, {0,0}};
       m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
       m_parameter = parameter;
   }
   /**
    **********************************************************************
    * Function: Expand
    *
    *   Author: $author$
    *     Date: 5/31/2017
    **********************************************************************
    */
   virtual eError Expand
   (cCharStreamInterface &result, cTInterface &t,
    const cTFunctionArgumentList& arglist) const {
       cTException e(e_ERROR_EXIT);
       DBT("()...throwing cTException e(e_ERROR_EXIT)...\n");
       throw (e);
       return e_ERROR_NONE;
   }
} g_cExitTFunction
("exit","exit(...)");

/**
 **********************************************************************
 *  Class: cIfTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cIfTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIfTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cIfTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","test condition"},
           {"(do)","do if cond"},
           {"(else)...","do else cond"},
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
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if (cond->GetLength()>0)
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cIfTFunction
("if","if(cond,(do),(else),...)");

/**
 **********************************************************************
 *  Class: cElseTFunction
 *
 * Author: $author$
 *   Date: 4/5/2008
 **********************************************************************
 */
class cElseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cElseTFunction
     *
     *      Author: $author$
     *        Date: 4/5/2008
     **********************************************************************
     */
    cElseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","test condition"},
           {"(do)","do else cond"},
           {"(else)...","do if cond"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if (cond->GetLength()<1)
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cElseTFunction
("else","else(cond,(do),(else)...)");

/**
 **********************************************************************
 *  Class: cIfThenTFunction
 *
 * Author: $author$
 *   Date: 4/5/2008
 **********************************************************************
 */
class cIfThenTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIfThenTFunction
     *
     *      Author: $author$
     *        Date: 4/5/2008
     **********************************************************************
     */
    cIfThenTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"did","do then test condition"},
           {"(do),...","do if did"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length;
        const char *buffer;
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((buffer = cond->GetBuffer(length)))
        if (length > 0)
        {
            result.Write(buffer, length);

            if ((expr = cond->GetNextItem()))
            do
            {
                if (expr->GetLength()>0)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cIfThenTFunction
  ("if-then","if-then(did,(do),...)");

/**
 **********************************************************************
 *  Class: cElseThenTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cElseThenTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cElseThenTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cElseThenTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"did","do then test condition"},
           {"(else),...","do else did"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
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
        TLENGTH length;
        const char* buffer;
        cTFunctionArgument* cond;
        cTFunctionArgument* expr;

        if ((cond = arglist.GetFirstItem()))
        {
            if ((buffer = cond->GetBuffer(length)))
            if (length > 0)
            {
                result.Write(buffer, length);
                return e_ERROR_NONE;
            }

            if ((expr = cond->GetNextItem()))
            do
            {
                if (expr->GetLength()>0)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cElseThenTFunction
  ("else-then","else-then(did,(else),...)");

/**
 **********************************************************************
 *  Class: cThenIfTFunction
 *
 * Author: $author$
 *   Date: 4/5/2008
 **********************************************************************
 */
class cThenIfTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cThenIfTFunction
     *
     *      Author: $author$
     *        Date: 4/5/2008
     **********************************************************************
     */
    cThenIfTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"todo","test condition then do"},
           {"(do),...","do if todo"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length;
        const char *buffer;
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((buffer = cond->GetBuffer(length)))
        if (length > 0)
        {
            if ((expr = cond->GetNextItem()))
            do
            {
                if (expr->GetLength()>0)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));

            result.Write(buffer, length);
        }
        return e_ERROR_NONE;
    }
} g_cThenIfTFunction
  ("then-if","then-if(todo,(do),...)");

/**
 **********************************************************************
 *  Class: cThenElseTFunction
 *
 * Author: $author$
 *   Date: 4/5/2008
 **********************************************************************
 */
class cThenElseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cThenElseTFunction
     *
     *      Author: $author$
     *        Date: 4/5/2008
     **********************************************************************
     */
    cThenElseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"todo","test condition then do"},
           {"(else),...","do else todo"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/5/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length;
        const char *buffer;
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((buffer = cond->GetBuffer(length)))
        if (length > 0)
        {
            if ((expr = cond->GetNextItem()))
            do
            {
                if (expr->GetLength()<1)
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));

            result.Write(buffer, length);
        }
        return e_ERROR_NONE;
    }
} g_cThenElseTFunction
("then-else","then-else(todo,(else),...)");

/**
 **********************************************************************
 *  Class: cCaseTFunction
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
class cCaseTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cCaseTFunction
     *
     *      Author: $author$
     *        Date: 12/28/2008
     **********************************************************************
     */
    cCaseTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"when","conditional test"},
           {"(do),...","conditional expansion"},
           {"(otherwise)","otherwise expansion"},
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
        eError error;
        TLENGTH length;
        cTFunctionArgument *when;
        cTFunctionArgument *expr;

        if ((when = arglist.GetFirstItem()))
        if ((expr = when->GetNextItem()))
        {
            do
            {
                if (0 >= (length = when->GetLength()))
                {
                    if ((when = expr->GetNextItem()))
                    {
                        if ((expr = when->GetNextItem()))
                            continue;

                        else if ((error = t.Expand(result, *when)))
                                return error;
                    }
                    break;
                }

                if ((error = t.Expand(result, *expr)))
                    return error;

                break;
            }
            while (when);
        }
        else if ((error = t.Expand(result, *when)))
                return error;

        return e_ERROR_NONE;
    }
} g_cCaseTFunction
  ("case","case(when,(do)[[,...,when,(do),](otherwise)])");

/**
 **********************************************************************
 *  Class: cSwitchTFunction
 *
 * Author: $author$
 *   Date: 12/28/2008
 **********************************************************************
 */
class cSwitchTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cSwitchTFunction
     *
     *      Author: $author$
     *        Date: 12/28/2008
     **********************************************************************
     */
    cSwitchTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","conditional value"},
           {"case","conditional match"},
           {"(do),...","conditional expansion"},
           {"(otherwise)","otherwise expansion"},
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
        int unequal;
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *match;
        cTFunctionArgument *expr;

        if ((cond = arglist.GetFirstItem()))
        if ((match = cond->GetNextItem()))
        {
            if ((expr = match->GetNextItem()))
            do
            {
                if ((unequal = cond->Compare(*match)))
                {
                    if ((match = expr->GetNextItem()))
                    if ((expr = match->GetNextItem()))
                        continue;

                    else if ((error = t.Expand(result, *match)))
                            return error;

                    break;
                }

                if ((error = t.Expand(result, *expr)))
                    return error;

                break;
            }
            while (match);
        }
        else if ((error = t.Expand(result, *cond)))
                return error;

        return e_ERROR_NONE;
    }
} g_cSwitchTFunction
("switch","switch(cond,case,(do)[[,...,case,(do),](otherwise)])");

/**
 **********************************************************************
 *  Class: cIfYesTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cIfYesTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIfYesTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cIfYesTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","test condition"},
           {"(do)","do if cond is 'yes'"},
           {"(else)...","do else"},
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
        const char* yes = "yes";
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;
        int unequal;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if (!(unequal = cond->Compare(yes)))
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cIfYesTFunction
  ("if-yes","if-yes(cond,(do),(else),...)");

/**
 **********************************************************************
 *  Class: cElseYesTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cElseYesTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cElseYesTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cElseYesTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","test condition"},
           {"(do)","do if cond is not 'yes'"},
           {"(else)...","do else"},
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
        const char* yes = "yes";
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;
        TLENGTH length;
        int unequal;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if ((0 < (length = cond->GetLength()))
            && (unequal = cond->Compare(yes)))
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cElseYesTFunction
("else-yes","else-yes(cond,(do),(else),...)");

/**
 **********************************************************************
 *  Class: cIfNoTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cIfNoTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cIfNoTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cIfNoTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","test condition"},
           {"(do)","do if cond is 'no'"},
           {"(else)...","do else"},
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
        const char* no = "no";
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;
        int unequal;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if (!(unequal = cond->Compare(no)))
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cIfNoTFunction
  ("if-no","if-no(cond,(do),(else),...)");

/**
 **********************************************************************
 *  Class: cElseNoTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cElseNoTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cElseNoTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cElseNoTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","test condition"},
           {"(do)","do if cond is not 'no'"},
           {"(else)...","do else"},
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
        const char* no = "no";
        eError error;
        cTFunctionArgument *cond;
        cTFunctionArgument *expr;
        TLENGTH length;
        int unequal;

        if ((cond = arglist.GetFirstItem()))
        if ((expr = cond->GetNextItem()))
        if ((0 < (length = cond->GetLength()))
            && (unequal = cond->Compare(no)))
        {
            if ((error = t.Expand(result, *expr)))
                return error;
        }
        else if ((expr = expr->GetNextItem()))
        {
            do
            {
                if ((error = t.Expand(result, *expr)))
                    return error;
            }
            while((expr = expr->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cElseNoTFunction
("else-no","else-no(cond,(do),(else),...)");

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
