// ============================================================================
// File: clist.h
// ============================================================================
// Header file for the Dynamic CList
// ============================================================================

#ifndef DYNAMIC_CLIST_HEADER
#define DYNAMIC_CLIST_HEADER

// type definitions
typedef int  ListItemType;

// constant(s)
const   int     MAX_ITEMS = 42;

class   CList
{
public:
    // constructor and destructor
    CList();
    ~CList();

    // member functions
    bool      Clear();
    bool      GetItem(int  index, ListItemType  &item) const;
    int       GetCapacity() const;
    int       GetCurrentSize() const;
    bool      Add(const ListItemType  &newItem);
    bool      IsEmpty() const;
    bool      IsFull() const;
    bool      Remove(const ListItemType  &value);
    bool      SetCapacity(int num);
    bool      DestroyList();

    // overloaded operator(s)
    CList&      operator=(const CList &rhs);

private:
    // data members
    int             m_capacity; // current allocated array size from HEAP
    int             m_numItems; // current number of itemsM
    ListItemType    *m_items;   // head pointer (array) to items

    // member functions
    bool     CloseItemGap(int  index);
    int      CopyList(const CList &otherList);
    bool     ItemExists(int &index, const ListItemType &item);
};

#endif  // DYNAMIC_CLIST_HEADER
