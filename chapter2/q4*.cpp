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
Feedback
I would recommend including a shortened free fall table,
either in the question or in an appendix. I also
recommend including a few test cases to help students
check their implementations. As a minor improvement, I
would recommend reorganizing these types of questions as
it takes a long time to search a paragraph for the constants
and the steps in the algorithm. Add a bullet list with the
algorithm steps and a constant table for easy lookup.

Question
If you jump out of an airplane without a parachute, how long
do you have to live? In high school physics class when you
compute the motion of a falling body, you neglect air
resistance. This is because you can’t compute the motion of
a body with air resistance analyti- cally. Lucky for you, it
is easy to compute numerically using a computer.
Here is how you do it. If y is the height of an object above
the ground, and v is its velocity, then Δt seconds later, its
position will be y + vΔt, and its velocity will be v + aΔt,
where a is the acceleration. You can compute the acceleration
as a = −g + 12CDAρv2/m, where g = 9.81 m/s2 is the acceleration
of gravity, CD is the drag coefficient (roughly 1 for a person),
A is the area of the object (roughly 1 m2 for a person), ρ is
the density of air, which is around 1.2 kg/m3, and m is the
mass of the object (around 80 kg for a person).
Start with y = 1000m and v = 0m/s and iterate until you hit the
ground (y ≤ 0m). How many seconds did that take? Look up a
skydiving free fall time table and see how closely you agree.

Output
You dropped 1000.000000m in 29.840000s with a
final force of 28727.172725N and
velocity of 35.908966m/s
*/