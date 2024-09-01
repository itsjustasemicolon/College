#include <stdio.h>
#include <stdlib.h>

// Constants and definitions
#define MAX 100

// Queue implementation using an array
typedef struct {
    int front, rear, size;
    int data[MAX];
} ArrayQueue;

void initArrayQueue(ArrayQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isFullArrayQueue(ArrayQueue* q) {
    return q->size == MAX;
}

int isEmptyArrayQueue(ArrayQueue* q) {
    return q->size == 0;
}

void enqueueArray(ArrayQueue* q, int value) {
    if (isFullArrayQueue(q)) {
        printf("Array Queue Overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->size++;
}

int dequeueArray(ArrayQueue* q) {
    if (isEmptyArrayQueue(q)) {
        printf("Array Queue Underflow\n");
        return -1; // Error value
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return value;
}

void arrayQueueMenu() {
    ArrayQueue q;
    initArrayQueue(&q);
    int choice, value;
    do {
        printf("\nArray Queue Menu:\n1. Enqueue\n2. Dequeue\n3. Size\n4. Overflow/Underflow\n5. Back\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueueArray(&q, value);
                break;
            case 2:
                value = dequeueArray(&q);
                if (value != -1) printf("Dequeued: %d\n", value);
                break;
            case 3:
                printf("Size: %d\n", q.size);
                break;
            case 4:
                printf("Overflow: %s\nUnderflow: %s\n", isFullArrayQueue(&q) ? "Yes" : "No", isEmptyArrayQueue(&q) ? "Yes" : "No");
                break;
        }
    } while (choice != 5);
}

// Node structure for linked list queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue implementation using linked list
typedef struct {
    Node* front;
    Node* rear;
    int size;
} LinkedListQueue;

void initLinkedListQueue(LinkedListQueue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

int isEmptyLinkedListQueue(LinkedListQueue* q) {
    return q->size == 0;
}

void enqueueLinkedList(LinkedListQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear) {
        q->rear->next = newNode;
    } else {
        q->front = newNode;
    }
    q->rear = newNode;
    q->size++;
}

int dequeueLinkedList(LinkedListQueue* q) {
    if (isEmptyLinkedListQueue(q)) {
        printf("Linked List Queue Underflow\n");
        return -1; // Error value
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    q->size--;
    return value;
}

void linkedListQueueMenu() {
    LinkedListQueue q;
    initLinkedListQueue(&q);
    int choice, value;
    do {
        printf("\nLinked List Queue Menu:\n1. Enqueue\n2. Dequeue\n3. Size\n4. Underflow\n5. Back\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueueLinkedList(&q, value);
                break;
            case 2:
                value = dequeueLinkedList(&q);
                if (value != -1) printf("Dequeued: %d\n", value);
                break;
            case 3:
                printf("Size: %d\n", q.size);
                break;
            case 4:
                printf("Underflow: %s\n", isEmptyLinkedListQueue(&q) ? "Yes" : "No");
                break;
        }
    } while (choice != 5);
}

int main() {
    int choice;
    do {
        printf("\nMain Menu:\n1. Array Queue\n2. Linked List Queue\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: arrayQueueMenu(); break;
            case 2: linkedListQueueMenu(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 3);
    return 0;
}

