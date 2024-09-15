//
// Created by atolstenko on 2/9/2023.
//

#include "HexagonGameOfLife.h"
void HexagonGameOfLife::Step(World& world)
{
  Point2D current;
  for (int y = 0; y < world.SideSize(); y++) {
    for (int x = 0; x < world.SideSize(); x++) {
      current = Point2D(x, y);
      int count = CountNeighbors(world, current);
        if (count != 2)
          world.SetNext(current, false);
        else
          world.SetNext(current, true);
    }
  }
}
int HexagonGameOfLife::CountNeighbors(World& world, Point2D point)
{
  int sum = 0;

  if (point.y % 2 == 0) {
    // even
    if(point.y > 0) sum += world.Get(point + point.UP) ? 1 : 0;
    if (point.y > 0 && point.x > 0) sum += world.Get(point + point.UP + point.LEFT) ? 1 : 0;
    if (point.x < world.SideSize() - 1) sum += world.Get(point + point.RIGHT) ? 1 : 0;
    if (point.x > 0) sum += world.Get(point + point.LEFT) ? 1 : 0;
    if (point.y < world.SideSize() - 1) sum += world.Get(point + point.DOWN) ? 1 : 0;
    if (point.y < world.SideSize() - 1 && point.x > 0) sum += world.Get(point + point.DOWN + point.LEFT) ? 1 : 0;
  } else {
    // odd
    if (point.y > 0) sum += world.Get(point + point.UP) ? 1 : 0;
    if (point.y > 0 && point.x < world.SideSize() - 1) sum += world.Get(point + point.UP + point.RIGHT) ? 1 : 0;
    if (point.x < world.SideSize() - 1) sum += world.Get(point + point.RIGHT) ? 1 : 0;
    if (point.x > 0) sum += world.Get(point + point.LEFT) ? 1 : 0;
    if (point.y < world.SideSize() - 1) sum += world.Get(point + point.DOWN) ? 1 : 0;
    if (point.y < world.SideSize() - 1 && point.x < world.SideSize() - 1) sum += world.Get(point + point.DOWN + point.RIGHT) ? 1 : 0;
  }

  return sum;
}
