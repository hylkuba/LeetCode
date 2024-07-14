#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
 * 
 */

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        if(nums.size() < 2) return false;
        
        std::sort(nums.begin(), nums.end());

        for(size_t i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) return true;
        }

        return false;
    }
};

int main(void) {
    std::vector<int> nums = {1,2,3,1};
    Solution sol;
    std::cout << sol.containsDuplicate(nums) << std::endl;

    return 0;
}