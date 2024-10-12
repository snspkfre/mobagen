#include "Agent.h"
#include <queue>
#include "World.h"
using namespace std;

std::vector<Point2D> Agent::generatePath(World* w) {
  unordered_map<Point2D, Point2D> cameFrom;  // to build the flowfield and build the path
  priority_queue<Point2D> frontier;                   // to store next ones to visit
  unordered_set<Point2D> frontierSet;        // OPTIMIZATION to check faster if a point is in the queue
  unordered_map<Point2D, bool> visited;      // use .at() to get data, if the element dont exist [] will give you wrong results

  // bootstrap state
  auto catPos = w->getCat();
  frontier.push(catPos);
  frontierSet.insert(catPos);
  Point2D borderExit = Point2D::INFINITE;  // if at the end of the loop we dont find a border, we have to return random points

  while (!frontierSet.empty()) {
    Point2D current = frontier.front();
    frontier.pop();
    frontierSet.erase(current);
    visited[current] = true;
    vector<Point2D> neighbors = getVisitableNeightbors(w, current, visited, frontierSet);

    if(w->catWinsOnSpace(current)) {
      vector<Point2D> returnValue;
      Point2D cur = current;
      while(cameFrom[cur] != catPos) {
        returnValue.push_back(cur);
        cur = cameFrom[cur];
      }
      returnValue.push_back(cur);

      for(Point2D n : returnValue) {
        cout << n.x << "," << n.y << endl;
      }
      return returnValue;
    }

    for(Point2D next : neighbors)
    {
      if(cameFrom.find(next) == cameFrom.end()) {
        frontier.push(next);
        frontierSet.insert(next);
        cameFrom[next] = current;
      }
    }
  }



  // if the border is not infinity, build the path from border to the cat using the camefrom map
  // if there isnt a reachable border, just return empty vector
  // if your vector is filled from the border to the cat, the first element is the catcher move, and the last element is the cat move
  return vector<Point2D>();
}

vector<Point2D> Agent::getVisitableNeightbors(World* w, Point2D p, unordered_map<Point2D, bool> visited, unordered_set<Point2D> frontierSet)
{
  vector<Point2D> neighbors, temp;
  temp = w->neighbors(p);
  for(Point2D p : temp)
  {
    if(w->catcherCanMoveToPosition(p) && !w->getContent(p) && frontierSet.find(p) == frontierSet.end()) neighbors.push_back(p);
  }

  return neighbors;
}