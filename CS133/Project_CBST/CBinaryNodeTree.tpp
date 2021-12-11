// =============================================================================
// File: CBinaryNodeTree.tpp
// =============================================================================
// Implementation file for the class CBinaryNodeTree.tpp
// =============================================================================

#include <iostream>
#include <queue>          // std::queue
#include <stack>


// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the default constructor for CBinaryNodeTree.  It sets the root to
// nullptr.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(){
    m_rootPtr = nullptr;
}




// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the type constructor for CBinaryNodeTree.  It allocates a space for a
// CBinaryNode and sets it equal to m_rootPtr.  The new node will have it's
// right and left child pointers set to nullptr.
//
// Input:
//       rootItem   [IN]    - A const reference ItemType.
//       
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType &rootItem) {
    m_rootPtr = rootItem;
}




// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the type constructor for CBinaryNodeTree.  It allocates a space for a
// CBinaryNode and sets it equal to m_rootPtr.  The new node will have it's
// right and left child pointers set to rightTreePtr and leftTreePtr,
// respectively.
//
// Input:
//       rootItem      [IN]    - A const ItemType reference to initialize the
//                                  new node.
//       leftTreePtr   [IN]    - A const CBinaryNode<ItemType> pointer that
//                                  points to the left child.
//       rightTreePtr  [IN]    - A const CBinaryNode<ItemType> pointer that
//                                  points to the right child.
//       
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType &rootItem, const CBinaryNodeTree<ItemType> *leftTreePtr, const CBinaryNodeTree<ItemType> *rightTreePtr) {
    m_rootPtr = rootItem;
    m_rootPtr->SetLeftChildPtr(leftTreePtr);
    m_rootPtr->SetRightChildPtr(rightTreePtr);
}




// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the copy constructor for CBinaryNodeTree. It creates a deep copy of
// "tree."
//
// Input:
//       tree   [IN]    - A const templated CBinaryNodeTree that will be copied.
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const CBinaryNodeTree<ItemType> &tree) {
    m_rootPtr = tree.GetRootPtr();
}




// ==== CBinaryNodeTree<ItemType>::~CBinaryNodeTree ============================
//
// This is the destructor for CBinaryNodeTree.  It will release all the nodes
// from the heap.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBinaryNodeTree<ItemType>::~CBinaryNodeTree() {
    Clear();
}




// ==== CBinaryNodeTree<ItemType>::IsEmpty =====================================
//
// This function checks if the tree is empty or not.
//
// Input:
//       void
//
// Output:
//       Returns true if the tree is empty, otherwise false.
//
// =============================================================================
template<class ItemType>
bool CBinaryNodeTree<ItemType>::IsEmpty() const {
    if (m_rootPtr == nullptr){
        return true;
    }
    
    return false;
}




// ==== CBinaryNodeTree<ItemType>::GetHeight ===================================
//
// This function returns the height of the tree.  It calls the protected member
// function GetHeightHelper to get the height from the root of the tree.
//
// Input:
//       void
//
// Output:
//       Returns an integer for the height of the tree.
//
// =============================================================================
template<class ItemType>
int CBinaryNodeTree<ItemType>::GetHeight() const {
    return GetHeightHelper(m_rootPtr);
}




// ==== CBinaryNodeTree<ItemType>::GetNumberOfNodes ============================
//
// This function returns the number of nodes in the tree.  It calls the
// protected member function GetNumberOfNodesHelper to get the number of nodes
// from the root of the tree.
//
// Input:
//       void
//
// Output:
//       Returns an integer for the number of nodes in the tree.
//
// =============================================================================
template<class ItemType>
int CBinaryNodeTree<ItemType>::GetNumberOfNodes() const {
    return GetNumberOfNodesHelper(m_rootPtr);
}




// ==== CBinaryNodeTree<ItemType>::GetRootData =================================
//
// This function returns the data item in the root of the tree.
//
// Throws a PrecondViolatedExcept if the root of the tree is empty (nullptr).
//
// Input:
//       void
//
// Output:
//       Returns an ItemType, which is the item in the root of the tree.
//
// =============================================================================
template<class ItemType>
ItemType CBinaryNodeTree<ItemType>::GetRootData() const throw(PrecondViolatedExcept) {
    if (IsEmpty())
        throw PrecondViolatedExcept("Error. Root of tree is Empty.\n");
    
    return m_rootPtr->GetItem();
}




// ==== CBinaryNodeTree<ItemType>::SetRootData =================================
//
// This function sets the data item in the root of the tree.
//
// Input:
//       newData    [IN]    - A const ItemType reference that has the new data
//                              value.
//       
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::SetRootData(const ItemType &newData) {
    m_rootPtr->SetItem(newData);
}





// ==== CBinaryNodeTree<ItemType>::Clear =======================================
//
// This function removes all nodes from the heap and sets the root pointer to
// nullptr.  To make things easier, this function can call the member function
// DestroyTree.
//
// Input:
//       void
//       
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::Clear() {

    DestroyTree(m_rootPtr);
    m_rootPtr = nullptr;
}




