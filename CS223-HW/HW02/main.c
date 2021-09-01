#include <stdio.h>
#include <stdlib.h>

void PrintChars(int num, char c) {
    for (int i = 0; i < num; i++){
        printf("%c", c);
    }
}

void PrintBox(int width, int height, char c) {
    for (int i = 1; i <= height; i++){
        for (int j = 1; j <= width; j++){
            if (i == 1 || i == height || j == 1 || j == width){
                PrintChars(1, c);
            }
            else{
                PrintChars(1, ' ');
            }
        }
        printf("\n");
    }
}

int main(){

    int width, height, check;
    char c;

    printf("Please enter a positive box width: ");
    check = scanf("%i", &width);
    if (check != 1){
        printf("Error reading width...");
        exit(1);
    }
    else if (width < 1 || width > 80){
        printf("Sorry, the width must be between 1 and 80 inclusive...");
        exit(1);
    }

    printf("Please enter a positive box height: ");
    check = scanf("%i", &height);
    if (check != 1){
        printf("Error reading height...");
        exit(1);
    }
    else if (height < 1){
        printf("Sorry, the height must be positive...");
        exit(1);
    }

    printf("Please enter the box character: ");
    check = scanf(" %c", &c);
    if (check != 1){
        printf("Error reading character...");
        exit(1);
    }
    PrintBox(width, height, c);

    return (0);
}

