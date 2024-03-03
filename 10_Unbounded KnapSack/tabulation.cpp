#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int unBoundedKnapSack(vector<int> &wt, vector<int> &val, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
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
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}
int main()
{
    vector<int>wt = {2,3,4,5};
    vector<int>val = {3,4,5,6};
    int W = 10;
    cout<<unBoundedKnapSack(wt,val,W);
    return 0;
}