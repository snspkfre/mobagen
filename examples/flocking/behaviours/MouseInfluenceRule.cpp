#include "MouseInfluenceRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f MouseInfluenceRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
      ImGuiIO& io = ImGui::GetIO();
      if (ImGui::IsMousePosValid() && io.MouseDown[0]) {
          Vector2f mousePos(io.MousePos.x, io.MousePos.y);
          Vector2f displacement = mousePos - boid->getPosition();
          //float distance = displacement.getMagnitude();

          Vector2f force = displacement.normalized();//universal strength of force
  
          if (isRepulsive)
              force *= -1.f;
  
          return force;
      }
      else
          return Vector2f::zero();
  return Vector2f::zero();
}

bool MouseInfluenceRule::drawImguiRuleExtra() {
  bool valueHasChanged = false;

  if (ImGui::RadioButton("Attractive", !isRepulsive)) {
    isRepulsive = false;
    valueHasChanged = true;
  }

  ImGui::SameLine();
  if (ImGui::RadioButton("Repulsive", isRepulsive)) {
    isRepulsive = true;
    valueHasChanged = true;
  }

  return valueHasChanged;
}