#include <stdio.h>
#include "stack.h"

int main() {
    Stack myStack;
    init(&myStack);

    // Push elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // Pop elements from the stack and print them
    while (!is_empty(&myStack)) {
        int item = pop(&myStack);
        printf("%d ", item);
    }

    return 0;
}
