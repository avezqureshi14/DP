#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, int index, int buy, int profit)
{
    if (index == prices.size())
    {
        return 0;
    }
    if (buy)
    {
        profit = max(-prices[index] + solve(prices, index + 1, 0, profit), 0 + solve(prices, index + 1, 1, profit));
    }
    else
    {
        profit = max(prices[index] + solve(prices, index + 1, 1, profit), 0 + solve(prices, index + 1, 1, profit));
    }

    return profit;
}

int buyAndSell(vector<int> &prices)
{
    int index = 0;
    int buy = 1;
    int profit = 0;
    return solve(prices, index, buy, profit);
}
int main()
{
    vector<int>prices = {7,1,5,3,6,4};
    cout<<buyAndSell(prices);
    return 0;
}