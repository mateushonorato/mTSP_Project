#ifndef ARGS_H
#define ARGS_H

#include <iostream>
#include <string>

using namespace std;

extern bool allHeuristics;
extern bool allInstances;
extern bool verbose;
extern int numSalesmen;
extern string instanceFileName;
extern string selectedHeuristic;

void parseArguments(int argc, char *argv[]);

#endif // ARGS_H