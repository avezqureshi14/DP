#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string LCS(string s1, string s2, int n, int m, string &ans)
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
                ans.push_back(s1[i-1]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return ans;
}
int main()
{
    string s1 = "abcdgh";
    string s2 = "abedfhr";
    int n = s1.length();
    int m = s2.length();
    string ans;
    for (auto i : LCS(s1, s2, n, m, ans))
    {
        cout << i << " ";
    }
    return 0;
}