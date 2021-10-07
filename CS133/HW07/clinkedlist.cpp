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
CLinkedList::CLinkedList(){
    headPtr = nullptr;
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
    Node *p = headPtr;
    Node *n;

    while (p != nullptr){
        n = p->GetNext();
        delete p;
        p = n;
    }

    if (IsEmpty()) {
        return true;
    }
    else {
        return false;
    }
}




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
bool CLinkedList::GetItem(int index, ListItemType &item) const{
    int currentIndex = 0;
    Node *p = headPtr;

    while (p->GetNext() != nullptr){
        if (++currentIndex == index){
            item = p->GetItem();
            return true;
        }
        p = p->GetNext();
    }

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
bool CLinkedList::Contains(const ListItemType &item) const {
    Node *p = headPtr;

    while(p->GetNext() != nullptr){
        if (p->GetItem() == item){
            return true;
        }
        p = p->GetNext();
    }

    return false;
}




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
int CLinkedList::GetCurrentSize() const {
    if (headPtr == nullptr){
        return 0;
    }

    int items = 1;
    Node *p = headPtr;

    while(p->GetNext() != nullptr){
        items++;
        p = p->GetNext();
    }

    return items;
}




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
bool CLinkedList::Add(const ListItemType &newItem) {
    if (headPtr == nullptr){
        return AddInFront(newItem);
    }

    if (headPtr->GetItem() > newItem){
        return AddInFront(newItem);
    }

    if (tailPtr == nullptr){
        printf("NULL ");
        return AddInEnd(newItem);
    }
    else if (tailPtr->GetItem() < newItem){
                printf("END ");
        return AddInEnd(newItem);
    }

    return AddInMiddle(newItem);
}




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
bool CLinkedList::IsEmpty() const {
    if (headPtr == nullptr){
        return true;
    }
    
    return false;
}




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
bool CLinkedList::Remove(const ListItemType &value){
    if (headPtr == nullptr){
        return false;
    }

    if (headPtr->GetItem() == value){
        Node *t = headPtr;

        headPtr = headPtr->GetNext();
        delete t;

        return true;
    }
    
    Node *p = headPtr;

    while (p->GetNext() != nullptr){
        if (p->GetNext() != nullptr && p->GetNext()->GetItem() == value){
            break;
        }
        p = p->GetNext();
    }

    if (p != nullptr) {
        Node *target = p->GetNext();

        p->SetNext(target->GetNext());

        delete target;
        return true;
    }

    return false;
}




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
bool CLinkedList::Clear() {
    if (headPtr == nullptr){
        return true;
    }

    Node *p = headPtr;
    Node *temp = new Node;

    while (p->GetNext() != nullptr) {
        temp = p->GetNext();
        delete p;
        p = temp;
    }

    if (IsEmpty()){
        return true;
    }
    else {
        return false;
    }
}




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
void CLinkedList::DisplayListAscending() {
    if (headPtr == nullptr){
        printf("\n");
    }
    else {
        Node *p = headPtr;

        while (p->GetNext()) {
            cout << p->GetItem() << endl;

            p = p->GetNext();
        }
    }
}



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
void CLinkedList::DisplayListDescending() {
    if (tailPtr == nullptr){
        printf("\n");
    }
    else {
        Node *p = tailPtr;
        while (p->GetPrev() != nullptr) {
            cout << p->GetItem() << endl;

            p = p->GetPrev();
        }
    }
}




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
/*
char CLinkedList::NewItemLocation(const ListItemType &newItem) {

}
*/


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
bool CLinkedList::AddInFront(const ListItemType &newItem) {
    printf("ADD TO FRONT\n");
    Node *p = new Node(newItem, headPtr, nullptr);

    if (headPtr != nullptr) {
        headPtr->SetPrev(p);
    }

    headPtr = p;

    if (tailPtr == nullptr){
        tailPtr = p;
    }

    p = nullptr;

    return true;
}




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
bool CLinkedList::AddInEnd(const ListItemType &newItem) {
    printf("ADD TO END\n");
    Node *n = new Node(newItem, nullptr, tailPtr);

    if (tailPtr != nullptr){
        n->SetNext(tailPtr->GetNext());
        tailPtr->SetNext(n);
    }   

    tailPtr = n;

    if (headPtr == nullptr){
        headPtr = n;
    }

    n = nullptr;

    return true;
}




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
bool CLinkedList::AddInMiddle(const ListItemType &newItem) {
        printf("ADD TO MID\n");

    Node *p = headPtr;

    while(p->GetNext() != nullptr){
        if (p->GetNext()->GetItem() > newItem) {
            break;
        }

        p = p->GetNext();
    }

    Node *n = new Node(newItem, p->GetNext(), p);

    p->SetNext(n);

    return Contains(newItem);
}
