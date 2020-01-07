#include <stdio.h>
#include <stdbool.h>
// Function declaration before main is important in linux. but in dev C++ it is not required
bool isPrime(int num);

int main(void) {
  int num;
  printf("Enter the number: ");
  scanf("%d", &num);
  if(isPrime(num)) printf("%d is a prime number.\n", num);
  else  printf("%d is not a prime number.\n", num);
  return 0;
}

bool isPrime(int num){
  if(num == 2 || num == 3)
    return true;
  if(num % 2 == 0)
    return false;
  int i = 3;
  while(i * i < num){
    if(num % i == 0)
      return false;
    i += 2;
  }
  return true;
}
