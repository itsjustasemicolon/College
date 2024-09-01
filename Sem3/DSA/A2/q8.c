#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the circular queue

// Circular Queue implementation using an array
typedef struct {
    int front, rear, size;
    int data[MAX];
} CircularQueue;

// Initialize the circular queue
void initCircularQueue(CircularQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Check if the circular queue is full
int isFullCircularQueue(CircularQueue* q) {
    return q->size == MAX;
}

// Check if the circular queue is empty
int isEmptyCircularQueue(CircularQueue* q) {
    return q->size == 0;
}

// Add an element to the rear of the circular queue
void enqueueCircular(CircularQueue* q, int value) {
    if (isFullCircularQueue(q)) {
        printf("Circular Queue Overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->size++;
}

// Remove and return an element from the front of the circular queue
int dequeueCircular(CircularQueue* q) {
    if (isEmptyCircularQueue(q)) {
        printf("Circular Queue Underflow\n");
        return -1; // Error value
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return value;
}

// Display the current menu for circular queue operations
void circularQueueMenu() {
    CircularQueue q;
    initCircularQueue(&q);
    int choice, value;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Overflow/Underflow\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueueCircular(&q, value);
                break;
            case 2:
                value = dequeueCircular(&q);
                if (value != -1) printf("Dequeued: %d\n", value);
                break;
            case 3:
                printf("Size: %d\n", q.size);
                break;
            case 4:
                printf("Overflow: %s\n", isFullCircularQueue(&q) ? "Yes" : "No");
                printf("Underflow: %s\n", isEmptyCircularQueue(&q) ? "Yes" : "No");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
}

// Main function to drive the menu
int main() {
    circularQueueMenu();
    return 0;
}

