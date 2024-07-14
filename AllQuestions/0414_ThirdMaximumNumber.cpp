#include <iostream>
#include <vector>
#include <set>

/**
 * @brief Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Can you find an O(n) solution?
 * 
 */

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::set<int> s;

        for(size_t i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        if(s.size() < 3) return *s.rbegin();

        auto it = s.rbegin();
        std::advance(it, 2);

        return *it;
    }
};

int main(void) {
    Solution s;
    std::vector<int> nums = {3, 2, 1};
    std::cout << s.thirdMax(nums) << std::endl;
    return 0;
}