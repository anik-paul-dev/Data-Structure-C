#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

typedef struct Stack {
    int data[MAX];
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
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Unable to push %d\n", value);
        exit(EXIT_FAILURE);
    } else {
        stack->data[++stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Unable to pop\n");
        exit(EXIT_FAILURE);
    } else {
        return stack->data[stack->top--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    Stack stack;
    initialize(&stack);
    int i = 0;
    char token;

    while (expression[i] != '\0') {
        token = expression[i];

        // If the token is a digit, push it to the stack
        if (isdigit(token)) {
            push(&stack, token - '0');
        }
        // If the token is an operator, pop two elements from the stack,
        // apply the operator and push the result back to the stack
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", token);
                    exit(EXIT_FAILURE);
            }
            push(&stack, result);
        }
        i++;
    }

    // The final result will be the only element left in the stack
    return pop(&stack);
}

int main() {
    char expression[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
