#include <stdio.h>
#define N 7

void bubbleSort(int arr[], int size);
void swap(int *a, int *b);

int main(void)
{
    int arr[] = {80, 20, 50, 5, 90, 23, 15};
    bubbleSort(arr, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}

void bubbleSort(int arr[], int size)
{
    // Base case
    if (size == 1)
        return;
    int swapped;
    for (int i = 0; i < size; i++)
    {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}