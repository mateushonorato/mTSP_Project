#include "args.h"

string instanceFileName;
string selectedHeuristic;
bool verbose = false;
int numSalesmen;
bool allHeuristics = false;
bool allInstances = false;

Arguments resolveArgument(string arg)
{
    if (arg == "--instance" || arg == "-i")
    {
        return INSTANCE_FILE;
    }
    else if (arg == "--heuristic" || arg == "-h")
    {
        return HEURISTIC;
    }
    else if (arg == "--num-salesmen" || arg == "-n")
    {
        return NUM_SALESMEN;
    }
    else if (arg == "--all-heuristics" || arg == "-ah")
    {
        return RUN_ALL_HEURISTICS;
    }
    else if (arg == "--all-instances" || arg == "-ai")
    {
        return RUN_ALL_INSTANCES;
    }
    else if (arg == "--verbose" || arg == "-v")
    {
        return VERBOSE;
    }
    else
    {
        return HELP_MESSAGE;
    }
}

void helpMessage(string programName)
{
    cout << "Usage: " + programName + " -i <instance_file> -h <heuristic> -n <num_salesmen>" << endl;
    cout << "Options:" << endl;
    cout << "  --instance, -i: Instance file" << endl;
    cout << "  --heuristic, -h: Heuristic to be used" << endl;
    cout << "  --num-salesmen, -n: Number of salesmen" << endl;
    cout << "  --all-heuristics, -ah: Run all heuristics" << endl;
    cout << "  --all-instances, -ai: Run all instances" << endl;
    cout << "  --verbose, -v: Print detailed output" << endl;
    exit(EXIT_FAILURE);
}

void parseArguments(int argc, char *argv[])
{
    if (argc < 3)
    {
        helpMessage(argv[0]);
    }

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        switch (resolveArgument(arg))
        {
        case INSTANCE_FILE:
            instanceFileName = argv[++i];
            break;
        case HEURISTIC:
            selectedHeuristic = argv[++i];
            break;
        case NUM_SALESMEN:
            if(i + 1 >= argc) {
                cerr << "Error: Number of salesmen must be specified." << endl;
                helpMessage(argv[0]);
            }
            numSalesmen = atoi(argv[++i]);
            break;
        case RUN_ALL_HEURISTICS:
            allHeuristics = true;
            break;
        case RUN_ALL_INSTANCES:
            allInstances = true;
            break;
        case VERBOSE:
            verbose = true;
            break;
        case HELP_MESSAGE:
            helpMessage(argv[0]);
            break;
        default:
            helpMessage(argv[0]);
            break;
        }
    }

    if (!allHeuristics && selectedHeuristic.empty())
    {
        cerr << "Error: Heuristic must be specified unless --all-heuristics is used." << endl;
        helpMessage(argv[0]);
    }

    if (!allInstances && instanceFileName.empty())
    {
        cerr << "Error: Instance file must be specified unless --all-instances is used." << endl;
        helpMessage(argv[0]);
    }

    if (numSalesmen == 0)
    {
        cerr << "Error: Number of salesmen must be specified." << endl;
        helpMessage(argv[0]);
    }
}