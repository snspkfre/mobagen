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
      if (world.Get(current)) {
        if (count != 2)
          world.SetNext(current, false);
        else
          world.SetNext(current, true);
      } else if (count == 2) {
        world.SetNext(current, true);
      } else {
        world.SetNext(current, false);
      }
    }
  }
}
int HexagonGameOfLife::CountNeighbors(World& world, Point2D point)
{
  int sum = 0;
  if (point.y == 0)
  {
    //top edge
    sum += world.Get(point + point.UP) ? 1 : 0;
    sum += world.Get(point + point.UP + point.RIGHT) ? 1 : 0;
    sum += world.Get(point + point.RIGHT) ? 1 : 0;
    sum += world.Get(point + point.LEFT) ? 1 : 0;
  }
  else if (point.y == world.SideSize() - 1)
  {
    //bottom edge
    if (point.y % 2 == 1)
    {//even bottom edge
      sum += world.Get(point + point.DOWN) ? 1 : 0;
      sum += world.Get(point + point.DOWN + point.RIGHT) ? 1 : 0;
    }
    else
    {//odd bottom edge
      sum += world.Get(point + point.DOWN) ? 1 : 0;
      sum += world.Get(point + point.DOWN + point.LEFT) ? 1 : 0;
    }
    sum += world.Get(point + point.RIGHT) ? 1 : 0;
    sum += world.Get(point + point.LEFT) ? 1 : 0;
  }
  else
  {
    if (point.y % 2 == 0)
    {
      //even
      sum += world.Get(point + point.UP) ? 1 : 0;
      sum += world.Get(point + point.UP + point.LEFT) ? 1 : 0;
      sum += world.Get(point + point.RIGHT) ? 1 : 0;
      sum += world.Get(point + point.LEFT) ? 1 : 0;
      sum += world.Get(point + point.DOWN) ? 1 : 0;
      sum += world.Get(point + point.DOWN + point.LEFT) ? 1 : 0;
    }
    else
    {
      //odd
      sum += world.Get(point + point.UP) ? 1 : 0;
      sum += world.Get(point + point.UP + point.RIGHT) ? 1 : 0;
      sum += world.Get(point + point.RIGHT) ? 1 : 0;
      sum += world.Get(point + point.LEFT) ? 1 : 0;
      sum += world.Get(point + point.DOWN) ? 1 : 0;
      sum += world.Get(point + point.DOWN + point.RIGHT) ? 1 : 0;
    }
  }
  return sum;
}
