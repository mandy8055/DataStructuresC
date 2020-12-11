#include <stdio.h>

int gcd(int num1, int num2);

int main(void)
{
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("The gcd of two numbers is: %d", gcd(num1, num2));
    return 0;
}
// Implementation of Euclidean GCD(O(logn))
int gcd(int num1, int num2)
{
    if (num1 > num2)
    {
        // Base case
        if (num2 == 0)
            return num1;
        return gcd(num2, num1 % num2);
    }
    else
    {
        // Base Case
        if (num1 == 0)
            return num2;
        return gcd(num1, num2 % num1);
    }
}