#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int> &nums, int &sum, bool &flag, int subsetSum)
{
    if (index == nums.size())
    {
        if (subsetSum == sum)
        {
            flag = true;
        }
        return;
    }
    subsetSum += nums[index];
    solve(index + 1, nums, sum, flag, subsetSum);
    subsetSum -= nums[index];
    solve(index + 1, nums, sum, flag, subsetSum);
}

bool subsetSum(vector<int> &nums, int &sum)
{
    int index = 0;
    bool flag = false;
    int subsetSum = 0;
    solve(index, nums, sum, flag, subsetSum);
    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool subsetSumII(vector<int> &nums, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }

    if (n < 0)
    {
        return false;
    }

    bool include = subsetSumII(nums, sum - nums[n], n - 1);
    bool exclude = subsetSumII(nums, sum, n - 1);

    return exclude || include;
}

int main()
{
    vector<int> nums = {2, 3, 7, 8};
    int sum = 5;
    int subsetSum = 0;
    bool flag = false;
    int n = nums.size();
    if (subsetSumII(nums, sum, 0))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    return 0;
}