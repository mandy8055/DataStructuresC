#include <stdio.h>
#include "primeHeader.h"

/*
Statement: Given Q queries and an integer K where each query consists of a range [L, R] and the task is
           to find the count of integers in the given range whose digit sum is prime and divisible by K.
*/

int countNumbers(int arr[], int k);
int digitSum(int num);
int main(void){
    int k = 3;
    // {{1, 11}, {5, 15}, {2, 24}}; K = 2
    int que[5][5] = {{2, 17}, {3, 24}};
    for(int i = 0; i < 2; i++){
        printf("%d\n", countNumbers(que[i], k));
    }
    return 0;
}

int countNumbers(int arr[], int k){
    int count = 0;
    for(int i = arr[0]; i <= arr[1]; i++){
        if(i / 10 == 0){
            if(i % k == 0 && isPrime(i))count++;
        }
        else{
            if(digitSum(i) % k == 0 && isPrime(digitSum(i)))count++;
        }
    }
    return count;
}

int digitSum(int num){
    if(num == 0) return 0;
    return ((num % 10) + (digitSum(num / 10)));
}