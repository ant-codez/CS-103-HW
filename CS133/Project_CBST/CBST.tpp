// ============================================================================
// File: CBST.tpp
// ============================================================================
// Implementation file for the class CBST
// ============================================================================



// ==== CBST<ItemType>::CBST ===================================================
//
// This is the default constructor for CBST<ItemType>. It sets the root to
// nullptr.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBST<ItemType>::CBST() {
    this->SetRootPtr(nullptr);
}




// ==== CBST<ItemType>::CBST ===================================================
//
// This is the type constructor for CBST<ItemType>.  It allocates a space for a
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
template<class ItemType>
CBST<ItemType>::CBST(const ItemType &rootItem) { 
    CBinaryNode<ItemType> *Root = new CBinaryNode<ItemType>(rootItem);
    this->SetRootPtr(Root);
}




// ==== CBST<ItemType>::CBST ===================================================
//
// This is the copy constructor for CBST<ItemType>. It creates a deep copy of
// "tree."
//
// Input:
//       tree   [IN]    - A const templated CBST that will be copied.
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBST<ItemType>::CBST(const CBST<ItemType> &tree) {
    this->SetRootPtr(this->CopyTree(tree.GetRootPtr()));
}




// ==== CBST<ItemType>::~CBST ==================================================
//
// This is the destructor for CBST<ItemType>.  It will release all the nodes
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
CBST<ItemType>::~CBST() {
    this->Clear();
}




// ==== CBST<ItemType>::Add ====================================================
//
// This function adds an item to a tree.  Calls the PlaceNode function to add
// the node to the tree to make sure it is balanced using AVL.
//
// Input:
//       newEntry   [IN]    - A const ItemType reference to the new entry to be
//                              added to the tree.
//       
// Output:
//       Returns true if successful, otherwise false.
//
// =============================================================================
template<class ItemType>
bool CBST<ItemType>::Add(const ItemType &newEntry) {
    CBinaryNode<ItemType>* nodePtr = new CBinaryNode<ItemType>(newEntry);
    this->SetRootPtr(PlaceNode(this->GetRootPtr(), nodePtr));

    return true;
}




// ==== CBST<ItemType>::Remove =================================================
//
// This function removes an entry (a node), if it exists, from the tree.
//
// Input:
//       anEntry    [IN]    - A const ItemType reference to the new entry to be
//                              added to the tree.
//
// Output:
//       Returns true if successful, otherwise false.
//
// =============================================================================
template<class ItemType>
bool CBST<ItemType>::Remove(const ItemType &anEntry) {
    bool success = false;
    this->SetRootPtr(RemoveValue(this->GetRootPtr(), anEntry, success));
    
    return success;
}




// ==== CBST<ItemType>::operator= ==============================================
//
// This function assigns the right-hand side CBST to the left-hand side CBST.
// Make sure to protect against assignment to self!
//
// Input:
//       rhs    [IN]    - A const templated CBST to copy from.
// Output:
//       A templated CBST reference object (the left-hand side of the tree.
//
// =============================================================================
template<class ItemType>
CBST<ItemType>& CBST<ItemType>::operator=(const CBST<ItemType> &rhs) {
    if (&rhs != this) {
        CBST<ItemType> *temp = new CBST<ItemType>(rhs);
        this->Clear();
        this->SetRootPtr(temp->GetRootPtr());
        temp->SetRootPtr(nullptr);
    }
    
    return *this;
}




