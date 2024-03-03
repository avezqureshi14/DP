#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestPalindromicSequence(string s1)
{
    int n = s1.length();
    int m = n;
    string s2 = s1;
    reverse(s2.begin(), s2.end());
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
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}
int main()
{
    string s1 = "RAECAR";
    cout<<longestPalindromicSequence(s1);
    return 0;
}