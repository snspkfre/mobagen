#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>
#include <vector>

using namespace std;

bool RecursiveBacktrackerExample::Step(World* w) {
  // todo: implement this
  if(!st.empty())
  {
    visited[st.back().x][st.back().y] = true;
    w->SetNodeColor(st.back(), Color::Red);
    vector<Point2D> neighbors = getVisitables(w, st.back());
   
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

    st.push_back(neighbor);

    return true;
  }
  else
  {
    st.push_back(randomStartPoint(w));
  }

  return false;
}

void RecursiveBacktrackerExample::Clear(World* world) {
  visited.clear();
  st.clear();
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

//this shit is BASED
std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  std::vector<Point2D> visitables;
  if (w->isValidPosition(p.Up()) && !visited[p.Up().x][p.Up().y]) visitables.push_back(p.Up());
  if (w->isValidPosition(p.Down()) && !visited[p.Down().x][p.Down().y]) visitables.push_back(p.Down());
  if (w->isValidPosition(p.Left()) && !visited[p.Left().x][p.Left().y]) visitables.push_back(p.Left());
  if (w->isValidPosition(p.Right()) && !visited[p.Right().x][p.Right().y]) visitables.push_back(p.Right());

  return visitables;
}
