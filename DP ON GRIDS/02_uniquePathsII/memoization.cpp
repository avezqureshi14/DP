#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int uniquePathsIIRecursive(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{

    if (i >= 0 && j >= 0 && mat[i][j] == -1)
    {
        return 0;
    }
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

    int up = uniquePathsIIRecursive(i - 1, j, mat, dp);
    int left = uniquePathsIIRecursive(i, j - 1, mat, dp);
    dp[i][j] = up + left;
    return dp[i][j];
}

int uniquePathsII(int m, int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return uniquePathsIIRecursive(m - 1, n - 1, mat, dp);
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    cout << uniquePathsII(m, n, matrix);
    return 0;
}