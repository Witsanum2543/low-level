/* 
*  Name : Witsanu Sirichanyaphong
*  ID : 6181099
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void printmatrix(int **matrix, int sizex, int sizey){
    for(int row=0; row<sizex; row++){
        for(int col=0; col<sizey; col++){
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

int** createSquareMatrix(int size){
    int** new_arr = malloc(sizeof(int*) * size);
    for(int i=0; i<size; i++){
        new_arr[i] = malloc(sizeof(int) * size);
    }
    return new_arr;
}

int** smaller_matrix(int **arr, int oldsize, int row, int col){
    int** new_arr = createSquareMatrix(oldsize-1);
    
    int row_newarr = 0;
    for(int i=0; i<oldsize; i++){
        if(i == row){ continue;}

        int col_newarr = 0;
        for(int j=0; j<oldsize; j++){
            if(j == col){continue;}

            new_arr[row_newarr][col_newarr] = arr[i][j];
            col_newarr++;
        }
        row_newarr++;
    }
    return new_arr;
}

double compute_det(int **arr, int size){
    if(size==1){return arr[0][0];}
    if(size==2){
        double det = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
        return det;
    } else {
        double det = 0.0;
        for(int col=0; col<size; col++){
            det += arr[0][col] * pow(-1,1+(col+1)) * compute_det(smaller_matrix(arr, size, 0, col), size-1);
        }
        return det;
    }
}

int main(){
    int** arr = createSquareMatrix(3);
    arr[0][0] = 5; arr[0][1] = 3; arr[0][2] = 7;
    arr[1][0] = 2; arr[1][1] = -5; arr[1][2] = 8;
    arr[2][0] = -6; arr[2][1] = 4; arr[2][2] = 9;
    
    // [5 , 3 , 7]  
    // [2 , -5 , 8]   
    // [-6 , 4 , 9]     =  -737

    int** arr2 = createSquareMatrix(4);
    arr2[0][0] = 1; arr2[0][1] = 0; arr2[0][2] = 4; arr2[0][3] = -6;
    arr2[1][0] = 2; arr2[1][1] = 5; arr2[1][2] = 0; arr2[1][3] = 3;
    arr2[2][0] = -1; arr2[2][1] = 2; arr2[2][2] = 3; arr2[2][3] = 5;
    arr2[3][0] = 2; arr2[3][1] = 1; arr2[3][2] = -2; arr2[3][3] = 3;


    // [1 , 0 , 4, -6]  
    // [2 , 5 , 0, 3]   
    // [-1 , 2 , 3, 5]    
    // [2, 1 , -2, 3]    =  318

    int** arr3 = createSquareMatrix(4);
    arr3[0][0] = 1; arr3[0][1] = 2; arr3[0][2] = 3; arr3[0][3] = 4;
    arr3[1][0] = 5; arr3[1][1] = 2; arr3[1][2] = 3; arr3[1][3] = 1;
    arr3[2][0] = 2; arr3[2][1] = 5; arr3[2][2] = 0; arr3[2][3] = 1;
    arr3[3][0] = 3; arr3[3][1] = 2; arr3[3][2] = 4; arr3[3][3] = 2;


    printf("%f\n", compute_det(arr, 3));
    printf("%f\n", compute_det(arr2, 4));
    printf("%f", compute_det(arr3, 4));
    
}