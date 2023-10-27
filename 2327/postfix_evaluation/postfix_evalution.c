#include <stdio.h>
#include <string.h>
#include <ctype.h> // For isdigit
#include "stack.h"

// Function to perform postfix evaluation
int evaluate_postfix(const char* postfix) {
    Stack operandStack;
    init(&operandStack);

    int length = strlen(postfix);

    for (int i = 0; i < length; i++) {
        char current_char = postfix[i];

        if (isdigit(current_char)) {
            // If the character is a digit, push it onto the stack
            int value = current_char - '0'; // Convert character to integer
            push(&operandStack, value);
        } else if (isspace(current_char)) {
            // Ignore whitespace characters
            continue;
        } else {
            // If the character is an operator, pop two operands, apply the operator, and push the result
            int operand2 = pop(&operandStack);
            int operand1 = pop(&operandStack);

            int result;
            switch (current_char) {
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
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    return -1;
            }

            push(&operandStack, result);
        }
    }

    // The final result should be on the top of the stack
    return pop(&operandStack);
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluate_postfix(postfix);

    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}