// ==== CBinaryNodeTree<ItemType>::Contains ====================================
//
// This function checks if a particular entry exists in the tree.
//
// Input:
//       anEntry    [IN]    - A const ItemType reference to check of its
//                              existence.
//
// Output:
//       Returns true if the entry is already in the tree, false otherwise.
//
// =============================================================================
template<class ItemType>
bool CBinaryNodeTree<ItemType>::Contains(const ItemType &anEntry) const {
    bool success;

    FindNode(m_rootPtr, anEntry, success);

    return success;
}




// ==== CBinaryNodeTree<ItemType>::PreorderTraverse ============================
//
// This function traverses in pre-order by calling the protected member function
// Preorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::PreorderTraverse(void Visit(const ItemType &item)) const {
    Preorder(Visit, m_rootPtr);
}




// ==== CBinaryNodeTree<ItemType>::InorderTraverse =============================
//
// This function traverses in in-order by calling the protected member function
// Inorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::InorderTraverse(void Visit(const ItemType &item)) const {
    Inorder(Visit, m_rootPtr);
}




// ==== CBinaryNodeTree<ItemType>::PostorderTraverse ===========================
//
// This function traverses in post-order by calling the protected member
// function Postorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::PostorderTraverse(void Visit(const ItemType &item)) const {
    Postorder(Visit, m_rootPtr);
}




// ==== CBinaryNodeTree<ItemType>::LevelorderTraverse ==========================
//
// This function traverses in level-order by calling the protected member
// function Levelorder for each level to process.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::LevelorderTraverse(void Visit(const ItemType &item)) const {
    Levelorder(Visit, m_rootPtr, GetHeight());
}




// ==== CBinaryNodeTree<ItemType>::operator= ==================================
//
// This function assigns the right-hand side CBinaryNodeTree to the left-hand
// side CBinaryNodeTree.  Make sure to protect against assignment to self!
//
// Input:
//       rhs    [IN]    - A const templated CBinaryNodeTree to copy from.
//
// Output:
//       A templated CBinaryNodeTree reference object (the left-hand side of the
//          tree.
//
// =============================================================================
template<class ItemType>
CBinaryNodeTree<ItemType>& CBinaryNodeTree<ItemType>::operator=(const CBinaryNodeTree<ItemType> &rhs) {
    //RETURRN TO THIS
    if (m_rootPtr != rhs->GetRootPtr()) {
        CBinaryNodeTree<ItemType> *temp = new CBinaryNodeTree<ItemType>(rhs);
        Clear();
        m_rootPtr = temp->GetRootPtr();
        temp->SetRootPtr(nullptr);
    }

    return *m_rootPtr;
}





// ==== CBinaryNodeTree<ItemType>::GetRootPtr ==================================
//
// This function returns m_rootPtr
//
// Input:
//       Nothing
//
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of the
//          root pointer.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::GetRootPtr() const {
    return m_rootPtr;
}




// ==== CBinaryNodeTree<ItemType>::SetRootPtr ==================================
//
// This function sets m_rootPtr
//
// Input:
//       rootPtr    [IN]    - A CBinaryNode<ItemType> pointer.
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::SetRootPtr(CBinaryNode<ItemType> *rootptr) {
    m_rootPtr = rootptr;
}




// ==== CBinaryNodeTree<ItemType>::GetParentNode ===============================
//
// This function searches for the parent node of any node in the tree.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of the parent node.
//      nodePtr     [IN]    - A templated CBinaryNode pointer to find the parent
//                              of.
//
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of the
//          parent node pointer.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::GetParentNode(CBinaryNode<ItemType> *subTreePtr, CBinaryNode<ItemType> *nodePtr) const {
    //Not sure if needed
    if (subTreePtr == nullptr) {
        return subTreePtr;
    }

    if (subTreePtr->GetItem() == nodePtr){
        return subTreePtr;
    }
    else {
        GetParentNode(subTreePtr->GetLeftChildPtr(), nodePtr);
        GetParentNode(subTreePtr->GetRightChildPtr(), nodePtr);
    }
}




// ==== CBinaryNodeTree<ItemType>::GetHeightHelper =============================
//
// This function finds the height starting at subTreePtr (this could be root or
// any other node within the tree).
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the height
//                              from.
//
// Output:
//       An int that is the height from subTreePtr.
//
// =============================================================================
template<class ItemType>
int CBinaryNodeTree<ItemType>::GetHeightHelper(CBinaryNode<ItemType> *subTreePtr) const {
    if (subTreePtr == nullptr){
        return -1;
    }
    else {
        int leftHeight = GetHeightHelper(subTreePtr->GetLeftChildPtr());
        int rightHeight = GetHeightHelper(subTreePtr->GetRightChildPtr());

        if (leftHeight > rightHeight){
            return (leftHeight + 1);
        }
        else{
            return (rightHeight + 1);
        }
    }
}





