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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 4/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_IO_LOGGER_HPP
#define _TEXTA_IO_LOGGER_HPP

#include "xos/io/logger.hpp"

#define TEXTA_LOG_ANY XOS_LOG_ANY
#define TEXTA_LOG_FATAL XOS_LOG_FATAL
#define TEXTA_LOG_ERROR XOS_LOG_ERROR
#define TEXTA_LOG_WARN XOS_LOG_WARN
#define TEXTA_LOG_INFO XOS_LOG_INFO
#define TEXTA_LOG_DEBUG XOS_LOG_DEBUG
#define TEXTA_LOG_TRACE XOS_LOG_TRACE

#define TEXTA_LOG_ANYF XOS_LOG_ANYF
#define TEXTA_LOG_FATALF XOS_LOG_FATALF
#define TEXTA_LOG_ERRORF XOS_LOG_ERRORF
#define TEXTA_LOG_WARNF XOS_LOG_WARNF
#define TEXTA_LOG_INFOF XOS_LOG_INFOF
#define TEXTA_LOG_DEBUGF XOS_LOG_DEBUGF
#define TEXTA_LOG_TRACEF XOS_LOG_TRACEF

#define TEXTA_LOG_MESSAGE_ANY XOS_LOG_MESSAGE_ANY
#define TEXTA_LOG_MESSAGE_FATAL XOS_LOG_MESSAGE_FATAL
#define TEXTA_LOG_MESSAGE_ERROR XOS_LOG_MESSAGE_ERROR
#define TEXTA_LOG_MESSAGE_WARN XOS_LOG_MESSAGE_WARN
#define TEXTA_LOG_MESSAGE_INFO XOS_LOG_MESSAGE_INFO
#define TEXTA_LOG_MESSAGE_DEBUG XOS_LOG_MESSAGE_DEBUG
#define TEXTA_LOG_MESSAGE_TRACE XOS_LOG_MESSAGE_TRACE

#define TEXTA_LOG_MESSAGE_ANYF XOS_LOG_MESSAGE_ANYF
#define TEXTA_LOG_MESSAGE_FATALF XOS_LOG_MESSAGE_FATALF
#define TEXTA_LOG_MESSAGE_ERRORF XOS_LOG_MESSAGE_ERRORF
#define TEXTA_LOG_MESSAGE_WARNF XOS_LOG_MESSAGE_WARNF
#define TEXTA_LOG_MESSAGE_INFOF XOS_LOG_MESSAGE_INFOF
#define TEXTA_LOG_MESSAGE_DEBUGF XOS_LOG_MESSAGE_DEBUGF
#define TEXTA_LOG_MESSAGE_TRACEF XOS_LOG_MESSAGE_TRACEF

#define TEXTA_LOG_MESSAGE_ANYFV XOS_LOG_MESSAGE_ANYFV
#define TEXTA_LOG_MESSAGE_FATALFV XOS_LOG_MESSAGE_FATALFV
#define TEXTA_LOG_MESSAGE_ERRORFV XOS_LOG_MESSAGE_ERRORFV
#define TEXTA_LOG_MESSAGE_WARNFV XOS_LOG_MESSAGE_WARNFV
#define TEXTA_LOG_MESSAGE_INFOFV XOS_LOG_MESSAGE_INFOFV
#define TEXTA_LOG_MESSAGE_DEBUGFV XOS_LOG_MESSAGE_DEBUGFV
#define TEXTA_LOG_MESSAGE_TRACEFV XOS_LOG_MESSAGE_TRACEFV

#define TEXTA_LOG_MESSAGE_ANYMFV XOS_LOG_MESSAGE_ANYMFV
#define TEXTA_LOG_MESSAGE_FATALMFV XOS_LOG_MESSAGE_FATALMFV
#define TEXTA_LOG_MESSAGE_ERRORMFV XOS_LOG_MESSAGE_ERRORMFV
#define TEXTA_LOG_MESSAGE_WARNMFV XOS_LOG_MESSAGE_WARNMFV
#define TEXTA_LOG_MESSAGE_INFOMFV XOS_LOG_MESSAGE_INFOMFV
#define TEXTA_LOG_MESSAGE_DEBUGMFV XOS_LOG_MESSAGE_DEBUGMFV
#define TEXTA_LOG_MESSAGE_TRACEMFV XOS_LOG_MESSAGE_TRACEMFV

namespace texta {
namespace io {

} // namespace io 
} // namespace texta 

#endif // _TEXTA_IO_LOGGER_HPP 
