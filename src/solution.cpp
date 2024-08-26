#include "solution.h"

void printSolution(const Solution &sol)
{
    cout << "Instance: " << sol.instanceName << endl
         << "Heuristic: " << sol.heuristicName << endl;
    for (const auto &route : sol.routes)
    {
        cout << "[ ";
        for (const auto &elem : route.cities)
        {
            cout << elem << " ";
        }
        cout << "] -> Cost = " << route.cost << endl;
    }
    cout << "Total cost = " << sol.totalCost << endl
         << "--------------------------------------------" << endl;
}

void calculateCosts(Solution &sol, const Instance &inst)
{
    sol.totalCost = 0;
    for (auto &route : sol.routes)
    {
        route.cost = 0;
        for (long unsigned int i = 0; i < route.cities.size() - 1; ++i)
        {
            route.cost += inst.distance[route.cities[i]][route.cities[i + 1]];
        }
        route.cost += inst.distance[route.cities.back()][route.cities.front()];
        sol.totalCost += route.cost;
    }
}

void saveSolution(const Solution &sol)
{
    string fileName = "results/" + sol.heuristicName + "/" + sol.instanceName + "_" + to_string(numSalesmen) + ".txt";
    ofstream arq(fileName);
    if (arq)
    {
        arq << numSalesmen << endl;
        arq << sol.totalCost << endl;
        for (const auto &route : sol.routes)
        {
            for (const auto &elem : route.cities)
            {
                arq << elem << " ";
            }
            arq << endl
                << route.cost << endl;
        }
        arq.close();
    }
    else
    {
        cerr << "Error trying to save results to file " << fileName << endl;
    }
}