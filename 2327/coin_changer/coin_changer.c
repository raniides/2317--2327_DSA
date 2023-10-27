#include <stdio.h>
#include "stack.h"

// Define the denominations of coins
int denominations[] = {1, 2, 5, 10};

// Function to find all combinations of coins to make an amount
void findCombinations(int amount, int index, Stack* stack, int* total_combinations) {
    if (amount == 0) {
        // If amount is zero, we found a combination
        printf("Combination: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d rupee coin", stack->data[i]);
            if (i < stack->top) {
                printf(" + ");
            }
        }
        printf("\n");
        (*total_combinations)++;
    } else if (amount > 0 && index < sizeof(denominations) / sizeof(denominations[0])) {
        // Choose the current denomination
        push(stack, denominations[index]);
        findCombinations(amount - denominations[index], index, stack, total_combinations);
        pop(stack);

        // Skip the current denomination
        findCombinations(amount, index + 1, stack, total_combinations);
    }
}

int main() {
    int amount;

    // Create and initialize the stack
    Stack stack;
    init(&stack);

    // Input the amount from the user
    printf("Enter the amount in rupees: ");
    scanf("%d", &amount);

    // Find and print all combinations of coins
    printf("All combinations of coins to make %d rupees:\n", amount);
    int total_combinations = 0;
    findCombinations(amount, 0, &stack, &total_combinations);

    printf("Total number of combinations = %d\n", total_combinations);

    return 0;
}
