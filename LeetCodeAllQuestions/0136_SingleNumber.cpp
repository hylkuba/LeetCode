#include <iostream>
#include <vector>
#include <set>

/**
 * @brief Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
 * 
 */

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::set<int> q;

        for(size_t i = 0; i < nums.size(); i++) {
            if(q.find(nums[i]) == q.end()) {
                q.insert(nums[i]);
            } else {
                q.erase(nums[i]);
            }
        }

        return *q.begin();
    }
};

int main(void) {
    Solution solution;
    std::vector<int> nums = {2, 2, 1};
    std::cout << solution.singleNumber(nums) << std::endl;
    return 0;
}