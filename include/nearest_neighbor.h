#ifndef NEAREST_NEIGHBOR_H
#define NEAREST_NEIGHBOR_H

#include "instance.h"
#include "solution.h"
#include <float.h>
#include <vector>

using namespace std;

int findNearestNeighbor(const Instance &inst, const vector<bool> &visited, int currentCity);
Solution solveNearestNeighbor(const Instance &inst);

#endif // NEAREST_NEIGHBOR_H