#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<int> wt, vector<int> &val, int kpwt, int n, int maxProfit)
{
    if (n == 0 || kpwt == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= kpwt)
    {
        maxProfit = max(val[n - 1] + knapSack(wt, val, kpwt - wt[n - 1], n - 1, maxProfit), knapSack(wt, val, kpwt, n - 1, maxProfit));
        return maxProfit;
    }
    else
    {
       return knapSack(wt, val, kpwt, n - 1, maxProfit);
    }
}

int main()
{
    vector<int>wt = {2,8,3,7};
    vector<int>val = {1,5,7,9};
    int kpwt = 11;
    int n = wt.size();
    int maxProfit = 0;
    cout<<knapSack(wt,val,kpwt,n,maxProfit);

    return 0;
}