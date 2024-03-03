#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<int> wt, vector<int> &val, int W, int n, int maxProfit, vector<vector<int>> dp)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (wt[n - 1] <= W)
    {
        dp[n][W] = max(val[n - 1] + knapSack(wt, val, W - wt[n - 1], n - 1, maxProfit, dp), knapSack(wt, val, W, n - 1, maxProfit, dp));
        return dp[n][W];
    }
    else
    {
        dp[n][W] = knapSack(wt, val, W, n - 1, maxProfit, dp);
        return dp[n][W];
    }
}

int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    int n = wt.size();
    int maxProfit = 0;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << knapSack(wt, val, W, n, maxProfit, dp);

    return 0;
}