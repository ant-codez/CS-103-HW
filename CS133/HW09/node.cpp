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

Node::Node() : m_next(nullptr), m_prev(nullptr)
{
} // end of Node::Node



// ==== Node::Node (Type) =====================================================
//
// This is the type constructor that sets the m_next and m_prev pointer to
// nullptr and initialzes m_item.
//
// ============================================================================

Node::Node(const ListItemType &item) : m_item(item), m_next(nullptr),
                                                     m_prev(nullptr)
{
} // end of Node::Node



// ==== Node::Node (Type) =====================================================
//
// This is the type constructor that initializes m_next and m_prev pointer and
// m_item.
//
// ============================================================================

Node::Node(const ListItemType &item, Node *nextNodePtr, Node *prevNodePtr) : 
                m_item(item), m_next(nextNodePtr), m_prev(prevNodePtr)
{
} // end of Node::Node




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

void     Node::SetItem(const ListItemType &item)
{
    m_item = item;    
} // end of Node::SetItem



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

void     Node::SetNext(Node *nextNodePtr)
{
    m_next = nextNodePtr;    
} // end of Node::SetNext



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

void     Node::SetPrev(Node *prevNodePtr)
{
    m_prev = prevNodePtr;    
} // end of Node::SetPrev



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

ListItemType     Node::GetItem() const
{
    return m_item;    
} // end of Node::GetItem



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

Node*     Node::GetNext() const
{
    return m_next;    
} // end of Node::GetNext



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

Node*     Node::GetPrev() const
{
    return m_prev;    
} // end of Node::GetNext
