#include <stdio.h>

#include <vector>

int main() {
  const int N = 1e6;
  int index = 1, primes[N];
  primes[0] = 2;
  for (int i = 3; i < N; i += 2) {
    bool isPrime = true;
    for (int j = 1; j < index; j++) {
      if (i % primes[j] == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) primes[index++] = i;
  }

  printf("Primes found count: %d\n", index);
  printf("The largest 10 primes found are:\n");
  for (int i = index - 1, j = 0; j < 10; i--, j++) {
    printf("%d\n", primes[i]);
  }
}
/*
Quesiton
Write a program that lists prime numbers in increasing order.
A prime number is one that is only divisible by one and
itself. For example 3 is prime but 4 is not, because it is
divisible by 2. A simple, but inefficient, algorithm for
finding prime numbers is to loop over all numbers and test
each one for division by the numbers smaller than it.
Remember, you can use the % operator to test for
divisibility. Around 300 B.C. Euclid proved that there is an
infinite number of prime numbers. How many can you find?

Output
Primes found count: 78498
The largest 10 primes found are:
999983
999979
999961
999959
999953
999931
999917
999907
999883
999863

*/