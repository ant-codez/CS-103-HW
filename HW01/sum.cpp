// =========================================================================
// sum.cpp
// Recieve 3 (int) from the command line. Evaluates the sum of all (int)
// and prints to command line as output
// =========================================================================
#include <iostream>
using namespace std;

int main() {
    int intvar1;
    int intvar2;
    int intvar3;
    
    cout << "Enter integer one: ";
    cin >> intvar1;
    cout << "\nEnter integer two: ";
    cin >> intvar2;
    cout << "\nEnter integer three: ";
    cin >> intvar3;
    cout << endl << intvar1 << " + " << intvar2 << " + " << intvar3 << " = " << intvar1 + intvar2 + intvar3 << endl;
    return 0;
}