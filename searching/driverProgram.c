#include <stdio.h>
#include "searchingAlgos.h"
#include "../Sorting/sortingAlgos.h"
#define N 7

int main(void)
{
    int arr[] = {80, 20, 50, 5, 90, 23, 15};
    int searchElement = 90;
    int searchElementNT = 92;
    // int res = linearSearch(arr, N, searchElement);
    // For implementing binary search array should be sorted. Therefore;
    quickSort(arr, 0, N - 1);
    // int res = binarySearch_Recursive(arr, 0, N, searchElementNT);
    int res = binarySearch_Iterative(arr, N, searchElementNT);
    if (res == -1)
        printf("Searched element is not present in the array.");
    else
        printf("Element is present at position %d in the array.", res);

    return 0;
}
