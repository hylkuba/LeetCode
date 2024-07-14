#include <vector>
#include <iostream>

/**
 * @brief Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
 * 
 */

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        long long totalVal = 1;
        size_t size = nums.size();

        for(size_t i = 0; i < size; i++) {
            totalVal *= nums[i];
        }

        std::vector<int> result;
        if(totalVal != 0) {
            for(size_t i = 0; i < size; i++) {
                result.push_back(totalVal / nums[i]);
            }
        } else {
            int index = 0;
            totalVal = 1;
            int zeroCnt = 0;
            for(size_t i = 0; i < size; i++) {
                if(nums[i] == 0) {
                    zeroCnt++;
                    index = i;
                } else {
                    totalVal *= nums[i];
                }
            }

            // If there are two zeroes, whole vector contains zeroes
            if(zeroCnt > 1) {
                for(size_t i = 0; i < size; i++) {
                    result.push_back(0);
                }
            } // Otherwise there are zeroes everywhere except "index"
            else {
                for(size_t i = 0; i < size; i++) {
                    if(i == index) {
                        result.push_back(totalVal);
                    } else {
                        result.push_back(0);
                    }
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = solution.productExceptSelf(nums);
    for(size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}