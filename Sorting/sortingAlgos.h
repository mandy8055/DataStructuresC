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

// Implementation of Counting sort
void countingSort(int arr[], int size, int range)
{
    int countArr[range];
    // Filling the initial array with the 0s
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

// Utility function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}