#include "args.h"

string instanceFileName;
string selectedHeuristic;
bool verbose = false;

void parseArguments(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "Usage: " << argv[0] << " <instance_file> <heuristic> [-v]" << endl;
        exit(EXIT_FAILURE);
    }

    instanceFileName = argv[1];
    selectedHeuristic = argv[2];

    if (argc == 4 && string(argv[3]) == "-v")
    {
        verbose = true;
    }
}