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

Instance readInstance(filesystem::path filePath)
{
    Instance inst;
    inst.name = filePath.stem().string();
    ifstream arq(filePath);
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
            cout << "Instance " << inst.name << " loaded successfully!" << endl;
        }

        return inst;
    }
    else
    {
        cerr << endl
             << "Error opening file " << filePath.string() << endl
             << endl;
        exit(EXIT_FAILURE);
    }
}

bool checkNumSalesmen(Instance &inst)
{
    if (inst.size / 2 < numSalesmen)
    {
        if (verbose)
        {
            cout << "Instance " << inst.name << " will not be solved. The number of salesmen must be less than half the number of cities!" << endl
                 << "Number of cities = " << inst.size << endl
                 << "Number of salesmen = " << numSalesmen << endl
                 << "--------------------------------------------" << endl;
        }
        return true;
    }
    return false;
}

vector<Instance> readInstances()
{
    if (verbose)
    {
        cout << "Loading instances..." << endl;
    }
    vector<Instance> instances;
    if (!allInstances)
    {
        Instance inst = readInstance(instanceFileName);
        instances.push_back(inst);
    }
    else
    {
        for (const auto &entry : filesystem::directory_iterator("instances"))
        {
            if (entry.is_regular_file())
            {
                instances.push_back(readInstance(entry.path()));
            }
        }
    }
    if (verbose)
    {
        cout << "All instances loaded successfully!" << endl
             << "--------------------------------------------" << endl;
    }
    return instances;
}