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
 *   File: ctvariable.hxx
 *
 * Author: $author$
 *   Date: 9/30/2017
 **********************************************************************
 */
#ifndef _XDE_CT_CTVARIABLE_HXX
#define _XDE_CT_CTVARIABLE_HXX

#include "xde/ct/ctvalue.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cBalancedBinaryTreeBranchT
<tTNameChars,cTVariable,cBase> cTVariableExtend;
/**
 **********************************************************************
 *  Class: cTVariable
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class cTVariable
: virtual public cTVariableInterface, public cTVariableExtend {
public:
    typedef cTVariableInterface cImplements;
    typedef cTVariableExtend cExtends;
    typedef cTVariable cDerives;

    cCharBuffer m_name;
    cTValue m_value;
    cTValueList m_value_list;
    cTValueList m_value_free_list;

    /**
     **********************************************************************
     * Constructor: cTVariable
     *
     *      Author: $author$
     *        Date: 3/31/2008
     **********************************************************************
     */
    cTVariable
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1)
    : m_value(value, valuelen) {
        eError error = 0;
        int count = 0;

        if (name) {
            if ((count = m_name.Write(name,namelen)) < 0)
                throw (error = e_ERROR_WRITE);
        }
    }
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError SetValue
    (const char *value, int valuelen=-1) {
        cTValue *cvalue;

        if ((cvalue=m_value_list.GetFirstItem()))
            return cvalue->Set(value,valuelen);

        return m_value.Set(value,valuelen);
    }
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual const char *GetValue() const {
        cTValue *value;

        if ((value=m_value_list.GetFirstItem()))
            return value->Get();

        return m_value.Get();
    }
    /**
     **********************************************************************
     * Function: PushValue
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError PushValue
    (const char *value, int valuelen=-1) {
        eError error = 0;
        cTValue *cvalue = 0;

        if ((cvalue=m_value_free_list.PopItem())) {
            if ((error=cvalue->Set(value,valuelen))) {
                delete cvalue;
                return error;
            }
        }
        else {
            if (!(cvalue=new cTValue(value,valuelen)))
                return e_ERROR_NEW;
        }
        m_value_list.PushItem(*cvalue);
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: PopValue
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError PopValue() {
        cTValue *cvalue = 0;

        if (!(cvalue=m_value_list.PopItem()))
            return e_ERROR_FAILED;

        m_value_free_list.PushItem(*cvalue);
        return e_ERROR_NONE;
    }

    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    int Compare(const cTVariable &branch) const {
        return Compare(branch.GetName());
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    int Compare(const tTNameChars& name) const  {
        return m_name.Compare(name);
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    int Compare(const tTNameChars& name, int length) const {
        return m_name.Compare(name, length);
    }

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    inline const char* GetName() const {
        return m_name.GetBuffer();
    }
};

typedef cBalancedBinaryTreeT
<tTNameChars,cTVariable,cBase> cTVariableTreeExtend;
/**
 **********************************************************************
 *  Class: cTVariableTree
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class cTVariableTree: public cTVariableTreeExtend {
public:
    typedef cTVariableTreeExtend cExtends;
    typedef cTVariableTree cDerives;
    /**
     **********************************************************************
     * Constructor: cTVariableTree
     *
     *      Author: $author$
     *        Date: 3/31/2008
     **********************************************************************
     */
    cTVariableTree() {
    }
    /**
     **********************************************************************
     * Function: AddNew
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    eError AddNew
    (cTVariable *&variable,
     const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1) {

        if (!(variable = new cTVariable
            (name, namelen, value, valuelen)))
            return e_ERROR_NEW;

        Insert(variable);
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    cTVariable* Find
    (const char *name, int namelen=-1) const {

        if (namelen<0) {
            return cExtends::Find(name);
        } else {
            if (namelen>0)
                return cExtends::Find(name, namelen);
        }
        return 0;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CT_CTVARIABLE_HXX */
