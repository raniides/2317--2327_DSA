#include <stdio.h>
#include <string.h>
#include "stack.h"

// Function to check if the given character is an opening bracket
int is_opening_bracket(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Function to check if the given character is a closing bracket
int is_closing_bracket(char c) {
    return (c == ')' || c == '}' || c == ']');
}

// Function to check if two characters form a matching pair of brackets
int are_matching_brackets(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

// Function to check for balanced brackets
int is_balanced(char* expression) {
    Stack stack;
    init(&stack);

    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        if (is_opening_bracket(expression[i])) {
            push(&stack, expression[i]);
        } else if (is_closing_bracket(expression[i])) {
            if (is_empty(&stack)) {
                return 0; // Unmatched closing bracket
            }

            char top = pop(&stack);

            if (!are_matching_brackets(top, expression[i])) {
                return 0; // Mismatched brackets
            }
        }
    }

    // If the stack is empty, all brackets are balanced
    return is_empty(&stack);
}

int main() {
    char expression[100];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (is_balanced(expression)) {
        printf("The expression \"%s\" is valid.\n", expression);
    } else {
        printf("The expression \"%s\" is not valid.\n", expression);
    }

    return 0;
}
