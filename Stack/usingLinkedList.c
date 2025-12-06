#include <stdio.h>
#include <stdlib.h>

// ⭐ Node structure for Linked List (used as Stack)
// Each node stores an integer value and a pointer to the next node
struct Node{
    int data;
    struct Node* next;
};

// ⭐ 'head' will work as TOP of the Stack
// Initially stack is empty → head = NULL
struct Node* head=NULL;

// ----------------------------------------------------
// 🔼 PUSH Operation → Insert at the beginning (TOP)
// This simulates stack behavior using a linked list
// ----------------------------------------------------
void push(int val){
    // Step 1: Create a new node and assign the value
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    
    // Step 2: If stack is empty → new node becomes TOP
    if(head==NULL){
        head=newNode;
        return;
    }
    // Step 3: Otherwise link new node to current TOP
    newNode->next=head;
    // Step 4: Update TOP to new node
    head=newNode;
}

// ----------------------------------------------------
// 🔽 POP Operation → Remove element from the TOP
// ----------------------------------------------------
void pop(){
    // Step 1: If stack is empty → Underflow
    if(head==NULL){
        printf("List is Empty(UnderFlow)");
        return;
    }
    // Step 2: Store current TOP in temp
    struct Node* temp=head;
    // Step 3: Move TOP to next node
    head=head->next;
    // Step 4: Delete old TOP to free memory
    free(temp);
}