#include <stdio.h>
#include "primeHeader.h"

/* Statement: Given an integer N, the task is to find the count of all the primes below N
              whcich can be expressed as the sum of two primes.

    Pseudocode:
        1. Input the number num.
        2. If number is less than 5 simply return 0;
        3. Take a counter to count to number of prime results.
        **4. Take a variable and initialize to 2(Every other prime numbers which are possible 
            from the sum of two prime numbers must contain 2 as one prime number).
*/

int countPrimes(int num);
int main(void){
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("%d\n", countPrimes(num));
    return 0;
}

int countPrimes(int num){
    if(num < 5)return 0;
    int count = 0, i = 2;
    for(int j = 3; (i + j) <= num; j += 2){
        int tmp = i + j;
        if(isPrime(j) && isPrime(tmp))count++;
    }
    return count;
}

