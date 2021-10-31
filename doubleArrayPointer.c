#include<stdio.h>
#include<stdlib.h>

int main(){
    int** arr = malloc(sizeof(int*) * 3);
    for(int i=0; i<3; i++){
        arr[i] = malloc(sizeof(int)*3);
    }

    arr[0][0] = 10; arr[0][1] = 20; arr[0][2] = 30;
    arr[1][0] = 100; arr[1][1] = 200; arr[1][2] = 300;
    arr[2][0] = 1000; arr[2][1] = 2000; arr[2][2] = 3000;

    // each pointer take 8 bytes of memory
    printf("%d\n", arr); // address of first pointer
    printf("%d\n", arr+1); // address of second pointer
    printf("%d\n", arr+2); // address of third pointer
    printf("-------------\n");
    printf("%d\n", *arr); // address of first array
    printf("%d\n", *(arr+1)); // address of second array
    printf("%d\n", *(arr+2));  // address of third array
    printf("-------------\n");
    printf("%d\n", *(*(arr+2)) );  // first element of third array
    printf("%d\n", *(*(arr+2)+1)); // second element of third array
    printf("%d\n", *(*(arr+2)+2)); // third element of third array
    printf("-------------\n");
    printf("%d\n", *((*arr)+1) ); // second element of first array
}   