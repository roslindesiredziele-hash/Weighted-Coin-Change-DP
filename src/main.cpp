#include "DPSolver.h"

#include <iostream>
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