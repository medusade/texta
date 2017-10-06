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
 *   File: ctcomparefunctions.cxx
 *
 * Author: $author$
 *   Date: 10/1/2017
 **********************************************************************
 */
#include "xde/ct/ctcomparefunctions.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cNotWhatTFunction
 *
 * Author: $author$
 *   Date: 5/30/2017
 **********************************************************************
 */
class cNotWhatTFunction: public cTFunction {
protected:
    const char* m_what;
public:
    typedef cTFunction cExtends;
    /**
     **********************************************************************
     * Constructor: cNotWhatTFunction
     *
     *      Author: $author$
     *        Date: 5/30/2017
     **********************************************************************
     */
    cNotWhatTFunction
    (const char* name, const char* description, const char* what)
    : cExtends(name, description), m_what(what) {
        static cTFunctionParameter parameter[]
        = {{"cond,...","return condition is not [what]"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 5/30/2017
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const {
        const char* what = 0;
        cTFunctionArgument *cond = 0;
        const char* chars = 0;
        TLENGTH length = 0;
        int unequal = 0;

        if ((cond = arglist.GetFirstItem())) {
            if (!(what = m_what)) {
                if ((what = cond->GetBuffer())) {
                    if (!(what[0])) {
                        what = 0;
                    }
                }
                cond = cond->GetNextItem();
            }
            if ((what) && (cond)) {
                do {
                    if ((0 < (length = cond->GetLength()))
                        && (unequal = cond->Compare(what))) {
                        if ((chars = cond->GetBuffer())) {
                            result.Write(chars, length);
                        }
                    }
                } while ((cond = cond->GetNextItem()));
            }
        }
        return e_ERROR_NONE;
    }
} g_cNotWhatTFunction
  ("not-what","not-what(what,cond,...)", 0);

/**
 **********************************************************************
 *  Class: cNotNoTFunction
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class cNotNoTFunction: public cNotWhatTFunction {
public:
    typedef cNotWhatTFunction cExtends;
    /**
     **********************************************************************
     * Constructor: cNotNoTFunction
     *
     *      Author: $author$
     *        Date: 1/12/2009
     **********************************************************************
     */
    cNotNoTFunction(const char* name, const char* description)
    : cExtends(name, description, "no") {
        static cTFunctionParameter parameter[]
        = {{"cond,...","return condition is not 'no'"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
} g_cNotNoTFunction
  ("not-no","not-no(cond,...)");

/**
 **********************************************************************
 *  Class: cNotYesTFunction
 *
 * Author: $author$
 *   Date: 5/30/2017
 **********************************************************************
 */
class cNotYesTFunction: public cNotWhatTFunction {
public:
    typedef cNotWhatTFunction cExtends;
    /**
     **********************************************************************
     * Constructor: cNotYesTFunction
     *
     *      Author: $author$
     *        Date: 5/30/2017
     **********************************************************************
     */
    cNotYesTFunction(const char* name, const char* description)
    : cExtends(name, description, "yes") {
        static cTFunctionParameter parameter[]
        = {{"cond,...","return condition is not 'yes'"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
} g_cNotYesTFunction
  ("not-yes","not-yes(cond,...)");

/**
 **********************************************************************
 *  Class: cAndTFunction
 *
 * Author: $author$
 *   Date: 1/14/2009
 **********************************************************************
 */
class cAndTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cAndTFunction
     *
     *      Author: $author$
     *        Date: 1/14/2009
     **********************************************************************
     */
    cAndTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","test condition"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/14/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *cond;
        const char* chars;
        TLENGTH length;

        if ((cond = arglist.GetFirstItem()))
        {
            do
            {
                if (0 >= (length = cond->GetLength()))
                    return e_ERROR_NONE;
            }
            while((cond = cond->GetNextItem()));

            if ((cond = arglist.GetFirstItem()))
            do
            {
                if ((chars = cond->GetBuffer(length)))
                    result.Write(chars, length);
            }
            while((cond = cond->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cAndTFunction
  ("and","and(cond,...)");

/**
 **********************************************************************
 *  Class: cOrTFunction
 *
 * Author: $author$
 *   Date: 1/14/2009
 **********************************************************************
 */
class cOrTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cOrTFunction
     *
     *      Author: $author$
     *        Date: 1/14/2009
     **********************************************************************
     */
    cOrTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","test condition"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/14/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        cTFunctionArgument *cond;
        const char* chars;
        TLENGTH length;

        if ((cond = arglist.GetFirstItem()))
        {
            do
            {
                if ((chars = cond->GetBuffer(length)))
                if (0 < length)
                {
                    result.Write(chars, length);
                    break;
                }
            }
            while((cond = cond->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cOrTFunction
  ("or","or(cond,...)");

/**
 **********************************************************************
 *  Class: cXorTFunction
 *
 * Author: $author$
 *   Date: 1/14/2009
 **********************************************************************
 */
class cXorTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cXorTFunction
     *
     *      Author: $author$
     *        Date: 1/14/2009
     **********************************************************************
     */
    cXorTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"cond","test condition"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 1/14/2009
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        bool one = false;
        cTFunctionArgument *cond;
        const char* chars;
        TLENGTH length;

        if ((cond = arglist.GetFirstItem()))
        {
            do
            {
                if (0 < (length = cond->GetLength()))
                if (one)
                    return e_ERROR_NONE;
                else one = true;
            }
            while((cond = cond->GetNextItem()));

            if ((cond = arglist.GetFirstItem()))
            do
            {
                if ((chars = cond->GetBuffer(length)))
                    result.Write(chars, length);
            }
            while((cond = cond->GetNextItem()));
        }
        return e_ERROR_NONE;
    }
} g_cXorTFunction
  ("xor","xor(cond,...)");

/**
 **********************************************************************
 *  Class: cEqualTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cEqualTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cEqualTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cEqualTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string,...","strings to compare"},
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
        int unequal;
        TLENGTH length, length2;
        const char *buffer, *buffer2;
        cTFunctionArgument *arg;
        cCharComparer comparer;

        if ((arg = arglist.GetFirstItem()))
        if ((buffer = arg->GetBuffer(length)))
        {
            while((arg = arg->GetNextItem()))
            {
                if ((buffer2 = arg->GetBuffer(length2)))
                if (!(unequal = comparer.Compare
                    (buffer, length, buffer2, length2)))
                    continue;

                return e_ERROR_NONE;
            }

            if (length>0)
                result.Write(buffer, length);
        }
        return e_ERROR_NONE;
    }
} g_cEqualTFunction
  ("equal","equal(string,...)");

/**
 **********************************************************************
 *  Class: cUnequalTFunction
 *
 * Author: $author$
 *   Date: 4/6/2008
 **********************************************************************
 */
class cUnequalTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cUnequalTFunction
     *
     *      Author: $author$
     *        Date: 4/6/2008
     **********************************************************************
     */
    cUnequalTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
        static cTFunctionParameter parameter[]
        = {{"string,...","strings to compare"},
           {0,0}};
        m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
        m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/6/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList& arglist) const
    {
        int unequal;
        TLENGTH length, length1, length2;
        const char *buffer, *buffer1, *buffer2;
        cTFunctionArgument *arg, *arg1, *arg2;
        cCharComparer comparer;

        if ((arg2 = (arg1 = arglist.GetFirstItem())))
        if ((buffer1 = arg1->GetBuffer(length1)))
        {
            while((arg2 = arg2->GetNextItem()))
            {
                if ((buffer2 = arg2->GetBuffer(length2)))
                if ((unequal = comparer.Compare
                    (buffer1, length1, buffer2, length2)))
                {
                    for (arg = arg1->GetNextItem();
                         arg && (arg != arg2);
                         arg = arg->GetNextItem())
                    {
                        if ((buffer = arg->GetBuffer(length)))
                        if ((unequal = comparer.Compare
                            (buffer, length, buffer2, length2)))
                            continue;

                        unequal = false;
                    }

                    if (unequal)
                        continue;
                }

                return e_ERROR_NONE;
            }

            if (length>0)
                result.Write(buffer1, length1);
        }
        return e_ERROR_NONE;
    }
} g_cUnequalTFunction
  ("unequal","unequal(string,...)");

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */
