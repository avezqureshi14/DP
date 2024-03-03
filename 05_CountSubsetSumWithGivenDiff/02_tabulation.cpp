#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countSubsetSumWithGivenDiff(vector<int> nums, int diff)
{
    int n = nums.size();
    int totalSum = 0;
    for (auto i : nums)
    {
        totalSum += i;
    }
    // even is important
    if (totalSum < diff || (diff + totalSum) % 2 != 0)
        return 0;
    int s1 = (diff + totalSum) / 2;
    if (s1 < 0)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s1; j++)
        {
            if (j >= nums[i - 1])
            {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s1];
}
int main()
{
    vector<int> nums = {1, 1, 2, 3};
    int diff = 1;
    cout << countSubsetSumWithGivenDiff(nums, diff);
    return 0;
}