#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char buf[1000];
    printf("Write input text: ");
    fgets(buf, 1000, stdin);
    printf("%s\n", buf);

    exit(EXIT_SUCCESS);
}