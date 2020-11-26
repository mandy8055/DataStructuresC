#include <stdio.h>
#include <string.h>
#include <math.h>

int binarySearch_Iterative(int arr[], int size, int searchElement);
int binarySearch_Recursive(int arr[], int low, int high, int searchElement);
int linearSearch(int arr[], int size, int searchElement);

// Implementation of Iterative Binary Search
int binarySearch_Iterative(int arr[], int size, int searchElement)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int middle = floor((low + high) / 2);
        if (arr[middle] == searchElement)
            return middle;
        if (arr[middle] > searchElement)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}
// Implementation of Recursive binary Search
/* NOTE: Not recommended to implement since it is a tail recursion. 
 *        Iterative method preferred to avoid using extra space
*/
int binarySearch_Recursive(int arr[], int low, int high, int searchElement)
{
    if (low <= high)
    {
        int mid = floor((high + low) / 2);
        // Base case
        if (arr[mid] == searchElement)
            return mid;
        if (arr[mid] > searchElement)
            return binarySearch_Recursive(arr, low, mid - 1, searchElement);
        else
            return binarySearch_Recursive(arr, mid + 1, high, searchElement);
    }
    return -1;
}

// Implementation of linear search
int linearSearch(int arr[], int size, int searchElement)
{
    int i;
    for (i = 0; i < size; i++)
        if (arr[i] == searchElement)
            return i;
    return -1;
}