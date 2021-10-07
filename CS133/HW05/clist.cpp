// ============================================================================
// File: clist.cpp
// ============================================================================
// This is the implementation file for the list ADT CList.  This
// implementation uses a dynamic array to store a list of type ListItemType
// (ints) items.
// ============================================================================

#include    <iostream>
#include    "clist.h"
using namespace std;


// ==== CList::CList (Default) ================================================
//
// This is the default constructor that initializes the variable m_numItems.
//
// ============================================================================
CList::CList()
:m_numItems(0), m_capacity(MAX_ITEMS)
{
    m_items = new ListItemType[m_capacity];

    for (int i = 0; i < m_capacity; i++){
        m_items[i] = 0;
    }
}




// ==== CList::~CList (Destructor) ============================================
//
// This is the destructor, which calls the DestroyList function.
//
// ============================================================================
CList::~CList(){
    DestroyList();
}



// ==== CList::DestroyList ====================================================
//
// This function resets the lists by assigning 0 to m_numItems, m_capacity, and
// releasing the memory of m_items.
//
// Input:
//      void
//
// Output:
//      A bool value indicating if all went well or false otherwise.
//
// ============================================================================
bool CList::DestroyList(){
    m_numItems = 0;
    m_capacity = 0;

    delete [] m_items;

    return true;
}




//// ==== CList::GetItem ========================================================
//
// This function retrieves the value of an item at a particular location.
//
// Input:
//      index   -- the index location for the target item (zero-based).
//
//      item    -- a reference to a ListItemType object. This argument will
//                 contain the desired item after the function completes.
//
// Output:
//      A bool value of success or failure.
//
// ============================================================================
bool CList::GetItem(int index, ListItemType &newItem) const{
    printf("ITEM = [%i]\n", m_items[index]);
   if (m_items[index] == newItem){
       return true;
   }
   else {
       return false;
   }
}




// ==== CList::GetCapacity ====================================================
//
// This function retrieves the capacity in the list.
//
// Input:
//      void
//
// Output:
//      A int value.
//
// ============================================================================
int CList::GetCapacity() const {
    return m_capacity;
}




// ==== CList::GetCurrentSize =================================================
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
int CList::GetCurrentSize() const {
    return m_numItems;
}




// ==== CList::Add ============================================================
//
// This function inserts an item at the end of the list. If the list is full,
// allocate twice the current capacity.
//
// Input:
//      newItem     -- a const reference to the new item to insert into the list
//
// Output:
//      A bool value
//
// ============================================================================
bool CList::Add(const ListItemType &value) {

    for (int i = 0; i < m_capacity; i++){
        temp[i] = 0;
    }

    if (m_items == m_capacity){

    }
}




// ==== CList::IsEmpty ========================================================
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
bool CList::IsEmpty() const {
    if (!m_items[0]){
        return true;
    }
    else{
        false;
    }
}




// ==== CList::IsFull =========================================================
//
// This function returns a boolean value if the list is full.
//
// Input:
//      void
//
// Output:
//      A boolean value. True if list is full, false otherwise.
//
// ============================================================================
bool CList::IsFull() const {
    return m_capacity == m_numItems;
}





// ==== CList::Remove =========================================================
//
// This function removes an item from the list.
//
// If the target item is at the end of the list, the locations of the
// other list items are unaffected.
//
// If the target item is before the end of the list, all elements after
// the target location are moved towards the front of the array one
// position to fill in the gap.
//
// Input:
//      value       -- a const reference to an item to remove from the list
//
// Output:
//      A boolean value of success or failure
//
// ============================================================================
bool CList::Remove(const ListItemType &value) {
    
}




// ==== CList::SetCapacity ====================================================
// This function resizes the memory from the HEAP
//
// Input:
//      num         [IN]    - An integer to increase or decrease the memory
//
// Output:
//      A bool value of success or failure
//
// ============================================================================
bool CList::SetCapacity(int num) {
    ListItemType    *newItems = new ListItemType[num];
    int i = 0;
    int stop;
    int size = 0;

    stop = (m_capacity > num) ? num : m_capacity;

    for (i = 0; i < stop; i++){
        if (m_items[i] != 0){
            size++;
        }
        newItems[i] = m_items[i];
    }

    if (m_capacity < num) {
        for (i = stop; i < num; ++i){
            newItems[i] = 0;
        }
    }

    delete [] m_items;
    m_numItems = size;
    m_capacity = num;
    m_items = newItems;
}




// ==== CList::Clear ==========================================================
// This function clears the entries by resetting the number of m_numItems to 0
// and setting m_capacity to default value (MAX_ITEMS);
//
// Input:
//      void
//
// Output:
//      A bool value of success or failure
//
// ============================================================================
bool CList::Clear() {
    m_numItems = 0;
    m_capacity = MAX_ITEMS;

    if (m_numItems == 0 && m_capacity == MAX_ITEMS){
        return true;
    }
    else{
        return false;
    }
}



// ==== CList::operator= ======================================================
// This is the overloaded assignment operator, copying the parameter's list to
// the calling object.
//
// Input:
//      rhs         -- a reference to a source CList object
//
// Output:
//      A reference to the calling object.
//
// ============================================================================
CList& CList::operator=(const CList &rhs) {
    if (rhs.m_capacity > m_capacity){
        SetCapacity(rhs.m_capacity);
    }

    m_items = rhs.m_items;

    return rhs;
}




// ==== CList::CloseItemGap ======================================================
//
// This function moves the elements of the list forward one position to close
// the gap of deleting an item.
//
// The caller of this function only needs to provide the index (location) of
// the item that was deleted.
//
// Input:
//      index           -- the index location for the target item (zero-based).
//
// Output:
//      A bool value
//
// ============================================================================




// ==== CList::CopyList =======================================================
//
// This function copies the contents of one CList object to another CList
// object.  If the destination object already contains a list, then that list
// is first released.
//
// Input:
//      otherList   -- a const reference to an existing CList object
//
// Output:
//      The total number of items copied from the source object to the
//      destination object.
//
// ============================================================================





// ==== CList::ItemExists =====================================================
//
// This function checks if an item exists in the list. If the list is empty
// index will have a value of -1 and false is returned. If the item
// was not found, false is returned.  If the item was found, the
// location in the list (index) is updated and true is returned.
//
// Input:
//      index   -- the reference index location for the target item
//                 (zero-based). Will update correct index location when it
//                 returns to the caller
//
//      item    -- a reference to a ListItemType object.
//
// Output:
//      A bool value of success or failure
//
// ============================================================================
bool CList::ItemExists(int &index, const ListItemType &item){
    if (IsEmpty()){
        return false;
    }
    
    if (m_items[index] == item){
        
        return true;
    }
    else {
        return false;
    }
}
