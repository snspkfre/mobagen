#ifndef AGENT_H
#define AGENT_H
#include "math/Point2D.h"
#include <vector>
#include <unordered_set>
#include <unordered_map>

class World;

class Agent {
public:
  explicit Agent() = default;

  virtual Point2D Move(World*) = 0;

  std::vector<Point2D> generatePath(World* w);

  std::vector<Point2D> getVisitableNeightbors(World* w, Point2D p, std::unordered_map<Point2D, bool> visited, std::unordered_set<Point2D> frontierSet);
};

#endif  // AGENT_H
