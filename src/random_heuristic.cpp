#include "random_heuristic.h"

Solution solveRandomHeuristic(const Instance &inst)
{

    random_device rd;
    mt19937 mt(rd());
    Solution sol;
    sol.heuristicName = "random_heuristic";
    sol.instanceName = inst.name;
    vector<bool> visited(inst.size, false);
    sol.routes.resize(numSalesmen);
    int currentCity = mt() % inst.size;
    visited[currentCity] = true;
    sol.routes[0].cities.push_back(currentCity);
    int visitedCities = 1;
    while (visitedCities < inst.size)
    {
        for (int i = 0; i < numSalesmen; i++)
        {
            int nextCity = mt() % inst.size;
            while (visited[nextCity])
            {
                nextCity = mt() % inst.size;
            }
            visited[nextCity] = true;
            sol.routes[i].cities.push_back(nextCity);
            visitedCities++;
        }
    }
    return sol;
}