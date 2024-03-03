#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, int index, int buy, int profit,vector<vector<int>>&dp, int n)
{
    if (index == prices.size())
    {
        return 0;
    }
    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }
    
    if (buy)
    {
        profit = max(-prices[index] + solve(prices, index + 1, 0, profit,dp,n), 0 + solve(prices, index + 1, 1, profit,dp,n));
    }
    else
    {
        profit = max(prices[index] + solve(prices, index + 1, 1, profit,dp,n), 0 + solve(prices, index + 1, 1, profit,dp,n));
    }

    return dp[n][buy] = profit;
}

int buyAndSell(vector<int> &prices)
{
    int index = 0;
    int buy = 1;
    int profit = 0;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(prices, index, buy, profit,dp,n);
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << buyAndSell(prices);
    return 0;
}