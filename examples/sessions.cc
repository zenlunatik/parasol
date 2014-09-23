#include "sessions.h"
#include <stdint.h>
#include <boost/utility.hpp>

using namespace Sessions;

// --------Session-----------------
class SessionImpl : public Session,
                    private boost::noncopyable
{
public:
    SessionImpl(const char* sessionId);
    ~SessionImpl() {}
    
    // ----------------BEGIN Session interface --------------------------------
    Status setUsername(const std::string username);
    Status setPassword(const std::string password);
    Status setUserid(const int userid);
    Status setLastAccessTime(const int lastAccessTime);
    Status setPagesVisited(const std::vector<std::string> pagesVisited);
    Status setUseragent(const std::string useragent);
    Status setIsMobileUser(const int isMobileUser = 0);

    Status commitChanges();
    
    static Status deleteSessionImpl(const char* sessionId);
    // ----------------END Session interface -----------------------------------

private:
    std::string m_username;
    std::string m_password;
    int m_userid;
    int m_lastAccessTime;
    std::vector<std::string> m_pagesVisited;
    std::string m_useragent;
    int m_isMobileUser;
}; // class SessionImpl

SessionImpl::SessionImpl(const char* sessionId) : m_isMobileUser(0)
{
    // Set up defaults here from schema
}

Status 
SessionImpl::setUsername(const std::string username)
{
    return kSuccess;
}

Status 
SessionImpl::setPassword(const std::string password)
{
    return kSuccess;
}

Status 
SessionImpl::setUserid(const int userid)
{
    return kSuccess;
}

Status 
SessionImpl::setLastAccessTime(const int lastAccessTime)
{
    return kSuccess;
}

Status 
SessionImpl::setPagesVisited(const std::vector<std::string> pagesVisited)
{
    return kSuccess;
}

Status
SessionImpl::setUseragent(const std::string useragent)
{
    return kSuccess;
}

Status
SessionImpl::setIsMobileUser(const int isMobileUser)
{
    return kSuccess;
}

Status
SessionImpl::commitChanges()
{
    // Insert code here to commit
    // changes to a new  record
    //

    return kSuccess;
}

Status
SessionImpl::deleteSessionImpl(const char* sessionId)
{
    return kSuccess;
}

Status
Session::deleteSession(const char* sessionId)
{
    return SessionImpl::deleteSessionImpl(sessionId);
}

Session*
SessionFactory::createNewSession(const char* sessionId)
{
    return new SessionImpl(sessionId);
}



// --------SessionUpdater-----------------
class SessionUpdaterImpl : public SessionUpdater,
                           private boost::noncopyable
{
public:
    SessionUpdaterImpl(const char* sessionId);
    ~SessionUpdaterImpl() {}
    
    // ----------------BEGIN SessionUpdater interface --------------------------------
    Status setUsername(const std::string username);
    Status setPassword(const std::string password);
    Status setUserid(const int userid);
    Status setLastAccessTime(const int lastAccessTime);
    Status setPagesVisited(const std::vector<std::string> pagesVisited);
    Status setUseragent(const std::string useragent);
    Status setIsMobileUser(const int isMobileUser = 0);

    Status commitChanges();
    // ----------------END SessionUpdater interface -----------------------------------
private:
    std::string m_username;
    std::string m_password;
    int m_userid;
    int m_lastAccessTime;
    std::vector<std::string> m_pagesVisited;
    std::string m_useragent;
    int m_isMobileUser;
}; // class SessionUpdaterImpl

SessionUpdaterImpl::SessionUpdaterImpl(const char* sessionId)
{
}

Status 
SessionUpdaterImpl::setUsername(const std::string username)
{
    return kSuccess;
}

Status 
SessionUpdaterImpl::setPassword(const std::string password)
{
    return kSuccess;
}

Status 
SessionUpdaterImpl::setUserid(const int userid)
{
    return kSuccess;
}

Status 
SessionUpdaterImpl::setLastAccessTime(const int lastAccessTime)
{
    return kSuccess;
}

Status 
SessionUpdaterImpl::setPagesVisited(const std::vector<std::string> pagesVisited)
{
    return kSuccess;
}

Status
SessionUpdaterImpl::setUseragent(const std::string useragent)
{
    return kSuccess;
}

