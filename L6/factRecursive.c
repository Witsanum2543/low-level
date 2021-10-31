#include<stdio.h>
int fact(int i){
    if(i==1){
        return 1;
    } else {
        return i * fact(i-1);
    }
}
int main(){
    int a;
    scanf("%d", &a);
    printf("Factorial of %d is %d", a, fact(a));
}