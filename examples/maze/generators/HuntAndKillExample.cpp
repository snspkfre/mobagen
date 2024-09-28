#include "HuntAndKillExample.h"
#include "../World.h"
#include "Random.h"
#include <climits>
bool HuntAndKillExample::Step(World* w) {
  // todo: code this
  Point2D current;
  for (int y = 0; y < w->GetSize(); y++)
  {
    for (int x = 0; x < w->GetSize(); x++)
    {
      current = Point2D(x, y);
      std::vector<Point2D> neighbors = getVisitables(w, current);


    }
  }

  return false;
}
void HuntAndKillExample::Clear(World* world) {
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}
Point2D HuntAndKillExample::randomStartPoint(World* world) {
  // Todo: improve this if you want
  auto sideOver2 = world->GetSize() / 2;

  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> HuntAndKillExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;
  if (p.y > 0 && w->GetNorth(p)) visitables.push_back(Point2D(p.x, p.y - 1));
  if (p.x < w->GetSize() - 1 && w->GetSouth(p)) visitables.push_back(Point2D(p.x, p.y + 1));
  if (p.x > 0 && w->GetWest(p)) visitables.push_back(Point2D(p.x - 1, p.y));
  if (p.y < w->GetSize() - 1 && w->GetEast(p)) visitables.push_back(Point2D(p.x + 1, p.y));
  // todo: code this

  return visitables;
}
std::vector<Point2D> HuntAndKillExample::getVisitedNeighbors(World* w, const Point2D& p) {
  std::vector<Point2D> deltas = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> neighbors;

  if (p.y > 0 && !w->GetNorth(p)) neighbors.push_back(Point2D(p.x, p.y - 1));
  if (p.x < !w->GetSize() - 1 && w->GetSouth(p)) neighbors.push_back(Point2D(p.x, p.y + 1));
  if (p.x > 0 && !w->GetWest(p)) neighbors.push_back(Point2D(p.x - 1, p.y));
  if (p.y < !w->GetSize() - 1 && w->GetEast(p)) neighbors.push_back(Point2D(p.x + 1, p.y));
  // todo: code this

  return neighbors;
}
