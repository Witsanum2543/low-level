#include<stdio.h>
#include<stdlib.h>
#define DEBUG 0

void printMatrix(int **a, int sizex, int sizey)
{
    for(int i=0; i<sizex; i++)
    {
        for(int j=0; j<sizey; j++)
        {
            printf("%3d, ", *(*(a+i) + j));
        }
        print("\n");
    }
}

int matrixAdd(int **a, int **b, int **result, int sizex, int sizey)
{
    int i,j;
    for(i=0; i<sizex; i++)
    {
        for(j=0; j<sizey; j++)
        {
            *(*(result + i) + j) = *(*(a+i) +j) + *(*(b+i) +j);
        }
    }
}

int main()
{
    int **a;
    int **b;
    int **c;
    a = malloc(sizeof(int*)*5);
    b = malloc(sizeof(int*)*5);
    c = malloc(sizeof(int*)*5);
    for(int i=0; i<5; i++)
    {
        *(a+i) = a = malloc(sizeof(int)*5);
        *(b+i) = a = malloc(sizeof(int)*5);
        *(c+i) = a = malloc(sizeof(int)*5);
        for(int i=0; i<5; i++)
        {

        }
    }

    print("A: \n");
    printMatrix(a, 5, 5);

    print("B: \n");
    printMatrix(b, 5, 5);

    print("C: \n");
    printMatrix(c, 5, 5);

    // free memory
    for(int i=0; i<5; i++)
    {
        free(*(a+i));
        free(*(b+i));
        free(*(c+i));
    }
    free(a); free(b); free(c);
}