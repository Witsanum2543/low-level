#include<stdio.h>
#include<stdlib.h>

int* Add(int* a, int* b){
    // a and b are pointer to integer ( local to Add function )
    int *c = malloc(sizeof(int));
    *c = *a + *b;
    // return address of pointer c
    // but we should return address of local variable so we use malloc
    // &c = address of c,  c is also a address of c
    return c;
}

int main() {
    int a=2, b=4;
    int* ptr = Add(&a, &b);
    printf("sum = %d\n", *ptr);
    return 0;
}