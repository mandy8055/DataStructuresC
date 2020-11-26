#include <stdio.h>
#include <math.h>

void bubbleSort(int arr[], int size);
void countingSort(int arr[], int size, int range);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void selectionSort(int arr[], int size);
// Utility functions
void merge(int arr[], int l, int m, int r);
int partition(int arr[], int low, int high);
void printArr(int arr[], int size);
void swap(int *a, int *b);

// Implementation of Bubble sort
void bubbleSort(int arr[], int size)
{
    int i, j, swapped;
    for (i = 0; i < size; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

// Implementation of Counting sort
void countingSort(int arr[], int size, int range)
{
    int countArr[range];
    // Filling the countArr array initially with 0's.
    int i;
    for (i = 0; i <= range; i++)
    {
        countArr[i] = 0;
    }
    // Populating the countArr with the frequencies.
    for (i = 0; i < size; i++)
    {
        countArr[arr[i]]++;
    }

    int k = 0; // For keeping track of the index of original array.
    for (i = 0; i <= range; i++)
    {
        if (countArr[i])
        {
            int j;
            for (j = 0; j < countArr[i]; j++)
            {
                arr[k++] = i;
            }
        }
    }
}

// Implementation of Insertion Sort
void insertionSort(int arr[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

// Implementation of Merge Sort
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = floor((l + r) / 2);
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Implementation of QuickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitions = partition(arr, low, high);
        quickSort(arr, low, partitions - 1);
        quickSort(arr, partitions + 1, high);
    }
}
// Implementation of Selection Sort
void selectionSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        int jmin = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[jmin])
                jmin = j;
        }
        if (i != jmin)
            swap(&arr[i], &arr[jmin]);
    }
}
// Utility functions
// Implementation of Merge Algorithm
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays for left and right sub-arrays
    int L[n1], R[n2];
    // Populate the temp sub-arrays
    int i, j;
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    // Merge the sub-arrays
    int k = l;
    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements from L sub-arrays if exists
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements from R sub-array if exists
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Implementation of partition algorithm
int partition(int arr[], int low, int high)
{
    int i, j, pivot;
    pivot = arr[high];
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
// Implementation of Print Array
void printArr(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (i == (size - 1))
        {
            printf("%d", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
}
// Implementation of Swap
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
