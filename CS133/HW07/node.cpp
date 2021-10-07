// ============================================================================
// File: node.cpp
// ============================================================================
// This is the implementation file for the class Node.
// ============================================================================

#include    <iostream>
#include    "node.h"



// ==== Node::Node (Default) ==================================================
//
// This is the default constructor that sets the m_next and m_prev pointer to
// nullptr and leaves item unintialized (garbage).
//
// ============================================================================
Node::Node(){
    m_next = nullptr;
    m_prev = nullptr;
}



// ==== Node::Node (Type) =====================================================
//
// This is the type constructor that sets the m_next and m_prev pointer to
// nullptr and initialzes m_item.
//
// ============================================================================
Node::Node(const ListItemType &item){
    m_next = nullptr;
    m_prev = nullptr;
    m_item = item;
}



// ==== Node::Node (Type) =====================================================
//
// This is the type constructor that initializes m_next and m_prev pointer and
// m_item.
//
// ============================================================================
Node::Node(const ListItemType &item, Node *next, Node *prev){
    m_next = next;
    m_prev = prev;
    m_item = item;
}




// ==== Node::SetItem =========================================================
//
// This function assigns a value to m_item.
//
// Input:
//      item            -- a const reference to the datatype ListItemType
//
// Output:
//      void
//
// ============================================================================
void Node::SetItem(const ListItemType &item){
    m_item = item;
}



// ==== Node::SetNext =========================================================
//
// This function assigns a pointer to m_next
//
// Input:
//      nextNodePtr     -- a pointer to the next Node
//
// Output:
//      void
//
// ============================================================================
void Node::SetNext(Node *next){
    m_next = next;
}



// ==== Node::SetPrev =========================================================
//
// This function assigns a pointer to m_prev
//
// Input:
//      prevNodePtr     -- a pointer to the previous Node
//
// Output:
//      void
//
// ============================================================================
void Node::SetPrev(Node *prev){
    m_prev = prev;
}



// ==== Node::GetItem =========================================================
//
// This function return m_item
//
// Input:
//      void
//
// Output:
//      ListItemType
//
// ============================================================================
ListItemType Node::GetItem() const {
    return m_item;
}



// ==== Node::GetNext =========================================================
//
// This function return m_next
//
// Input:
//      void
//
// Output:
//      Node pointer
//
// ============================================================================
Node* Node::GetNext() const {
    return m_next;
}



// ==== Node::GetPrev =========================================================
//
// This function return m_prev
//
// Input:
//      void
//
// Output:
//      Node pointer
//
// ============================================================================
Node* Node::GetPrev() const {
    return  m_prev;
}
