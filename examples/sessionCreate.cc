#include "sessionCreate.h"
#include <boost/utility.hpp>

using namespace Sessions;

//------------------Session-------------
class SessionImpl : public Session,
               private boost::noncopyable
{
public:
     SessionImpl(const char* sessionId);
     ~SessionImpl() {}

// ----------------BEGIN Session interface --------------------------------

     Status setUsername(const std::string username);
     Status setPagesvisited(const int pagesVisited);
     Status setIsmobileuser(const int isMobileUser = 0);
     Status setUserid(const int userid);
     Status setLastaccesstime(const int lastAccessTime);
     Status setUseragent(const std::string useragent);
     Status setPassword(const std::string password);

     Status commitChanges();
// ----------------END Session interface -----------------------------------
private:

     std::string m_username
     int m_pagesVisited
     int m_isMobileUser
     int m_userid
     int m_lastAccessTime
     std::string m_useragent
     std::string m_password
}; // end SessionImpl

SessionImpl::SessionImpl(const char* sessionId) : 
          m_isMobileUser(0)
{
     //Set up defaults here
}

Status
SessionImpl::setUsername(const std::string username)
{
     return kSuccess
}

Status
SessionImpl::setPagesvisited(const int pagesVisited)
{
     return kSuccess
}

Status
SessionImpl::setIsmobileuser(const int isMobileUser)
{
     return kSuccess
}

Status
SessionImpl::setUserid(const int userid)
{
     return kSuccess
}

Status
SessionImpl::setLastaccesstime(const int lastAccessTime)
{
     return kSuccess
}

Status
SessionImpl::setUseragent(const std::string useragent)
{
     return kSuccess
}

Status
SessionImpl::setPassword(const std::string password)
{
     return kSuccess
}

Status
SessionImpl::commitChanges()
{
     // Insert code here to commit
     // changes to a new  record
     //

     return kSuccess;
}

Session*
SessionFactory::createNewSession(const char* sessionId)
{
     return new SessionImpl(sessionId);
}