class GenCreate:

    def genHeader(self, schemaDict) :
        className = schemaDict['root']
        namespace = className + 's'
        namespace = namespace.title()

        headers = "#include \"headers.h\"\n#include <string>\n#include <vector>\n\n"         
        namespaceBegin = "namespace " + namespace + "\n{\n"
        classBegin = "     class " + className.title() + "\n     {\n"
        classDef = "     public:\n          virtual ~" + className.title() + "() {};\n\n"
        methodNames = ''
        for key,value in schemaDict['data'].items() :
            if key == schemaDict['root'] :
                continue
            # Ideally this mapping should come for a config file
            #
            dataType = 'int'
            if value['type'] == 'int' :
                dataType = "int"
            elif value['type'] == 'string' :
                dataType = "std::string"
            elif value['type'] == 'stringvector' :
                dataType = "std::vector<std::string>"


            methodNames = methodNames + "          virtual Status set" + key.title() + "(const " + dataType + " " + key
            if 'default' in value :
                methodNames = methodNames + " = " + value['default']

            methodNames = methodNames + ") = 0;\n"

        commitMethod = "\n          virtual Status commitChanges() = 0;\n\n"
        classEnd = "     }; // class " + className.title() + "\n\n"
        factory = "     class " + className.title() + "Factory \n     {\n     public:\n          static " + className.title() + " *createNew" + className.title() + "(const char* " + className + "Id);\n     }; // class " + className.title() + "Factory\n"
        namespaceEnd = "\n} // namespace " + namespace
        headerFO = open(className + "Create.h", "w")
        headerFO.write(headers)
        headerFO.write(namespaceBegin)
        headerFO.write(classBegin)
        headerFO.write(classDef)
        headerFO.write(methodNames)
        headerFO.write(commitMethod)
        headerFO.write(classEnd)
        headerFO.write(factory)
        headerFO.write(namespaceEnd)
        headerFO.close()
        

#{'data': 
#{'username': {'type': 'string'}, 
#'pagesVisited': {'type': 'stringvector', 'notifyon': 'modify'},
#'isMobileUser': {'default': '0', 'type': 'int'}, 
#'userid': {'type': 'int'}, 
#'lastAccessTime': {'type': 'int'},
#'session': {'notifyon': 'create,delete'}, 
#'useragent': {'type': 'string'}, 
#'password': {'type': 'string', 'secure':'yes'}}, 
#'root': 'session'}




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

Session*
SessionFactory::createNewSession(const char* sessionId)
{
    return new SessionImpl(sessionId);
}
