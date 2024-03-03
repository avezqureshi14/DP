#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubstring(string s1, string s2, int n, int m, int len)
{

    if (n == 0 || m == 0)
    {
        return len;
    }
    if (s1[n - 1] == s2[m - 1])
    {
        len = LongestCommonSubstring(s1, s2, n - 1, m - 1, len + 1);
    }
    int len1 = LongestCommonSubstring(s1, s2, n - 1, m, 0);
    int len2 = LongestCommonSubstring(s1, s2, n, m - 1, 0);
    len = max({len, len1, len2});
    return len;
}
int main()
{

    string s1 = "abcawd";
    string s2 = "abcdef";
    int l1 = s1.size();
    int l2 = s2.size();
    cout << LongestCommonSubstring(s1, s2, l1, l2, 0) << endl;
    

    return 0;
}