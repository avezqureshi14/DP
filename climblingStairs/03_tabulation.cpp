#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int climbingStairs(int n){
    vector<int>dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int climbingStairsII(int n){
    int prev2 = 1;
    int prev1 = 1;
    int curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main()
{
    cout<<climbingStairsII(5);
    return 0;
}