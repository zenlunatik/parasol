#include "helpers.h"
#include <string>
#include <vector>

namespace Sessions
{
     class SessionUpdate
     {
     public:
          virtual ~SessionUpdate() {};

          virtual Status setUsername(const std::string username) = 0;
          virtual Status setPagesvisited(const std::vector<std::string> pagesVisited) = 0;
          virtual Status setIsmobileuser(const int isMobileUser = 0) = 0;
          virtual Status setUserid(const int userid) = 0;
          virtual Status setLastaccesstime(const int lastAccessTime) = 0;
          virtual Status setUseragent(const std::string useragent) = 0;
          virtual Status setPassword(const std::string password) = 0;

          virtual Status commitChanges() = 0;

     }; // class SessionUpdate

     class SessionUpdateFactory 
     {
     public:
          static SessionUpdate *createNewSessionUpdate(const char* SessionUpdateId);
     }; // class SessionUpdateFactory

} // namespace Sessions