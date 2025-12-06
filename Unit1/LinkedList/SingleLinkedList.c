#include <stdio.h>   // Provides printf(), scanf() and basic input/output functions
#include <stdlib.h>  // Provides malloc(), free() for dynamic memory allocation

/*
    👉 What this program does:
       1. Defines a Node structure (data + next pointer)
       2. Creates a global head pointer (starting point of the linked list)
       3. Dynamically allocates a new node using malloc
       4. Stores data inside the node
       5. Connects the node to head → forming a 1-node linked list
*/

// Step 1: Define the structure for a Linked List node
struct Node {
    int data;            // Stores the integer value of the node
    struct Node* next;   // Stores the address of the next node (NULL if no next node)
};

// Step 2: Create a global head pointer
// Initially there is no linked list, so head = NULL
struct Node* head = NULL;

int main() {
    /*
        Step 3: Create a new node dynamically

        malloc() allocates memory in the heap.
        sizeof(struct Node) calculates how much memory a Node needs.

        We cast malloc to (struct Node*) because malloc returns a void* (generic pointer).
    */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Always check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed! Could not create node.\n");
        return 1; // Non-zero return indicates an error
    }

    /*
        Step 4: Assign a value to the new node.

        "->" is used because newNode is a pointer.
        newNode->data means “store data inside the node that newNode points to”.
    */
    newNode->data = 5;

    /*
        Step 5: Set the next pointer to NULL.

        Since this is the only node we are creating right now,
        there is no next node. So next = NULL makes it the last node.
    */
    newNode->next = NULL;

    /*
        Step 6: Connect the new node to the head pointer.

        Before this, head = NULL (list was empty).
        After this assignment:
            head → [ data = 5 | next = NULL ]

        This officially creates a Linked List with ONE element.
    */
    head = newNode;

    /*
        Step 7: Print to verify that the node was created successfully.
    */
    printf("Node created successfully!\n");
    printf("Head points to a node with data: %d\n", head->data);

    /*
        Summary:
        - We created a single-node linked list.
        - Next steps (in future programs):
            * Insert at beginning
            * Insert at end
            * Insert at any position
            * Delete nodes
            * Print the entire list
    */

    return 0; // Program executed successfully
}