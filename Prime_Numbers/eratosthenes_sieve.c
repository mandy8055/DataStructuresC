#include <stdio.h>
#include "primeHeader.h"

int main(void){
  int num;
  printf("Enter the number: ");
  scanf("%d", &num);
  printf("Following are the list of numbers smaller than or equal to %d\n", num);
  eratosthenesSieve(num);
  return 0;
}
