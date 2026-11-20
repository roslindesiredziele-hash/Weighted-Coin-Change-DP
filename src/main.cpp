#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <Windows.h>

#include "DPSolver.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

double MeasureDP(int amount, const vector<Coin>& coins, int repetitions);

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

double MeasureDP(int amount, const vector<Coin>& coins, int repetitions)
{
    LARGE_INTEGER start, end, frequency;

    QueryPerformanceFrequency(&frequency);

    double totalTime = 0.0;

    for (int i = 0; i < repetitions; i++)
    {
        QueryPerformanceCounter(&start);

        MinWeight(
            amount,
            coins);

        QueryPerformanceCounter(&end);

        totalTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
    }

    return totalTime / repetitions;
}

void RunExample()
{
    vector<Coin> coins =
    {
        {1, 10},
        {2, 5},
        {5, 2}
    };

    int amount = 10;

    int result = MinWeight(amount, coins);

    cout
        << "Minimum weight for "
        << amount
        << " = "
        << result
        << "\n\n";
}