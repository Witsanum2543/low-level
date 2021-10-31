/* 
*  Name : Witsanu Sirichanyaphong
*  ID : 6181099
*/
#include<stdio.h>
#include<stdlib.h>

struct node_name{
    int data;
    struct node_name *next;
};
typedef struct node_name Node;

Node* front;

void insert(int num){
    if (front == NULL){
        front = malloc(sizeof(Node));
        front->data = num;
        front->next = NULL;
        return;
    }
    Node* temp;
    Node* temp2 = malloc(sizeof(Node));
    Node* previous = NULL;
    for(temp = front; temp->data <= num && temp->next!=NULL; temp=temp->next){
        // stop at node that greater or equal to num
        previous = temp;
    }
    if(temp->data >= num){
        temp2->data = num;
        temp2->next = temp;
        // for insert(2) then insert(1) 
        if (previous == NULL){
             front = temp2;
             return;
        }
        previous->next = temp2;
        return;
    }
    temp2->data = num;
    temp2->next = NULL;
    temp->next = temp2;
}

int delete(int num){
    Node* temp;
    Node* previous = NULL;
    if(front == NULL) {return 0;}
    for(temp=front; temp->data!=num && temp->next!=NULL; temp=temp->next){
        previous = temp;
    }
    if(temp->data == num){
        if(previous == NULL){
            front = temp->next;
            return 1;
        }
        previous->next = temp->next;
        free(temp);
        return 1;
    }
    return 0;
}

void print(){
    Node* temp;
    printf("{");
    for(temp=front; temp->next!=NULL; temp=temp->next){
        printf("%d, ", temp->data);
    }
    printf("%d", temp->data);
    printf("}\n");
}

int search(int num){
    Node* temp;
    for(temp=front; temp!=NULL; temp=temp->next){
        if(temp->data == num){
            printf("Found %d", num);
            return 1;
        }
    }
    printf("Cannot Find %d", num);
    return 0;
}

int main(){
    front = NULL;
    insert(2);
    insert(1);
    insert(4);
    insert(3);
    insert(11);
    insert(12);
    print();
    delete(12);
    print();
}