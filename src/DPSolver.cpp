#include "DPSolver.h"

#include <climits>
#include <algorithm>

using namespace std;

int MinWeight(int amount, const vector<Coin>& coins)
{
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int current = 1;
         current <= amount;
         current++)
    {
        for (const Coin& coin : coins)
        {
            if (current >= coin.denomination && dp[current - coin.denomination] != INT_MAX)
            {
                dp[current] = min( dp[current], dp[current - coin.denomination]  + coin.weight);
            }
        }
    }

    return dp[amount];
}