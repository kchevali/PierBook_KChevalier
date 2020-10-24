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


Output

*/