#include <stdio.h>
#include "primeHeader.h"

int main(void){
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    printf("The prime factors of %d are: ", num);
    primeFactorization(num);
    return 0;
}