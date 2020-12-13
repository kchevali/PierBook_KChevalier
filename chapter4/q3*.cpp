#include <math.h>
#include <stdio.h>

const int maxCount = 30;

void mandel_brot(double* x, double* y, double a, double b) {
  double x_ = *x * *x - *y * *y + a;
  *y = 2 * *x * *y + b;
  *x = x_;
}

// example of alternative pattern
void other(double* x, double* y, double a, double b) {
  double x_ = a * cos(*x) + *y;
  *y = 2 * *x * *y + b;
  *x = x_;
}

double run(double a, double b) {
  double x = 0, y = 0, i = 0, threshold = 4;
  while (++i < maxCount && x * x + y * y < threshold) {
    mandel_brot(&x, &y, a, b);
    // other(&x, &y, a, b);//example of alternative
  }
  // printf("A: %d, B: %d, X: %d Y: %d\n", a, b, x, y);
  return i / maxCount;
}

int main() {
  int length = 80, a = -2, b = 1, c = -1, d = 1;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      double first = a + (i / (double)length) * (b - a);
      double second = c + (j / (double)length) * (d - c);
      printf(run(first, second) > 0.5 ? "█" : " ");
    }
    printf("\n");
  }
}

/*
Feedback
I would recommend adding more content to this question. Maybe
you can suggest other patterns that they can draw since they
are modularizing the iteration step. I added a random example
that I created by trial and error: other(). See comment above.

Question
Rewrite your Mandelbrot function from Exercise 3.3 so that it
calls another function that computes a single Mandelbrot
iteration. This function should take x, y, a, and b as
arguments and returns the updated x and y. Hint: use pointers
to both pass in and return x and y. Modify your program from
Exercise 3.3 so that it writes the ASCII art picture of the
Mandelbrot set to a file.

Output
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                        █
                                  ██   ███   ██
                                     ███████
                                    █████████
                                     ███████
                          ██     ███████████████     ██
                           █     ███████████████     █
                            █████████████████████████
                            █████████████████████████
                             ███████████████████████
                             ███████████████████████
                         █ ███████████████████████████ █
                           ███████████████████████████
                             ███████████████████████
                             ███████████████████████
                              █████████████████████
                               ███████████████████
                                █████████████████
                                █████████████████
                          █ █████████████████████████ █
                      █  ███████████████████████████████  █
                     ███████████████████████████████████████
             █ █     ███████████████████████████████████████     █ █
              ██ ██ █████████████████████████████████████████ ██ ██
              █████████████████████████████████████████████████████
               ███████████████████████████████████████████████████
               ███████████████████████████████████████████████████
                █████████████████████████████████████████████████
             ███████████████████████████████████████████████████████
              █████████████████████████████████████████████████████
              █████████████████████████████████████████████████████
              █████████████████████████████████████████████████████
     ███████████████████████████████████████████████████████████████████████
      █████████████████████████████████████████████████████████████████████
    █████████████████████████████████████████████████████████████████████████
 █ ███████████████████████████████████████████████████████████████████████████ █
   ███████████████████████████████████████████████████████████████████████████
      █████████████████████████████████████████████████████████████████████
       ███████████████████████████████████████████████████████████████████
      █       █████████████████████████████████████████████████████       █
              █████████████████████████████████████████████████████
               ███████████████████████████████████████████████████
             ███████████████████████████████████████████████████████
                █████████████████████████████████████████████████
                  █████████████████████████████████████████████
               █ ███████████████████████████████████████████████ █
                ████████████████████████ ████████████████████████
                █████ █████████████████   █████████████████ █████
              ████ █   █ █████████████     █████████████ █   █ ████
                █        ████  ██ █           █ ██  ████        █
                         ███   ██               ██   ███

*/