
#include "word_frequency.h"

// Swap two WordFrequency elements
void swap(struct WordFreq *a, struct WordFreq *b) {
    struct WordFreq temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(struct WordFreq arr[], int low, int high) {
    int pivot = arr[high].frequency;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].frequency <= pivot) {  // Modified to sort in ascending order
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quicksort(struct WordFreq arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
