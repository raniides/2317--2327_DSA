#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "stack.h"

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

void infix_to_postfix(const char* infix, char* postfix) {
    Stack stack;
    init(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char token = infix[i];
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (is_operator(token)) {
            while (!is_empty(&stack) && precedence(stack.data[stack.top]) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!is_empty(&stack) && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!is_empty(&stack) && stack.data[stack.top] == '(') {
                pop(&stack); // Pop and discard the '('
            }
        }
        i++;
    }

    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    char postfix[100];
    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
