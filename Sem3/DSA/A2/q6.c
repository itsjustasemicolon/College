#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the structure for a stack
typedef struct Stack {
    int* data;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(const char* postfix) {
    Stack* stack = createStack(100); // Create a stack with capacity 100

    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];

        if (isspace(ch)) {
            continue; // Skip spaces
        }

        if (isdigit(ch)) {
            // Convert char digit to integer and push onto the stack
            push(stack, ch - '0');
        } else {
            // Operator case
            if (isEmpty(stack)) {
                printf("Error: Invalid expression\n");
                exit(EXIT_FAILURE);
            }
            int val2 = pop(stack);
            if (isEmpty(stack)) {
                printf("Error: Invalid expression\n");
                exit(EXIT_FAILURE);
            }
            int val1 = pop(stack);

            switch (ch) {
                case '+':
                    push(stack, val1 + val2);
                    break;
                case '-':
                    push(stack, val1 - val2);
                    break;
                case '*':
                    push(stack, val1 * val2);
                    break;
                case '/':
                    if (val2 != 0) {
                        push(stack, val1 / val2);
                    } else {
                        printf("Error: Division by zero\n");
                        free(stack->data);
                        free(stack);
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Error: Unsupported operator %c\n", ch);
                    free(stack->data);
                    free(stack);
                    exit(EXIT_FAILURE);
            }
        }
    }

    int result = pop(stack);
    if (!isEmpty(stack)) {
        printf("Error: Invalid expression\n");
        free(stack->data);
        free(stack);
        exit(EXIT_FAILURE);
    }

    free(stack->data);
    free(stack);

    return result;
}

int main() {
    char postfix[100];

    printf("Enter postfix expression (single-digit operands and operators, separated by spaces): ");
    fgets(postfix, sizeof(postfix), stdin);

    // Remove newline character if present
    size_t len = strlen(postfix);
    if (len > 0 && postfix[len - 1] == '\n') {
        postfix[len - 1] = '\0';
    }

    int result = evaluatePostfix(postfix);

    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}