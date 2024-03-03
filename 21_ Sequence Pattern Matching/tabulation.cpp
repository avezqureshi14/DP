#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool sequencePatternMatching(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
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
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int LCSlen = dp[n][m];
    if (n == LCSlen)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s1 = "AXY";
    string s2 = "ADXCPY";
    int n = s1.length();
    int m = s2.length();
    if (sequencePatternMatching(s1, s2, n, m))
    {
        cout << "Yeah";
    }
    else
    {
        cout << "Nope";
    }

    return 0;
}