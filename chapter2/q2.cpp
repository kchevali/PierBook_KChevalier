#include <stdio.h>

#include <vector>

const int N = 1e8;
int primes[N];
std::vector<bool> bs(N + 1, true);

int main() {
  bs[0] = bs[1] = false;
  int index = 0;
  for (long long i = 2; i < N; i++) {
    if (bs[i]) {
      for (long long j = i * i; j < N; j += i) bs[j] = false;
      primes[index++] = i;
    }
  }

  printf("Primes found count: %d\n", index);
  printf("The largest 10 primes found are:\n");
  for (int i = index - 1, j = 0; j < 10; i--, j++) {
    printf("%d\n", primes[i]);
  }
}
/*
Write a program that lists prime numbers in increasing order.
A prime number is one that is only divisible by one and
itself. For example 3 is prime but 4 is not, because it is
divisible by 2. A simple, but inefficient, algorithm for
finding prime numbers is to loop over alint numbers and test
each one for division by the numbers smaller than it.
Remember, you can use the % operator to test for
divisibility. Around 300 B.C. Euclid proved that there is an
infinite number of prime numbers. How many can you find?

Output
Primes found count: 5761455
The largest 10 primes found are:
99999989
99999971
99999959
99999941
99999931
99999847
99999839
99999827
99999821
99999787

*/