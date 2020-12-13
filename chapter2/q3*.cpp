#include <stdio.h>
int maxCount = 30;

void run(double a, double b) {
  double x = 0, y = 0, i = 0, threshold = 4;
  while (++i < maxCount && x * x + y * y < threshold) {
    double x_ = x * x - y * y + a;
    y = 2 * x * y + b;
    x = x_;
  }
  // printf("A: %d, B: %d, X: %d Y: %d\n", a, b, x, y);
  printf("%f %f go to: %f\n", a, b, x * x + y * y);
}

int main() {
  run(1, 1);
  run(10, 10);
}
/*
Feedback
This problem is interesting, but I have some
recommendations for improvement. First, I would describe
the mandelbrot set a bit more and a picture would nice,
since if the reader never heard of this set then it might
seem too abstract. Also the excercise is a little vague and
it [[would be better if you can give the reader more
direction. For example, I would give specific directions
like what would the algorithm output if x = 1 and y = 1
after 4 iterations? Second, I would provide some test
cases to help the student check if they implemented their
algorithm correctly.

Question
Write a program that performs the Mandelbrot iteration.
Try different values of a and b and see what happens.
Is there some value of x and y beyond which you can be
confident the iteration will eventually go to infinity.
What different kinds of behavior do x and y exhibit
when they do not go to infinity?

Output
1.000000 1.000000 go to: 10.000000
10.000000 10.000000 go to: 200.000000


*/