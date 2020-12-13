#include <signal.h>
#include <stdio.h>
void (*signal(int signum, void (*sighandler)(int)))(int);
void clean_exit_on_sig(int sig_num) { printf("\n Signal %d received", sig_num); }

void getCallStack(int x) {
  int a, b, c, d, e, f, g;
  printf("%d\n", x);
  getCallStack(++x);
}

int main() { getCallStack(1); }
/*
Question
How big is your call stack? Write a recursive function
that counts the number of times it has been called.
The function should take an integer argument, print
that value, increment it and call itself with the
incremented value. Write a program that calls this
function with an argument of 1. Put your function in
a different file from main and declare your function
in a header file. Create a Makefile to compile and link
your code. How many layers of recursion can you do?
What happens when you reach the limit? How do your
results compare with those of your classmates?

Output

*/