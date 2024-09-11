#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {
  // todo: implement
  Point2D current;
  for (int y = 0; y < world.SideSize(); y++)
  {
    for (int x = 0; x < world.SideSize(); x++)
    {
      current = Point2D(x, y);
      int count = CountNeighbors(world, current);
      if (world.Get(current)) {
        if (count < 2 || count > 3)
          world.SetNext(current, false);
        else
          world.SetNext(current, true);
      } else if (count == 3) {
        world.SetNext(current, true);
      } else {
        world.SetNext(current, false);
      }
    }
  }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
  // todo: implement
  int sum = 0;
  sum += world.Get(point + point.UP) ? 1 : 0;
  sum += world.Get(point + point.LEFT) ? 1 : 0;
  sum += world.Get(point + point.DOWN) ? 1 : 0;
  sum += world.Get(point + point.RIGHT) ? 1 : 0;
  sum += world.Get(point + point.UP + point.LEFT) ? 1 : 0;
  sum += world.Get(point + point.LEFT + point.DOWN) ? 1 : 0;
  sum += world.Get(point + point.DOWN + point.RIGHT) ? 1 : 0;
  sum += world.Get(point + point.RIGHT + point.UP) ? 1 : 0;
  return sum;
}
