/* 
*  Name : Witsanu Sirichanyaphong
*  ID : 6181099
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char* new_array(char* str[]){
    
}


char* tab_to_space(char* str[] ,int numspace){
    int i = 0;
    int tab_count = 0;
    while(str[i] != '\0'){
        if(str[i] == '\t'){tab_count++;}
        i++;
    }

    char* temp = malloc(sizeof(strlen(str) + (tab_count * numspace-1) ));
    
}

// char* space_to_tab(char* str[] ,int numspace){
    
// }



int main(int argc, char* argv[]) {

    int num_space = atoi(argv[2]);
    char *str = malloc(500*sizeof(char));
    gets(str);

    printf("%s", str);
    // if(argv[1] == "-d"){
    //     tab_to_space(,num_space)
    // }
    // if(argv[1] == "-e"){
    //     space_to_tab(,num_space)
    // }
    
    return 0;
}