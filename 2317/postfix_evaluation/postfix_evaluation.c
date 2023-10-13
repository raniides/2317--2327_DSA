#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isdigit
#include "stack.h"

int evaluate_postfix(const char* postfix) {
    Stack stack;
    init(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];

        if (isdigit(token)) {
            push(&stack, token - '0'); // Convert character to integer and push to the stack
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
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
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        fprintf(stderr, "Error: Division by zero\n");
                        exit(1);
                    }
                    break;
            }

            push(&stack, result);
        }
    }

    if (!is_empty(&stack) && stack.top == 0) {
        return stack.data[0];
    } else {
        fprintf(stderr, "Error: Invalid postfix expression\n");
        exit(1);
    }
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluate_postfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