Status
SessionUpdaterImpl::setIsMobileUser(const int isMobileUser)
{
    return kSuccess;
}

Status
SessionUpdaterImpl::commitChanges()
{
    // Insert code here to commit
    // changes to an existing record
    //
    return kSuccess;
}

SessionUpdater*
SessionUpdaterFactory::getSessionUpdater(const char* sessionId)
{
    return new SessionUpdaterImpl(sessionId);
}


//------------SessionReader-------------------
class SessionReaderImpl : public SessionReader,
                          private boost::noncopyable
{
public:
    SessionReaderImpl(const char* sessionId, SessionReader::ReadMode mode);
    ~SessionReaderImpl() {}
    
    // ----------------BEGIN SessionReader interface --------------------------------
    Status getUsername(std::string& username);
    Status getPassword(std::string& password);
    Status getUserid(int& userid);
    Status getLastAccessTime(int& lastAccessTime);
    Status getPagesVisited(std::vector<std::string>& pagesVisited);
    Status getUseragent(std::string& useragent);
    Status getIsMobileUser(int& isMobileUser);
    // ----------------END SessionReader interface -----------------------------------
private:
    std::string m_username;
    std::string m_password;
    int m_userid;
    int m_lastAccessTime;
    std::vector<std::string> m_pagesVisited;
    std::string m_useragent;
    int m_isMobileUser;
    bool m_populated;
}; // class SessionImpl

SessionReaderImpl::SessionReaderImpl(const char* sessionId, SessionReader::ReadMode mode)
{
    m_populated = false;
    // Need to add code here to connect to a db and fetch the session.
    //

}

Status
SessionReaderImpl::getUsername(std::string& username)
{
    if (m_populated) {
        username = m_username;
        return kSuccess;
    }
    return kFailure;
}

Status 
SessionReaderImpl::getPassword(std::string& password)
{
    if (m_populated) {
        password = m_password;
        return kSuccess;
    }
    return kFailure;
}

Status 
SessionReaderImpl::getUserid(int& userid)
{
    if (m_populated) {
        userid = m_userid;
        return kSuccess;
    }
    return kFailure;
}

Status 
SessionReaderImpl::getLastAccessTime(int& lastAccessTime)
{
    if (m_populated) {
        lastAccessTime = m_lastAccessTime;
        return kSuccess;
    }
    return kFailure;
}

Status
SessionReaderImpl::getPagesVisited(std::vector<std::string>& pagesVisited)
{
    if (m_populated) {
        pagesVisited = m_pagesVisited;
        return kSuccess;
    }
    return kFailure;
}

Status
SessionReaderImpl::getUseragent(std::string& useragent)
{
    if (m_populated) {
        useragent = m_useragent;
        return kSuccess;
    }
    return kFailure;
}

Status 
SessionReaderImpl::getIsMobileUser(int& isMobileUser)
{
    if (m_populated) {
        isMobileUser = m_isMobileUser;
        return kSuccess;
    }
    return kFailure;
}

SessionReader*
SessionReaderFactory::getSessionReader(const char* sessionId, SessionReader::ReadMode mode)
{
    // Insert code here to query the db with sessionId and
    // populate member variables.
    //
    return new SessionReaderImpl(sessionId, mode);
}


Status
Sessions::deleteSession(const char* sessionId)
{
    return kSuccess;

}

//------------SessionIterator-------------------
class SessionIteratorImpl : public SessionIterator,
                            private boost::noncopyable
{
public:
    SessionIteratorImpl();
    ~SessionIteratorImpl();

    // ----------------BEGIN SessionIterator interface --------------------------------
    void first();
    void next();
    bool isDone() const;
    SessionReader* currentItem() const;
    // ----------------END SessionIterator interface ----------------------------------

private:
    uint64_t m_current;
};

SessionIteratorImpl::SessionIteratorImpl()
{
    // Add code here to set up db to iterate
    // over records
    //

}

SessionIteratorImpl::~SessionIteratorImpl()
{
}


void
SessionIteratorImpl::first()
{
}

void
SessionIteratorImpl::next()
{
}

bool
SessionIteratorImpl::isDone() const
{
    return true;
}

SessionReader*
SessionIteratorImpl::currentItem() const
{
    return NULL;
}


SessionIterator*
SessionIteratorFactory::getSessionIterator()
{
    return new SessionIteratorImpl();
}


