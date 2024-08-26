#include "nearest_neighbor.h"

int findNearestNeighbor(const Instance &inst, const vector<bool> &visited, int currentCity)
{
    int nearestCity = -1;
    float minDistance = FLT_MAX;

    for (int city = 0; city < inst.size; ++city)
    {
        if (!visited[city] && inst.distance[currentCity][city] < minDistance)
        {
            minDistance = inst.distance[currentCity][city];
            nearestCity = city;
        }
    }

    return nearestCity;
}

Solution solveNearestNeighbor(const Instance &inst)
{
    Solution sol;
    sol.heuristicName = "nearest_neighbor";
    sol.instanceName = inst.name;
    vector<bool> visited(inst.size, false);
    sol.routes.resize(numSalesmen);

    for (int salesman = 0; salesman < numSalesmen; ++salesman)
    {
        int currentCity = salesman % inst.size; // Start each salesman at a different city
        sol.routes[salesman].cities.push_back(currentCity);
        visited[currentCity] = true;

        for (int step = 1; step < inst.size / numSalesmen; ++step)
        {
            int nextCity = findNearestNeighbor(inst, visited, currentCity);
            if (nextCity == -1)
                break;

            sol.routes[salesman].cities.push_back(nextCity);
            visited[nextCity] = true;
            currentCity = nextCity;
        }
    }

    return sol;
}