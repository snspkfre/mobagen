#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to avoid boids too close
  Vector2f separatingForce = Vector2f::zero();
  Vector2f pos = boid->getPosition();

  for (Boid* n : neighborhood)
  {
    Vector2f nPos = n->getPosition();
    Vector2f diff = pos - nPos;
    float dist = diff.getMagnitude();
    if (dist > 0 && dist < desiredMinimalDistance)
    {
      separatingForce += diff.normalized() * ((desiredMinimalDistance / 2) / (dist));
    }
  }

  return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
  bool valusHasChanged = false;

  if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
    valusHasChanged = true;
  }

  return valusHasChanged;
}
