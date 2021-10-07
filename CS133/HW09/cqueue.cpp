// ============================================================================
// File: cqueue.cpp
// ============================================================================
// This is the implementation file for the list ADT CQueue.  This
// implementation uses the ADT CList.
// ============================================================================

#include    <iostream>
#include    "clinkedlist.h"
#include    "cqueue.h"
using namespace std;



// ==== CQueue::DestroyQueue ==================================================
//
// This function clears the queue.
//
// Input:
//      void
//
// Output:
//      void
//
// ============================================================================
void CQueue::DestroyQueue() {
    m_qList.DestroyList();
}




// ==== CQueue::Dequeue =======================================================
//
// This function removes an item from the queue (top of the list)
//
// The function throws error codes from the class CQueueException
//		Ex: "CQueue::Dequeue" Message: Passes the message from
//      CLinkedListException
//
// Input:
//      void
//
// Output:
//      bool (true if successful, otherwise false)
//
// ============================================================================
bool CQueue::Dequeue() throw (CQueueException) {
    QueueItemType temp;

    try {
        m_qList.GetItem(0, temp);
    }
    catch (const CLinkedListException &exceptObj) {
        throw CQueueException("CQueue::Dequeue", exceptObj.GetMsg());
        return false;
    }
    
    try {
        return m_qList.Remove(temp);
    }
    catch (const CLinkedListException &exceptObj) {
        throw CQueueException("CQueue::Dequeue", exceptObj.GetMsg());
        return false;
    }

}




// ==== CQueue::Enqueue =======================================================
//
// This function adds an item to the bottom of the CList
//
// Input:
//      newItem		-- a QueueItemType
//
// Output:
//      bool
//
// ============================================================================
bool CQueue::Enqueue(const QueueItemType &newItem) {
    return m_qList.Add(newItem);
}



// ==== CQueue::PeekFront =====================================================
//
// This function returns the value on top of the list.
//
// The function throws error codes from the class CQueueException
//		Ex: "CQueue::PeekFront" Message: Passes the message from
//      CLinkedListException
//
// Input:
//      void
//
// Output:
//      void
//
// ============================================================================
QueueItemType CQueue::PeekFront() const throw (CQueueException) {
    QueueItemType temp;

    try {
        m_qList.GetItem(0, temp);
        return temp;
    }
    catch (const CLinkedListException &exceptObj) {
        throw CQueueException("CQueue::PeekFront", exceptObj.GetMsg());
    }
}




// ==== CQueue::IsEmpty =======================================================
//
// This function returns a boolean value if the queue is empty.
//
// Input:
//      void
//
// Output:
//      A boolean value. True if list is empty, false otherwise.
//
// ============================================================================
bool CQueue::IsEmpty() const {
    return m_qList.IsEmpty();
}
