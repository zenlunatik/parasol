// This is an auto generated file. 
//

#include "sessionIterator.h"
#include <stdint.h>
#include <boost/utility.hpp>
using namespace Sessions;

//------------SessionIterator-------------------
class SessionIteratorImpl: public SessionIterator,
                          private boost::noncopyable
{
public:
    SessionIteratorImpl();
    ~SessionIteratorImpl();

    // ----------------BEGIN SessionIterator interface--------------------------------
    void first();
    void next();
    bool isDone() const;
    SessionReader* currentItem() const;
    //----------------END SessionIterator interface----------------------------------

private:
    uint64_t m_current;
}; // class SessionIteratorImpl


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

boolSessionIteratorImpl::isDone() const
{
    return true;
}

SessionReader*
SessionIteratorImpl::currentItem() const
{    return NULL;
}

SessionIterator* 
SessionIteratorFactory::getSessionIterator()
{
    return new SessionIteratorImpl();
}