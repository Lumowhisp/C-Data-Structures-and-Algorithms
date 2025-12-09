// #using linked list
#include<stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;//initially set to NULL
void push(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    //basically yahan pe huminsertion at start karte hain toh
    if(head==NULL){
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;

}
void pop(){
    if(head==NULL){
        printf("List is Empty");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    free(temp);
}
