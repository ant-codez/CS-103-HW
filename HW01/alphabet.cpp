#include <iostream>

using namespace std;

void DisplayUppercaseABC() {
    for (char i = 'A'; i <= 'Z'; i++){
        cout << i << " ";
        if (i == 'M')
            cout << endl;
    }
    cout << endl << endl;
}

int main() {
    cout << "About to call the Display UppercaseABC function...\n\n";
    DisplayUppercaseABC();
    cout << "Returned from the DisplayUppercaseABC function.\n";
    return 0;
}

