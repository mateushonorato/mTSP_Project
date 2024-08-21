#include "instance.h"

void calculateDistance(Instance &inst)
{
    for (int i = 0; i < inst.size; i++)
    {
        for (int j = 0; j < inst.size; j++)
        {
            inst.distance[i][j] = sqrt(pow(inst.coords[i].x - inst.coords[j].x, 2) + pow(inst.coords[i].y - inst.coords[j].y, 2));
        }
    }
}

void readInstance(Instance &inst, string fileName)
{
    ifstream arq(fileName);
    if (arq.is_open())
    {
        // número de cidades
        arq >> inst.size;

        // criando o vetor de pontos
        inst.coords = new Point[inst.size];

        // lendo as coordenadas
        for (int i = 0; i < inst.size; i++)
        {
            arq >> inst.coords[i].id >> inst.coords[i].x >> inst.coords[i].y;
        }

        // criando a matriz de distâncias
        inst.distance = new float *[inst.size];
        for (int i = 0; i < inst.size; i++)
        {
            inst.distance[i] = new float[inst.size];
        }

        // calculando a matriz
        calculateDistance(inst);

        if (verbose)
        {
            cout << endl
                 << "Instance " << fileName << " loaded successfully!" << endl
                 << endl;
        }
    }
    else
    {
        cerr << endl
             << "Error opening file " << fileName << endl
             << endl;
        exit(EXIT_FAILURE);
    }
}