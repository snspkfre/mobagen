#include "Catcher.h"
#include "World.h"
#include <vector>

using namespace std;

Point2D Catcher::Move(World* world) {
  vector<Point2D> path = generatePath(world);
  if(path.size() > 0)
    return path.front();

  auto side = world->getWorldSideSize() / 2;

  for (;;) {
    Point2D p = {Random::Range(-side, side), Random::Range(-side, side)};
    auto cat = world->getCat();
    if (cat.x != p.x && cat.y != p.y && !world->getContent(p)) return p;
  }
}
