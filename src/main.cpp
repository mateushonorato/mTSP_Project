#include "args.h"
#include "instance.h"
#include "nearest_neighbor.h"
#include "random_heuristic.h"
#include "solution.h"
#include <filesystem>

using namespace std;

int main(int argc, char *argv[])
{
    parseArguments(argc, argv);
    vector<Instance> instances;
    if (!allInstances)
    {
        Instance inst = readInstance(instanceFileName);
        instances.push_back(inst);
    }
    else
    {
        for (const auto &entry : filesystem::directory_iterator("instances"))
        {
            if (entry.is_regular_file())
            {
                Instance inst = readInstance(entry.path().string());
                instances.push_back(inst);
            }
        }
    }
    for (Instance inst : instances)
    {
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
