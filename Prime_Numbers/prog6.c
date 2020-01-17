#include <stdio.h>
#include "primeHeader.h"
#include <stdbool.h>
/*
Statement: Given an integer N and a base number A; the task is to check whether N is 
           Euler pseudoprime to the given base A.

           EULER PSEUDOPRIME:

           An integer N is called Euler Pseudoprime to the base A, if
            1. A > 0 and N is an odd composite number.
            2. A and N are co-prime i.e. GCD(A, N) = 1.
            3. A ^ (N - 1) / 2 % N is either 1 or N - 1.
*/
bool eulerPseudoPrime(int n, int base);

int main(void){
    int n, base;
    scanf("%d %d", &n, &base);
    if(eulerPseudoPrime(n, base))printf("YES");
    else printf("NO");
    printf("\n");
    return 0;
}

bool eulerPseudoPrime(int n, int base){
    bool res = false;
    // Condition 1: base > 0 and n is odd composite number.
    if(base > 0 && n % 2 != 0 && !isPrime(n)){
        // Condition 2: base and n are co-prime.
        if(gcd(n, base) == 1){
            // Condition 3: base ^(n - 1) / 2 % N is either 1 or n - 1.
            int tmp1 = (n - 1) / 2;
            int tmp = power(base, tmp1, n);
            if(tmp == 1 || tmp == (n - 1))res = true;  
            }
    }
    return res;
}