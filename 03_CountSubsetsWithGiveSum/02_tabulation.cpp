#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countSubsetsWithGivenSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; i++)
    {
            dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= arr[i-1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]] ;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(auto i : dp){
        for(auto j : i ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return dp[n][sum];
}
int main()
{
    vector<int> arr = {1,1,1,1,1};
    int targetSum = 3;
    cout << countSubsetsWithGivenSum(arr, targetSum);
    return 0;
}