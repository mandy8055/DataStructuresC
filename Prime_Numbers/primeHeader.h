#include <stdio.h>
#include <stdbool.h>

// 1. Basic prime validation function
bool isPrime(int num){
  if(num == 0 || num == 1)
    return false;
  if(num == 2 || num == 3)
    return true;
  if(num % 2 == 0)
    return false;
  int i = 3;
  while(i * i <= num){
    if(num % i == 0)
      return false;
    i += 2;
  }
  return true;
}

// 2. Eratosthenes sieve function
void eratosthenesSieve(int n){
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
  // 4. Print p (Time Complexity: O(nloglogn))
  for(int p = 2; p <= n; p++)
    if(primes[p])
      printf("%d ", p);

  printf("\n");
}

// 3. Prime factorization of a number
void primeFactorization(int n){
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      int count = 0;
      while(n % i == 0){
        n /= i;
        count++;
      }
      printf("(%d ^ %d)", i, count);
    }
  }
  if(n != 1)printf("(%d ^ 1)", n);

  printf("\n");
}

// 4. Eratosthenese Sieve sum
long eratosthenesSieveAndSum(int n){
  int primes[n + 1];
  long sum = 0;
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
  // 4. Print p (Time Complexity: O(nloglogn))
  for(int p = 2; p <= n; p++)
    if(primes[p])
      sum += p;
  return sum;
}

int gcd(int num1, int num2){
  // base case
  if(num2 == 0) return num1;
  // Main case
  return gcd(num2, num1 % num2);
}

int powerForPseudoPrime(int a, int tmp, int n){
  // Base case
  if(tmp == 0)return 1;
  if(tmp == 1) return a;
  // Main case
  int i = 1, b = 1;
  while(i <= tmp){
    b = (b * a) % n;
    i++;
  }
  return b;
}
