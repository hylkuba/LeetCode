#include <iostream>
#include <vector>

/**
 * @brief Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
 * 
 */

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        std::vector<int> noZero;
        for(size_t i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                noZero.push_back(nums[i]);
            }
        }

        for(size_t i = 0; i < noZero.size(); i++) {
            nums[i] = noZero[i];
        }

        for(size_t i = noZero.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main(void) {
    Solution sol;
    std::vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    for(auto num : nums) {
        std::cout << num << " ";
    }
    return 0;
}