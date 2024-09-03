#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce = Vector2f::zero();
  
  // todo: add your code here to make a force towards the center of mass
  // hint: iterate over the neighborhood

  // find center of mass

  Vector2f pos = boid->getPosition();

  for (Boid* n : neighborhood)
  {
    if (n == boid) continue;
    cohesionForce += n->getPosition() - pos;
  }
  if (neighborhood.size() > 0)
  cohesionForce /= neighborhood.size();
  
  return cohesionForce;
}