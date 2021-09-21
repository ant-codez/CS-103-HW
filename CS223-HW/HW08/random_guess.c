#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000

void FillRandArray(int *array, int numElem, int maxVal){
    int r;

    for (int i = 0; i < numElem; i++){
        r = rand() % maxVal;
        array[i] = r;
    }
}

int FindNumMatches(int *array, int numElem, int target){
    int found = 0;

    for (int i = 0; i < numElem; i++){
        if (array[i] == target){
            printf("array[%i] = %i\n", i, array[i]);
            found++;
        }
    }

    return found;
}

int main(void){
    int maxRand, target, guess, check, matches;
    int *array;
    srand(time(NULL));

    array = (int*)malloc(SIZE * sizeof(int));

    printf("What is the maximum random value? ");
    check = scanf("%i", &maxRand);
    if (!check){
        printf("Didn't read an int, bye!\n");
        exit(1);
    }

    printf("What is the target value? ");
    check = scanf("%i", &target);
    if (!check){
        printf("Didn't read an int, bye!\n");
        exit(1);
    }

    printf("How many matches do you think there will be? ");
    check = scanf("%i", &guess);
    if (!check){
        printf("Didn't read an int, bye!\n");
        exit(1);
    }

    FillRandArray(array, SIZE, maxRand);
    matches = FindNumMatches(array, SIZE, target);

    printf("There were %i matches, meaning you were off by %i...\n", matches, matches - guess);

    return (0);
}