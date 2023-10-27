#include <stdio.h>
#include <string.h>
#include "stack.h"

// Function to check if a character is an operator
int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int get_precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0; // for non-operators
}

// Function to perform infix to postfix conversion
void infix_to_postfix(const char* infix, char* postfix) {
    Stack operatorStack;
    init(&operatorStack);

    int infix_length = strlen(infix);
    int j = 0;

    for (int i = 0; i < infix_length; i++) {
        char current_char = infix[i];

        if (isalnum(current_char)) {
            postfix[j++] = current_char;
        } else if (current_char == '(') {
            push(&operatorStack, current_char);
        } else if (current_char == ')') {
            while (!is_empty(&operatorStack) && peek(&operatorStack) != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Pop the '('
        } else if (is_operator(current_char)) {
            while (!is_empty(&operatorStack) && get_precedence(peek(&operatorStack)) >= get_precedence(current_char)) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, current_char);
        }
    }

    // Pop any remaining operators from the stack
    while (!is_empty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[100];
    char postfix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
