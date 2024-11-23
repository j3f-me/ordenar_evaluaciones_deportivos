//
// Created by jan on 22.11.24.
//

#include "ordenamiento.h"

// fuente: https://www.geeksforgeeks.org/c-bubble-sort/
int bubble_sort(atleta **arreglo, int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arreglo[j]->id > arreglo[j + 1]->id) {
                atleta *temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
    return comparisons;
}


// quicksort functions: https://www.geeksforgeeks.org/quick-sort-in-c/
void swap(atleta **a, atleta **b) {
    atleta *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(atleta **arr, int low, int high) {
    // Initialize pivot to be the first element
    int p = arr[low]->id;
    int i = low;
    int j = high;

    while (i < j) {
        // Find the first element greater than
        // the pivot (from starting)
        while (arr[i]->id <= p && i <= high - 1) {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (arr[j]->id > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quick_sort(atleta **arr, int low, int high) {
    if (low < high) {
        // call partition function to find Partition Index
        int pi = partition(arr, low, high);

        // Recursively call quickSort() for left and right
        // half based on Partition Index
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// radix sort: https://www.geeksforgeeks.org/c-program-for-radix-sort/

int getMax(atleta **arr, int n) {
    int mx = arr[0]->id;
    for (int i = 1; i < n; i++)
        if (arr[i]->id > mx)
            mx = arr[i]->id;
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(atleta **arr, int n, int exp) {
    // output array
    int output[n];
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i]->id / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i]->id / exp) % 10] - 1] = arr[i]->id;
        count[(arr[i]->id / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i]->id = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radix_sort(atleta **arr, int n) {
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
