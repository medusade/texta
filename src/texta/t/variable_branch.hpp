///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: variable_branch.hpp
///
/// Author: $author$
///   Date: 5/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_VARIABLE_BRANCH_HPP
#define _TEXTA_T_VARIABLE_BRANCH_HPP

#include "texta/t/t.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS variable;
class _EXPORT_CLASS variable_branch;
typedef variable& variable_leaf;
typedef xos::base::avl::branch_implements variable_branch_implements;
typedef xos::base::avl::brancht
<variable_leaf, variable_branch, variable_branch_implements,
 xos::base::binary::brancht
 <variable_leaf, variable_branch, xos::base::binary::branch_implements,
  xos::base::brancht<variable_leaf, variable_branch,
  xos::base::branch_implements, xos::base::branch_extends> > > variable_branch_extends;
///////////////////////////////////////////////////////////////////////
///  Class: variable_branch
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS variable_branch:
virtual public variable_branch_implements, public variable_branch_extends {
public:
    typedef variable_branch_implements Implements;
    typedef variable_branch_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    variable_branch(variable_leaf f): Extends(f) {
    }
    virtual ~variable_branch() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t
} // namespace texta

#endif // _TEXTA_T_VARIABLE_BRANCH_HPP
