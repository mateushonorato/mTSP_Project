#include "solution.h"

void printSolution(const Solution &sol)
{
    for (const auto &subvector : sol)
    {
        cout << "[ ";
        for (const auto &elem : subvector)
        {
            cout << elem << " ";
        }
        cout << "]" << endl;
    }
}