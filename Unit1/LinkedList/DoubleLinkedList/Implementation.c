#include <stdio.h>
#include <stdlib.h>

/*
    🌟 STRUCTURE OF A DOUBLY LINKED LIST NODE
    Each node stores:
    - data  → integer value
    - next  → pointer to next node
    - prev  → pointer to previous node
*/
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

/*
    🌟 HEAD POINTER
    Always points to the FIRST node of the list.
    If list is empty → head = NULL
*/
struct Node* head = NULL;


/* ===========================================================
   ✅ INSERT AT BEGINNING
   Steps:
   1. Create new node
   2. Set its data
   3. If list empty → head = newNode
   4. Otherwise adjust pointers:
      newNode → next = old head
      old head → prev = newNode
      head = newNode
=========================================================== */
void insertAtBegin() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Element: ");
    int element;
    scanf("%d", &element);

    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Case 1: List is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Case 2: Insert before head
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}


/* ===========================================================
   ✅ INSERT AT END
   Steps:
   1. Create new node
   2. If list empty → head = newNode
   3. Else traverse to last node
   4. Attach new node at end
=========================================================== */
void insertAtEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Element: ");
    int element;
    scanf("%d", &element);

    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Case 1: Empty list
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Case 2: Traverse to last node
    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    // Attach at end
    newNode->prev = curr;
    curr->next = newNode;
}


/* ===========================================================
   ✅ INSERT AT GIVEN INDEX (0‑based)
   Steps:
   1. Create new node
   2. If index = 0 → insert at beginning
   3. Traverse until one node before target index
   4. Adjust pointers and insert
=========================================================== */
void insertAtPlace() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Element: ");
    int element;
    scanf("%d", &element);

    printf("Enter Index: ");
    int index;
    scanf("%d", &index);

    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Case 1: Empty list
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Case 2: Insert at beginning
    if (index == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Case 3: Traverse to (index - 1)
    struct Node* curr = head;
    while (curr->next != NULL && index > 1) {
        curr = curr->next;
        index--;
    }

    // Insert between curr and curr->next
    newNode->next = curr->next;
    newNode->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = newNode;
    }

    curr->next = newNode;
}


/* ===========================================================
   ✅ DELETE AT BEGINNING
   Steps:
   1. If list empty → return
   2. Move head to next node
   3. Free old head
=========================================================== */
void deletedAtStart() {
    if (head == NULL) {
        printf("List is empty");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    // If list still has nodes
    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}


/* ===========================================================
   ✅ DELETE AT END
   Steps:
   1. If empty → return
   2. If only 1 node → delete head
   3. Traverse to last node
   4. Remove it
=========================================================== */
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is Empty");
        return;
    }

    // Case 1: Only one node
    if (head->next == NULL) {
        struct Node* temp = head;
        head = NULL;
        free(temp);
        return;
    }

    // Case 2: Traverse to last node
    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    struct Node* prev = curr->prev;
    prev->next = NULL;
    free(curr);
}
