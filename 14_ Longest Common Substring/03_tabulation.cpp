#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubstring(string s1, string s2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxLen;
}

int main() {
    string s1 = "abbcf";
    string s2 = "abbdaf";
    int n = s1.length();
    int m = s2.length();
    cout << LongestCommonSubstring(s1, s2, n, m);
    return 0;
}
