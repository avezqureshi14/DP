#include <iostream>
#include <vector>

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

int main() {
    std::vector<int> nums = {2, 3,4,1,5};
    int targetSum = 5;
    
    int totalCount = countSubsets(nums, targetSum, 0);
    
    std::cout << "Total subsets with sum " << targetSum << ": " << totalCount << std::endl;
    
    return 0;
}
