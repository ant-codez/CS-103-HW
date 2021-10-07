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
//  This program works with the ADT CLinkedList.  It allows the user to remove
// and insert items (nodes) in the list.
// ============================================================================

#include    <iostream>
using namespace std;
#include    "clinkedlist.h"

// global constants
const int MAX_ITEMS = 5;


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    CLinkedList               list;
    int                       numToAdd[MAX_ITEMS] = {10, 12, 15, 5};

    // The following steps will display, add, and remove items in the list to 
    // test all the functions.

    // 1) Display an empty list
    cout << "\n1) Display the number of items and an empty list:\n\n";
    cout << "Number of items: " << list.GetCurrentSize() << endl;
    list.DisplayListAscending();

    // 2) Clear an empty list
    cout << "\n2) Clearing an empty list:\n\n";
    if (!list.Clear())
    {
        cerr << "\nError in clearing list!\n\n";
    }

    // 3) Add some numbers
    cout << "\n3) Adding " << MAX_ITEMS << " numbers to fill the list:\n\n";
    for (int i = 0; i <  MAX_ITEMS; ++i)
    {
        cout << "Adding " << numToAdd[i] << "...\n";

        if (!list.Add(numToAdd[i]))
        {
            cerr << "\nError in adding " << numToAdd[i] << " to the list!\n\n";
        }
        cout << "Number of items: " << list.GetCurrentSize() << endl << endl;
        list.DisplayListAscending();    
    }

    // 4) Display the current list in ascending and descending order
    cout << "\n4) Display the number of items, an ascending ordered list, "
         << "and a descending ordered list:\n\n";
    cout << "Number of items: " << list.GetCurrentSize() << endl << endl;
    list.DisplayListAscending();
    cout << endl << endl;
    list.DisplayListDescending();


    // 5) Delete the first item value (5 and notice how the items get rearranged)
    cout << "\n5) Delete first item (value 5):\n\n";
    if (!list.Remove(5))
    {
        cerr << "\nError in removing item value " << 5 << " from the list!\n\n";
    }

    // 6) Display list
    cout << "\n6) Displaying list:\n\n";
    list.DisplayListAscending();
    
     // 7) Delete a middle item value (12 and notice how the items get rearranged)
    cout << "\n7) Delete a middle item (value 12):\n\n";
    if (!list.Remove(12))
    {
        cerr << "\nError in removing item value " << 12 << " from the list!\n\n";
    }

    // 8) Display list
    cout << "\n8) Displaying list:\n\n";
    list.DisplayListAscending();
    
     // 9) Delete the last item (value 15 and notice how the items get rearranged)
    cout << "\n9) Delete the last item (value 15):\n\n";
    if (!list.Remove(15))
    {
        cerr << "\nError in removing item value " << 15 << " from the list!\n\n";
    }

    // 10) Display list
    cout << "\n10) Displaying list:\n\n";
    list.DisplayListAscending();
    
     // 11) Check if item value 333 exists in the list
    cout << "\n11) Check if item value 333 exists in the list:\n\n";
    if (!list.Contains(333))
    {
        cerr << "\nItem value 333 doesn't exist in the list!\n\n";
    }

    // 12) Delete item value 333, which is not in the list
    cout << "\n12) Delete item value 333, which is not in the list:\n\n";
    if (!list.Remove(333))
    {
        cerr << "\nError in removing item value 333 from the list!\n\n";
    }

    // 13) Clear the list
    cout << "\n13) Clearing the list:\n\n";
    if (!list.Clear())
    {
        cerr << "\nError in clearing list!\n\n";
    }

    // 14) Display list
    cout << "\n14) Displaying an empty list:\n\n";
    list.DisplayListAscending();

    return 0;

}  // end of "main"
