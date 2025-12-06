#include <stdio.h>
#include <stdlib.h>

/* ⭐ Node Structure
   A Node stores:
   1. data → integer value
   2. next → pointer to the next node in the linked list
*/
struct Node {
    int data;
    struct Node* next;
};

/* ⭐ Head Pointer
   This always points to the FIRST node of the linked list.
   If head = NULL → list is empty.
*/
struct Node* head = NULL;


/* ----------------------------------------------------------
   🔵 insertAtBegin()
   Inserts a new node at the START of the linked list.

   Steps:
   1. Allocate memory for a new node.
   2. Take input from the user.
   3. Set newNode->next to current head.
   4. Move head to point to the new node.
---------------------------------------------------------- */
void insertAtBegin() {
    int element;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Element to Insert at Beginning: ");
    scanf("%d", &element);

    newNode->data = element;
    newNode->next = head;   // Connect new node to the current list
    head = newNode;         // Update head to the new node
}


/* ----------------------------------------------------------
   🔵 insertAtEnd()
   Inserts a new node at the END of the linked list.

   Steps:
   1. Create a new node.
   2. If list is empty → head = newNode.
   3. If list has only 1 node → attach after head.
   4. Otherwise traverse to the last node and attach newNode.
---------------------------------------------------------- */
void insertAtEnd() {
    int element;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Element to Insert at End: ");
    scanf("%d", &element);

    newNode->data = element;
    newNode->next = NULL;

    // CASE 1: Empty list
    if (head == NULL) {
        head = newNode;
        return;
    }

    // CASE 2: Only one node
    if (head->next == NULL) {
        head->next = newNode;
        return;
    }

    // CASE 3: More than one node → find the last node
    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;  // Link last node to new node
}


/* ----------------------------------------------------------
   🔵 insertAtPlace()
   Inserts a node at a user-given INDEX (0-based).

   Example:
   index = 0 → Insert at the beginning
   index = 3 → Insert at 4th position

   Logic:
   - Traverse the list until the correct position.
   - Insert the new node between prev and curr.
---------------------------------------------------------- */
void insertAtPlace() {
    int element, index;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Element to Insert: ");
    scanf("%d", &element);
    newNode->data = element;
    newNode->next = NULL;

    printf("Enter Index (Position): ");
    scanf("%d", &index);

    // CASE 1: Insert at beginning
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    // Traverse until required index
    while (curr != NULL && index > 0) {
        prev = curr;
        curr = curr->next;
        index--;
    }

    // If index still > 0 → invalid
    if (index > 0) {
        printf("Invalid Position!\n");
        free(newNode);
        return;
    }

    // Insert node between prev and curr
    prev->next = newNode;
    newNode->next = curr;
}


/* ----------------------------------------------------------
   🔵 DeletionAtBegin()
   Deletes the FIRST node of the linked list.

   Steps:
   1. If list empty → cannot delete.
   2. Store head in temp.
   3. Move head to next node.
   4. free(temp) to delete memory.
---------------------------------------------------------- */
void DeletionAtBegin() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;  // Move head to the next node
    free(temp);         // Delete old head

    printf("Node Deleted from Beginning\n");
}


/* ----------------------------------------------------------
   🔵 DeleteAtEnd()
   Deletes the LAST node of the linked list.

   Logic:
   - If 0 nodes → cannot delete
   - If 1 node → delete head
   - Otherwise traverse until second-last node
---------------------------------------------------------- */
void DeleteAtEnd() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    // CASE 1: Only one node
    if (head->next == NULL) {
        struct Node* temp = head;
        head = NULL;
        free(temp);
        return;
    }

    // CASE 2: More than one node
    struct Node* curr = head;
    struct Node* prev = NULL;

    // Reach the last node
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;  // Remove last node
    free(curr);         // Delete last node
}


/* ----------------------------------------------------------
   🔵 DeleteAtPlace()
   Deletes a node at a specific index.

   Logic:
   - If index = 0 → delete head
   - Traverse list until index
   - Update prev->next to skip curr
   - Delete curr
---------------------------------------------------------- */
void DeleteAtPlace() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    int index;
    printf("Enter Index to be Deleted: ");
    scanf("%d", &index);

    // CASE 1: Delete first node
    if (index == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr != NULL && index > 0) {
        prev = curr;
        curr = curr->next;
        index--;
    }

    // If curr becomes NULL → index out of range
    if (curr == NULL) {
        printf("Invalid Position\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}


/* ----------------------------------------------------------
   🌟 MAIN FUNCTION
   Runs sample operations for demonstration.
---------------------------------------------------------- */
int main() {
    printf("---- Linked List Insertion & Deletion Demo ----\n");

    insertAtBegin();
    insertAtEnd();
    insertAtPlace();
    DeletionAtBegin();
    DeleteAtEnd();
    DeleteAtPlace();

    return 0;
}
