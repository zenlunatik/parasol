#ifndef SESSIONS_H
#define SESSIONS_H

// This is an auto generated file.
//

#include <string>
#include <vector>

namespace Sessions
{
    enum Status {
        kSuccess = 0,
        kFailure = 255
    };

    class Session 
    {
    public:
        virtual ~Session() {};

        virtual Status setUsername(const std::string username) = 0;
        virtual Status setPassword(const std::string password) = 0;
        virtual Status setUserid(const int userid) = 0;
        virtual Status setLastAccessTime(const int lastAccessTime) = 0;
        virtual Status setPagesVisited(const std::vector<std::string> pagesVisited) = 0;
        virtual Status setUseragent(const std::string useragent) = 0;
        virtual Status setIsMobileUser(const int isMobileUser = 0) = 0;

        virtual Status commitChanges() = 0;

        static Status deleteSession(const char* sessionId);

    }; // class Session
    
    class SessionFactory 
    {
    public:
        static Session* createNewSession(const char* sessionId);
    }; // class SessionFactory


    class SessionUpdater
    {
    public:

        virtual ~SessionUpdater() {}

        virtual Status setUsername(const std::string username) = 0;
        virtual Status setPassword(const std::string password) = 0;
        virtual Status setUserid(const int userid) = 0;
        virtual Status setLastAccessTime(const int lastAccessTime) = 0;
        virtual Status setPagesVisited(const std::vector<std::string> pagesVisited) = 0;
        virtual Status setUseragent(const std::string useragent) = 0;
        virtual Status setIsMobileUser(const int isMobileUser = 0) = 0;

        virtual Status commitChanges() = 0;

    }; // class SessionUpdater
    
    class SessionUpdaterFactory
    {
    public:
        static SessionUpdater* getSessionUpdater(const char* sessionId);
    }; // class SessionUpdaterFactory


    class SessionReader
    {
    public:
        enum ReadMode {
            kReadSession = 0,    // Read the complete session
            kReadItem    = 1     // Read one item
        };
        
        
        virtual ~SessionReader() {}

        virtual Status getUsername(std::string& username) = 0;
        virtual Status getPassword(std::string& password) = 0;
        virtual Status getUserid(int& userid) = 0;
        virtual Status getLastAccessTime(int& lastAccessTime) = 0;
        virtual Status getPagesVisited(std::vector<std::string>& pagesVisited) = 0;
        virtual Status getUseragent(std::string& useragent) = 0;
        virtual Status getIsMobileUser(int& isMobileUser) = 0;

    }; // class SessionReader


    class SessionReaderFactory 
    {
    public:
        static SessionReader* getSessionReader(const char* sessionId, SessionReader::ReadMode mode);
    }; // class SessionReaderFactory
    
    Status deleteSession(const char* sessionId);

    //
    // Using the iterator
    // SessionIterator* iter = SessionIteratorFactory::getSessionIterator();
    // if (!iter) return;
    // for (iter->first(); !iter->isDone(); iter->next()) {
    //      std::string username;
    //      iter->currentItem()->getUsername(username);
    // }
    //

    class SessionIterator
    {
    public:

        virtual ~SessionIterator() {}

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool isDone() const = 0;
        virtual SessionReader* currentItem() const = 0;

    }; // class SessionIterator
    
    class SessionIteratorFactory 
    {
    public:
        static SessionIterator* getSessionIterator();
    }; // class SessionIteratorFactory

} //namespace Sessions

#endif
