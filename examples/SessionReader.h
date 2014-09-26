#include "helpers.h"
#include <string>
#include <vector>

namespace Sessions
{
     class SessionReader
     {
     public:
          virtual ~SessionReader() {};

          virtual Status getUsername(std::string& username) = 0;
          virtual Status getPagesvisited(std::vector<std::string>& pagesVisited) = 0;
          virtual Status getIsmobileuser(int& isMobileUser) = 0;
          virtual Status getUserid(int& userid) = 0;
          virtual Status getLastaccesstime(int& lastAccessTime) = 0;
          virtual Status getUseragent(std::string& useragent) = 0;
          virtual Status getPassword(std::string& password) = 0;
     }; // class SessionReader

     class SessionReaderFactory 
     {
     public:
          static SessionReader* createNewSessionReader(const char* SessionReaderId);
     }; // class SessionReaderFactory

} // namespace Sessions