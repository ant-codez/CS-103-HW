// ============================================================================
// File: clinkedlist.cpp
// ============================================================================
// This is the implementation file for a doubly list ADT CLinkedList.  This
// implementation uses nodes to store a list of type ListItemType (ints) items.
// ============================================================================

#include    <iostream>
#include    "clinkedlist.h"
using namespace std;



// ==== CLinkedList::CLinkedList (Default) ====================================
//
// This is the default constructor that sets the head pointer to nullptr
//
// ============================================================================
CLinkedList::CLinkedList(): headPtr(nullptr), tailPtr(nullptr)
{    
}



// ==== CLinkedList::~CLnkedList (Destructor) =================================
//
// This is the destructor, which releases all the nodes.
//
// ============================================================================
CLinkedList::~CLinkedList(){
    DestroyList();
}




// ==== CLinkedList::DestroyList ==============================================
//
// This function releases (frees) all the nodes and sets headPtr to nullptr
//
// Input:
//      void
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================
bool CLinkedList::DestroyList() {
    Node    *leadPtr = headPtr;
    Node    *trailPtr; // use a trail pointer to point to the next node.

    // loop until leadPtr doesn't point to a nullptr
    while (leadPtr != nullptr)
    {
        // assign trailPtr the next location
        trailPtr = leadPtr -> GetNext();

        // delete what leadPtr points to
        delete leadPtr;

        // update leadPtr to point to the next location
        leadPtr = trailPtr;
    }

    // set leadPtr, headPtr, and tailPtr to point to nullptr
    headPtr = nullptr;
    leadPtr = nullptr;
    tailPtr = nullptr;

    return true;
}




// ==== CLinkedList::GetItem ==================================================
//
// This function retrieves the value of an item at a particular location 
// (particular node).
//
// The function throws error codes from the class CLinkedListException
//		Ex: "CLinkedList::GetItem" Message: "Empty"
//
//
// Input:
//      index   -- the index location for the target item (zero-based).
//
//      item    -- a reference to a ListItemType object. This argument will
//                 contain the desired item after the function completes.
//
// Output:
//      A boolean value
//
// ============================================================================
bool CLinkedList::GetItem(int index, ListItemType &item) const throw (CLinkedListException) {
    Node    *tracePtr = headPtr;
    int     counter = 0;

    // if the list is empty, return false
    if (IsEmpty())
    {
        tracePtr = nullptr;
        throw CLinkedListException("CLinkedList::GetItem", "Empty");
        return false;
    }

    // Cycle through all the Nodes until the end is reached
    while (tracePtr != nullptr)
    {
        // test if we have reached Node index
        if (counter == index)
        {
            // update item
            item = tracePtr -> GetItem();

            // change tracePtr to nullptr
            tracePtr = nullptr;

            // return true
            return true;
        }

        // increment counter
        ++counter;

        // change tracePtr to the next node
        tracePtr = tracePtr -> GetNext();
    }

    // The index is out of bounds so return false
    tracePtr = nullptr;
    throw CLinkedListException("CLinkedList::GetItem", "Empty");
    return false;
}




// ==== CLinkedList::Contains =================================================
//
// This function checks if an item exists in the list.
//
// Input:
//      newItem     -- a const reference to item to check if it exists
//
// Output:
//      A boolean value
//
// ============================================================================
bool CLinkedList::Contains(const ListItemType &item) const
{
    // create a pointer to trace through the nodes, starting at headPtr.
    Node    *tracePtr = headPtr;

    // Cycle through all the Nodes until the end is reached
    while (tracePtr != nullptr)
    {
        // check if the current node has an item value, if it does return true
        if (tracePtr -> GetItem() == item)
        {
            return true;
        }

        // change tracePtr to the next node
        tracePtr = tracePtr -> GetNext();
    }

    // Cycled through the whole list and item was not found, return false.
    tracePtr = nullptr;

    return false;

}  // end of "CLinkedList::Contains"




// ==== CLinkedList::GetCurrentSize ===========================================
//
// This function retrieves the number of items in the list.
//
// Input:
//      void
//
// Output:
//      A int value.
//
// ============================================================================
int CLinkedList::GetCurrentSize() const
{
    // create a pointer to trace through the nodes, starting at headPtr.
    Node    *tracePtr = headPtr;
    int     counter = 0;

    // Cycle through all the Nodes until the end is reached
    while (tracePtr != nullptr)
    {
        // increment counter
        ++counter;

        // change tracePtr to the next node
        tracePtr = tracePtr -> GetNext();
    }

    // update tracePtr to nullptr
    tracePtr = nullptr;

    return counter;

}  // end of "CLinkedList::GetCurrentSize"




// ==== CLinkedList::Add ======================================================
//
// This function inserts an item at the end of the list.
//
// Input:
//      newItem     -- a const reference to the new item to insert into the list
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================
bool CLinkedList::Add(const ListItemType &newItem)
{
    // allocate space for a new node and initialize the item and set next
    // pointer to nullptr and prev pointer to tailPtr.
    Node    *newNode = new Node(newItem, nullptr, tailPtr);
 
    if (tailPtr != nullptr)
    {
        // change newNode next to equal the next from tailPtr if tailPtr != nullptr
        newNode -> SetNext(tailPtr -> GetNext());

        // change tailPtr next to newNode
        tailPtr -> SetNext(newNode);
    }

    // update tailPtr to point to newNode
    tailPtr = newNode;

    // update headPtr if it is nullptr
    if (headPtr == nullptr)
    {
        headPtr = newNode;
    }

    // assign nullptr to newNode
    newNode = nullptr;

    // return true
    return true;

}  // end of "CLinkedList::AddInEnd"




