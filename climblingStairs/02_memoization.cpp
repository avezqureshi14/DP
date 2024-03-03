#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int climbingStairs(int n, vector<int> dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = climbingStairs(n - 1, dp) + climbingStairs(n - 2, dp);
    return dp[n];
}
int main()
{
    int n = 4;
    vector<int>dp(n+1,-1);
    cout<<climbingStairs(n,dp);
    return 0;
}