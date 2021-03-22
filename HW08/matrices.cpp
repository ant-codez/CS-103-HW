// ============================================================================
// file: matrices.cpp
// ============================================================================
// Programmer: Anthony Chavez
// Date: 03/15/2021
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time: 
// Instructor: Dr. Rodriguez
// Project: Matrices
//
// Description:
// 
// ============================================================================
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
using namespace std;


// Function Prototypes
void    InitMatrix(int[][3]);
void    DispMatrix(int[][3]);
void    AddMatrix(int[][3], int[][3]);
void    TMatrix(int[][3]);
int     DetMatrix(int[][3]);


// ==== main ==================================================================
//
// ============================================================================

int main(){
    int matrix1[3][3], matrix2[3][3];

    printf("Please enter 9 integer values for the first matrix:\n");
    InitMatrix(matrix1);
    cout << endl;
    printf("Please enter 9 integer values for the second matrix:\n");
    InitMatrix(matrix2);
    printf("\n  The matricies you've entered are:\n");
    DispMatrix(matrix1);
    cout << endl;
    DispMatrix(matrix2);
    printf("\n  The sum of the matrices are:\n");
    AddMatrix(matrix1, matrix2);
    printf("\n  The transpose of the matrices are:\n");
    TMatrix(matrix1);
    cout << endl;
    TMatrix(matrix2);
    printf("\nThe determinant of the matrices are: %i and %i", DetMatrix(matrix1), DetMatrix(matrix2));
    

    return (0);
}

void InitMatrix(int matrix1[][3]){
    for (int x = 0; x <= 2; x++){
        for (int y = 0; y <= 2; y++){
            printf("[%d][%d]: ", x, y);
            cin >> matrix1[x][y];
        }
    }

}

void DispMatrix(int matrix1[][3]){
    for (int x = 0; x <= 2; x++){
        for (int y = 0; y <= 2; y++){
            printf("\t%i", matrix1[x][y]);
        }
        cout << endl;
    }
}

void AddMatrix(int matrix1[][3], int matrix2[][3]){
    int tempMatrix[3][3];

    for (int x = 0; x <= 2; x++){
        for (int y = 0; y <= 2; y++){
            tempMatrix[x][y] = matrix1[x][y] + matrix2[x][y];
        }
    }

    DispMatrix(tempMatrix);
}

void TMatrix(int matrix[][3]){
    int transpose[3][3];

    for (int x = 0; x <= 2; x++){
        for (int y = 0; y <= 2; y++){
            transpose[x][y] = matrix[y][x];
        }
    }

    DispMatrix(transpose);
}

int DetMatrix(int m[][3]){
    int a = m[0][0], b = m[0][1], c = m[0][2];
    int d = m[1][0], e = m[1][1], f = m[1][2];
    int g = m[2][0], h = m[2][1], i = m[2][2];

    return (a*(e*i - f*h) - (b*(d*i - f*g)) + (c*(d*h - e*g)));
}