#ifndef SOLUTION_H
#define SOLUTION_H
#include "instance.h"
#include <iostream>
#include <vector>

using namespace std;

typedef struct sRoute
{
    vector<int> cities;
    float cost;
} Route;

typedef struct sSolution
{
    float totalCost;
    vector<Route> routes;
} Solution;

void printSolution(const Solution &sol);
void calculateCosts(Solution &sol, const Instance &inst);

#endif // SOLUTION_H