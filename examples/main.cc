#include "sessions.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace Sessions;

int main()
{
    // Creating a new session
    //
    Session* newSession = SessionFactory::createNewSession("1234");
    if (!newSession) {
        cout<<"Unable to create a new session"<<endl;
        return 0;
    }
    newSession->setUsername("user1");
    if (newSession->commitChanges() != kSuccess) {
        std::cout<<"Failed to commit new session"<<std::endl;
    }

    // Update an existing session
    //
    SessionUpdater* sessionUpdater = SessionUpdaterFactory::getSessionUpdater("1234");
    if (!sessionUpdater) {
        cout<<"Unable to create a session updater"<<endl;
        return 0;
    }
    sessionUpdater->setUsername("user1");
    if (sessionUpdater->commitChanges() != Sessions::kSuccess) {
        std::cout<<"Failed to commit existing session"<<std::endl;
    }

    // Reading an existing session
    //
    SessionReader* sessionReader = 
        SessionReaderFactory::getSessionReader("1234", SessionReader::kReadSession);
    if (!sessionReader) {
        cout<<"Unable to create a session reader"<<endl;
        return 0;
    }
    string username;
    sessionReader->getUsername(username);

    // Iterating over all sessions
    //
    SessionIterator* iter = SessionIteratorFactory::getSessionIterator();
    if (!iter) return 0;
    for (iter->first(); !iter->isDone(); iter->next()) {
        std::string username;
        iter->currentItem()->getUsername(username);
    }

    // Deleting a session
    //
    if (deleteSession("1234") != kSuccess) {
        cout<<"Failed to delete a session";
        return 0;
    }

    cout<<"Success"<<endl;
}
