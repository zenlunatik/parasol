#include "SessionReaderUpdate.h"
#include <boost/utility.hpp>

using namespace Sessions;

//------------------SessionReader-------------
class SessionReaderImpl : public SessionReader,
               private boost::noncopyable
{
public:
     SessionReaderImpl(const char* SessionReaderId);
     ~SessionReaderImpl() {}

// ----------------BEGIN SessionReader interface --------------------------------

     Status getUsername(std::string username);
     Status getPagesvisited(int pagesVisited);
     Status getIsmobileuser(int isMobileUser);
     Status getUserid(int userid);
     Status getLastaccesstime(int lastAccessTime);
     Status getUseragent(std::string useragent);
     Status getPassword(std::string password);
// ----------------END SessionReader interface -----------------------------------
private:

     std::string m_username
     int m_pagesVisited
     int m_isMobileUser
     int m_userid
     int m_lastAccessTime
     std::string m_useragent
     std::string m_password
}; // end SessionReaderImpl

SessionReaderImpl::SessionReaderImpl(const char* SessionReaderId) : 
          
{
     //Set up defaults here
}

Status
SessionReaderImpl::getUsername(std::string&  username)
{
     return kSuccess
}

Status
SessionReaderImpl::getPagesvisited(int&  pagesVisited)
{
     return kSuccess
}

Status
SessionReaderImpl::getIsmobileuser(int&  isMobileUser)
{
     return kSuccess
}

Status
SessionReaderImpl::getUserid(int&  userid)
{
     return kSuccess
}

Status
SessionReaderImpl::getLastaccesstime(int&  lastAccessTime)
{
     return kSuccess
}

Status
SessionReaderImpl::getUseragent(std::string&  useragent)
{
     return kSuccess
}

Status
SessionReaderImpl::getPassword(std::string&  password)
{
     return kSuccess
}


SessionReader*
SessionReaderFactory::createNewSessionReader(const char* SessionReaderId)
{
     return new SessionReaderImpl(SessionReaderId);
}