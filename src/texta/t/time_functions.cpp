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
///   File: time_functions.cpp
///
/// Author: $author$
///   Date: 5/23/2016
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"
#include "xos/os/time.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
///  Class: year_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS year_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    year_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        xos::os::current::time t;
        result r;
        r.append_int(t.year());
        out.write(r);
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_year_function
  ("year", "year([year,(do)])");

///////////////////////////////////////////////////////////////////////
///  Class: month_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS month_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    month_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        xos::os::current::time t;
        result r;
        r.append_int(t.month());
        out.write(r);
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_month_function
  ("month", "month([month,(do)])");

///////////////////////////////////////////////////////////////////////
///  Class: day_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS day_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    day_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        xos::os::current::time t;
        result r;
        r.append_int((int)t.day());
        out.write(r);
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_day_function
  ("day", "day([day,(do)])");

///////////////////////////////////////////////////////////////////////
///  Class: date_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS date_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    date_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand
    (output &out, processor &p,
     const function_argument_list &args) const {
        xos::os::current::time t;
        result r;
        r.append_int(t.month());
        r.append("/");
        r.append_int((int)t.day());
        r.append("/");
        r.append_int(t.year());
        out.write(r);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_date_function
  ("date", "date([month,day,year,(do)])");

} // namespace t
} // namespace texta
