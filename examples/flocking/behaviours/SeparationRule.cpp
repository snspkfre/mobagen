#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f separatingForce = Vector2f::zero();
  Vector2f pos = boid->getPosition();

  for (Boid* n : neighborhood)
  {
    Vector2f nPos = n->getPosition();
    Vector2f diff = pos - nPos;//difference between the current boid in the loop and boid
    float dist = diff.getMagnitude();
    if (dist > 0 && dist < desiredMinimalDistance)
    {
      separatingForce += diff.normalized() * ((desiredMinimalDistance / 2) / (dist));//inversly proportional to distance
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
