#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <string>

struct PhysicsBody {
 public:
  const char* name;
  double initVel, mass, dragConstant, area;

  PhysicsBody(const char* name, double initVel, double mass, double dragConstant, double area) {
    this->name = name;
    this->initVel = initVel;
    this->mass = mass;
    this->dragConstant = dragConstant;
    this->area = area;
  }
  PhysicsBody() {}
};

struct Environment {
 public:
  const char* name;
  double gravity, airDensity, temp;

  Environment(const char* name, double gravity, double airDensity, double temp) {
    this->name = name;
    this->gravity = gravity;
    this->airDensity = airDensity;
    this->temp = temp;
  }
  Environment() {}
};

const double dt = 0.001;
double temp(double y, double t) { return t - 0.0065 * y; }
double density(double y, const Environment& environment) { return environment.airDensity * pow(temp(y, environment.temp) / environment.temp, 5.2561 - 1.0); }

void shootCannon(const PhysicsBody& body, const Environment& environment, double angle, double& distanceTravelled, double& maxHeight, double& time) {
  double x = 0, y = 0;
  double radAngle = angle * M_PI / 180.0;
  double dx = body.initVel * cos(radAngle), dy = body.initVel * sin(radAngle);
  maxHeight = 0, time = 0;
  while (y >= 0) {
    x += dx * dt, y += dy * dt;
    maxHeight = std::max(maxHeight, y);

    double vel = sqrt(dx * dx + dy * dy);
    double drag = 0.5 * body.dragConstant * body.area * density(y, environment) * vel * vel / body.mass;
    dx += (-drag * dx / vel) * dt;

    dy += (-environment.gravity - drag * dy / vel) * dt;

    time += dt;
  }
  distanceTravelled = x;
}

int main() {
  PhysicsBody cannonBall = PhysicsBody("Cannonball", 250, 30, 0.45, 0.03);
  PhysicsBody human = PhysicsBody("Human", 33, 80, 0.45, 0.03);
  PhysicsBody tesla = PhysicsBody("Tesla", 50, 2270, 0.24, 0.7);

  Environment earth = Environment("Earth", 9.81, 1.225, 288.16);
  Environment mars = Environment("Mars", 3.711, 0.02, 210.372);
  Environment moon = Environment("Moon", 1.62, 0, 399.817);

  std::pair<PhysicsBody, Environment> parameters[4] = {std::make_pair(cannonBall, earth), std::make_pair(cannonBall, moon), std::make_pair(human, moon), std::make_pair(tesla, mars)};

  double endAngle = 90, dAngle = 15;
  const char* divider = "*****************************************************************\n";

  for (const auto& parameter : parameters) {
    PhysicsBody body;
    Environment environment;
    std::tie(body, environment) = parameter;

    printf("Projectile: %s on %s\n", body.name, environment.name);
    printf("%s", divider);
    printf("*   %s\t*   %s\t*   %s\t*   %s\t*\n", "angle", "dist", "height", "time");
    printf("%s", divider);

    for (double angle = dAngle; angle <= endAngle; angle += dAngle) {
      double distanceTravelled, maxHeight, time;
      shootCannon(body, environment, angle, distanceTravelled, maxHeight, time);
      printf("*   %.2f\t*   %.2f\t*   %.2f\t*   %.2f\t*\n", angle, distanceTravelled, maxHeight, time);
    }
    printf("%s\n", divider);
  }
}
/*

Question
Write a program that prints a table of the range of
the cannon as a function of the firing angle. Put
your function in a different file from main and
declare your function in a header file. Create a
Makefile to compile and link your code.

Output
Projectile: Cannonball on Earth
*****************************************************************
*   angle       *   dist        *   height      *   time        *
*****************************************************************
*   15.00       *   2084.54     *   168.66      *   11.68       *
*   30.00       *   2910.34     *   546.04      *   20.95       *
*   45.00       *   3026.25     *   1004.14     *   28.45       *
*   60.00       *   2539.14     *   1441.69     *   34.21       *
*   75.00       *   1488.88     *   1762.80     *   37.95       *
*   90.00       *   0.00        *   1883.04     *   39.27       *
*****************************************************************

Projectile: Cannonball on Moon
*****************************************************************
*   angle       *   dist        *   height      *   time        *
*****************************************************************
*   15.00       *   19290.50    *   1292.23     *   79.88       *
*   30.00       *   33411.69    *   4822.59     *   154.32      *
*   45.00       *   38580.45    *   9645.15     *   218.24      *
*   60.00       *   33411.63    *   14467.70    *   267.29      *
*   75.00       *   19290.24    *   17998.05    *   298.13      *
*   90.00       *   0.00        *   19290.25    *   308.64      *
*****************************************************************

Projectile: Human on Moon
*****************************************************************
*   angle       *   dist        *   height      *   time        *
*****************************************************************
*   15.00       *   336.16      *   22.52       *   10.55       *
*   30.00       *   582.21      *   84.04       *   20.37       *
*   45.00       *   672.27      *   168.07      *   28.81       *
*   60.00       *   582.19      *   252.10      *   35.28       *
*   75.00       *   336.12      *   313.61      *   39.35       *
*   90.00       *   0.00        *   336.13      *   40.74       *
*****************************************************************

Projectile: Tesla on Mars
*****************************************************************
*   angle       *   dist        *   height      *   time        *
*****************************************************************
*   15.00       *   336.87      *   22.57       *   6.98        *
*   30.00       *   583.31      *   84.21       *   13.47       *
*   45.00       *   673.47      *   168.40      *   19.05       *
*   60.00       *   583.20      *   252.59      *   23.34       *
*   75.00       *   336.72      *   314.22      *   26.03       *
*   90.00       *   0.00        *   336.78      *   26.95       *
*****************************************************************

*/