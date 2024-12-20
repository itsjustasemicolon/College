#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(Stack *stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1; 
    }
    return stack->arr[stack->top];
}

typedef struct Queue {
    Stack *stack1;
    Stack *stack2;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    queue->capacity = capacity;
    return queue;
}

void enqueue(Queue *queue, int item) {
    if (queue->stack1->top == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    push(queue->stack1, item);
}

int dequeue(Queue *queue) {
    if (queue->stack1->top == -1 && queue->stack2->top == -1) {
        printf("Queue is empty\n");
        return -1; 
    }

    if (queue->stack2->top == -1) {
        while (queue->stack1->top != -1) {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    return pop(queue->stack2);
}

void displayQueue(Queue *queue) {
    printf("Queue contents: ");
    for (int i = queue->stack2->top; i >= 0; i--) {
        printf("%d ", queue->stack2->arr[i]);
    }
    for (int i = 0; i <= queue->stack1->top; i++) {
        printf("%d ", queue->stack1->arr[i]);
    }
    printf("\n");
}

void freeQueue(Queue *queue) {
    free(queue->stack1->arr);
    free(queue->stack2->arr);
    free(queue->stack1);
    free(queue->stack2);
    free(queue);
}

int main() {
    int capacity = 100; 
    Queue *queue = createQueue(capacity);
   
    int choice, value;

    do {
        printf("\nQueue using Two Stacks Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) printf("Dequeued: %d\n", value);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    freeQueue(queue);
    return 0;
}
