#ifndef INSTANCE_H
#define INSTANCE_H

#include <cmath>
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
    int size;
    float **distance;
    Point *coords;
} Instance;

void calculateDistance(Instance &inst);
void readInstance(Instance &inst, string fileName);

#endif // INSTANCE_H