#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Function to solve the Josephus problem
int josephus(Node* prev, int k,int n) {
    Node* current=prev->next;//head
    // Eliminate nodes until one node is left
    while (n>1) 
    {
        int i=1;
        for ( i = 1; i < k; i++) 
        {
            prev = current;
            current = current->next;
        }

        // Remove the k-th node
        prev->next = current->next;
        free(current);
        // Move to the next node
        current = prev->next;
        n--;
    }

    int lastPerson = current->data;
    free(current); // Free the last remaining node
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
    if(n<=0)
    return 0;
    Node* head = (Node*) malloc(sizeof(Node));
    head->data=1;
    head->next=NULL;
    Node *ptr=head;
    int i=2;
    for(i=2;i<=n;i++)
    {
        Node* n = (Node*) malloc(sizeof(Node));
        n->data=i;
        n->next=NULL;
        ptr->next=n;
        ptr=n;
    }
    ptr->next=head;// Make it circular
    printf("Circular linked list before elimination: ");
    printCircularList(head);

    int lastPerson = josephus(ptr, k,n);

    printf("The last remaining person is: %d\n", lastPerson);

    return 0;
}
