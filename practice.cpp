#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int knapSack(vector<int> &wt, vector<int> &val, int W, int n, int m, int maxProfit, vector<vector<int>> dp)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (wt[n - 1] > W)
    {
        return knapSack(wt, val, W, n - 1, m - 1, maxProfit, dp);
    }
    else
    {
        dp[n][W] = max(val[n - 1] + knapSack(wt, val, W - wt[n - 1], n - 1, m - 1, maxProfit, dp), knapSack(wt, val, W, n - 1, m - 1, maxProfit, dp));
        return dp[n][W];
    }
}

int knapSackTD(vector<int> &wt, vector<int> &val, int W, int n, int m, int maxProfit, vector<vector<int>> dp)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }

    return dp[n][W];
}

int main()
{
    vector<int> wt = {2, 8, 3, 7};
    vector<int> val = {1, 5, 7, 9};
    int W = 11;
    int maxProfit = 0;
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << knapSackTD(wt, val, W, wt.size(), val.size(), maxProfit, dp);
    return 0;
}