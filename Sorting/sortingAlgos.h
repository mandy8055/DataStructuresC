#include <stdio.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void insertionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void countingSort(int arr[], int size, int range);
void selectionSort(int arr[], int size);

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
    for (int i = 0; i <= range; i++)
    {
        countArr[i] = 0;
    }
    // Populating the countArr with the frequencies.
    for (int i = 0; i < size; i++)
    {
        countArr[arr[i]]++;
    }

    int k = 0; // For keeping track of the index of original array.
    for (int i = 0; i <= range; i++)
    {
        if (countArr[i])
        {
            for (int j = 0; j < countArr[i]; j++)
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
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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