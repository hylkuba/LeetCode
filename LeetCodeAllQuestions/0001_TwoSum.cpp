#include <iostream>
#include <vector>

/**
 * @brief Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 * 
 */

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int num1 = 0, num2 = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t m = i + 1; m < nums.size(); m++) {
                if(nums[i] + nums[m] == target) {
                    num2 = m;
                    break;
                }
            }
            if(num2 != 0) {
                num1 = i;
                break;
            }
        }
        return std::vector<int>{num1, num2};
    }
};

int main(void) {
    Solution sol;

    std::vector<int> nums = {3, 2, 4};
    int target = 6;
    std::vector<int> result = sol.twoSum(nums, target);

    // Print the result
    for (int index : result) {
        std::cout << index << " ";
    }

    return 0;
}