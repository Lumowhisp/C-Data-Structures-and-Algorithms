#include <stdio.h>
#include <stdlib.h>

// 🌟 Defining the structure of a Node
// Every node stores an integer (data) and a pointer to the next node (next)
struct Node {
    int data;
    struct Node* next;
};

// 🌟 Global head pointer — points to the first node of the linked list
struct Node* head = NULL;


/* ----------------------------------------------------------
   🔵 insertAtBegin()
   Purpose → Insert a new node at the *START* of the linked list.
   Steps:
   1. Create new node using malloc()
   2. Ask user for element to insert
   3. Set new node's next = current head
   4. Update head to newNode
---------------------------------------------------------- */
void insertAtBegin() {
    int element;

    // Step 1: Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Step 2: Take user input
    printf("Enter Element to Insert at Beginning: ");
    scanf("%d", &element);

    // Step 3: Fill node data
    newNode->data = element;

    // Step 4: Connect new node to existing list
    newNode->next = head;

    // Step 5: Update head
    head = newNode;
}


/* ----------------------------------------------------------
   🔵 insertAtEnd()
   Purpose → Insert a new node at the *END* of the linked list.
   Steps:
   1. Create new node
   2. Take input
   3. If list empty → new node becomes head
   4. If only 1 node → attach after head
   5. If multiple nodes → reach last node and insert
---------------------------------------------------------- */
void insertAtEnd() {
    int element;

    // Step 1: Create Node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Step 2: Input
    printf("Enter Element to Insert at End: ");
    scanf("%d", &element);

    newNode->data = element;
    newNode->next = NULL;

    // Step 3: If list empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Step 4: If only one node
    if (head->next == NULL) {
        head->next = newNode;
        return;
    }

    // Step 5: More than one node → reach last node
    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    // Attach new node at last
    curr->next = newNode;
}


/* ----------------------------------------------------------
   🔵 insertAtPlace()
   Purpose → Insert node at *specific index* (0-based)
   Example:
   index = 0 → Insert at beginning
   index = 3 → Insert at 4th position
---------------------------------------------------------- */
void insertAtPlace() {
    int element, index;

    // Step 1: Create Node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Element to Insert: ");
    scanf("%d", &element);
    newNode->data = element;
    newNode->next = NULL;

    printf("Enter Index (Position): ");
    scanf("%d", &index);

    // Step 2: Inserting at beginning
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Step 3: Traverse until index
    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr != NULL && index > 0) {
        prev = curr;
        curr = curr->next;
        index--;
    }

    // If index out of range
    if (index > 0) {
        printf("Invalid Position!\n");
        free(newNode);
        return;
    }

    // Step 4: Insert node between prev and curr
    prev->next = newNode;
    newNode->next = curr;
}


/* ----------------------------------------------------------
   🌟 MAIN FUNCTION
   Calls all insertion functions so user can test them
---------------------------------------------------------- */
int main() {
    printf("---- Linked List Insertion Demo ----\n");

    insertAtBegin();
    insertAtEnd();
    insertAtPlace();

    return 0;
}
