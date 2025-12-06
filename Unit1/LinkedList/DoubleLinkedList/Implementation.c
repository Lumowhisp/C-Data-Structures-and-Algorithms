#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head=NULL;

void insertAtBegin(){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Element:");
    int element;
    scanf("%d",&element);
    newNode->data=element;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}
void insertAtEnd(){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Element:");
    int element;
    scanf("%d",&element);
    newNode->data=element;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    struct Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    newNode->prev=curr;
    curr->next=newNode;
}
void insertAtPlace(){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Element:");
    int element;
    scanf("%d",&element);
    printf("Enter Index:");
    int index;
    scanf("%d",&index);
    newNode->data=element;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    if (index == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    struct Node* curr=head;
    while(curr->next!=NULL&&index>1){
        curr=curr->next;
        index--;
    }
    newNode->next=curr->next;
    newNode->prev=curr;
    if(curr->next!=NULL){
        curr->next->prev=newNode;
    }
    curr->next=newNode;

}
void deletedAtStart(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    if(head->next!=NULL){
        head->prev=NULL;
    }
    free(temp);
}
void deleteAtEnd(){
    if(head==NULL){
        printf("List is Empty");
        return;
    }
    if(head->next==NULL){
        struct Node* temp=head;
        head=NULL;
        free(temp);
        return;
    }
    struct Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    struct Node* prev=curr->prev;
    prev->next=NULL;
    free(curr);

}
