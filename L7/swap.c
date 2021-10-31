#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp; 
}

int main()
{
    int a=5;
    int b=10;
    printf("before swapping a= %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("after swapping a= %d, b = %d\n", a, b);
    return 0;
}