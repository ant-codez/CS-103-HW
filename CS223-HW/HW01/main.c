#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char **argv){
    int temp;
    int min = INT_MAX;
    int max = 0;

    printf("Enter some integer values, EOF to quit...\n");

    while (true){
        if (scanf("%i", &temp) != EOF){
            if (temp > max){
                max = temp;
            }
            if (temp < min){
                min = temp;
            }
        }
        else{
            break;
        }
    }
    
    if (max == 0 && min == INT_MAX)
        printf("No integer values were read from stdin.\n");
    else
        printf("\n\nMax Value = %i\nMin Value = %i\n", max, min);    

    return (0);
}