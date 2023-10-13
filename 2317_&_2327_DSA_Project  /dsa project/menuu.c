
//menuu.c
#include <stdio.h>
#include "word_frequency.h"
#include "merge_sort.c"
#include "quickSort.c"

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
        // Perform the merge sort
        mergeSort(arr, 0, size - 1);

    printf("\nSorted Output based on word frequency is:\n");

        // Print the sorted results in the terminal
        for (i = 0; i < size; i++) {
            printf("%s: %d\n", arr[i].word, arr[i].frequency);
        }

        // Create and open a new file for writing the sorted output
        FILE *sortedFile = fopen("sorted_output.txt", "w");

        if (sortedFile == NULL) {
            printf("Error creating sorted_output.txt file.\n");
            return 1;
        }

        // Write the sorted results to the sorted_output.txt file
            for (i = 0; i < size; i++) {
                    fprintf(sortedFile, "%s: %d\n", arr[i].word, arr[i].frequency);
                
        }

        fclose(sortedFile); // Close the sorted output file
    } else if (num == 2) {
        // Add code for Quick Sort
         // Perform quicksort
    quicksort(arr, 0, size - 1);

    // Write sorted results to the output file
    FILE *output_file = fopen("sorted_output1.txt", "w");
    if (output_file == NULL) {
        perror("Error opening the output file");
        return 1;
    }

    // Print the sorted results in the terminal
        for (i = 0; i < size; i++) {
            printf("%s: %d\n", arr[i].word, arr[i].frequency);
        }

    for (int i = 0; i < size; i++) {
        fprintf(output_file, "%s: %d\n", arr[i].word, arr[i].frequency);
    }

    fclose(output_file);

    printf("Sorting complete in ascending order. Results saved in 'sorted_output1.txt'\n");

    } else {
        printf("Please select a number from 1 to 2.\n");
    }

    return 0;
}

