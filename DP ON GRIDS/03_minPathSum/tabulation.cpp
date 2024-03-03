int mod = (int)(1e9 + 7);

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minPathSum(int m, int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = mat[i][j];
            }
            else if (i >= 0 && j >= 0 && mat[i][j] == -1)
            {
                dp[i][j] = 0;
            }
            else
            {
                int up = mat[i][j];
                int left = mat[i][j];

                if (i > 0)
                {
                    up += dp[i - 1][j];
                }
                else
                {
                    up = 1e9;
                }
                if (j > 0)
                {
                    left += dp[i][j - 1];
                }
                else
                {
                    left = 1e9;
                }
                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix = {{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
    cout << minPathSum(m, n, matrix);
    return 0;
}