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
 *   File: ctbase.hxx
 *
 * Author: $author$
 *   Date: 9/29/2017
 **********************************************************************
 */
#ifndef _XDE_CT_CTBASE_HXX
#define _XDE_CT_CTBASE_HXX

#include "xde/cos/cfile.hxx"
#include "xde/cbase/cbuffer.hxx"
#include "xde/cbase/cstring.hxx"
#include "xde/cbase/cstream.hxx"
#include "xde/cbase/clist.hxx"
#include "xde/cbase/cbinarytree.hxx"
#include "xde/cbase/cdigitizer.hxx"
#include "xde/cbase/csplitter.hxx"
#include "xde/cdebug/cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Typedef: tTNameChars
 *
 *  Author: $author$
 *    Date: 3/31/2008
 **********************************************************************
 */
typedef const char* tTNameChars;

/**
 **********************************************************************
 *   Enum: eTError
 *
 * Author: $author$
 *   Date: 8/2/2003
 **********************************************************************
 */
typedef int eTError;
enum {
    e_FIRST_T_ERROR = e_NEXT_ERROR,

    e_ERROR_EXPAND = e_FIRST_T_ERROR,
    e_ERROR_BREAK,
    e_ERROR_EXIT,

    e_NEXT_T_ERROR,
    e_LAST_T_ERROR = e_NEXT_T_ERROR-1
};

/**
 **********************************************************************
 *  Class: cTException
 *
 * Author: $author$
 *   Date: 5/31/2017
 **********************************************************************
 */
class cTException {
public:
    /**
     **********************************************************************
     * Constructor: cTException
     *
     *      Author: $author$
     *        Date: 6/9/2017
     **********************************************************************
     */
    cTException(eTError error): m_error(error) {
    }
    cTException(const cTException& copy): m_error(copy.m_error) {
    }
    virtual ~cTException() {
    }
    /**
     **********************************************************************
     * Function: Error
     *
     *   Author: $author$
     *     Date: 6/9/2017
     **********************************************************************
     */
    virtual eTError Error() const {
        eTError error = m_error;
        return error;
    }
protected:
    eTError m_error;
};

class c_INTERFACE_CLASS cTInterface;
class c_INTERFACE_CLASS cT;

class c_INTERFACE_CLASS cTFunctionInterface;
class c_EXPORT_CLASS cTFunctionItem;
class c_EXPORT_CLASS cTFunctionList;
class c_EXPORT_CLASS cTFunctionBranch;
class c_EXPORT_CLASS cTFunctionTree;
class c_EXPORT_CLASS cTFunctionParameter;
class c_EXPORT_CLASS cTFunctionArgument;
class c_EXPORT_CLASS cTFunctionArgumentList;
class c_EXPORT_CLASS cTFunction;

class c_INTERFACE_CLASS cTVariableInterface;
class c_EXPORT_CLASS cTVariable;

class c_INTERFACE_CLASS cTValueInterface;
class c_EXPORT_CLASS cTValue;

typedef cListItemT<cTFunctionItem, cBase> cTFunctionItemExtends;
/**
 **********************************************************************
 *  Class: cTFunctionItem
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class c_EXPORT_CLASS cTFunctionItem: public cTFunctionItemExtends {
public:
    typedef cTFunctionItemExtends cExtends;
    typedef cTFunctionItem cDerives;

    cTFunctionInterface &m_function;

    /**
     **********************************************************************
     * Constructor: cTFunctionItem
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cTFunctionItem(cTFunctionInterface &function) : m_function(function) {
    }
    /**
     **********************************************************************
     * Function: GetFunction
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline cTFunctionInterface& GetFunction() const {
        return (cTFunctionInterface&)(m_function);
    }
};

typedef cStaticListT<cTFunctionItem, cBase> cTFunctionListExtends;
/**
 **********************************************************************
 *  Class: cTFunctionList
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class c_EXPORT_CLASS cTFunctionList: public cTFunctionListExtends {
public:
    typedef cTFunctionListExtends cExtends;
    typedef cTFunctionList cDerives;
};

/**
 **********************************************************************
 *  Class: cTFunctionInterface
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cTFunctionInterface: virtual public cInterfaceBase {
public:
    typedef cInterfaceBase cImplements;
    typedef cTFunctionInterface cDerives;
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError Initialize(cTInterface &t) = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError Finalize(cTInterface &t) = 0;
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t,
     const cTFunctionArgumentList &arglist) const = 0;
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 4/1/2008
     **********************************************************************
     */
    virtual int CompareName
    (const char* toChars, int length = -1) const = 0;
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual const char *GetName() const = 0;
    /**
     **********************************************************************
     * Function: GetDescription
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual const char *GetDescription
    (const cTFunctionParameter *&parameter, int &parameters) const = 0;
    /**
     **********************************************************************
     * Function: GetItem
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual cTFunctionItem &GetItem() const = 0;
    /**
     **********************************************************************
     * Function: GetBranch
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual cTFunctionBranch &GetBranch() const = 0;
};

/**
 **********************************************************************
 *  Class: cTValueInterface
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cTValueInterface: virtual public cInterfaceBase {
public:
    typedef cInterfaceBase cImplements;
    typedef cTValueInterface cDerives;
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError Set
    (const char *value, int valuelen = -1) = 0;
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual const char *Get() const = 0;
};

/**
 **********************************************************************
 *  Class: cTVariableInterface
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cTVariableInterface: virtual public cInterfaceBase {
public:
    typedef cInterfaceBase cImplements;
    typedef cTVariableInterface cDerives;
    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError SetValue
    (const char *value, int valuelen = -1) = 0;
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual const char *GetValue() const = 0;
    /**
     **********************************************************************
     * Function: PushValue
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError PushValue
    (const char *value, int valuelen = -1) = 0;
    /**
     **********************************************************************
     * Function: PopValue
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    virtual eError PopValue() = 0;
};
/**
 **********************************************************************
 *  Class: cTParameterInterface
 *
 * Author: $author$
 *   Date: 1/12/2009
 **********************************************************************
 */
