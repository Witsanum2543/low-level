#include<stdio.h>
#include<stdlib.h>

int isPrime(int n){
    if (n == 2 || n == 3) {return 1;}
    if (n % 2 != 0 && n % 3 != 0) {return 1;}
    return 0;
}

int main(){
    printf("%d\n", isPrime(2));
    printf("%d\n", isPrime(3));
    printf("%d\n", isPrime(5));
    printf("%d\n", isPrime(7));
    printf("%d\n", isPrime(11));
    printf("%d\n", isPrime(13));
    printf("%d", isPrime(17));
    return 0;
}