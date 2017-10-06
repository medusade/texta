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
 *   File: ctmain.hxx
 *
 * Author: $author$
 *   Date: 10/1/2017
 **********************************************************************
 */
#ifndef _XDE_CAPP_CCONSOLE_CT_CTMAIN_HXX
#define _XDE_CAPP_CCONSOLE_CT_CTMAIN_HXX

#include "xde/cconsole/cargmain.hxx"
#include "xde/ct/ct.hxx"
#include "xde/cfs/cfilesystemdirectory.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef cArgMain cTMainExtends;
/**
 **********************************************************************
 *  Class: cTMain
 *
 * Author: $author$
 *   Date: 12/29/2008
 **********************************************************************
 */
class cTMain: public cTMainExtends {
public:
    typedef cTMainExtends cExtends;
    typedef cTMain cDerives;

    const tChar* m_inputVariableNameChars;
    const tChar* m_outputVariableNameChars;
    const tChar* m_inputValueChars;
    const tChar* m_outputValueChars;

    tString m_inFileName;
    tString m_outFileName;

    tFile m_inFile;
    tFile m_outFile;

    cFileSystemDirectoryT<tChar> m_fileSystemDirectory;

    cT m_t;

    /**
     **********************************************************************
     * Constructor: cTMain
     *
     *      Author: $author$
     *        Date: 12/29/2008
     **********************************************************************
     */
    cTMain()
    : m_inputVariableNameChars("input"),
      m_outputVariableNameChars("output"),
      m_inputValueChars("0"),
      m_outputValueChars("1") {
    }

    /**
     **********************************************************************
     * Function: Run
     *
     *   Author: $author$
     *     Date: 12/29/2008
     **********************************************************************
     */
    virtual int Run
    (int argc, const tChar** argv, const tChar** env) {
        int err = 0;
        cCharStreamInterface* in = &m_stdIn;
        cCharStreamInterface* out = &m_stdOut;
        const tChar* inName = m_inputVariableNameChars;
        const tChar* outName = m_outputVariableNameChars;
        const tChar* inValue = m_inputValueChars;
        const tChar* outValue = m_outputValueChars;
        const tChar* chars = 0;
        tLength length = 0;
        eError error = 0;

        if (!(error = m_fileSystemDirectory.GetCurrentWorking())) {
            if ((chars = m_fileSystemDirectory.HasChars(length))) {
                if (!(m_inFileName.Length())) {
                    m_inFileName.Assign(chars, length);
                    m_inFileName.AppendL("/", m_inputValueChars, NULL);
                }
                if (!(m_outFileName.Length())) {
                    m_outFileName.Assign(chars, length);
                    m_outFileName.AppendL("/", m_outputValueChars, NULL);
                }
                if ((chars = m_inFileName.HasChars(length))) {
                    DBF("...input \"%s\" = \"%s\"...\n", inName, chars);
                    inValue = chars;
                }
                if ((chars = m_outFileName.HasChars(length))) {
                    DBF("...output \"%s\" = \"%s\"...\n", outName, chars);
                    outValue = chars;
                }
            }
        }

        m_t.SetValue(inName,-1, inValue);
        m_t.SetValue(outName,-1, outValue);
        try {
            DBF("() m_t.Expand(*out, *in)...\n");
            if ((error = m_t.Expand(*out, *in))) {
                DBE("() ...failed on m_t.Expand(*out, *in)\n");
                err = 1;
            } else {
                DBF("() ...m_t.Expand(*out, *in)\n");
            }
        } catch (const cTException& e) {
            eError error = e.Error();
            DBF("() ...caught const cTException& e = %d\n", error);
            if (e_ERROR_EXIT != (error)) {
                err = 1;
            }
        }
        return err;
    }
    virtual int BeforeRun
    (int argc, const tChar** argv, const tChar** env) {
        int err = 1;
        eError error = 0;
        DBF("() m_t.Initialize()...\n");
        if ((error = m_t.Initialize()))
            DBE("() ...failed on m_t.Initialize()\n");
        else {
            DBE("() ...m_t.Initialize()\n");
            err = 0;
        }
        return err;
    }
    virtual int AfterRun
    (int argc, const tChar** argv, const tChar** env) {
        int err = 1;
        eError error = 0;
        DBF("() m_t.Finalize()...\n");
        if ((error = m_t.Finalize()))
            DBE("() ...failed on m_t.Finalize()\n");
        else {
            DBE("() ...m_t.Finalize()\n");
            err = 0;
        }
        return err;
    }

    /**
     **********************************************************************
     * Function: MainNamedArg
     *
     *   Author: $author$
     *     Date: 1/1/2009
     **********************************************************************
     */
    virtual int MainNamedArg
    (const tChar *argName, const tChar *argValue,
     int args, int argn, const tChar *arg,
     int argc, const tChar** argv, const tChar** env) {
        tLength argNameLength = -1;
        tLength argValueLength = -1;
        m_t.SetValue(argName,argNameLength, argValue,argValueLength);
        return argn;
    }
    /**
     **********************************************************************
     * Function: MainUnnamedArgn
     *
     *   Author: $author$
     *     Date: 12/31/2008
     **********************************************************************
     */
    virtual int MainUnnamedArgn
    (int unnamedArgn,
     int args, int argn, const tChar *arg,
     int argc, const tChar** argv, const tChar** env) {
        tLength length;
        const tChar* chars;

        if ((arg) && (arg[0])) {
            if (1 > unnamedArgn) {
                if (0 > (length = m_inFileName.Assign(arg)))
                    DBE("() failed to assign input file = \"%s\"\n", arg);
                else {
                    if (m_inputVariableNameChars) {
                        if ((chars = m_inFileName.HasChars(length)))
                            m_t.SetValue(m_inputVariableNameChars,-1, chars,length);
                    }
                }
            } else {
                if (2 > unnamedArgn) {
                    if (0 > (length = m_outFileName.Assign(arg)))
                        DBE("() failed to assign output file = \"%s\"\n", arg);
                    else {
                        if (m_outputVariableNameChars) {
                            if ((chars = m_outFileName.HasChars(length)))
                                m_t.SetValue(m_outputVariableNameChars,-1, chars,length);
                        }
                    }
                }
            }
        }
        return argn;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CAPP_CCONSOLE_CT_CTMAIN_HXX */
