#include <stdio.h>
#include "sortingAlgos.h"
#define N 7
int main(void)
{
    int arr[] = {80, 20, 50, 5, 90, 23, 15};
    bubbleSort(arr, N);
    // insertionSort(arr, N);
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