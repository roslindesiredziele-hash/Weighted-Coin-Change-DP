#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <Windows.h>

#include "DPSolver.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

double MeasureDP(int amount, const vector<Coin>& coins, int repetitions);
void RunExample();

int main()
{
    RunExample();

    vector<Coin> coins =
    {
        {1, 10},
        {2, 5},
        {5, 2},
        {10, 4},
        {20, 6},
        {50, 10}
    };

    ofstream outfile("./data/benchmark.csv");

    if (!outfile)
    {
        cerr
            << "Unable to open benchmark.csv\n";

        return 1;
    }

    outfile
        << "Amount,"
        << "TimeMs\n";

    vector<int> amounts =
    {
        10,
        20,
        30,
        40,
        50,
        100,
        200,
        300,
        400,
        500,
        1000,
        2000,
        5000,
        10000,
        20000,
        50000,
        100000
    };

    for (int amount : amounts)
    {
        int repetitions;

        if (amount <= 1000)
        {
            repetitions = 1000;
        }
        else if (amount <= 10000)
        {
            repetitions = 200;
        }
        else
        {
            repetitions = 50;
        }

        double time = MeasureDP(amount, coins, repetitions);

        cout
            << "Amount: "
            << amount
            << " | Time: "
            << time
            << " ms"
            << endl;

        outfile
            << amount
            << ","
            << time
            << "\n";
    }

    outfile.close();

    cout << "\nBenchmark completed.\n";

    cout << "Results saved to " << "./data/benchmark.csv\n";

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