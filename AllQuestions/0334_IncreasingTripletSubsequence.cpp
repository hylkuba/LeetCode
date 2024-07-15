#include <iostream>
#include <vector>

/**
 * @brief Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
 * 
 */

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int first_small = INT_MAX;
        int second_small = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= first_small) {
                first_small = nums[i];
            } else if(nums[i] <= second_small) {
                second_small = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {2,1,5,0,4,6};
    bool result = solution.increasingTriplet(nums);
    return 0;
}