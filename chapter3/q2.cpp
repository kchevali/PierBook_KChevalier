#include <stdio.h>

#include <vector>

const int N = 1e8;
int primes[N];
std::vector<bool> bs(N + 1, true);

bool isPrime(int N) {
  if (N < bs.size()) return bs[N];
  for (int p : primes)
    if (N % p == 0) return false;
  return true;
}

int main() {
  int n[5]{2, 3, 5, 7, 11};

  bs[0] = bs[1] = false;
  int index = 0;
  for (long long i = 2; i < N; i++) {
    if (bs[i]) {
      for (long long j = i * i; j < N; j += i) bs[j] = false;
      primes[index++] = i;
    }
  }

  int twinPrime = 0;
  for (int i = 0; i < index; i++) {
    for (int next : n) {
      if (isPrime(primes[i] + next)) {
        twinPrime++;
        break;
      }
    }
  }
  printf("Prime Count: %d\n", index);
  printf("Twin Prime Count:%d\n", twinPrime);
}
/*


Output
Prime Count: 5761455
Twin Prime Count:440314
*/