// ==== CBST<ItemType>::PlaceNode ==============================================
//
// This function adds a node in the tree. It makes sure that the same node value
// is not added twice.  Furthermore, as soon as it adds a node, it makes sure
// the tree is still AVL balanced.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of where to add the node.
//      nodePtr     [IN]    - A templated CBinaryNode pointer node that will be
//                              added to the tree.
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of
//          the updated parent node pointer (after any shifts caused from AVL
//          balancing, parent node may need updating).
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::PlaceNode(CBinaryNode<ItemType> *subTreePtr, CBinaryNode<ItemType> *newNode) {
    if (subTreePtr == nullptr){
        subTreePtr = newNode;
        return subTreePtr;
    }
    
    if (newNode->GetItem() < subTreePtr->GetItem()){
        subTreePtr->SetLeftChildPtr(PlaceNode(subTreePtr->GetLeftChildPtr(), newNode));
    }
    else if (newNode->GetItem() > subTreePtr->GetItem()) {
        subTreePtr->SetRightChildPtr(PlaceNode(subTreePtr->GetRightChildPtr(), newNode));
    }
    else {
        //found duplicate
        return subTreePtr;
    }

    int bf = getBalanceFactor(subTreePtr);

    //left left
    if (bf > 1 && newNode->GetItem() < subTreePtr->GetLeftChildPtr()->GetItem()) {
        return RightRotate(subTreePtr);
    }
    //right right
    if (bf < -1 && newNode->GetItem() > subTreePtr->GetRightChildPtr()->GetItem()) {
        return LeftRotate(subTreePtr);
    }
    //left right
    if (bf > 1 && newNode->GetItem() > subTreePtr->GetLeftChildPtr()->GetItem()) {
        return LeftRightRotate(subTreePtr);
    }
    //right left
    if (bf < -1 && newNode->GetItem() < subTreePtr->GetRightChildPtr()->GetItem()) {
        return RightLeftRotate(subTreePtr);
    }

    return subTreePtr;
}




// ==== CBST<ItemType>::LeftRotate =============================================
//
// This function rotates the nodes to the left.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::LeftRotate(CBinaryNode<ItemType> *subTreePtr) {
    CBinaryNode<ItemType> *temp = subTreePtr->GetRightChildPtr();
    subTreePtr->SetRightChildPtr(temp->GetLeftChildPtr());
    temp->SetLeftChildPtr(subTreePtr);

    return temp;
}




// ==== CBST<ItemType>::RightRotate ============================================
//
// This function rotates the nodes to the right.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RightRotate(CBinaryNode<ItemType> *subTreePtr) {
    CBinaryNode<ItemType> *pivot = subTreePtr->GetLeftChildPtr();
    subTreePtr->SetLeftChildPtr(pivot->GetRightChildPtr());
    pivot->SetRightChildPtr(subTreePtr);

    return pivot;
}




// ==== CBST<ItemType>::LeftRightRotate ========================================
//
// This function rotates the nodes to the left and then right.  In other words,
// it rotates the left child of subTreePtr to the left and then rotates
// subTreePtr to the right.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::LeftRightRotate(CBinaryNode<ItemType> *subTreePtr) {
    subTreePtr->SetLeftChildPtr(LeftRotate(subTreePtr->GetLeftChildPtr()));
    CBinaryNode<ItemType> *temp = RightRotate(subTreePtr);

    return temp;
}




// ==== CBST<ItemType>::RightLeftRotate ========================================
//
// This function rotates the nodes to the right and then left.  In other words,
// it rotates the right child of subTreePtr to the right and then rotates
// subTreePtr to the left.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RightLeftRotate(CBinaryNode<ItemType> *subTreePtr) {
    subTreePtr->SetRightChildPtr(RightRotate(subTreePtr->GetRightChildPtr()));
    CBinaryNode<ItemType> *temp = LeftRotate(subTreePtr);

    return temp;
}


// ==== CBST<ItemType>::getBalanceFactor ========================================
//
// This function recursively travels down the subTree given and returns the 
// current balance factor of the subTree
//
// Input:
//      subTreePtr  [IN]    - A subTree whos balance factor we want to inspect
//                            
// Output:
//       An integer representing the current balance factor of the tree recieved
//
// =============================================================================
template<class ItemType>
int CBST<ItemType>::getBalanceFactor(const CBinaryNode<ItemType> *subTreePtr) {
    if (subTreePtr == nullptr) {
        return -1;
    }
    
    return this->GetHeightHelper(subTreePtr->GetLeftChildPtr()) - this->GetHeightHelper(subTreePtr->GetRightChildPtr());
}


