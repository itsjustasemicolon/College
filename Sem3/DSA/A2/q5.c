#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the structure for a stack
typedef struct Stack {
    char* data;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, char item) {
    if (isFull(stack)) return;
    stack->data[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) return '\0'; // Return null character if stack is empty
    return stack->data[stack->top--];
}

// Function to get the top element of the stack
char peek(Stack* stack) {
    if (isEmpty(stack)) return '\0'; // Return null character if stack is empty
    return stack->data[stack->top];
}

// Function to check precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(const char* infix, char* postfix) {
    Stack* stack = createStack(100); // Create a stack with capacity 100
    int k = 0; // Index for postfix expression

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isspace(ch)) {
            continue;
        }

        if (isalnum(ch)) {
            postfix[k++] = ch; // Add operand to postfix expression
        } else if (ch == '(') {
            push(stack, ch); // Push '(' onto the stack
        } else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(stack);
            }
            pop(stack); // Remove '(' from the stack
        } else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(ch)) {
                postfix[k++] = pop(stack);
            }
            push(stack, ch); // Push operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(stack)) {
        postfix[k++] = pop(stack);
    }

    postfix[k] = '\0'; // Null-terminate the postfix expression
    free(stack->data);
    free(stack);
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline character if present
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}