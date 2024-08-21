#ifndef ARGS_H
#define ARGS_H

#include <iostream>
#include <string>

using namespace std;

extern string instanceFileName;
extern string selectedHeuristic;
extern bool verbose;

void parseArguments(int argc, char *argv[]);

#endif // ARGS_H