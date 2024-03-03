#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minPathSumRecursive(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 1e7;
    }
    if (i == 0 && j == 0)
    {
        return mat[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = mat[i][j] + minPathSumRecursive(i - 1, j, mat, dp);
    int left = mat[i][j] + minPathSumRecursive(i, j - 1, mat, dp);
    dp[i][j] = min(up, left);
    return dp[i][j];
}

int minPathSum(int m, int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return minPathSumRecursive(m - 1, n - 1, mat, dp);
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix = {{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
    cout << minPathSum(m, n, matrix);
    return 0;
}