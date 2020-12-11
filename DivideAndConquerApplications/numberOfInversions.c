#include <stdio.h>
#include <math.h>
#define N 7

int enhancedMergeSort(int arr[], int aux[], int left, int right);
int merge(int arr[], int aux[], int left, int middle, int right);

int main(void)
{
    int arr[] = {80, 20, 50, 5, 90, 23, 15};
    int aux[N];
    // Populate the aux array. aux contains the sorted array.
    int i;
    for (i = 0; i < N; i++)
    {
        aux[i] = arr[i];
    }
    printf("The total numbers of inversions in the array is: %d", enhancedMergeSort(arr, aux, 0, N - 1));
    return 0;
}

// Implementation of enhanced Merge Sort
int enhancedMergeSort(int arr[], int aux[], int left, int right)
{
    int inversionCount = 0;
    // Base Case
    if (left == right)
        return 0;
    if (left < right)
    {
        int middle = floor((left + right) / 2);

        inversionCount += enhancedMergeSort(arr, aux, left, middle);
        inversionCount += enhancedMergeSort(arr, aux, middle + 1, right);

        inversionCount += merge(arr, aux, left, middle, right);
    }
    return inversionCount;
}

// Implementation of merge algorithm(Modified for counting number of inversions)
int merge(int arr[], int aux[], int left, int middle, int right)
{
    int i, j, k, count = 0;
    i = k = left;
    j = middle + 1;

    while (i <= middle && j <= right)
    {
        if (arr[i] <= arr[j])
            aux[k++] = arr[i++];
        else
        {
            aux[k++] = arr[j++];
            count += (middle - i + 1);
        }
    }

    while (i <= middle)
        aux[k++] = arr[i++];

    for (i = left; i <= right; i++)
        arr[i] = aux[i];
    return count;
}