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
 *   File: ctvalue.hxx
 *
 * Author: $author$
 *   Date: 9/30/2017
 **********************************************************************
 */
#ifndef _XDE_CT_CTVALUE_HXX
#define _XDE_CT_CTVALUE_HXX

#include "xde/ct/ctbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cDynamicListItemT<cTValue, cBase> cTValueExtend;
/**
 **********************************************************************
 *  Class: cTValue
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class cTValue: virtual public cTValueInterface, public cTValueExtend {
public:
    typedef cTValueInterface cImplements;
    typedef cTValueExtend cExtends;
    typedef cTValue cDerives;

    cCharBuffer m_value;

    /**
     **********************************************************************
     * Constructor: cTValue
     *
     *      Author: $author$
     *        Date: 3/31/2008
     **********************************************************************
     */
    cTValue(const char *value = 0, int valuelen = -1) {
        eError error;
        int count;

        if (value)
        if ((count = m_value.Write(value,valuelen)) < 0)
            throw (error = e_ERROR_WRITE);
    }
    /**
     **********************************************************************
     * Function: Set
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError Set
    (const char *value, int valuelen = -1) {
        int count;

        if ((count = m_value.Copy(value, valuelen)) < 0)
            return e_ERROR_COPY;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual const char *Get() const {
        return m_value.GetBuffer();
    }
};

typedef cDynamicListT<cTValue, cBase> cTValueListExtend;
/**
 **********************************************************************
 *  Class: cTValueList
 *
 * Author: $author$
 *   Date: 3/31/2008
 **********************************************************************
 */
class cTValueList: public cTValueListExtend {
public:
    typedef cTValueListExtend cExtends;
    typedef cTValueList cDerives;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CT_CTVALUE_HXX */

        

