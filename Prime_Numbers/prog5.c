#include <stdio.h>
#include "primeHeader.h"
#include <math.h>

/*
    Statement: Given an integer D, the tak is to find the sum of all the prime numbers whose count of digits is less than
               or equal to D.
*/

long calculateLogic(int D);
int main(void){
    int D;
    scanf("%d", &D);
    printf("%ld", calculateLogic(D));
    printf("\n");

    return 0;
}

long calculateLogic(int D){
    int limit = pow(10, D) - 1;
    return eratosthenesSieveAndSum(limit);
}