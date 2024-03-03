#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minPathSumTriangleRecursive(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return triangle[n - 1][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int d = triangle[i][j] + minPathSumTriangleRecursive(i + 1, j, triangle, n, dp);
    int dg = triangle[i][j] + minPathSumTriangleRecursive(i + 1, j + 1, triangle, n, dp);
    dp[i][j] = min(d, dg);
    return dp[i][j];
}

int minPathSumTriangle(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minPathSumTriangleRecursive(0, 0, triangle, n, dp);
}
int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int n = 4;
    cout << minPathSumTriangle(triangle, n);
    return 0;
}