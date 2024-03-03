#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int coinChangeII(vector<int> &coins, int amount)
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
                dp[i][j] = min(dp[i][j - coins[i - 1]] + dp[i - 1][j], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount];
}
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        } 
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
int main() 
{
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << coinChange(coins, amount);

    return 0;
}