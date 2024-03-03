#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int shortestCommonSuperSequence(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    string ansString;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ansString.push_back(s1[i - 1]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int lcs = dp[n][m];
    int ans = (m + n) - lcs;
    return ans;
}
int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << shortestCommonSuperSequence(s1, s2);
    return 0;
}