#include<stdio.h>
#include<stdlib.h>

void printmatrix(int **matrix, int sizex, int sizey){
    for(int row=0; row<sizex; row++){
        for(int col=0; col<sizey; col++){
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

void transpose(int **a, int **b, int sizex, int sizey){
    for(int row=0; row<sizex; row++){
        for(int col=0; col<sizey; col++){
            b[col][row] = a[row][col];
        }
    }
}

int main(){
    int** arr = malloc(sizeof(int*) * 2);
    for(int i=0; i<3; i++){
        arr[i] = malloc(sizeof(int)*3);
    }
    arr[0][0] = 4; arr[0][1] = 8; arr[0][2] = 7;
    arr[1][0] = 1; arr[1][1] = 2; arr[1][2] = 3;

    // [4 , 8 , 2]              [4, 1]
    // [1 , 2 , 3]     -->      [8, 2]
    //                          [2, 3]

    int** arr2 = malloc(sizeof(int*) * 3);
    for(int i=0; i<3; i++){
        arr2[i] = malloc(sizeof(int)*2);
    }

    transpose(arr, arr2, 2, 3);
    printmatrix(arr2,3,2);

    return 0;
}