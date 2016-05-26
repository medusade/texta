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
///   File: function.hpp
///
/// Author: $author$
///   Date: 3/20/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_HPP
#define _TEXTA_T_FUNCTION_HPP

#include "texta/t/t.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS processor;
class _EXPORT_CLASS variable;
class _EXPORT_CLASS function;
class _EXPORT_CLASS function_argument;
class _EXPORT_CLASS function_argument_list;
class _EXPORT_CLASS function_parameter;
class _EXPORT_CLASS function_item;
class _EXPORT_CLASS function_branch;
class _EXPORT_CLASS function_tree;

typedef implement_base function_implement;
///////////////////////////////////////////////////////////////////////
///  Class: function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function: virtual public function_implement {
public:
    typedef function_implement Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init(processor &p) = 0;
    virtual bool fini(processor &p) = 0;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const = 0;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const function& to) const {
        return compare_name(to.name());
    }
    virtual int compare_name(const char* to) const = 0;
    virtual const char *name() const = 0;
    virtual const char *description() const {
        const function_parameter *parameter = 0;
        size_t parameters = 0;
        return description(parameter, parameters);
    }
    virtual const char *description
    (const function_parameter *&parameter, size_t &parameters) const = 0;
    virtual const function_parameter* parameter() const {
        size_t parameters = 0;
        return parameter(parameters);
    }
    virtual const function_parameter* parameter(size_t &parameters) const = 0;
    virtual size_t parameters() const = 0;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual function_item &item() const = 0;
    virtual function_branch &branch() const = 0;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t 
} // namespace texta 

#endif // _TEXTA_T_FUNCTION_HPP 
