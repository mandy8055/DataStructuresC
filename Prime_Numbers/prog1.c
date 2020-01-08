// Remove all the prime numbers from the given array.

#include <stdio.h>
#include "primeHeader.h"

void removePrimes(int arr[], int size);


int main(void){
    int arr[] = {4, 6, 5, 3, 8, 7, 10, 11, 14, 15};
    int size = 10;
    removePrimes(arr, size);
    return 0;
}

void removePrimes(int arr[], int size){
    for(int i = 0; i < size; i++){
        if(!isPrime(arr[i]))printf("%d ", arr[i]);
    }
    printf("\n");
}