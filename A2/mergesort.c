/* 
*  Name : Witsanu Sirichanyaphong
*  ID : 6181099
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME_LENGTH 30;

typedef struct EntryStruct {
    int data;
    char *name;
} Entry;

void merge(Entry *output, Entry *L, int nl, Entry *R, int nR){
    int i = 0, j = 0 , k = 0;
    while(i < nl && j < nR){
        if (L[i].data <= R[j].data){
            output[k].data = L[i].data;
            output[k].name = L[i].name;
            i++;
        } else {
            output[k].data = R[j].data;
            output[k].name = R[j].name;
            j++;
        }
        k++;
    }
    while(i < nl){
        output[k].data = L[i].data;
        output[k].name = L[i].name;
        i++;
        k++;
    }
    while(j < nR){
        output[k].data = R[j].data;
        output[k].name = R[j].name;
        j++;
        k++;
    }

}

void merge_sort(Entry *entries, int n){
    if(n==1){
        return;
    } else {
        int mid = n/2;
        Entry *left = malloc(sizeof(Entry) * mid);
        Entry *right = malloc(sizeof(Entry) * (n-mid));
        for(int i=0; i<mid; i++){
            left[i].data = entries[i].data;
            left[i].name = entries[i].name;
        }
        for(int i=mid; i<n; i++){
            right[i-mid].data = entries[i].data;
            right[i-mid].name = entries[i].name;
        }
        Entry *temp = malloc(sizeof(Entry) * n);
        merge_sort(left, mid);
        merge_sort(right, n-mid);
        merge(temp, left, mid, right, n-mid);
        for(int i=0; i<n; i++){
            entries[i].data = temp[i].data;
            entries[i].name = temp[i].name;
        }
        free(temp);
    }
}

int main(){
    Entry *new = malloc(sizeof(Entry) * 4);
    new[0].data = 4; new[0].name = "aa";
    new[1].data = 7; new[1].name = "bb";
    new[2].data = 2; new[2].name = "cc";
    new[3].data = 1; new[3].name = "dd";

    merge_sort(new, 4);
    for(int i=0; i<4; i++){
        printf("data = %d Char = %s\n", new[i].data, new[i].name);
    }
}