// ==== CLinkedList::IsEmpty ==================================================
//
// This function returns a boolean value if the list is empty.
//
// Input:
//      void
//
// Output:
//      A boolean value. True if list is empty, false otherwise.
//
// ============================================================================
bool CLinkedList::IsEmpty() const
{
    return (headPtr == nullptr);

}  // end of "CLinkedList::IsEmpty"





// ==== CLinkedList::Remove ===================================================
//
// This function removes an item from the list.
//
// The function throws error codes from the class CLinkedListException
//		Ex: "CLinkedList::Remove" Message: "Empty"
//
// Input:
//      value       -- a const reference to an item to remove from the list
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================
bool  CLinkedList::Remove(const ListItemType  &value) throw (CLinkedListException)
{
    // create a pointer to trace (lead) through the nodes, starting at headPtr.
    Node    *leadPtr = headPtr;
    Node    *trailPtr = nullptr; // use a trail pointer to point to the next node.

    // check if the list is empty, if it is return false
    if (IsEmpty())
    {
        leadPtr = nullptr;
        throw CLinkedListException("CLinkedList::Remove", "Empty");
        return false;
    }

    // Remove item if it is in front by checking it if it is equal to value.
    if (leadPtr -> GetItem() == value)
    {
        // change headPtr to point to next node 
        headPtr = leadPtr -> GetNext();

        // change tailPtr to point to nullptr if there is only 1 node
        if (headPtr == nullptr)
        {
            tailPtr = headPtr;
        }

        // change prev to nullptr for the node after leadPtr, assuming headPtr
        // is not nullptr
        if (headPtr != nullptr)
        {
            headPtr -> SetPrev(nullptr);
        }

        // delete what leadPtr points to
        delete leadPtr;

        // assign leadPtr nullptr
        leadPtr = nullptr;

        // return a status of true
        return true;
    }

    // Remove item if it is in the middle or last by looping until leadPtr
    // doesn't point to a nullptr or break when we found the value of interest
    while (leadPtr != nullptr)
    {
        // check if the item is equal to value and the next Node is not nullptr
        if ( (leadPtr -> GetNext() != nullptr)
           &&(leadPtr -> GetNext() -> GetItem() == value) ) 
             
        {
            break;
        }

        // update leadPtr to point to the next node
        leadPtr = leadPtr -> GetNext();
    }

    // check if value was found based if we have reached the end (nullptr)
    if (leadPtr != nullptr)
    {
        // assign trailPtr to the next value
        trailPtr = leadPtr -> GetNext();

        // assign leadPtr to point to the node after the one we want to delete
        leadPtr -> SetNext(trailPtr -> GetNext());

        // assign the prev address of the next Node (after the delete Node) to
        // point to leadPtr.  This is only if trailPtr -> next is not nullptr
        // (last Node).
        if (trailPtr -> GetNext() != nullptr)
        {
            trailPtr -> GetNext() -> SetPrev(leadPtr);
        }
        else // change tailPtr to point to the next to last Node
        {
            tailPtr = leadPtr;
        }

        // delete trailPtr
        delete trailPtr;

        // Assign leadPtr and trailPtr nullptr
        leadPtr = nullptr;
        trailPtr = nullptr;

        // return true
        return true;
    }

    // Nothing to delete as value doesn't exist.  Return false
    leadPtr = nullptr;
    throw CLinkedListException("CLinkedList::Remove", "Empty");
    return false;    

}  // end of "CLinkedList::Remove"



// ==== CLinkedList::Clear ==========================================================
//
// This function clears the list.
//
// Input:
//      void
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================
bool    CLinkedList::Clear()
{
    // Call DestroyList
    return (DestroyList());

} // end CLinkedList::Clear




// ==== CLinkedList::DisplayListAscending =====================================
//
// This function displays the list in ascending order using the headPtr.
//
// Input:
//      void
//
// Output:
//      void
//
// ============================================================================
void    CLinkedList::DisplayListAscending()
{
    // create a pointer to trace through the nodes, starting at headPtr.
    Node    *tracePtr = headPtr;

    // Cycle through all the Nodes until the end is reached
    while (tracePtr != nullptr)
    {
        cout << tracePtr -> GetItem() << endl;

        // update tracePtr
        tracePtr = tracePtr -> GetNext();
    }

    // assign tracePtr a nullptr
    tracePtr = nullptr;

} // end CLinkedList::DisplayListAscending




// ==== CLinkedList::DisplayListDescending ====================================
//
// This function displays the list in descending order using the tailPtr.
//
// Input:
//      void
//
// Output:
//      void
//
// ============================================================================
void    CLinkedList::DisplayListDescending()
{
    // create a pointer to trace through the nodes, starting at tailPtr.
    Node    *tracePtr = tailPtr;

    // Cycle through all the Nodes until the end is reached
    while (tracePtr != nullptr)
    {
        cout << tracePtr -> GetItem() << endl;

        // update tracePtr
        tracePtr = tracePtr -> GetPrev();
    }

    // assign tracePtr a nullptr
    tracePtr = nullptr;

} // end CLinkedList::DisplayListDescending  

