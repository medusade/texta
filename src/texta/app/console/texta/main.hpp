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
///   File: main.hpp
///
/// Author: $author$
///   Date: 3/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_APP_CONSOLE_TEXTA_MAIN_HPP
#define _TEXTA_APP_CONSOLE_TEXTA_MAIN_HPP

#include "texta/t/processor.hpp"
#include "texta/t/function_list.hpp"
#include "texta/io/logger.hpp"
#include "xos/base/getopt/main.hpp"
#include "xos/base/avl/tree.hpp"
#include "xos/base/binary/tree.hpp"

namespace texta {
namespace app {
namespace console {
namespace texta {

typedef xos::base::getopt::main_implements main_implements;
typedef xos::base::getopt::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS output: public ::texta::t::output {
    public:
        output(main_extends& main): main_(main) {}
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual ssize_t write(const char* out, ssize_t length) {
            ssize_t count = main_.out(out, length);
            return count;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        main_extends& main_;
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS input: public ::texta::t::input {
    public:
        input(main_extends& main): main_(main) {}
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual ssize_t read(char* in, size_t size) {
            ssize_t count = main_.in(in, size);
            return count;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        main_extends& main_;
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        ::texta::t::processor p;
        if ((p.init())) {
            output out(*this);
            input in(*this);
            ssize_t count = 0;
            count = p.expand(out, in);
            p.fini();
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int _run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char* a2z = "ABCDEFGHIJKLMNOPQRTSUVWXYZ";
        xos::base::avl::branch b[26];
        xos::base::avl::tree t;
        size_t i, n;
        for (i = (n = xos::base::chars_t::count(a2z)); i > 0; --i) {
            xos::base::leaf& l = b[n-i].leaf();
            xos::base::leaf::what_t& w = l.what();
            w.assign(a2z + i - 1, 1);
            t.insert(b[n-i]);
        }
        for (xos::base::avl::branch* b = t.first();  b; b = t.next(*b)) {
            out(b->leaf().what().chars());
        }
        outln();
        for (i = (n = xos::base::chars_t::count(a2z)); i > 0; --i) {
            t.remove(b[n-i]);
            for (xos::base::avl::branch* b = t.first();  b; b = t.next(*b)) {
                out(b->leaf().what().chars());
            }
            outln();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace texta 
} // namespace console 
} // namespace app 
} // namespace texta 

#endif // _TEXTA_APP_CONSOLE_TEXTA_MAIN_HPP 
        