// ==== CBinaryNodeTree<ItemType>::GetNumberOfNodesHelper ======================
//
// This function finds the number of nodes starting at subTreePtr (this could be
// root or any other node within the tree).
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the number
//                              of nodes from.
//
// Output:
//       An int that represents the number of nodes from subTreePtr.
//
// =============================================================================
template<class ItemType>
int CBinaryNodeTree<ItemType>::GetNumberOfNodesHelper(CBinaryNode<ItemType> *subTreePtr) const {
    if (subTreePtr == nullptr)
        return 0;
    
    int num = 0;
    if (subTreePtr->GetLeftChildPtr() && subTreePtr->GetRightChildPtr()){
        num++;
    }

    num += (GetNumberOfNodesHelper(subTreePtr->GetLeftChildPtr() + GetNumberOfNodesHelper(subTreePtr->GetRightChildPtr())));

    return num;
}




// ==== CBinaryNodeTree<ItemType>::FindMinNode =================================
//
// This function finds the minimum ItemType Node in the tree starting from
// subTreePtr. If there is no minimum ItemType Node found, the function returns
// nullptr.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the
//                              minimum node from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the minimum
//          node.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::FindMinNode(CBinaryNode<ItemType> *subTreePtr) {
    CBinaryNode<ItemType> *minNode = subTreePtr;

    while (minNode->GetLeftChildPtr() != nullptr)
    {
        minNode = minNode->GetLeftChildPtr();
    }

    return minNode;
}




// ==== CBinaryNodeTree<ItemType>::FindMaxNode =================================
//
// This function finds the maximum ItemType Node in the tree starting from
// subTreePtr. If there is no maximum ItemType Node found, the function returns
// nullptr.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the
//                              maximum node from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the maximum
//          node.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::FindMaxNode(CBinaryNode<ItemType> *subTreePtr) {
    CBinaryNode<ItemType> *maxNode = subTreePtr;

    while (maxNode->GetRightChildPtr() != nullptr)
    {
        maxNode = maxNode->GetRightChildPtr();
    }

    return maxNode;
}




// ==== CBinaryNodeTree<ItemType>::CopyTree ====================================
//
// This function copies a tree using a deep copy.
//
// Input:
//      oldTreeRootPtr  [IN]    - A templated CBinaryNode pointer to copy from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the new root.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBinaryNodeTree<ItemType>::CopyTree(const CBinaryNode<ItemType> *oldTreeRootPtr) const {
    CBinaryNode<ItemType>* newTreePtr = nullptr;

    if (oldTreeRootPtr != nullptr) {
        newTreePtr = new CBinaryNode<ItemType>(oldTreeRootPtr->GetItem(), nullptr, nullptr);
        
        newTreePtr->SetLeftChildPtr(CopyTree(oldTreeRootPtr->GetLeftChildPtr()));
        newTreePtr->SetRightChildPtr(CopyTree(oldTreeRootPtr->GetRightChildPtr()));
    }

    return newTreePtr;
}




// ==== CBinaryNodeTree<ItemType>::DestroyTree =================================
//
// This function destroys a tree.  In other words, it releases the memory from
// the heap.
//
// Input:
//       CBinaryNode<ItemType> *subTreePtr [IN/OUT] - The tree to destroy.
//       
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::DestroyTree(CBinaryNode<ItemType> *subTreePtr) {
    if (subTreePtr != nullptr) {
       DestroyTree(subTreePtr->GetLeftChildPtr());
       DestroyTree(subTreePtr->GetRightChildPtr());
       delete subTreePtr;
    }
}




// ==== CBinaryNodeTree<ItemType>::Preorder ====================================
//
// This function traverses the tree in pre-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::Preorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr) const {
    if (treePtr == nullptr)
        return;

    Visit(treePtr->GetItem());
    Preorder(Visit, treePtr->GetLeftChildPtr());
    Preorder(Visit, treePtr->GetRightChildPtr());
}




// ==== CBinaryNodeTree<ItemType>::Inorder ====================================
//
// This function traverses the tree in in-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::Inorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr) const {
    if (treePtr == nullptr)
        return;

    Inorder(Visit, treePtr->GetLeftChildPtr());
    Visit(treePtr->GetItem());
    Inorder(Visit, treePtr->GetRightChildPtr());
}




// ==== CBinaryNodeTree<ItemType>::Postorder ===================================
//
// This function traverses the tree in post-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::Postorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr) const {
    if (treePtr == nullptr)
        return;

    Postorder(Visit, treePtr->GetLeftChildPtr());
    Postorder(Visit, treePtr->GetRightChildPtr());
    Visit(treePtr->GetItem());
}




// ==== CBinaryNodeTree<ItemType>::Levelorder ==================================
//
// This function traverses the tree in level-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//		level                      [IN]    - The height of the tree (total
//                                              levels to process).
//
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void CBinaryNodeTree<ItemType>::Levelorder(void Visit(const ItemType &item), CBinaryNode<ItemType> *treePtr, int level) const {
    if (treePtr == nullptr)
        return;
    
    queue<CBinaryNode<ItemType>*> q;
    q.push(treePtr);

    while(!q.empty()) {
        CBinaryNode<ItemType> *current = q.front();

        Visit(current->GetItem());
        if (current->GetLeftChildPtr() != nullptr)
            q.push(current->GetLeftChildPtr());
        if (current->GetRightChildPtr() != nullptr)
            q.push(current->GetRightChildPtr());
        q.pop();
    }

}

