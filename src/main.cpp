#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <Windows.h>

#include "DPSolver.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<Coin> coins =
    {
        {1, 10},
        {2, 5},
        {5, 2}
    };

    int amount = 10;

    int result =
        MinWeight(amount, coins);

    cout
        << "Minimum weight for "
        << amount
        << " = "
        << result
        << endl;

    return 0;
}