#include <iostream>
#include <vector>
#include <map>

/**
 * @brief Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
 * 
 */

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::map<int, int> values;

        // Store values and the number of occurances into map
        for(size_t i = 0; i < nums.size(); i++) {
            values[nums[i]]++;
        }

        // search in map for most occuring one
        
        bool first = true;
        int result = 0;
        int majority = 0;

        for(const auto& it : values) {
            if(first) {
                first = false;
                majority = it.second;
                result = it.first;
                continue;
            }

            if(it.second > majority) {
                majority = it.second;
                result = it.first;
            }
        }

        return result;
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {3, 2, 3};
    std::cout << solution.majorityElement(nums) << std::endl;

    nums = {2, 2, 1, 1, 1, 2, 2};
    std::cout << solution.majorityElement(nums) << std::endl;

    return 0;
}