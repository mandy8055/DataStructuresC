#include <stdio.h>

int eratosthenesSieve(int n);

int main(void){
  int num;
  printf("Enter the number: ");
  scanf("%d", &num);
  printf("Following are the list of numbers smaller than or equal to %d\n", num);
  eratosthenesSieve(num);
  return 0;
}

int eratosthenesSieve(int n){
  int primes[n + 1];
  // 1. Consider All elements as prime initially
  for(int i = 0; i <= n; i++)
    primes[i] = 1;

  // 2. Make primes[0] and primes[1] as 0 (since they are not prime)
  primes[0] = primes[1] = 0;

  // 3. Main case
  for(int i = 2; i * i <= n; i++){
    if(primes[i] == 1)
      for(int j = i * i; j <= n; j += i)
        primes[j] = 0;
  }
  // 4. Print p
  for(int p = 2; p <= n; p++)
    if(primes[p])
      printf("%d ", p);

  printf("\n");
}
