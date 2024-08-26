#ifndef ARGS_H
#define ARGS_H

#include <iostream>
#include <string>

using namespace std;

enum Arguments
{
    INSTANCE_FILE,
    HEURISTIC,
    NUM_SALESMEN,
    RUN_ALL_HEURISTICS,
    RUN_ALL_INSTANCES,
    VERBOSE,
    HELP_MESSAGE
};

extern bool allHeuristics;
extern bool allInstances;
extern bool verbose;
extern int numSalesmen;
extern string instanceFileName;
extern string selectedHeuristic;

Arguments resolveArgument(string arg);
void helpMessage(string programName, string errorMessage);
void parseArguments(int argc, char *argv[]);

#endif // ARGS_H