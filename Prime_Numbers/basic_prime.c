#include <stdio.h>
#include "primeHeader.h"
int main(void) {
  int num;
  printf("Enter the number: ");
  scanf("%d", &num);
  if(isPrime(num)) printf("%d is a prime number.\n", num);
  else  printf("%d is not a prime number.\n", num);
  return 0;
}
