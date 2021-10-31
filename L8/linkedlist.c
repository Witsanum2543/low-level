#include<stdio.h>
#include<stdlib.h>

struct node_name{
    int my_data;
    struct node_name *next;
};
// now we will call struct node_name as a Node
typedef struct node_name Node;

Node *front; // global variable

// Delete the first element of my data
void delete(int data){
    Node *temp;
    Node *previous;
    if(front == NULL) {return;}
    else{
        for(temp=front; temp->my_data!=data && temp->next!=NULL; temp=temp->next){
            // this will stop before go into node.my_data = data
            previous = temp;
        }
        if(temp->my_data == data){
            // [Previous Node] -> [Temp == data] -> [The node after Temp]
            // want [Previous Node]->next == temp->next
            // It will look like this [Previous Node] -> [The node after Temp]
            previous->next = temp->next;
            free(temp);
            
        }
    }
}

// insert a new node at the end
void insert(int data){
    // temp will be set as a front later
    Node *temp;
    // temp2 is act like a hold node to assign to temp later
    Node *temp2;
    if(front == NULL) 
    {
        temp = malloc(sizeof(Node));
        temp->my_data = data; 
        temp->next = NULL;
        front = temp;
        return;
    }
    // temp -> next = *temp.next 
    for(temp=front; temp->next!=NULL; temp=temp->next){
        // no code needed in here, once we are at NULL it mean we are at end of linked list
    } 
    temp2 = malloc(sizeof(Node));
    temp2->my_data = data; 
    temp2->next = NULL;
    temp->next = temp2;
}

// // print the linked list
// void print(){
//     Node *temp;
//     printf("{");
//     for(temp = front; temp!=NULL; temp = temp->next){
//         printf("%d, ", temp->my_data);
//     } 
//     printf("}\n");
// }

void print(){
    Node *temp=front;
    int min = temp->my_data;
    int size = 0;
    // to find size of linked list first
    for(temp; temp!=NULL; temp=temp->next){
        size++;
        if(temp->my_data < min) {min = temp->my_data;}
    }
    // make array and put all number in array;
    int *arr = malloc(sizeof(int) * size);
    temp=front;
    int i=0;
    for(temp; temp!=NULL; temp=temp->next){
        arr[i] = temp->my_data;
        i++;
    }
    // sorting the array (bubble sort)
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // print a sorting linked list without changed origin
    printf("{");
    for(int i=0; i<size-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d", arr[size-1]);
    printf("}\n");
    free(arr);
}

void insertAt(int data, int index){
    Node *temp;
    Node *temp2;
    Node *previous;
    if(index == 0) 
    {
        temp = malloc(sizeof(Node));
        temp->my_data = data; 
        temp->next = front;
        front = temp;
        return;
    }
    for(temp=front; index > 0 && temp->next!=NULL; temp=temp->next){
        index--;
        previous = temp;
    } 
    temp2 = malloc(sizeof(Node));
    temp2->my_data = data; 
    temp2->next = temp;
    previous->next = temp2;
}

int main()
{
    front = NULL;
    // {3, 1, 2, 5, 4}
    // {1, 2, 3, 4, 5}
    insert(3);
    insert(1);
    insert(2);
    insert(5);
    insert(4);
    insertAt(25,1);
    print();
}