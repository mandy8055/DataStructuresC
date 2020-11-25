#include <stdio.h>
#include "sortingAlgos.h"
#define N 7
#define N2 10
// Runner function for running comparison-based sorting algorithms
int main(void)
{
    int arr[] = {80, 20, 50, 5, 90, 23, 15};
    // bubbleSort(arr, N);
    // insertionSort(arr, N);
    // selectionSort(arr, N);
    quickSort(arr, 0, N - 1);
    for (int i = 0; i < N; i++)
    {
        if (i == (N - 1))
        {
            printf("%d", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
    return 0;
}

// Runner function for non-comparison based sorting algorithms
/*
int main(void)
{
    int arr2[] = {1, 2, 4, 9, 9, 9, 4, 1, 5, 3};
    countingSort(arr2, N2, 9);
    for (int i = 0; i < N2; i++)
    {
        if (i == (N2 - 1))
        {
            printf("%d", arr2[i]);
            break;
        }
        printf("%d, ", arr2[i]);
    }
    return 0;
}
*/