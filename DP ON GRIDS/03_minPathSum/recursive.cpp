#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minPathSumRecursive(int i, int j, vector<vector<int>> &mat)
{

    if (i < 0 || j < 0)
    {
        return 1e9;
    }
    if (i == 0 && j == 0)
    {
        return mat[i][j];
    }

    int up = mat[i][j] + minPathSumRecursive(i - 1, j, mat);
    int left = mat[i][j] + minPathSumRecursive(i, j - 1, mat);

    return min(up, left);
}

int minPathSum(int m, int n, vector<vector<int>> &mat)
{

    return minPathSumRecursive(m - 1, n - 1, mat);
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix = {{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
    cout << minPathSum(m, n, matrix);
    return 0;
}