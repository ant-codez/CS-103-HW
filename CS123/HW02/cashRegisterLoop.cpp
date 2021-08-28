// =========================================================================
// cashRegisterLoop.cpp
// This program asks how many items you will be purchasing and then using a for loop
// adds the price of each item (type float) and then shows the Subtotal (type float) 
// Tax added to price, and the Total after tax. The user is then asked to either 
// pay a Cash amount greater than the total or to use a Credit Card.
// =========================================================================
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int numberOfItems;
    float costOfItem;
    float salesTax;
    float total = 0;
    float cash;
    char answer;

    while (true){
        printf("Please enter the number of items you will purchase: ");
        if (cin >> numberOfItems){
            break;
        }
        else{
            printf("Incorrect input: Not a number\n");
            cin.clear();
            cin.ignore(42, '\n');
        }
    }

    for (int i = 0; i < numberOfItems; i++) {
        while (true){
            printf("Please enter the cost of item #%i : $", i+1);
            if (cin >> costOfItem){
                break;
            }
            else{
                printf("Incorrect input: Must be a dollar ammount\n");
                cin.clear();
                cin.ignore(42, '\n');
            }
        }
        total += costOfItem;
    }

    cout << endl;
    salesTax = total * 0.0075;
    printf("Subtotal: $%.2f\nTax (7.75%): $%.2f\nTotal: $%.2f\n\n", total, salesTax, total + salesTax);
    total += salesTax;
    printf("Cash or credit? Enter 'C' for Cash or 'T' for Credit: ");

    while (true){ 
        cin >> answer;

        if (toupper(answer) == 'C'){
            while (true){
                printf("Please enter amount of Cash: $");
                cin >> cash;
                if (cash < total){
                    printf("Not enough Cash, Please enter an amount greater than or equal to $%.2f\n", total);
                    cin.clear();
                    cin.ignore(42, '\n');
                }
                else
                    break;
            }
            printf("Change: $%.2f\n", cash - total);
            break;
        }
        else if (toupper(answer) == 'T'){
            printf("Card Payment: $%.2f\n", total);
            break;
        }
        else{
            printf("Incorrect selection: Not 'C' or 'T'\n");
            printf("Cash or credit? Enter 'C' for Cash or 'T' for Credit: ");
            cin.clear();
            cin.ignore(42, '\n');
        }
    }

}