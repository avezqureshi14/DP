#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string printLCSS(string s1,string s2){
    int n = s1.length();
    int m = s2.length();
    string ans;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
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
            if (s1[i-1] == s2[j-1])
            {
                ans.push_back(s1[i-1]);
            }
            else{
                ans.push_back(s1[i]);
                ans.push_back(s2[i]);
            }
        }
                
    }
    return ans;
}
int main()
{
    string s1 = "abcdaf";
    string s2 = "acbcf";
    cout<<printLCSS(s1,s2);
    return 0;
}