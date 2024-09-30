#include "HuntAndKillExample.h"
#include "../World.h"
#include "Random.h"
#include <climits>
#include <vector>

using namespace std;

bool HuntAndKillExample::Step(World* w) {
  // todo: code this
  if(st.empty()) {
    st.push_back(randomStartPoint(w));
    w->SetNodeColor(st.back(), Color::Gray);
    vector<Point2D> neighbors = getVisitablesReturning(w, st.back());
    if(neighbors.empty()) {
      w->SetNodeColor(st.back(), Color::Black);
      st.pop_back();
      return true;
    }
    Point2D neighbor = neighbors.front();
    if(neighbors.size() != 1)
    {
      Random random;
      neighbor = neighbors[random.Range(0, neighbors.size() - 1)];
    }

    if(neighbor == st.back().Right())
    {
      w->SetEast(st.back(), false);
      w->SetWest(st.back().Right(), false);
    }
    else if(neighbor == st.back().Up())
    {
      w->SetNorth(st.back(), false);
      w->SetSouth(st.back().Up(), false);
    }
    else if(neighbor == st.back().Down())
    {
      w->SetSouth(st.back(), false);
      w->SetNorth(st.back().Down(), false);
    }
    else
    {
      w->SetWest(st.back(), false);
      w->SetEast(st.back().Left(), false);
    }

    st.pop_back();
    st.push_back(neighbor);

    return true;

  }
  else {
    visited[st.back().x][st.back().y] = true;
    vector<Point2D> neighbors = getVisitables(w, st.back());
    w->SetNodeColor(st.back(), Color::Gray);

    if(neighbors.empty()) {
      w->SetNodeColor(st.back(), Color::Black);
      st.pop_back();
      return true;
    }
    Point2D neighbor = neighbors.front();
    if(neighbors.size() != 1)
    {
      Random random;
      neighbor = neighbors[random.Range(0, neighbors.size() - 1)];
    }

    if(neighbor == st.back().Right())
    {
      w->SetEast(st.back(), false);
      w->SetWest(st.back().Right(), false);
    }
    else if(neighbor == st.back().Up())
    {
      w->SetNorth(st.back(), false);
      w->SetSouth(st.back().Up(), false);
    }
    else if(neighbor == st.back().Down())
    {
      w->SetSouth(st.back(), false);
      w->SetNorth(st.back().Down(), false);
    }
    else
    {
      w->SetWest(st.back(), false);
      w->SetEast(st.back().Left(), false);
    }

    st.pop_back();
    st.push_back(neighbor);

    return true;
  }

  return false;
}

void HuntAndKillExample::Clear(World* world) {
  visited.clear();
  st.clear();
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
      if (!visited[y][x])
        return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> HuntAndKillExample::getVisitables(World* w, const Point2D& p) {
  std::vector<Point2D> visitables;
  if (w->isValidPosition(p.Up()) && !visited[p.Up().x][p.Up().y]) visitables.push_back(p.Up());
  if (w->isValidPosition(p.Down()) && !visited[p.Down().x][p.Down().y]) visitables.push_back(p.Down());
  if (w->isValidPosition(p.Left()) && !visited[p.Left().x][p.Left().y]) visitables.push_back(p.Left());
  if (w->isValidPosition(p.Right()) && !visited[p.Right().x][p.Right().y]) visitables.push_back(p.Right());

  return visitables;
}

std::vector<Point2D> HuntAndKillExample::getVisitablesReturning(World* w, const Point2D& p) {
  std::vector<Point2D> visitables;
  if (w->isValidPosition(p.Up())) visitables.push_back(p.Up());
  if (w->isValidPosition(p.Down())) visitables.push_back(p.Down());
  if (w->isValidPosition(p.Left())) visitables.push_back(p.Left());
  if (w->isValidPosition(p.Right())) visitables.push_back(p.Right());

  return visitables;
}

std::vector<Point2D> HuntAndKillExample::getVisitedNeighbors(World* w, const Point2D& p) {
  std::vector<Point2D> visitedNeighbors;
  if (w->isValidPosition(p.Up()) && visited[p.Up().x][p.Up().y]) visitedNeighbors.push_back(p.Up());
  if (w->isValidPosition(p.Down()) && visited[p.Down().x][p.Down().y]) visitedNeighbors.push_back(p.Down());
  if (w->isValidPosition(p.Left()) && visited[p.Left().x][p.Left().y]) visitedNeighbors.push_back(p.Left());
  if (w->isValidPosition(p.Right()) && visited[p.Right().x][p.Right().y]) visitedNeighbors.push_back(p.Right());

  return visitedNeighbors;
}
