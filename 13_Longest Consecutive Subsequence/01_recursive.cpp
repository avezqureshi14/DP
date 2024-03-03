#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestConsecutiveSubsequence(string s1, string s2, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (s1[n - 1] == s2[m - 1])
    {
        return 1 + longestConsecutiveSubsequence(s1, s2, n - 1, m - 1);
    }
    else
    {
        return max(longestConsecutiveSubsequence(s1, s2, n - 1, m), longestConsecutiveSubsequence(s1, s2, n, m - 1));
    }
}
int main()
{
    string s1 = "eac";
    string s2 = "eca";
    int n = s1.length();
    int m = s2.length();
    cout << longestConsecutiveSubsequence(s1, s2, n, m);
    return 0;
}