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

void helpMessage(string programName, string errorMessage)
{
    if (!errorMessage.empty())
    {
        cerr << "Error: " << errorMessage << endl;
    }
    cout << "Usage: " + programName + " -i <instance_file> -h <heuristic> -n <num_salesmen>" << endl
         << "Options:" << endl
         << "  --instance, -i: Instance file" << endl
         << "  --heuristic, -h: Heuristic to be used" << endl
         << "  --num-salesmen, -n: Number of salesmen" << endl
         << "  --all-heuristics, -ah: Run all heuristics" << endl
         << "  --all-instances, -ai: Run all instances" << endl
         << "  --verbose, -v: Print detailed output" << endl;
    exit(EXIT_FAILURE);
}

void parseArguments(int argc, char *argv[])
{
    if (argc < 3)
    {
        helpMessage(argv[0], "");
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
            if (i + 1 >= argc)
            {
                helpMessage(argv[0], "Number of salesmen must be specified.");
            }
            if (!isdigit(*argv[i + 1]))
            {
                helpMessage(argv[0], "Number of salesmen must be an integer.");
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
            helpMessage(argv[0], "");
            break;
        default:
            helpMessage(argv[0], "Invalid argument.");
            break;
        }
    }

    if (!allHeuristics && selectedHeuristic.empty())
    {
        helpMessage(argv[0], "Heuristic must be specified unless --all-heuristics is used.");
    }

    if (!allInstances && instanceFileName.empty())
    {
        helpMessage(argv[0], "Instance file must be specified unless --all-instances is used.");
    }

    if (numSalesmen == 0)
    {
        helpMessage(argv[0], "Number of salesmen must be specified.");
    }
}