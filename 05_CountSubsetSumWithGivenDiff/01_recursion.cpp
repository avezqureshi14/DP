#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// we know we will be getting minimum difference by doing difference of two subset sum S1 and S2, we will be getting S1 by using the formula
//  s1 = diff + sumofarray / 2 , this will be the value of s1 to get the minimum difference , now just we have to find that how many subset sum will be giving this value


int countSubsets(const std::vector<int>& nums, int targetSum, int currentIndex) {
    if (targetSum == 0) {
        // If the target sum is reached, return 1 to count this as a valid subset
        return 1;
    }
    
    if (currentIndex >= nums.size()) {
        // If we have traversed the entire array and the target sum is not reached, return 0
        return 0;
    }
    
    int includeCount = 0;
    if (nums[currentIndex] <= targetSum) {
        // Include the current number and recursively check the remaining sum
        includeCount = countSubsets(nums, targetSum - nums[currentIndex], currentIndex + 1);
    }
    
    // Exclude the current number and recursively check the remaining sum
    int excludeCount = countSubsets(nums, targetSum, currentIndex + 1);
    
    // Return the total count by adding both includeCount and excludeCount
    return includeCount + excludeCount;
}

int countMiniSubsetWithGivenDiff(vector<int> &nums, int diff)
{
    int totalSum = 0;
    int n = nums.size();
    for (auto i : nums)
    {
        totalSum += i;
    }
    int s1 = 0;
    int s2 = 0;
    s1 = diff + totalSum / 2;
    int currentIndex = 0;
    return countSubsets(nums,s1,currentIndex);
}
int main()
{
    vector<int>nums = {1,1,2,3};
    int diff = 1;
    cout<<countMiniSubsetWithGivenDiff(nums,diff);
    return 0;
}