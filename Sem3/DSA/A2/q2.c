#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular linked list with n nodes
Node* createCircularList(int n) {
    if (n <= 0) return NULL;

    Node* head = createNode(1);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    current->next = head; // Make it circular
    return head;
}

// Function to solve the Josephus problem
int josephus(Node** head, int k) {
    if (*head == NULL || k <= 0) return -1;

    Node* current = *head;
    Node* prev = NULL;

    // Find the last node to adjust circular link
    while (current->next != *head) {
        current = current->next;
    }

    // Set the last node as the end of the list
    prev = current;
    current = *head;

    // Eliminate nodes until one node is left
    while (prev != current) {
        // Count k-1 nodes
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }

        // Remove the k-th node
        prev->next = current->next;
        free(current);

        // Move to the next node
        current = prev->next;
    }

    int lastPerson = current->data;
    free(current); // Free the last remaining node
    *head = NULL;  // Clear the list

    return lastPerson;
}

// Function to print the circular linked list
void printCircularList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function to test the Josephus problem
int main() {
    int n, k;

    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    Node* head = createCircularList(n);
   
    printf("Circular linked list before elimination: ");
    printCircularList(head);

    int lastPerson = josephus(&head, k);

    printf("The last remaining person is: %d\n", lastPerson);

    return 0;
}
