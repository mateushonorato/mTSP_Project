#include "args.h"
#include "instance.h"
#include "nearest_neighbor.h"
#include "random_heuristic.h"
#include "solution.h"

using namespace std;

int main(int argc, char *argv[])
{
    parseArguments(argc, argv);
    vector<Instance> instances = readInstances();
    for (Instance inst : instances)
    {
        if (checkNumSalesmen(inst))
        {
            continue;
        }
        if (selectedHeuristic == "nearest_neighbor" || allHeuristics)
        {
            Solution sol = solveNearestNeighbor(inst);
            calculateCosts(sol, inst);
            saveSolution(sol);
            if (verbose)
            {
                printSolution(sol);
            }
        }
        if (selectedHeuristic == "random_heuristic" || allHeuristics)
        {
            Solution sol = solveRandomHeuristic(inst);
            calculateCosts(sol, inst);
            saveSolution(sol);
            if (verbose)
            {
                printSolution(sol);
            }
        }
    }
    return 0;
}
