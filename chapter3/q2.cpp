#include <stdio.h>

#include <vector>

const int N = 1e8;
int primes[N];
bool bs[N + 1];

int main() {
  memset(bs, true, sizeof(bs));
  bs[0] = bs[1] = false;
  int length = 0, twinPrime = 0;
  for (long long i = 2; i < N; i++) {
    if (bs[i]) {
      for (long long j = i * i; j < N; j += i) bs[j] = false;
      if (primes[length - 1] + 2 == i) twinPrime++;
      primes[length++] = i;
    }
  }

  printf("Prime Count: %d\n", length);
  printf("Twin Prime Count:%d\n", twinPrime);
}
/*


Question
Write a function that determines if a number is
prime. As we discussed in Exercise 2.2, a prime
number is one that is only divisible by 1 and
itself. A simple, though inefficient, algorithm
for determining if a number is prime is to loop
over all the numbers less than it and test for
divisibility with %.
Use this function in a program that lists twin
primes in increasing order. A twin prime is a
pair of primes that differ by 2, like 3 and 5
or 11 and 13. Put your function in a different
file from main and declare your function in a
header file. Create a Makefile to compile and
link your code.

Output
Prime Count: 5761455
Twin Prime Count:440314
*/