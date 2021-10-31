#include<stdio.h>

void prefix_sum(int *a, int *b, int *c)
{
    *b += *a;
    *c += *a + *b;
}

void main()
{
    int a = 5;
    int b = 12;
    int c = 15;
    prefix_sum(&a, &b, &c);
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
}