// ==== CBST<ItemType>::RemoveValue ============================================
//
// This function removes a value from the tree.  It also keeps the tree AVL
// balanced after each removal.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of the node to remove.
//      target      [IN]    - A const ItemType value that we want to remove from
//                              the tree.
//      success     [OUT]   - A bool value that is marked true if sucessful,
//                              false otherwise.
//
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the removal.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::RemoveValue(CBinaryNode<ItemType> *subTreePtr, const ItemType &target, bool &success) {
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    }
    else if (subTreePtr->GetItem() > target) {
        subTreePtr->SetLeftChildPtr(RemoveValue(subTreePtr->GetLeftChildPtr(), target, success));
    }
    else if (subTreePtr->GetItem() < target) {
        subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), target, success));
    }
    else {
        if (subTreePtr->GetLeftChildPtr() == nullptr) {
            CBinaryNode<ItemType> *temp = subTreePtr->GetRightChildPtr();
            delete subTreePtr;
            success = true;
            return temp;
        }
        else if (subTreePtr->GetRightChildPtr() == nullptr) {
            CBinaryNode<ItemType> *temp = subTreePtr->GetLeftChildPtr();
            delete subTreePtr;
            success = true;
            return temp;
        }
        else {
            CBinaryNode<ItemType> *temp = this->FindMinNode(subTreePtr->GetRightChildPtr()); 
            subTreePtr->SetItem(temp->GetItem());
            subTreePtr->SetRightChildPtr(RemoveValue(subTreePtr->GetRightChildPtr(), temp->GetItem(), success));
        }
    }

    int bf = getBalanceFactor(subTreePtr);

    //left left imbalance
    if (bf == 2 && getBalanceFactor(subTreePtr->GetLeftChildPtr()) >= 0) {
        success = true;
        return RightRotate(subTreePtr);
    }
    //left right imbalance
    else if (bf == 2 && getBalanceFactor(subTreePtr->GetLeftChildPtr()) == -1) {
        success = true;
        subTreePtr->SetLeftChildPtr(LeftRotate(subTreePtr->GetLeftChildPtr()));
        return RightRotate(subTreePtr);
    }
    //right right imbalance
    else if (bf == -2 && getBalanceFactor(subTreePtr->GetRightChildPtr()) <= 0){
        success = true;
        return LeftRotate(subTreePtr);
    }
    //right left imbalance
    else if (bf == -2 && getBalanceFactor(subTreePtr->GetRightChildPtr()) == 1){
        success = true;
        subTreePtr->SetRightChildPtr(RightRotate(subTreePtr->GetRightChildPtr()));
        return LeftRotate(subTreePtr);
    }

    return subTreePtr;
}




// ==== CBinaryNodeTree<ItemType>::FindNode ====================================
//
// This function finds a target node if it exists.
//
// Input:
//      treePtr     [IN]    - A templated CBinaryNode pointer to start the
//                              search of the node to find
//      target      [IN]    - A const ItemType value that we want to find from
//                              the tree.
//      success     [OUT]   - A bool value that is marked true if sucessful,
//                              false otherwise.
//
// Output:
//       An CBinaryNode<ItemType> templated pointer of the node found.  If not
//          found, a nullptr is returned.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* CBST<ItemType>::FindNode(CBinaryNode<ItemType> *subTreePtr, const ItemType &target, bool &success) const {
    if (subTreePtr == nullptr){
        success = false;
        return nullptr;
    }
    else if (subTreePtr->GetItem() == target) {
        success = true;
        return subTreePtr;
    }
    else if (subTreePtr->GetItem() > target) {
        return FindNode(subTreePtr->GetLeftChildPtr(), target, success);
    }
    else{
        return FindNode(subTreePtr->GetRightChildPtr(), target, success);
    }
}

