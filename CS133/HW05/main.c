// ============================================================================
// File: main.cpp
// ============================================================================
// Programmer: ???
// Date: ???
// Class: CSCI 133 ("Data Structures Using C++")
// Time: ???
// Instructor: Dr. Rodriguez
// Project: ???
//
// Description:
//  This program works with the ADT CList.  It allows the user to remove and
//  insert items in the list.
// ============================================================================

#include    <iostream>
using namespace std;
#include    "clist.h"

// function prototypes
void    DisplayList(const CList  &list);



// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    CList               list;
    CList               list2;

    // The following steps will display, add, and remove items in the list to
    // test all the functions.

    // 1) Display capacity, number of items, and an empty list
    cout << "\n1) Display capacity, number of items, and an empty list:\n\n";
    cout << "Capacity: " << list.GetCapacity() << endl;
    cout << "Number of items: " << list.GetCurrentSize() << endl;
    DisplayList(list);

    // 2) Clear an empty list
    cout << "\n2) Clearing an empty list:\n\n";
    if (!list.Clear())
    {
        cerr << "\nError in clearing list!\n\n";
    }

    // 3) Add some numbers
    cout << "\n3) Inserting 5 numbers to fill the list:\n\n";
    for (int i = 10; i < (10 + MAX_ITEMS); ++i)
    {
            cout << "Adding " << i << "...\n";

        if (!list.Add(i))
        {
            cerr << "\nError in adding " << i << " to the list!\n\n";
        }

    }

    // 4) Display a full list
    cout << "\n4) Displaying a full list:\n\n";
    DisplayList(list);

    // 5) Add one more number to be over the limit and see the capacity resize
    cout << "\n5) Inserting one more item beyond the full list:\n\n";
    if (!list.Add(9))
    {
        cerr << "\nError in adding 9 to the list!\n\n";
    }

    // 6) Display capacity, number of items, and a "fuller" list
    cout << "\n6) Display capacity, number of items, and a \"fuller\" list:\n\n"                       ;
    cout << "Capacity: " << list.GetCapacity() << endl;
    cout << "Number of items: " << list.GetCurrentSize() << endl;
    DisplayList(list);

    // 7) Delete item value 10 (notice how numbers get rearranged)
    cout << "\n7) Delete item value 10:\n\n";
    if (!list.Remove(10))
    {
        cerr << "\nError in removing item value 10 from the list!\n\n";
    }

    // 8) Display list
    cout << "\n8) Displaying list:\n\n";
    DisplayList(list);

    // 9) Delete item value 333, which is not in the list
    cout << "\n9) Delete item value 333, which is not in the list:\n\n";
    if (!list.Remove(333))
    {
        cerr << "\nError in removing item value 333 from the list!\n\n";
    }

    // 10) Display list
    cout << "\n10) Displaying list:\n\n";
    DisplayList(list);

    // 11) Copy list to list2 and display list2.
    // Note: We'll let the destructor clear list2.
    cout << "\n11) Copy list to list2 and display list2:\n\n";
    list2 = list;
    DisplayList(list2);

    // 12) Clear the list
    cout << "\n12) Clearing the list:\n\n";
    if (!list.Clear())
    {
        cerr << "\nError in clearing list!\n\n";
    }

    // 13) Display list
    cout << "\n13) Displaying an empty list:\n\n";
    DisplayList(list);

    return 0;

}  // end of "main"
