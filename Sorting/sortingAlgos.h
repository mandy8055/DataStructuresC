#include <stdio.h>

void swap(int *a, int *b);
void insertionSort(int arr[], int size);
void bubbleSort(int arr[], int size);

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

// Utility function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}