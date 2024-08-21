#include "solution.h"

void printSolution(const Solution &sol)
{
    for (const auto &route : sol.routes)
    {
        cout << "[ ";
        for (const auto &elem : route.cities)
        {
            cout << elem << " ";
        }
        cout << "] -> Cost = " << route.cost << endl;
    }
    cout << "Total cost = " << sol.totalCost << endl;
}

void calculateCosts(Solution &sol, const Instance &inst)
{
    sol.totalCost = 0;
    for (auto &route : sol.routes)
    {
        route.cost = 0;
        for (int i = 0; i < route.cities.size() - 1; ++i)
        {
            route.cost += inst.distance[route.cities[i]][route.cities[i + 1]];
        }
        route.cost += inst.distance[route.cities.back()][route.cities.front()];
        sol.totalCost += route.cost;
    }
}