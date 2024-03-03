#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int uniquePathsRecursive(int i, int j, vector<vector<int>>&dp){
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    
    int up = uniquePathsRecursive(i-1,j,dp);
    int left = uniquePathsRecursive(i,j-1,dp);

    dp[i][j] = up + left;
    return dp[i][j];
}

int uniquePaths(int m, int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

    return uniquePathsRecursive(m-1,n-1,dp);
}

int main()
{
    int m = 3;
    int n = 7;
    cout<<uniquePaths(m,n);
    return 0;
}