#include <stdio.h>

/* Question Statement: Given two integers X and Y where X > Y, the task is check if 
   there exists a prime number P such that if P is repeatedly subtracted from X then it gives Y.*/
/*
    Pseudocode
    1. Input Two numbers.
    2. Subtract smaller number from the larger number.
    3. If the subtracted number is 1 return false.
    4. else return true.
*/

int main(void){
    printf("Enter two numbers: ");
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int temp = 0;
    if(num1 > num2)temp = num1 - num2;
    else temp = num2 - num1;
    if(temp == 1) printf("NO\n");
    else printf("YES\n");

    return 0;
}

