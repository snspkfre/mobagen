#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce = Vector2f::zero();
  Vector2f pos = boid->getPosition();

  for (Boid* n : neighborhood)
  {
    if (n == boid) continue;
    cohesionForce += n->getPosition();
  }
  if (neighborhood.size() > 0)
  {
    cohesionForce /= neighborhood.size();
    cohesionForce -= pos;
  }

  return cohesionForce;
}