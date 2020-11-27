#include <stdio.h>
#include <math.h>
#define N 7
struct pair
{
    int min;
    int max;
};

struct pair getMinMax(int arr[], int low, int high);

// Driver program
int main(void)
{
    int arr[] = {80, 20, 50, 5, 90, 23, 15};
    printf("The minimum element in the array is %d and the maximum element in the given array is %d", getMinMax(arr, 0, N - 1).min, getMinMax(arr, 0, N - 1).max);
    return 0;
}

/* Steps involving implementation of getMinMax function:
1. If there is only one element in the array.
2. If there are only two elements in the array.
3. If there are more than two elements in the array.{Recursion here} DIVIDE
4. Compare to get min and max element from the result got in step 3.
*/
struct pair getMinMax(int arr[], int low, int high)
{
    struct pair minMax, minMaxRight, minMaxLeft;
    // Base Case: If there is only one element in the array
    if (low == high)
    {
        minMax.min = minMax.max = arr[low];
        return minMax;
    }
    // If there are two elements in the array
    if (high == low + 1)
    {
        if (arr[low] <= arr[high])
        {
            minMax.min = arr[low];
            minMax.max = arr[high];
        }
        else
        {
            minMax.min = arr[high];
            minMax.max = arr[low];
        }
        return minMax;
    }
    // If there are more than two elements in the array
    else
    {
        int mid = floor((low + high) / 2);
        minMaxLeft = getMinMax(arr, low, mid);
        minMaxRight = getMinMax(arr, mid + 1, high);

        // Compare for the maximum element between two sub problems
        if (minMaxLeft.max > minMaxRight.max)
        {
            minMax.max = minMaxLeft.max;
            minMax.min = minMaxRight.min;
        }
        else
        {
            minMax.max = minMaxRight.max;
            minMax.min = minMaxLeft.min;
        }
        return minMax;
    }
}