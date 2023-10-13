#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

struct Stack {
    int top;
    int capacity;
    struct TreeNode** array;  // Changed the data type to store TreeNode pointers
};

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct TreeNode**)malloc(stack->capacity * sizeof(struct TreeNode*));
    if (!stack->array) {
        free(stack);
        return NULL;
    }
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

bool push(Stack* stack, struct TreeNode* item) {
    if (isFull(stack)) {
        return false;
    }
    stack->array[++stack->top] = item;
    return true;
}

struct TreeNode* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top--];
}

struct TreeNode* top(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top];
}

void destroyStack(Stack* stack) {
    free(stack->array);
    free(stack);
}