class c_INTERFACE_CLASS cTParameterInterface: virtual public cInterfaceBase {
public:
    typedef cInterfaceBase cExtends;
    typedef cTParameterInterface cDerives;

    /**
     **********************************************************************
     * Function: GetFirstParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetFirstParameter
    (int& length, const char*& named, int& namedLength) = 0;
    /**
     **********************************************************************
     * Function: GetLastParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetLastParameter
    (int& length, const char*& named, int& namedLength) = 0;
    /**
     **********************************************************************
     * Function: GetNextParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetNextParameter
    (int& length, const char*& named, int& namedLength) = 0;
    /**
     **********************************************************************
     * Function: GetPrevParameter
     *
     *   Author: $author$
     *     Date: 1/12/2009
     **********************************************************************
     */
    virtual const char* GetPrevParameter
    (int& length, const char*& named, int& namedLength) = 0;
};
/**
 **********************************************************************
 *  Class: cTInterface
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class c_INTERFACE_CLASS cTInterface: virtual public cTParameterInterface {
public:
    typedef cTParameterInterface cImplements;
    typedef cTInterface cDerives;

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 4/1/2008
     **********************************************************************
     */
    virtual eError Initialize() = 0;
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 4/1/2008
     **********************************************************************
     */
    virtual eError Finalize() = 0;

    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &out, cCharStreamInterface &in) = 0;
    /**
     **********************************************************************
     * Function: ExpandFunction
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError ExpandFunction
    (cCharStreamInterface &out,
     const cTFunctionArgumentList &args, const char* name) = 0;

    /**
     **********************************************************************
     * Function: GetFirstFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cTFunctionInterface* GetFirstFunction() = 0;
    /**
     **********************************************************************
     * Function: GetNextFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cTFunctionInterface* GetNextFunction() = 0;
    /**
     **********************************************************************
     * Function: FindFunction
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual cTFunctionInterface*
    FindFunction(const char *name, int namelen = -1) const = 0;

    /**
     **********************************************************************
     * Function: ExpandVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual eError ExpandVariable
    (cCharStreamInterface &out, const char* name) = 0;
    /**
     **********************************************************************
     * Function: SetVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual cTVariableInterface* SetVariable
    (const char *name,int namelen = -1,
     const char *value = 0,int valuelen = -1) = 0;
    /**
     **********************************************************************
     * Function: GetVariable
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual cTVariableInterface* GetVariable
    (const char *name,int namelen = -1,
     const char *value = 0,int valuelen = -1) = 0;

    /**
     **********************************************************************
     * Function: SetValue
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual const char *SetValue
    (const char *name,int namelen = -1,
     const char *value = 0,int valuelen = -1) = 0;
    /**
     **********************************************************************
     * Function: GetValue
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    virtual const char *GetValue
    (const char *name,int namelen = -1) = 0;
    /**
     **********************************************************************
     * Function: AddFunction
     *
     *   Author: $author$
     *     Date: 9/29/2017
     **********************************************************************
     */
    virtual void AddFunction(cTFunctionItem& item) = 0;
    /**
     **********************************************************************
     * Function: RemoveFunction
     *
     *   Author: $author$
     *     Date: 9/29/2017
     **********************************************************************
     */
    virtual void RemoveFunction(cTFunctionItem& item) = 0;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CT_CTBASE_HXX */
