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

void findMaxDistance(const PhysicsBody& body, const Environment& environment, double minHeight, double& angle, double& distanceTravelled, double& maxHeight, double& time) {
  double low = 0, high = 90, ESP = 0.001;
  shootCannon(body, environment, high, distanceTravelled, maxHeight, time);
  if (maxHeight < minHeight) {
    angle = 90;  // unable to meet min height
    return;
  }
  // binary search between low and high until |high - low| <= ESP
  while (fabs(high - low) > ESP) {
    angle = (low + high) / 2;
    shootCannon(body, environment, angle, distanceTravelled, maxHeight, time);
    if (maxHeight < minHeight || angle < 45) {
      low = angle;
    } else if (angle == 45) {
      return;
    } else {
      high = angle;
    }
  }
}

int main() {
  PhysicsBody cannonBall = PhysicsBody("Cannonball", 250, 30, 0.45, 0.03);
  PhysicsBody human = PhysicsBody("Human", 33, 80, 0.45, 0.03);
  PhysicsBody tesla = PhysicsBody("Tesla", 50, 2270, 0.24, 0.7);

  Environment earth = Environment("Earth", 9.81, 1.225, 288.16);
  Environment mars = Environment("Mars", 3.711, 0.02, 210.372);
  Environment moon = Environment("Moon", 1.62, 0, 399.817);

  std::pair<PhysicsBody, Environment> parameters[4] = {std::make_pair(cannonBall, earth), std::make_pair(cannonBall, moon), std::make_pair(human, moon), std::make_pair(tesla, mars)};

  double minHeight = 1200;
  const char* divider = "*****************************************************************\n";

  for (const auto& parameter : parameters) {
    PhysicsBody body;
    Environment environment;
    std::tie(body, environment) = parameter;

    double angle, maxHeight, distanceTravelled, time;
    findMaxDistance(body, environment, minHeight, angle, distanceTravelled, maxHeight, time);

    printf("Projectile: %s on %s\n", body.name, environment.name);
    if (angle == 90)
      printf("%s %lf\n\n", "Cannot reach min height - Max Height:", maxHeight);
    else
      printf("Angle: %lf Height:%lf Max Dist:%lf\n\n", angle, maxHeight, distanceTravelled);
  }
}
/*
Feedback
I would clarify the first part of this question. You are
asking to maximize the total distance travelled and the
maximum height, which you can't do directly. I
recommend rephrasing the question as what is the
maximum distance you can shoot that has a max height
above (or below) some value.

Question
Modify your function from Exercise 3.4 so that it returns
both the distance the cannonball traveled, and its
maximum height. Use this function in a program to figure
out the maximum height of a hill that you could fire over
if you wanted to hit a target at the maximum distance you
can reach. Suppose you wanted to fire over a hill that
was twice as large as that. What is the maximum range to
the target in this case?

Output
Projectile: Cannonball on Earth
Angle: 51.433182 Height:1199.992014 Max Dist:2889.008624

Projectile: Cannonball on Moon
Angle: 45.000000 Height:9645.150117 Max Dist:38580.453088

Projectile: Human on Moon
Cannot reach min height - Max Height: 336.127611

Projectile: Tesla on Mars
Cannot reach min height - Max Height: 336.778711
*/