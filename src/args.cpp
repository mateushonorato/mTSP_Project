#include "args.h"

string instanceFileName;
string selectedHeuristic;
bool verbose = false;
int numSalesmen;
bool allHeuristics = false;
bool allInstances = false;

void parseArguments(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <instance_file> <heuristic> <num_salesmen> [--all-heuristics] [--all-instances] [-v]" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        if (arg == "-v")
        {
            verbose = true;
        }
        else if (arg == "--all-heuristics")
        {
            allHeuristics = true;
        }
        else if (arg == "--all-instances")
        {
            allInstances = true;
        }
        else if (instanceFileName.empty())
        {
            instanceFileName = arg;
        }
        else if (selectedHeuristic.empty())
        {
            selectedHeuristic = arg;
        }
        else if (numSalesmen == 0)
        {
            numSalesmen = atoi(arg.c_str());
        }
    }

    if (!allHeuristics && selectedHeuristic.empty())
    {
        cerr << "Error: Heuristic must be specified unless --all-heuristics is used." << endl;
        exit(EXIT_FAILURE);
    }

    if (!allInstances && instanceFileName.empty())
    {
        cerr << "Error: Instance file must be specified unless --all-instances is used." << endl;
        exit(EXIT_FAILURE);
    }

    if (numSalesmen == 0)
    {
        cerr << "Error: Number of salesmen must be specified." << endl;
        exit(EXIT_FAILURE);
    }
}