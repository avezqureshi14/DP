#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int miniSubsetSumDiff(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (auto i : nums)
    {
        totalSum += i;
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= totalSum; j++)
        {
            if (j >= nums[i - 1])
            {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int mini = INT_MAX;
    
    for (int j = totalSum / 2; j >= 0; j--)
    {
        if (dp[n][j])
        {
            cout<<endl;
            cout<<"Totalsum is "<<totalSum<<endl;
            cout<<"2*j is "<<2*j<<endl;
            cout<<endl;
            mini = totalSum - 2 * j;
            break;
        }
    }
    return mini;
}
int main()
{
    vector<int> nums = {1,9,15};
    cout << miniSubsetSumDiff(nums);
    return 0;
}