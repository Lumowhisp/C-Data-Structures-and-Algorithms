// ------------------------------  
// STACK IMPLEMENTATION USING ARRAY  
// This program shows how a basic stack works (Push, Pop, Print)  
// Beginner-friendly with clear steps for revision  
// ------------------------------  
// MAX size of the stack
#define MAX 5
#include <stdio.h>

// 'top' stores the index of the top element in stack  
// -1 means stack is empty  
int top=-1;
// Array to store stack elements  
int arr[5];
// ------------------------------  
// PUSH OPERATION  
// Adds a new value to the top of the stack  
// ------------------------------
void push(int val){
    // If top reaches MAX-1, no more space → Overflow
    if(top==MAX-1){
        printf("Overflow");
        return;
    }
    // Move top to next empty position
    top++;
    // Store the new value at the new top
    arr[top]=val;
 
}
// ------------------------------  
// POP OPERATION  
// Removes the top element from the stack  
// ------------------------------
void pop(){
    // If top is -1 → stack is empty
    if(top==-1){
        printf("UnderFlow");
        return ;
    }
    // Simply decrease top to remove the last element
    top--;
}
// ------------------------------  
// PRINT STACK  
// Displays all elements from bottom to top  
// ------------------------------
void print(){
    // Loop runs from index 0 to top
    for(int i=0;i<=top;i++){
        printf("%d ",arr[i]);
    }
}
// ------------------------------  
// MAIN FUNCTION  
// Testing stack operations  
// ------------------------------
int main(){
    // Push two values into the stack
    push(5);
    push(10);
    // Display current stack state
    print();   // Output: 5 10
}