#include "args.h"
#include "instance.h"
#include "nearest_neighbor.h"
#include "solution.h"

int main(int argc, char *argv[])
{
    parseArguments(argc, argv);
    Instance inst = readInstance(instanceFileName);
    if (allHeuristics)
    {
    }
    else
    {
        if (selectedHeuristic == "nearest_neighbor")
        {
            Solution sol = solveNearestNeighbor(inst);
            if (verbose)
                cout << "Solution:" << endl;
                printSolution(sol);
        }
    }
    return 0;
}
