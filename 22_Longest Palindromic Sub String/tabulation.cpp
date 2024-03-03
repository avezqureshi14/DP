#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string longestPalindromicSubstring(string s1)
{
    int n = s1.length();
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    int maxLength = 0, endIndex = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }
    return s1.substr(endIndex - maxLength + 1, maxLength);
}

int main()
{
    string s = "aacabdkacaa";
    cout << longestPalindromicSubstring(s) << endl;
    return 0;
}
