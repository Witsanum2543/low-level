#include<stdio.h>
#include<stdlib.h>

void dotProduct(int *a, int *b, int* result, int size){
    int temp = 0;
    for(int i=0; i<size; i++){
        temp += a[i] * b[i];
    }   
    *result = temp;
}


int main(){ 
    int *a = malloc(sizeof(int) * 3);
    a[0] = 2; a[1] = 3; a[2] = 1;
    int *b = malloc(sizeof(int) * 3);
    b[0] = 1; b[1] = 4; b[2] = 3;
    int *result;
    dotProduct(a, b, result, 3);
    printf("%d", *result);
}