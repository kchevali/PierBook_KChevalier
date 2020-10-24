#include <stdio.h>

int main() {
  printf("char:  %lu\n", sizeof(char));
  printf("short: %lu\n", sizeof(short));
  printf("int:   %lu\n", sizeof(int));
  printf("long:  %lu\n", sizeof(long));
}
/*
Write a C++ program that determine show many bytes are used
to store char, short, int, and long variables on your
operating system. Compare with your classmates. Did they
get the same results?

Output

char:  1
short: 2
int:   4
long:  8
*/