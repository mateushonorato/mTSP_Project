#ifndef SOLUTION_H
#define SOLUTION_H
#include "args.h"
#include "instance.h"
#include <iostream>
#include <vector>

using namespace std;

typedef struct sRoute
{
    vector<int> cities;
    float cost = 0;
} Route;

typedef struct sSolution
{
    string heuristicName;
    string instanceName;
    float totalCost = 0;
    vector<Route> routes;
} Solution;

void printSolution(const Solution &sol);
void calculateCosts(Solution &sol, const Instance &inst);
void saveSolution(const Solution &sol);

#endif // SOLUTION_H