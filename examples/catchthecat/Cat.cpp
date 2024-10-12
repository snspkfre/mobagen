#include "Cat.h"
#include "World.h"
#include <vector>
#include <stdexcept>

using namespace std;

Point2D Cat::Move(World* world) {
  vector<Point2D> path = generatePath(world);
  if(path.size() > 0)
    return path.back();

  auto rand = Random::Range(0, 5);
  auto pos = world->getCat();
  switch (rand) {
    case 0:
      return World::NE(pos);
    case 1:
      return World::NW(pos);
    case 2:
      return World::E(pos);
    case 3:
      return World::W(pos);
    case 4:
      return World::SW(pos);
    case 5:
      return World::SE(pos);
    default:
      throw "random out of range";
  }
}
