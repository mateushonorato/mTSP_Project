#ifndef INSTANCE_H
#define INSTANCE_H

#include "args.h"
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct sPoint
{
    float x, y;
    int id;
} Point;

typedef struct sInstance
{
    string name;
    int size;
    float **distance;
    Point *coords;
} Instance;

void calculateDistance(Instance &inst);
bool checkNumSalesmen(Instance &inst);
Instance readInstance(filesystem::path filePath);
vector<Instance> readInstances();

#endif // INSTANCE_H