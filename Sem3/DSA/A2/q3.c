#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at a specified position
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
   
    // Insert at the head (position 0)
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node* current = *head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to delete a node from a specified position
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = *head;

    // Delete from the head (position 0)
    if (position == 0) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to count the number of nodes in the doubly linked list
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to reverse print the doubly linked list
void reversePrint(Node* head) {
    if (head == NULL) return;

    // Go to the end of the list
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Print in reverse
    while (current != NULL) {
        printf("%d <- ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Function to reverse the doubly linked list
void reverseList(Node** head) {
    Node *temp = NULL;
    Node *current = *head;

    // Swap next and prev for all nodes of the list
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Update the head to the new head
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to test the doubly linked list operations
int main() {
    Node* head = NULL;

    // Insert nodes
    insertAtPosition(&head, 10, 0);
    insertAtPosition(&head, 20, 1);
    insertAtPosition(&head, 30, 2);
    insertAtPosition(&head, 25, 2);
    printf("List after insertions: ");
    printList(head);

    // Count nodes
    printf("Number of nodes: %d\n", countNodes(head));

    // Reverse print the list
    printf("Reverse print of the list: ");
    reversePrint(head);

    // Reverse the doubly linked list
    reverseList(&head);
    printf("List after reversal: ");
    printList(head);

    // Delete nodes
    deleteAtPosition(&head, 1);
    printf("List after deletion at position 1: ");
    printList(head);

    deleteAtPosition(&head, 0);
    printf("List after deletion at position 0: ");
    printList(head);

    return 0;
}