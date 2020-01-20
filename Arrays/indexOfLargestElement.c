#include <stdio.h>

int MAX_INT(int arr[]);

int main(void){
    int arr_count;
    // Inputting the size of array
    scanf("%d", &arr_count);
    // Dynamic allocation of memory
    int *types = malloc(sizeof(int) * arr_count);
    for(int types_i = 0; types_i < arr_count; types_i++){
       scanf("%d",&types[types_i]);
    }
    // Setting up the frequency array
    int a[5];
    for(int i = 1; i <= 5; i++)a[i] = 0;

    return 0;
}
// Function to return the index of the largest element in an array. 
// (If two elements are equal then return the smaller index)
int MAX_INT(int arr[])
{
    int Max,temp;
    int i=1;
    temp=i;
    Max=arr[i];
    while(i <= 5)
    {
        if (Max < arr[i])
        {
            Max=arr[i];
            temp=i;
        }
        i++;
    }
    return temp;
}

