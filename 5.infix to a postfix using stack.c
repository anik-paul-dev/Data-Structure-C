#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100 // Maximum size of the stack

typedef struct Stack {
    char data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element to the stack
void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow. Unable to push %c\n", value);
        exit(EXIT_FAILURE);
    } else {
        stack->data[++stack->top] = value;
    }
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Unable to pop\n");
        exit(EXIT_FAILURE);
    } else {
        return stack->data[stack->top--];
    }
}

// Function to peek the top element of the stack
char peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    } else {
        return stack->data[stack->top];
    }
}

// Function to determine the precedence of operators
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

// Function to determine the associativity of operators
int isRightAssociative(char op) {
    if (op == '^') {
        return 1; // Right associative
    }
    return 0; // Left associative
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initialize(&stack);
    int i = 0, j = 0;
    char token;

    while (infix[i] != '\0') {
        token = infix[i];

        // If the token is an operand, add it to the postfix expression
        if (isalnum(token)) {
            postfix[j++] = token;
        }
        // If the token is '(', push it to the stack
        else if (token == '(') {
            push(&stack, token);
        }
        // If the token is ')', pop and output from the stack until '(' is encountered
        else if (token == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop '(' from the stack
        }
        // If the token is an operator
        else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) > precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            while (!isEmpty(&stack) && precedence(peek(&stack)) == precedence(token) && !isRightAssociative(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
