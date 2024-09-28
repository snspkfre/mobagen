#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>
#include <vector>

using namespace std;

bool RecursiveBacktrackerExample::Step(World* w) {
  // todo: implement this
  /*Point2D current;

  for (int y = 0; y < w->GetSize(); y++)
  {
    for (int x = 0; x <  w->GetSize(); x++)
    {
      current = Point2D(x, y);
      Point2D other;
      vector<Point2D> visitables = getVisitables(w, current);
      if (visitables.size() == 1)
      {
        other = visitables.front();
      }
      else if (!visitables.empty())
      {
        //other =
      }
    }
  }

  return false;*/
}

void RecursiveBacktrackerExample::Clear(World* world) {
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}

Point2D RecursiveBacktrackerExample::randomStartPoint(World* world) {
  auto sideOver2 = world->GetSize() / 2;

  // todo: change this if you want
  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;
  if (p.y > 0 && w->GetNorth(p)) visitables.push_back(p.Up());
  if (p.x < w->GetSize() - 1 && w->GetSouth(p)) visitables.push_back(p.Down());
  if (p.x > 0 && w->GetWest(p)) visitables.push_back(p.Left());
  if (p.y < w->GetSize() - 1 && w->GetEast(p)) visitables.push_back(p.Right());

  return visitables;
}
