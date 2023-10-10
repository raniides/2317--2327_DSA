//menu.c
#include <stdio.h>
#include "word_frequency.h"
#include "merge_sort.c"

#define MAX_SIZE 610 

int main() {
    int num;

    printf("Enter the number from 1 to 2\n1: Merge Sort\n2: Quick Sort\n");
    scanf("%d", &num);

    struct WordFreq arr[MAX_SIZE]; // Assuming a maximum size for your data
    FILE *file = fopen("output.txt", "r");
    int i = 0;
    int freq = 1;

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int size = 0;

    while (fscanf(file, "%s %d", arr[size].word, &arr[size].frequency) != EOF) {
        size++;
    }

    fclose(file);

    if (num == 1) {
        mergeSort(arr, 0, size - 1);

        // Create and open a new file for writing the sorted output
        FILE *sortedFile = fopen("sorted_output.txt", "w");

        if (sortedFile == NULL) {
            printf("Error creating sorted_output.txt file.\n");
            return 1;
        }

        // Write the sorted results to the sorted_output.txt file
        for ( freq = 1; freq <= size; freq++) {
            for (i = 0; i < size; i++) {
                if (arr[i].frequency == freq) {
                    fprintf(sortedFile, "%s: %d\n", arr[i].word, arr[i].frequency);
                }
            }
        }

        fclose(sortedFile); // Close the sorted output file
    } else if (num == 2) {
        // Add code for Quick Sort
    } else {
        printf("Please select a number from 1 to 2.\n");
    }

    return 0;
}

