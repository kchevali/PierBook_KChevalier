#include <math.h>
#include <stdio.h>

const double mass = 80.0, dt = 0.0001, timeOfContact = 0.1;
double temp(double y) { return 288.16 - 0.0065 * y; }
double density(double y) { return 1.225 * pow(temp(y) / 288.16, 5.2561 - 1.0); }
double acc(double v, double y) { return -9.81 + 0.5 * density(y) * v * v / mass; }

void drop(double y, double& time, double& force, double& vel) {
  double t = 0, v = 0;
  while (y > 0) {
    double a = acc(v, y);
    y -= v * dt;
    v -= a * dt;
    t += dt;
  }
  vel = v;
  time = t;
  force = v / timeOfContact * mass;
}

int main() {
  double height = 1000, time, force, vel;
  drop(height, time, force, vel);
  printf("You dropped %fm in %fs with a\nfinal force of %fN and\nvelocity of %fm/s\n", height, time, force, vel);
}
/*


Output
You dropped 1000.000000m in 29.840000s with a
final force of 28727.172725N and
velocity of 35.908966m/s
*/