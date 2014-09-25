#include "SessionUpdateUpdate.h"
#include <boost/utility.hpp>

using namespace Sessions;

//------------------SessionUpdate-------------
class SessionUpdateImpl : public SessionUpdate,
               private boost::noncopyable
{
public:
     SessionUpdateImpl(const char* SessionUpdateId);
     ~SessionUpdateImpl() {}

// ----------------BEGIN SessionUpdate interface --------------------------------

     Status setUsername(const std::string username);
     Status setPagesvisited(const int pagesVisited);
     Status setIsmobileuser(const int isMobileUser = 0);
     Status setUserid(const int userid);
     Status setLastaccesstime(const int lastAccessTime);
     Status setUseragent(const std::string useragent);
     Status setPassword(const std::string password);

     Status commitChanges();
// ----------------END SessionUpdate interface -----------------------------------
private:

     std::string m_username
     int m_pagesVisited
     int m_isMobileUser
     int m_userid
     int m_lastAccessTime
     std::string m_useragent
     std::string m_password
}; // end SessionUpdateImpl

SessionUpdateImpl::SessionUpdateImpl(const char* SessionUpdateId) : 
          m_isMobileUser(0)
{
     //Set up defaults here
}

Status
SessionUpdateImpl::setUsername(const std::string username)
{
     return kSuccess
}

Status
SessionUpdateImpl::setPagesvisited(const int pagesVisited)
{
     return kSuccess
}

Status
SessionUpdateImpl::setIsmobileuser(const int isMobileUser)
{
     return kSuccess
}

Status
SessionUpdateImpl::setUserid(const int userid)
{
     return kSuccess
}

Status
SessionUpdateImpl::setLastaccesstime(const int lastAccessTime)
{
     return kSuccess
}

Status
SessionUpdateImpl::setUseragent(const std::string useragent)
{
     return kSuccess
}

Status
SessionUpdateImpl::setPassword(const std::string password)
{
     return kSuccess
}

Status
SessionUpdateImpl::commitChanges()
{
     // Insert code here to commit
     // changes to a new  record
     //

     return kSuccess;
}

SessionUpdate*
SessionUpdateFactory::createNewSessionUpdate(const char* SessionUpdateId)
{
     return new SessionUpdateImpl(SessionUpdateId);
}