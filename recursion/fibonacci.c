#include <stdio.h>
long fibonacciRecursive(int n);
long fibonacciIterative(int n);

int main(void)
{
    printf("%ld", fibonacciIterative(8));
    //    printf("%ld", fibonacciRecursive(8));

    return 0;
}

long fibonacciRecursive(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

long fibonacciIterative(int n)
{
    long first = 0, second = 1;
    long third;
    if (n == 0)
        return first;
    int i = 2;
    while (i <= n)
    {
        third = first + second;
        first = second;
        second = third;
        i++;
    }
    return third;
}
