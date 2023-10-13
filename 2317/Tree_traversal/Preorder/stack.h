#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "tree_node.h"  // Include the TreeNode definition

// Define the data type for the stack
typedef struct Stack Stack;

// Create an empty stack
Stack* createStack(int capacity);

// Check if the stack is empty
bool isEmpty(Stack* stack);

// Check if the stack is full
bool isFull(Stack* stack);

// Push a pointer to a struct TreeNode onto the stack
bool push(Stack* stack, struct TreeNode* item);

// Pop a pointer to a struct TreeNode from the stack
struct TreeNode* pop(Stack* stack);

// Get the top element of the stack without popping it
struct TreeNode* top(Stack* stack);

// Free the memory allocated for the stack
void destroyStack(Stack* stack);

#endif
