#ifndef __SESSIONS_ITER_H__
#define __SESSIONS_ITER_H__

// This is an auto generated file. 
//

namespace Sessions
{
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
          static SessionIterator*getSessionIterator();
     }; // class SessionIteratorFactory


} // namespace Sessions

#endif
