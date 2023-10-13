// 2317
// merge_sort.c
#include "word_frequency.h"

// Merge function for merging two sorted arrays of struct WordFreq
void merge(struct WordFreq arr[], int leftmost_index, int middle_index, int rightmost_index) {
    int i, j, k;
    int n1 = middle_index - leftmost_index + 1;
    int n2 = rightmost_index - middle_index;

    // Create temporary arrays
    struct WordFreq L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[leftmost_index + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle_index + 1 + j];

    // Merge the temporary arrays back into arr[l...r]
    i = 0;
    j = 0;
    k = leftmost_index;

    while (i < n1 && j < n2) {
        if (L[i].frequency <= R[j].frequency) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function for an array of struct WordFreq
void mergeSort(struct WordFreq arr[], int leftmost_index, int rightmost_index) {
    if (leftmost_index < rightmost_index) {
        int middle_index = leftmost_index + (rightmost_index - leftmost_index) / 2;

        // Sort first and second halves
        mergeSort(arr, leftmost_index, middle_index);
        mergeSort(arr, middle_index + 1, rightmost_index);

        // Merge the two halves
        merge(arr, leftmost_index, middle_index, rightmost_index);
    }
}

