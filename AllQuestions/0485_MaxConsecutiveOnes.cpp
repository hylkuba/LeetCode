#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
 * 
 */

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int max = 0;
        int curr = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(!nums[i]) {
                curr = 0;
            } else {
                curr++;
            }
            max = std::max(max, curr);
        }

        return max;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {1,1,0,1,1,1};
    int result = solution.findMaxConsecutiveOnes(nums);
    std::cout << "Result: " << result << std::endl;
    return 0;
}