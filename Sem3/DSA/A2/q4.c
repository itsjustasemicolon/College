#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Define the structure for a stack node
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* head=NULL;
int noNodes=0;
// Function to push an element onto the stack
void push(int d) {
    Node* newNode =(Node*) malloc(sizeof(Node));
    newNode->data=d;
    newNode->next =head;
    head=newNode;
    noNodes++;
}

// Function to pop an element from the stack
int pop(Node* top) {
    head=head->next;
    top->next=NULL;
    int v=top->data;
    free(top);
    noNodes--;
    return v;
}
// Function to display all elements in the stack
void display(Node* top) {
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}


int main() 
{
    int choice, value;
   
    do {
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                if(noNodes==0)
                printf("Stack is empty. Nothing to pop.\n");
                else
                {
                    value = pop(head);
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                if(noNodes==0)
                printf("Stack is empty. Nothing to peek.\n");
                else
                printf("Top element: %d\n", head->data);
                break;
            case 4:
                if(noNodes==0)
                printf("Stack empty");
                else
                display(head);
                break;
            case 5:
                if (noNodes==0) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
                break;
        }
    } while (true);
   
    // Free remaining nodes in the stack
    while (head != NULL) {
        Node* temp = head;
        head=head->next;
        temp->next=NULL;
        free(temp);
    }
    return 0;
}
