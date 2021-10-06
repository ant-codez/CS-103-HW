// ============================================================================
// File: cqueue.h
// ============================================================================
// Header file for the CQueue class.
// ============================================================================

#ifndef CQUEUE_H
#define CQUEUE_H

#include    <iostream>
#include    "clinkedlist.h"

// type definitions
typedef ListItemType    QueueItemType; // ListItemType comes from clinkedlist.h

// exception class for CQueue
class CQueueException
{
public:
    // constructor
    CQueueException(std::string funcName, std::string msg)
            : m_msg(msg), m_funcName(funcName) 
    {
    }

    // member function
    std::string GetMsg() const {return m_msg;}
    std::string GetFuncName() const {return m_funcName;}

private:
    std::string  m_msg;
    std::string  m_funcName;
};

// make our own CQueue class as oppose to the prebuilt STL
class   CQueue
{
public:
    // constructors and destructor

    /* compiler generated default constructor/destructor will be enough*/

    // member functions
    void            			DestroyQueue();
    bool            			Dequeue() throw (CQueueException);
    bool            			Enqueue(const QueueItemType  &newItem);
    QueueItemType   	        PeekFront() const throw (CQueueException);
    bool            			IsEmpty() const;

private:
    // data members
    CLinkedList	m_qList;
};

#endif  // CQUEUE_H
