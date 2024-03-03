#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// coinChange Problem 1
int coinChangeI(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j >= coins[i - 1])
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount];
}
int main()
{
    // we are using subset amount here
    vector<int> coins = {1, 2, 3};
    int amount = 5;
    cout << coinChangeI(coins, amount);
    return 0;
}