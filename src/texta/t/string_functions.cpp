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
///   File: string_functions.cpp
///
/// Author: $author$
///   Date: 3/22/2016
///////////////////////////////////////////////////////////////////////
#include "texta/t/functions.hpp"

namespace texta {
namespace t {

///////////////////////////////////////////////////////////////////////
///  Class: parse_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS parse_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    parse_function(const char *name, const char *description)
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
        function_argument
            *val = 0, *delim = 0,
            *before = 0, *between = 0, *after = 0,
            *expr = 0, *var = 0;

        if ((val = args.first_argument()) && (0 < val->length())
            && ((delim = val->next_argument())) && (0 < delim->length())) {
            if ((before = delim->next_argument())) {
                if ((between = before->next_argument())) {
                    if ((after = between->next_argument())) {
                        if ((expr = after->next_argument())) {
                            if ((var = expr->next_argument())) {
                                if (1 > (var->length())) var = 0;
                            }
                            if (1 > (expr->length())) expr = 0;
                        }
                        if (1 > (after->length())) after = 0;
                    }
                    if (1 > (between->length())) between = 0;
                }
                if (1 > (before->length())) before = 0;
            }
            expand
            (out, p, val->chars(), val->length(),
             delim->chars(), delim->length(),
             before, between, after, expr, var);
        }
        return true;
    }
    virtual bool expand
    (output &out, processor &p,
     const char *val, size_t val_length, const char *delim, size_t delim_length,
     function_argument *before, function_argument *between, function_argument *after,
     function_argument *expr, function_argument *var) const {
        if (val_length > delim_length) {
            const char *chars = val, *found = 0;
            TEXTA_LOG_MESSAGE_DEBUG("chars_t::find(\"" << chars << "\", \"" << delim << "\")...");
            if ((found = chars_t::find(chars, delim))) {
                TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(chars, found - chars) << " = chars_t::find(\"" << chars << "\", \"" << delim << "\")");
                do {
                    expand
                    (out, p, chars, found - chars,
                     before, after, expr, var);
                    if ((between)) {
                        out.write(between->chars());
                    }
                    chars = (found + delim_length);
                    TEXTA_LOG_MESSAGE_DEBUG("chars_t::find(\"" << chars << "\", \"" << delim << "\")...");
                    if ((found = chars_t::find(chars, delim))) {
                        TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(chars, found - chars) << " = chars_t::find(\"" << chars << "\", \"" << delim << "\")");
                    } else {
                        if (val_length > (chars - val)) {
                            expand
                            (out, p, chars,
                             val_length - (chars - val),
                             before, after, expr, var);
                        }
                    }
                } while (found);
            }
        }
        return true;
    }
    virtual bool expand
    (output &out, processor &p,
     const char *chars, size_t length,
     function_argument *before, function_argument *after,
     function_argument *expr, function_argument *var) const {
        if ((before)) {
            out.write(before->chars());
        }
        if ((expr)) {
            if ((var)) {
                string val(chars, length);
                p.push_variable(*var, val);
            }
            p.expand(out, *expr);
            expr->seek(0);
            if ((var)) {
                p.pop_variable(*var);
            }
        } else {
            out.write(chars, length);
        }
        if ((after)) {
            out.write(after->chars());
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_parse_function
  ("parse", "parse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])"),
  the_lparse_function
  ("lparse", "lparse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])");

///////////////////////////////////////////////////////////////////////
///  Class: reverse_parse_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS reverse_parse_function: public parse_function {
public:
    typedef parse_function Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    reverse_parse_function(const char *name, const char *description)
    : Extends(name, description) {
        static function_parameter parameter[]
        = {{0,0}};
        set_parameter(parameter);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::expand;
    virtual bool expand
    (output &out, processor &p,
     const char *val, size_t val_length, const char *delim, size_t delim_length,
     function_argument *before, function_argument *between, function_argument *after,
     function_argument *expr, function_argument *var) const {
        if (val_length > delim_length) {
            const char *chars = val, *begin = chars, *end = chars + val_length, *found = 0;
            TEXTA_LOG_MESSAGE_DEBUG("chars_t::find_reverse(\"" << chars << "\", \"" << delim << "\", 0, " << delim_length << ", " << (end - chars) << ")...");
            if ((found = chars_t::find_reverse(chars, delim))) {
                begin = found + delim_length;
                TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(begin, end - begin) << " = chars_t::find_reverse(\"" << chars << "\", \"" << delim << "\", 0, " << delim_length << ", " << (end - chars) << ")");
                do {
                    expand
                    (out, p, begin, end - begin,
                     before, after, expr, var);
                    if ((between)) {
                        out.write(between->chars());
                    }
                    end = found;
                    TEXTA_LOG_MESSAGE_DEBUG("chars_t::find_reverse(" << chars_to_string(chars, end - chars) << ", \"" << delim << "\", 0, " << delim_length << ", " << (end - chars) << ")...");
                    if ((found = chars_t::find_reverse
                          (chars, delim, 0, delim_length, end - chars))) {
                        begin = found + delim_length;
                        TEXTA_LOG_MESSAGE_DEBUG("..." << chars_to_string(begin, end - begin) << " = chars_t::find_reverse(" << chars_to_string(chars, end - chars) << ", \"" << delim << "\", 0, " << delim_length << ", " << (end - chars) << ")");
                    } else {
                        if (0 < (end - chars)) {
                            expand
                            (out, p, chars, (end - chars),
                             before, after, expr, var);
                        }
                    }
                } while (found);
            }
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_reverse_parse_function
  ("reverse-parse", "reverse-parse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])"),
  the_rparse_function
  ("rparse", "rparse(string,delim[,(before)[,(between)[,[(after),](expr),var]]])");

///////////////////////////////////////////////////////////////////////
///  Class: left_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_function
  ("left", "left(string,pattern)");

///////////////////////////////////////////////////////////////////////
///  Class: right_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS right_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    right_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_right_function
  ("right", "right(string,pattern)");

///////////////////////////////////////////////////////////////////////
///  Class: left_char_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_char_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_char_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_char_function
  ("left-char", "left-char(string)");

///////////////////////////////////////////////////////////////////////
///  Class: left_chars_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_chars_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_chars_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_chars_function
  ("left-chars", "left-chars(string)");

///////////////////////////////////////////////////////////////////////
///  Class: left_of_right_char_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_of_right_char_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_of_right_char_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_of_right_char_function
  ("left-of-right-char", "left-of-right-char(string)");

///////////////////////////////////////////////////////////////////////
///  Class: left_of_right_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS left_of_right_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    left_of_right_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_left_of_right_function
  ("left-of-right", "left-of-right(string,pattern)");

///////////////////////////////////////////////////////////////////////
///  Class: length_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS length_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    length_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_length_function
  ("length", "length(string,...)");

///////////////////////////////////////////////////////////////////////
///  Class: replace_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS replace_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    replace_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_replace_function
  ("replace", "replace(from,to,string,...)");

///////////////////////////////////////////////////////////////////////
///  Class: right_char_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS right_char_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    right_char_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_right_char_function
  ("right-char", "right-char(string)");

///////////////////////////////////////////////////////////////////////
///  Class: right_chars_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS right_chars_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    right_chars_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_right_chars_function
  ("right-chars", "right-chars(string)");

///////////////////////////////////////////////////////////////////////
///  Class: right_of_left_char_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS right_of_left_char_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    right_of_left_char_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_right_of_left_char_function
  ("right-of-left-char", "right-of-left-char(string)");

///////////////////////////////////////////////////////////////////////
///  Class: right_of_left_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS right_of_left_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    right_of_left_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_right_of_left_function
  ("right-of-left", "right-of-left(string,pattern)");

///////////////////////////////////////////////////////////////////////
///  Class: strlen_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS strlen_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    strlen_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_strlen_function
  ("strlen", "strlen(string,...)");

///////////////////////////////////////////////////////////////////////
///  Class: strpad_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS strpad_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    strpad_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_strpad_function
  ("strpad", "strpad(string,...,padding,padlen)");

///////////////////////////////////////////////////////////////////////
///  Class: tolower_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS tolower_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    tolower_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_tolower_function
  ("tolower", "tolower(string,...)");

///////////////////////////////////////////////////////////////////////
///  Class: toupper_function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS toupper_function: public function_extend {
public:
    typedef function_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    toupper_function(const char *name, const char *description)
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
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
} the_toupper_function
  ("toupper", "toupper(string,...)");

} // namespace t
} // namespace texta
