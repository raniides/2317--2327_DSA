// word_frequency.h
#ifndef WORD_FREQUENCY_H
#define WORD_FREQUENCY_H

// Define the data structure to store word frequencies
struct WordFreq {
    char word[610];
    int frequency;
};

// Merge sort function declaration
void mergeSort(struct WordFreq arr[], int l, int r);

#endif

