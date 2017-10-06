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
 *   File: ctfunction.hxx
 *
 * Author: $author$
 *   Date: 9/29/2017
 **********************************************************************
 */
#ifndef _XDE_CT_CTFUNCTION_HXX
#define _XDE_CT_CTFUNCTION_HXX

#include "xde/ct/ctbase.hxx"
#include "xde/cbase/ccomparer.hxx"
#include "xde/cbase/cbuffer.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cBalancedBinaryTreeBranchT
<tTNameChars,cTFunctionBranch,cBase> cTFunctionBranchExtends;
/**
 **********************************************************************
 *  Class: cTFunctionBranch
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class c_EXPORT_CLASS cTFunctionBranch: public cTFunctionBranchExtends {
public:
    typedef cTFunctionBranchExtends cExtends;
    typedef cTFunctionBranch cDerives;

    cTFunctionInterface &m_function;

    /**
     **********************************************************************
     * Constructor: cTFunctionBranch
     *
     *      Author: $author$
     *        Date: 7/8/2003
     **********************************************************************
     */
    cTFunctionBranch(cTFunctionInterface &function): m_function(function) {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    int Compare(const cTFunctionBranch &branch) const {
        const tTNameChars toLeaf = branch.m_function.GetName();
        return Compare(toLeaf);
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    int Compare(const tTNameChars& toLeaf) const {
        int unequal = m_function.CompareName(toLeaf);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    int Compare(const tTNameChars& toLeaf, int length) const {
        int unequal = m_function.CompareName(toLeaf, length);
        return unequal;
    }
};

typedef cBalancedBinaryTreeT
<tTNameChars,cTFunctionBranch,cBase> cTFunctionTreeExtends;
/**
 **********************************************************************
 *  Class: cTFunctionTree
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionTree: public cTFunctionTreeExtends {
public:
    typedef cTFunctionTreeExtends cExtends;
    typedef cTFunctionTree cDerives;
    /**
     **********************************************************************
     * Function: Add
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    void Add(cTFunctionInterface &function) {
        const char* name;
        if ((name = function.GetName()))
        DBT("() adding function \"%s\"...\n", name);

        cExtends::Insert(&function.GetBranch());
    }
    /**
     **********************************************************************
     * Function: Remove
     *
     *   Author: $author$
     *     Date: 9/30/2017
     **********************************************************************
     */
    void Remove(cTFunctionInterface &function) {
        const char* name;
        if ((name = function.GetName()))
        DBT("() removing function \"%s\"...\n", name);

        cExtends::Delete(&function.GetBranch());
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    cTFunctionInterface* Find
    (const char* name, int namelen=-1) const {
        cTFunctionBranch *branch;

        if (namelen<0)
        {
            if ((branch=cExtends::Find(name)))
                return &branch->m_function;
        }
        else if (namelen>0)
        {
            if ((branch=cExtends::Find(name,namelen)))
                return &branch->m_function;
        }
        return 0;
    }
};

typedef cDynamicListItemT
<cTFunctionArgument, cCharBuffer> cTFunctionArgumentExtends;
/**
 **********************************************************************
 *  Class: cTFunctionArgument
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionArgument: public cTFunctionArgumentExtends {
public:
    typedef cTFunctionArgumentExtends cExtends;
    typedef cTFunctionArgument cDerives;
};

typedef cDynamicListT<cTFunctionArgument,cBase> cTFunctionArgumentListExtend;
/**
 **********************************************************************
 *  Class: cTFunctionArgumentList
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionArgumentList: public cTFunctionArgumentListExtend {
public:
    typedef cTFunctionArgumentListExtend cExtends;
    typedef cTFunctionArgumentList cDerives;
};

/**
 **********************************************************************
 *  Class: cTFunctionParameter
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionParameter {
public:
    typedef cTFunctionParameter cDerives;

    const char *m_name;
    const char *m_description;

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    inline const char *GetName() const {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetDescription
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    inline const char *GetDescription() const {
        return m_description;
    }
};

/**
 **********************************************************************
 *  Class: cTFunction
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class c_EXPORT_CLASS cTFunction
: virtual public cTFunctionInterface, public cBase {
public:
    typedef cTFunctionInterface cImplements;
    typedef cBase cExtends;
    typedef cTFunction cDerives;

    cTFunctionItem m_item;
    cTFunctionBranch m_branch;

    const char *m_name;
    const char *m_description;
    const cTFunctionParameter *m_parameter;
    int m_parameters;

    cCharComparer m_comparer;

    /**
     **********************************************************************
     * Constructor: cTFunction
     *
     *      Author: $author$
     *        Date: 8/2/2003
     **********************************************************************
     */
    cTFunction
    (const char *name, const char *description)
    : m_item(*this), m_branch(*this),
      m_name(name), m_description(description),
      m_parameter(0), m_parameters(0) {
        TheList().AddItem(m_item);
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual eError Initialize(cTInterface &t) {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual eError Finalize(cTInterface &t) {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList &arglist) const {
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 12/26/2008
     **********************************************************************
     */
    virtual cTVariableInterface* GetVariable
    (cTInterface &t, const cTFunctionArgument& name) const {
        cTVariableInterface *variable = 0;
        const char* nameChars;
        TLENGTH nameLength;
        if ((nameChars = name.GetBuffer(nameLength)))
        if (0 < nameLength)
            variable = t.GetVariable(nameChars, nameLength);
        return variable;
    }
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 4/1/2008
     **********************************************************************
     */
    virtual int CompareName
    (const char* toChars, int length=-1) const {
        int unequal = m_comparer.Compare(m_name,-1, toChars, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual const char* GetName() const {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetDescription
     *
     *   Author: $author$
     *     Date: 8/2/2003
     **********************************************************************
     */
    virtual const char* GetDescription
    (const cTFunctionParameter*& parameter, int &parameters) const {
        parameter = m_parameter;
        parameters = m_parameters;
        return m_description;
    }
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual cTFunctionItem& GetItem() const {
        return (cTFunctionItem&)(m_item);
    }
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual cTFunctionBranch& GetBranch() const {
        return (cTFunctionBranch&)(m_branch);
    }
    /**
     **********************************************************************
     * Function: TheList
     *
     *   Author: $author$
     *     Date: 9/29/2017
     **********************************************************************
     */
    static cTFunctionList &TheList() {
        static cTFunctionList list;
        return (cTFunctionList&)(list);
    }
};

/**
 **********************************************************************
 *  Class: cStringTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cStringTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cStringTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cStringTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
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
        TLENGTH length;
        const char *buffer;
        cTFunctionArgument *arg;
        cCharBuffer string;

        if ((arg = arglist.GetFirstItem()))
        do
        {
            if ((buffer = arg->GetBuffer(length)))
            if (length>0)
            if (0 > (length = string.Write(buffer, length)))
                return e_ERROR_WRITE;
        }
        while((arg = arg->GetNextItem()));

        if ((buffer = string.GetBuffer(length)))
        if (length>0)
            return Expand(result, t, buffer, length);

        return e_ERROR_NONE;
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
     const char* buffer, TLENGTH length) const
    {
        return e_ERROR_NONE;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CT_CTFUNCTION_HXX */
