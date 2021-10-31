#include<stdio.h>
#include<stdlib.h>

int comparator(const int *a, const int *b){
    if ( *a < *b ) return -1;
    else if ( *a == *b) return 0;
    else return 1;
}

int main()
{
    int *(func_ptr) (const int *, const int *) = &comparator;
    int a[10] = {1,3,2,8,5,32,6,23,1,20};
    int i;

    qsort(a, 10, sizeof(int), *func_ptr);

    for(i=0; i<10; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}