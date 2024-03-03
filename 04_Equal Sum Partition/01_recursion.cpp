#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solveEqualSumPart(vector<int> &nums, int n, int &tSum, int sum)
{
    if (sum == tSum)
    {
        return true;
    }
    if (n < 0)
    {
        return false;
    }
    bool include = solveEqualSumPart(nums, n - 1, tSum, sum + nums[n - 1]);
    bool exclude = solveEqualSumPart(nums, n - 1, tSum, sum);

    return include || exclude;
}

bool equalSumPartition(vector<int> &nums, int &n)
{
    int tSum = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        tSum = tSum + nums[i];
    }
    if (tSum % 2)
    {
        return false;
    }
    else
    {
        return solveEqualSumPart(nums, n, tSum, sum);
    }
}
int main()
{
    vector<int>nums = {1, 2, 3, 7};
    int n = nums.size();
    if (equalSumPartition(nums,n))
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"Nope"<<endl;
    }
    
    return 0;
}