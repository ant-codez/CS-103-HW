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





// ==== CLinkedList::~CLnkedList (Destructor) =================================
//
// This is the destructor, which releases all the nodes.
//
// ============================================================================





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





// ==== CLinkedList::GetItem ==================================================
//
// This function retrieves the value of an item at a particular location 
// (particular node).
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





// ==== CLinkedList::Add ======================================================
//
// This function inserts an item in the list.  However, it makes sure that the
// values are still in ascending order.
//
// Input:
//      newItem     -- a const reference to the new item to insert into the list
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================





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





// ==== CLinkedList::Remove ===================================================
//
// This function removes an item from the list.
//
// Input:
//      value       -- a const reference to an item to remove from the list
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================





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
  




// ==== CLinkedList::NewItemLocation ==========================================
//
// This function checks where to add a new item ('F'ront, 'M'iddle, or 'E'nd)
//
// Note: The function expects that the list has at least one item.
//
// Input:
//      newitem    -- a reference to a ListItemType object.
//
// Output:
//      A char of the location to put the new item ('F'ront, 'M'iddle, 
//      or 'E'nd)
//
// ============================================================================




// ==== CLinkedList::AddInFront ===============================================
//
// This function inserts a new node in the front of the list
//
// Input:
//      newitem    -- a reference to a ListItemType object.
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================





// ==== CLinkedList::AddInEnd =================================================
//
// This function inserts a new node at the end of the list
//
// Input:
//      newitem    -- a reference to a ListItemType object.
//
// Output:
//      A boolean value of success or failure.
//
// ============================================================================





// ==== CLinkedList::AddInMiddle ==============================================
//
// This function inserts a new node in the middle of the list
//
// Input:
//      newitem    -- a reference to a ListItemType object.
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================

